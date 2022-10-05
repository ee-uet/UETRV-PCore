`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module dualport_mem (

    input   logic                                  rst_n,                      // reset
    input   logic                                  clk,                        // clock

  // Instruction memory interface
    input  wire type_if2imem_s                      if2imem_i,                 // Bus interface from IF to imem 
    output type_imem2if_s                           imem2if_o,                 // From imem to IF


  // Data memory interface
    input   wire type_dbus2peri_s                   dbus2dmem_i,               // Data memory input signals
    output  type_peri2dbus_s                        dmem2dbus_o,               // Data memory output signals

 // Selection signal from address decoder of dbus interconnect 
    input   logic                                   dmem_sel_i
);


// Dual port memory instantiation and initialization
logic [`XLEN-1:0]          dualport_memory[`IDMEM_SIZE];

initial
begin
     // Reading the contents of imem.txt file to memory variable
     $readmemh("imem.txt", dualport_memory); 
end

//================================= Ibus interface ==================================//
// Local signals
type_if2imem_s                        if2imem;               
type_imem2if_s                        imem2if_ff;

logic [`MEM_ADDR_WIDTH-1:0]          imem_addr, imem_addr_ff;
logic                                imem_rd_req, imem_rd_req_ff;

// Local signal assignments
assign if2imem     = if2imem_i;
assign imem_rd_req = if2imem.req;
assign imem_addr   = {2'b0, if2imem.addr[`MEM_ADDR_WIDTH-1:2]};  // Memory is word addressable

// The memory address is captured on the negative edge of the clock, 
// while the read data is made available asynchronously on the next 
// positive edge
always_ff @(negedge clk) begin
   if (~rst_n) begin
       imem_rd_req_ff  <= '0;
       imem_addr_ff    <= '0;
    end 
    else begin
       imem_rd_req_ff  <= imem_rd_req;
       imem_addr_ff    <= imem_addr;              // Memory is word addressable
    end
end


// Synchronous memory read operation
always_ff @ (posedge clk) begin 
    if (~rst_n) begin
        imem2if_ff.ack    <= 1'b0;
        imem2if_ff.r_data <= 32'h00000013;
    end else if (imem_rd_req_ff) begin                         // & ~imem2if_ff.ack
        imem2if_ff.ack    <= 1'b1;
        imem2if_ff.r_data <= dualport_memory[imem_addr_ff];   
    end
end


assign imem2if_o = imem2if_ff;    


//================================= Dbus interface ==================================//

// Local signals
type_dbus2peri_s                      dbus2dmem;               
type_peri2dbus_s                      dmem2dbus_ff;
logic [`XLEN-1:0]                     dmem_wdata_ff;
logic [`MEM_ADDR_WIDTH-1:0]           dmem_addr_ff, dmem_addr;
logic [3:0]                           dmem_selbyte_ff;
logic                                 dmem_wen_ff;
logic                                 dmem_sel_ff;
logic                                 dmem_ren;


// Connect the local signals to appropriate IOs of the module
assign dbus2dmem = dbus2dmem_i; 
assign dmem_addr = {2'b0, dbus2dmem.addr[`MEM_ADDR_WIDTH-1:2]};
// assign dmem_ren = (dbus2dmem.cyc) & (~dbus2dmem.w_en); 

// The memory address is captured on the negative edge of the clock, 
// while the read data is made available asynchronously on the next 
// positive edge
always_ff @(negedge clk)
  begin
   if (~rst_n) begin
       dmem_sel_ff     <= '0;
       dmem_wen_ff     <= '0;
       dmem_selbyte_ff <= '0;
       dmem_addr_ff    <= '0;
       dmem_wdata_ff   <= '0;
    end 
    else begin
       dmem_sel_ff     <= (dbus2dmem.cyc & dmem_sel_i);
       dmem_wen_ff     <= dbus2dmem.w_en;
       dmem_selbyte_ff <= dbus2dmem.sel_byte;
       dmem_wdata_ff   <= dbus2dmem.w_data;
       dmem_addr_ff    <= dmem_addr;              // Memory is word addressable
    end
  end

// Synchronous load and store operations for data memory
always_ff @(posedge clk) begin  
    dmem2dbus_ff <= '0;
    if ( dmem_sel_ff &  ~dmem2dbus_ff.ack) begin
        if (dmem_wen_ff) begin
            if (dmem_selbyte_ff[0]) dualport_memory[dmem_addr_ff][7:0]   <= dmem_wdata_ff[7:0];
            if (dmem_selbyte_ff[1]) dualport_memory[dmem_addr_ff][15:8]  <= dmem_wdata_ff[15:8];
            if (dmem_selbyte_ff[2]) dualport_memory[dmem_addr_ff][23:16] <= dmem_wdata_ff[23:16];
            if (dmem_selbyte_ff[3]) dualport_memory[dmem_addr_ff][31:24] <= dmem_wdata_ff[31:24];
        end else begin
            dmem2dbus_ff.ack <= 1'b1;
            dmem2dbus_ff.r_data <= dualport_memory[dmem_addr_ff];
        end
    end
end

// Synchronous read operation (the 'r_data' and 'ack' signals are updated on the
// negative edge of the clock)
/*
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        dmem2dbus_ff <= '0;
    end else begin
        dmem2dbus_ff <= dmem2dbus_next;
    end
end

always_comb begin 

    dmem2dbus_next = '0;
    // The read data in response to load operation
    if (cyc_ff & r_en & (~dmem2dbus_ff.ack)) begin
        dmem2dbus_next.ack = 1'b1;
        dmem2dbus_next.r_data = dualport_memory[addr];
    end 
end
 */                     
assign dmem2dbus_o = dmem2dbus_ff;

endmodule : dualport_mem


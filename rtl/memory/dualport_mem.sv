`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module dualport_mem (

    input   logic                                  rst_n,                    // reset
    input   logic                                  clk,                      // clock

  // Instruction memory interface
    input  logic                                    if2imem_req_i,             // Instruction memory request
    input  logic [`XLEN-1:0]                        if2imem_addr_i,            // Instruction memory address
    output logic [`XLEN-1:0]                        imem2if_rdata_o,           // Instruction memory read data


  // Data memory interface
    input   wire type_core2dbus_s                   mem2dmem_i,              // Data memory input signals
    output  type_dbus2core_s                        dmem2mem_o,               // Data memory output signals

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
logic [`XLEN-1:0]                         rdata_ff;
logic [9:0]                               raddr;
logic                                     rd_req;

// Local signal assignments
assign rd_req = if2imem_req_i;
assign raddr = {2'b0, if2imem_addr_i[9:2]};  // Memory is word addressable

// Synchronous memory read operation
always_ff @ (posedge clk) begin 
    if (rst_n) begin
        rdata_ff  <= '0;
    end else if (rd_req) begin
        rdata_ff <= dualport_memory[raddr];   // #(DELAY)
    end
end


assign imem2if_rdata_o = rdata_ff;    


//================================= Dbus interface ==================================//

// Local signals
type_core2dbus_s                      mem2dmem;               
type_dbus2core_s                      dmem2mem;
logic [`XLEN-1:0]                     data_wr_ff;
logic [`XLEN-1:0]                     addr_ff;
logic [3:0]                           mask_ff;
logic                                 wr_ff;
logic                                 req_ff;


// Connect the local signals to appropriate IOs of the module
assign  mem2dmem = mem2dmem_i; 

// The memory address is captured on the negative edge of the clock, 
// while the read data is made available asynchronously 
always_ff @(negedge clk)
  begin
   if (rst_n) begin
       req_ff     <= '0;
       wr_ff      <= '0;
       mask_ff    <= '0;
       addr_ff    <= '0;
       data_wr_ff <= '0;
    end 
    else begin
       req_ff     <= mem2dmem.req;
       wr_ff      <= mem2dmem.wr;
       mask_ff    <= mem2dmem.mask;
       data_wr_ff <= mem2dmem.data_wr;
       addr_ff    <= {2'b0, mem2dmem.addr[9:2]};              // Memory is word addressable
    end
  end

// Asynchronous read operation
assign dmem2mem.data_rd = ((~mem2dmem.req) & (~mem2dmem.wr)) 
                        ? dualport_memory[addr_ff]                 
                        : '0;                       
assign dmem2mem_o       = dmem2mem;

// Memory store operation 
always_ff @(posedge clk)
begin  
   if ( !req_ff && !wr_ff ) begin
        if (mask_ff[0]) dualport_memory[addr_ff][7:0] = data_wr_ff[7:0];
        if (mask_ff[1]) dualport_memory[addr_ff][15:8] = data_wr_ff[15:8];
        if (mask_ff[2]) dualport_memory[addr_ff][23:16] = data_wr_ff[23:16];
        if (mask_ff[3]) dualport_memory[addr_ff][31:24] = data_wr_ff[31:24];
   end
end


endmodule : dualport_mem


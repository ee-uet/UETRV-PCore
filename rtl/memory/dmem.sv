`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module dmem (

    input   logic                                  rst_n,                    // reset
    input   logic                                  clk,                      // clock

  // Dbus to data memory interface
    input   wire type_dbus2peri_s                  dbus2dmem_i,              // Data memory input signals
    output  type_peri2dbus_s                       dmem2dbus_o,               // Data memory output signals

  // Selection signal from address decoder of dbus interconnect 
    input   logic                                  dmem_sel_i
);


// Instruction memory instantiation and initialization
logic [`XLEN-1:0]          data_memory[`DMEM_SIZE];

initial
begin
     // Reading the contents of imem.txt file to memory variable
     $readmemh("dmem.txt", data_memory); 
end

// Local signals
type_dbus2peri_s                      dbus2dmem;               
type_peri2dbus_s                      dmem2dbus;
logic [`XLEN-1:0]                     w_data_ff;
logic [`XLEN-1:0]                     addr_ff;
logic [3:0]                           mask_ff;
logic                                 wr_ff;
logic                                 req_ff;

logic                                 dmem_sel;

// Connect the local signals to appropriate IOs of the module
assign  dbus2dmem = dbus2dmem_i; 
assign  dmem_sel = dmem_sel_i;

// The memory read address is captured on the negative edge of the clock, 
// while the read data/instruction is made available asynchronously 
always_ff @(negedge clk)
  begin
   if (~rst_n) begin
       req_ff     <= '0;
       wr_ff      <= '0;
       mask_ff    <= '0;
       addr_ff    <= '0;
       w_data_ff  <= '0;
    end 
    else begin
       req_ff     <= dbus2dmem.cyc;
       wr_ff      <= dbus2dmem.w_en;
       mask_ff    <= dbus2dmem.sel_byte;
       w_data_ff  <= dbus2dmem.w_data;
       addr_ff    <= dbus2dmem.addr[11:2];              // Memory is word addressable
    end
  end

// Asynchronous read operation
assign dmem2dbus.r_data = ((~dbus2dmem.cyc) & (~dbus2dmem.w_en) & dmem_sel) 
                        ? data_memory[addr_ff]                 
                        : '0;                       
assign dmem2dbus_o      = dmem2dbus;

// Memory store operation 
always_ff @(posedge clk)
begin  
   if ( !req_ff && !wr_ff && dmem_sel) begin
        if (mask_ff[0])
                data_memory[addr_ff][7:0] = w_data_ff[7:0];
        if (mask_ff[1])
                data_memory[addr_ff][15:8] = w_data_ff[15:8];
        if (mask_ff[2])
                data_memory[addr_ff][23:16] = w_data_ff[23:16];
        if (mask_ff[3])
                data_memory[addr_ff][31:24] = w_data_ff[31:24];
   end
end


endmodule : dmem


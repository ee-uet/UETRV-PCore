`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module dmem (

    input   logic                                  rst_n,                    // reset
    input   logic                                  clk,                      // clock

  // DMEM <---> Memory module interface
    input   wire type_signal_to_dmem_s              mem2dmem_i,              // Data memory input signals
    output  type_signal_from_dmem_s                 dmem2mem_o               // Data memory output signals

);


// Instruction memory instantiation and initialization
logic [`XLEN-1:0]          data_memory[`DMEM_SIZE];

initial
begin
     // Reading the contents of imem.txt file to memory variable
     $readmemh("dmem.txt", data_memory); 
end

// Local signals
type_signal_to_dmem_s                 mem2dmem;               
type_signal_from_dmem_s               dmem2mem;
logic [`XLEN-1:0]                     data_wr_ff;
logic [`XLEN-1:0]                     data_rd_ff;
logic [`XLEN-1:0]                     addr_ff;
logic [3:0]                           mask_ff;
logic                                 wr_ff;
logic                                 cs_ff;


// Connect the local signals to appropriate IOs of the module
assign  mem2dmem = mem2dmem_i; 

// The memory read address is captured on the negative edge of the clock, 
// while the read data/instruction is made available asynchronously 
always_ff @(negedge clk)
  begin
   if (rst_n) begin
       cs_ff      <= '0;
       wr_ff      <= '0;
       mask_ff    <= '0;
       addr_ff    <= '0;
       data_wr_ff <= '0;
    end 
    else begin
       cs_ff      <= mem2dmem.cs;
       wr_ff      <= mem2dmem.wr;
       mask_ff    <= mem2dmem.mask;
       data_wr_ff <= mem2dmem.data_wr;
       addr_ff    <= {2'b0, mem2dmem.addr[9:2]};              // Memory is word addressable
    end
  end

// Asynchronous read operation
assign dmem2mem.data_rd = ((~mem2dmem.cs) & (~mem2dmem.wr)) 
                        ? data_memory[addr_ff]                 
                        : '0;                       
assign dmem2mem_o       = dmem2mem;

// Memory store operation 
always_ff @(posedge clk)
begin  
   if ( !cs_ff && !wr_ff ) begin
        if (mask_ff[0])
                data_memory[addr_ff][7:0] = data_wr_ff[7:0];
        if (mask_ff[1])
                data_memory[addr_ff][15:8] = data_wr_ff[15:8];
        if (mask_ff[2])
                data_memory[addr_ff][23:16] = data_wr_ff[23:16];
        if (mask_ff[3])
                data_memory[addr_ff][31:24] = data_wr_ff[31:24];
   end
end


endmodule : dmem


`include "../defines/UETRV_PCore_defs.svh"

module imem (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

  // IF <---> IMEM interface
//    output   logic                                   imem2if_resp_o,         // Instruction memory request acknowledgement
    input  logic                                    if2imem_req_i,             // Instruction memory request
    input   logic [`XLEN-1:0]                       if2imem_addr_i,            // Instruction memory address
    output  logic [`XLEN-1:0]                       imem2if_rdata_o           // Instruction memory read data
//    input   type_scr1_mem_resp_e                    imem2if_resp_i,            // Instruction memory response


);


// Instruction memory instantiation and initialization
logic   [`XLEN-1:0]          memory[`IMEM_SIZE];

initial
begin
     // Reading the contents of imem.txt file to memory variable
     $readmemh("imem.txt", memory); 
end

// Local signals
logic   [`XLEN-1:0]          rdata_ff;
logic   [9:0]                raddr_ff;
logic                        cs_ff;


// The memory read address is captured on the positive edge of the clock, 
// while the read data/instruction is made available on the negative edge 
always_ff @(posedge clk)
  begin
   if (rst_n) begin
       cs_ff     <=   '0;
       raddr_ff  <=   '0;
    end 
    else begin
       cs_ff     <=   if2imem_req_i;
       raddr_ff  <=   if2imem_addr_i[9:2]; // Memory is word addressable
    end
  end

// Memory read operation requires cs_ff = 0
/*always_ff @ (negedge clk) begin 
    if (rst_n) begin
        rdata_ff  <= '0;
    end else if (cs_ff) begin
        rdata_ff   <=   memory[raddr_ff];   // #(DELAY)
    end
end
*/

assign imem2if_rdata_o   =   memory[raddr_ff];  // MT: Asynchronous read    --- rdata_ff; 

endmodule: imem


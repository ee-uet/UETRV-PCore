`include "../defines/UETRV_PCore_defs.svh"

module imem (

    input   logic                                   rst_n,                    // reset
    input   logic                                   clk,                      // clock

  // IF <---> IMEM interface
//    output   logic                                  imem2if_resp_o,            // Instruction memory request acknowledgement
    input  logic                                    if2imem_req_i,             // Instruction memory request
    input  logic [`XLEN-1:0]                        if2imem_addr_i,            // Instruction memory address
    output logic [`XLEN-1:0]                        imem2if_rdata_o            // Instruction memory read data
//    input   type_scr1_mem_resp_e                    imem2if_resp_i,            // Instruction memory response

);


// Instruction memory instantiation and initialization
logic [`XLEN-1:0]          inst_memory[`IMEM_SIZE];

initial
begin
     // Reading the contents of imem.txt file to memory variable
     $readmemh("imem.txt", inst_memory); 
end

// Local signals
logic [`XLEN-1:0]                         rdata_ff;
logic [9:0]                               raddr;
logic                                     rd_req;

// Local signal assignments
assign rd_req = if2imem_req_i;
assign raddr = {2'b0, if2imem_addr_i[9:2]};  // Memory is word addressable

// Synchronous memory read operation
always_ff @ (posedge clk) begin 
    if (~rst_n) begin
        rdata_ff <= 32'h00000013;
    end else if (rd_req) begin
        rdata_ff <= inst_memory[raddr];   // #(DELAY)
    end
end


assign imem2if_rdata_o = rdata_ff;  //  

endmodule : imem


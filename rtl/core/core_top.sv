`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module core_top (

    input   logic                        rst_n,                  // reset
    input   logic                        clk                     // clock

);

// Local signals
logic                                   if2imem_req;             // Instruction memory request
logic [`XLEN-1:0]                       if2imem_addr;            // Instruction memory address
logic [`XLEN-1:0]                       imem2if_rdata;  
type_signal_to_dmem_s                   ptop2dmem;                // Signal to data memory 
type_signal_from_dmem_s                 dmem2ptop; 

pipeline_top pipe_top_module (
    .rst_n                (rst_n            ),
    .clk                  (clk              ),

    // IMEM interface signals 
    .if2imem_req_o       (if2imem_req),
    .if2imem_addr_o      (if2imem_addr),
    .imem2if_rdata_i     (imem2if_rdata),

    // DMEM interface signals
    .ptop2dmem_o         (ptop2dmem),       // Signal to data memory 
    .dmem2ptop_i         (dmem2ptop)
);

// Data memory
dmem dmem_module (
    .rst_n                (rst_n            ),
    .clk                  (clk              ),

    // Instruction memory interface signals 
    .mem2dmem_i           (ptop2dmem),
    .dmem2mem_o           (dmem2ptop)
);


// Instruction memory
imem imem_module (
    .rst_n                (rst_n            ),
    .clk                  (clk              ),

    // Data memory interface signals 
    .if2imem_req_i       (if2imem_req),
    .if2imem_addr_i      (if2imem_addr),
    .imem2if_rdata_o     (imem2if_rdata)
);

endmodule: core_top


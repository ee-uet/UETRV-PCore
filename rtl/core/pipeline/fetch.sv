`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module fetch (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

   // IF <---> IMEM interface
//    input   logic                                   imem2if_resp_i,         // Instruction memory request acknowledgement
    output  logic                                   if2imem_req_o,             // Instruction memory request
    output  logic [`XLEN-1:0]                       if2imem_addr_o,            // Instruction memory address
    input   logic [`XLEN-1:0]                       imem2if_rdata_i,           // Instruction memory read data
//    input   type_scr1_mem_resp_e                    imem2if_resp_i,            // Instruction memory response

    // IF <---> ID interface
    output   logic [`XLEN-1:0]                      if2id_pc_o,              // pc to fetch stage
    output   logic [`XLEN-1:0]                      if2id_instr_o,           // Instruction to ID module
//    input   logic                                  if2id_err_i,             // Instruction access fault 

    input  logic                                     id2if_rdy_i,             // Ready signal from ID module 
//    output   logic                                 if2id_valid_o,           // Valid response from IF module

    // IF <---> EXE feedback interface
    input wire type_exe2if_fb_s                      exe2if_fb_i
);


// Local siganls
type_exe2if_fb_s                     exe2if_fb;

// Imem address generation
logic [`XLEN-1:0]                    pc_ff;              // Current value of program counter (PC)
logic [`XLEN-1:0]                    pc_next;            // Updated value of PC

assign imem_update_addr = id2if_rdy_i;   // | exu2if_pc_req_i;
assign exe2if_fb        = exe2if_fb_i;


// PC update state machine
always_ff @(posedge clk) begin
    if (rst_n) begin
        pc_ff <= '0;
    end else begin
        pc_ff <= pc_next;
    end
end

assign pc_next  = exe2if_fb.jump_br_taken ? exe2if_fb.alu_pc 
                : imem_update_addr        ? (pc_ff + 32'd4)
                : pc_ff;


// Update the outputs to Imem module
assign if2imem_addr_o = pc_next;
assign if2imem_req_o  = `IMEM_INST_REQ;

// MT TODO: should be made configurable for enabling/disabling pipeline stage 
assign if2id_instr_o = imem2if_rdata_i;
assign if2id_pc_o    = pc_ff;

endmodule : fetch


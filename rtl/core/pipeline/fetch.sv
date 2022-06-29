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
    output type_if2id_data_s                         if2id_data_o,

//    input   logic                                  if2id_err_o,             // Instruction access fault 

    input  logic                                     id2if_fb_rdy_i,             // Ready signal from ID module 
//    output   logic                                 if2id_valid_o,           // Valid response from IF module

    // IF <---> EXE feedback interface
    input wire type_exe2if_fb_s                      exe2if_fb_i
);


// Local siganls
type_exe2if_fb_s                     exe2if_fb;
type_if2id_data_s                    if2id_data;

// Imem address generation
logic [`XLEN-1:0]                    pc_ff;              // Current value of program counter (PC)
logic [`XLEN-1:0]                    pc_next;            // Updated value of PC

assign id2if_fb_rdy = id2if_fb_rdy_i;   // | exu2if_pc_req_i;
assign exe2if_fb    = exe2if_fb_i;


// PC update state machine
always_ff @(posedge clk) begin
    if (rst_n) begin
        pc_ff <= '0;
    end else begin
        pc_ff <= pc_next;
    end
end

assign pc_next = exe2if_fb.jump_br_taken ? exe2if_fb.alu_pc 
               : id2if_fb_rdy            ? (pc_ff + 32'd4)
               : pc_ff;


// Update the outputs to Imem module
assign if2imem_addr_o = pc_next;
assign if2imem_req_o  = `IMEM_INST_REQ;

// MT TODO: should be made configurable for enabling/disabling pipeline stage 
`ifdef IF2ID_PIPELINE_STAGE
    assign if2id_data.instr = exe2if_fb.jump_br_taken 
                            ? `INSTR_NOP              // Insert NOP for jump or branch taken
                            : imem2if_rdata_i;
`else
    assign if2id_data.instr = imem2if_rdata_i;
`endif

assign if2id_data.pc = pc_ff;
assign if2id_data_o  = if2id_data;

endmodule : fetch


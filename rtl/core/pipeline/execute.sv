// Include some licensing info and file header 

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module execute (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // ID <---> EXE interface
    input  wire type_id2exe_data_s       id2exe_data_i,
    input  wire type_id2exe_ctrl_s       id2exe_ctrl_i,            // Structure for control signals from decode to execute 

    // EXE <---> MEM interface
    output type_exe2mem_data_s           exe2mem_data_o,
    output type_exe2mem_ctrl_s           exe2mem_ctrl_o,

    // EXE <---> Forward_stall interface
    input wire type_fwd2exe_s            fwd2exe_i,
    output type_exe2fwd_s                exe2fwd_o,    

    
    // EXE <---> IF feedback interface
    output type_exe2if_fb_s              exe2if_fb_o,

    // WB <---> EXE feedback interface
    input logic [`XLEN-1:0]              wrb2exe_fb_rd_data_i

);

//============================= Local signals and their assignments =============================//
 
type_id2exe_ctrl_s                   id2exe_ctrl;
type_id2exe_data_s                   id2exe_data;
type_exe2if_fb_s                     exe2if_fb;
type_alu_ops_sel_e                   alu_operator;
type_br_ops_sel_e                    branch_ops;
type_exe2fwd_s                       exe2fwd;
type_fwd2exe_s                       fwd2exe;
logic [`XLEN-1:0]                    wrb2exe_fb_rd_data;

// Input operand signals
logic [`XLEN-1:0]                    operand_rs1_data;
logic [`XLEN-1:0]                    operand_rs2_data;

// ALU signals
logic  [`XLEN-1:0]                   alu_adder_out;
logic  [`XLEN-1:0]                   alu_operand_1;
logic  [`XLEN-1:0]                   alu_operand_2;
logic  [`XLEN-1:0]                   exe2mem_alu_result;

// Branch related signals
logic  [`XLEN-1:0]                   cmp_operand_1;
logic  [`XLEN-1:0]                   cmp_operand_2;
logic  [`XLEN:0]                     cmp_output;
logic                                cmp_not_zero;
logic                                cmp_neg;
logic                                cmp_overflow;
logic                                branch_res;

logic  [4:0]                         shift_amt;
logic                                illegal_instr;

// Instantiate input control and data structures and get the ALU operator
assign alu_operator   = type_alu_ops_sel_e'(id2exe_ctrl_i.alu_ops);
assign branch_ops     = type_br_ops_sel_e'(id2exe_ctrl_i.branch_ops);
assign id2exe_ctrl    = id2exe_ctrl_i;
assign id2exe_data    = id2exe_data_i;

// Feedback data from Writeback
assign wrb2exe_fb_rd_data = wrb2exe_fb_rd_data_i;

// Preparing the operands with forwarding 
assign fwd2exe = fwd2exe_i;
assign operand_rs1_data = fwd2exe.fwd_rs1 ? wrb2exe_fb_rd_data : id2exe_data.rs1_data;
assign operand_rs2_data = fwd2exe.fwd_rs2 ? wrb2exe_fb_rd_data : id2exe_data.rs2_data;


//============================== Preparing signals for ALU operations ============================//

// Operand for shift operations 
assign shift_amt = alu_operand_2[4:0];

// Prepare the two operands
always_comb begin
   alu_operand_1 = (id2exe_ctrl.alu_opr1_sel == ALU_OPR1_PC)
                 ? (id2exe_data.pc)                               // Operand 1 is PC
                 : (operand_rs1_data);                            // Operand 1 is register
   alu_operand_2 = (id2exe_ctrl.alu_opr2_sel == ALU_OPR2_IMM)
                 ? (id2exe_data.imm)                              // Operand 2 is immediate
                 : (operand_rs2_data);                        // Operand 2 is register
end

// Implementation of different ALU operations
// Addition and subtraction
always_comb begin
    alu_adder_out = (alu_operator == ALU_OPS_ADD)
                  ? (alu_operand_1 + alu_operand_2)   // Addition 
                  : (alu_operand_1 - alu_operand_2);  // Subtraction and comparison
end

//============================ Branch related implementation ====================================// 

// Difference calculation for comparison operations (branch and set-less-then operations)
assign cmp_operand_1 = operand_rs1_data;
assign cmp_operand_2 = (id2exe_ctrl.alu_cmp_opr2_sel == ALU_CMP_OPR2_IMM)
                     ? id2exe_data.imm 
                     : operand_rs2_data;

assign cmp_output    = {1'b0, cmp_operand_1} - {1'b0, cmp_operand_2};
assign cmp_not_zero  = |cmp_output[`XLEN-1:0];
assign cmp_neg       = cmp_output[`XLEN-1];
assign cmp_overflow  = (cmp_neg & ~cmp_operand_1[`XLEN-1] & cmp_operand_2[`XLEN-1]) |
                       (~cmp_neg & cmp_operand_1[`XLEN-1] & ~cmp_operand_2[`XLEN-1]); 


// Evaluate the branch comparison result
always_comb begin 
   // set comparison by default
   branch_res = 1'b0;
   case (id2exe_ctrl.branch_ops)
      BR_EQ:   branch_res = ~cmp_not_zero;
      BR_NE:   branch_res = cmp_not_zero;
      BR_LT:   branch_res = (cmp_neg ^ cmp_overflow);
      BR_LTU:  branch_res = cmp_output[`XLEN];             // Check if the carry-flag bit is set
      BR_GE:   branch_res = ~(cmp_neg ^ cmp_overflow);
      BR_GEU:  branch_res = ~cmp_output[`XLEN];            // Carry flag bit is cleared
      default: branch_res = 1'b0;
   endcase
end

//=================================== MUX for output result =====================================//
 
always_comb begin
   exe2mem_alu_result   =  '0;
   case (alu_operator)
      ALU_OPS_AND : begin
         exe2mem_alu_result = alu_operand_1 & alu_operand_2;
      end
      ALU_OPS_OR : begin
         exe2mem_alu_result = alu_operand_1 | alu_operand_2;
      end
      ALU_OPS_XOR : begin
         exe2mem_alu_result = alu_operand_1 ^ alu_operand_2;
      end
      ALU_OPS_ADD : begin
         exe2mem_alu_result = alu_adder_out;
      end
      ALU_OPS_SUB : begin
         exe2mem_alu_result = alu_adder_out;
      end
      // Shift related operations
      ALU_OPS_SLL : begin
         exe2mem_alu_result = alu_operand_1 << shift_amt;
      end
      ALU_OPS_SRL : begin
         exe2mem_alu_result = alu_operand_1 >> shift_amt;
      end
      ALU_OPS_SRA : begin
         exe2mem_alu_result = alu_operand_1 >>> shift_amt;
      end
      // Branch related operations
      ALU_OPS_BRANCH : begin
         exe2mem_alu_result = alu_adder_out;
      end
      // Load upper immediate requires copying operand 2 to ALU output 
      ALU_OPS_COPY_OPR2 : begin
         exe2mem_alu_result = alu_operand_2;
      end
      // Check for rs1 less than rs2 for both signed/unsigned comparisons  
      ALU_OPS_SLT : begin
         exe2mem_alu_result = `XLEN'(cmp_neg ^ cmp_overflow);
      end
      ALU_OPS_SLTU : begin
         exe2mem_alu_result = `XLEN'(cmp_output[`XLEN]);
      end
      default : begin 
         exe2mem_alu_result = '0; 
      end
   endcase
end

// Update the output data signals
assign exe2mem_data_o.alu_result = exe2mem_alu_result;
assign exe2mem_data_o.instr      = id2exe_data.instr;
assign exe2mem_data_o.pc         = id2exe_data.pc;
assign exe2mem_data_o.rs2_data   = operand_rs2_data; // MT: This should be verified due to forwarding

// Assign the output control signals 
assign exe2mem_ctrl_o.rd_wrb_sel = id2exe_ctrl.rd_wrb_sel;
assign exe2mem_ctrl_o.mem_ld_ops = id2exe_ctrl.mem_ld_ops;
assign exe2mem_ctrl_o.mem_st_ops = id2exe_ctrl.mem_st_ops;
assign exe2mem_ctrl_o.rd_wr_req  = id2exe_ctrl.rd_wr_req;
assign exe2mem_ctrl_o.jump_req   = id2exe_ctrl.jump_req;                          
assign exe2mem_ctrl_o.branch_req = id2exe_ctrl.branch_req;                          
assign exe2mem_ctrl_o.mret_req   = id2exe_ctrl.mret_req;                      
assign exe2mem_ctrl_o.fencei_req = id2exe_ctrl.fencei_req;                         
assign exe2mem_ctrl_o.wfi_req    = id2exe_ctrl.wfi_req;  


// Update the module output signals
assign exe2fwd.rs1_addr = id2exe_data.instr[19:15];
assign exe2fwd.rs2_addr = id2exe_data.instr[24:20];

assign exe2fwd_o = exe2fwd;

// Feedback signals from EXE to IF stage
assign exe2if_fb.jump_br_taken = id2exe_ctrl.jump_req || (id2exe_ctrl.branch_req & branch_res);                          
assign exe2if_fb.alu_pc        = exe2mem_alu_result;                          
assign exe2if_fb_o             = exe2if_fb;                  

endmodule : execute


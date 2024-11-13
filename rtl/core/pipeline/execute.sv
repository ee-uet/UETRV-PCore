// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The execute stage of the pipeline for RV32I.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022

 
`ifndef VERILATOR
`include "../../defines/m_ext_defs.svh"
`else
`include "m_ext_defs.svh"
`endif

module execute (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // ID <---> EXE interface
    input  wire type_id2exe_data_s       id2exe_data_i,
    input  wire type_id2exe_ctrl_s       id2exe_ctrl_i,            // Structure for control signals from decode to execute 

    // EXE <---> M-Extension interface
    output type_exe2div_s                exe2div_o,

    // EXE <---> LSU interface
    output type_exe2lsu_data_s           exe2lsu_data_o,
    output type_exe2lsu_ctrl_s           exe2lsu_ctrl_o,

    // EXE <---> CSR interface
    output type_exe2csr_data_s           exe2csr_data_o,
    output type_exe2csr_ctrl_s           exe2csr_ctrl_o,

    // EXE <---> Forwarding module interface
    input wire type_fwd2exe_s            fwd2exe_i,
    output type_exe2fwd_s                exe2fwd_o,    

    
    // EXE <---> IF feedback interface
    output type_exe2if_fb_s              exe2if_fb_o,

    // WB/LSU <---> EXE feedback interface
    input logic [`XLEN-1:0]              lsu2exe_fb_alu_result_i,
    input logic [`XLEN-1:0]              wrb2exe_fb_rd_data_i

);

//============================= Local signals and their assignments =============================//
// Local control and data signal structures 
type_id2exe_ctrl_s                   id2exe_ctrl;
type_id2exe_data_s                   id2exe_data;
type_exe2lsu_ctrl_s                  exe2lsu_ctrl;
type_exe2lsu_data_s                  exe2lsu_data;
type_exe2csr_ctrl_s                  exe2csr_ctrl;
type_exe2csr_data_s                  exe2csr_data;

// Signals for M-extension
type_exe2div_s                       exe2div;

type_exe2if_fb_s                     exe2if_fb;
type_alu_i_ops_e                     alu_i_operator;
type_br_ops_e                        branch_ops;
type_exe2fwd_s                       exe2fwd;
type_fwd2exe_s                       fwd2exe;

// Feedback signals for forwarding
logic [`XLEN-1:0]                    lsu2exe_fb_alu_result;
logic [`XLEN-1:0]                    wrb2exe_fb_rd_data;


// Input operand signals
logic [`XLEN-1:0]                    operand_rs1_data;
logic [`XLEN-1:0]                    operand_rs2_data;

// ALU signals
logic  [`XLEN-1:0]                   alu_adder_output;
logic  [`XLEN-1:0]                   alu_operand_1;
logic  [`XLEN-1:0]                   alu_operand_2;
logic  [`XLEN-1:0]                   alu_result;

// Branch related signals
logic  [`XLEN-1:0]                   cmp_operand_1;
logic  [`XLEN-1:0]                   cmp_operand_2;
logic  [`XLEN:0]                     cmp_output;
logic                                cmp_not_zero;
logic                                cmp_neg;
logic                                cmp_overflow;
logic                                branch_res;
logic                                fence_i_req;

logic  [4:0]                         shift_amt;

logic [`RF_AWIDTH-1:0]               rs1_addr;            
logic [`RF_AWIDTH-1:0]               rs2_addr;           
logic [`RF_AWIDTH-1:0]               rd_addr;            

// Instantiate input control and data structures and get the ALU operator
assign alu_i_operator = type_alu_i_ops_e'(id2exe_ctrl_i.alu_i_ops);
assign branch_ops     = type_br_ops_e'(id2exe_ctrl_i.branch_ops);
assign id2exe_ctrl    = id2exe_ctrl_i;
assign id2exe_data    = id2exe_data_i;
assign fence_i_req    = id2exe_ctrl.fence_i_req;

// Signals for CSR module
assign rd_addr  = id2exe_data.instr[11:7];
assign rs1_addr = id2exe_data.instr[19:15];
assign rs2_addr = id2exe_data.instr[24:20];

// Feedback data from LSU and writeback to execute stage
assign lsu2exe_fb_alu_result = lsu2exe_fb_alu_result_i;
assign wrb2exe_fb_rd_data    = wrb2exe_fb_rd_data_i;

// Preparing the operands for execution stage with forwarding 
assign fwd2exe = fwd2exe_i;
// assign operand_rs1_data = fwd2exe.fwd_wrb_rs1 ? wrb2exe_fb_rd_data : id2exe_data.rs1_data;
// assign operand_rs2_data = fwd2exe.fwd_wrb_rs2 ? wrb2exe_fb_rd_data : id2exe_data.rs2_data;

always_comb begin
    case (1'b1)
        fwd2exe.fwd_lsu_rs1 : begin
            operand_rs1_data = lsu2exe_fb_alu_result;
        end
        fwd2exe.fwd_wrb_rs1 : begin
            operand_rs1_data = wrb2exe_fb_rd_data;
        end
        default             : begin
            operand_rs1_data = id2exe_data.rs1_data;
        end
    endcase
end

always_comb begin
    case (1'b1)
        fwd2exe.fwd_lsu_rs2 : begin
            operand_rs2_data = lsu2exe_fb_alu_result;
        end
        fwd2exe.fwd_wrb_rs2 : begin
            operand_rs2_data = wrb2exe_fb_rd_data;
        end
        default             : begin
            operand_rs2_data = id2exe_data.rs2_data;
        end
    endcase
end

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
                 : (operand_rs2_data);                            // Operand 2 is register
end

// Implementation of different ALU operations
// Addition and subtraction
always_comb begin
    alu_adder_output = (alu_i_operator == ALU_I_OPS_ADD)
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
      BR_OPS_EQ:  branch_res = ~cmp_not_zero;
      BR_OPS_NE:  branch_res = cmp_not_zero;
      BR_OPS_LT:  branch_res = (cmp_neg ^ cmp_overflow);
      BR_OPS_LTU: branch_res = cmp_output[`XLEN];             // Check if the carry-flag bit is set
      BR_OPS_GE:  branch_res = ~(cmp_neg ^ cmp_overflow);
      BR_OPS_GEU: branch_res = ~cmp_output[`XLEN];            // Carry flag bit is cleared
      default: branch_res = 1'b0;
   endcase
end

//=================================== MUX for ALU output result =====================================//
 
always_comb begin
   alu_result = '0;

   case (alu_i_operator)
      ALU_I_OPS_AND : begin
         alu_result = alu_operand_1 & alu_operand_2;
      end
      ALU_I_OPS_OR : begin
         alu_result = alu_operand_1 | alu_operand_2;
      end
      ALU_I_OPS_XOR : begin
         alu_result = alu_operand_1 ^ alu_operand_2;
      end
      ALU_I_OPS_ADD : begin
         alu_result = alu_adder_output;
      end
      ALU_I_OPS_SUB : begin
         alu_result = alu_adder_output;
      end
      // Shift related operations
      ALU_I_OPS_SLL : begin
         alu_result = alu_operand_1 << shift_amt;
      end
      ALU_I_OPS_SRL : begin
         alu_result = alu_operand_1 >> shift_amt;
      end
      ALU_I_OPS_SRA : begin
         alu_result = $signed(alu_operand_1) >>> shift_amt;
      end
      // Branch related operations
      ALU_I_OPS_COPY_OPR1 : begin
         alu_result = alu_operand_1;
      end
      // Load upper immediate requires copying operand 2 to ALU output 
      ALU_I_OPS_COPY_OPR2 : begin
         alu_result = alu_operand_2;
      end
      // Check for rs1 less than rs2 for both signed/unsigned comparisons  
      ALU_I_OPS_SLT : begin
         alu_result = `XLEN'({cmp_neg ^ cmp_overflow});
      end
      ALU_I_OPS_SLTU : begin
         alu_result = `XLEN'(cmp_output[`XLEN]);
      end
      default : begin 
         alu_result = '0; 
      end
   endcase
end

//============================ Signal evaluations for Bit Manipulation operations ===============================// 
type_alu_b_ops_e        alu_b_ops;
logic [`XLEN-1:0]       alu_b_result;

assign alu_b_ops    = type_alu_b_ops_e'(id2exe_ctrl_i.alu_b_ops);

assign bitmanip_cmd = |alu_b_ops;

logic             is_ctz;
logic [`XLEN-1:0] max_result, maxu_result;
logic [`XLEN-1:0] min_result, minu_result;
logic             is_cpop;
logic [`XLEN-1:0] cnt_data;
logic [`XLEN:0]   cnt_en;
logic [5:0]       cnt_result;
logic [`XLEN-1:0] alu_operand_1_rev, alu_operand_2_rev;
logic [`XLEN-1:0] zbs_index;
logic [`XLEN-1:0] clmul_operand_1, clmul_operand_2, clmul_result, clmulr_result;

for (genvar i = 0; i < `XLEN; i++) begin
   assign alu_operand_1_rev[i] = alu_operand_1[(`XLEN-1) - i];
   assign alu_operand_2_rev[i] = alu_operand_2[(`XLEN-1) - i];
   assign clmulr_result[i] = clmul_result[(`XLEN-1) - i];
end

/////////////////
//// Min/Max ////
/////////////////
assign max_result  = ~(cmp_neg ^ cmp_overflow) ? alu_operand_1 : alu_operand_2;
assign maxu_result = ~cmp_output[`XLEN] ? alu_operand_1 : alu_operand_2;

assign min_result  = (cmp_neg ^ cmp_overflow) ? alu_operand_1 : alu_operand_2;
assign minu_result = cmp_output[`XLEN] ? alu_operand_1 : alu_operand_2;

///////////////////
//// zbs index ////
///////////////////
assign zbs_index = 1 << (alu_operand_2 & (`XLEN-1));

////////////////////////////////
//// clmul, clmulh, clmulr /////
////////////////////////////////

assign clmul_operand_1 = (alu_b_ops == ALU_ZBC_OPS_CLMULH | alu_b_ops == ALU_ZBC_OPS_CLMULR) ? alu_operand_1_rev : alu_operand_1;
assign clmul_operand_2 = (alu_b_ops == ALU_ZBC_OPS_CLMULH | alu_b_ops == ALU_ZBC_OPS_CLMULR) ? alu_operand_2_rev : alu_operand_2;

always_comb begin
   clmul_result = '0;
   for (int i = 0; i <= `XLEN; i++) begin
      clmul_result = ((clmul_operand_2 >> i) & 1) ? clmul_result ^ (clmul_operand_1 << i) : clmul_result;
   end
end


////////////////////////
//// lzc, tzc, cpop ////
////////////////////////

assign is_ctz  = (alu_b_ops == ALU_ZBB_OPS_CTZ);
assign is_cpop = (alu_b_ops == ALU_ZBB_OPS_CPOP);

assign cnt_data = is_cpop ? alu_operand_1 : (is_ctz ? ~alu_operand_1 : ~alu_operand_1_rev);

always_comb begin
   cnt_result = '0;
   cnt_en     = {32'b0, 1'b1};

   for (int unsigned i=0; i<32; i++) begin
      // keep counting if all the previous bits are 1, starting from LSB
      // always count in case of c_pop OP.
      cnt_en[i+1] = is_cpop || (cnt_en[i] && cnt_data[i]);
      if (cnt_en[i]) begin
         cnt_result = cnt_result + {5'h0, cnt_data[i]};
      end
   end
end

always_comb begin
   case (alu_b_ops)
      ALU_ZBA_OPS_SH1ADD : begin
         alu_b_result = (alu_operand_1 << 1) + alu_operand_2;
      end
      ALU_ZBA_OPS_SH2ADD : begin
         alu_b_result = (alu_operand_1 << 2) + alu_operand_2;
      end
      ALU_ZBA_OPS_SH3ADD : begin
         alu_b_result = (alu_operand_1 << 3) + alu_operand_2;
      end
      ALU_ZBB_OPS_ANDN : begin
         alu_b_result = alu_operand_1 & (~alu_operand_2);
      end
      ALU_ZBB_OPS_ORN : begin
         alu_b_result = alu_operand_1 | (~alu_operand_2);
      end
      ALU_ZBB_OPS_XNOR : begin
         alu_b_result = alu_operand_1 ^ (~alu_operand_2);
      end
      ALU_ZBB_OPS_CLZ,
      ALU_ZBB_OPS_CTZ,
      ALU_ZBB_OPS_CPOP : begin
         alu_b_result = cnt_result;
      end
      ALU_ZBB_OPS_MAX : begin
         alu_b_result = max_result;
      end
      ALU_ZBB_OPS_MAXU : begin
         alu_b_result = maxu_result;
      end
      ALU_ZBB_OPS_MIN : begin
         alu_b_result = min_result;
      end
      ALU_ZBB_OPS_MINU : begin
         alu_b_result = minu_result;
      end
      ALU_ZBB_OPS_SEXTB : begin
         alu_b_result = {{24{alu_operand_1[7]}}, alu_operand_1[7:0]};
      end
      ALU_ZBB_OPS_SEXTH : begin
         alu_b_result = {{16{alu_operand_1[15]}}, alu_operand_1[15:0]};
      end
      ALU_ZBB_OPS_ZEXTH : begin
         alu_b_result = {16'b0, alu_operand_1[15:0]};
      end
      ALU_ZBB_OPS_ROL : begin
         alu_b_result = (alu_operand_1 << shift_amt) | (alu_operand_1 >> (`XLEN-shift_amt));
      end
      ALU_ZBB_OPS_ROR,
      ALU_ZBB_OPS_RORI : begin
         alu_b_result = (alu_operand_1 >> shift_amt) | (alu_operand_1 << (`XLEN-shift_amt));
      end
      ALU_ZBB_OPS_ORC : begin
         alu_b_result = {{8{|alu_operand_1[31:24]}}, {8{|alu_operand_1[23:16]}}, {8{|alu_operand_1[15:8]}}, {8{|alu_operand_1[7:0]}}};
      end
      ALU_ZBB_OPS_REV8 : begin
         alu_b_result = {alu_operand_1[7:0], alu_operand_1[15:8], alu_operand_1[23:16], alu_operand_1[31:24]};
      end
      ALU_ZBS_OPS_BCLR,
      ALU_ZBS_OPS_BCLRI : begin
         alu_b_result = alu_operand_1 & (~zbs_index);
      end
      ALU_ZBS_OPS_BSET,
      ALU_ZBS_OPS_BSETI : begin
         alu_b_result = alu_operand_1 | zbs_index;
      end
      ALU_ZBS_OPS_BEXT,
      ALU_ZBS_OPS_BEXTI : begin
         alu_b_result = |(alu_operand_1 & zbs_index);
      end
      ALU_ZBS_OPS_BINV,
      ALU_ZBS_OPS_BINVI : begin
         alu_b_result = alu_operand_1 ^ zbs_index;
      end
      ALU_ZBC_OPS_CLMUL : begin
         alu_b_result = clmul_result;
      end
      ALU_ZBC_OPS_CLMULR : begin
         alu_b_result = clmulr_result;
      end
      ALU_ZBC_OPS_CLMULH : begin
         alu_b_result = clmulr_result >> 1;
      end
      default: begin
         alu_b_result = '0;
      end
   endcase
end

//============================ Signal evaluations for Multiplication operations ===============================// 
//assign mul_cmd = {((alu_m_ops_ff[1] & alu_m_ops_ff[0]) | (alu_m_ops_ff[1] & ~alu_m_ops_ff[0])),
//  ((alu_m_ops_ff[1] & alu_m_ops_ff[0]) | (~alu_m_ops_ff[1] & alu_m_ops_ff[0]))};

type_alu_m_ops_e                    alu_m_ops;
logic                               is_opr1_signed;
logic                               is_opr2_signed;
logic                               opr1_sgn;
logic                               opr2_sgn;
logic                               mul_cmd, mul_cmd_hi;

logic signed [`XLEN:0]              mul_opr1;
logic signed [`XLEN:0]              mul_opr2;

logic signed [2*`XLEN-1:0]          mul_output;
logic [`XLEN-1:0]                   alu_m_result;


assign alu_m_ops      = type_alu_m_ops_e'(id2exe_ctrl_i.alu_m_ops);
assign mul_cmd        = |alu_m_ops;
assign mul_cmd_hi     = alu_m_ops[1] | alu_m_ops[0];
assign is_opr1_signed = alu_m_ops[1];                
assign is_opr2_signed = alu_m_ops[1] & alu_m_ops[0];

assign opr1_sgn       = is_opr1_signed & alu_operand_1[`XLEN-1];
assign opr2_sgn       = is_opr2_signed & alu_operand_2[`XLEN-1];

assign mul_opr1 = $signed({opr1_sgn, alu_operand_1});
assign mul_opr2 = $signed({opr2_sgn, alu_operand_2});
assign mul_output = mul_opr1 * mul_opr2; 

assign alu_m_result = mul_cmd_hi ? mul_output[2*`XLEN-1:`XLEN]
                    : mul_output[`XLEN-1:0];

//============================ Signal evaluations for CSR operations ===============================// 
always_comb begin

    case (id2exe_ctrl.csr_ops)
        CSR_OPS_WRITE  : begin
            exe2csr_ctrl.csr_rd_req = |rd_addr;
            exe2csr_ctrl.csr_wr_req = 1'b1;
        end
        CSR_OPS_SET,
        CSR_OPS_CLEAR  : begin
            exe2csr_ctrl.csr_rd_req = 1'b1;
            exe2csr_ctrl.csr_wr_req = |rs1_addr;
        end
        default : begin
            exe2csr_ctrl.csr_rd_req = 1'b0;
            exe2csr_ctrl.csr_wr_req = 1'b0;
        end
    endcase
  
end


//==================================== Output signals update ======================================// 

// Update the output data signals for M-Extension
assign exe2div.alu_operand_1 = alu_operand_1;
assign exe2div.alu_operand_2 = alu_operand_2;

// Assign the output control signals for M-Extension
assign exe2div.alu_d_ops  = id2exe_ctrl.alu_d_ops;

// Update the output data signals for LSU
assign exe2lsu_data.alu_result = mul_cmd ? alu_m_result : (bitmanip_cmd ? alu_b_result : alu_result);
assign exe2lsu_data.pc_next    = id2exe_data.pc_next;
assign exe2lsu_data.rs2_data   = operand_rs2_data; // MT: This should be verified due to forwarding

// Assign the output control signals for LSU
assign exe2lsu_ctrl.rd_addr    = id2exe_data.instr[11:7];
assign exe2lsu_ctrl.rd_wrb_sel = id2exe_ctrl.rd_wrb_sel;
assign exe2lsu_ctrl.ld_ops     = id2exe_ctrl.ld_ops;
assign exe2lsu_ctrl.st_ops     = id2exe_ctrl.st_ops;
assign exe2lsu_ctrl.jump_req   = id2exe_ctrl.jump_req;                          
assign exe2lsu_ctrl.branch_req = id2exe_ctrl.branch_req; 
assign exe2lsu_ctrl.amo_ops    = id2exe_ctrl.amo_ops;
assign exe2lsu_ctrl.fence_req = id2exe_ctrl.fence_req;

// If this is CSR operation then destination register write selection is managed 
// by CSR read control signal
assign exe2lsu_ctrl.rd_wr_req  = (|id2exe_ctrl.csr_ops) 
                               ? exe2csr_ctrl.csr_rd_req 
                               : id2exe_ctrl.rd_wr_req;

// Assign the output control signals for CSR   
assign exe2csr_ctrl.csr_ops    = id2exe_ctrl.csr_ops;
assign exe2csr_ctrl.exc_req    = id2exe_ctrl.exc_req;
assign exe2csr_ctrl.irq_req    = id2exe_ctrl.irq_req;                      
assign exe2csr_ctrl.sys_ops    = id2exe_ctrl.sys_ops;  
assign exe2csr_ctrl.fence_i_req = fence_i_req;                     

// Update the output data signals for CSR
assign exe2csr_data.csr_addr   = id2exe_data.instr[31:20];
assign exe2csr_data.pc         = id2exe_data.pc;
assign exe2csr_data.instr      = id2exe_data.instr;
assign exe2csr_data.exc_code   = id2exe_data.exc_code;
assign exe2csr_data.instr_flushed = id2exe_data.instr_flushed;

// MT: The register operand below can be routed through ALU for optimization purpose. The 
// immediate operand can be sent as 5-bit field separately along the data path
assign exe2csr_data.csr_wdata = (id2exe_ctrl.csr_opr_sel == CSR_OPR_REG)
                              ? operand_rs1_data                                 // register operand
                              : {{`XLEN-`RF_AWIDTH{1'b0}}, rs1_addr};            // immediate value

// Signals from EXE module for forwarding evaluation
assign exe2fwd.rs1_addr   = rs1_addr;
assign exe2fwd.rs2_addr   = rs2_addr;
assign exe2fwd.new_pc_req = id2exe_ctrl.jump_req || (id2exe_ctrl.branch_req & branch_res); // fence_i_req ||

// The following signals determine whether the two operands are general-purpose registers
// or not. These are used to minimize the number of stalls in case of load-use RAW hazards
assign exe2fwd.use_rs1 = (id2exe_ctrl.alu_opr1_sel == ALU_OPR1_REG) 
                       | id2exe_ctrl.branch_req;
assign exe2fwd.use_rs2 = (id2exe_ctrl.alu_opr2_sel == ALU_OPR2_REG) 
                       | (|id2exe_ctrl.st_ops)
                       | id2exe_ctrl.branch_req;

// Update the module output signals
assign exe2lsu_ctrl_o  = exe2lsu_ctrl;
assign exe2lsu_data_o  = exe2lsu_data;
assign exe2csr_ctrl_o  = exe2csr_ctrl;
assign exe2csr_data_o  = exe2csr_data;
assign exe2fwd_o       = exe2fwd;

assign exe2div_o       = exe2div;

// Update the feedback signals from EXE to IF stage                         
assign exe2if_fb.pc_new       = {alu_result[31:2], 2'b0};  // fence_i_req ? id2exe_data.pc_next :  
// assign exe2if_fb.icache_flush = fence_i_req;                         
assign exe2if_fb_o            = exe2if_fb;                  

endmodule : execute

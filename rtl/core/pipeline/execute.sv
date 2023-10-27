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
    output type_exe2mul_s                exe2mul_o,

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
type_exe2mul_s                       exe2mul;

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

//============================ Signal evaluation for CSR operations ===============================// 
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
assign exe2mul.alu_operand_1 = alu_operand_1;
assign exe2mul.alu_operand_2 = alu_operand_2;

// Assign the output control signals for M-Extension
assign exe2mul.alu_m_ops  = id2exe_ctrl.alu_m_ops;

// Update the output data signals for LSU
assign exe2lsu_data.alu_result = alu_result;
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

assign exe2mul_o       = exe2mul;

// Update the feedback signals from EXE to IF stage                         
assign exe2if_fb.pc_new       = {alu_result[31:2], 2'b0};  // fence_i_req ? id2exe_data.pc_next :  
// assign exe2if_fb.icache_flush = fence_i_req;                         
assign exe2if_fb_o            = exe2if_fb;                  

endmodule : execute


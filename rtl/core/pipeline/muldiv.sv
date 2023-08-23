// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The multiply/divide module for M-extension.
//
// Author: Ali Imran, UET Lahore
// Date: 20.5.2023

 
`ifndef VERILATOR
`include "../../defines/m_ext_defs.svh"
`else
`include "m_ext_defs.svh"
`endif

module muldiv (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // EXE <---> M-extension interface
    input  wire type_exe2mul_s           exe2mul_i,

    input wire                           fwd2mul_stall_i,
    input wire                           fwd2mul_flush_i,

    // M-extension <---> Forward-stall interface
    output type_mul2fwd_s                mul2fwd_o,

    output type_mul2wrb_s                mul2wrb_o
);


//============================= Local signals and their assignments =============================//
// Local control and data signal structures 
type_exe2mul_s                       exe2mul;
type_mul2fwd_s                       mul2fwd;
type_mul2wrb_s                       mul2wrb;

type_alu_m_ops_e                     alu_m_ops, alu_m_ops_next, alu_m_ops_ff;

// ALU_M signals
logic  [`XLEN-1:0]                   alu_opr_1, alu_m_opr_1, alu_m_opr1_next, alu_m_opr1_ff;
logic  [`XLEN-1:0]                   alu_opr_2, alu_m_opr_2, alu_m_opr2_next, alu_m_opr2_ff;
logic                                alu_m_opr1_sign_next, alu_m_opr1_sign_ff;
logic                                alu_m_opr2_sign_next, alu_m_opr2_sign_ff;


logic                                alu_m_req;
logic                                alu_m_ack_next, alu_m_ack_ff;
logic  [`XLEN-1:0]                   alu_m_result_next;

logic  [2*`XLEN-1:0]                 mult;
logic  [2*`XLEN-1:0]                 mult_ss;
logic  [2*`XLEN-1:0]                 mult_su;
logic  [2*`XLEN-1:0]                 mult_su_int;
logic  [`XLEN-1:0]                   div;
logic  [`XLEN-1:0]                   div_u;
logic  [`XLEN-1:0]                   rem;
logic  [`XLEN-1:0]                   rem_u;

logic                                div_done;
logic                                div_valid;

assign exe2mul = exe2mul_i;

assign alu_m_ops = type_alu_m_ops_e'(exe2mul.alu_m_ops);
assign alu_opr_1 = exe2mul.alu_operand_1;
assign alu_opr_2 = exe2mul.alu_operand_2;

assign alu_m_req = |alu_m_ops_ff;


always_comb begin
    if (alu_m_ops == ALU_M_OPS_DIV || alu_m_ops == ALU_M_OPS_REM || alu_m_ops == ALU_M_OPS_MULHSU) begin
        alu_m_opr_1 = alu_opr_1[`XLEN-1] ? (~alu_opr_1 + 1) : alu_opr_1;
    end else begin
        alu_m_opr_1 = alu_opr_1;
    end
end


always_comb begin
    if (alu_m_ops == ALU_M_OPS_DIV || alu_m_ops == ALU_M_OPS_REM) begin
        alu_m_opr_2 = alu_opr_2[`XLEN-1] ? (~alu_opr_2+1) : alu_opr_2;
    end else begin
        alu_m_opr_2 = alu_opr_2;
    end
end


always_ff @(negedge rst_n, posedge clk ) begin

    if (~rst_n | fwd2mul_flush_i) begin
        alu_m_ops_ff       <= type_alu_m_ops_e'(0);
        alu_m_opr1_ff      <= '0;
        alu_m_opr2_ff      <= '0;
        alu_m_opr1_sign_ff <= '0;
        alu_m_opr2_sign_ff <= '0;
    end else begin
        alu_m_ops_ff       <= alu_m_ops_next; 
        alu_m_opr1_ff      <= alu_m_opr1_next;
        alu_m_opr2_ff      <= alu_m_opr2_next;
        alu_m_opr1_sign_ff <= alu_m_opr1_sign_next;
        alu_m_opr2_sign_ff <= alu_m_opr2_sign_next;
    end 
end

always_comb begin

    if (fwd2mul_stall_i) begin
        alu_m_ops_next       = alu_m_ops_ff; 
        alu_m_opr1_next      = alu_m_opr1_ff;
        alu_m_opr2_next      = alu_m_opr2_ff;
        alu_m_opr1_sign_next = alu_m_opr1_sign_ff;
        alu_m_opr2_sign_next = alu_m_opr2_sign_ff;
    end else begin
        alu_m_ops_next       = alu_m_ops;
        alu_m_opr1_next      = alu_m_opr_1;
        alu_m_opr2_next      = alu_m_opr_2;
        alu_m_opr1_sign_next = alu_opr_1[`XLEN-1];
        alu_m_opr2_sign_next = alu_opr_2[`XLEN-1];
    end
end

always_comb begin
    mult    = alu_m_opr1_ff          * alu_m_opr2_ff;
    mult_ss = $signed(alu_m_opr1_ff) * $signed(alu_m_opr2_ff);
end

always_comb begin
    alu_m_result_next = '0;
    alu_m_ack_next    = '0;
    mult_su_int       = alu_m_opr1_sign_ff ? (~mult + 1) : mult;

    case (alu_m_ops_ff)
        ALU_M_OPS_MUL    : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult_ss[31:0];
        end
        ALU_M_OPS_MULH   : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult_ss[63:32];
        end
        ALU_M_OPS_MULHSU : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult_su_int[63:32];
        end
        ALU_M_OPS_MULHU  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult[63:32];
        end
        ALU_M_OPS_DIV  : begin
            alu_m_ack_next    = div_done; 
            alu_m_result_next = ((alu_m_opr1_sign_ff ^ alu_m_opr2_sign_ff) && ~div_u[`XLEN-1]) 
                              ? (~div_u+1): div_u;
        end
        ALU_M_OPS_DIVU  : begin
            alu_m_ack_next    = div_done; 
            alu_m_result_next = div_u;
        end
        ALU_M_OPS_REM  : begin
            alu_m_ack_next    = div_done; 
            alu_m_result_next = ((alu_m_opr1_sign_ff && ~alu_m_opr2_sign_ff) || (alu_m_opr1_sign_ff && alu_m_opr2_sign_ff)) 
                              ? (~rem_u+1): rem_u;
        end
        ALU_M_OPS_REMU  : begin
            alu_m_ack_next    = div_done; 
            alu_m_result_next = rem_u;
        end
        default : begin
            alu_m_ack_next    = 1'b0;
            alu_m_result_next = '0;
        end
    endcase
end


always_ff @(negedge rst_n, posedge clk ) begin

    if (~rst_n) begin
        alu_m_ack_ff <= 1'b0;       
    end else begin
        alu_m_ack_ff <= alu_m_ack_next; 
    end
end


// Request from M-extension
assign mul2fwd.mul_req = alu_m_req; 

// Response from M-extension
assign mul2wrb.alu_m_result = alu_m_result_next; 
assign mul2fwd.mul_ack      = alu_m_ack_ff;

assign mul2fwd_o = mul2fwd;
assign mul2wrb_o = mul2wrb;

divider divider_module(                                                        // width of numbers in bits
    .clk                (clk),                                                 // clock
    .rst                (rst_n),                                               // reset
    .start_i            (alu_m_ops_ff[3] & ~(alu_m_ack_next | alu_m_ack_ff)),  // start calculation
    .opr1_i             (alu_m_opr1_ff),                                       // dividend (numerator)
    .opr2_i             (alu_m_opr2_ff),                                       // divisor (denominator) 
    .done_o             (div_done),                                            // calculation is complete (high for one tick)
    .quo_o              (div_u),                                               // result value: quotient
    .rem_o              (rem_u)                                                // result: remainder
);

endmodule

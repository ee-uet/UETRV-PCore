// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The divide operation implementation. The base implementation 
//              for divider used here is borrowed from: 
//              https://projectf.io/posts/division-in-verilog/
//
// Author: Ali Imran, UET Lahore
// Date: 20.5.2023


// 

`ifndef VERILATOR
`include "../../defines/m_ext_defs.svh"
`else
`include "m_ext_defs.svh"
`endif


module divider (     
    input wire logic                        clk,     // clock
    input wire logic                        rst,     // reset
    input wire logic                        start_i, // start calculation
    input wire logic [`XLEN-1:0]            opr1_i,  // dividend (numerator)
    input wire logic [`XLEN-1:0]            opr2_i,  // divisor (denominator)
 
    output     logic                        done_o,  // calculation is complete (high for one tick)
    output     logic [`XLEN-1:0]            quo_o,   // result value: quotient
    output     logic [`XLEN-1:0]            rem_o    // result: remainder
);


    logic                       busy_ff;
    logic                       done_ff;
    logic [`XLEN-1:0]           opr2_ff;             // copy of divisor
    logic [`XLEN-1:0]           quo_ff, quo_next;    // intermediate quotient
    logic [`XLEN:0]             acc_ff, acc_next;    // accumulator (1 bit wider)
    logic [`XLEN:0]             rem_ff;              // reminder 
    logic [$clog2(`XLEN)-1:0]   counter;             // iteration counter

    // division algorithm iteration
    always_comb begin
        if (acc_ff >= {1'b0, opr2_ff}) begin
            acc_next = acc_ff - opr2_ff;
            {acc_next, quo_next} = {acc_next[`XLEN-1:0], quo_ff, 1'b1};
        end else begin
            {acc_next, quo_next} = {acc_ff, quo_ff} << 1;
        end
    end

    // calculation control
    always_ff @(posedge clk) begin
        done_ff <= 0;
        if (!rst) begin
            busy_ff <= 0;
            done_ff <= 0;
            quo_ff  <= 0;
            rem_ff  <= 0;
        end else if (busy_ff) begin
            if (counter == `MAX_COUNT) begin                // Check the counter for completion 
                busy_ff <= 0;
                done_ff <= 1;
                quo_ff  <= quo_next;
                rem_ff  <= {1'b0, acc_next[`XLEN:1]};    // undo final shift
            end else begin                               // next iteration
                counter <= counter + 1;
                acc_ff  <= acc_next;
                quo_ff  <= quo_next;
            end
        end else if (start_i) begin
            counter <= 0;
            if (opr2_i == 0) begin                       // handle divide by zero
                busy_ff <= 0;
                done_ff <= 1;
                quo_ff  <= {32{1'b1}};
                rem_ff  <= {1'b0, opr1_i};
            end else begin
                busy_ff <= 1;
                opr2_ff <= opr2_i;
                {acc_ff, quo_ff} <= {{`XLEN{1'b0}}, opr1_i, 1'b0};  // initialize divide operation
            end
        end
    end


assign rem_o  = rem_ff[`XLEN-1:0];
assign quo_o  = quo_ff;
assign done_o = done_ff;

endmodule

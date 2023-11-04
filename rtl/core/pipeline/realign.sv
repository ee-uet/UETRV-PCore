// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: Instruction Realigner for Compressed Extension
//
// Author: Abdul Wadood, UET Lahore
// Date: 24.9.2023

`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module realign (
    input   logic                                   rst_n,
    input   logic                                   clk,

    // IMEM <---> REALIGN interface
    output type_if2icache_s                         ralgn2icache_o,
    input wire type_icache2if_s                     icache2ralgn_i,

    // REALIGN <---> IF interface
    output type_icache2if_s                         ralgn2if_o,
    input wire type_if2icache_s                     if2ralgn_i
);

// local signals for internal use
type_if2icache_s                            ralgn2icache, if2ralgn;
type_icache2if_s                            ralgn2if, icache2ralgn;
type_ralgn_states_e                         ralgn_state_ff, ralgn_state_next;

// Signals for re-aligner state machine
logic [`XLEN-1:0]                           prefetch_buf_data;
logic [`XLEN-1:0]                           realigned_instr;
logic                                       ralgn_sel, ralgn2if_ack, icache_req_next, buf_en;

// Input signal assigments
assign if2ralgn             = if2ralgn_i;
assign icache2ralgn         = icache2ralgn_i;

// concatenated instruction
assign realigned_instr      = {icache2ralgn.r_data[15:0], prefetch_buf_data[31:16]};

// Update the pre-fetch buffer
always_ff @(posedge clk) begin
    if (if2ralgn.req_kill) 
        prefetch_buf_data <= 32'd0;
    else if (icache2ralgn.ack & ~if2ralgn.if_stall & buf_en) begin
        prefetch_buf_data <= icache2ralgn.r_data;
    end
end

// State machine to control the realign.
always_ff @(posedge clk) begin
    if (~rst_n) begin
        ralgn_state_ff <= RALGN_IDLE;
    end else begin
        ralgn_state_ff <= ralgn_state_next;
    end
end

always_comb begin
    unique case (ralgn_state_ff)
        RALGN_IDLE: begin
            ralgn2if_ack            = 1'b1;
            ralgn_sel               = 1'b0;
            buf_en                  = 1'b1;
            icache_req_next         = 1'b0;
            ralgn_state_next        = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
        end
        RALGN_ICACHE_REQ: begin
            ralgn2if_ack            = if2ralgn.req_kill? (if2ralgn.addr[1] ? 1'b0 : 1'b1) : 1'b0;
            ralgn_sel               = 1'b1;
            buf_en                  = 1'b1;
            icache_req_next         = icache2ralgn.ack ? 1'b1 : 1'b0;
            if (if2ralgn.req_kill)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
            else
                ralgn_state_next    = icache2ralgn.ack ? RALGN_COMP_ACK : RALGN_ICACHE_REQ;
        end
        RALGN_COMP_ACK: begin
            ralgn2if_ack            = 1'b1;
            ralgn_sel               = 1'b1;
            buf_en                  = 1'b1;
            icache_req_next         = 1'b1;
            if (if2ralgn.req_kill)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
            else if (icache2ralgn.ack)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_COMP_ACK : RALGN_UNCOMP_ACK;
            else 
                ralgn_state_next    = RALGN_COMP_ACK;
        end
        RALGN_UNCOMP_ACK: begin
            ralgn2if_ack            = 1'b1;
            ralgn_sel               = 1'b0;
            buf_en                  = if2ralgn.addr[1] ? 1'b0 : 1'b1;
            icache_req_next         = 1'b1;
            if (if2ralgn.req_kill)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
            else if (icache2ralgn.ack)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_COMP_ACK : RALGN_UNCOMP_ACK;
            else 
                ralgn_state_next    = RALGN_UNCOMP_ACK;
        end

        default: begin      end
    endcase
end

assign ralgn2icache.icache_flush = if2ralgn.icache_flush;
assign ralgn2icache.if_stall     = if2ralgn.if_stall;
assign ralgn2icache.req          = if2ralgn.req;
assign ralgn2icache.req_kill     = if2ralgn.req_kill;
assign ralgn2icache.addr         = (icache_req_next & ~if2ralgn.req_kill) ? (if2ralgn.addr + 32'b100) : if2ralgn.addr;

assign ralgn2if.ack              = ralgn2if_ack & icache2ralgn.ack;
assign ralgn2if.r_data           = ralgn_sel ? realigned_instr : (icache_req_next ? prefetch_buf_data : icache2ralgn.r_data);
assign ralgn2if.comp_ack         = 1'b0;

// Output signal assigments
assign ralgn2icache_o   = ralgn2icache;
assign ralgn2if_o       = ralgn2if;

endmodule : realign
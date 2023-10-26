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
logic [`XLEN/2-1:0]                         lowerhw_buf;
logic [`XLEN-1:0]                           realigned_instr;
logic                                       ralgnInstr_sel, ralgn2if_ack, nextIcache_req;

// Input signal assigments
assign if2ralgn             = if2ralgn_i;
assign icache2ralgn         = icache2ralgn_i;

// concatenated instruction
assign realigned_instr      = {icache2ralgn.r_data[15:0], lowerhw_buf};

// saving lower half work of every valid instruction
always_ff @(posedge clk) begin
    if(icache2ralgn.ack & ~if2ralgn.if_stall) begin
        lowerhw_buf <= icache2ralgn.r_data[31:16];
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
            ralgnInstr_sel          = 1'b0;
            nextIcache_req          = 1'b0;
            ralgn_state_next        = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
        end
        RALGN_ICACHE_REQ: begin
            ralgn2if_ack            = 1'b0;
            ralgnInstr_sel          = 1'b1;
            if(if2ralgn.req_kill)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
            else begin
                ralgn_state_next    = icache2ralgn.ack ? RALGN_IF_ACK : RALGN_ICACHE_REQ;
                nextIcache_req      = icache2ralgn.ack ? 1'b1 : 1'b0;
            end
        end
        RALGN_IF_ACK: begin
            ralgn2if_ack            = 1'b1;
            ralgnInstr_sel          = 1'b1;
            if(if2ralgn.req_kill)
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_ICACHE_REQ : RALGN_IDLE;
            else if(icache2ralgn.ack) begin
                nextIcache_req      = if2ralgn.addr[1] ? 1'b1 : 1'b0;
                ralgn_state_next    = if2ralgn.addr[1] ? RALGN_IF_ACK : RALGN_IDLE;
            end else 
                ralgn_state_next    = RALGN_IF_ACK;
        end
        default: begin  end
    endcase
end

assign ralgn2icache.icache_flush = if2ralgn.icache_flush;
assign ralgn2icache.if_stall     = if2ralgn.if_stall;
assign ralgn2icache.req          = if2ralgn.req;
assign ralgn2icache.req_kill     = if2ralgn.req_kill;
assign ralgn2icache.addr         = (nextIcache_req & ~if2ralgn.req_kill) ? (if2ralgn.addr + 32'b100) : if2ralgn.addr;

assign ralgn2if.ack              = ralgn2if_ack & icache2ralgn.ack;
assign ralgn2if.r_data           = ralgnInstr_sel ? realigned_instr : icache2ralgn.r_data;
assign ralgn2if.comp_ack         = 0;

// Output signal assigments
assign ralgn2icache_o   = ralgn2icache;
assign ralgn2if_o       = ralgn2if;

endmodule : realign
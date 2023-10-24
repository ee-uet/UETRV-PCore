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

// Signals for re-aligner state machine
logic [`XLEN/2-1:0]                         lowerhw_buf;
logic [`XLEN-1:0]                           realigned_instr;
logic                                       conct_en, ack_en, pcP4_en;

// Input signal assigments
assign if2ralgn             = if2ralgn_i;
assign icache2ralgn         = icache2ralgn_i;

// Icache <---> Realign, pass through by default
assign ralgn2icache         = if2ralgn; 
assign ralgn2icache.addr    = (pcP4_en & ~if2ralgn.req_kill) ? (if2ralgn.addr + 32'b100) : if2ralgn.addr;

assign ralgn2if.ack         = ack_en & icache2ralgn.ack;
assign ralgn2if.r_data      = conct_en ? realigned_instr : icache2ralgn.r_data;

// concatenated instruction
assign realigned_instr = {icache2ralgn.r_data[15:0], lowerhw_buf};

// saving lower half work of every valid instruction
always_ff @(posedge clk) begin
    if(icache2ralgn.ack & ~if2ralgn.if_stall) begin
        lowerhw_buf <= icache2ralgn.r_data[31:16];
    end
end

logic [1:0] cs, ns;
localparam idle = 2'b00;
localparam fetch_mis = 2'b01;
localparam fetch_mis_ack = 2'b10;

always_ff @(posedge clk) begin
    if (~rst_n) begin
        cs <= idle;
    end else begin
        cs <= ns;
    end
end
// next state logic
always_comb begin
    case (cs)
        idle: begin
            ack_en          = 1;
            conct_en        = 0;
            pcP4_en         = 0;
            ns              = if2ralgn.addr[1] ? fetch_mis : idle;
        end
        fetch_mis: begin
            ack_en          = 0;
            conct_en        = 1;
            if(if2ralgn.req_kill)
                ns          = if2ralgn.addr[1] ? fetch_mis : idle;
            else begin
                ns          = icache2ralgn.ack ? fetch_mis_ack : fetch_mis;
                pcP4_en     = icache2ralgn.ack ? 1 : 0;
            end
        end
        fetch_mis_ack: begin
            ack_en          = 1;
            conct_en        = 1;
            if(if2ralgn.req_kill)
                ns          = if2ralgn.addr[1] ? fetch_mis : idle;
            else if(icache2ralgn.ack) begin
                pcP4_en     = if2ralgn.addr[1] ? 1 : 0;
                ns          = if2ralgn.addr[1] ? fetch_mis_ack : idle;
            end
        end
        default: begin
            
        end
    endcase
end

// Output signal assigments
assign ralgn2icache_o   = ralgn2icache;
assign ralgn2if_o       = ralgn2if;

endmodule : realign
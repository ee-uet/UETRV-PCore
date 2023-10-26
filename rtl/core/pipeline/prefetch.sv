// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: Instruction Prefetch module act as top module to handle
//              RISC-V Compressed Instructions.
//
//
// Author: Abdul Wadood, UET Lahore
// Date: 21.10.2023

`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module prefetch (
    input   logic                                   rst_n,
    input   logic                                   clk,
    // IMEM <---> REALIGN interface
    output type_if2icache_s                         pf2icache_o,
    input wire type_icache2if_s                     icache2pf_i,

    // REALIGN <---> IF interface
    output type_icache2if_s                         pf2if_o,
    input wire type_if2icache_s                     if2pf_i
);

`ifdef COMPRESSED

// Interface for Realigner
type_icache2if_s pf2ralgn, ralgn2dcmp, dcmp2if;;
type_if2icache_s ralgn2pf, if2ralgn;

assign pf2ralgn     = icache2pf_i;
assign if2ralgn     = if2pf_i;

realign realign_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // ICache <------> REALIGN
    .ralgn2icache_o             (ralgn2pf),
    .icache2ralgn_i             (pf2ralgn),

    // REALIGN <-----> Decompress
    .ralgn2if_o                 (ralgn2dcmp),
    .if2ralgn_i                 (if2ralgn)
);

decompress decode_module (
    // Decompress <-----> IF
    .ralgn2dcmp_i               (ralgn2dcmp),
    .req_kill_i                 (if2ralgn.req_kill),

    .dcmp2if_o                  (dcmp2if)
);

assign pf2if_o      = dcmp2if;
assign pf2icache_o  = ralgn2pf;

`else 

assign pf2if_o.comp_ack = 1'b0;
assign pf2if_o.ack      = icache2pf_i.ack;
assign pf2if.r_data     = icache2pf_i.r_data;
assign pf2icache_o      = if2pf_i;

`endif

endmodule : prefetch
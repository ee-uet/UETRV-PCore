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

// Interface for Realign
type_icache2if_s pf2ralgn, ralgn2dcmp, dcmp2if;;
type_if2icache_s ralgn2pf, if2ralgn;

assign pf2ralgn     = icache2pf_i;
assign if2ralgn     = if2pf_i;

realign realign_module (
    .rst_n                      (rst_n),
    .clk                        (clk),
    // REALIGN <------> ICache
    .ralgn2icache_o             (ralgn2pf),
    .icache2ralgn_i             (pf2ralgn),
    // IF <-----> REALIGN
    .ralgn2if_o                 (ralgn2dcmp),
    .if2ralgn_i                 (if2ralgn)
);

// Todo: Make the following code consistent with the PCore sv code base. 
//       Functionally working as of now.
wire isComp;
assign dcmp2if = ralgn2dcmp;
assign dcmp2if.comp_ack   = isComp & ~if2ralgn.req_kill;
decompress decompress_module (
    .i_clk       (clk),
    .i_instr     (ralgn2dcmp.r_data),
    .i_ack       (ralgn2dcmp.ack),
    .o_instr     (dcmp2if.r_data),
    .o_iscomp    (isComp)
);

assign pf2if_o      = dcmp2if;
assign pf2icache_o  = ralgn2pf;

endmodule : prefetch
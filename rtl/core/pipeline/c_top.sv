// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  A top level module for the 16 bit compressed instruction support.
//
// Author: Ateeb Tahir, DDRC, UET Lahore
// Date: 21.7.2023


`ifndef VERILATOR
`include "../../defines/c_ext_defs.svh"
`else
`include "c_ext_defs.svh"
`endif


module c_top(
    input   logic           clk,
    input   logic           reset,
    input   logic           br_taken_i,

    // IF <---> C Extension
    input  type_if2cext_s   if2cext_i,
    output type_cext2if_s   cext2if_o
);

logic                   pc_misalign;
logic           [31:0]  instruction;

    
// Demisalignment module to handle pc misalignment,
// due to 16 bit half-word aligned compressed instructions.
c_misalign misalign (
    //inputs
    .clk                    (clk), 
    .reset                  (reset), 

    .sel_for_branch         (br_taken_i),
    .icache_valid           (if2cext_i.icache_valid),
    .pc_in                  (if2cext_i.pc_ff), 
    .inst_in                (if2cext_i.instr_un),

    //outputs
    .stall_pc               (cext2if_o.stall),
    .pc_misaligned_o        (pc_misalign),
    .pc_out                 (cext2if_o.pc_aligned), 
    .inst_out               (instruction)
);

// Decoder for the c-extention that will decode 16-bit instructions
// into their respective 32-bit instructions towards decode module.
c_decode decode (
    //inputs
    .inst                   (instruction),
    .pc                     (if2cext_i.pc_ff[1]),
    .pc_misalign            (pc_misalign),  
    
    //outputs
    .next_comp16            (cext2if_o.is_comp), 
    .compressed_inst_out    (cext2if_o.instr),
    .illegal_inst           (cext2if_o.illegal)
);


endmodule

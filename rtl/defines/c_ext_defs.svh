// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: Definitions file for c-extension signals.
//
// Author: Ateeb Tahir, UET Lahore
// Date: 21.7.2023


`ifndef C_EXT_DEFS
`define C_EXT_DEFS

`include "pcore_config_defs.svh"

// Bus interface from IF to cext
typedef struct packed {                            
    logic [`XLEN-1:0]               instr_un;
    logic [`XLEN-1:0]               pc_ff;
    logic                           icache_valid;
} type_if2cext_s;

// Bus interface from cext to IF
typedef struct packed {      
    logic [`XLEN-1:0]               instr;
    logic [`XLEN-1:0]               pc_aligned;                   
    logic                           stall;
    logic                           is_comp; 
    logic                           illegal;
} type_cext2if_s;

`endif


//deprecated, used opcode values from pcore_interface_defs.svh
/*
typedef enum logic [6:0] { 
    load_opcode     = 7'b0000011;
    store_opcode    = 7'b0100011;
    R_type_opcode   = 7'b0110011;
    I_type_opcode   = 7'b0010011;
    B_type_opcode   = 7'b1100011;
    Jal_opcode      = 7'b1101111;
    Jalr_opcode     = 7'b1100111;
    LUI_opcode      = 7'b0110111;
    AUIPC_opcode    = 7'b0010111;
} type_c_opc;
*/






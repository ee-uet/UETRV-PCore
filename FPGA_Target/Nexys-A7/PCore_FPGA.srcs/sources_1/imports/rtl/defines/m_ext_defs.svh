// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Ali Imran, UET Lahore
// Date: 13.4.2023


`ifndef M_EXT_DEFS
`define M_EXT_DEFS

`include "pcore_interface_defs.svh"

`define WIDTH                        $clog2(`XLEN)
`define MAX_COUNT                    `WIDTH'(`XLEN-1)

typedef struct packed {                            
    logic [`XLEN-1:0]                alu_operand_1;     
    logic [`XLEN-1:0]                alu_operand_2; 
    type_alu_m_ops_e                 alu_m_ops;
} type_exe2mul_s;

typedef struct packed {                            
    logic                            mul_req;
    logic                            mul_ack;
} type_mul2fwd_s;

// M-extension-2-writeback signals
typedef struct packed {                            
    logic  [`XLEN-1:0]                alu_m_result;   
} type_mul2wrb_s;

typedef enum logic [1:0] {
    MULDIV_IDLE  = 2'h0,
    MULDIV_START = 2'h1,
    MULDIV_DONE  = 2'h2
} type_muldiv_states_e;

`endif // M_EXT_DEFS

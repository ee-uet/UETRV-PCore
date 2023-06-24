// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Umer Shahid, UET Lahore
// Date: 13.7.2022


`ifndef A_EXT_DEFS
`define A_EXT_DEFS

`include "pcore_config_defs.svh"

// Atomic memory opertions
 typedef enum logic [3:0] {
    AMO_OPS_NONE = '0,
    AMO_OPS_LR,
    AMO_OPS_SC,
    AMO_OPS_SWAP,
    AMO_OPS_ADD,
    AMO_OPS_XOR,
    AMO_OPS_AND,
    AMO_OPS_OR,
    AMO_OPS_MIN,
    AMO_OPS_MAX,
    AMO_OPS_MINU,
    AMO_OPS_MAXU
} type_amo_ops_e;

// State definitions for AMO state machine
typedef enum logic [2:0] {
    AMO_IDLE  = 3'h0,
    AMO_LOAD  = 3'h1,
    AMO_OP    = 3'h2,
    AMO_ST    = 3'h3,
    AMO_DONE  = 3'h4
} type_amo_states_e;

typedef struct packed {                            
    type_amo_ops_e                   amo_ops;              
    logic                            is_amo; 
    logic                            amo_flush; 

    // Response from memory load operation
    logic                            ack;  
} type_lsu2amo_ctrl_s;

typedef struct packed {                            
    logic [`XLEN-1:0]                lsu_addr;
    logic [`XLEN-1:0]                rs2_operand;

   // Response from memory load operation
    logic [`XLEN-1:0]                r_data; 
} type_lsu2amo_data_s;

typedef struct packed {                      
    logic                            amo_done;      
    logic                            ld_req;     
    logic                            st_req; 
    logic                            rd_wr_req;
} type_amo2lsu_ctrl_s;

typedef struct packed {                            
    logic [`XLEN-1:0]                w_data; 
    logic [`XLEN-1:0]                amo_wrb_data; 
} type_amo2lsu_data_s;

`endif // A_EXT_DEFS

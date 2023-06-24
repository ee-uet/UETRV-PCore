// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Muhammad Tahir, UET Lahore
// Date: 13.6.2023


`ifndef DDR_DEFS
`define DDR_DEFS

`include "pcore_interface_defs.svh"

// DDR memory related parametes 
parameter DDR2_DQ_WIDTH   =  16;
parameter DDR2_DQS_WIDTH  =   2;
parameter DDR2_ADDR_WIDTH =  13;
parameter DDR2_BA_WIDTH   =   3;
parameter DDR2_DM_WIDTH   =   2;

// Cache interface related parametes 
parameter APP_ADDR_WIDTH  =  27;
parameter APP_CMD_WIDTH   =   3;
parameter APP_DATA_WIDTH  = 128;
parameter APP_MASK_WIDTH  =  16; 

localparam CMD_READ       = 3'b001;
localparam CMD_WRITE      = 3'b000;

typedef enum logic [2:0] {
    STATE_CALIB           = 3'b000, 
    STATE_IDLE            = 3'b001,
    STATE_ISSUE_CMD_WDATA = 3'b010,  
    STATE_ISSUE_CMD       = 3'b011, 
    STATE_ISSUE_WDATA     = 3'b100 
} type_ddr_states_e; 

typedef struct packed {
    logic [DDR2_DQ_WIDTH-1:0]   ddr2_dq;
    logic [DDR2_DQS_WIDTH-1:0]  ddr2_dqs_n;
    logic [DDR2_DQS_WIDTH-1:0]  ddr2_dqs_p;
} type_mem2ddr_data_s;

typedef struct packed {
    logic [DDR2_ADDR_WIDTH-1:0] ddr2_addr;
    logic [DDR2_BA_WIDTH-1:0]   ddr2_ba;
    logic                       ddr2_ras_n;
    logic                       ddr2_cas_n;
    logic                       ddr2_we_n;
    logic                       ddr2_ck_p;
    logic                       ddr2_ck_n;
    logic                       ddr2_cke;
    logic                       ddr2_cs_n;
    logic [DDR2_DM_WIDTH-1:0]   ddr2_dm;
    logic                       ddr2_odt;
} type_mem2ddr_ctrl_s;


`endif

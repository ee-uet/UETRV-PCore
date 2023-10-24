// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Muhammad Tahir, UET Lahore
// Date: 13.7.2022


`ifndef PLIC_DEFS
`define PLIC_DEFS

`include "pcore_interface_defs.svh"

parameter int PLIC_SOURCE_COUNT = 2;
parameter int PLIC_TARGET_COUNT = 2;

parameter int PLIC_PRIO_LEVELS  = 7;
parameter int PLIC_SOURCE_WIDTH = $clog2(PLIC_SOURCE_COUNT + 1);
parameter int PLIC_PRIO_WIDTH   = $clog2(PLIC_PRIO_LEVELS + 1);

typedef enum logic [23:0] {
    PLIC_PRIORITY_OFFSET_R  = 24'h000000,
    PLIC_PRIORITY_OFFSET2_R = 24'h000004,
    PLIC_IP_OFFSET_R        = 24'h001000,
    PLIC_IE_OFFSET1_R       = 24'h002000,
    PLIC_IE_OFFSET2_R       = 24'h002080,
    PLIC_PRIOR_TH_OFFSET1_R = 24'h200000,
    PLIC_CLAIM_COMPLETE1_R  = 24'h200004,
    PLIC_PRIOR_TH_OFFSET2_R = 24'h201000,
    PLIC_CLAIM_COMPLETE2_R  = 24'h201004
} type_plic_regs_e;


// PLIC regs-2-gateway interface signals
typedef struct packed { 
  logic [PLIC_TARGET_COUNT-1:0]                            claim_req; //Target read indicator

  logic [PLIC_TARGET_COUNT-1:0]                            complete_req; //Target write indicator
  logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]     complete_idx;
} type_regs2gateway_s; 



`endif // PLIC_DEFS

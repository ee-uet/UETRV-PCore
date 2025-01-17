// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Fazail Ali Butt, UET Lahore
// Date: 30.11.2024

`ifndef STORE_BUFFER_DEFS
`define STORE_BUFFER_DEFS

`include "pcore_interface_defs.svh"
`include "mmu_defs.svh"
`include "cache_defs.svh"

//=========================== Store Buffer related definitions ===========================//
parameter STORE_BUFFER_WIDTH = 4;
parameter BLEN = STORE_BUFFER_WIDTH;

typedef struct packed {
    logic [DCACHE_ADDR_WIDTH-1:0]   addr;
    logic [DCACHE_DATA_WIDTH-1:0]   w_data;
    logic [3:0]                     sel_byte;
    logic                           w_en;
    logic                           req;
} type_stb2dcache_s;

typedef struct packed {                            
    logic [DCACHE_DATA_WIDTH-1:0]   r_data;
    logic                           ack;
} type_dcache2stb_s;

// Bus interface from LSU to STB
typedef struct packed {
    logic [DCACHE_ADDR_WIDTH-1:0]    addr;
    logic [DCACHE_DATA_WIDTH-1:0]    w_data;
    logic [3:0]                      sel_byte;  
    logic                            w_en;  
    logic                            req;
} type_lsummu2stb_s;

typedef struct packed {
    logic                            ack;                            
    logic [DCACHE_DATA_WIDTH-1:0]    r_data;
} type_stb2lsummu_s;

`endif

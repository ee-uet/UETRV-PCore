// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Muhammad Tahir, UET Lahore
// Date: 13.4.2023


`ifndef CACHE_DEFS
`define CACHE_DEFS

`include "pcore_interface_defs.svh"
`include "mmu_defs.svh"

//=========================== Instruction Cache related definitions ===========================//
parameter ICACHE_ADDR_WIDTH  = `XLEN;
parameter ICACHE_DATA_WIDTH  = `XLEN;
parameter ICACHE_LINE_WIDTH  = 128;            // Line width is in bits
parameter ICACHE_NO_OF_SETS  = `ICACHE_SETS; // 2048;

parameter ICACHE_OFFSET_BITS = $clog2(ICACHE_LINE_WIDTH/8);
parameter ICACHE_IDX_BITS    = $clog2(ICACHE_NO_OF_SETS); 
parameter ICACHE_TAG_BITS    = ICACHE_ADDR_WIDTH - ICACHE_IDX_BITS - ICACHE_OFFSET_BITS; 
parameter ICACHE_TAG_LSB     = ICACHE_ADDR_WIDTH - ICACHE_TAG_BITS; 

typedef enum logic [1:0] {
    ICACHE_IDLE, 
    ICACHE_READ_MEMORY, 
    ICACHE_FLUSH, 
    ICACHE_ALLOCATE 
} type_icache_states_e; 

// Bus interface from IF to icache  
typedef struct packed {                            
    logic [ICACHE_ADDR_WIDTH-1:0]    addr;
    logic                            req;
    logic                            req_kill;
    logic                            icache_flush; 
} type_if2icache_s;

// Bus interface from Icache to IF
typedef struct packed {                            
    logic [ICACHE_DATA_WIDTH-1:0]    r_data;
    logic                            ack;  
} type_icache2if_s;


typedef struct packed {
    logic [ICACHE_ADDR_WIDTH-1:0]    addr;
    logic                            req;
    logic                            kill;
} type_icache2mem_s;

typedef struct packed {
    logic [ICACHE_LINE_WIDTH-1:0]    r_data;
    logic                            ack;
} type_mem2icache_s;

  
typedef struct packed {
    logic [ICACHE_TAG_BITS-1:0]      tag;
    logic                            valid;
    logic [ICACHE_LINE_WIDTH-1:0]    data_line;
} type_icache_line_s;


//=========================== Data Cache related definitions ===========================//
parameter DCACHE_ADDR_WIDTH  = `XLEN;
parameter DCACHE_DATA_WIDTH  = `XLEN;
parameter DCACHE_LINE_WIDTH  = 128;            // Line width is in bits
parameter DCACHE_NO_OF_SETS  = `DCACHE_SETS; // 1024;

parameter DCACHE_OFFSET_BITS = $clog2(DCACHE_LINE_WIDTH/8);
parameter DCACHE_IDX_BITS    = $clog2(DCACHE_NO_OF_SETS); 
parameter DCACHE_TAG_BITS    = DCACHE_ADDR_WIDTH - DCACHE_IDX_BITS - DCACHE_OFFSET_BITS; 
parameter DCACHE_TAG_LSB     = DCACHE_ADDR_WIDTH - DCACHE_TAG_BITS; 

parameter DCACHE_MAX_IDX     = DCACHE_IDX_BITS'(DCACHE_NO_OF_SETS - 1);

parameter STORE_BUFFER_WIDTH = 4;
parameter BLEN = STORE_BUFFER_WIDTH;

typedef enum logic [2:0] {
    DCACHE_IDLE, 
    DCACHE_PROCESS_REQ,
    DCACHE_WRITE,
    DCACHE_FLUSH_NEXT,  
    DCACHE_ALLOCATE, 
    DCACHE_WRITE_BACK,
    DCACHE_FLUSH,  
    DCACHE_FLUSH_DONE
} type_dcache_states_e; 

// Bus interface from LSU to dcache  
/*typedef struct packed {                            
    logic [DCACHE_ADDR_WIDTH-1:0]    addr;
    logic [DCACHE_DATA_WIDTH-1:0]    w_data;
    logic [3:0]                      sel_byte;  
    logic                            w_en;  
    logic                            req; 
} type_lsummu2dcache_s;

// Bus interface from Icache to IF
typedef struct packed {                            
    logic [DCACHE_DATA_WIDTH-1:0]    r_data;
    logic                            ack;   
} type_dcache2lsummu_s;*/

// Bus interface from STB to dcache
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

typedef struct packed {
    logic [DCACHE_ADDR_WIDTH-1:0]    addr;
    logic [DCACHE_LINE_WIDTH-1:0]    w_data;
    logic                            req;
    logic                            w_en;  
} type_dcache2mem_s;

typedef struct packed {
    logic [DCACHE_LINE_WIDTH-1:0]    r_data;
    logic                            ack;
} type_mem2dcache_s;

  
typedef struct packed {
    logic [7:0]                      dirty;
    logic                            valid;
    logic [22:0]                     tag;
} type_dcache_tag_s;

typedef bit [DCACHE_LINE_WIDTH-1:0] type_dcache_data_s;

typedef enum logic [1:0] {
    DCACHE_ARBITER_IDLE = 2'h0,
    DCACHE_ARBITER_LSU  = 2'h1,
    DCACHE_ARBITER_MMU  = 2'h2
} type_cache_arbiter_states_e;

typedef enum logic [2:0] {
    MEM_ARBITER_IDLE    = 3'h0,
    MEM_ARBITER_DCACHE  = 3'h1,
    MEM_ARBITER_ICACHE  = 3'h2,
    MEM_ARBITER_IKILL   = 3'h3,
    MEM_ARBITER_DKILL   = 3'h4
} type_mem_arbiter_states_e;

// Interface signals for cache memory arbiter and main memory
typedef type_dcache2mem_s type_cache2mem_s;
typedef type_mem2dcache_s type_mem2cache_s;

`endif

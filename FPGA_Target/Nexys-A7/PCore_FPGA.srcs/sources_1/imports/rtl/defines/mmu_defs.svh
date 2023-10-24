// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Muhammad Tahir, UET Lahore
// Date: 13.12.2022


`ifndef MMU_DEFS
`define MMU_DEFS

`include "pcore_interface_defs.svh"

parameter int unsigned TLB_ENTRIES = 16;
parameter int unsigned DTLB_ENTRIES = 8;
parameter int unsigned DTLB_WIDTH = $clog2(DTLB_ENTRIES);

typedef enum logic [1:0] {
    TLB_REQ_NONE = 2'h0,
    TLB_REQ_INST = 2'h1,
    TLB_REQ_LSU  = 2'h2
} type_tlb_req_e;

// Page table levels for SV32 
typedef enum logic {
    LEVEL_1, 
    LEVEL_2
} type_ptw_levels_e; 

typedef enum logic[2:0] {
    PTW_IDLE,
    PTW_WAIT_R_VALID,
    PTW_PROCESS_PTE,
    PTW_LEVEL_TWO_REQ,
    PTW_PAGE_ERR,
    PTW_PAGE_ACCESS_ERR
} type_ptw_state_e;

//======================= Internal signal structures for MMU sub-modules =======================//

// Page table entry (pte) for sv32
typedef struct packed {
    logic [21:0]                     ppn; // ppn size   
    logic [1:0]                      rsw;
    logic                            d;
    logic                            a;
    logic                            g;
    logic                            u;
    logic                            x;
    logic                            w;
    logic                            r;
    logic                            v;
} type_pte_sv32_s;

typedef struct packed {
    // Tag bit-fields 
    logic [9:0]                      vpn_1;            // 10 bits for SV32
    logic [9:0]                      vpn_0;            // 10 bits for SV32                          
    logic                            valid;
    logic                            page_4M;
    // Data bit-fields
    type_pte_sv32_s                  pte;
} type_tlb_entry_s;

typedef struct packed {                             
    logic [`VPAGE_AWIDTH-1:0]        vpage_addr;
    logic                            tlb_flush;
    logic                            tlb_req;
} type_mmu2tlb_s;

typedef struct packed {                            
    type_pte_sv32_s                  pte;
    logic                            hit;
    logic                            page_4M;
} type_tlb2mmu_s;

typedef struct packed {
    type_pte_sv32_s                  pte;  
    logic [19:0]                     vpn;          // 20 bits for SV32                           
    logic                            page_4M;    
} type_ptw2tlb_s;

 
typedef struct packed { 
    // Signals from CSR
    logic [`PPN_WIDTH-1:0]           satp_ppn;  
    logic                            en_vaddr;
    logic                            en_ld_st_vaddr;
    logic                            mxr; 
    logic                            lsu_flush_req;
    logic                            i_kill_req;

    // Signals from LSU/DTLB
    logic [`VALEN-1:0]               dtlb_vaddr; 
    logic                            dtlb_req;
    logic                            dtlb_hit; 
    logic                            is_store;

    // Signals from IF/ITLB
    logic [`VALEN-1:0]               itlb_vaddr; 
    logic                            itlb_req;
    logic                            itlb_hit;
} type_mmu2ptw_s;

typedef struct packed {
    logic                            ptw_active;
    logic                            iwalk_active;
    logic                            pte_error;         // Set in case of error    
    logic                            access_exc; 
    logic [`VALEN-1:0]               vaddr;              
} type_ptw2mmu_s;


//============================= MMU external signal interfaces =============================//

// Signals from LSU to MMU including address translation request signals
typedef struct packed {                            
    logic [`PPN_WIDTH-1:0]           satp_ppn;  
    logic                            en_vaddr;
    logic                            en_ld_st_vaddr;
    logic                            mxr; 
    logic                            tlb_flush;
    logic                            lsu_flush;
    logic                            d_req;
    logic                            st_req;
    logic                            is_amo;
    logic [`VALEN-1:0]               d_vaddr;   
} type_lsu2mmu_s;

// Address translation response from MMU to LSU  
typedef struct packed {                            
    logic [`PALEN-1:0]               d_paddr;
    logic                            d_hit;  
    logic                            ld_page_fault;
    logic                            st_page_fault; 
} type_mmu2lsu_s;

// Address translation request from IF module to MMU
typedef struct packed {                            
    logic [`XLEN-1:0]                i_vaddr;
    logic                            i_req;
    logic                            i_kill;
} type_if2mmu_s;

// Address translation response from MMU to IF module 
typedef struct packed {                            
    logic [`PALEN-1:0]               i_paddr;
    logic                            i_hit; 
    logic                            i_page_fault; 
} type_mmu2if_s;

// Data request from MMU to Dcache
typedef struct packed {                            
    logic [`XLEN-1:0]                paddr;
    logic                            r_req; 
    logic                            flush_req; 
} type_mmu2dcache_s;

// Response from Dcache to MMU 
typedef struct packed {                            
    logic [`XLEN-1:0]                r_data;
    logic                            r_valid;  
} type_dcache2mmu_s;
 
`endif // MMU_DEFS

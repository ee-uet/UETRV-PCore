// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The MMU top module.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.12.2022


`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../../defines/mmu_defs.svh"
`else
`include "mmu_defs.svh"
`endif

module mmu (

    input   logic                                  rst_n,              // reset
    input   logic                                  clk,                // clock
    
    // LSU <---> MMU interface
    input  wire type_lsu2mmu_s                     lsu2mmu_i,
    output type_mmu2lsu_s                          mmu2lsu_o,

    // IF <---> MMU interface
    input  wire type_if2mmu_s                      if2mmu_i,
    output type_mmu2if_s                           mmu2if_o,

   // MMU <---> Data cache interface
    input wire type_dcache2mmu_s                     dcache2mmu_i,   
    output type_mmu2dcache_s                         mmu2dcache_o       

);

// Signals for IO interface
type_lsu2mmu_s                       lsu2mmu;
type_mmu2lsu_s                       mmu2lsu;

type_if2mmu_s                        if2mmu;
type_mmu2if_s                        mmu2if;

type_dcache2mmu_s                    dcache2mmu;
type_mmu2dcache_s                    mmu2dcache;

// Local signals
type_mmu2ptw_s                       mmu2ptw;
type_ptw2mmu_s                       ptw2mmu;

type_mmu2tlb_s                       mmu2itlb, mmu2dtlb;
type_tlb2mmu_s                       itlb2mmu, dtlb2mmu;

type_ptw2tlb_s                       ptw2tlb;
logic                                itlb_update;
logic                                dtlb_update;

logic                                ld_page_fault;
logic                                st_page_fault; 
logic                                i_page_fault;

// Get the input signals
assign if2mmu   = if2mmu_i;
assign lsu2mmu  = lsu2mmu_i;
assign dcache2mmu = dcache2mmu_i;

//============================= ITLB instantiation and connectivity =============================//
// Signals from MMU to TLB
assign mmu2itlb.vpage_addr = if2mmu.i_vaddr[`VALEN-1:12];
assign mmu2itlb.tlb_req    = if2mmu.i_req;
assign mmu2itlb.tlb_flush  = lsu2mmu.tlb_flush;

// ITLB module instantiation
itlb itlb_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    .ptw2tlb_i                  (ptw2tlb),
    .tlb_update_i               (itlb_update),
    .mmu2tlb_i                  (mmu2itlb),

    .tlb2mmu_o                  (itlb2mmu)            
);


always_comb begin

    // Default assignment corresponding to no address translation 
    mmu2if.i_paddr = {2'b0, if2mmu.i_vaddr};
    mmu2if.i_hit   = if2mmu.i_req;
   
    // Check if vaddr translation is enabled
    if (lsu2mmu.en_vaddr) begin
        mmu2if.i_paddr = {itlb2mmu.pte.ppn, if2mmu.i_vaddr[11:0]};
        mmu2if.i_hit   = itlb2mmu.hit;

        // In case this is a superpage, the page-offset field will be of 22 bits
        if (itlb2mmu.page_4M) begin
            mmu2if.i_paddr[21:12] = if2mmu.i_vaddr[21:12];
        end
    end
  
end


//============================= DTLB instantiation and connectivity =============================//
// Signals from MMU to TLB
assign mmu2dtlb.vpage_addr = lsu2mmu.d_vaddr[`VALEN-1:12];
assign mmu2dtlb.tlb_req    = lsu2mmu.d_req;
assign mmu2dtlb.tlb_flush  = lsu2mmu.tlb_flush;

// DTLB module instantiation
dtlb dtlb_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    .ptw2tlb_i                  (ptw2tlb),
    .tlb_update_i               (dtlb_update),
    .mmu2tlb_i                  (mmu2dtlb),

    .tlb2mmu_o                  (dtlb2mmu)            
);


always_comb begin

    // Default assignment corresponding to no address translation 
    mmu2lsu.d_paddr = {2'b0, lsu2mmu.d_vaddr};
    mmu2lsu.d_hit   = lsu2mmu.d_req;
   
    // Check if vaddr translation is enabled
    if (lsu2mmu.en_ld_st_vaddr) begin
        mmu2lsu.d_paddr = {dtlb2mmu.pte.ppn, lsu2mmu.d_vaddr[11:0]};
        mmu2lsu.d_hit   = dtlb2mmu.hit;

        // In case this is a superpage
        if (dtlb2mmu.page_4M) begin
            mmu2lsu.d_paddr[21:12] = lsu2mmu.d_vaddr[21:12];
        end
        
        
    end

end

// Handling page faults
always_comb begin
ld_page_fault = '0;
st_page_fault = '0;
i_page_fault  = '0;
    
    if (ptw2mmu.pte_error) begin
        if (ptw2mmu.iwalk_active) begin
            i_page_fault = 1'b1;
        end else if (lsu2mmu.st_req | lsu2mmu.is_amo) begin
            st_page_fault = 1'b1;
        end else if (~lsu2mmu.st_req & ~lsu2mmu.is_amo & lsu2mmu.d_req) begin
            ld_page_fault = 1'b1; 
        end 
    end
end

assign mmu2lsu.ld_page_fault = ld_page_fault;
assign mmu2lsu.st_page_fault = st_page_fault;
assign mmu2if.i_page_fault   = i_page_fault;


//============================= PTW instantiation and connectivity =============================//
// Signals from MMU to PTW
//------------------------
// Signals related to CSR
assign mmu2ptw.satp_ppn        = lsu2mmu.satp_ppn;
assign mmu2ptw.en_vaddr        = lsu2mmu.en_vaddr;
assign mmu2ptw.en_ld_st_vaddr  = lsu2mmu.en_ld_st_vaddr;
assign mmu2ptw.mxr             = lsu2mmu.mxr;

assign mmu2ptw.lsu_flush_req   = lsu2mmu.lsu_flush;
assign mmu2ptw.i_kill_req      = if2mmu.i_kill;

// Signals related to DTLB
assign mmu2ptw.dtlb_vaddr      = lsu2mmu.d_vaddr;
assign mmu2ptw.dtlb_req        = lsu2mmu.d_req & lsu2mmu.en_ld_st_vaddr;
assign mmu2ptw.dtlb_hit        = dtlb2mmu.hit;
assign mmu2ptw.is_store        = lsu2mmu.st_req;

// Signals related to ITLB
assign mmu2ptw.itlb_vaddr      = if2mmu.i_vaddr;
assign mmu2ptw.itlb_req        = if2mmu.i_req & lsu2mmu.en_vaddr;
assign mmu2ptw.itlb_hit        = itlb2mmu.hit;

// PTW module instantiation
ptw ptw_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    .mmu2ptw_i                  (mmu2ptw),
    .ptw2mmu_o                  (ptw2mmu),

    .ptw2tlb_o                  (ptw2tlb),
    .itlb_update_o              (itlb_update),
    .dtlb_update_o              (dtlb_update),

    .dcache2ptw_i                 (dcache2mmu),
    .ptw2dcache_o                 (mmu2dcache)            
);


assign mmu2lsu_o  = mmu2lsu;
assign mmu2if_o   = mmu2if;
assign mmu2dcache_o = mmu2dcache;

endmodule // mmu


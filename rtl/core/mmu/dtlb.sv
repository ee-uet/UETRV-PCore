// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The TLB for data memory interface.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.12.2022


`ifndef VERILATOR
`include "../../defines/mmu_defs.svh"
`else
`include "mmu_defs.svh"
`endif

module dtlb (

    input   logic                                  rst_n,              // reset
    input   logic                                  clk,                // clock

    // PTW <---> TLB interface
    input wire type_ptw2tlb_s                      ptw2tlb_i,
    input logic                                    tlb_update_i,

    // MMU <---> TLB interface
    input  wire type_mmu2tlb_s                     mmu2tlb_i,
    output type_tlb2mmu_s                          tlb2mmu_o

);


// Local signals
type_mmu2tlb_s                      mmu2tlb;
type_tlb2mmu_s                      tlb2mmu;

type_ptw2tlb_s                      ptw2tlb;

logic [9:0]                         vpn_0, vpn_1;
logic [DTLB_WIDTH-1:0]              r_index, w_index;

type_tlb_entry_s [DTLB_ENTRIES-1:0]  tlb_array_ff, tlb_array_next;

assign mmu2tlb = mmu2tlb_i;
assign ptw2tlb = ptw2tlb_i;

// Check for super-page to decide the index field place in the virtual address
// to be used by TLB
assign r_index = mmu2tlb.vpage_addr[DTLB_WIDTH+9:10];
//assign sp_sel   = tlb_array_ff[sp_index].page_4M && tlb_array_ff[sp_index].valid;
//assign r_index  = sp_sel ? sp_index : mmu2tlb.vpage_addr[DTLB_WIDTH-1:0];

// Virtual page number is 20-bit 
assign vpn_0 = mmu2tlb.vpage_addr[9:0];
assign vpn_1 = mmu2tlb.vpage_addr[19:10];
 
//=================================== Address tranlation =====================================//
always_comb begin

    // Default assignment
    tlb2mmu = '{default: 0};
   
    if (mmu2tlb.tlb_req && (tlb_array_ff[r_index].vpn_1 == vpn_1) && (tlb_array_ff[r_index].valid)) begin
        if (tlb_array_ff[r_index].vpn_0 == vpn_0 || tlb_array_ff[r_index].page_4M) begin
            tlb2mmu.pte     = tlb_array_ff[r_index].pte;
            tlb2mmu.hit     = 1'b1;
            tlb2mmu.page_4M = tlb_array_ff[r_index].page_4M;
        end
    end

end

//=================================== Update and flushing =====================================//

always_comb begin
    tlb_array_next = tlb_array_ff;
  //  w_index = ptw2tlb.vpn[DTLB_WIDTH-1:0];
    w_index = ptw2tlb.vpn[DTLB_WIDTH+9:10];

    if (mmu2tlb.tlb_flush) begin             // Flush all the enteries of the TLB
        for (int unsigned i = 0; i < DTLB_ENTRIES; i++) begin         
            tlb_array_next[i].valid = 1'b0;
        end
    end else if (tlb_update_i) begin   // Update the corresponding TLB entry 

    //    if (ptw2tlb.page_4M) begin
   //         w_index = ptw2tlb.vpn[DTLB_WIDTH+9:10];
   //     end
        tlb_array_next[w_index].pte     = ptw2tlb.pte;
        tlb_array_next[w_index].page_4M = ptw2tlb.page_4M;
        tlb_array_next[w_index].vpn_1   = ptw2tlb.vpn[19:10];
        tlb_array_next[w_index].vpn_0   = ptw2tlb.vpn[9:0];
        tlb_array_next[w_index].valid   = 1'b1;
    end
end

always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
        tlb_array_ff <= '{default: 0};
    end else begin       
        tlb_array_ff <= tlb_array_next;
    end
end


// Update the output signals
assign tlb2mmu_o = tlb2mmu;

endmodule // tlb


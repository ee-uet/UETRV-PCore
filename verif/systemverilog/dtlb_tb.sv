`timescale 1ns/1ps
`include "../../defines/mmu_defs.svh"

module dtlb_tb;

// Signals
    reg                                  rst_n;          
    reg                                clk;            

    // PTW <---> TLB interface
    type_ptw2tlb_s                      ptw2tlb_i;
    reg                                      tlb_update_i;

    // MMU <---> TLB interface
    type_mmu2tlb_s                          mmu2tlb_i;
    type_tlb2mmu_s                          tlb2mmu_o;
 dtlb dut(
 	.clk(clk),
 	.rst_n(rst_n),
 	.ptw2tlb_i(ptw2tlb_i),
    .tlb_update_i(tlb_update_i),
    .mmu2tlb_i(mmu2tlb_i),
    .tlb2mmu_o(tlb2mmu_o)
    );
// Clock Generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;  // 10ns clock period
    end
    initial begin
        rst_n = 0;
        repeat(10)@(posedge clk);
        rst_n = 1;
        @(posedge clk);
        
        
        //----------------------superpage-------------------------
        
        // Test case 1: Superpage -miss
        tlb_update_i=1;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80000;
        ptw2tlb_i.vpn=20'h80000;
        ptw2tlb_i.pte=32'h0020004f;
        ptw2tlb_i.page_4M=1;
        repeat(5)@(posedge clk);
        
        // Test case 2: Superpage  -hit
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80000;
        ptw2tlb_i.vpn=20'h80000;
        ptw2tlb_i.pte=32'h0200004f;
        ptw2tlb_i.page_4M=1;
        repeat(5)@(posedge clk);

        // Test case 3: Normal -miss
        tlb_update_i=1;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80900;
        ptw2tlb_i.vpn=20'h80900;
        ptw2tlb_i.pte=32'h0200004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);

        // Test case 4: Normal -hit
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80900;
        ptw2tlb_i.vpn=20'h80900;
        ptw2tlb_i.pte=32'h0020004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);

        // Test case 5: Normal -miss (max index)
        tlb_update_i=1;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h81c00;
        ptw2tlb_i.vpn=20'h81c00;
        ptw2tlb_i.pte=32'h0200004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);

        // Test case 6: Normal -hit (max index)
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h81c00;
        ptw2tlb_i.vpn=20'h81c00;
        ptw2tlb_i.pte=32'h0020004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);

        // Test case 7: Flush
        tlb_update_i=0;
        mmu2tlb_i.tlb_flush=1;
        repeat(20)@(posedge clk);

        //----------------TESTS TO VALIDATE FLUSH-------------

        // Test case 8: Superpage  -should be miss
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80000;
        ptw2tlb_i.vpn=20'h80000;
        ptw2tlb_i.pte=32'h0200004f;
        ptw2tlb_i.page_4M=1;
        repeat(5)@(posedge clk);

        // Test case 9: Normal -should be miss
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80900;
        ptw2tlb_i.vpn=20'h80900;
        ptw2tlb_i.pte=32'h0020004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);

        //----------------TESTS TO VALIDATE REPLACEMENT ON SPECIFIC INDEX-------------

        // Test case 10: Normal -miss
        tlb_update_i=1;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80000;
        ptw2tlb_i.vpn=20'h80000;
        ptw2tlb_i.pte=32'h0200004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);

        // Test case 11: Superpage  -should be miss
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80000;
        ptw2tlb_i.vpn=20'h80000;
        ptw2tlb_i.pte=32'h0200004f;
        ptw2tlb_i.page_4M=1;
        repeat(5)@(posedge clk);

        // Test case 12: Normal -should be hit
        tlb_update_i=0;
        mmu2tlb_i.tlb_req=1;
        mmu2tlb_i.vpage_addr=32'h80000;
        ptw2tlb_i.vpn=20'h80000;
        ptw2tlb_i.pte=32'h0020004f;
        ptw2tlb_i.page_4M=0;
        repeat(5)@(posedge clk);



        
        
        
        
    $stop;
    end

endmodule

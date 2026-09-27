`timescale 1ns/1ps
`include "../../defines/mmu_defs.svh"

module mmu_tb;

// Signals
  reg clk;
  reg rst_n;
  type_lsu2mmu_s                          lsu2mmu_i;
  type_mmu2lsu_s                          mmu2lsu_o;

  type_if2mmu_s                             if2mmu_i;
  type_mmu2if_s                             mmu2if_o;
  type_dcache2mmu_s                         dcache2mmu_i;
  type_mmu2dcache_s                         mmu2dcache_o; 
 mmu dut(
 	.clk(clk),
 	.rst_n(rst_n),
 	.lsu2mmu_i(lsu2mmu_i),
	.mmu2lsu_o(mmu2lsu_o),
        .if2mmu_i(if2mmu_i),
        .mmu2if_o(mmu2if_o),
        .dcache2mmu_i(dcache2mmu_i),
        .mmu2dcache_o(mmu2dcache_o)
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
        
        // Test case 1: Superpage -itlb
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110011111000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h0020004f;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 2: Superpage -dtlb
        lsu2mmu_i.en_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.satp_ppn=22'b0100110011111000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h0020004f;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 3: Superpage misalign
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110011111000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h0020c04f;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        //----------------------itlb_miss-------------------------
        
        // Test case 4: Two level paging with not readable and writeable
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h0820004d;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);   
        
        
        // Test case 5: Two level paging 
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h0820004f;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 6: Two level paging with invalid bit
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h0820004e;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
               
        
        // Test case 7: Two level paging with not executeable
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h08200047;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 8: Two level paging with not accessible
        lsu2mmu_i.en_vaddr=1;
        if2mmu_i.i_req=1;
        dut.mmu2ptw.itlb_hit=0;
        lsu2mmu_i.d_req=0;
        lsu2mmu_i.en_ld_st_vaddr=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        if2mmu_i.i_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h0820000f;
        repeat(2)@(posedge clk);
        lsu2mmu_i.en_vaddr=0;
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        //----------------------dtlb_miss-------------------------
        
        // Test case 9: Two level paging with not readable but mxr set
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.mxr=1;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h08200049;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 10: Two level paging with not readable and not mxr set
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.st_req=0;
        lsu2mmu_i.is_amo=0;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.mxr=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h08200049;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 11: Two level paging with store operation and not writeable
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.st_req=1;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h0820004b;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 12: Two level paging with store operation and not dirty
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.st_req=1;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200041;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_data=32'h0820c04f;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        //---------------------Permission Bits----------------------------
        
        // Test case 13: first level pte (r=1,x=0,w=1)
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.st_req=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200047;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 14: first level pte (r=0,x=1,w=0)
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.st_req=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200049;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        // Test case 15: first level pte (r=1,x=0,w=0)
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.st_req=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h04200043;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
         // Test case 16: first level pte (r=1,x=1,w=0)
        lsu2mmu_i.en_ld_st_vaddr=1;
        dut.mmu2ptw.dtlb_hit=0;
        lsu2mmu_i.d_req=1;
        lsu2mmu_i.en_ld_st_vaddr=1;
        lsu2mmu_i.st_req=0;
        lsu2mmu_i.satp_ppn=22'b0100110010001000010101;
        lsu2mmu_i.d_vaddr=32'h80000020;
        repeat(5)@(posedge clk);
        dcache2mmu_i.r_valid=1;
        dcache2mmu_i.r_data=32'h0420004b;
        repeat(2)@(posedge clk);
        dcache2mmu_i.r_valid=0;
        repeat(5)@(posedge clk);
        
        
        
        
    $stop;
    end

endmodule

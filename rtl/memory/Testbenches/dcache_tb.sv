`timescale 1ns / 1ps

`ifndef VERILATOR
`include "../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif
module dcache_tb;

    // Clock and Reset Signals
    reg clk;
    reg rst_n;

    // Control and Interface Signals
    reg dmem_sel_i;
    reg dcache_flush_i;
    reg dcache_kill_i;
    type_lsummu2dcache_s lsummu2dcache;
    type_dcache2lsummu_s dcache2lsummu;
    type_mem2dcache_s mem2dcache;
    type_dcache2mem_s dcache2mem;
    wire dcache2mem_kill;
    logic [10:0] index;
    logic wrb;

    // Instantiate the Data Cache Top Module
    wb_dcache_top dcache (
        .clk(clk),
        .rst_n(rst_n),
        .dmem_sel_i(dmem_sel_i),
        .dcache_flush_i(dcache_flush_i),
        .dcache_kill_i(dcache_kill_i),
        .lsummu2dcache_i(lsummu2dcache),
        .dcache2lsummu_o(dcache2lsummu),
        .mem2dcache_i(mem2dcache),
        .dcache2mem_o(dcache2mem),
        .dcache2mem_kill_o(dcache2mem_kill)
    );

    // Clock Generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;  // 10ns clock period
    end

    task cache_read_miss(input [DCACHE_ADDR_WIDTH-1:0] addr);
        begin
            @(posedge clk);
            mem2dcache.ack=0;
            lsummu2dcache.req = 1;
            lsummu2dcache.addr = addr;
            $display("================================");
            $display("=                              =");
            $display("=    Cache Read Miss Test      =");
            $display("=                              =");
            $display("================================");
            repeat(2)@(posedge clk);
            if (dcache.wb_dcache_controller_module.dcache_hit) begin
            	$display("------Failure------");
            end else if (dcache.wb_dcache_controller_module.dcache_miss) begin
            	$display("------Success------");
            end else begin
            	$display("------Anomaly------");
            end
            $display("\nBEFORE Cache Allocation");
            display_cacheline(addr);
            repeat(20)@(posedge clk);
            mem2dcache.ack=1;
        end
    endtask
    task cache_read_hit(input [DCACHE_ADDR_WIDTH-1:0] addr);
        begin
            @(posedge clk);
            lsummu2dcache.req = 1;
            lsummu2dcache.addr = addr;
            $display("================================");
            $display("=                              =");
            $display("=     Cache Read Hit Test      =");
            $display("=                              =");
            $display("================================");
            repeat(2)@(posedge clk);
            if (dcache.wb_dcache_controller_module.dcache_hit) begin
            	$display("------Success------");
            end else if (dcache.wb_dcache_controller_module.dcache_miss) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
        end
    endtask

    task cache_write_hit(input [DCACHE_ADDR_WIDTH-1:0] addr, input [DCACHE_DATA_WIDTH-1:0] data);
        begin
            @(posedge clk);
            lsummu2dcache.req = 1;
            lsummu2dcache.w_en = 1;
            lsummu2dcache.addr = addr;
            lsummu2dcache.w_data = data;
            $display("================================");
            $display("=                              =");
            $display("=     Cache Write Hit Test     =");
            $display("=                              =");
            $display("================================");
            $display("\nBEFORE Writing Cache-Line");
            display_cacheline(addr);
            repeat(2)@(posedge clk);
            if (dcache.wb_dcache_controller_module.dcache_hit) begin
            	$display("------Success------");
            end else if (dcache.wb_dcache_controller_module.dcache_miss) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
            
        end
    endtask
    task cache_write_miss(input [DCACHE_ADDR_WIDTH-1:0] addr, input [DCACHE_DATA_WIDTH-1:0] data);
        begin
            @(posedge clk);
            mem2dcache.ack=0;
            lsummu2dcache.req = 1;
            lsummu2dcache.w_en = 1;
            lsummu2dcache.addr = addr;
            lsummu2dcache.w_data = data;
            $display("================================");
            $display("=                              =");
            $display("=     Cache Write Miss Test    =");
            $display("=                              =");
            $display("================================");
            repeat(2)@(posedge clk);
            if (dcache.wb_dcache_controller_module.cache_evict_req_i) begin
            	wrb=1;
            end
            else begin
                wrb=0;
            end
            if (dcache.wb_dcache_controller_module.dcache_miss) begin
            	$display("------Success------");
            end else if (dcache.wb_dcache_controller_module.dcache_hit) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
            repeat(20)@(posedge clk);
            mem2dcache.ack=1;
            $display("\nAFTER Cache-Line Allocation");
            if (wrb) begin
            	repeat(3)@(posedge clk);
            end else begin
            	repeat(2)@(posedge clk);
            end
            display_cacheline(addr);
        end
    endtask
    task display_cacheline(input [DCACHE_ADDR_WIDTH-1:0] addr);
    begin
          index=addr[14:4];
          $display("Cache-line with %h at index %h  = %h", addr, index, dcache.wb_dcache_datapath_module.dcache_data_ram_module.dcache_dataram[index]);
          end
    endtask
    task display_read_data(input [DCACHE_ADDR_WIDTH-1:0] addr);
    begin
          index=addr[14:4];
          $display("\nREADING CACHE-LINE");
          $display("Cache-line with %h at index %h  = %h", addr, index, dcache2lsummu.r_data);
          end
    endtask
    // Test Cache Hit Scenario
    initial begin
         rst_n = 0;
         repeat(10)@(posedge clk);
         rst_n = 1;
        //------------------------------------------------------------------------------------------------------------------------
        // Cache read miss from a lowest index
        @(posedge clk);
        mem2dcache.r_data=128'habcdef0324561782f2f2f2ffcbfcb212; 
        dmem_sel_i=1;
        cache_read_miss(32'h80000000);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        $display("\nAFTER Cache Allocation");
        display_cacheline(32'h80000000);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        // Cache read miss from a highest index
        @(posedge clk);
        mem2dcache.r_data=128'h87654321876543218765432187654321; 
        dmem_sel_i=1;
        cache_read_miss(32'h80007ff0);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        $display("\nAFTER Cache Allocation");
        display_cacheline(32'h80007ff0);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read hit from a lowest index
        dmem_sel_i=1;
        cache_read_hit(32'h80000000);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        display_read_data(32'h80000000);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read hit from a lowest index+0x4
        dmem_sel_i=1;
        cache_read_hit(32'h80000004);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        display_read_data(32'h80000004);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read hit from a lowest index+0x8
        dmem_sel_i=1;
        cache_read_hit(32'h80000008);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        display_read_data(32'h80000008);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read hit from a lowest index+0xc
        dmem_sel_i=1;
        cache_read_hit(32'h8000000c);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        display_read_data(32'h8000000c);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read hit from a highest index
        dmem_sel_i=1;
        cache_read_hit(32'h80007ff0);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        display_read_data(32'h80007ff0);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read miss from lower index+0x10
        dmem_sel_i=1;
        mem2dcache.r_data=128'h26262626262626262626262626262626; 
        cache_read_miss(32'h80000010);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        $display("\nAFTER Cache Allocation");
        display_cacheline(32'h80000010);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read miss from in between index
        dmem_sel_i=1;
        mem2dcache.r_data=128'h12345678123456781234567812345678; 
        cache_read_miss(32'h80000c20);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        $display("\nAFTER Cache Allocation");
        display_cacheline(32'h80000c20);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache write hit (all Bytes of a word)
        dmem_sel_i=1;
        lsummu2dcache.sel_byte=4'b1111;
        cache_write_hit(32'h80000c20,32'hfafafafa);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        lsummu2dcache.w_en = 0;
        $display("\nAFTER Writing Cache-Line");
        @(posedge clk);
        display_cacheline(32'h80000c20);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache read hit(checking after writing)
        dmem_sel_i=1;
        cache_read_hit(32'h80000c20);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        display_read_data(32'h80000000);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache write hit (first byte of a word)
        dmem_sel_i=1;
        lsummu2dcache.sel_byte=4'b0001;
        cache_write_hit(32'h80000c20,32'hbcbcbcbc);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        lsummu2dcache.w_en = 0;
        $display("\nAFTER Writing Cache-Line");
        @(posedge clk);
        display_cacheline(32'h80000c20);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
         //Cache write hit(first two bytes of a word)
        dmem_sel_i=1;
        lsummu2dcache.sel_byte=4'b0011;
        cache_write_hit(32'h80000c20,32'h65656565);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        lsummu2dcache.w_en = 0;
        $display("\nAFTER Writing Cache-Line");
        @(posedge clk);
        display_cacheline(32'h80000c20);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
         //Cache write hit(first three bytes of a word)
        dmem_sel_i=1;
        lsummu2dcache.sel_byte=4'b0111;
        cache_write_hit(32'h80000c20,32'h23232323);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        lsummu2dcache.w_en = 0;
        $display("\nAFTER Writing Cache-Line");
        @(posedge clk);
        display_cacheline(32'h80000c20);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache write miss
        dmem_sel_i=1;
        mem2dcache.r_data=128'h78787878787878787878787878787878;
        lsummu2dcache.sel_byte=4'b1001;
        cache_write_miss(32'h8000030c,32'h14141414);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        lsummu2dcache.w_en = 0;
        $display("\nAFTER Writing Cache-Line");
        @(posedge clk);
        display_cacheline(32'h8000030c);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Cache write miss
        dmem_sel_i=1;
        lsummu2dcache.sel_byte=4'b1101;
        mem2dcache.r_data=128'h03203211032032110320321103203211;
        cache_write_miss(32'h8000830c,32'h90909090);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        lsummu2dcache.w_en = 0;
        $display("\nAFTER Writing Cache-Line");
        @(posedge clk);
        display_cacheline(32'h8000830c);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        //Flush
        dcache_flush_i=1;
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        dcache_flush_i=0;
        $display("============Flush Done============");
        //------------------------------------------------------------------------------------------------------------------------
        // Cache read miss after Flushing
        @(posedge clk);
        mem2dcache.r_data=128'hf231f478f231f478f231f478f231f478; 
        dmem_sel_i=1;
        cache_read_miss(32'h80007ff0);
        while(!dcache2lsummu.ack) begin
        	@(posedge clk);
        end
        lsummu2dcache.req = 0;
        $display("\nAFTER Cache Allocation");
        display_cacheline(32'h80007ff0);
        repeat(10)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        // Cache read without dmem_sel
        @(posedge clk);
        dmem_sel_i=0;
        lsummu2dcache.req = 1;
        lsummu2dcache.addr = 32'h80007ff0;
        while(!dcache2mem_kill) begin
        	@(posedge clk);
        end
        if (dcache2mem_kill) begin
        	$display("Request Killed");
        end else begin
        	$display("Request Not Killed");
        end
        repeat(5)@(posedge clk);
        //------------------------------------------------------------------------------------------------------------------------
        // Cache read with kill request signal
        @(posedge clk);
        dmem_sel_i=1;
        dcache_kill_i=1;
        lsummu2dcache.req = 1;
        lsummu2dcache.addr = 32'h80007ff0;
        while(!dcache2mem_kill) begin
        	@(posedge clk);
        end
        if (dcache2mem_kill) begin
        	$display("Request Killed");
        end else begin
        	$display("Request Not Killed");
        end
        repeat(5)@(posedge clk);
        $stop;
    end

endmodule


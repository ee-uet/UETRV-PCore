`timescale 1ns / 1ps
`include "../../defines/cache_defs.svh"

module icache_top_tb;

    // Clock and Reset Signals
    reg clk;
    reg rst_n;

    // Control and Interface Signals
    reg imem_sel_i;
    type_if2icache_s if2icache;
    type_icache2if_s icache2if;
    type_mem2icache_s mem2icache;
    type_icache2mem_s icache2mem;

    // Instantiate the Instruction Cache Top Module
    icache_top icache (
        .clk(clk),
        .rst_n(rst_n),
        .imem_sel_i(imem_sel_i),
        .if2icache_i(if2icache),
        .icache2if_o(icache2if),
        .mem2icache_i(mem2icache),
        .icache2mem_o(icache2mem)
    );

    // Clock Generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;  // 10ns clock period
    end

    // Reset Task
    task reset_cache();
        begin
            rst_n = 1'b0;
            imem_sel_i = 1'b0;
            if2icache = '0;
            mem2icache = '0;
            repeat(2) @(posedge clk);
            rst_n = 1'b1;
        end
    endtask

    // Task: Read from Cache
    task cache_read_miss(input [ICACHE_ADDR_WIDTH-1:0] addr);
        begin
            @(posedge clk);
            if2icache.req = 1'b1;
            if2icache.addr = addr;
            mem2icache.ack = 1'b0;
            $display("================================");
            $display("=                              =");
            $display("=    Cache Read Miss Test      =");
            $display("=                              =");
            $display("================================");
            repeat(3) @(posedge clk);
            if (icache.icache_top.icache_miss) begin
            	$display("------Success------");
            end else if (icache.icache_top.icache_hit) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
            repeat(5) @(posedge clk);
            mem2icache.ack = 1'b1;
            @(posedge clk);
            mem2icache.ack = 1'b0;
        end
    endtask

        // Task: Read from Cache
    task cache_read_hit(input [ICACHE_ADDR_WIDTH-1:0] addr);
        begin
            @(posedge clk);
            if2icache.req = 1'b1;
            if2icache.addr = addr;
            $display("================================");
            $display("=                              =");
            $display("=    Cache Read Hit Test       =");
            $display("=                              =");
            $display("================================");
            repeat(3) @(posedge clk);
            if (icache.icache_top.icache_hit) begin
            	$display("------Success------");
            end else if (icache.icache_top.icache_miss) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
        end
    endtask

    // Task: Flush the Cache
    task cache_flush();
        begin
            @(posedge clk);
            if2icache.icache_flush = 1'b1;
            $display("================================");
            $display("=                              =");
            $display("=       Cache Flush Test       =");
            $display("=                              =");
            $display("================================");
            while (~icache.icache_top.icache_flush_done) begin
                @(posedge clk);
            end
            if (icache.icache_top.icache_flush_done) begin
            	$display("------Success------");
            end else if (~icache.icache_top.icache_flush_done) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
        end
    endtask

    // Task: Access Cache with Kill Signal
    task cache_access_kill(input [ICACHE_ADDR_WIDTH-1:0] addr);
        begin
            @(posedge clk);
            if2icache.req = 1'b1;
            if2icache.addr = addr;
            repeat(2)@(posedge clk);
            if2icache.req_kill = 1'b1;
            repeat(2)@(posedge clk);
            if ((icache.icache_top.icache_state_ff == ICACHE_IDLE) && if2icache.req_kill) begin
            	$display("------Success------");
            end else if (icache.icache_top.icache_state_ff != ICACHE_IDLE) begin
            	$display("------Failure------");
            end else begin
            	$display("------Anomaly------");
            end
            if2icache.req_kill = 1'b0;
        end
    endtask

    // Test Cases of ICACHE
    initial begin
        $display("Starting ICache Testbench...");
        //------------------------------------------------------------------------------------------------------------------------
        // Reset the Cache
        $display("Reseting ICache");
        reset_cache();
        //------------------------------------------------------------------------------------------------------------------------
        // 1. Perform Cache Read Miss from base index
        @(posedge clk)
        mem2icache.r_data = 128'h12345678123456781234567812345678;
        $display("Test Case 1: Cache Read Miss");
        imem_sel_i = 1'b1;
        cache_read_miss(32'h80000000);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 2. Perform Cache Read Miss from maximum index
        @(posedge clk)
        mem2icache.r_data = 128'habcd1234abcd5678abcd1234abcd5678;
        $display("Test Case 2: Cache Read Miss");
        imem_sel_i = 1'b1;
        cache_read_miss(32'h80001ff0);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 3. Perform Cache Read Miss from middle index
        @(posedge clk)
        mem2icache.r_data = 128'h1234abcd5678abcd1234abcd5678abcd;
        $display("Test Case 3: Cache Read Miss");
        imem_sel_i = 1'b1;
        cache_read_miss(32'h800003f0);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 4. Perform Cache Read Hit from lowest index
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 4: Cache Read Hit");
        cache_read_hit(32'h80000000);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 5. Perform Cache Read Hit from middle index
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 5: Cache Read Hit");
        cache_read_hit(32'h800003f0);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 6. Perform Cache Read Hit from maximum index
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 6: Cache Read Hit");
        cache_read_hit(32'h80001ff0);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 7. Verify Cache Flush Behavior
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 7: Cache Flush");
        cache_flush();
        if2icache.icache_flush = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 8. Verify Cache Read Miss after flush
        @(posedge clk)
        mem2icache.r_data = 128'h10101010101010101010101010101010;
        $display("Test Case 8: Cache Read Miss");
        imem_sel_i = 1'b1;
        cache_read_miss(32'h800003f0);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 9. Perform Cache Read Hit after flush
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 9: Cache Read Hit");
        cache_read_hit(32'h800003f0);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 10. Perform Cache Access with Kill Signal
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 10: Cache Access with Kill Signal");
        cache_access_kill(32'h80001234);
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        /*// 11. Verify Cache Read Miss after access kill
        repeat(3)@(posedge clk);
        mem2icache.r_data = 128'h11001100110011001100110011001100;
        $display("Test Case 11: Cache Read Miss");
        imem_sel_i = 1'b1;
        cache_read_miss(32'h80000000);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        //------------------------------------------------------------------------------------------------------------------------
        // 12. Perform Cache Read Hit after access kill
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 12: Cache Read Hit");
        cache_read_hit(32'h80000000);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;*/
        //------------------------------------------------------------------------------------------------------------------------
        // 13. Test Cache Behavior with 4-way Associativity
        @(posedge clk);
        imem_sel_i = 1'b1;
        mem2icache.r_data = 128'h10101010101010101010101010101010;
        $display("Test Case 13: Testing Multi-way Associativity");
        cache_read_miss(32'h80000000); // Should hit way 0
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        mem2icache.r_data = 128'h12345678123456781234567812345678;
        cache_read_miss(32'h80002000); // Should hit way 1
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        mem2icache.r_data = 128'habcdef23abcdef23abcdef23abcdef23;
        cache_read_miss(32'h80004000); // Should hit way 2
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        mem2icache.r_data = 128'h98765432987654329876543298765432;
        cache_read_miss(32'h80008000); // Should hit way 3
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;
        // 14. Perform Cache Read Hit
        @(posedge clk);
        imem_sel_i = 1'b1;
        $display("Test Case 6: Cache Read Hit");
        cache_read_hit(32'h80004000);
        while (~icache2if.ack) begin
            @(posedge clk);
        end
        if2icache.req = 1'b0;

        // // 11. Test Cache Flush with Pending Requests
        // $display("Test Case 10: Cache Flush with Pending Requests");
        // cache_read(32'h00001234); // Pending request
        // cache_flush();
        // @(posedge clk);
        // cache_read(32'h00001234); // Verify behavior after flush*/

        $display("I-Cache Testbench Completed");
        $finish;
    end
endmodule

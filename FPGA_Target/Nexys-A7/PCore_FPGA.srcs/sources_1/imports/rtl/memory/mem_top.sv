// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The memory top module integrating the memory subsystem modules
//              with the processor core. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../defines/mmu_defs.svh"
`include "../defines/cache_defs.svh"
`include "../defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
`include "cache_defs.svh"
`include "ddr_defs.svh"
`endif

module mem_top (

    input   logic                                   rst_n,                   // reset
    input   logic                                   clk,                     // clock

  // Instruction cache memory interface
    input  wire type_if2icache_s                    if2icache_i,             // Bus interface from IF to icache 
    output type_icache2if_s                         icache2if_o,             // From imem to IF

  // MMU interface
    input  wire type_mmu2dcache_s                   mmu2dcache_i,            // Interface from MMU 
    output type_dcache2mmu_s                        dcache2mmu_o,            // From data memory to MMU

  // DBus <---> Data cache interface
    input   wire type_dbus2peri_s                   dbus2peri_i,             // Data memory input signals
    output  type_peri2dbus_s                        dcache2dbus_o,           // Data memory output signals
    output  type_peri2dbus_s                        bmem2dbus_o,             // Boot memory output signals
    input wire                                      dcache_flush_i,
    input wire                                      lsu_flush_i,

`ifdef DRAM
    // DDR memory interface
    input wire type_mem2cache_s                     dram2cache_i,
    output type_cache2mem_s                         cache2dram_o,
`endif

 // Selection signal from address decoder of dbus interconnect 
    input   logic                                   dmem_sel_i,
    input   logic                                   bmem_sel_i
);


// Local signals
type_if2icache_s                        if2icache;                           // Instruction memory address
type_icache2if_s                        icache2if; 
type_icache2if_s                        bmem2if;  
type_icache2mem_s                       icache2mem;
type_mem2icache_s                       mem2icache;

type_mmu2dcache_s                       mmu2dcache;               
type_dcache2mmu_s                       dcache2mmu;

type_dbus2peri_s                        dbus2peri; // lsummu2dmem;
type_peri2dbus_s                        dcache2dbus; // dmem2lsummu;              // Signals from data memory
type_peri2dbus_s                        bmem2dbus;  

type_lsummu2dcache_s                    lsummu2dcache, lsummu2dcache_ff, lsummu2dcache_next;
type_dcache2lsummu_s                    dcache2lsummu;
type_mem2dcache_s                       mem2dcache;
type_dcache2mem_s                       dcache2mem;

type_cache_arbiter_states_e             cache_arbiter_state_next, cache_arbiter_state_ff; 
type_mem_arbiter_states_e               mem_arbiter_state_next, mem_arbiter_state_ff; 

// Interface signals for cache memories and main memory connectivity
type_mem2cache_s                        mem2cache;
type_cache2mem_s                        cache2mem, cache2mem_ff;

// Peripheral module selection lines from the address decoder
logic                                   dmem_sel;
logic                                   bmem_sel;
logic                                   bmem_iaddr_match;

logic                                   dcache_kill_req;
logic                                   dcache2mem_kill;

logic                                   timeout_flag;
logic [7:0]                             timeout_next, timeout_ff; 

// Signal assignments
assign mmu2dcache = mmu2dcache_i;
assign dmem_sel  = dmem_sel_i;
assign if2icache = if2icache_i;
assign bmem_sel  = bmem_sel_i;
assign dbus2peri = dbus2peri_i;
assign bmem_iaddr_match = (if2icache.addr[`BMEM_SEL_ADDR_HIGH:`BMEM_SEL_ADDR_LOW] == `BMEM_ADDR_MATCH);


//========= Instruction cache, boot memory and associated interfaces =========//

bmem_interface bmem_interface_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2bmem_i          (dbus2peri),
    .bmem_d_sel_i         (bmem_sel),
    .bmem2dbus_o          (bmem2dbus),

   // Instruction memory interface signals 
    .if2bmem_i            (if2icache),
    .bmem_iaddr_match_i   (bmem_iaddr_match),
    .bmem2if_o            (bmem2if)
    
);

icache_top icache_top_module(
    .clk                    (clk),
    .rst_n                  (rst_n),

    // Instruction fetch to instruction cache interface
    .if2icache_i            (if2icache),
    .icache2if_o            (icache2if),
  
    // Instruction cache to instruction memory interface  
    .mem2icache_i           (mem2icache),
    .icache2mem_o           (icache2mem),
    .imem_sel_i             (~bmem_iaddr_match)
);

//============ Data cache, bus arbiter and associated interfaces =============//
// Arbitration between LSU and MMU interfaces for data cache access

always_ff @(posedge clk) begin
    if (~rst_n) begin
        cache_arbiter_state_ff <= DCACHE_ARBITER_IDLE; 
        lsummu2dcache_ff       <= '0;
    end else begin
        cache_arbiter_state_ff <= cache_arbiter_state_next;
        lsummu2dcache_ff       <= lsummu2dcache_next;
    end
end

always_comb begin
lsummu2dcache = '0;
lsummu2dcache_next = lsummu2dcache_ff;
dcache2dbus   = '0;
dcache2mmu    = '0;
cache_arbiter_state_next  = cache_arbiter_state_ff;
dcache_kill_req = '0;

   case (cache_arbiter_state_ff)

       DCACHE_ARBITER_IDLE: begin
           if (dmem_sel) begin
               lsummu2dcache.addr     = dbus2peri.addr;
               lsummu2dcache.w_data   = dbus2peri.w_data;
               lsummu2dcache.sel_byte = dbus2peri.sel_byte;
               lsummu2dcache.w_en     = dbus2peri.w_en;
               lsummu2dcache.req      = dbus2peri.req;
               cache_arbiter_state_next = DCACHE_ARBITER_LSU;
           end else if (~dmem_sel & mmu2dcache.r_req & ~mmu2dcache.flush_req) begin
               lsummu2dcache.addr     = mmu2dcache.paddr;
               lsummu2dcache.w_data   = '0;
               lsummu2dcache.sel_byte = '0;
               lsummu2dcache.w_en     = '0;
               lsummu2dcache.req      = 1'b1;
               cache_arbiter_state_next = DCACHE_ARBITER_MMU;
           end
           lsummu2dcache_next = lsummu2dcache; 
       end

       DCACHE_ARBITER_LSU: begin
           if (dcache2lsummu.ack) begin
               dcache2dbus.r_data = dcache2lsummu.r_data;
               dcache2dbus.ack    = 1'b1;
               lsummu2dcache_next      = '0;
               cache_arbiter_state_next = DCACHE_ARBITER_IDLE;
           end else begin
               cache_arbiter_state_next = DCACHE_ARBITER_LSU;
               lsummu2dcache.addr     = dbus2peri.addr;
               lsummu2dcache.w_data   = dbus2peri.w_data;
               lsummu2dcache.sel_byte = dbus2peri.sel_byte;
               lsummu2dcache.w_en     = dbus2peri.w_en;
               lsummu2dcache.req      = dbus2peri.req;
           end 

       end

       DCACHE_ARBITER_MMU: begin
           if (mmu2dcache.flush_req) begin 
               cache_arbiter_state_next = DCACHE_ARBITER_IDLE;
               dcache_kill_req = 1'b1;
           end else if (dcache2lsummu.ack) begin
               dcache2mmu.r_data  = dcache2lsummu.r_data;
               dcache2mmu.r_valid = 1'b1;
               lsummu2dcache_next      = '0;
               cache_arbiter_state_next = DCACHE_ARBITER_IDLE;
           end else begin
               cache_arbiter_state_next = DCACHE_ARBITER_MMU;
               lsummu2dcache.addr     = mmu2dcache.paddr;
               lsummu2dcache.w_data   = '0;
               lsummu2dcache.sel_byte = '0;
               lsummu2dcache.w_en     = '0;
               lsummu2dcache.req      = 1'b1;
           end 
       end

      default: begin     end
   endcase
 
end 

//========================== Data cache top module ===========================//
wb_dcache_top wb_dcache_top_module(
    .clk                    (clk),
    .rst_n                  (rst_n),

    // LSU/MMU to data cache interface
    .lsummu2dcache_i        (lsummu2dcache), // lsummu2dmem
    .dcache2lsummu_o        (dcache2lsummu), // dmem2lsummu
    .dcache_kill_i          (dcache_kill_req),
    .dcache2mem_kill_o      (dcache2mem_kill),
  
    // Data cache to main memory interface  
    .mem2dcache_i           (mem2dcache),
    .dcache2mem_o           (dcache2mem),
    .dcache_flush_i         (dcache_flush_i),
    .dmem_sel_i             (dmem_sel | mmu2dcache.r_req)
);

//============================= Main memory and its memory interface =============================//
// Arbitration between data and instruction caches for main memory access

always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        mem_arbiter_state_ff <= MEM_ARBITER_IDLE; 
        cache2mem_ff         <= '0;
        timeout_ff           <= '0;
    end else begin
        mem_arbiter_state_ff <= mem_arbiter_state_next;
        cache2mem_ff         <= cache2mem;
        timeout_ff           <= timeout_next;
    end
end


assign timeout_flag = (timeout_ff == 8'hEF);
always_comb begin
// cache2mem = '0;
cache2mem = cache2mem_ff;
mem2dcache   = '0;
mem2icache   = '0;
mem_arbiter_state_next  = mem_arbiter_state_ff;
timeout_next = '0;

   case (mem_arbiter_state_ff)
       MEM_ARBITER_IDLE: begin
           cache2mem = '0;
           if (dcache2mem.req ) begin           
               mem_arbiter_state_next = MEM_ARBITER_DCACHE;
               cache2mem.addr   = dcache2mem.addr;
               cache2mem.w_data = dcache2mem.w_data;             
               cache2mem.w_en   = dcache2mem.w_en;
               cache2mem.req    = 1'b1;

           end else if (~dcache2mem.req & icache2mem.req) begin          
               mem_arbiter_state_next = MEM_ARBITER_ICACHE;
               cache2mem.addr   = icache2mem.addr;
               cache2mem.w_data = '0;             
               cache2mem.w_en   = '0;
               cache2mem.req    = 1'b1;
           end
       end

       MEM_ARBITER_DCACHE: begin

           if (dcache2mem_kill) begin
               if (mem2cache.ack) begin
                   mem2dcache.r_data = '0;
                   mem2dcache.ack    = 1'b0;
                   mem_arbiter_state_next = MEM_ARBITER_IDLE;
               end else begin
                   mem_arbiter_state_next = MEM_ARBITER_DKILL; 
               end

           end else if (mem2cache.ack) begin
               mem2dcache.r_data = mem2cache.r_data;
               mem2dcache.ack    = 1'b1;
               mem_arbiter_state_next = MEM_ARBITER_IDLE;

           end 

       end

       MEM_ARBITER_ICACHE: begin
           
           if (if2icache.req_kill) begin  //   icache2mem.kill
               if (mem2cache.ack) begin
                      mem2icache.r_data = '0;
                      mem2icache.ack    = 1'b0;
                      mem_arbiter_state_next = MEM_ARBITER_IDLE;
               end else begin
                   mem_arbiter_state_next = MEM_ARBITER_IKILL; 
               end
               
           end else if (mem2cache.ack) begin
               mem2icache.r_data = mem2cache.r_data;
               mem2icache.ack    = 1'b1;
               mem_arbiter_state_next = MEM_ARBITER_IDLE;

           end else if (timeout_flag) begin
               mem2icache.r_data = '0;
               mem2icache.ack    = 1'b0;
               mem_arbiter_state_next = MEM_ARBITER_IDLE;

           end else begin
               timeout_next = timeout_ff + 1;
           end  
       end

       MEM_ARBITER_IKILL: begin
           if (mem2cache.ack || timeout_flag) begin // 
               mem2icache.r_data = '0;
               mem2icache.ack    = 1'b0;
               mem_arbiter_state_next = MEM_ARBITER_IDLE;
           end else begin
               timeout_next = timeout_ff + 1;
           end    
       end

       MEM_ARBITER_DKILL: begin
           if (mem2cache.ack || timeout_flag) begin
               mem2dcache.r_data = '0;
               mem2dcache.ack    = 1'b0;
               mem_arbiter_state_next = MEM_ARBITER_IDLE;
           end else begin
               timeout_next = timeout_ff + 1;
           end   
       end

      default: begin     end
   endcase
 
end

`ifndef DRAM
//============================= Main memory interface =============================//
main_mem main_mem_module (
    .rst_n                  (rst_n),
    .clk                    (clk),
    
    // Main memory interface signals 
    .cache2mem_i            (cache2mem),
    .mem2cache_o            (mem2cache)

);
`else
//============================= DRAM memory interface =============================//
assign cache2dram_o = cache2mem;
assign mem2cache = dram2cache_i;
`endif

// Output signal assignments
assign icache2if_o  = bmem2if.ack ? bmem2if : icache2if; 
assign bmem2dbus_o  = bmem2dbus;
assign dcache2dbus_o = dcache2dbus;  
assign dcache2mmu_o  = dcache2mmu; 

endmodule : mem_top

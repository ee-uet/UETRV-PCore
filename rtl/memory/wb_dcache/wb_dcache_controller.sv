// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The data cache controller. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.6.2023

`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module wb_dcache_controller (
    input wire                            clk_i, 
    input wire                            rst_ni,

    // Interface signals to/from cache datapath
    input wire                            cache_hit_i,
    input wire                            cache_evict_req_i,
    input  wire                           dcache_flush_i,
    output logic                          cache_wr_o,
    output logic                          cache_line_wr_o,
    output logic                          cache_line_clean_o,
    output logic                          cache_wrb_req_o,
    output logic [DCACHE_IDX_BITS-1:0]    evict_index_o,
 
    // LSU/MMU to data cache interface
    input wire                            lsummu2dcache_req_i,
    input wire                            lsummu2dcache_wr_i,
    output logic                          dcache2lsummu_ack_o,
    input wire                            dcache_kill_i,

    // Data memory to data cache interface
    input  wire                           mem2dcache_ack_i,
    output logic                          dcache2mem_req_o,
    output logic                          dcache2mem_wr_o,
    output logic                          dcache2mem_kill_o,
    input wire                            dmem_sel_i
);
         

type_dcache_states_e                  dcache_state_ff, dcache_state_next;
logic [DCACHE_IDX_BITS-1:0]           evict_index_next, evict_index_ff;

logic                                 lsummu2dcache_wr;
logic                                 dcache2lsummu_ack;
logic                                 dcache_hit;
logic                                 dcache_miss;
logic                                 dcache_evict;
logic                                 dcache2mem_wr;
logic                                 dcache2mem_req;

logic                                 cache_wrb_req;
logic                                 cache_wr;
logic                                 cache_line_wr;
logic                                 cache_line_clean;

logic                                 dcache2mem_kill;

assign lsummu2dcache_wr = lsummu2dcache_wr_i;

assign dcache_hit   = lsummu2dcache_req_i & dmem_sel_i & cache_hit_i;
assign dcache_miss  = lsummu2dcache_req_i & dmem_sel_i & ~cache_hit_i ;
assign dcache_evict = cache_evict_req_i;

// Cache controller state machine
always_ff @(posedge clk_i) begin
  if (~rst_ni) begin
      dcache_state_ff <= DCACHE_IDLE;
      evict_index_ff  <= '0;
  end else begin
      dcache_state_ff <= dcache_state_next;
      evict_index_ff  <= evict_index_next;
  end
end

 
always_comb begin
    dcache_state_next = dcache_state_ff;
    evict_index_next  = evict_index_ff;
    dcache2lsummu_ack = 1'b0;
    dcache2mem_req    = 1'b0;
    dcache2mem_wr     = 1'b0;
    cache_wrb_req     = 1'b0;
    cache_line_wr     = 1'b0;
    cache_line_clean  = 1'b0;
    cache_wr          = 1'b0;
    dcache2mem_kill   = 1'b0;
    
    unique case (dcache_state_ff)
        DCACHE_IDLE: begin
            // In case of flush, go to FLUSH State
            if (dcache_flush_i) begin                    
                dcache_state_next = DCACHE_FLUSH;
            end else if (dcache_hit) begin 
            // In case of hit, perform the cache read/write operation              
                if (lsummu2dcache_wr) begin
                    dcache_state_next = DCACHE_WRITE;
                    cache_wr          = 1'b1;
                end else begin 
                    dcache_state_next = DCACHE_READ;
                end
            end else if (dcache_miss) begin           
               if (dcache_evict) begin
                    dcache_state_next = DCACHE_WRITE_BACK;
                    dcache2mem_req    = 1'b1;
                    dcache2mem_wr     = 1'b1;
                    cache_wrb_req     = 1'b1;
                end else begin 
                    dcache_state_next = DCACHE_ALLOCATE;
                end
            end else begin
                dcache_state_next = DCACHE_IDLE;
                evict_index_next  = '0;
            end
        end
        DCACHE_READ: begin  
            // Send ack from cache, data will be returned by cache datapath          
            dcache_state_next = DCACHE_IDLE;
            dcache2lsummu_ack = 1'b1;
        end
        DCACHE_WRITE: begin  
            // Ack from cache, data is written simultaneously          
            dcache_state_next = DCACHE_IDLE;
            dcache2lsummu_ack = 1'b1;      
        end
        DCACHE_ALLOCATE: begin  
            // Response from main memory is received          
            if (mem2dcache_ack_i) begin
                dcache_state_next = DCACHE_IDLE;
                cache_line_wr     = 1'b1;
            end else begin
               dcache_state_next = DCACHE_ALLOCATE;
               dcache2mem_req    = 1'b1;
            end
        end
        DCACHE_WRITE_BACK: begin  
            // Response from main memory is received          
            if (mem2dcache_ack_i) begin  
                dcache_state_next = DCACHE_ALLOCATE;
                if (dcache_flush_i) begin
                    dcache_state_next = DCACHE_FLUSH;
                    cache_line_clean  = 1'b1;
                    evict_index_next  = evict_index_ff + 1;
                end 
            end else begin
                dcache_state_next = DCACHE_WRITE_BACK;
                dcache2mem_req    = 1'b1;
                dcache2mem_wr     = 1'b1;
                cache_wrb_req     = 1'b1;
            end
        end
        DCACHE_FLUSH: begin

            if (dcache_evict) begin
                dcache_state_next = DCACHE_WRITE_BACK;
                dcache2mem_req    = 1'b1;
                dcache2mem_wr     = 1'b1;
                cache_wrb_req     = 1'b1;
            end else begin 
                evict_index_next = evict_index_ff + 1;
                if (evict_index_ff == DCACHE_MAX_IDX) begin
                    dcache_state_next = DCACHE_FLUSH_DONE;
                //    dcache2lsummu_ack = 1'b1;
                    evict_index_next  = '0;
                end
            end

        end
        DCACHE_FLUSH_DONE: begin
            dcache2lsummu_ack = 1'b1;
            dcache_state_next = DCACHE_IDLE;
        end
        default: begin
            dcache_state_next = DCACHE_IDLE;
        end         
   endcase

    // Kill any ongoing request if the data memory is not addressed 
    if (~dmem_sel_i | dcache_kill_i) begin   // | dcache_kill_i   ---  & ~dcache_flush_i
        dcache_state_next = DCACHE_IDLE;
        evict_index_next  = '0;
        cache_wr          = 1'b0;
        dcache2mem_req    = 1'b0;
        dcache2mem_kill   = 1'b1;
    end

end


assign cache_wrb_req_o  = cache_wrb_req;
assign cache_wr_o       = cache_wr;
assign cache_line_wr_o  = cache_line_wr;
assign cache_line_clean_o  = cache_line_clean;
assign evict_index_o       = evict_index_ff;

assign dcache2mem_wr_o     = dcache2mem_wr;
assign dcache2mem_req_o    = dcache2mem_req;
assign dcache2mem_kill_o   = dcache2mem_kill;

assign dcache2lsummu_ack_o = dcache2lsummu_ack;
  
endmodule

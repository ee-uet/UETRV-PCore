// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The data cache top module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.6.2023

`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module wb_dcache_top (
    input wire                         clk,
    input wire                         rst_n,
    input wire                         dmem_sel_i,
    input wire                         dcache_flush_i,
    input wire                         dcache_kill_i,

    // LSU/MMU to data cache interface
    input wire type_lsummu2dcache_s    lsummu2dcache_i,
    output type_dcache2lsummu_s        dcache2lsummu_o,
  
    // Data cache to data memory interface  
    input wire type_mem2dcache_s       mem2dcache_i,
    output type_dcache2mem_s           dcache2mem_o,
    output logic                       dcache2mem_kill_o
);

logic                              cache_hit;
logic                              cache_evict_req;
logic                              cache_wr;
logic                              cache_line_wr;
logic                              cache_line_clean;
logic                              cache_wrb_req;
logic [DCACHE_IDX_BITS-1:0]        evict_index;

type_lsummu2dcache_s               lsummu2dcache;
type_dcache2lsummu_s               dcache2lsummu;

type_mem2dcache_s                  mem2dcache;
type_dcache2mem_s                  dcache2mem;

assign lsummu2dcache = lsummu2dcache_i;
assign mem2dcache    = mem2dcache_i;


wb_dcache_controller wb_dcache_controller_module(
  .clk                     (clk), 
  .rst_n                   (rst_n),

   // Interface signals for cache datapath
  .cache_hit_i             (cache_hit),
  .cache_evict_req_i       (cache_evict_req),
  .evict_index_o           (evict_index), 
  .cache_wr_o              (cache_wr),
  .cache_line_wr_o         (cache_line_wr),
  .cache_line_clean_o      (cache_line_clean),
  .cache_wrb_req_o         (cache_wrb_req),

  // LSU/MMU <---> data cache signals
  .lsummu2dcache_req_i     (lsummu2dcache.req),
  .lsummu2dcache_wr_i      (lsummu2dcache.w_en),
  .dcache2lsummu_ack_o     (dcache2lsummu.ack),
  .dcache_flush_i          (dcache_flush_i),
  .dcache_kill_i           (dcache_kill_i),
//  .dcache_flush_ack_o      (dcache2lsummu.flush_ack),    

  // Data memory <---> data cache signals
  .mem2dcache_ack_i        (mem2dcache.ack),
  .dcache2mem_req_o        (dcache2mem.req),
  .dcache2mem_wr_o         (dcache2mem.w_en),
  .dcache2mem_kill_o       (dcache2mem_kill_o),
  .dmem_sel_i              (dmem_sel_i)
);  

wb_dcache_datapath wb_dcache_datapath_module(
  .clk                     (clk),
  .rst_n                   (rst_n),

  // Interface signals for cache datapath
  .cache_wr_i              (cache_wr),
  .cache_line_wr_i         (cache_line_wr),
  .cache_line_clean_i      (cache_line_clean),
  .cache_wrb_req_i         (cache_wrb_req), 
  .evict_index_i           (evict_index),   
  .cache_hit_o             (cache_hit),
  .cache_evict_req_o       (cache_evict_req),

  // LSU/MMU <---> data cache signals
  .dcache_flush_i          (dcache_flush_i),
  .lsummu2dcache_req_i     (lsummu2dcache.req),
  .lsummu2dcache_addr_i    (lsummu2dcache.addr),
  .lsummu2dcache_wdata_i   (lsummu2dcache.w_data),
  .sel_byte_i              (lsummu2dcache.sel_byte),
  .dcache2lsummu_data_o    (dcache2lsummu.r_data),
  
  // Data memory <---> data cache signals
  .mem2dcache_data_i       (mem2dcache.r_data),
  .dcache2mem_data_o       (dcache2mem.w_data),
  .dcache2mem_addr_o       (dcache2mem.addr)
);


assign dcache2lsummu_o = dcache2lsummu;
assign dcache2mem_o    = dcache2mem;


endmodule

// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The instruction cache top module. 
//
// Author: Umer Shahid and Ali Imran, UET Lahore
// Date: 10.4.2023


`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module icache_top (
  input  wire logic             clk_i,
  input  wire logic             rst_ni,
  input  wire logic             imem_sel_i,

  // Instruction Fetch to Instruction Cache Interface
  input wire type_if2icache_s   if2icache_i,
  output type_icache2if_s       icache2if_o,
  
  // Instruction Cache to Instruction memory Interface  
  input wire type_mem2icache_s  mem2icache_i,
  output type_icache2mem_s      icache2mem_o
);

logic cache_hit;
logic cache_rw;

type_if2icache_s               if2icache;
type_mem2icache_s              mem2icache;
type_icache2if_s               icache2if;
type_icache2mem_s              icache2mem;

assign if2icache         = if2icache_i;
assign mem2icache.r_data = mem2icache_i.r_data;
assign mem2icache.ack    = mem2icache_i.ack;


icache_controller icache_controller_module(
  .clk_i                (clk_i), 
  .rst_ni               (rst_ni),
  .cache_hit_i          (cache_hit),
  .cache_rw_o           (cache_rw),

  .if2icache_req_i      (if2icache.req),
  .if2icache_req_kill_i (if2icache.req_kill),
  .icache2if_ack_o      (icache2if.ack),
  .icache2mem_kill_o    (icache2mem.kill),

  .mem2icache_ack_i     (mem2icache.ack),
  .icache2mem_req_o     (icache2mem.req),
  .imem_sel_i           (imem_sel_i)
);  

icache_datapath icache_datapath_module(
  .clk_i                (clk_i),
  .rst_ni               (rst_ni),
  .cache_rw_i           (cache_rw),
  .cache_hit_o          (cache_hit),

  // Instruction Fetch to Instruction Cache Interface
  .icache_flush         (if2icache.icache_flush),
  .if2icache_addr_i     (if2icache.addr),
  .icache2if_data_o     (icache2if.r_data),
  
  // Intruction Cache to Instruction Memory Interface
  .mem2icache_data_i   (mem2icache.r_data),
  .icache2mem_addr_o   (icache2mem.addr)
  
);


assign icache2if_o = icache2if;
assign icache2mem_o = icache2mem;


endmodule

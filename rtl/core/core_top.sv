// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The Core top module integrating the pipeline and MMU.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 12.06.2023


`ifndef VERILATOR
`include "../defines/mmu_defs.svh"
`include "../defines/plic_defs.svh"
`include "../defines/cache_defs.svh"
`include "../defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
`include "plic_defs.svh"
`include "cache_defs.svh"
`include "ddr_defs.svh"
`endif

module core_top (

    input   logic                        rst_n,                  // reset
    input   logic                        clk,                     // clock

   // IF <---> IMEM interface
    output type_if2icache_s             if2icache_o,              // Instruction memory request
    input wire type_icache2if_s         icache2if_i,              // Instruction memory response

   // MMU <---> Data cache interface
    input wire type_dcache2mmu_s        dcache2mmu_i,   
    output type_mmu2dcache_s            mmu2dcache_o,  

   // Data bus interface
    output type_lsu2dbus_s              lsu2dbus_o,                // Signal to data bus 
    input  wire type_dbus2lsu_s         dbus2lsu_i,
    output logic                        dcache_flush_o,
 //   output logic                        lsu_flush_o,

   // Memory mapped timer interface
   input wire type_clint2csr_s          clint2csr_i,

   // IRQ interface
   input wire type_pipe2csr_s           core2pipe_i

 //  input wire type_debug_port_s         debug_port_i 
);

// Local signals for MMU interface
type_if2mmu_s                           if2mmu;
type_mmu2if_s                           mmu2if;
type_lsu2mmu_s                          lsu2mmu;
type_mmu2lsu_s                          mmu2lsu;


pipeline_top pipeline_top_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IMEM interface signals 
    .if2icache_o         (if2icache_o),   
    .icache2if_i         (icache2if_i),

    // MMU interface signals
    // LSU <---> MMU interface 
    .mmu2lsu_i           (mmu2lsu), 
    .lsu2mmu_o           (lsu2mmu),

  // IF <---> MMU interface
    .if2mmu_o            (if2mmu),        // Instruction memory request
    .mmu2if_i            (mmu2if), 

    // DBUS interface signals
    .lsu2dbus_o          (lsu2dbus_o),       // Signal to data bus 
    .dbus2lsu_i          (dbus2lsu_i),
    .dcache_flush_o      (dcache_flush_o),
    .lsu_flush_o         (),

    .clint2csr_i         (clint2csr_i),

    // IRQ lines
    .core2pipe_i         (core2pipe_i)

   // .debug_port_i        (debug_port_i)
);

//==================================  MMU for virtual memory ==================================//
// MMU module instantiation
mmu mmu_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // Forward_stall module interface signals 
    .lsu2mmu_i                  (lsu2mmu),
    .mmu2lsu_o                  (mmu2lsu),

    .if2mmu_i                   (if2mmu),
    .mmu2if_o                   (mmu2if),

    .dcache2mmu_i               (dcache2mmu_i),
    .mmu2dcache_o               (mmu2dcache_o)
);

endmodule : core_top


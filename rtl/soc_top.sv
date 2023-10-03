// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The SoC top module integrating the processor core and peripherals
//              including the memory subsystem.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 12.06.2023

`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "./defines/mmu_defs.svh"
`include "./defines/plic_defs.svh"
`include "./defines/cache_defs.svh"
`include "./defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
`include "plic_defs.svh"
`include "cache_defs.svh"
`include "ddr_defs.svh"
`endif

module soc_top (

    input   logic                        rst_n,                  // reset
    input   logic                        clk,                     // clock

    input   logic                        irq_ext_i,
    input   logic                        irq_soft_i,
    

    // SPI interface signals
    // SPI bus interface signals including clock, chip_select, MOSI and MISO  
    output logic                         spi_clk_o,
    output logic                         spi_cs_o,
    input logic                          spi_miso_i,
    output logic                         spi_mosi_o,

`ifdef DRAM
    // DDR memory interface
    output wire                          valid_o,
    output wire                          we_o,
    output wire [31:0]                   addr_o,
    output wire [127:0]                  data_o,
    input  wire                          ready_i,
    input  wire  [127:0]                 data_i,
`endif

  //  input wire type_debug_port_s         debug_port_i,

    // Uart interface IO signals
    input   logic                        uart_rxd_i,
    output                               uart_txd_o
);

`ifdef DRAM

// DDR memory interface
wire type_cache2mem_s               cache2dram;
wire type_mem2cache_s               dram2cache;
assign addr_o = cache2dram.addr & ~32'h0F;
assign data_o = cache2dram.w_data;
assign valid_o = cache2dram.req;
assign we_o = cache2dram.w_en; 
assign dram2cache.r_data = data_i;
assign dram2cache.ack = ready_i;
`endif

// Local signals
type_if2icache_s                        if2icache;            // Instruction memory address
type_icache2if_s                        icache2if;   

type_mmu2dcache_s                       mmu2dcache;               
type_dcache2mmu_s                       dcache2mmu;

type_lsu2dbus_s                         lsu2dbus;           // Signal to data memory 
type_dbus2lsu_s                         dbus2lsu; 

type_dbus2peri_s                        dbus2peri;
type_pipe2csr_s                         core2pipe;


type_clint2csr_s                        clint2csr;

// Peripheral module selection lines from the address decoder
logic                                   dmem_sel;
logic                                   uart_sel;
logic                                   clint_sel;
logic                                   plic_sel;
logic                                   bmem_sel;
logic                                   spi_sel;

logic                                   dcache_flush;
logic                                   lsu_flush;
 

// IRQ ignals
logic                                   irq_uart;
logic                                   irq_ns_uart;
logic                                   irq_spi;

logic                                   irq_clint_timer;
logic                                   irq_plic_target_0, irq_plic_target_1;

// Interfaces for different peripheral modules (for read mux)
type_peri2dbus_s                        dcache2dbus;              // Signals from data memory 
type_peri2dbus_s                        uart2dbus; 
type_peri2dbus_s                        clint2dbus;
type_peri2dbus_s                        plic2dbus; 
type_peri2dbus_s                        bmem2dbus;              // Signals from boot memory 
type_peri2dbus_s                        spi2dbus;


// Input assignment to local signals
assign core2pipe.csr_mhartid = `CSR_MHARTID;
assign core2pipe.ext_irq     = {irq_plic_target_1, irq_plic_target_0};
assign core2pipe.timer_irq   = irq_clint_timer;
assign core2pipe.soft_irq    = irq_soft_i;
assign core2pipe.uart_irq    = '0; // irq_uart

core_top core_top_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IMEM interface signals 
    .if2icache_o         (if2icache),   
    .icache2if_i         (icache2if),

    // MMU interface signals
    .dcache2mmu_i        (dcache2mmu),
    .mmu2dcache_o        (mmu2dcache),

    // DBUS interface signals
    .lsu2dbus_o          (lsu2dbus),       // Signal to data bus 
    .dbus2lsu_i          (dbus2lsu),
    .dcache_flush_o      (dcache_flush),
   // .lsu_flush_o         (lsu_flush),

    .clint2csr_i         (clint2csr),

    // IRQ lines
    .core2pipe_i         (core2pipe)
    
    // , .debug_port_i        (debug_port_i)
);

//==================================  Data bus interconnect ==================================//
dbus_interconnect dbus_interconnect_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data memory interface signals 
    .lsu2dbus_i            (lsu2dbus),
    .dbus2lsu_o            (dbus2lsu),
    .dcache_flush_i        (dcache_flush),

    // Peripheral (data memory and GPIO) selection signals
    .dmem_sel_o            (dmem_sel),
    .uart_sel_o            (uart_sel),
    .clint_sel_o           (clint_sel), 
    .plic_sel_o            (plic_sel),
    .bmem_sel_o            (bmem_sel), 
    .spi_sel_o             (spi_sel),

    // Signals from dbus to peripherals
    .dbus2peri_o           (dbus2peri),

   // Data memory and peripheral interface signals 
    .dcache2dbus_i         (dcache2dbus),
    .uart2dbus_i           (uart2dbus),
    .clint2dbus_i          (clint2dbus),
    .plic2dbus_i           (plic2dbus),
    .bmem2dbus_i           (bmem2dbus),
    .spi2dbus_i            (spi2dbus)
);


uart uart_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus and IO interface signals 
    .dbus2uart_i           (dbus2peri),  // This should be updated after the WB/AHBL bus interface is used
    .uart_sel_i            (uart_sel),
    .uart2dbus_o           (uart2dbus),
    .uart_irq_o            (irq_uart),
    .uart_rxd_i            (uart_rxd_i),
    .uart_txd_o            (uart_txd_o)
);

clint clint_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus and peripheral interface signals 
    .dbus2clint_i          (dbus2peri),  // This should be updated if the bus interface is updated
    .clint_sel_i           (clint_sel),
    .clint2dbus_o          (clint2dbus),

    .clint2csr_o           (clint2csr),
    .clint_timer_irq_o     (irq_clint_timer)
);

plic_top plic_top_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus interface signals 
    .dbus2plic_i           (dbus2peri),  // This should be updated if the bus interface is updated
    .plic_sel_i            (plic_sel),
    .plic2dbus_o           (plic2dbus),
    .edge_select_i         (PLIC_SOURCE_COUNT'(0)),
    .irq_src_i             ({'0, irq_uart}),
    .irq_targets_o         ({irq_plic_target_1, irq_plic_target_0})
);


mem_top mem_top_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data cache interface signals 
    .dbus2peri_i          (dbus2peri),
    .dmem_sel_i           (dmem_sel),
    .dcache2dbus_o        (dcache2dbus),
    .bmem2dbus_o          (bmem2dbus),
    .dcache_flush_i       (dcache_flush),
    .lsu_flush_i          (lsu_flush),

   // MMU <---> data cache interface signals 
    .mmu2dcache_i         (mmu2dcache),
    .dcache2mmu_o         (dcache2mmu),

`ifdef DRAM
    // DDR memory interface
    .dram2cache_i(dram2cache),
    .cache2dram_o(cache2dram),
`endif

   // Instruction memory interface signals 
    .if2icache_i          (if2icache),
    .bmem_sel_i           (bmem_sel),
    .icache2if_o          (icache2if)
);

spi_top spi_top_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus and IO interface signals 
    .dbus2spi_i            (dbus2peri),  // This should be updated after the WB/AHBL bus interface is used
    .spi2dbus_o            (spi2dbus),
    .spi_sel_i             (spi_sel),
    .spi_irq_o             (irq_spi),

    .spi_clk_o             (spi_clk_o),
    .spi_cs_o              (spi_cs_o),
    .spi_miso_i            (spi_miso_i),
    .spi_mosi_o            (spi_mosi_o)
);

endmodule : soc_top


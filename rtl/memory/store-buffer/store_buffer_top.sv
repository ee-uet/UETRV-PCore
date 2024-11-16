// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The Store Buffer module. 
//
// Author: Fazail Ali Butt, UET Lahore
// Date: 15.11.2024

`ifndef VERILATOR
`include "../defines/mmu_defs.svh"
`include "../defines/cache_defs.svh"
`include "../defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
`include "cache_defs.svh"
`include "ddr_defs.svh"
`endif

module store_buffer_top #(
    parameter BLEN = 4                // Buffer Length
)(
    input  logic                        clk,                        // Clock
    input  logic                        rst_n,                      // Reset, active low

    // LSU --> store_buffer_top
    input  wire  type_lsummu2stb_s      lsummu2stb_i,    
    input  logic                        dmem_sel_i,                 // Data memory select from LSU

    // store_buffer_top --> LSU
    output type_stb2lsummu_s            stb2lsummu_o,
    //output logic                        stb2lsummu_stall,           // Stall signal 

    // store_buffer_top --> dcache
    output   type_stb2dcache_s          stb2dcache_o,
    
    output logic                        stb2dcache_empty,           // store buffer empty signal to dcache
    output logic                        dmem_sel_o,                 // Data memory select from Store Buffer

    // dCache --> store_buffer_top  
    input wire type_dcache2stb_s        dcache2stb_i
);

// store_buffer_top --> dcache
    logic [DCACHE_ADDR_WIDTH-1:0]   stb2dcache_addr;     
    logic [DCACHE_DATA_WIDTH-1:0]   stb2dcache_wdata;    
    logic [3:0]                     stb2dcache_sel_byte; 
    logic                           stb2dcache_w_en;     
    logic                           stb2dcache_req;

// dcache --> store buffer top
    logic [DCACHE_DATA_WIDTH-1:0]   dcache2stb_rdata; 
    logic                           dcache2stb_ack;          

// lsummu --> stb (store buffer)
    logic [DCACHE_ADDR_WIDTH-1:0]   lsummu2stb_addr;    
    logic [DCACHE_DATA_WIDTH-1:0]   lsummu2stb_wdata;   
    logic [3:0]                     lsummu2stb_sel_byte;
    logic                           lsummu2stb_w_en;    
    logic                           lsummu2stb_req;

// stb (store buffer) --> lsummu
    logic                           stb2lsummu_ack;  
    logic [DCACHE_DATA_WIDTH-1:0]   stb2lsummu_rdata;

// Local Signals
    logic                           stb_wr_en;    // Store Buffer Write Enable (from LSU controller)
    logic                           stb_rd_en;    // Store Buffer Read Enable (from Cache controller)
    logic                           stb_full;     // Store Buffer full signal
    logic                           stb_empty;    // Store Buffer empty signal
    logic                           rd_sel;       // selection for read mux
    logic                           stb_bypass;   // Buffer Bypass signal
    logic                           stb_stall;    // Buffer Stall signal

// lsummu --> stb (store buffer)
    assign lsummu2stb_addr      = lsummu2stb_i.addr;
    assign lsummu2stb_wdata     = lsummu2stb_i.w_data;
    assign lsummu2stb_sel_byte  = lsummu2stb_i.sel_byte;
    assign lsummu2stb_w_en      = lsummu2stb_i.w_en;
    assign lsummu2stb_req       = lsummu2stb_i.req;

// dcache --> store_buffer_top
    assign dcache2stb_ack       = dcache2stb_i.ack;
    assign dcache2stb_rdata     = dcache2stb_i.r_data;

    assign stb2lsummu_rdata = dcache2stb_rdata;                     // bypassing rdata signal
    assign stb_bypass = ((lsummu2stb_req & !lsummu2stb_w_en) | (!lsummu2stb_req & !lsummu2stb_w_en)) & stb_empty;

/* =========================================== Store Buffer Datapath ============================================= */
    store_buffer_datapath #(
        .BLEN(BLEN)
    ) u_store_buffer (
        .clk                    (clk),
        .rst_n                  (rst_n),
        
        // LSU --> store_buffer_datapath
        .lsummu2stb_addr        (lsummu2stb_addr),
        .lsummu2stb_wdata       (lsummu2stb_wdata),
        .lsummu2stb_sel_byte    (lsummu2stb_sel_byte),

        // lsu_stb_controller --> store_buffer_datapath
        .stb_wr_en              (stb_wr_en),

        // stb_cache_controller --> store_buffer_datapath
        .stb_rd_en              (stb_rd_en),
        .rd_sel                 (rd_sel),

        // store_buffer_datapath --> dcache
        .stb2dcache_addr        (stb2dcache_addr),
        .stb2dcache_wdata       (stb2dcache_wdata),
        .stb2dcache_sel_byte    (stb2dcache_sel_byte),

        // store_buffer --> store_buffer_controllers
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        .stb_bypass             (stb_bypass)
    );

/* =========================================== LSU to Store Buffer Controller ==================================== */
    lsu_stb_controller u_lsu_stb_controller (
        .clk                    (clk),
        .rst_n                  (rst_n),

        // LSU --> lsu_stb_controller
        .lsummu2stb_w_en        (lsummu2stb_w_en),
        .lsummu2stb_req         (lsummu2stb_req),
        .dmem_sel_i             (dmem_sel_i),

        // store_buffer_datapath --> lsu_stb_controller 
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        .stb_bypass             (stb_bypass),   

        // dcache --> stb_cache_controller
        .dcache2stb_ack         (dcache2stb_ack),     

        // lsu_stb_controller --> LSU
        .stb2lsummu_ack         (stb2lsummu_ack),

        // lsu_stb_controller --> store_buffer_datapath
        .stb_wr_en              (stb_wr_en),
    
        // lsu_stb_controller --> LSU
        .stb2lsummu_stall       (stb_stall)
    );

/* =========================================== Store Buffer to Cache Controller ================================== */
    stb_cache_controller u_stb_cache_controller (
        .clk                    (clk),
        .rst_n                  (rst_n),

        // store_buffer_datapath --> stb_cache_controller
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        .stb_bypass             (stb_bypass),

        // LSU --> lsu_stb_controller
        .lsummu2stb_w_en        (lsummu2stb_w_en),
        .lsummu2stb_req         (lsummu2stb_req),
        .dmem_sel_i             (dmem_sel_i),

        // dcache --> stb_cache_controller
        .dcache2stb_ack         (dcache2stb_ack),

        // stb_cache_controller --> store_buffer_datapath
        .stb_rd_en              (stb_rd_en),
        .rd_sel                 (rd_sel),

        // stb_cache_controller --> dcache
        .stb2dcache_req         (stb2dcache_req),
        .stb2dcache_w_en        (stb2dcache_w_en),
        .dmem_sel_o             (dmem_sel_o)
    );
    
/* =========================================== Output signals ==================================================== */ 
    assign stb2dcache_empty = stb_empty;

    // stb (store buffer) --> lsummu
    assign stb2lsummu_o.ack     = stb2lsummu_ack;
    assign stb2lsummu_o.r_data  = stb2lsummu_rdata;

    // store_buffer_top --> dcache
    assign stb2dcache_o.addr      = stb2dcache_addr;
    assign stb2dcache_o.w_data    = stb2dcache_wdata;
    assign stb2dcache_o.sel_byte  = stb2dcache_sel_byte;
    assign stb2dcache_o.w_en      = stb2dcache_w_en;
    assign stb2dcache_o.req       = stb2dcache_req;

endmodule

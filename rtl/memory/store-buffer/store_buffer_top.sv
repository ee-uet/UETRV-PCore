// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The Store Buffer module. 
//
// Author: Fazail Ali Butt, UET Lahore
// Date: 15.11.2024

`ifndef VERILATOR
`include "../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module store_buffer_top (
    input  logic                        clk,                        // Clock
    input  logic                        rst_n,                      // Reset, active low

    // LSU --> store_buffer_top
    input  wire  type_lsummu2stb_s      lsummu2stb_i,    
    input  logic                        dmem_sel_i,                 // Data memory select from LSU

    // store_buffer_top --> LSU
    output type_stb2lsummu_s            stb2lsummu_o,

    // store_buffer_top --> dcache
    output   type_stb2dcache_s          stb2dcache_o,
    
    output logic                        stb2dcache_empty,           // store buffer empty signal to dcache
    output logic                        dmem_sel_o,                 // Data memory select from Store Buffer

    // dCache --> store_buffer_top  
    input wire type_dcache2stb_s        dcache2stb_i
);

// store_buffer_top --> dcache Signals
    logic [DCACHE_ADDR_WIDTH-1:0]   stb2dcache_addr;     
    logic [DCACHE_DATA_WIDTH-1:0]   stb2dcache_wdata;    
    logic [3:0]                     stb2dcache_sel_byte; 
    logic                           stb2dcache_w_en;     
    logic                           stb2dcache_req;

// dcache --> store buffer top Signals
    logic [DCACHE_DATA_WIDTH-1:0]   dcache2stb_rdata; 
    logic                           dcache2stb_ack;          

// lsummu --> stb (store buffer) Signals
    logic [DCACHE_ADDR_WIDTH-1:0]   lsummu2stb_addr;    
    logic [DCACHE_DATA_WIDTH-1:0]   lsummu2stb_wdata;   
    logic [3:0]                     lsummu2stb_sel_byte;
    logic                           lsummu2stb_w_en;    
    logic                           lsummu2stb_req;

// stb (store buffer) --> lsummu Signals
    logic                           stb2lsummu_ack;  
    logic [DCACHE_DATA_WIDTH-1:0]   stb2lsummu_rdata;

// Local Signals
    logic                           wr_en;        // Store Buffer Write Enable (from LSU controller)
    logic                           rd_en;        // Store Buffer Read Enable (from Cache controller)
    logic                           stb_full;     // Store Buffer full signal
    logic                           stb_empty;    // Store Buffer empty signal
    logic                           rd_sel;       // selection for read mux
    logic                           stb_bypass;   // Buffer Bypass signal
    logic                           stb_stall;    // Buffer Stall signal

    logic                           stb_ack;

    logic [DCACHE_ADDR_WIDTH-1:0]   stb_addr;     
    logic [DCACHE_DATA_WIDTH-1:0]   stb_wdata;    
    logic [3:0]                     stb_sel_byte;
    logic                           stb_req;
    logic                           stb_w_en;
    logic                           dm_sel;

/* =========================================== Input signals ===================================================== */ 
    // lsummu --> stb (store buffer)
    assign lsummu2stb_addr      = lsummu2stb_i.addr;
    assign lsummu2stb_wdata     = lsummu2stb_i.w_data;
    assign lsummu2stb_sel_byte  = lsummu2stb_i.sel_byte;
    assign lsummu2stb_w_en      = lsummu2stb_i.w_en;
    assign lsummu2stb_req       = lsummu2stb_i.req;

    // dcache --> store_buffer_top
    assign dcache2stb_ack       = dcache2stb_i.ack;
    assign dcache2stb_rdata     = dcache2stb_i.r_data;

/* =========================================== Bypassing Store buffer for Load Instructions ====================== */ 
    // Store Buffer bypass for load instructions
    assign stb_bypass = ((lsummu2stb_req & !lsummu2stb_w_en) | (!lsummu2stb_req & !lsummu2stb_w_en)) & stb_empty;

    always_comb begin
            case (stb_bypass)
            1'b1: begin  
                stb2lsummu_ack      = dcache2stb_ack;
                stb2lsummu_rdata    = dcache2stb_rdata;

                stb2dcache_addr     = lsummu2stb_addr;
                stb2dcache_wdata    = lsummu2stb_wdata;
                stb2dcache_sel_byte = lsummu2stb_sel_byte;
                stb2dcache_req      = lsummu2stb_req;
                stb2dcache_w_en     = lsummu2stb_w_en;

                dmem_sel_o          = dmem_sel_i;
            end
            1'b0: begin
                stb2lsummu_ack      = stb_ack;
                stb2lsummu_rdata    = '0;

                stb2dcache_addr     = stb_addr;
                stb2dcache_wdata    = stb_wdata;
                stb2dcache_sel_byte = stb_sel_byte;
                stb2dcache_req      = stb_req;
                stb2dcache_w_en     = stb_w_en;

                dmem_sel_o          = dm_sel;
            end
            default: begin
                stb2lsummu_ack      = stb_ack;
                stb2lsummu_rdata    = '0;

                stb2dcache_addr     = stb_addr;
                stb2dcache_wdata    = stb_wdata;
                stb2dcache_sel_byte = stb_sel_byte;
                stb2dcache_req      = stb_req;
                stb2dcache_w_en     = stb_w_en;

                dmem_sel_o          = dm_sel;
            end
            endcase
    end

/* =========================================== Store Buffer Datapath ============================================= */
    store_buffer_datapath u_store_buffer (
        .clk                    (clk),
        .rst_n                  (rst_n),
        
        // LSU --> store_buffer_datapath
        .lsummu2stb_addr        (lsummu2stb_addr),
        .lsummu2stb_wdata       (lsummu2stb_wdata),
        .lsummu2stb_sel_byte    (lsummu2stb_sel_byte),

        // lsu_stb_controller --> store_buffer_datapath
        .wr_en                  (wr_en),

        // stb_cache_controller --> store_buffer_datapath
        .rd_en                  (rd_en),
        .rd_sel                 (rd_sel),

        // store_buffer_datapath --> dcache
        .stb_addr               (stb_addr),
        .stb_wdata              (stb_wdata),
        .stb_sel_byte           (stb_sel_byte),

        // store_buffer --> store_buffer_controllers
        .stb_full               (stb_full),
        .stb_empty              (stb_empty)
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

        // lsu_stb_controller --> LSU
        .stb_ack                (stb_ack),
        .stb_stall              (stb_stall),

        // lsu_stb_controller --> store_buffer_datapath
        .wr_en                  (wr_en)
    );

/* =========================================== Store Buffer to Cache Controller ================================== */
    stb_cache_controller u_stb_cache_controller (
        .clk                    (clk),
        .rst_n                  (rst_n),

        // store_buffer_datapath --> stb_cache_controller
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        // dcache --> stb_cache_controller
        .dcache2stb_ack         (dcache2stb_ack),

        // stb_cache_controller --> store_buffer_datapath
        .rd_en                  (rd_en),
        .rd_sel                 (rd_sel),

        // stb_cache_controller --> dcache
        .stb_req                (stb_req),
        .stb_w_en               (stb_w_en),
        .dm_sel                 (dm_sel)
    );
    
/* =========================================== Output signals ==================================================== */ 
    assign stb2dcache_empty         = stb_empty;

    // stb (store buffer) --> lsummu
    assign stb2lsummu_o.ack         = stb2lsummu_ack;
    assign stb2lsummu_o.r_data      = stb2lsummu_rdata;

    // store_buffer_top --> dcache
    assign stb2dcache_o.addr        = stb2dcache_addr;
    assign stb2dcache_o.w_data      = stb2dcache_wdata;
    assign stb2dcache_o.sel_byte    = stb2dcache_sel_byte;
    assign stb2dcache_o.w_en        = stb2dcache_w_en;
    assign stb2dcache_o.req         = stb2dcache_req;

endmodule

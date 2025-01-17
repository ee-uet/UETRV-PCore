// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The Store Buffer module. 
//
// Author: Fazail Ali Butt, UET Lahore
// Date: 15.11.2024

`ifndef VERILATOR
`include "../../defines/store_buffer_defs.svh"
`else
`include "store_buffer_defs.svh"
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

// Local Signals
    logic                           wr_en;                  // Store Buffer Write Enable (from LSU controller)
    logic                           rd_en;                  // Store Buffer Read Enable (from Cache controller)
    logic                           stb_full;               // Store Buffer full signal
    logic                           stb_empty, empty_ff;    // Store Buffer empty signal
    logic                           rd_sel;                 // selection for read mux
    logic                           stb_bypass;             // Buffer Bypass signal

    logic                           stb_ack;                // store buffer acknowledgement signal for lsu

    logic [DCACHE_ADDR_WIDTH-1:0]   stb_addr;               // store buffer addr to dcache
    logic [DCACHE_DATA_WIDTH-1:0]   stb_wdata;              // store buffer wdata to dcache
    logic [3:0]                     stb_sel_byte;           // store buffer sel_byte to dcache
    logic                           stb_req;                // store buffer request to dcache
    logic                           stb_w_en;               // store buffer write enable to dcache
    logic                           dm_sel;                 // store buffer dmem selection to dcache

    logic                           st_req;                 // store request

    assign st_req = lsummu2stb_i.req & lsummu2stb_i.w_en;

/* =========================================== Bypassing Store buffer for Load Instructions ====================== */ 
    // Store Buffer bypass for load instructions
    logic wr_ff;
    always_ff @(posedge clk or negedge rst_n ) begin
        if (!rst_n)begin
            empty_ff <= '0;
            wr_ff    <= '0;
        end else begin
            empty_ff <= stb_empty;
            wr_ff    <= lsummu2stb_i.w_en;
        end
    end
    
    assign stb_bypass = ((lsummu2stb_i.req & !wr_ff) | (!lsummu2stb_i.req & !wr_ff)) & empty_ff;
    
/* =========================================== Store Buffer Datapath ============================================= */
    store_buffer_datapath u_store_buffer (
        .clk                    (clk),
        .rst_n                  (rst_n),
        
        // LSU --> store_buffer_datapath
        .lsummu2stb_addr        (lsummu2stb_i.addr),
        .lsummu2stb_wdata       (lsummu2stb_i.w_data),
        .lsummu2stb_sel_byte    (lsummu2stb_i.sel_byte),

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
        .dmem_sel_i             (dmem_sel_i),

        // store buffer top --> lsu_stb_controller
        .st_req                 (st_req),

        // store_buffer_datapath --> lsu_stb_controller 
        .stb_full               (stb_full),  

        // lsu_stb_controller --> LSU
        .stb_ack                (stb_ack),

        // lsu_stb_controller --> store_buffer_datapath
        .wr_en                  (wr_en)
    );

/* =========================================== Store Buffer to Cache Controller ================================== */
    stb_cache_controller u_stb_cache_controller (
        .clk                    (clk),
        .rst_n                  (rst_n),

        // store_buffer_datapath --> stb_cache_controller
        .stb_empty              (stb_empty),

        // dcache --> stb_cache_controller
        .dcache2stb_ack         (dcache2stb_i.ack),

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
    
    always_comb begin
        stb2lsummu_o.ack      = stb_ack;
        stb2lsummu_o.r_data   = '0;

        stb2dcache_o.addr     = stb_addr;
        stb2dcache_o.w_data   = stb_wdata;
        stb2dcache_o.sel_byte = stb_sel_byte;
        stb2dcache_o.req      = stb_req;
        stb2dcache_o.w_en     = stb_w_en;

        dmem_sel_o            = dm_sel;
		if (stb_bypass) begin
		    stb2lsummu_o.ack      = dcache2stb_i.ack;
		    stb2lsummu_o.r_data   = dcache2stb_i.r_data;

		    stb2dcache_o.addr     = lsummu2stb_i.addr;
		    stb2dcache_o.w_data   = lsummu2stb_i.w_data;
		    stb2dcache_o.sel_byte = lsummu2stb_i.sel_byte;
		    stb2dcache_o.req      = lsummu2stb_i.req;
		    stb2dcache_o.w_en     = lsummu2stb_i.w_en;

		    dmem_sel_o            = dmem_sel_i;
        end
    end

endmodule

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

module store_buffer_datapath (
    input  logic                            clk,
    input  logic                            rst_n,

// LSU --> store_buffer_datapath
    input  logic [DCACHE_ADDR_WIDTH-1:0]    lsummu2stb_addr,        // Address input from LSU/MMU
    input  logic [DCACHE_DATA_WIDTH-1:0]    lsummu2stb_wdata,       // Data input from LSU/MMU
    input  logic [3:0]                      lsummu2stb_sel_byte,    // Byte selection input from LSU/MMU
    
// lsu_stb_controller --> store_buffer_datapath
    input  logic                            wr_en,              // Write enable signal

// stb_cache_controller --> store_buffer_datapath
    input  logic                            rd_en,              // Read enable signal
    input  logic                            rd_sel,                 // Read Selection signal

// store_buffer_datapath --> dcache 
    output logic [DCACHE_ADDR_WIDTH-1:0]    stb_addr,        // Address output to Cache
    output logic [DCACHE_DATA_WIDTH-1:0]    stb_wdata,        // Data output to Cache
    output logic [3:0]                      stb_sel_byte,    // Byte selection output to Cache

// store_buffer_datapath --> store buffer controllers
    output logic                            stb_full,               // Full signal
    output logic                            stb_empty               // Empty signal
);

    // Buffer Registers (arrays to hold multiple entries)
    logic [DCACHE_ADDR_WIDTH-1:0]     addr_buf     [BLEN-1:0];
    logic [DCACHE_DATA_WIDTH-1:0]     data_buf     [BLEN-1:0];
    logic [3:0]                       sel_byte_buf [BLEN-1:0];

    // Buffer Counter (to track read and write index)
    logic [$clog2(BLEN)-1:0]  rd_index, rd_index_add;
    logic [$clog2(BLEN)-1:0]  wr_index, wr_index_comp, wr_index_add;

    // counter for write operaitons
    assign wr_index_add = (wr_index == BLEN-1) ? '0: (wr_index + 1);
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_index <= 0;
        end
        else if (wr_en) begin
            wr_index <= wr_index_add;
        end
        else begin
            wr_index <= wr_index;
        end
    end

    // counter for read operaitons
    assign rd_index_add = (rd_index == BLEN-1) ? '0: (rd_index + 1);
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_index <= 0;
        end
        else if (rd_en) begin
            rd_index <= rd_index_add;
        end
        else begin
            rd_index <= rd_index;
        end
    end

    // Write/Read logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            addr_buf     <= addr_buf    ;
            data_buf     <= data_buf    ;
            sel_byte_buf <= sel_byte_buf;
        end 
        else if (wr_en) begin
            // Write new values to buffer at wr_index
            addr_buf     [wr_index] <= lsummu2stb_addr;
            data_buf     [wr_index] <= lsummu2stb_wdata;
            sel_byte_buf [wr_index] <= lsummu2stb_sel_byte;
        end     
        else begin
            addr_buf     [rd_index] <= addr_buf     [rd_index];
            data_buf     [rd_index] <= data_buf     [rd_index];
            sel_byte_buf [rd_index] <= sel_byte_buf [rd_index];
        end
    end

    always_comb begin
        if (rd_sel) begin
            stb_addr     = addr_buf      [rd_index];
            stb_wdata    = data_buf      [rd_index];
            stb_sel_byte = sel_byte_buf  [rd_index];
        end else begin
            stb_addr     = '0;
            stb_wdata    = '0;
            stb_sel_byte = '0;
        end
    end

    assign wr_index_comp = (wr_index == BLEN-1) ? '0: wr_index + 1;
    
    assign stb_full = (rd_index == (wr_index_comp)) ? 1'b1 : 1'b0;
    assign stb_empty = (rd_index == wr_index) ? 1'b1 : 1'b0;

endmodule

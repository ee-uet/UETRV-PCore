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

module store_buffer_datapath (
    input  logic                            clk,
    input  logic                            rst_n,

// LSU --> store_buffer_datapath
    input  logic [DCACHE_ADDR_WIDTH-1:0]    lsummu2stb_addr,        // Address input from LSU/MMU
    input  logic [DCACHE_DATA_WIDTH-1:0]    lsummu2stb_wdata,       // Data input from LSU/MMU
    input  logic [3:0]                      lsummu2stb_sel_byte,    // Byte selection input from LSU/MMU
    //input logic stb_write,
    //input logic stb_request,

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
    logic [$clog2(BLEN)-1:0]  rd_index;
    logic [$clog2(BLEN)-1:0]  wr_index, wr_index_comp;

    // counter for write operaitons
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_index <= 0;
        end
        else if (wr_en) begin
            wr_index <= (wr_index + 1);
        end else begin
            wr_index <= wr_index;
        end
    end

    // counter for read operaitons
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_index <= 0;
        end
        else if (rd_en) begin
            rd_index <= (rd_index + 1);
        end
        else begin
            rd_index <= rd_index;
        end
    end

    // Write/Read logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            addr_buf     [wr_index] <= addr_buf     [wr_index];
            data_buf     [wr_index] <= data_buf     [wr_index];
            sel_byte_buf [wr_index] <= sel_byte_buf [wr_index];
        end else begin
                if (wr_en) begin
                    // Write new values to buffer at wr_index
                    addr_buf     [wr_index] <= lsummu2stb_addr; //addr_ff;
                    data_buf     [wr_index] <= lsummu2stb_wdata; //data_ff;
                    sel_byte_buf [wr_index] <= lsummu2stb_sel_byte; //sel_byte_ff;
                end
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
    
    assign stb_full  = (wr_index_comp == rd_index) ? 1'b1 : 1'b0;
    assign stb_empty = (wr_index == rd_index) ? 1'b1 : 1'b0;
    //assign stb_empty = 1;

endmodule


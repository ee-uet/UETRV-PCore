// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The datapath for data cache. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.6.2023


`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module wb_dcache_datapath(
    input  wire                            clk_i,
    input  wire                            rst_ni,

    // Interface signals to/from cache controller
    input  wire                            cache_wr_i,
    input  wire                            cache_line_wr_i,
    input  wire                            cache_line_clean_i,
    input  wire                            cache_wrb_req_i,
    input  wire [DCACHE_IDX_BITS-1:0]      evict_index_i,
    output logic                           cache_hit_o,
    output logic                           cache_evict_req_o,

    // LSU/MMU to data cache interface
    input  wire                            dcache_flush_i,
    input wire [DCACHE_ADDR_WIDTH-1:0]     lsummu2dcache_addr_i,
    input wire [DCACHE_DATA_WIDTH-1:0]     lsummu2dcache_wdata_i,
    input wire [3:0]                       sel_byte_i,
    output logic [DCACHE_DATA_WIDTH-1:0]   dcache2lsummu_data_o,
  
    // Data cache to data memory interface
    input  wire  [DCACHE_LINE_WIDTH-1:0]   mem2dcache_data_i,
    output logic [DCACHE_LINE_WIDTH-1:0]   dcache2mem_data_o,
    output logic [DCACHE_ADDR_WIDTH-1:0]   dcache2mem_addr_o
  
);

type_dcache_data_s                   cache_data_ram[DCACHE_NO_OF_SETS];
type_dcache_tag_s                    cache_tag_ram[DCACHE_NO_OF_SETS];

type_dcache_data_s                   cache_line_read, cache_line_write;
type_dcache_tag_s                    cache_tag_read, cache_tag_write;

logic [DCACHE_DATA_WIDTH-1:0]        cache_word_read, cache_word_write;
logic [DCACHE_DATA_WIDTH-1:0]        lsummu2dcache_wdata;
logic [3:0]                          sel_byte;
logic [DCACHE_ADDR_WIDTH-1:0]        dcache2mem_addr;

logic [DCACHE_DATA_WIDTH-1:0]        dcache2lsummu_data_ff, dcache2lsummu_data_next;
logic [DCACHE_TAG_BITS-1:0]          addr_tag;
logic [1:0]                          addr_offset;
logic [DCACHE_IDX_BITS-1:0]          addr_index;
logic [DCACHE_IDX_BITS-1:0]          evict_index;
logic                                dcache_flush;                               

assign dcache_flush         = dcache_flush_i;
assign evict_index          = evict_index_i;
assign sel_byte             = sel_byte_i;
assign lsummu2dcache_wdata  = lsummu2dcache_wdata_i;

assign addr_tag             = lsummu2dcache_addr_i[DCACHE_ADDR_WIDTH-1:DCACHE_TAG_LSB];
assign addr_offset          = lsummu2dcache_addr_i[DCACHE_OFFSET_BITS-1:2];
assign addr_index           = dcache_flush ? evict_index :
                              lsummu2dcache_addr_i[DCACHE_TAG_LSB-1:DCACHE_OFFSET_BITS];

// Cache read and write operations 
assign cache_tag_read.tag   = cache_tag_ram[addr_index].tag;
assign cache_tag_read.valid = cache_tag_ram[addr_index].valid;
assign cache_tag_read.dirty = cache_tag_ram[addr_index].dirty;

assign cache_tag_write.tag   = addr_tag;
assign cache_tag_write.valid = 1'b1;
assign cache_tag_write.dirty = 1'b0;

assign cache_line_read = cache_data_ram[addr_index];

always_comb begin
    unique case (addr_offset)
      2'b00:    cache_word_read = cache_line_read[31:0];
      2'b01:    cache_word_read = cache_line_read[63:32];
      2'b10:    cache_word_read = cache_line_read[95:64];
      2'b11:    cache_word_read = cache_line_read[127:96];
      default:  cache_word_read = '0;
    endcase
end

always_comb begin
    cache_word_write = cache_word_read;        
        if (sel_byte[0]) cache_word_write[7:0]   = lsummu2dcache_wdata[7:0]; 
        if (sel_byte[1]) cache_word_write[15:8]  = lsummu2dcache_wdata[15:8]; 
        if (sel_byte[2]) cache_word_write[23:16] = lsummu2dcache_wdata[23:16]; 
        if (sel_byte[3]) cache_word_write[31:24] = lsummu2dcache_wdata[31:24]; 
end

always_comb begin
    cache_line_write = cache_line_read;

    unique case (addr_offset)
        2'b00:    cache_line_write[31:0]   = cache_word_write;
        2'b01:    cache_line_write[63:32]  = cache_word_write;
        2'b10:    cache_line_write[95:64]  = cache_word_write;
        2'b11:    cache_line_write[127:96] = cache_word_write;
      //  default:  dcache2lsummu_data_next = '0;
    endcase
end


always_ff @(posedge clk_i) begin
    if (!rst_ni ) begin // || dcache_flush_i
        for (integer i = 0; i < (DCACHE_NO_OF_SETS); i = i + 1) begin
         //   cache_tag_ram[i].tag   = {DCACHE_TAG_BITS{1'b0}};
            cache_tag_ram[i].valid = 1'b0;
            cache_tag_ram[i].dirty = 1'b0;
         //   cache_data_ram[i]      = {DCACHE_LINE_WIDTH{1'b0}};
        end
    end else if (cache_line_clean_i) begin // Only clean (not invalidate) cache line on flush
        cache_tag_ram[addr_index].dirty <= 1'b0;
    end else if (cache_wr_i) begin
        cache_data_ram[addr_index]      <= cache_line_write;
        cache_tag_ram[addr_index].dirty <= 1'b1;
    end else if (cache_line_wr_i) begin
        cache_tag_ram[addr_index].tag   <= cache_tag_write.tag;
        cache_tag_ram[addr_index].valid <= cache_tag_write.valid;
        cache_tag_ram[addr_index].dirty <= cache_tag_write.dirty;
        cache_data_ram[addr_index]      <= mem2dcache_data_i;
    end
end

// Prepare address and data signals for cache-line writeback or allocate on cache miss 
always_comb begin
    if (cache_wrb_req_i) begin
        dcache2mem_addr = {cache_tag_read.tag, addr_index, {{DCACHE_OFFSET_BITS}{1'b0}}};
    end else begin
        dcache2mem_addr = lsummu2dcache_addr_i;
    end
end


// Read data from cache to LSU/MMU 
assign dcache2lsummu_data_next = cache_word_read;

always_ff@(posedge clk_i) begin
   if(!rst_ni) begin
        dcache2lsummu_data_ff <= '0;
    end else begin
        dcache2lsummu_data_ff <= dcache2lsummu_data_next;
    end
end

// Output signals update
assign cache_hit_o          = (addr_tag == cache_tag_read.tag) && cache_tag_read.valid;
assign cache_evict_req_o    = cache_tag_read.dirty; // & cache_tag_read.valid;
assign dcache2mem_addr_o    = dcache2mem_addr;
assign dcache2mem_data_o    = cache_line_read;
assign dcache2lsummu_data_o = dcache2lsummu_data_ff;

endmodule

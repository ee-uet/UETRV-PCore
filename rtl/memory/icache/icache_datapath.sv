// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The instruction cache datapath. 
//
// Author: Umer Shahid and Ali Imran, UET Lahore
// Date: 10.4.2023


`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module icache_datapath(
  input  wire                            clk_i,
  input  wire                            rst_ni,

  input  wire                            icache_flush,
  input  wire                            cache_rw_i,
  output logic                           cache_hit_o,

  // Instruction Fetch to Instruction Cache Interface
  input wire [ICACHE_ADDR_WIDTH-1:0]     if2icache_addr_i,
  output logic [ICACHE_DATA_WIDTH-1:0]   icache2if_data_o,
  
  // Intruction Cache to Instruction Memory Interface
  input  wire  [ICACHE_LINE_WIDTH-1:0]   mem2icache_data_i,
  output logic [ICACHE_ADDR_WIDTH-1:0]   icache2mem_addr_o
  
);

type_icache_line_s                   icache[0:ICACHE_NO_OF_SETS-1];
type_icache_line_s                   icache_rd_buf, icache_wr_buff;

logic [ICACHE_DATA_WIDTH-1:0]        icache2if_data_ff, icache2if_data_next;
logic [ICACHE_TAG_BITS-1:0]          addr_tag;
logic [1:0]                          addr_offset;
logic [ICACHE_IDX_BITS-1:0]          addr_index;

assign addr_tag                 = if2icache_addr_i[ICACHE_ADDR_WIDTH-1:ICACHE_TAG_LSB];
assign addr_index               = if2icache_addr_i[ICACHE_TAG_LSB-1:ICACHE_OFFSET_BITS];
assign addr_offset              = if2icache_addr_i[ICACHE_OFFSET_BITS-1:2];

assign icache_wr_buff.tag       = addr_tag;
assign icache_wr_buff.valid     = 1'b1;
assign icache_wr_buff.data_line = mem2icache_data_i;

always_ff@(posedge clk_i) begin
   if(!rst_ni) begin
        icache2if_data_ff <= '0;
    end else begin
        icache2if_data_ff <= icache2if_data_next;
    end
end

always_comb begin
    unique case (addr_offset)
      2'b00:    icache2if_data_next = icache_rd_buf.data_line[31:0]  ;
      2'b01:    icache2if_data_next = icache_rd_buf.data_line[63:32] ;
      2'b10:    icache2if_data_next = icache_rd_buf.data_line[95:64] ;
      2'b11:    icache2if_data_next = icache_rd_buf.data_line[127:96];
      default:  icache2if_data_next = '0;
    endcase
end

// Cache read and write operations 
assign icache_rd_buf.tag       = icache[addr_index].tag;
assign icache_rd_buf.valid     = icache[addr_index].valid;
assign icache_rd_buf.data_line = icache[addr_index].data_line ;


always_ff @(posedge clk_i) begin
    if (!rst_ni || icache_flush) begin
        for (integer i = 0; i < (ICACHE_NO_OF_SETS); i = i + 1) begin
            icache[i].tag       = {ICACHE_TAG_BITS{1'b0}};
         //   icache[i].data_line = {ICACHE_LINE_WIDTH{1'b0}};
            icache[i].valid     = 1'b0;
        end
    end else if (cache_rw_i) begin
        icache[addr_index].tag       <= icache_wr_buff.tag;
        icache[addr_index].data_line <= icache_wr_buff.data_line;
        icache[addr_index].valid     <= icache_wr_buff.valid;
    end
end

// Output signals update
assign cache_hit_o        = (addr_tag == icache_rd_buf.tag) && icache_rd_buf.valid && ~icache_flush;
assign icache2mem_addr_o = if2icache_addr_i;
assign icache2if_data_o   = icache2if_data_ff;

endmodule

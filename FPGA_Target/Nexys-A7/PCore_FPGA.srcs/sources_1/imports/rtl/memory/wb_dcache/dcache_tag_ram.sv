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

module dcache_tag_ram
#(
parameter NUM_COL    = 4,
parameter COL_WIDTH  = 8,
parameter ADDR_WIDTH = $clog2(DCACHE_NO_OF_SETS), // 10, 
parameter DATA_WIDTH = NUM_COL*COL_WIDTH          // Data Width in bits
) (
  input wire                     clk,
  input wire                     rst_n,

  input wire                     req,
  input wire   [NUM_COL-1:0]     wr_en, 
  input wire   [ADDR_WIDTH-1:0]  addr,
  input wire   [DATA_WIDTH-1:0]  wdata,
  output logic [DATA_WIDTH-1:0]  rdata
);


// Memory
reg [DATA_WIDTH-1:0]             dcache_tagram[DCACHE_NO_OF_SETS-1:0];

// Cache write operation
generate
genvar i;

for(i=0;i<NUM_COL;i=i+1) begin
always @ (posedge clk) begin
    if (wr_en[i]) begin
         dcache_tagram[addr][i*COL_WIDTH +: COL_WIDTH] <= wdata[i*COL_WIDTH +: COL_WIDTH];
    end
end
end
endgenerate

// Cache read operation
always @ (posedge clk) begin
    if(!rst_n) begin
        rdata <= '0;
    end else if (&wr_en) begin
        rdata <= wdata;
    end else begin
        rdata <= dcache_tagram[addr]; 
    end 
end

endmodule 

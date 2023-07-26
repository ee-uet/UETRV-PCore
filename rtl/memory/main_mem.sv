// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The main memory module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../defines/pcore_config_defs.svh"
`include "../defines/mmu_defs.svh"
`include "../defines/cache_defs.svh"
`include "../defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
`include "pcore_config_defs.svh"
`include "cache_defs.svh"
`include "ddr_defs.svh"
`endif

module main_mem (

    input   logic                                   rst_n,                     // reset
    input   logic                                   clk,                       // clock

    // Cache <---> main memory interface
    input wire type_cache2mem_s                     cache2mem_i,
    output type_mem2cache_s                         mem2cache_o
);

// Local signals
type_mem2cache_s                      mem2cache;
type_cache2mem_s                      cache2mem;

logic [`MEM_ADDR_WIDTH-1:0]           mem_addr;
//logic [3:0]                           dmem_selbyte_ff;
logic                                 mem_wen;
logic                                 mem_req;

// Dual port memory instantiation and initialization
logic [DCACHE_LINE_WIDTH-1:0]          dualport_memory[`IDMEM_SIZE];

`ifdef COMPLIANCE
initial
begin
     // Reading the contents of imem.txt file to memory variable
     // Not required to $readmem for COMPLIANCE Tests
end

`elsif RTL_SIMULATION
initial 
begin
    // Reading the contents of example imem.txt file to memory variable
     $readmemh("imem.txt", dualport_memory);  
end
//`endif
`else
initial
begin
     // Reading the contents of example imem.txt file to memory variable
     $readmemh("sdk/example-linux/imem.txt", dualport_memory);  
end
`endif

//============================ Main memory module ============================//
// Connect the local signals to appropriate IOs of the module
assign cache2mem = cache2mem_i; 
assign mem_addr = cache2mem.addr[`MEM_ADDR_WIDTH-1:4];
assign mem_req = cache2mem.req ;
assign mem_wen = cache2mem.w_en;

// Synchronous load and store operations for data memory
always_ff @(posedge clk) begin  

    if (mem_req & ~mem2cache.ack) begin
        
        if (mem_wen) begin
            dualport_memory[mem_addr] <= cache2mem.w_data;
        end 
        mem2cache.r_data <= dualport_memory[mem_addr];

        mem2cache.ack <= 1'b1;
    end else begin
        mem2cache.ack <= 1'b0;
    end
end

// Update the output signals
assign mem2cache_o = mem2cache;

endmodule : main_mem

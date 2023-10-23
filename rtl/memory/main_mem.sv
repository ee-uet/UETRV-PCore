// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The main memory module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022

`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../defines/mmu_defs.svh"
`include "../defines/cache_defs.svh"
`include "../defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
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

logic [7:0]                 delay_counter;
logic                       response_flag;


// Dual port memory instantiation and initialization
logic [`XLEN-1:0]          dualport_memory[`IDMEM_SIZE];

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
    // $readmemh("sdk/example-linux/imem.txt", dualport_memory);  
end
`endif

//============================ Main memory module ============================//
// Connect the local signals to appropriate IOs of the module
assign cache2mem = cache2mem_i; 
assign mem_addr = {2'b0, cache2mem.addr[`MEM_ADDR_WIDTH-1:2]};
assign mem_req = cache2mem.req ;
assign mem_wen = cache2mem.w_en;


// Synchronous load and store operations for data memory
always_ff @(posedge clk) begin  

    if (mem_req & ~mem2cache.ack & response_flag) begin // 
        
        if (mem_wen) begin
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b00}] <= cache2mem.w_data[31:0];
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b01}] <= cache2mem.w_data[63:32];
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b10}] <= cache2mem.w_data[95:64];
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b11}] <= cache2mem.w_data[127:96];
        end else begin
          //  dmem2dbus_ff.r_data <= dualport_memory[dmem_addr_ff];
            mem2cache.r_data[31:0]   <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b00}];   
            mem2cache.r_data[63:32]  <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b01}];   
            mem2cache.r_data[95:64]  <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b10}];   
            mem2cache.r_data[127:96] <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b11}]; 
            
        end

        mem2cache.ack <= 1'b1;
    end else begin
        mem2cache <= '0;
    end
end


always_ff @(posedge clk) begin 

    if (~rst_n) begin
        delay_counter <= '0; 
    end /* else if (mem_req) begin
        delay_counter <= delay_counter + 7'd1;
    end */ else begin
       // delay_counter <= '0;
        delay_counter <= delay_counter + 7'd1;
    end

end

// assign response_flag = (~mem_wen) ? 1'b1 : delay_counter[2];
assign response_flag = delay_counter[0];



// Update the output signals
assign mem2cache_o = mem2cache;

endmodule


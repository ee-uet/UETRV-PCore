// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The Victim-Cache for data cache. 
//
// Author: Muhammad Ehsan,  Moazzam Ali, Muhammad Mujtaba Rawn
// Date: 08.10.2024

`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module victim_cache (
    input logic                            clk,
    input logic                            rst,
    input logic                            flush_i,

    input logic [DCACHE_LINE_WIDTH-1 : 0]  dcache2victim_data_i,   //input_data
    input logic [VICTIM_ADDR_BITS-1  : 0]  dcache2victim_addr_i,   //input_tag + index
    input logic                            victim_wr_en_i,

    output logic [DCACHE_LINE_WIDTH-1 : 0] victim2dcache_data_o,   //output_data
    output logic [VICTIM_ADDR_BITS-1  : 0] victim2dcache_addr_o ,  //output_tag + index
    output logic                           victim_hit_o
);

//////////////    VICTIM_CACHE      /////////////// 

logic [DCACHE_LINE_WIDTH-1  : 0] victim_cache_data   [VICTIM_NO_OF_SETS-1:0];
logic [VICTIM_ADDR_BITS-1   : 0] victim_cache_addr   [VICTIM_NO_OF_SETS-1:0];

///////////////////////////////////////////////////

logic [VICTIM_COUNTER_BITS-1:0] write_counter;
logic [VICTIM_NO_OF_SETS-1:0]   valid;

/////////////////////////////////////////////////

always_ff @(posedge clk or negedge rst) begin 
    if (!rst || flush_i) begin
        write_counter  <= '0;
        valid          <= '0;
    end
    else if  (victim_wr_en_i) begin
        if ((dcache2victim_addr_i == victim_cache_addr[0]) && valid[0]) begin
            victim_cache_data[0]  <= dcache2victim_data_i;
        end
        else if ((dcache2victim_addr_i == victim_cache_addr[1]) && valid[1]) begin
            victim_cache_data[1]  <= dcache2victim_data_i;
        end
        else if ((dcache2victim_addr_i == victim_cache_addr[2]) && valid[2]) begin
            victim_cache_data[2]  <= dcache2victim_data_i;
        end
        else if ((dcache2victim_addr_i == victim_cache_addr[3]) && valid[3]) begin
            victim_cache_data[3]  <= dcache2victim_data_i;
        end
        else begin
            valid[write_counter]              <= 1'b1;
            victim_cache_data[write_counter]  <= dcache2victim_data_i;
            victim_cache_addr [write_counter] <= dcache2victim_addr_i;
            write_counter                     <= write_counter + 1'b1;            
        end
    end
end


// always_ff @(posedge clk) begin     
//     if (valid[0] && (dcache2victim_addr_i == victim_cache_addr[0])) begin
//         victim2dcache_data_o <= victim_cache_data[0];
//         victim2dcache_addr_o <= victim_cache_addr[0];
//         victim_hit_o         <= 1'b1;
//     end
//     else if (valid[1] && (dcache2victim_addr_i == victim_cache_addr[1])) begin
//         victim2dcache_data_o <= victim_cache_data[1];
//         victim2dcache_addr_o <= victim_cache_addr[1];
//         victim_hit_o         <= 1'b1;
//     end
//     else if (valid[2] && (dcache2victim_addr_i == victim_cache_addr[2])) begin
//         victim2dcache_data_o <= victim_cache_data[2];
//         victim2dcache_addr_o <= victim_cache_addr[2];
//         victim_hit_o         <= 1'b1;
//     end
//     else if (valid[3] && (dcache2victim_addr_i == victim_cache_addr[3])) begin
//         victim2dcache_data_o <= victim_cache_data[3];
//         victim2dcache_addr_o <= victim_cache_addr[3];
//         victim_hit_o         <= 1'b1;
//     end
//     else begin
//         victim2dcache_data_o <= '0;
//         victim2dcache_addr_o <= '0;
//         victim_hit_o         <= 1'b0;
//     end
// end


always_comb begin
    if (!victim_wr_en_i) begin
        if (valid[0] && (dcache2victim_addr_i == victim_cache_addr[0])) begin
            victim2dcache_data_o = victim_cache_data[0];
            victim2dcache_addr_o = victim_cache_addr[0];
            victim_hit_o = 1'b1;
        end
        else if (valid[1] && (dcache2victim_addr_i == victim_cache_addr[1])) begin
            victim2dcache_data_o = victim_cache_data[1];
            victim2dcache_addr_o = victim_cache_addr[1];
            victim_hit_o         = 1'b1;
        end
        else if (valid[2] && (dcache2victim_addr_i == victim_cache_addr[2])) begin
            victim2dcache_data_o = victim_cache_data[2];
            victim2dcache_addr_o = victim_cache_addr[2];
            victim_hit_o         = 1'b1;
        end
        else if (valid[3] && (dcache2victim_addr_i == victim_cache_addr[3])) begin
            victim2dcache_data_o = victim_cache_data[3];
            victim2dcache_addr_o = victim_cache_addr[3];
            victim_hit_o         = 1'b1;
        end
        else begin
            victim2dcache_data_o = '0;
            victim2dcache_addr_o = '0;
            victim_hit_o = 1'b0;
        end
    end
    else begin
        victim2dcache_data_o = '0;
        victim2dcache_addr_o = '0;
        victim_hit_o = 1'b0;
    end
end

endmodule
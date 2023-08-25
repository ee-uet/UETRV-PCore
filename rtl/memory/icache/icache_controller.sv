// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The instruction cache controller module. 
//
// Author: Umer Shahid and Ali Imran, UET Lahore
// Date: 10.4.2023


`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif


module icache_controller (
  input wire                            clk_i, 
  input wire                            rst_ni,

  input wire                            cache_hit_i,
  output logic                          cache_rw_o,
  input wire                            imem_sel_i,
 
  // Instruction fetch to Instruction Cache Interface
  input wire                            if2icache_req_i,
  input wire                            if2icache_req_kill_i,
  output logic                          icache2if_ack_o,

  // Instruction Memory to Instruction Cache Interface
  input  wire                           mem2icache_ack_i,
  output logic                          icache2mem_req_o

);

//test code
type_icache_ways		                   icache_way;
//test code
  
type_icache_states_e                  icache_state_ff, icache_state_next;
logic                                 icache2if_ack;
logic                                 icache_hit;
logic                                 icache_miss;

//test code
logic 				      icache_hit_set0;
logic 				      icache_hit_set1;
logic 				      icache_miss_set0;
logic 				      icache_miss_set1;
//test code

  

//assign icache_hit = if2icache_req_i & imem_sel_i & cache_hit_i;
//assign icache_miss = if2icache_req_i & imem_sel_i & ~cache_hit_i;
//test code
assign icache_hit_way0 = if2icache_req_i & imem_sel_i & cache_hit_i & (icache_way == way0);
assign icache_hit_way1 = if2icache_req_i & imem_sel_i & cache_hit_i & (icache_way == way1);
assign icache_miss_way0 = if2icache_req_i & imem_sel_i & ~cache_hit_i & (icache_way == way0);
assign icache_miss_way1 = if2icache_req_i & imem_sel_i & ~cache_hit_i & (icache_way == way1);
//test code

// Cache controller state machine
always_ff @(posedge clk_i) begin
  if (~rst_ni) begin
      icache_state_ff <= ICACHE_IDLE;
  end else begin
      icache_state_ff <= icache_state_next;
  end
end

 
always_comb begin
    icache_state_next = icache_state_ff;
    icache2mem_req_o  = '0;
    cache_rw_o = '0;
    
    unique case (icache_state_ff)
        ICACHE_IDLE: begin
            // In case of miss, initiate main memory read cycle   
            /**if (icache_miss) begin           
                icache2mem_req_o = 1'b1;
                icache_state_next = ICACHE_READ_MEMORY;
            end else begin
                icache_state_next = ICACHE_IDLE;
            end
        end**/
          
        //test code
         ICACHE_IDLE: begin
            // In case of miss, initiate main memory read cycle   
		 if (icache_miss_way0) begin           
                icache2mem_req_o = 1'b0;
                icache_state_next = ICACHE_READ_WAY1;
            end 
		 else if(icache_miss_way1) begin
		            icache2mem_req_o = 1'b1;
                icache_state_next = ICACHE_READ_MEMORY;
            end
        end
       //test code
          
        ICACHE_READ_MEMORY: begin  
            // Response from main memory is received          
            if (mem2icache_ack_i) begin
                icache_state_next = ICACHE_IDLE;
                cache_rw_o = 1'b1;
                icache2mem_req_o = 1'b0;
            end else begin
                icache_state_next = ICACHE_READ_MEMORY;
                 icache2mem_req_o = 1'b1;
            end
        end
    endcase

    // Kill any ongoing main memory read request if:
    //     1) There is a jump/branch/exception/interrupt leading to new PC
    //     2) The new PC points to boot memory region (only happens on reset) 
    if (~imem_sel_i | if2icache_req_kill_i) begin
        icache_state_next = ICACHE_IDLE;
        cache_rw_o = 1'b0;
        icache2mem_req_o = 1'b0;
    end

end

// Generate the response for the fetch stage
always_comb begin
    if (icache_hit) begin
        icache2if_ack = 1;
    end else begin
        icache2if_ack = 0;
    end
end

always_ff@(posedge clk_i) begin
  if(~rst_ni) begin
      icache2if_ack_o <= '0;
  end else begin
      icache2if_ack_o <= icache2if_ack;
  end
end
  
endmodule

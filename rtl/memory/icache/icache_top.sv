// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The instruction cache top module. 
//
// Author: Umer Shahid and Ali Imran, UET Lahore
// Date: 10.4.2023


`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module icache_top (
  input  wire logic             clk,
  input  wire logic             rst_n,
  input  wire logic             imem_sel_i,

  // Instruction Fetch to Instruction Cache Interface
  input wire type_if2icache_s   if2icache_i,
  output type_icache2if_s       icache2if_o,
  
  // Instruction Cache to Instruction memory Interface  
  input wire type_mem2icache_s  mem2icache_i,
  output type_icache2mem_s      icache2mem_o
);


type_if2icache_s                     if2icache;
type_mem2icache_s                    mem2icache;
type_icache2if_s                     icache2if;
type_icache2mem_s                    icache2mem;

logic                                cache_hit;
logic                                cache_req;
logic                                icache_flush;
logic                                cache_valid_bit;

type_icache_states_e                 icache_state_ff, icache_state_next;
logic                                icache2if_ack, icache2if_ack_ff;
logic                                icache_hit;
logic                                icache_miss;
logic                                if2icache_req;
logic                                imem_sel_ff;

logic [ICACHE_DATA_WIDTH-1:0]        icache2if_data_ff, icache2if_data_next;
logic [`XLEN-1:0]                    icache_wr_tag;
logic [ICACHE_TAG_BITS-1:0]          addr_tag, addr_tag_ff;
logic [1:0]                          addr_offset, addr_offset_ff;
logic [ICACHE_IDX_BITS-1:0]          addr_index;

logic [ICACHE_IDX_BITS-1:0]          flush_index_next, flush_index_ff;
logic                                icache_flush_ff;
logic                                icache_flush_done;

// 2-way associativity related signal definitions
logic [ICACHE_LINE_WIDTH-1:0]        icache_rd_data; 
logic [ICACHE_LINE_WIDTH-1:0]        icache_rd_data_way[0:3];
logic [`XLEN-1:0]                    icache_rd_tag_way[0:3]; 
logic [1:0]                          replace_way_ff; 
logic [3:0]                          cache_wr_way; 
logic [3:0]                          cache_hit_way; 


assign if2icache         = if2icache_i;
assign mem2icache.r_data = mem2icache_i.r_data;
assign mem2icache.ack    = mem2icache_i.ack;

assign icache_flush = if2icache.icache_flush || icache_flush_ff;

assign cache_hit_way[0] = icache_rd_tag_way[0][31] && (icache_rd_tag_way[0][ICACHE_TAG_BITS-1:0] == addr_tag_ff);
assign cache_hit_way[1] = icache_rd_tag_way[1][31] && (icache_rd_tag_way[1][ICACHE_TAG_BITS-1:0] == addr_tag_ff);
assign cache_hit_way[2] = icache_rd_tag_way[2][31] && (icache_rd_tag_way[2][ICACHE_TAG_BITS-1:0] == addr_tag_ff);
assign cache_hit_way[3] = icache_rd_tag_way[3][31] && (icache_rd_tag_way[3][ICACHE_TAG_BITS-1:0] == addr_tag_ff);


assign cache_hit   = (|cache_hit_way) && ~icache_flush; 
assign icache_hit  = if2icache_req & imem_sel_ff & cache_hit;
assign icache_miss = if2icache_req & imem_sel_ff & ~cache_hit;

assign cache_req   = if2icache.req & imem_sel_i;
assign addr_tag    = if2icache.addr[ICACHE_ADDR_WIDTH-1:ICACHE_TAG_LSB];
assign addr_offset = if2icache.addr[ICACHE_OFFSET_BITS-1:2];
assign addr_index  = icache_flush_ff ? flush_index_ff : if2icache.addr[ICACHE_TAG_LSB-1:ICACHE_OFFSET_BITS];

assign icache_wr_tag  = {cache_valid_bit, {`XLEN-ICACHE_TAG_BITS-1{1'b0}}, addr_tag}; 

// Select the requested word from the read cache data line
assign icache_rd_data = cache_hit_way[3] ? icache_rd_data_way[3] : cache_hit_way[2] ? icache_rd_data_way[2] : cache_hit_way[1] ? icache_rd_data_way[1] : icache_rd_data_way[0];

always_comb begin
    unique case (addr_offset_ff) 
      2'b00:    icache2if_data_next = icache_rd_data[31:0]  ;
      2'b01:    icache2if_data_next = icache_rd_data[63:32] ;
      2'b10:    icache2if_data_next = icache_rd_data[95:64] ;
      2'b11:    icache2if_data_next = icache_rd_data[127:96];
      default:  icache2if_data_next = '0;
    endcase
end

always_ff@(posedge clk) begin
  if(!rst_n) begin
      addr_tag_ff    <= '0;
      addr_offset_ff <= '0;
      if2icache_req  <= '0;
      imem_sel_ff    <= '0;
  end else begin
      addr_tag_ff    <= addr_tag;
      addr_offset_ff <= addr_offset;
      if2icache_req  <= if2icache.req;
      imem_sel_ff    <= imem_sel_i;
  end
end


// 2-way associativity
always @ (posedge clk) begin
    if (!rst_n) begin
        replace_way_ff <= '0;
    end else if (mem2icache.ack) begin
        replace_way_ff <= replace_way_ff + 2'd1;
    end
end


// Cache flush flag
always_ff @(posedge clk) begin
  if (!rst_n) begin
      icache_flush_ff  <= '0;
  end else if (if2icache.icache_flush) begin
      icache_flush_ff <= 1'b1;
  end else if (icache_flush_done) begin
      icache_flush_ff <= 1'b0;
  end 
end

// Cache controller state machine
always_ff @(posedge clk) begin
  if (!rst_n) begin
      icache_state_ff <= ICACHE_IDLE;
      flush_index_ff  <= '0;
  end else begin
      icache_state_ff <= icache_state_next;
      flush_index_ff  <= flush_index_next;
  end
end
 
always_comb begin
    icache_state_next = icache_state_ff;
    flush_index_next  = '0; //flush_index_ff;
    icache2mem.req    = '0;
    cache_wr_way      = '0;
    cache_valid_bit   = '0;
    icache_flush_done = 1'b0;
    
    unique case (icache_state_ff)
        ICACHE_IDLE: begin
            // In case of miss, initiate main memory read cycle   
            if (if2icache.icache_flush) begin           
                icache_state_next = ICACHE_FLUSH;
            end else if (icache_miss & ~if2icache.req_kill) begin           
                icache2mem.req = 1'b1;
                icache_state_next = ICACHE_READ_MEMORY;
            end else begin
                icache_state_next = ICACHE_IDLE;
            end
        end
        ICACHE_READ_MEMORY: begin  
            // Response from main memory is received          
            if (if2icache.req_kill) begin 
                icache_state_next = ICACHE_IDLE;
                icache2mem.req = 1'b0;
                icache2mem.kill = 1'b1;
            end else if (mem2icache.ack) begin
                icache_state_next = ICACHE_IDLE;
                cache_valid_bit = 1'b1;
                icache2mem.req = 1'b0;
                if (replace_way_ff == 2'd3)
                    cache_wr_way[3] = 1'b1;
                else if (replace_way_ff == 2'd2)
                    cache_wr_way[2] = 1'b1;
                else if (replace_way_ff == 2'd1)
                    cache_wr_way[1] = 1'b1;
                else 
                    cache_wr_way[0] = 1'b1;
            end else begin
                icache_state_next = ICACHE_READ_MEMORY;
                icache2mem.req = 1'b1;
            end
        end
        ICACHE_FLUSH: begin
                
            if (&flush_index_ff) begin  
                icache_flush_done = 1'b1;
                icache_state_next = ICACHE_IDLE;
            end else begin
                flush_index_next = flush_index_ff + 1;
                icache_state_next = ICACHE_FLUSH;
                cache_valid_bit = 1'b0;
                cache_wr_way    = 4'hF;
            end
        end
       
        default: begin      end
    endcase

    // Kill any ongoing main memory read request if:
    //     1) The new PC points to boot memory region (only happens on reset) 
    if (~imem_sel_i) begin  // | if2icache_req_kill_i
        icache_state_next = ICACHE_IDLE;
        cache_wr_way   = '0;    
        icache2mem.req = 1'b0;
    end

end


icache_data_ram icache_data_ram_module0 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (mem2icache.r_data),
  .wr_en                (cache_wr_way[0]),
  .rdata                (icache_rd_data_way[0])  
);

icache_tag_ram icache_tag_ram_module0 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (icache_wr_tag),
  .wr_en                (cache_wr_way[0]),
  .rdata                (icache_rd_tag_way[0])
);

icache_data_ram icache_data_ram_module1 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (mem2icache.r_data),
  .wr_en                (cache_wr_way[1]),
  .rdata                (icache_rd_data_way[1])  
);

icache_tag_ram icache_tag_ram_module1 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (icache_wr_tag),
  .wr_en                (cache_wr_way[1]),
  .rdata                (icache_rd_tag_way[1])
);

icache_data_ram icache_data_ram_module2 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (mem2icache.r_data),
  .wr_en                (cache_wr_way[2]),
  .rdata                (icache_rd_data_way[2])  
);

icache_tag_ram icache_tag_ram_module2 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (icache_wr_tag),
  .wr_en                (cache_wr_way[2]),
  .rdata                (icache_rd_tag_way[2])
);

icache_data_ram icache_data_ram_module3 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (mem2icache.r_data),
  .wr_en                (cache_wr_way[3]),
  .rdata                (icache_rd_data_way[3])  
);

icache_tag_ram icache_tag_ram_module3 (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .addr                 (addr_index),
  .wdata                (icache_wr_tag),
  .wr_en                (cache_wr_way[3]),
  .rdata                (icache_rd_tag_way[3])
);

// Generate the response for the fetch stage
always_comb begin
    if (icache_hit) begin
        icache2if_ack = 1;
    end else begin
        icache2if_ack = 0;
    end
end

// Output signals update
assign icache2mem.addr  = if2icache.addr;
assign icache2if.r_data = icache2if_data_next; 
assign icache2if.ack    = icache2if_ack;     
assign icache2if_o      = icache2if;
assign icache2mem_o     = icache2mem;

endmodule
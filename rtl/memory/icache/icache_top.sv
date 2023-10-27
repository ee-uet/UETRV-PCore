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


//type_icache_line_s                   icache[0:ICACHE_NO_OF_SETS-1];

logic                          cache_hit;
logic                          cache_rw;
logic                          cache_req;
logic                          icache_flush;
logic                          cache_valid_bit;

type_if2icache_s               if2icache;
type_mem2icache_s              mem2icache;
type_icache2if_s               icache2if;
type_icache2mem_s              icache2mem;

type_icache_states_e                 icache_state_ff, icache_state_next;
type_icache_line_s                   icache_rd_buf;
logic                                icache2if_ack, icache2if_ack_ff;
logic                                icache_hit;
logic                                icache_miss;
logic                                if2icache_req;
logic                                imem_sel_ff;

logic [ICACHE_DATA_WIDTH-1:0]        icache2if_data_ff, icache2if_data_next;
logic [`XLEN-1:0]                    icache_wr_tag, icache_rd_tag;
logic [ICACHE_TAG_BITS-1:0]          addr_tag, addr_tag_ff;
logic [1:0]                          addr_offset, addr_offset_ff;
logic [ICACHE_IDX_BITS-1:0]          addr_index;

logic [ICACHE_IDX_BITS-1:0]          flush_index_next, flush_index_ff;
logic                                icache_flush_ff;
logic                                icache_flush_done;


assign if2icache         = if2icache_i;
assign mem2icache.r_data = mem2icache_i.r_data;
assign mem2icache.ack    = mem2icache_i.ack;

assign icache_flush = if2icache.icache_flush || icache_flush_ff;

assign cache_hit   = (addr_tag_ff == icache_rd_buf.tag) && icache_rd_buf.valid && ~icache_flush; // MT
assign icache_hit  = if2icache_req & imem_sel_ff & cache_hit;
assign icache_miss = if2icache_req & imem_sel_ff & ~cache_hit;


// Cache flush flag
always_ff @(posedge clk) begin
  if (!rst_n) begin
      icache_flush_ff  <= '0;
  end else if (if2icache.icache_flush) begin
      icache_flush_ff <= 1'b1;
  end else if (icache_flush_done) begin
      icache_flush_ff <= 1'b0;
  end /*else begin
      icache_flush_ff <= icache_flush_ff;
  end */
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
    icache2mem.req  = '0;
    cache_rw = '0;
    cache_valid_bit = '0;
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
                cache_rw = 1'b0;
                icache2mem.req = 1'b0;
                icache2mem.kill = 1'b1;
            end else if (mem2icache.ack) begin
                icache_state_next = ICACHE_IDLE;
                cache_rw = 1'b1;
                cache_valid_bit = 1'b1;
                icache2mem.req = 1'b0;
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
                cache_rw = 1'b1;
                cache_valid_bit = 1'b0;
            end
        end
       
        default: begin      end
    endcase

    // Kill any ongoing main memory read request if:
    //     1) The new PC points to boot memory region (only happens on reset) 
    if (~imem_sel_i) begin  // | if2icache_req_kill_i
        icache_state_next = ICACHE_IDLE;
        cache_rw = 1'b0;
        icache2mem.req = 1'b0;
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


always_ff@(posedge clk) begin
  if(!rst_n) begin
      icache2if_ack_ff <= '0;
  end else begin
      icache2if_ack_ff <= icache2if_ack;
  end
end

always_ff@(posedge clk) begin
   if(!rst_n) begin
        icache2if_data_ff <= '0;
    end else begin
        icache2if_data_ff <= icache2if_data_next;
    end
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


//assign icache2if_ack_o = icache2if_ack;
assign cache_req = if2icache.req & imem_sel_i;
assign addr_tag       = if2icache.addr[ICACHE_ADDR_WIDTH-1:ICACHE_TAG_LSB];
assign addr_offset    = if2icache.addr[ICACHE_OFFSET_BITS-1:2];
//assign addr_index     = if2icache.addr[ICACHE_TAG_LSB-1:ICACHE_OFFSET_BITS];
assign addr_index  = icache_flush_ff ? flush_index_ff : if2icache.addr[ICACHE_TAG_LSB-1:ICACHE_OFFSET_BITS];

always_comb begin
    unique case (addr_offset_ff) // MT
      2'b00:    icache2if_data_next = icache_rd_buf.data_line[31:0]  ;
      2'b01:    icache2if_data_next = icache_rd_buf.data_line[63:32] ;
      2'b10:    icache2if_data_next = icache_rd_buf.data_line[95:64] ;
      2'b11:    icache2if_data_next = icache_rd_buf.data_line[127:96];
      default:  icache2if_data_next = '0;
    endcase
end

assign icache_wr_tag  = {cache_valid_bit, {`XLEN-ICACHE_TAG_BITS-1{1'b0}}, addr_tag}; 

assign icache_rd_buf.tag   = icache_rd_tag[ICACHE_TAG_BITS-1:0];
assign icache_rd_buf.valid = icache_rd_tag[31];

icache_data_ram icache_data_ram_module (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .wr_en                (cache_rw),
  .addr                 (addr_index),
  .wdata                (mem2icache.r_data),
  .rdata                (icache_rd_buf.data_line) // 
);

icache_tag_ram icache_tag_ram_module (
  .clk                  (clk), 
  .rst_n                (rst_n),

  .req                  (cache_req),
  .wr_en                (cache_rw),
  .addr                 (addr_index),
  .wdata                (icache_wr_tag),
  .rdata                (icache_rd_tag)
);


// Output signals update
assign icache2mem.addr  = if2icache.addr;
assign icache2if.r_data = icache2if_data_next; // MT
assign icache2if.ack    = icache2if_ack;     // MT
assign icache2if_o      = icache2if;
assign icache2mem_o     = icache2mem;

endmodule

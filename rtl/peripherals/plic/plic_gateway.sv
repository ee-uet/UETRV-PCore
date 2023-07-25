// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The platform level interrupt controller (PLIC) gateway module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.12.2022


`ifndef VERILATOR
`include "../../defines/plic_defs.svh"
`else
`include "plic_defs.svh"
`endif

module plic_gateway (
   input logic                                             rst_n,           // reset
   input logic                                             clk,             // clock

   input [PLIC_SOURCE_COUNT-1:0]                            irq_src_i,
   input [PLIC_SOURCE_COUNT-1:0]                            edge_select_i,     // 0 is level and 1 is edge triggered


  input wire type_regs2gateway_s                           regs2gateway_i,
  input [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]     claim_idx_i,

  output logic [PLIC_SOURCE_COUNT-1:0]                     irq_pending_o
);


// Signal definitions for module interfaces
type_regs2gateway_s                                       regs2gateway;

logic [PLIC_SOURCE_COUNT-1:0]                             irq_pending_ff, irq_pending_next;
logic [PLIC_SOURCE_COUNT-1:0]                             irq_active_ff, irq_active_next;    
logic [PLIC_SOURCE_COUNT-1:0]                             irq_set_pending;
logic [PLIC_SOURCE_COUNT-1:0]                             irq_set_active;
logic [PLIC_SOURCE_COUNT-1:0]                             irq_req;   

logic [PLIC_SOURCE_COUNT-1:0]                             irq_src_ff, irq_src_next;


logic [PLIC_SOURCE_COUNT-1:0]                             claim;      // One hot claim signal
logic [PLIC_SOURCE_COUNT-1:0]                             complete;   // One hot complete signal
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]      claim_idx;
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]      complete_idx;

// Signal assignments
assign irq_src_next = irq_src_i;
assign regs2gateway = regs2gateway_i;
assign claim_idx    = claim_idx_i;
assign complete_idx = regs2gateway.complete_idx;

always_comb begin
    claim = '0;
    complete = '0;
    for (int i = 0 ; i < PLIC_TARGET_COUNT ; i++) begin

        if (regs2gateway.claim_req[i] && claim_idx[i] != 0) begin 
            claim[claim_idx[i]-1] = 1'b1;
        end

        if (regs2gateway.complete_req[i] && complete_idx[i] != 0) begin 
            complete[complete_idx[i]-1] = 1'b1;
        end
    end
end

// Capture the incoming interrupts
always_ff @(posedge clk) begin
    if (~rst_n) begin 
        irq_src_ff <= '0;
    end else begin
        irq_src_ff <= irq_src_next;
    end
end

always_comb begin
  for (int i = 0 ; i < PLIC_SOURCE_COUNT; i++) begin
    irq_req[i] = (edge_select_i[i]) ? irq_src_next[i] & ~irq_src_ff[i] : irq_src_next[i];
  end
end

// IRQ source is responsible to set corresponding interrupt pending bit, which 
// is cleared by the respective claim request. A second IRQ request from the 
// same source is ignored till the interrupt has been claimed.
always_ff @(posedge clk) begin
  if (~rst_n) begin
    irq_pending_ff <= '0;
  end else begin
    irq_pending_ff <= irq_pending_next;
  end
end

always_comb begin 
    irq_set_pending  = (irq_req & ~irq_active_ff & ~irq_pending_ff);
    irq_pending_next = (irq_pending_ff | irq_set_pending) & (~claim);            
end

// Interrupt active controls the pending behavior. The pending bit is cleared 
// by the corresponding claim request, but the setting of pending bit again is
// postponed till the complete request from the target is received. 
always_ff @(posedge clk) begin
  if (~rst_n) begin
    irq_active_ff <= '0;
  end else begin
    irq_active_ff <= irq_active_next;
  end
end

always_comb begin 
    irq_set_active  = irq_req & ~irq_active_ff;
    irq_active_next = (irq_active_ff | irq_set_active) & (~complete);            
end


// Output signal assignments
assign irq_pending_o = irq_pending_ff;

endmodule

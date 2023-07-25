// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The platform level interrupt controller (PLIC) target module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.12.2022


`ifndef VERILATOR
`include "../../defines/plic_defs.svh"
`else
`include "plic_defs.svh"
`endif

module plic_target (
  input logic                                             clk,
  input logic                                             rst_n,

  input [PLIC_SOURCE_COUNT-1:0]                           irq_pending_i,

  input [PLIC_SOURCE_COUNT-1:0]                           regs_ie_i,
  input [PLIC_SOURCE_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]      regs_prio_i,
  input [PLIC_PRIO_WIDTH-1:0]                             regs_prio_th_i,

  output logic                                            irq_req_o,
  output logic [PLIC_SOURCE_WIDTH-1:0]                    irq_idx_o
);

// Interface signals
logic [PLIC_SOURCE_COUNT-1:0]                        irq_pending;
logic [PLIC_SOURCE_COUNT-1:0]                        regs_ie;
logic [PLIC_SOURCE_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]   regs_prio;

logic [PLIC_PRIO_WIDTH-1:0]                          prio_th;

logic                                                irq_req_ff, irq_req_next;
logic [PLIC_SOURCE_WIDTH-1:0]                        irq_idx_ff, irq_idx_next;
 
// Signal assignments
assign irq_pending = irq_pending_i;
assign regs_ie     = regs_ie_i;
assign regs_prio   = regs_prio_i;

always_comb begin
    prio_th      = regs_prio_th_i;
    irq_idx_next = '0; 
    irq_req_next = 1'b0;

    for (int i = PLIC_SOURCE_COUNT-1 ; i >= 0 ; i--) begin
        if ((irq_pending[i] & regs_ie[i]) == 1'b1 && regs_prio[i] > prio_th) begin
            prio_th      = regs_prio[i];
            irq_idx_next = PLIC_SOURCE_WIDTH'(i+1);
            irq_req_next = 1'b1;
        end
    end 
end

always_ff @(posedge clk) begin
    if (!rst_n) begin
        irq_req_ff <= 1'b0;
        irq_idx_ff <= '0;
    end else begin
        irq_req_ff <= irq_req_next;
        irq_idx_ff <= irq_idx_next;
    end
end


// Output signal assignments
assign irq_idx_o = irq_idx_ff;
assign irq_req_o = irq_req_ff;

endmodule


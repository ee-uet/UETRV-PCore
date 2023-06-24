// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The platform level interrupt controller (PLIC) top module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.12.2022

`ifndef VERILATOR
`include "../../defines/plic_defs.svh"
`else
`include "plic_defs.svh"
`endif

module plic_top (
    input logic                                    rst_n,               // reset
    input logic                                    clk,                 // clock

    // Dbus to PLIC module interface
    input wire type_dbus2peri_s                    dbus2plic_i,              
    output type_peri2dbus_s                        plic2dbus_o, 

    // Selection signal from Dbus interconnect address decoder
    input logic                                    plic_sel_i, 

    input logic [PLIC_SOURCE_COUNT-1:0]            edge_select_i,     // 1 for edge
  
    input  logic [PLIC_SOURCE_COUNT-1:0]           irq_src_i,         // External interrupt sources
    output logic [PLIC_TARGET_COUNT-1:0]           irq_targets_o      // Separate interrupt signals to each target
);

type_regs2gateway_s                                     regs2gateway;

logic [PLIC_SOURCE_COUNT-1:0]                           irq_pending;
logic [PLIC_TARGET_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]      regs_prio_th; 
logic [PLIC_SOURCE_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]      regs_prio;
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_COUNT-1:0]    regs_ie;
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]    claim_idx;

// Instantiate PLIC gateway
plic_gateway  plic_gateway_module (
    .rst_n                      (rst_n),
    .clk                        (clk),	

    .irq_src_i                  (irq_src_i),
    .edge_select_i              (edge_select_i),

    .regs2gateway_i             (regs2gateway),
    .claim_idx_i                (claim_idx),
 
    .irq_pending_o              (irq_pending)
);


// Instantiate target modules depending on the number of targets
for (genvar i = 0 ; i < PLIC_TARGET_COUNT; i++) begin 

    plic_target  plic_target_module (
        .rst_n                  (rst_n),
        .clk                    (clk),	

        .irq_pending_i          (irq_pending),

        .regs_ie_i              (regs_ie[i]),
        .regs_prio_i            (regs_prio),
        .regs_prio_th_i         (regs_prio_th[i]),

        .irq_req_o              (irq_targets_o[i]),
        .irq_idx_o              (claim_idx[i])
    );
end

// Instantiate PLIC registers
plic_regs plic_regs_module (
    .rst_n                      (rst_n),
    .clk                        (clk),	

    .dbus2plic_i                (dbus2plic_i),
    .plic2dbus_o                (plic2dbus_o),
    .plic_sel_i                 (plic_sel_i),

    .regs_ie_o                  (regs_ie),
    .regs_prio_o                (regs_prio),
    .regs_prio_th_o             (regs_prio_th),
    
    .irq_pending_i              (irq_pending), 
    .claim_idx_i                (claim_idx),

    .regs2gateway_o             (regs2gateway)
);

endmodule

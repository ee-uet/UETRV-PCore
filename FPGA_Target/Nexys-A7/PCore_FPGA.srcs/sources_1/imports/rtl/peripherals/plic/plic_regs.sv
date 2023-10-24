// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The platform level interrupt controller (PLIC) registers. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.12.2022


`ifndef VERILATOR
`include "../../defines/plic_defs.svh"
`else
`include "plic_defs.svh"
`endif

module plic_regs (

    input logic                                                    rst_n,           // reset
    input logic                                                    clk,             // clock

    // Dbus to PLIC module interface
    input wire type_dbus2peri_s                                    dbus2plic_i,              
    output type_peri2dbus_s                                        plic2dbus_o, 

    // Selection signal from address decoder of Dbus interconnect 
    input logic                                                    plic_sel_i, 

    // Regs <---> Target interface signals 
    output logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_COUNT-1:0]    regs_ie_o,
    output logic [PLIC_SOURCE_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]      regs_prio_o,
    output logic [PLIC_TARGET_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]      regs_prio_th_o,   
    //  
    input wire [PLIC_SOURCE_COUNT-1:0]                             irq_pending_i,       
    input wire [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]      claim_idx_i,
 
    output type_regs2gateway_s                                     regs2gateway_o

);

// Signal definitions for module interfaces
type_regs2gateway_s                                    regs2gateway;

logic [PLIC_TARGET_COUNT-1:0]                          claim_req;    // Target read request
logic [PLIC_TARGET_COUNT-1:0]                          complete_req; // Target write request
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]   complete_idx;

// Signal definitions for Dbus interface
logic [`PLIC_REG_OFFSET_WIDTH-1:0]                     reg_addr;
logic                                                  reg_rd_req;
logic                                                  reg_wr_req;

// Read and write data for PLIC registers
logic [`XLEN-1:0]                                      reg_r_data; 
logic [`XLEN-1:0]                                      reg_w_data;


// PLIC register definitions
logic [PLIC_TARGET_COUNT-1:0]                          prio_th_reg_wr_flag;
logic [PLIC_SOURCE_COUNT-1:0]                          prio_reg_wr_flag;
logic [PLIC_TARGET_COUNT-1:0]                          ie_reg_wr_flag;

logic [PLIC_TARGET_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]     plic_reg_prio_th_ff, plic_reg_prio_th_next;
logic [PLIC_SOURCE_COUNT-1:0][PLIC_PRIO_WIDTH-1:0]     plic_reg_prio_ff, plic_reg_prio_next;
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_COUNT-1:0]   plic_reg_ie_ff, plic_reg_ie_next;

logic [PLIC_SOURCE_COUNT-1:0]                          plic_reg_irq_pending;
logic [PLIC_TARGET_COUNT-1:0][PLIC_SOURCE_WIDTH-1:0]   claim_idx;

// Signal assignments
assign plic_reg_irq_pending = irq_pending_i;     
assign claim_idx            = claim_idx_i;


//================================= PLIC registers read operations ==================================//

always_comb begin
    reg_r_data = '0;
    claim_req  = '0;

    if(reg_rd_req) begin
        case(reg_addr)
            24'h000000: reg_r_data[PLIC_PRIO_WIDTH-1:0] = '0;                        // IRQ 0 is reserved
            24'h000004: reg_r_data[PLIC_PRIO_WIDTH-1:0] = plic_reg_prio_ff[0][PLIC_PRIO_WIDTH-1:0];
            24'h000008: reg_r_data[PLIC_PRIO_WIDTH-1:0] = plic_reg_prio_ff[1][PLIC_PRIO_WIDTH-1:0];
            24'h001000: reg_r_data[PLIC_SOURCE_COUNT:0] = {plic_reg_irq_pending[PLIC_SOURCE_COUNT-1:0], 1'b0};
            24'h002000: reg_r_data[PLIC_SOURCE_COUNT:0] = {plic_reg_ie_ff[0][PLIC_SOURCE_COUNT-1:0], 1'b0};
            24'h002080: reg_r_data[PLIC_SOURCE_COUNT:0] = {plic_reg_ie_ff[1][PLIC_SOURCE_COUNT-1:0], 1'b0};
            24'h200000: reg_r_data[PLIC_PRIO_WIDTH-1:0] = plic_reg_prio_th_ff[0][PLIC_PRIO_WIDTH-1:0];
            24'h201000: reg_r_data[PLIC_PRIO_WIDTH-1:0] = plic_reg_prio_th_ff[1][PLIC_PRIO_WIDTH-1:0];
            24'h200004: begin
                reg_r_data[PLIC_SOURCE_WIDTH-1:0] = claim_idx[0][PLIC_SOURCE_WIDTH-1:0];
                claim_req[0] = 1'b1;
            end
            24'h201004: begin
                reg_r_data[PLIC_SOURCE_WIDTH-1:0] = claim_idx_i[1][PLIC_SOURCE_WIDTH-1:0];
                claim_req[1] = 1'b1;
            end
            default    :        ;                 // Should not get here
      endcase
    end 
end

//================================= PLIC registers write operations ==================================//

always_comb begin
    prio_reg_wr_flag    = '0;
    ie_reg_wr_flag      = '0;
    prio_th_reg_wr_flag = '0;
    complete_idx        = '0;
    complete_req        = '0;
  
 
    if (reg_wr_req & ~plic2dbus_ff.ack) begin
        unique case(reg_addr)
        24'h000000:                              ; // IRQ 0 is reserved
        24'h000004: prio_reg_wr_flag[0]    = 1'b1;
        24'h000008: prio_reg_wr_flag[1]    = 1'b1;
        24'h002000: ie_reg_wr_flag[0]      = 1'b1;
        24'h002080: ie_reg_wr_flag[1]      = 1'b1;
        24'h200000: prio_th_reg_wr_flag[0] = 1'b1;
        24'h201000: prio_th_reg_wr_flag[1] = 1'b1;
        24'h200004: begin
          complete_idx[0][PLIC_SOURCE_WIDTH-1:0] = reg_w_data[PLIC_SOURCE_WIDTH-1:0];
          complete_req[0] = 1'b1;
        end
        24'h201004: begin
          complete_idx[1][PLIC_SOURCE_WIDTH-1:0] = reg_w_data[PLIC_SOURCE_WIDTH-1:0];
          complete_req[1] = 1'b1;
        end
        default:     ;   // Should not end up here
      endcase
    end 
end


// Update PLIC priority registers 
// ------------------------------
always_ff @(posedge clk) begin
    if (~rst_n) begin
        plic_reg_prio_ff    <= '0;
    end else begin
        plic_reg_prio_ff <= plic_reg_prio_next;       
    end
end

always_comb begin 

    for (int i = 0; i < PLIC_SOURCE_COUNT; i++) begin
        if (prio_reg_wr_flag[i]) begin
            plic_reg_prio_next[i] = reg_w_data[PLIC_PRIO_WIDTH-1:0];
        end else begin
            plic_reg_prio_next[i] = plic_reg_prio_ff[i];
        end
    end
end


// Update PLIC priority threshold registers 
// ----------------------------------------
always_ff @(posedge clk) begin
    if (~rst_n) begin
        plic_reg_prio_th_ff    <= '0;
    end else begin
        plic_reg_prio_th_ff <= plic_reg_prio_th_next;       
    end
end

always_comb begin 

    for (int i = 0; i < PLIC_TARGET_COUNT; i++) begin
        if (prio_th_reg_wr_flag[i]) begin
            plic_reg_prio_th_next[i] = reg_w_data[PLIC_PRIO_WIDTH-1:0];
        end else begin
            plic_reg_prio_th_next[i] = plic_reg_prio_th_ff[i];
        end
    end
end


// Update PLIC interrupt enable registers 
// --------------------------------------
always_ff @(posedge clk) begin
    if (~rst_n) begin
        plic_reg_ie_ff    <= '0;
    end else begin
        plic_reg_ie_ff <= plic_reg_ie_next;       
    end
end

always_comb begin 

    for (int i = 0; i < PLIC_TARGET_COUNT; i++) begin
        if (ie_reg_wr_flag[i]) begin
            plic_reg_ie_next[i] = reg_w_data[PLIC_SOURCE_COUNT:1];
        end else begin
            plic_reg_ie_next[i] = plic_reg_ie_ff[i];
        end
    end
end


//================================= Dbus interface ==================================//
type_peri2dbus_s                      plic2dbus_ff;

// Signal interface to data bus
assign reg_addr   = type_plic_regs_e'(dbus2plic_i.addr[`PLIC_REG_OFFSET_WIDTH-1:0]);
assign reg_w_data = dbus2plic_i.w_data;
assign reg_rd_req = !dbus2plic_i.w_en && dbus2plic_i.req && plic_sel_i;
assign reg_wr_req = dbus2plic_i.w_en  && dbus2plic_i.req && plic_sel_i;

// PLIC synchronous read operation 
always_ff @(posedge clk) begin  
    plic2dbus_ff <= '0;
    if ((reg_wr_req | reg_rd_req) & ~plic2dbus_ff.ack) begin
        plic2dbus_ff.ack <= 1'b1;
        if (reg_rd_req)
        plic2dbus_ff.r_data <= reg_r_data;  
        
    end 
end  

assign regs2gateway.claim_req    = claim_req;
assign regs2gateway.complete_req = complete_req;
assign regs2gateway.complete_idx = complete_idx;

// Response signals to dbus 
assign plic2dbus_o.r_data = plic2dbus_ff.r_data;
assign plic2dbus_o.ack = plic2dbus_ff.ack;

// Output signals for different modules
assign regs_ie_o      = plic_reg_ie_ff;
assign regs_prio_o    = plic_reg_prio_ff;
assign regs_prio_th_o = plic_reg_prio_th_ff;
assign regs2gateway_o = regs2gateway;

endmodule


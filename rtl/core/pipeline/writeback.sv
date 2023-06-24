// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The writeback stage of the pipeline.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../../defines/m_ext_defs.svh"
`else
`include "m_ext_defs.svh"
`endif

module writeback (

    input   logic                            rst_n,                    // reset
    input   logic                            clk,                      // clock

    // LSU <---> Writeback interface
    input wire type_lsu2wrb_data_s           lsu2wrb_data_i,
    input wire type_lsu2wrb_ctrl_s           lsu2wrb_ctrl_i,

    // CSR <---> Writeback interface
    input wire type_csr2wrb_data_s           csr2wrb_data_i,

    // M-extension <---> Writeback interface
    input wire type_mul2wrb_s                mul2wrb_i,

    // Writeback <---> ID interface for feedback signals
    output type_wrb2id_fb_s                  wrb2id_fb_o,

    // Writeback <---> EXE interface for feedback signals
    output logic [`XLEN-1:0]                 wrb2exe_fb_rd_data_o,

    // Writeback <---> Forward_stall interface for forwarding
    output type_wrb2fwd_s                    wrb2fwd_o
);

// Local signals
type_lsu2wrb_data_s            lsu2wrb_data;
type_lsu2wrb_ctrl_s            lsu2wrb_ctrl;
type_csr2wrb_data_s            csr2wrb_data;
type_mul2wrb_s                 mul2wrb;

type_wrb2id_fb_s               wrb2id_fb;
logic [`XLEN-1:0]              wrb_rd_data;

// Assign appropriate values to the output signals
assign lsu2wrb_data = lsu2wrb_data_i;
assign lsu2wrb_ctrl = lsu2wrb_ctrl_i;
assign csr2wrb_data = csr2wrb_data_i;
assign mul2wrb      = mul2wrb_i;
 
// Writeback MUX for output signal selection
always_comb begin
     wrb_rd_data = '0;

      case (lsu2wrb_ctrl.rd_wrb_sel)
         RD_WRB_ALU    : begin
             wrb_rd_data = lsu2wrb_data.alu_result;
         end
         RD_WRB_INC_PC : begin
             wrb_rd_data = lsu2wrb_data.pc_next;
         end
         RD_WRB_DMEM   : begin
             wrb_rd_data = lsu2wrb_data.r_data;
         end
         RD_WRB_CSR    : begin
             wrb_rd_data = csr2wrb_data.csr_rdata;
         end
         RD_WRB_M_ALU  : begin
             wrb_rd_data = mul2wrb.alu_m_result;
         end
         default       : wrb_rd_data  = '0;              // default case 
     endcase
end

// Prepare the signals for output 
assign wrb2id_fb.rd_data   = wrb_rd_data; 
assign wrb2id_fb.rd_addr   = lsu2wrb_data.rd_addr; 
assign wrb2id_fb.rd_wr_req = lsu2wrb_ctrl.rd_wr_req;

// Update the module output signals
assign wrb2fwd_o.rd_addr    = lsu2wrb_data.rd_addr; 
assign wrb2fwd_o.rd_wr_req  = lsu2wrb_ctrl.rd_wr_req;
assign wrb2exe_fb_rd_data_o = wrb_rd_data;
assign wrb2id_fb_o          = wrb2id_fb;

endmodule : writeback


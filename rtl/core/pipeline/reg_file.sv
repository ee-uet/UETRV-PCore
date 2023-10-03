// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The register file with write operation on -ve clock edge.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../../defines/pcore_interface_defs.svh"
`else
`include "pcore_interface_defs.svh"
`endif

module reg_file (

    input   logic                      rst_n,               // reset
    input   logic                      clk,                 // clock

    // IDU <---> RF interface
    input   logic [`RF_AWIDTH-1:0]     id2rf_rs1_addr_i,    // rs1 read address
    input   logic [`RF_AWIDTH-1:0]     id2rf_rs2_addr_i,    // rs2 read address
    output  logic [`XLEN-1:0]          rf2id_rs1_data_o,    // rs1 read data
    output  logic [`XLEN-1:0]          rf2id_rs2_data_o,    // rs2 read data

    input   logic                      id2rf_rd_wr_req_i,   // write request
    input   logic [`RF_AWIDTH-1:0]     id2rf_rd_addr_i,     // rd write address
    input   logic [`XLEN-1:0]          id2rf_rd_data_i     // rd write data

 //   input wire type_debug_port_s       debug_port_i
);

// register file instantiation
logic   [`XLEN-1:0]          register_file[`RF_SIZE];

// local signals
logic                        rs1_addr_valid;
logic                        rs2_addr_valid;
logic                        rf_wr_valid;

// control signals for validity of register file read/write operations
assign  rs1_addr_valid   = |id2rf_rs1_addr_i;
assign  rs2_addr_valid   = |id2rf_rs2_addr_i;
assign  rf_wr_valid      = (|id2rf_rd_addr_i) & id2rf_rd_wr_req_i;

// asynchronous read operation for two register operands
assign  rf2id_rs1_data_o = (rs1_addr_valid) 
                         ? register_file[id2rf_rs1_addr_i] 
                         : '0;
assign  rf2id_rs2_data_o = (rs2_addr_valid) 
                         ? register_file[id2rf_rs2_addr_i] 
                         : '0;

// Write operation is performed on the negative edge
always_ff @( negedge clk) begin
    if (~rst_n) begin
        register_file <= '{default: '0};
    end else if (rf_wr_valid) begin
        register_file[id2rf_rd_addr_i] <= id2rf_rd_data_i;
    end

  //  if (debug_port_i.reg_wr_req) begin
  //      register_file[debug_port_i.reg_addr] <= debug_port_i.reg_data;
  //  end
end


endmodule : reg_file

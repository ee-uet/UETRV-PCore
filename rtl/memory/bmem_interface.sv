// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The boot memory and its interface with instruction/data bus. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022

`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module bmem_interface (

    input   logic                                   rst_n,                     // reset
    input   logic                                   clk,                       // clock

  // Instruction (boot) memory interface
    input  wire type_if2icache_s                    if2bmem_i,                 // Bus interface from IF  
    output type_icache2if_s                         bmem2if_o,                 // From boot memory to IF

  // DBus <---> Boot memory interface
    input   wire type_dbus2peri_s                   dbus2bmem_i,               // Boot memory input signals
    output  type_peri2dbus_s                        bmem2dbus_o,               // Boot memory output signals
    input logic                                     bmem_d_sel_i,
    input logic                                     bmem_iaddr_match_i
   
);


//================================= Ibus interface ==================================//
// Local signals
type_if2icache_s                      if2bmem;               
//type_icache2if_s                      bmem2if_ff, bmem2if_next;

type_dbus2peri_s                      dbus2bmem;
//type_peri2dbus_s                      bmem2dbus_ff, bmem2dbus_next;

logic [`XLEN-1:0]                     bmem_i_addr;
logic [`XLEN-1:0]                     bmem_d_addr;
logic [`XLEN-1:0]                     bmem_rd_addr;
logic [`XLEN-1:0]                     bmem_rdata;

logic                                 bmem_i_sel;
logic                                 bmem_d_sel;
logic                                 bmem_iaddr_match;
logic                                 bmem_req;

logic                                 bmem2if_ack_ff, bmem2if_ack_next;
logic                                 bmem2dbus_ack_ff, bmem2dbus_ack_next;


// Local signal assignments
assign if2bmem     = if2bmem_i;
assign bmem_i_addr = if2bmem.addr; 

assign dbus2bmem   = dbus2bmem_i;
assign bmem_d_addr = dbus2bmem.addr; 
assign bmem_iaddr_match = bmem_iaddr_match_i;

assign bmem_i_sel  = (if2bmem.req & bmem_iaddr_match); 
assign bmem_d_sel  = (dbus2bmem.req & bmem_d_sel_i);

assign bmem_rd_addr = bmem_d_sel ? bmem_d_addr 
                    : bmem_i_sel ? bmem_i_addr : '0; 

// Synchronous memory read operation for IF module interface
always_ff @ (negedge rst_n, posedge clk) begin 
    if (~rst_n) begin
        bmem2if_ack_ff    <= 1'b0;
        bmem2dbus_ack_ff  <= 1'b0;
    end else begin                         
        bmem2if_ack_ff    <= bmem2if_ack_next; 
        bmem2dbus_ack_ff  <= bmem2dbus_ack_next;
    end
end

always_comb begin 
    bmem2if_ack_next = '0;
    bmem2dbus_ack_next = '0;

    if (bmem_i_sel & ~bmem_d_sel) begin                         
        bmem2if_ack_next    = 1'b1; 
    end else if (bmem_d_sel) begin
        bmem2dbus_ack_next  = 1'b1;
    end
end

assign bmem2dbus_o.r_data = bmem_rdata; 
assign bmem2dbus_o.ack    = bmem2dbus_ack_ff; 

assign bmem2if_o.r_data   = bmem_rdata; 
assign bmem2if_o.ack      = bmem2if_ack_ff;

//================= Boot memory module and associated interfaces ==================//

assign bmem_req = bmem_i_sel | bmem_d_sel;

// Boot memory module instantiation 
bmem bmem_module (
     .rst_n                       (rst_n),
     .clk                         (clk),

     .if2bmem_addr_i              (bmem_rd_addr),
     .if2bmem_req_i               (bmem_req),
     .bmem2if_data_o              (bmem_rdata)
);   

endmodule : bmem_interface


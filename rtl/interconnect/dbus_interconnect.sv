// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The data bus address decoder for module level addressing. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../defines/pcore_interface_defs.svh"
`else
`include "pcore_interface_defs.svh"
`endif

module dbus_interconnect (

    input logic                                    rst_n,                    // reset
    input logic                                    clk,                      // clock

    // Core <----> dbus interface
    input wire type_lsu2dbus_s                     lsu2dbus_i,
    output type_dbus2lsu_s                         dbus2lsu_o,               // Signals to core
    input wire                                     dcache_flush_i,

    // dbus <----> Peripheral module interface
    input wire type_peri2dbus_s                    dcache2dbus_i,            // Signals from DATA memory 
    input wire type_peri2dbus_s                    uart2dbus_i,              // Signals from UART module
    input wire type_peri2dbus_s                    clint2dbus_i,             // Signals from CLINT module
    input wire type_peri2dbus_s                    plic2dbus_i,              // Signals from PLIC module
    input wire type_peri2dbus_s                    bmem2dbus_i,              // Signals from DATA memory 
    input wire type_peri2dbus_s                    spi2dbus_i,               // Signals from SPI module

    output logic                                   dmem_sel_o,               // DATA memory selection line
    output logic                                   uart_sel_o,               // UART selection line
    output logic                                   clint_sel_o,              // CLINT selection line
    output logic                                   plic_sel_o,               // PLIC selection line
    output logic                                   bmem_sel_o,               // Boot memory selection line
    output logic                                   spi_sel_o,                // SPI selection line

    output type_dbus2peri_s                        dbus2peri_o               // Signals from dbus to peripheral 
                                                                             // modules
);

// Local signals
type_lsu2dbus_s                       lsu2dbus;

type_dbus2peri_s                      dbus2peri;
logic [`DBUS_ADDR_WIDTH-1:0]          dbus_addr;
logic                                 ld_req;
logic                                 st_req;
logic                                 dbus_req;

logic                                 dmem_addr_match;
logic                                 uart_addr_match;
logic                                 clint_addr_match;
logic                                 plic_addr_match;
logic                                 bmem_addr_match;
logic                                 spi_addr_match;

logic                                 dmem_sel;
logic                                 uart_sel;
logic                                 clint_sel;
logic                                 plic_sel;
logic                                 bmem_sel;
logic                                 spi_sel;

// Assign input signals
assign lsu2dbus = lsu2dbus_i;
assign ld_req   = lsu2dbus.ld_req;
assign st_req   = lsu2dbus.st_req;

// Connect the local signals to appropriate IOs of the module
assign dbus_addr = lsu2dbus.addr[`DBUS_ADDR_WIDTH-1:0]; 
assign dbus_req  = st_req | ld_req; 

// Decode the device address
assign dmem_addr_match  = (dbus_addr[`DMEM_SEL_ADDR_HIGH:`DMEM_SEL_ADDR_LOW] == `DMEM_ADDR_MATCH);
assign bmem_addr_match  = (dbus_addr[`BMEM_SEL_ADDR_HIGH:`BMEM_SEL_ADDR_LOW] == `BMEM_ADDR_MATCH);

assign uart_addr_match  = (dbus_addr[`PERI_SEL_ADDR_HIGH:`PERI_SEL_ADDR_LOW] == `UART_ADDR_MATCH);
assign plic_addr_match  = (dbus_addr[`PERI_SEL_ADDR_HIGH:`PERI_SEL_ADDR_LOW] == `PLIC_ADDR_MATCH);
assign clint_addr_match = (dbus_addr[`PERI_SEL_ADDR_HIGH:`PERI_SEL_ADDR_LOW] == `CLINT_ADDR_MATCH);
assign spi_addr_match   = (dbus_addr[`PERI_SEL_ADDR_HIGH:`PERI_SEL_ADDR_LOW] == `SPI_ADDR_MATCH);

//=================================== Store operation =====================================//
// Prepare the write data and mask for store  
always_comb begin
   dbus2peri.w_data   = '0;
   dbus2peri.sel_byte = '0;

   case (lsu2dbus.st_ops)
      ST_OPS_SB : begin
         case (dbus_addr[1:0]) 
            2'b00 : begin 
               dbus2peri.w_data[7:0]   = lsu2dbus.w_data[7:0]; 
               dbus2peri.sel_byte = 4'b0001;
            end 
            2'b01 : begin
               dbus2peri.w_data[15:8]  = lsu2dbus.w_data[7:0];
               dbus2peri.sel_byte = 4'b0010;
            end
            2'b10 : begin
               dbus2peri.w_data[23:16] = lsu2dbus.w_data[7:0];
               dbus2peri.sel_byte = 4'b0100;
            end
            2'b11 : begin
               dbus2peri.w_data[31:24] = lsu2dbus.w_data[7:0];
               dbus2peri.sel_byte = 4'b1000;
            end
            default : begin    
            end  
         endcase
      end // ST_OPS_SB   
      ST_OPS_SH : begin 
         case (dbus_addr[1]) 
            1'b0 : begin
               dbus2peri.w_data[15:0]  = lsu2dbus.w_data[15:0];
               dbus2peri.sel_byte = 4'b0011;
            end 
            1'b1 : begin
               dbus2peri.w_data[31:16]  = lsu2dbus.w_data[15:0];
               dbus2peri.sel_byte = 4'b1100;
            end
            default : begin    
            end  
         endcase
      end // ST_OPS_SH
      ST_OPS_SW : begin
         dbus2peri.w_data = lsu2dbus.w_data;
         dbus2peri.sel_byte = 4'b1111;
      end
      default : begin
         dbus2peri.w_data = '0;
         dbus2peri.sel_byte = 4'b0000;
      end
   endcase // st_ops
end

// Address decoder for peripheral module selection
always_comb begin
    dmem_sel  = 1'b0;
    clint_sel = 1'b0;
    plic_sel  = 1'b0;
    uart_sel  = 1'b0;
    bmem_sel  = 1'b0;
    spi_sel   = 1'b0;
    
    if ((dmem_addr_match & dbus_req) | dcache_flush_i) begin
        dmem_sel  = 1'b1;
    end else if (clint_addr_match & dbus_req) begin
        clint_sel = 1'b1;
    end else if (plic_addr_match & dbus_req) begin
        plic_sel = 1'b1;
    end else if (uart_addr_match & dbus_req) begin
        uart_sel  = 1'b1;
    end else if (spi_addr_match & dbus_req) begin
        spi_sel  = 1'b1;
    end else if (bmem_addr_match & dbus_req) begin
        bmem_sel  = 1'b1;
    end
end

// Output signal assignemnets
assign dbus2peri.addr = dbus_addr;
assign dbus2peri.req  = dbus_req;
assign dbus2peri.w_en = st_req;

// Assign the output signals
assign dbus2peri_o = dbus2peri;

// Peripheral module selection signals from address decoder 
assign dmem_sel_o  = dmem_sel;
assign uart_sel_o  = uart_sel;
assign clint_sel_o = clint_sel;
assign plic_sel_o  = plic_sel;
assign bmem_sel_o  = bmem_sel;
assign spi_sel_o   = spi_sel;

// Mux for the peripheral module read data
assign dbus2lsu_o = dmem_sel  ? type_dbus2lsu_s'(dcache2dbus_i) 
                  : clint_sel ? type_dbus2lsu_s'(clint2dbus_i)
                  : plic_sel  ? type_dbus2lsu_s'(plic2dbus_i)
                  : uart_sel  ? type_dbus2lsu_s'(uart2dbus_i)  
                  : spi_sel   ? type_dbus2lsu_s'(spi2dbus_i)
                  : bmem_sel  ? type_dbus2lsu_s'(bmem2dbus_i)  
                  : '0;

endmodule : dbus_interconnect


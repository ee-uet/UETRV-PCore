// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: SPI datapath with configurable clock rate. 
//
// Author: Shehzeen Malik, UET Lahore
// Date: 11.4.2023


`timescale 1ns / 1ps
 
`ifndef VERILATOR
`include "../../defines/spi_defs.svh"
`else
`include "spi_defs.svh"
`endif

module spi_datapath (
    input logic                                rst_n,                    // reset
    input logic                                clk,                      // clock
     
     // MOSI MISO signals of SPI 
     input logic                               miso_r,
     output logic                              mosi_r,

     // Signals from controller
     input logic                               spi_clk_i,
     input logic [11:0]                        clock_cnt,
     input logic [2:0]                         state_ff_i, 
     input logic [2:0]                         state_next_i,

     // Tx fifo
     input     logic                           tx_fifo_read,
     input     logic                           rx_fifo_write,
     output    logic                           tx_fifo_empty,

     // Signals to/from registers 
     input     logic                           spi_shift_direct,
     input     logic [2:0]                     tx_water_mark,
     input     logic [2:0]                     rx_water_mark,
     output    logic                           rx_fifo_mark,
     output    logic                           tx_fifo_mark,
     input logic                               spi_clk_phase,
     input logic [11:0]                        spi_clk_period,

     // Rx fifo
     input     logic                           rx_fifo_read,
     input     logic                           rx_fifo_enable,
     input     logic                           tx_fifo_write,
     input     logic [7:0]                     tx_fifo_data,
     output    logic                           tx_fifo_full,
     output    logic                           rx_fifo_empty,
     output    logic [7:0]                     rx_fifo_data
);
    
// Register definitions
logic [7:0]                               rx_shift_data, tx_shift_data;

// Fifo signals
logic [ADDR_FIFO:0]                       tx_fifo_count;
logic [ADDR_FIFO:0]                       rx_fifo_count;
logic [7:0]                               reg_tx_data;

logic                                     spi_clk;

type_spi_states_e                         state_ff, state_next;

// Signal assignments
assign spi_clk = spi_clk_i;
assign state_ff = type_spi_states_e'(state_ff_i);
assign state_next = type_spi_states_e'(state_next_i);

// ----------------------------
// Receive data from miso in shift register 
// ----------------------------
always @ (posedge clk) begin
    if(~rst_n)
        rx_shift_data <= 'h0;
    else if ((clock_cnt == spi_clk_period) && (spi_clk_phase == spi_clk) && (state_ff == SPI_ST_TRANS)) begin
        if (spi_shift_direct)
            rx_shift_data <= {miso_r, rx_shift_data[7:1]};
        else
            rx_shift_data <= {rx_shift_data[6:0], miso_r};
    end
end

// -----------------------
// Transmit data from mosi 
// -----------------------
always @(posedge clk) begin
    if (~rst_n) begin
        mosi_r        <= 1'b0;
        tx_shift_data <= 'b0; 
    end else if ((state_ff == SPI_ST_WAIT) && (state_next == SPI_ST_TRANS)) begin
            if (spi_shift_direct) begin
                mosi_r        <= reg_tx_data[0];
                tx_shift_data <= {1'b0, reg_tx_data[7:1]};
            end else begin
                mosi_r        <= reg_tx_data[7];
                tx_shift_data <= {reg_tx_data[6:0], 1'b0};
            end
    end else if ((state_ff == SPI_ST_TRANS) && (clock_cnt == spi_clk_period) && (spi_clk_phase ^ spi_clk) ) begin
        if (spi_shift_direct) begin
                mosi_r        <= tx_shift_data[0];
                tx_shift_data <= {1'b0, tx_shift_data[7:1]};
        end else begin
                mosi_r        <= tx_shift_data[7];
                tx_shift_data <= {tx_shift_data[6:0], 1'b0};
        end
    end
end

// Tx watermark check
always_comb begin
    if (tx_fifo_count[2:0] < tx_water_mark)
        tx_fifo_mark = 1'b1;
    else if (tx_fifo_count[2:0] > tx_water_mark)
        tx_fifo_mark = 1'b0;
    else
        tx_fifo_mark = 1'b0;
end

// Rx watermark check
always_comb begin
    if (rx_fifo_count[2:0] > rx_water_mark)
        rx_fifo_mark = 1'b1;
    else if (rx_fifo_count[2:0] < rx_water_mark)
        rx_fifo_mark = 1'b0;
    else
        rx_fifo_mark = 1'b0;
end

spi_fifo tx_fifo(
    .clk (clk),
    .rst_n (rst_n),
    .data_in (tx_fifo_data),
    .data_out (reg_tx_data),
    .data_count (tx_fifo_count),
    .fifo_en (1'b1),
    .fifo_read (tx_fifo_read),
    .fifo_write (tx_fifo_write),
    .fifo_full (tx_fifo_full),
    .fifo_empty (tx_fifo_empty)
);

spi_fifo rx_fifo(
    .clk                          (clk),
    .rst_n                        (rst_n),
    .data_in                      (rx_shift_data),
    .data_out                     (rx_fifo_data),
    .data_count                   (rx_fifo_count),
    .fifo_en                      (rx_fifo_enable),
    .fifo_read                    (rx_fifo_read),
    .fifo_write                   (rx_fifo_write),
    .fifo_full                    (),
    .fifo_empty                   (rx_fifo_empty)
);

endmodule

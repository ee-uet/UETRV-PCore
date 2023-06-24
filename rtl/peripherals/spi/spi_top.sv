// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: SPI top module with configurable clock rate. 
//
// Author: Shehzeen Malik, UET Lahore
// Date: 11.4.2023


`timescale 1ns / 1ps

`ifndef VERILATOR
`include "../../defines/spi_defs.svh"
`else
`include "spi_defs.svh"
`endif


module spi_top (
    input logic                                    rst_n,                  // reset
    input logic                                    clk,                    // clock

     // Dbus to SPI module interface
    input wire type_dbus2peri_s                    dbus2spi_i,              // SPI dbus input signals
    output type_peri2dbus_s                        spi2dbus_o,              // SPI dbus output signals

    // Selection signal from address decoder of dbus interconnect 
     input   logic                                 spi_sel_i,
     
    // Interrupt signal from SPI
    output logic                                   spi_irq_o,
     
    // SPI bus interface signals including clock, chip_select, MOSI and MISO  
    output logic                                   spi_clk_o,
    output logic                                   spi_cs_o,
    input logic                                    spi_miso_i,
    output logic                                   spi_mosi_o

);
    
// Local signals 
logic [1:0]                         spi_reg_cs_default;
logic [1:0]                         spi_reg_cs_id;
logic [11:0]                        spi_clk_period;
logic                               spi_clk_phase   ;
logic                               spi_clk_polarity;
logic [1:0]                         spi_cs_mode     ;
logic [7:0]                         spi_c2t_time        ;
logic [7:0]                         spi_t2c_time        ;
logic [7:0]                         spi_inter_cs_time   ;
logic [7:0]                         spi_inter_fr_time;
logic [3:0]                         spi_data_size   ;
logic                               spi_busy;
logic                               spi_tx_fifo_empty;
logic                               spi_mosi_fst_transmit;
logic                               spi_mosi_en;
logic                               spi_miso_en;
logic                               spi_tx_fifo_read;
logic                               spi_rx_fifo_write;
logic                               spi_tx_fifo_full;
logic                               spi_rx_fifo_empty;
logic [7:0]                         spi_rx_fifo_data;
logic [7:0]                         spi_tx_fifo_data;
logic                               spi_rx_fifo_enable;
logic                               spi_rx_fifo_read;
logic                               spi_tx_fifo_write;
logic                               spi_rx_fifo_mark;
logic                               spi_tx_fifo_mark;
logic [2:0]                         spi_tx_water_mark;
logic [2:0]                         spi_rx_water_mark;
logic                               spi_shift_direct;

logic [11:0]                        clock_cnt;
logic [2:0]                         state_ff; 
logic [2:0]                         state_next;

//============================= SPI Controller interface ============================//
spi_controller spi_controller_module(
    .rst_n               (rst_n),
    .clk                 (clk),
    .spi_sel_i           (spi_sel_i),
    .spi_cs_o            (spi_cs_o),

    .reg_cs_default_ff   (spi_reg_cs_default),
    .reg_cs_id_ff        (spi_reg_cs_id),
     .spi_clk_period     (spi_clk_period),
     .spi_clk_phase     (spi_clk_phase),
     .spi_clk_polarity  (spi_clk_polarity),
     .spi_cs_mode       (spi_cs_mode),
     .c2t_time          (spi_c2t_time),
     .t2c_time          (spi_t2c_time),
     .inter_cs_time     (spi_inter_cs_time),
     .inter_frame_time  (spi_inter_fr_time),
     .spi_data_size     (spi_data_size),
     .spi_busy          (spi_busy),

     .tx_fifo_empty     (spi_tx_fifo_empty),
     .tx_fifo_read      (spi_tx_fifo_read),
     .rx_fifo_write     (spi_rx_fifo_write),
     .spi_clk_o         (spi_clk_o),
     .clock_cnt_o            (clock_cnt),
     .state_ff_o             (state_ff), 
     .state_next_o           (state_next)
    );
    
//============================ SPI Datapath interface ===============================//
spi_datapath spi_datapath_module(
    .rst_n                   (rst_n),
    .clk                     (clk),

    .miso_r                  (spi_miso_i),
    .mosi_r                  (spi_mosi_o),
    .spi_clk_i               (spi_clk_o),

    .clock_cnt               (clock_cnt),
    .state_ff_i              (state_ff), 
    .state_next_i            (state_next),
    .spi_clk_period          (spi_clk_period),
    .spi_clk_phase           (spi_clk_phase),

    .tx_fifo_read (spi_tx_fifo_read),
    .rx_fifo_write (spi_rx_fifo_write),
    .tx_fifo_empty (spi_tx_fifo_empty),
    .spi_shift_direct (spi_shift_direct),
    .tx_water_mark (spi_tx_water_mark),
    .rx_water_mark (spi_rx_water_mark),
    .rx_fifo_mark (spi_rx_fifo_mark),
    .tx_fifo_mark (spi_tx_fifo_mark),
    .rx_fifo_read (spi_rx_fifo_read),
    .rx_fifo_enable (spi_rx_fifo_enable),
    .tx_fifo_write (spi_tx_fifo_write),
    .tx_fifo_data (spi_tx_fifo_data),
    .tx_fifo_full (spi_tx_fifo_full),
    .rx_fifo_empty (spi_rx_fifo_empty),
    .rx_fifo_data (spi_rx_fifo_data)
);

    //=========================== SPI Registers Update interface ========================//
spi_regs spi_regs_module (
    .rst_n (rst_n),
    .clk (clk),

    // Data bus interface signals
    .dbus2spi_i             (dbus2spi_i),
    .spi2dbus_o             (spi2dbus_o),
    .spi_sel_i              (spi_sel_i),
    
    // IRQ request signal 
    .spi_irq_o              (spi_irq_o),

     // SPI control signals
    .spi_busy               (spi_busy),
    .spi_clk_period         (spi_clk_period),
    .spi_clk_phase          (spi_clk_phase),
    .spi_clk_polarity       (spi_clk_polarity),
    .reg_cs_mode_ff         (spi_cs_mode),
    .c2t_time               (spi_c2t_time),
    .t2c_time               (spi_t2c_time),
    .inter_cs_time          (spi_inter_cs_time),
    .inter_frame_time       (spi_inter_fr_time),
    .spi_data_size          (spi_data_size),
    .reg_cs_default_ff      (spi_reg_cs_default),
    .reg_cs_id_ff           (spi_reg_cs_id),
    .tx_fifo_full           (spi_tx_fifo_full),
    .rx_fifo_empty          (spi_rx_fifo_empty),
    .rx_fifo_data           (spi_rx_fifo_data),
    .reg_tx_data_ff         (spi_tx_fifo_data),
    .rx_fifo_enable         (spi_rx_fifo_enable),
    .rx_fifo_read           (spi_rx_fifo_read),
    .tx_fifo_write          (spi_tx_fifo_write),
    .rx_fifo_mark           (spi_rx_fifo_mark),
    .tx_fifo_mark           (spi_tx_fifo_mark),
    .tx_water_mark          (spi_tx_water_mark),
    .rx_water_mark          (spi_rx_water_mark),
    .spi_shift_direct       (spi_shift_direct)
);
    

endmodule

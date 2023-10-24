// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Shehzeen Malik, UET Lahore
// Date: 11.4.2023


`ifndef SPI_DEFS
`define SPI_DEFS

`include "pcore_interface_defs.svh"

localparam int unsigned DEPTH_FIFO = 8;
localparam int unsigned ADDR_FIFO  = $clog2 (DEPTH_FIFO);
//localparam SPI_SCLK = CLK_I / (2 * (CLOCK_SEL + 1));

// SPI register definitions
typedef enum logic [7:0] {
    SPI_SCK_DIV_R  = 8'h00, // Serial clock divisor
    SPI_SCK_MODE_R = 8'h04, // Serial clock mode
    SPI_CS_ID_R    = 8'h10, // Chip select ID
    SPI_CS_DEF_R   = 8'h14, // Chip select default
    SPI_CS_MODE_R  = 8'h18, // Chip select mode
    SPI_DELAY_0_R  = 8'h28, // Delay control 0
    SPI_DELAY_1_R  = 8'h2C, // Delay control 1
    SPI_FMT_R      = 8'h40, // Frame format
    SPI_TXDATA_R   = 8'h48, // Tx FIFO data
    SPI_RXDATA_R   = 8'h4C, // Rx FIFO data
    SPI_TX_MARK_R  = 8'h50, // Tx FIFO watermark
    SPI_RX_MARK_R  = 8'h54, // Rx FIFO watermark
    SPI_FCTRL_R    = 8'h60, // SPI flash interface control
    SPI_FFMT_R     = 8'h64, // SPI flash instruction format
    SPI_IE_R       = 8'h70, // SPI interrupt enable
    SPI_IP_R       = 8'h74  // SPI interrupt pending
} type_spi_regs_e;

typedef enum logic [2:0] {
    SPI_ST_IDLE       = 3'h0,
    SPI_ST_LOAD_DATA  = 3'h1,
    SPI_ST_WAIT       = 3'h2,
    SPI_ST_TRANS      = 3'h3,
    SPI_ST_TURNAROUND = 3'h4,
    SPI_ST_INTERVAL   = 3'h5
} type_spi_states_e;

`endif // SPI_DEFS

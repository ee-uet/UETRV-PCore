// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: UART receiver module. 
//
// Author: Shehzeen Malik, UET Lahore
// Date: 13.7.2022

`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../../defines/uart_defs.svh"
`else
`include "uart_defs.svh"
`endif

module uart_rx (

    input logic                                     rst_n,                    // reset
    input logic                                     clk,                      // clock

    input logic                                     rx_pin_in,
    input wire [UART_BAUD_DIV_SIZE-1:0]	            baud_div_i,

    output logic [`UART_DATA_SIZE-1:0]               rx_data_o,
    output logic                                    valid_o,
    output logic                                    frame_err_o
);

// Bit counter and signal definitions 
logic [UART_DATA_BIT_COUNT:0]           bit_count_ff, bit_count_next;
logic                                   rx_busy;
logic                                   sample_pulse;
logic                                   sbit_mid_point;
logic                                   rx_pin_ff;

// Use baud divisor to divide the clock and generate pulses as bit sampling points
logic [UART_BAUD_DIV_SIZE-1:0]          sample_count_ff, sample_count_next;
logic [UART_BAUD_DIV_SIZE-1:0]          sbit_sample_count_ff, sbit_sample_count_next;

// Shift register for collecting the incoming bits, acts as a serial to parallel converter
logic [`UART_DATA_SIZE-1:0]              shifter_ff, shifter_next;
logic                                   valid_ff, valid_next;
logic                                   frame_err_ff, frame_err_next;

// Signals for UART state machine
type_uart_rx_states_e state_ff, state_next;

// Signal assignments	
assign sample_pulse = (sample_count_ff == 1);
assign rx_busy      = (bit_count_ff != 0);

// Creating the mid point of the start bit and also achieving debouncing
assign sbit_mid_point = (sbit_sample_count_ff == {1'b0, baud_div_i[UART_BAUD_DIV_SIZE-1:1]});


always_ff @(negedge clk) begin
    if (~rst_n) begin
        rx_pin_ff <= 1'b1;
    end else begin
        rx_pin_ff <= rx_pin_in;
    end
end

// State register update
always_ff @(posedge clk) begin
    if (~rst_n) begin
        state_ff             <= UART_RX_IDLE;
        sample_count_ff      <= '0;
        sbit_sample_count_ff <= '0;
	bit_count_ff         <= '0;
        shifter_ff           <= '0;
	valid_ff             <= 1'b0;
        frame_err_ff         <= 1'b0; 
    end else begin
        state_ff             <= state_next;
        sample_count_ff      <= sample_count_next;
        sbit_sample_count_ff <= sbit_sample_count_next;
	bit_count_ff         <= bit_count_next;
        shifter_ff           <= shifter_next;
	valid_ff             <= valid_next;
        frame_err_ff         <= frame_err_next;      
    end
end

// Next state and output evaluations
always_comb begin
    sample_count_next      = baud_div_i;
    bit_count_next         = bit_count_ff;
    shifter_next           = shifter_ff; 
    state_next             = state_ff;
    sbit_sample_count_next = sbit_sample_count_ff;
    valid_next             = valid_ff;
    frame_err_next         = frame_err_ff;

    case (state_ff)
        UART_RX_IDLE  : begin
            sbit_sample_count_next = '0;
            valid_next             = 1'b0;
            frame_err_next         = 1'b0;
            state_next             = UART_RX_IDLE;

            if (!rx_pin_ff) begin 
                state_next = UART_RX_START;
            end
	end
	
        UART_RX_START : begin
            sbit_sample_count_next = sbit_sample_count_ff + 1;

            if (sbit_mid_point) begin
                bit_count_next    = `UART_DATA_SIZE;          
                state_next        = UART_RX_DATA;
                sample_count_next = baud_div_i; 
                sbit_sample_count_next = '0;                 
            end               
        end
	
	UART_RX_DATA : begin   		
            if (sample_pulse) begin                
                sample_count_next = baud_div_i;

                // If we are done with receving the data byte, resent and go to the idle state
                if (rx_busy) begin				
                    shifter_next   = {rx_pin_ff, shifter_ff[`UART_DATA_SIZE-1:1]};
                    bit_count_next = bit_count_ff - 1;
                end else begin              
                    state_next     = UART_RX_STOP;
                end
            end else begin
                sample_count_next = (sample_count_ff - 1);
            end               
        end

        UART_RX_STOP : begin   		
            if (sample_pulse) begin
                state_next = UART_RX_IDLE;
                if (rx_pin_ff) begin                
                    valid_next     = 1'b1;                    
                end else begin
                    frame_err_next = 1'b1;
                end                
            end else begin
                sample_count_next = (sample_count_ff - 1);
            end               
        end
        
    endcase
end

// Output signals update
assign valid_o     = valid_ff;
assign rx_data_o   = shifter_ff;
assign frame_err_o = frame_err_ff;


endmodule

// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: SPI controller with configurable clock rate. 
//
// Author: Shehzeen Malik, UET Lahore
// Date: 11.4.2023


`timescale 1 ns / 100 ps
 
`ifndef VERILATOR
`include "../../defines/spi_defs.svh"
`else
`include "spi_defs.svh"
`endif

module spi_controller (
     input logic                               rst_n,                    // reset
     input logic                               clk,                      // clock
     input logic                               spi_sel_i,
     //slave select
     output logic                              spi_cs_o,

     //signals from and to reg update
     input logic [1:0]                         reg_cs_default_ff,
     input logic [1:0]                         reg_cs_id_ff,
     input logic [11:0]                        spi_clk_period,
     input logic                               spi_clk_phase   ,
     input logic                               spi_clk_polarity,
     input logic [1:0]                         spi_cs_mode     ,
     input logic [7:0]                         c2t_time        ,
     input logic [7:0]                         t2c_time        ,
     input logic [7:0]                         inter_cs_time   ,
     input logic [7:0]                         inter_frame_time,
     input logic [3:0]                         spi_data_size   ,
     output logic                              spi_busy,
     
     //signals to datapath
     input logic                               tx_fifo_empty,
     output logic                              tx_fifo_read,
     output logic                              rx_fifo_write,
     output logic                              spi_clk_o,
     output logic [11:0]                       clock_cnt_o,
     output logic [2:0]                        state_ff_o, 
     output logic [2:0]                        state_next_o

);
    
logic [7:0]                               c2t_delay,t2c_delay;
logic [7:0]                               count_intercs, count_interfr;
logic [3:0]                               data_cnt;
logic [11:0]                              clock_cnt;
logic [1:0]                               count_up;
logic [3:0]                               max_data_count;
logic                                     spi_clk;
logic                                     spi_clk_edge;
logic [1:0]                               spi_slave_sel;

// Signals for SPI state machine
type_spi_states_e                         state_ff, state_next;

assign max_data_count = spi_clk_phase ? (spi_data_size - 1) : (spi_data_size);

/*================================= State Machine ========================== */

// Current State register synchronous update
always_ff @(posedge clk) begin
    if (~rst_n)
        state_ff <= SPI_ST_IDLE;
    else
        state_ff <= state_next;
end

// Next_state always block
always_comb begin
    state_next = SPI_ST_IDLE;
 
    case (state_ff)
        SPI_ST_IDLE : begin 
            if((count_intercs == inter_cs_time)  && !tx_fifo_empty) 
                state_next = SPI_ST_LOAD_DATA;
             else 
                state_next = SPI_ST_IDLE; 
        end
        SPI_ST_LOAD_DATA : begin 
                state_next = SPI_ST_WAIT;
        end
        SPI_ST_WAIT : begin 
            if(c2t_delay == c2t_time) 
                state_next = SPI_ST_TRANS;
            else 
                state_next = SPI_ST_WAIT;
        end
        SPI_ST_TRANS : begin 
            if (spi_clk_phase == 0) begin
                if (data_cnt == max_data_count) begin
                    if ((spi_cs_mode == 2'b00) || ((spi_cs_mode != 2'b00) && tx_fifo_empty))
                         state_next = SPI_ST_INTERVAL;
                    else if (!tx_fifo_empty && ((spi_cs_mode == 2'b10) || (spi_cs_mode == 2'b11)))
                         state_next = SPI_ST_TURNAROUND;
                end else
                    state_next = SPI_ST_TRANS;
            end else if (spi_clk_phase == 1) begin
                if((data_cnt == max_data_count) && (spi_clk == spi_clk_polarity)) begin 
                    if (clock_cnt == spi_clk_period) begin
                        if ((spi_cs_mode == 2'b00) || ((spi_cs_mode != 2'b00) && tx_fifo_empty))
                            state_next = SPI_ST_INTERVAL;
                        else if (!tx_fifo_empty && ((spi_cs_mode == 2'b10) || (spi_cs_mode == 2'b11)))
                            state_next = SPI_ST_TURNAROUND;
                    end
                end else begin
                    state_next = SPI_ST_TRANS;
                end
            end                        
        end
        SPI_ST_TURNAROUND : begin 
            if(count_interfr == inter_frame_time)
                 state_next = SPI_ST_TRANS;
            else 
                 state_next = SPI_ST_TURNAROUND;
        end
        SPI_ST_INTERVAL   : begin 
            if(t2c_delay == t2c_time)
                state_next = SPI_ST_IDLE;
            else 
                state_next = SPI_ST_INTERVAL;
        end
        default : begin 
            state_next = SPI_ST_IDLE;
        end
    endcase
end
    
// Clock count
always_ff @(posedge clk) begin
    if (~rst_n)
       clock_cnt <= '0;
    else begin
       if (clock_cnt < spi_clk_period)
           clock_cnt <= clock_cnt + 'b01;
       else if ((state_ff != state_next) || (clock_cnt == spi_clk_period))
           clock_cnt <= '0;
    end
end

// Count for one period of clock cycle for delay0,1 regs times
always_ff @(posedge clk) begin
    if (~rst_n ) 
       count_up  <= 2'b00;
    else begin
       if (clock_cnt == spi_clk_period)
           count_up  <= count_up  + 2'b01;
       else if ((state_ff != state_next) || (count_up == 2'b10))
           count_up  <= 2'b00;
    end
end

// Counter for minimum time between deassertion and assertion
always_ff @(posedge clk) begin
    if(~rst_n)
        count_intercs <= '0;
    else begin
        if ((state_ff == SPI_ST_IDLE) && (count_intercs < inter_cs_time)) begin
            if (count_up == 2'b10)
                count_intercs <= count_intercs + 8'h01;
        end else
            count_intercs <= '0;
    end    
end

// Counter for delay between two frames without deassertion
always_ff @(posedge clk) begin
    if(~rst_n)
        count_interfr <= '0;
    else begin
        if ((state_ff == SPI_ST_TURNAROUND) && (count_interfr < inter_frame_time)) begin
            if (count_up == 2'b10)  
                count_interfr <= count_interfr + 8'h01;
        end else
            count_interfr <= '0;
    end    
end

// Counter for ss=0 to transmission and transmission to ss=1
always_ff @(posedge clk) begin
    if(~rst_n) begin
        c2t_delay <= '0;
        t2c_delay <= '0;
    end else begin
        if ((state_ff == SPI_ST_WAIT) && (c2t_delay < c2t_time)) begin
            if (count_up == 2'b10)
                c2t_delay <= c2t_delay + 1; 
        end else
            c2t_delay <= '0;

        if ((state_ff == SPI_ST_INTERVAL) && (t2c_delay < t2c_time)) begin
            if (count_up == 2'b10)
                t2c_delay <= t2c_delay + 1;
        end else
            t2c_delay <= '0;
    end
end    


assign spi_clk_edge = ((state_ff == SPI_ST_TRANS) && (clock_cnt == spi_clk_period));
// Generate SCLK
always_ff @(posedge clk) begin
    if (~rst_n || (state_ff != SPI_ST_TRANS))
       spi_clk <= spi_clk_polarity;
    else begin
       if (spi_clk_edge)
           spi_clk <= ~spi_clk;
    end
end


// Counter for number of bits transmitted
always_ff @(posedge clk) begin
    if(~rst_n) begin
        data_cnt <= '0;
    end else begin
        if (spi_clk_edge) begin
            if (spi_clk_phase == 0) begin
                if (spi_clk == spi_clk_polarity && data_cnt <= spi_data_size)
                    data_cnt <= data_cnt + 1; 
            end
            if (spi_clk_phase == 1) begin
                if (spi_clk != spi_clk_polarity && data_cnt <= spi_data_size)
                    data_cnt <= data_cnt + 1; 
            end
        end else begin
            data_cnt <= 0;
        end
    end
end

// Enable for loading changed configurations so that current transmission does not get affected
always_comb begin
    if ((state_ff == SPI_ST_IDLE) || (state_ff == SPI_ST_TURNAROUND))
        spi_busy = 1'b0;
    else
        spi_busy = 1'b1;
end
    
// Slave select update
always_ff @(posedge clk) begin
    if (~rst_n || (state_ff == SPI_ST_IDLE))
        spi_slave_sel <= reg_cs_default_ff;
    else
        spi_slave_sel <= (reg_cs_default_ff ^ reg_cs_id_ff);
end

// Rx fifo write control
always_comb begin
    rx_fifo_write = 1'b0;

    if (state_ff == SPI_ST_TRANS) begin
        if (spi_clk_phase == 0) begin
            if (data_cnt == max_data_count)
                rx_fifo_write = 1'b1;
        end else if (spi_clk_phase == 1) begin
            if((data_cnt == max_data_count) && (spi_clk == spi_clk_polarity)) begin 
                if (clock_cnt == spi_clk_period)
                    rx_fifo_write = 1'b1;
            end
        end else
           rx_fifo_write = 1'b0;
    end else
       rx_fifo_write = 1'b0;
end

// Tx fifo read control
always_comb begin
    if ((state_ff == SPI_ST_LOAD_DATA) ||
        ((state_ff == SPI_ST_TURNAROUND) && (count_interfr == 8'h00)))
        tx_fifo_read = 1'b1;
    else
        tx_fifo_read = 1'b0;
end

// Update the signal outputs
assign spi_clk_o    = spi_clk;
assign clock_cnt_o  = clock_cnt;
assign state_ff_o   = state_ff;
assign state_next_o = state_next;
assign spi_cs_o     = spi_slave_sel[0];


endmodule

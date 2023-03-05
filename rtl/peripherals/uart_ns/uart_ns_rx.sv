/*********************************************************************
 * Filename :    uart_rx.scala
 * Date     :    20-03-2021
 * Author   :    Muhammad Tahir
 *
 * Description:  Uart receiver module.
 *********************************************************************/
`ifndef VERILATOR
`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/UART_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "UART_defs.svh"
`endif

module uart_ns_rx (

    input logic                                     rst_n,                    // reset
    input logic                                     clk,                      // clock

    input logic                                     rx_pin_in,
    input wire [UART_DATA_SIZE-1:0]	            baud_div_i,

    output logic [UART_DATA_SIZE-1:0]               rx_data_o,
    output logic                                    valid_o,
    output logic                                    frame_err_o
);

// Bit counter and signal definitions 
logic [UART_DATA_BIT_COUNT:0]           bit_count_ff, bit_count_next;
logic                                   rx_busy;
logic                                   sample_pulse;
logic                                   sbit_mid_point;

// Use baud divisor to divide the clock and generate pulses as bit sampling points
logic [UART_DATA_SIZE-1:0]          sample_count_ff, sample_count_next;
logic [UART_DATA_SIZE-1:0]          sbit_sample_count_ff, sbit_sample_count_next;

// Shift register for collecting the incoming bits, acts as a serial to parallel converter
logic [UART_DATA_SIZE-1:0]              shifter_ff, shifter_next;
logic                                   valid_ff, valid_next;
logic                                   frame_err_ff, frame_err_next;

// Signals for UART state machine
type_uart_rx_states_e state, state_next;

// Signal assignments	
assign sample_pulse = (sample_count_ff == 0);
assign rx_busy      = (bit_count_ff != 0);

// Creating the mid point of the start bit and also achieving debouncing
assign sbit_mid_point = (sbit_sample_count_ff == baud_div_i[UART_BAUD_DIV_SIZE-1:1]);

// State register update
always_ff @ (posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        state                <= UART_RX_IDLE;
        sample_count_ff      <= '0;
        sbit_sample_count_ff <= '0;
	bit_count_ff         <= '0;
        shifter_ff           <= '0;
	valid_ff             <= 1'b0;
        frame_err_ff         <= 1'b0; 
    end else begin
        state                <= state_next;
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

    case (state)
        UART_RX_IDLE  : begin
            sbit_sample_count_next = '0;
            sample_count_next      = '0;
            shifter_next           = '0;
            bit_count_next         = '0;
            valid_next             = 1'b0;
            frame_err_next         = 1'b0;
            state_next             = UART_RX_IDLE;

            if (!rx_pin_in) begin 
                state_next = UART_RX_START;
            end
	end
	
        UART_RX_START : begin
            sbit_sample_count_next = sbit_sample_count_ff + 1;

            if (sbit_mid_point) begin
                bit_count_next    = UART_DATA_SIZE;          
                state_next        = UART_RX_DATA;
                sample_count_next = (baud_div_i - 1);                
            end               
        end
	
	UART_RX_DATA : begin   		
            if (sample_pulse) begin
                
                sample_count_next = baud_div_i - 1;

                // If we are done with receving the data byte, resent and go to the idle state
                if (rx_busy) begin				
                    shifter_next   = {rx_pin_in, shifter_ff[UART_DATA_SIZE-1:1]};
                    bit_count_next = bit_count_ff - 1;
                end else begin
                    sbit_sample_count_next = '0;                
                    state_next             = UART_RX_STOP;
                end
            end else begin
                sample_count_next = (sample_count_ff - 1);
            end               
        end

        UART_RX_STOP : begin   		
            if (sample_pulse) begin
                state_next = UART_RX_IDLE;
                if (rx_pin_in) begin                
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


endmodule : uart_ns_rx
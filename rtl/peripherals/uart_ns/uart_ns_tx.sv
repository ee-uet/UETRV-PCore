/*********************************************************************
 * Filename :    uart_tx.scala
 * Date     :    21-01-2022
 * Author   :    
 * Adopted from uart.scala by Dr. Muhammad Tahir
 *
 * Description:  Uart transmit module.
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
 
module uart_ns_tx (

    input logic                             rst_n,                    // reset
    input logic                             clk,                      // clock

    input logic [UART_DATA_SIZE-1:0]        tx_data_i,
    input logic [UART_DATA_SIZE-1:0]        baud_div_i,
    input logic                             two_stop_bits,
    input logic                             valid_i,

    output logic                            ready_o,	
    output logic                            tx_pin_o
);


logic [UART_DATA_SIZE-1:0]              sample_count_ff, sample_count_next = 'b0;
logic [UART_FRAME_BIT_COUNT-1:0]            bit_count_ff, bit_count_next = 0;

logic [UART_FRAME_BIT_COUNT-1:0]            uart_frame_size;
logic [UART_SBIT_DATA_SIZE-1:0]             shifter_ff, shifter_next;

logic                                       sample_pulse;
logic                                       tx_busy;
logic                                       tx_pin;

// Signals for UART state machine
type_uart_tx_states_e state, state_next;

// Generate local signals for processing
assign sample_pulse = (sample_count_ff == 0);
assign tx_busy      = (bit_count_ff != 0);

always_comb begin
    if (two_stop_bits) begin
	uart_frame_size = UART_8DATA_2STOP_BITS;
    end else begin
        uart_frame_size = UART_8DATA_1STOP_BITS;
    end
end	

// State register synchronous update
always_ff @ (posedge clk or negedge rst_n) begin
    if (!rst_n) begin
	state        <= UART_TX_IDLE;
        sample_count_ff <= '0;
        bit_count_ff   <= '0;
        shifter_ff   <= '0;
    end else begin
	state        <= state_next;
        sample_count_ff <= sample_count_next;
        bit_count_ff   <= bit_count_next;
        shifter_ff   <= shifter_next;
    end
end

// Next_state and output always block
always_comb begin
    case (state)
        UART_TX_IDLE : begin
            tx_pin         = 1;
            sample_count_next = 0;
            bit_count_next   = 0;
            shifter_next   = '0;

            if (valid_i && !tx_busy) begin 
                state_next = UART_TX_START; 
            end
        end
		
        UART_TX_START : begin
            shifter_next = {tx_data_i, 1'b0};
            bit_count_next = uart_frame_size;

            if (tx_busy) begin
                state_next = UART_TX_DATA;
            end
        end
		
        UART_TX_DATA : begin			
            if (sample_pulse) begin
                tx_pin         = shifter_ff[0];
                bit_count_next   = bit_count_ff - 1;
                shifter_next   = {1'b1, shifter_ff[UART_SBIT_DATA_SIZE-1:1]};
                sample_count_next = (baud_div_i - 1);
            end else begin
                sample_count_next = (sample_count_ff - 1);
            end
                     
            if (!tx_busy) begin
                state_next = UART_TX_IDLE;
            end
        end
      
        default : begin
                tx_pin         = 1'b1;
                sample_count_next = '0;
                bit_count_next   = '0;
                shifter_next   = '0; 
                state_next     = UART_TX_IDLE;
        end
    endcase
end

// Output signal assignments
assign ready_o  = !tx_busy;
assign tx_pin_o = tx_pin;

endmodule : uart_ns_tx

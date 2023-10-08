// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: Uart top module with configurable baud rate using
//              buad register. 
//
// Author: Shehzeen Malik, UET Lahore
// Date: 13.7.2022

`ifndef VERILATOR
`include "../../defines/uart_defs.svh"
`else
`include "uart_defs.svh"
`endif


module uart ( 
    input logic                                    rst_n,                    // reset
    input logic                                    clk,                      // clock

    // Dbus to UART module interface
    input wire type_dbus2peri_s                    dbus2uart_i,              
    output type_peri2dbus_s                        uart2dbus_o,              

    // Selection signal from address decoder of dbus interconnect 
    input logic                                    uart_sel_i,
	
    // Interrupt signal from Uart
    output logic                                   uart_irq_o,
     
    // Rx Tx signals from Uart 
    input logic                                    uart_rxd_i,
    output logic                                   uart_txd_o
);

`define                                 FIFOSIZE        8

// Signal definitions for Dbus interface
logic [3:0]                             reg_addr;
logic                                   reg_rd_req;
logic                                   reg_wr_req;
logic [`XLEN-1:0]                       reg_r_data; 
logic [`XLEN-1:0]                       reg_w_data;
	
// Local sinals for IO and internal use
logic                                   tx_valid_next, tx_valid_ff;
logic                                   tx_valid;
logic 					tx_ready;
logic                                   rx_valid;
logic                                   frame_err;
logic                                   rx_empty;

logic [`UART_DATA_SIZE-1:0]             uart_rx_byte;
logic [`UART_DATA_SIZE-1:0] 	        uart_tx_byte;
logic                                   two_stop_bits;

logic [`UART_DATA_SIZE-1:0]             uart_reg_rx_ff, uart_reg_rx_next;	
logic [`UART_DATA_SIZE-1:0]             uart_reg_tx_ff, uart_reg_tx_next;
logic [UART_BAUD_DIV_SIZE-1:0]          uart_reg_baud_ff, uart_reg_baud_next;
logic [19:0]                            uart_reg_txctrl_ff, uart_reg_txctrl_next;
logic [19:0]                            uart_reg_rxctrl_ff, uart_reg_rxctrl_next;
logic [`UART_DATA_SIZE-1:0]             uart_reg_status_ff, uart_reg_status_next;
logic [`UART_DATA_SIZE-1:0]             uart_reg_int_mask_ff, uart_reg_int_mask_next;
   
// Register address decoding signals
logic                                   rx_reg_wr_flag;
logic                                   tx_reg_wr_flag;
logic                                   baud_reg_wr_flag;
logic                                   txctrl_reg_wr_flag;
logic                                   rxctrl_reg_wr_flag;
logic                                   int_mask_reg_wr_flag;

logic                                   [7:0] rx_fifo[0:`FIFOSIZE];
logic                                   [7:0] r_ptr = 0;
logic                                   [7:0] fifo_out;
logic                                   fifo_not_empty;
logic                                   fifo_full;
logic                                   rx_data_read;
logic                                   rx_data_write; 
	
	
//================================= UART register read operations ==================================//
always_comb begin
    reg_r_data  = '0; 
    rx_empty    = '0;

    if(reg_rd_req) begin
        case (reg_addr)
            // UART data receive and trnsmit registers
            UART_TXDATA_R   : reg_r_data =  {~tx_ready, 31'b0};
            UART_RXDATA_R   : begin 
                                  reg_r_data = {~uart_reg_status_ff[1], 23'b0, uart_reg_rx_ff};
                                  rx_empty   = 1'b1;
                              end
            // UART baud rate configuration register
            UART_BAUD_R     : reg_r_data = {16'b0, uart_reg_baud_ff};

            // UART control and status registers
            UART_STATUS_R   : reg_r_data = {24'b0, uart_reg_status_ff};
            UART_TXCTRL_R   : reg_r_data = {12'b0, uart_reg_txctrl_ff};
            UART_RXCTRL_R   : reg_r_data = {12'b0, uart_reg_rxctrl_ff};
 
            // UART interrupt masking register
            UART_INT_MASK_R : reg_r_data = {24'b0, uart_reg_int_mask_ff};
            default         : reg_r_data = '0;
        endcase // reg_addr
    end
end

//================================= UART register write operations ==================================//
always_comb begin

    rx_reg_wr_flag       = 1'b0;
    tx_reg_wr_flag       = 1'b0;
    baud_reg_wr_flag     = 1'b0;
    txctrl_reg_wr_flag   = 1'b0;
    rxctrl_reg_wr_flag   = 1'b0;
    int_mask_reg_wr_flag = 1'b0;

    // Register write flag evaluation
    if(reg_wr_req & ~uart2dbus_ff.ack) begin
        case (reg_addr)
            // UART data receive and trnsmit registers
            UART_RXDATA_R   : begin    end                    // Read only register
            UART_TXDATA_R   : tx_reg_wr_flag       = 1'b1;
            
            // UART baud rate configuration register
            UART_BAUD_R     : baud_reg_wr_flag     = 1'b1;

            // UART tx and rx control registers
            UART_TXCTRL_R   : txctrl_reg_wr_flag  = 1'b1;
            UART_RXCTRL_R   : rxctrl_reg_wr_flag  = 1'b1;
 
            // UART interrupt masking register
            UART_INT_MASK_R : int_mask_reg_wr_flag = 1'b1;
            default         : begin    end
        endcase // reg_addr
    end
end

// Update UART rx data register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_rx_ff <= '0;
    end else begin
        uart_reg_rx_ff <= uart_reg_rx_next;
    end
end

always_comb begin 

    if (fifo_not_empty) begin
        uart_reg_rx_next = fifo_out; 
    end else begin                         
        uart_reg_rx_next = uart_reg_rx_ff; 
    end       
end

// Update UART tx data register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_tx_ff <= 'h4A;
        tx_valid_ff    <= 1'b0;
    end else begin
        uart_reg_tx_ff <= uart_reg_tx_next;
        tx_valid_ff    <= tx_valid_next;
    end
end

always_comb begin 

    if (tx_reg_wr_flag) begin
        uart_reg_tx_next = reg_w_data[7:0]; 
        tx_valid_next    = 1'b1;
    end else begin                         
        uart_reg_tx_next = uart_reg_tx_ff; 
        tx_valid_next    = 1'b0;
    end       
end

// Update UART baud rate register 
// ------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_baud_ff <= 'h10;        
    end else begin
//        uart_reg_baud_ff <= uart_reg_baud_next;
        uart_reg_baud_ff <= 'h0a;
    end
end

always_comb begin 
    if (baud_reg_wr_flag) begin
        uart_reg_baud_next = reg_w_data[15:0];         
    end else begin                         
        uart_reg_baud_next = uart_reg_baud_ff;         
    end       
end

// Update UART tx control register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_txctrl_ff <= '0;        
    end else begin
        uart_reg_txctrl_ff <= uart_reg_txctrl_next;
    end
end

always_comb begin 

    if (txctrl_reg_wr_flag) begin
        uart_reg_txctrl_next = reg_w_data[19:0];          
    end else begin                         
        uart_reg_txctrl_next = uart_reg_txctrl_ff;         
    end       
end

// Update UART rx control register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_rxctrl_ff <= '0;        
    end else begin
        uart_reg_rxctrl_ff <= uart_reg_rxctrl_next;
    end
end

always_comb begin 

    if (rxctrl_reg_wr_flag) begin
        uart_reg_rxctrl_next = reg_w_data[19:0];          
    end else begin                         
        uart_reg_rxctrl_next = uart_reg_rxctrl_ff;         
    end       
end

// Update UART status register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_status_ff <= '0;        

    end else begin
        uart_reg_status_ff <= uart_reg_status_next;
    end
end

always_comb begin 
    uart_reg_status_next = uart_reg_status_ff;
    
    if (fifo_full)  
        uart_reg_status_next[1] = 1'b1;
    else            
        uart_reg_status_next[1] = fifo_not_empty;
    
    uart_reg_status_next[0] = tx_ready;   

end

// Update UART interrupt mask register 
// -----------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_int_mask_ff <= '0;        
    end else begin
        uart_reg_int_mask_ff <= uart_reg_int_mask_next;
    end
end

always_comb begin 

    if (int_mask_reg_wr_flag) begin
        uart_reg_int_mask_next = reg_w_data[7:0];          
    end else begin                         
        uart_reg_int_mask_next = uart_reg_int_mask_ff;         
    end       
end
	
//================================= Dbus interface ==================================//
type_peri2dbus_s                      uart2dbus_ff;

// Signal interface to Wishbone bus
assign reg_addr   = type_uart_regs_e'(dbus2uart_i.addr[5:2]);
assign reg_w_data = dbus2uart_i.w_data;
assign reg_rd_req = !dbus2uart_i.w_en && dbus2uart_i.req && uart_sel_i;
assign reg_wr_req = dbus2uart_i.w_en  && dbus2uart_i.req && uart_sel_i;

// UART synchronous read operation 
always_ff @(posedge clk) begin  
    uart2dbus_ff <= '0;
    if ((reg_wr_req | reg_rd_req) &  ~uart2dbus_ff.ack) begin
        uart2dbus_ff.ack <= 1'b1;
        if (reg_rd_req)
            uart2dbus_ff.r_data <= reg_r_data;         
    end  
end  

// Response signals to dbus 
assign uart2dbus_o.r_data = uart2dbus_ff.r_data;
assign uart2dbus_o.ack = uart2dbus_ff.ack;


// Prepare the output signals
assign two_stop_bits = 1'b1;
assign tx_valid      = tx_valid_ff;
assign uart_tx_byte  = uart_reg_tx_ff;

// UART interrupt generation
assign uart_irq_o  = |(uart_reg_status_ff & uart_reg_int_mask_ff);

// Instantiation of UART transmt and receive modules
uart_tx uart_tx_module (
    .rst_n                      (rst_n),
    .clk                        (clk),	

    .tx_data_i                  (uart_tx_byte),
    .two_stop_bits              (two_stop_bits),
    .baud_div_i                 (uart_reg_baud_ff),
    .tx_pin_o                   (uart_txd_o),

    .valid_i                    (tx_valid),
    .ready_o                    (tx_ready)
);
            
uart_rx uart_rx_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    .rx_pin_in                  (uart_rxd_i),
    .baud_div_i                 (uart_reg_baud_ff),
    .rx_data_o                  (uart_rx_byte),
    .valid_o                    (rx_valid),
    .frame_err_o                (frame_err)
);



always_comb begin
    fifo_out        = rx_fifo[r_ptr];
    fifo_not_empty  = (r_ptr != 8'h0);
    fifo_full       = (r_ptr == `FIFOSIZE-1);
    rx_data_read    = reg_rd_req & ~uart2dbus_ff.ack & (reg_addr == UART_RXDATA_R);
    rx_data_write   = rx_valid;
end   

int i, k;

always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        r_ptr    <= '0;
         for (k = 0; k <= `FIFOSIZE; k++)
            rx_fifo[k] <= '0;

    end else if (rx_data_write & ~rx_data_read) begin
    // if write only, r_ptr += 1
        for (i = 2; i <= `FIFOSIZE; i++) 
            rx_fifo[i]  <= rx_fifo[i-1];

        rx_fifo[1]  <= uart_rx_byte;
                    
        if (r_ptr < `FIFOSIZE)             
            r_ptr <= r_ptr + 8'h1;
    end else if (~rx_data_write &  rx_data_read) begin
    // if read only,  r_ptr -= 1
        if (r_ptr > 0)                     
            r_ptr <= r_ptr - 8'h1;
    end else if (rx_data_write & rx_data_read) begin
    // if both,  no change to r_ptr
        for (i = 2; i <= `FIFOSIZE; i++) 
            rx_fifo[i]  <= rx_fifo[i-1];

        rx_fifo[1]  <= uart_rx_byte;

    end
end
   
    
endmodule	

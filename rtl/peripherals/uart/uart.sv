/*********************************************************************
 * Filename :    uart.sv
 * Date     :    13-07-2022
 * Author   :    
 * Adopted from uart.scala by Dr. Muhammad Tahir
 
 * Description:  Uart top module with configurable baud rate using
 *               buad register.
 *********************************************************************/

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/UART_defs.svh"


 module uart ( 
     input logic                                    rst_n,                    // reset
     input logic                                    clk,                      // clock

     // Dbus to UART module interface
     input wire type_dbus2peri_s                    dbus2uart_i,              // GPIO dbus input signals
     output type_peri2dbus_s                        uart2dbus_o,              // GPIO dbus output signals

     // Selection signal from address decoder of dbus interconnect 
     input   logic                                  uart_sel_i,
	
     // Interrupt signal from Uart
     output	logic				    uart_irq_o,
     
     // Rx Tx signals from Uart 
     input     logic                 		    uart_rxd_i,
     output    logic		                    uart_txd_o
);


// Signal definitions for dbus interface
logic [5:0]                             reg_addr;
logic                                   reg_rd_req;
logic                                   reg_wr_req;
	
// Local sinals for IO and internal use
logic                                   tx_valid_next, tx_valid_ff;
logic                                   tx_valid;
logic 					tx_ready;
logic                                   rx_valid;
logic                                   frame_err;

logic [UART_DATA_SIZE-1:0]              uart_rx_byte;
logic [UART_DATA_SIZE-1:0] 	        uart_tx_byte;
logic                                   two_stop_bits;

logic [UART_DATA_SIZE-1:0]              uart_reg_rx_ff, uart_reg_rx_next;	
logic [UART_DATA_SIZE-1:0]              uart_reg_tx_ff, uart_reg_tx_next;
logic [UART_BAUD_DIV_SIZE-1:0]          uart_reg_baud_ff, uart_reg_baud_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_control_ff, uart_reg_control_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_status_ff, uart_reg_status_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_int_mask_ff, uart_reg_int_mask_next;
   
// Register address decoding signals
logic                                   rx_reg_wr_flag;
logic                                   tx_reg_wr_flag;
logic                                   baud_reg_wr_flag;
logic                                   control_reg_wr_flag;
logic                                   status_reg_wr_flag;
logic                                   int_mask_reg_wr_flag; 
	
// Read and write signals for UART registers
logic [15:0]                            reg_r_data; 
logic [`XLEN-1:0]                       reg_w_data;
	
//================================= UART register read operations ==================================//
always_comb begin
    reg_r_data  = '0; 

    if(reg_rd_req) begin
        case (reg_addr)
            // UART data receive and trnsmit registers
            UART_RXDATA_R   : reg_r_data = uart_reg_rx_ff;
            UART_TXDATA_R   : reg_r_data = uart_reg_tx_ff;
            
            // UART baud rate configuration register
            UART_BAUD_R     : reg_r_data = uart_reg_status_ff;

            // UART control and status registers
            UART_STATUS_R   : reg_r_data = uart_reg_status_ff;
            UART_CONTROL_R  : reg_r_data = uart_reg_status_ff;
 
            // UART interrupt masking register
            UART_INT_MASK_R : reg_r_data = uart_reg_status_ff;
            default         : reg_r_data = '0;
        endcase // reg_addr
    end
end

//================================= UART register write operations ==================================//
always_comb begin

    rx_reg_wr_flag       = 1'b0;
    tx_reg_wr_flag       = 1'b0;
    baud_reg_wr_flag     = 1'b0;
    control_reg_wr_flag  = 1'b0;
    status_reg_wr_flag   = 1'b0;
    int_mask_reg_wr_flag = 1'b0;

    // Register write flag evaluation
    if(reg_wr_req) begin
        case (reg_addr)
            // UART data receive and trnsmit registers
            UART_RXDATA_R   : begin    end                    // Read only register
            UART_TXDATA_R   : tx_reg_wr_flag       = 1'b1;
            
            // UART baud rate configuration register
            UART_BAUD_R     : baud_reg_wr_flag     = 1'b1;

            // UART control and status registers
            UART_CONTROL_R  : control_reg_wr_flag  = 1'b1;
            UART_STATUS_R   : status_reg_wr_flag   = 1'b1;
 
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

    if (rx_valid) begin
        uart_reg_rx_next = uart_rx_byte; 
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
        uart_reg_baud_ff <= 'h8;        
    end else begin
        uart_reg_baud_ff <= uart_reg_baud_next;
    end
end

always_comb begin 
    if (baud_reg_wr_flag) begin
        uart_reg_baud_next = reg_w_data;         
    end else begin                         
        uart_reg_baud_next = uart_reg_baud_ff;         
    end       
end

// Update UART control register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_control_ff <= '0;        
    end else begin
        uart_reg_control_ff <= uart_reg_control_next;
    end
end

always_comb begin 

    if (control_reg_wr_flag) begin
        uart_reg_control_next = reg_w_data[7:0];          
    end else begin                         
        uart_reg_control_next = uart_reg_control_ff;         
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

    case (1'b1)
        frame_err          : begin
            uart_reg_status_next[4] = 1'b1;
        end
        rx_valid           : begin
            uart_reg_status_next[0] = 1'b1;
        end
        status_reg_wr_flag : begin
            uart_reg_status_next    = reg_w_data[7:0]; 
        end
        default            : begin
            uart_reg_status_next[1] = tx_ready; 
        end
    endcase      
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
assign reg_addr   = type_uart_regs_e'(dbus2uart_i.addr[7:2]);
assign reg_w_data = dbus2uart_i.w_data[15:0];
assign reg_rd_req = !dbus2uart_i.w_en && dbus2uart_i.cyc && uart_sel_i;
assign reg_wr_req = dbus2uart_i.w_en  && dbus2uart_i.cyc && uart_sel_i;

// UART synchronous read operation 
always_ff @(posedge clk) begin  
    uart2dbus_ff <= '0;
    if ( reg_rd_req &  ~uart2dbus_ff.ack) begin
            uart2dbus_ff.ack <= 1'b1;
            uart2dbus_ff.r_data <= {16'b0, reg_r_data};  
        
    end  
end  

// Prepare the output signals
assign two_stop_bits = 1'b1;
assign tx_valid      = tx_valid_ff;
assign uart_tx_byte  = uart_reg_tx_ff;

// UART interrupt generation
assign uart_irq_o  = |(uart_reg_status_ff && uart_reg_int_mask_ff);

// Response signals to dbus 
assign uart2dbus_o = uart2dbus_ff;

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
    
    
endmodule	
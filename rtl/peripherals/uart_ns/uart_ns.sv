/*********************************************************************
 * Filename :    uart.sv
 * Date     :    13-07-2022
 * Author   :    
 * Adopted from uart.scala by Dr. Muhammad Tahir
 
 * Description:  Uart top module with configurable baud rate using
 *               buad register.
 *********************************************************************/

`ifndef VERILATOR
`include "../../defines/uart_defs.svh"
`else
`include "uart_defs.svh"
`endif


module uart_ns ( 
    input logic                                    rst_n,                    // reset
    input logic                                    clk,                      // clock

    // Dbus to UART module interface
    input wire type_dbus2peri_s                    dbus2uart_i,              
    output type_peri2dbus_s                        uart2dbus_o,              

    // Selection signal from address decoder of dbus interconnect 
    input logic                                    uart_ns_sel_i,
	
    // Interrupt signal from Uart
    output logic                                   uart_ns_irq_o,
     
    // Rx Tx signals from Uart 
    input logic                                    uart_ns_rxd_i,
    output logic                                   uart_ns_txd_o
);


// Signal definitions for Dbus interface
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
logic [UART_DATA_SIZE-1:0]              uart_reg_baud_ff, uart_reg_baud_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_lctrl_ff, uart_reg_lctrl_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_ie_ff, uart_reg_ie_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_lstatus_ff, uart_reg_lstatus_next;
// logic [UART_DATA_SIZE-1:0]              uart_reg_is_ff, uart_reg_is_next;
logic [UART_DATA_SIZE-1:0]              uart_reg_scratch_ff, uart_reg_scratch_next;
   
// Register address decoding signals
logic                                   fifoctrl_reg_wr_flag;
logic                                   tx_reg_wr_flag;
logic                                   baud_reg_wr_flag;
logic                                   ie_reg_wr_flag;
logic                                   lctrl_reg_wr_flag;
// logic                                   is_reg_wr_flag; 
logic                                   scratch_reg_wr_flag; 
	
// Read and write signals for UART registers
logic [UART_DATA_SIZE-1:0]              reg_r_data; 
logic [`XLEN-1:0]                       reg_w_data;
	
//================================= UART register read operations ==================================//
always_comb begin
    reg_r_data  = '0; 

    if(reg_rd_req) begin
        case (reg_addr)
            // UART data receive and trnsmit registers
       //     UART_TXDATA_R   : reg_r_data = {~tx_ready, 31'b0};
            UART_TXRXDATA_R   : reg_r_data = uart_reg_rx_ff;
            
            // UART baud rate configuration register
            UART_SCRATCH_R     : reg_r_data = uart_reg_scratch_ff;

            // UART control and status registers
            UART_LSTATUS_R   : reg_r_data = uart_reg_lstatus_ff;
            UART_IE_R        : reg_r_data = uart_reg_ie_ff;
 
            // UART interrupt masking register
            UART_LINECTRL_R   : reg_r_data = uart_reg_lctrl_ff;
            default         : reg_r_data = '0;
        endcase // reg_addr
    end
end

//================================= UART register write operations ==================================//
always_comb begin

    fifoctrl_reg_wr_flag = 1'b0;
    tx_reg_wr_flag       = 1'b0;
    baud_reg_wr_flag     = 1'b0;
    ie_reg_wr_flag       = 1'b0;
    lctrl_reg_wr_flag   = 1'b0;
    scratch_reg_wr_flag = 1'b0;

    // Register write flag evaluation
    if(reg_wr_req & ~uart2dbus_ff.ack) begin
        case (reg_addr)
            // UART data receive and trnsmit registers
        //    UART_RXDATA_R   : begin    end                    // Read only register
            UART_TXRXDATA_R   : tx_reg_wr_flag       = 1'b1;
            
            // UART baud rate configuration register
            UART_SCRATCH_R     : scratch_reg_wr_flag     = 1'b1;

            // UART control and status registers
            UART_IS_FIFO_R   : fifoctrl_reg_wr_flag  = 1'b1;
            UART_LINECTRL_R : lctrl_reg_wr_flag   = 1'b1;
 
            // UART interrupt masking register
            UART_IE_R       : ie_reg_wr_flag = 1'b1;
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

// Update UART scratch register 
// ------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_scratch_ff <= 'h8;        
    end else begin
        uart_reg_scratch_ff <= uart_reg_scratch_next;
    end
end

always_comb begin 
    if (scratch_reg_wr_flag) begin
        uart_reg_scratch_next = reg_w_data;         
    end else begin                         
        uart_reg_scratch_next = uart_reg_scratch_ff;         
    end       
end



// Update UART line control register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_lctrl_ff <= '0;        
    end else begin
        uart_reg_lctrl_ff <= uart_reg_lctrl_next;
    end
end

always_comb begin 

    if (lctrl_reg_wr_flag) begin
        uart_reg_lctrl_next = reg_w_data[7:0];          
    end else begin                         
        uart_reg_lctrl_next = uart_reg_lctrl_ff;         
    end       
end

// Update UART line status register 
// ----------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_lstatus_ff <= '0;        
    end else begin
        uart_reg_lstatus_ff <= uart_reg_lstatus_next;
    end
end

always_comb begin 
    uart_reg_lstatus_next = uart_reg_lstatus_ff;

    case (1'b1)
        frame_err          : begin
            uart_reg_lstatus_next[3] = 1'b0;
        end
        rx_valid           : begin
            uart_reg_lstatus_next[0] = 1'b1;
        end
        default            : begin
            uart_reg_lstatus_next[5] = tx_ready;
            uart_reg_lstatus_next[6] = tx_ready; 
        end
    endcase      
end

// Update UART interrupt enable register 
// -----------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        uart_reg_ie_ff <= '0;        
    end else begin
        uart_reg_ie_ff <= uart_reg_ie_next;
    end
end

always_comb begin 

    if (ie_reg_wr_flag) begin
        uart_reg_ie_next = reg_w_data[7:0];          
    end else begin                         
        uart_reg_ie_next = uart_reg_ie_ff;         
    end       
end
	
//================================= Dbus interface ==================================//
type_peri2dbus_s                      uart2dbus_ff;

// Signal interface to Wishbone bus
assign reg_addr   = type_uart_ns_regs_e'(dbus2uart_i.addr[4:2]);
assign reg_w_data = dbus2uart_i.w_data[7:0];
assign reg_rd_req = !dbus2uart_i.w_en && dbus2uart_i.req && uart_ns_sel_i;
assign reg_wr_req = dbus2uart_i.w_en  && dbus2uart_i.req && uart_ns_sel_i;

// UART synchronous read operation 
always_ff @(posedge clk) begin  
    uart2dbus_ff <= '0;
    if ((reg_wr_req | reg_rd_req) &  ~uart2dbus_ff.ack) begin
            uart2dbus_ff.ack <= 1'b1;
        if (reg_rd_req)
            uart2dbus_ff.r_data <= {24'b0, reg_r_data};  
        
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
assign uart_ns_irq_o  = |(uart_reg_lstatus_ff & uart_reg_ie_ff);

// Instantiation of UART transmt and receive modules
uart_ns_tx uart_ns_tx_module (
    .rst_n                      (rst_n),
    .clk                        (clk),	

    .tx_data_i                  (uart_tx_byte),
    .two_stop_bits              (two_stop_bits),
    .baud_div_i                 (uart_reg_baud_ff),
    .tx_pin_o                   (uart_ns_txd_o),

    .valid_i                    (tx_valid),
    .ready_o                    (tx_ready)
);
            
uart_ns_rx uart_ns_rx_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    .rx_pin_in                  (uart_ns_rxd_i),
    .baud_div_i                 (uart_reg_baud_ff),
    .rx_data_o                  (uart_rx_byte),
    .valid_o                    (rx_valid),
    .frame_err_o                (frame_err)
);
    
    
endmodule	

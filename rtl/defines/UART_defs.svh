//////////////////////////////////////////////////////////////////////////////////
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

localparam int unsigned UART_DATA_SIZE      = 8;
localparam int unsigned UART_DATA_BIT_COUNT = $clog2(UART_DATA_SIZE);
localparam int unsigned UART_BAUD_DIV_SIZE  = 16;
localparam int unsigned UART_1STOP_BIT      = 1;
localparam int unsigned UART_2STOP_BITS     = 2;
localparam int unsigned UART_OVERSAMPLE     = 2;

  
localparam UART_SBIT_DATA_SIZE   = UART_DATA_SIZE + 1;
localparam UART_8DATA_1STOP_BITS = UART_SBIT_DATA_SIZE + 1;
localparam UART_8DATA_2STOP_BITS = UART_SBIT_DATA_SIZE + 2;
localparam UART_FRAME_BIT_COUNT  = $clog2(UART_SBIT_DATA_SIZE + UART_2STOP_BITS);

typedef enum logic [3:0] {
    UART_RXDATA_R   = 4'h0,
    UART_TXDATA_R   = 4'h1,
    UART_BAUD_R     = 4'h2,
    UART_CONTROL_R  = 4'h3,
    UART_STATUS_R   = 4'h4,
    UART_INT_MASK_R = 4'h5
} type_uart_regs_e;

typedef enum logic [1:0] {
    UART_TX_IDLE  = 2'h0,
    UART_TX_START = 2'h1,
    UART_TX_DATA  = 2'h2
} type_uart_tx_states_e;


typedef enum logic [1:0] {
    UART_RX_IDLE  = 2'h0,
    UART_RX_START = 2'h1,
    UART_RX_DATA  = 2'h2,
    UART_RX_STOP  = 2'h3
} type_uart_rx_states_e;



   

   


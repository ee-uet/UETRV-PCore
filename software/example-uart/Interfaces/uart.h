
 #define UART_BAUD_DIV  0x10


/** UART module prototype */
typedef struct __attribute__((packed,aligned(4))) {
	uint32_t tx_data;
	uint32_t rx_data;  
	uint32_t tx_crtl;
	uint32_t rx_ctrl;  
	uint32_t int_mask;
	uint32_t status; 
	uint32_t baud;     
} Uetrv32_Uart_Struct;

/** UART module hardware access */
#define UART_Module (*((volatile Uetrv32_Uart_Struct*) (0x90000000UL)))


// Function prototypes
void Uetrv32_Uart_Init(uint32_t baud);
void Uetrv32_Uart_Tx(uint32_t tx_data);
void Uetrv32_Uart_Isr(void);
void UETrv32_Uart_Print(const char *s);
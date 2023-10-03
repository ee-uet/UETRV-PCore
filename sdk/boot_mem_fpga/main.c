#include <stdint.h>
#include "Interfaces/uart.h"


#define dst_data_ptr ((volatile int*) (0x80000000UL))

// Function prototype
uint32_t Get_Data_Word(void);
void Start_App_Program(void);
void Transfer_Executable(void);

void main(void) {

uint8_t  rx_byte = 0;

  // Initialize UART with desired baudrate
  Uetrv32_Uart_Init(UART_BAUD_DIV);

  Uetrv32_Uart_Tx((uint32_t) 'L');
  Uetrv32_Uart_Tx((uint32_t) 'o'); 
  Uetrv32_Uart_Tx((uint32_t) 'a');
  Uetrv32_Uart_Tx((uint32_t) 'd'); 
  Uetrv32_Uart_Tx((uint32_t) ' ');
  Uetrv32_Uart_Tx((uint32_t) 'f'); 
  Uetrv32_Uart_Tx((uint32_t) 'i');
  Uetrv32_Uart_Tx((uint32_t) 'l'); 
  Uetrv32_Uart_Tx((uint32_t) 'e'); 
  Uetrv32_Uart_Tx((uint32_t) '\n');
  Uetrv32_Uart_Tx((uint32_t) '\r'); 
 

  Transfer_Executable();

  Uetrv32_Uart_Tx((uint32_t) 'O');
  Uetrv32_Uart_Tx((uint32_t) 'k');
  Uetrv32_Uart_Tx((uint32_t) '\n');
  Uetrv32_Uart_Tx((uint32_t) '\r'); 

		
  while (rx_byte != 'a') {
      rx_byte = (uint8_t) Uetrv32_Uart_Rx(); 
  }

  return; 
}


/************************************************************************
 * Transfer the executable file to the Instruction Mmeory.
 *
 ***********************************************************************/
void Transfer_Executable(void) {
  
uint32_t instr_code = 0, i = 0;
uint8_t  rx_byte = 0;

    // Clear any spurious reception at startup due to reset
     while (rx_byte != 'a') {
          rx_byte = (uint8_t) Uetrv32_Uart_Rx(); 
     }

    // Get the executable image size 
    uint32_t size  = Get_Data_Word(); // Executable size is in bytes
	
    while (i < (size/4)) {          // Size in words for loop count
        instr_code = Get_Data_Word(); 
        dst_data_ptr[i++] = instr_code;
        
    }

}

/************************************************************************
 * Read word from Uart interface.
 *
 * 
 * @return 32-bit data word.
 ***********************************************************************/
uint32_t Get_Data_Word(void) {

  union {
    uint32_t word;
    uint8_t  byte[sizeof(uint32_t)];
  } data;

  uint32_t i;
		
  for (i=0; i<4; i++) {
     data.byte[i] = (uint8_t) Uetrv32_Uart_Rx(); 
   //  Uetrv32_Uart_Tx((uint32_t) data.byte[i]);   
  }
	
  return data.word;
}




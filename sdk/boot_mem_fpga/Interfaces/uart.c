
// Standard libraries
// #include <stdint.h>
  #include <inttypes.h>
 // #include <limits.h>

#include "uart.h"


/**********************************************************************//**
 * Initialize UART module.
 *
 * @note Configure the baud divisor register.
 *
 * @param baud.
 **************************************************************************/
void Uetrv32_Uart_Init(uint32_t baud) {
  
  UART_Module.baud = baud;
}


/**********************************************************************//**
 * UART data transmit. This is a blocking function.
 *
 **************************************************************************/
void Uetrv32_Uart_Tx(uint32_t tx_data) {
  
  while ((UART_Module.status & 0x01) == 0);
	UART_Module.tx_data = tx_data;             // trigger transfer

  return ;
}

/**********************************************************************//**
 * Print string (zero-terminated) via UART. 
 *
 * @note This function is blocking.
 *
 * @param[in] s -- Pointer to string.
 **************************************************************************/
/* void UETrv32_Uart_Print(const char *s) {

  char c = 0;
  while ((c = *s++)) {
    Uetrv32_Uart_Tx(((uint32_t) c));
  }
}
*/
/**********************************************************************//**
 * UART data receive. This is a blocking function.
 *
 **************************************************************************/
uint8_t Uetrv32_Uart_Rx(void) {
   uint8_t rx_data; 

   while ((UART_Module.status & 0x02) == 0);

   rx_data = (uint8_t) UART_Module.rx_data;       // read data byte
   UART_Module.status &= ~(0x02);

   return rx_data;
}


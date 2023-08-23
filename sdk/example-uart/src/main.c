#include <stdint.h>
#include <stdio.h>

#include "../Interfaces/uart.h"
#include "../Interfaces/plic.h"

unsigned int fact (unsigned int n);

const char message[8] = {'H','e','l','l','o', '\n', '\r'};
char dst[8] = {0,0,0,0,0,0,0,0};


/* ************************************************************************ 
 * Main function.
 **************************************************************************/
int main(void) {
  uint32_t count = 0;

 // Uetrv32_Plic_Init();

 // count = fact(6);

  // Initialize UART with desired baudrate
  Uetrv32_Uart_Init(UART_BAUD_DIV);

 // for(count = 0; count < 8; count++) {
 //   dst[count] = message[count]; 
 // }
//    printf("Hello World");
  while(1){
	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((message[count])); 
  	}  
  }
}

unsigned int fact (unsigned int n) {
if(n <=1) 
  return 1;
return n* fact (n -1) ;
}

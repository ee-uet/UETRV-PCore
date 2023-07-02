// Standard libraries
// #include <stdint.h>
  #include <inttypes.h>
 // #include <limits.h>

#include "spi.h"


/**********************************************************************//**
 * Initialize SPI module.
 *
 * @note Determine the clock freq of SPI bus.
 *
 * @param baud.
 **************************************************************************/
void Uetrv32_Spi_Init(uint8_t baud) {
  
  SPI_Module.baud |= baud;
}


/**********************************************************************//**
 * Initiate SPI transfer. This is a blocking function.
 *
 **************************************************************************/
uint8_t Uetrv32_Spi_Trans(uint8_t tx_data) {
  
  SPI_Module.tx_data = tx_data;             // trigger transfer
  while(!(SPI_Module.status & SPI_TX_RDY)); // wait for transfer to finish

  return (uint8_t)(SPI_Module.rx_data) ;
}


/**********************************************************************//**
 * Activate SPI chip select signal.
 *
 * @param cs Set the chip select mask.
 **************************************************************************/
/* void Uetrv32_Spi_CS_EN(uint8_t cs) {
  
  SPI_Module.ss_mask |= cs;
}
*/

/**********************************************************************//**
 * Deactivate SPI chip select signal.
  *
 * @param cs Reset the chip select mask.
 **************************************************************************/
/* void Uetrv32_Spi_CS_DIS(uint8_t cs) {

  SPI_Module.ss_mask &= ~cs;
}
*/


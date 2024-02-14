/*
 * Copyright (C) 2014  Marco Antonio Zanata Alves (mazalves at inf.ufrgs.br)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdint.h>
#include "../Interfaces/uart.h"
#include "../Interfaces/plic.h"


// Function to read CSR (Control and Status Register)
static inline uint32_t read_csr_mcycle(void) {
    volatile uint32_t value;
    asm volatile ("csrr %0, mcycle" : "=r"(value) : :);
    return value;
}

static inline uint32_t read_csr_minstret(void) {
    volatile uint32_t value;
    asm volatile ("csrr %0, minstret" : "=r"(value) : :);
    return value;
}


void int_to_string(uint32_t value, char *buffer, int buffer_size) {
    // Check for null buffer or zero buffer size
    if (buffer == NULL || buffer_size <= 0)
        return;

    // Ensure the buffer is null-terminated
    buffer[buffer_size - 1] = '\0';

    // Handle negative numbers
    int sign = 1;
    if (value < 0) {
        sign = -1;
        value *= -1;
    }

    // Start writing digits from the end of the buffer
    int pos = buffer_size - 2; // Leave one space for the null terminator
    do {
        buffer[pos--] = '0' + (value % 10); // Convert digit to character
        value /= 10; // Move to the next digit
    } while (value != 0 && pos >= 0);

    // Add sign if the number was negative
    if (sign == -1 && pos >= 0)
        buffer[pos--] = '-';

    // Shift the string to the beginning of the buffer
    if (pos >= 0) {
        int shift = buffer_size - pos - 1;
        for (int i = 0; i <= pos; ++i) {
            buffer[i] = buffer[i + shift];
        }
    } else {
        // If the entire number didn't fit, just ensure null termination
        buffer[0] = '\0';
    }
}

// =============================================================================
int main (void) {
    // Read cycle count
    volatile uint32_t cycles_start = read_csr_mcycle(); // mcycle CSR


  Uetrv32_Uart_Init(UART_BAUD_DIV);
    int i=0, j=-1, k=2, l=3, m=-1, n=5,o=6, count=0;
    int repetitions = 10000;
const char message[8] = {'H','e','l','l','o', '\n', '\r'};
const char done[8] = {'D','o','n','e','!', '\n', '\r'};
const char mcycl[8] = {'C','y','c','l','e', '=', '\r'};
const char minst[8] = {'I','n','s','t','r', '=', '\r'};

	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((message[count])); 
  	}  

    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");

    for (i=0;i<repetitions;i++) {
        if (i%2 == 0) {
            j++;
            switch (j & 3) {
                case 0:
                case 1:
                    k++;
                break;

                case 2:
                case 3:
                    l++;
                break;
            }
        }
        else {
            m++;
            switch (m & 7) {
                case 0:
                case 1:
                case 2:
                case 3:
                    n++;
                break;

                case 4:
                case 5:
                case 6:
                case 7:
                    o++;
                break;
            }
        }
    }

    asm volatile ("nop");
    asm volatile ("nop");
    asm volatile ("nop");
	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((done[count])); 
  	}  


    // Read instruction count
    volatile uint32_t instrs_end = read_csr_minstret(); // minstret CSR

    // Calculate IPC
    volatile uint32_t cycles_end = read_csr_mcycle(); // mcycle CSR
    uint32_t cycles = cycles_end - cycles_start;
    uint32_t instrs = instrs_end; // Assuming no interrupts
    char buffer[20];
    int_to_string(cycles, buffer, sizeof(buffer));
	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((mcycl[count])); 
  	}  
	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((buffer[count])); 
  	}  
    int_to_string(instrs, buffer, sizeof(buffer));
	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((minst[count])); 
  	}  
	for(count = 0; count < 8; count++) {
    	  Uetrv32_Uart_Tx((buffer[count])); 
  	}  
    
    
    

	return 0;

}



// Standard libraries
// #include <stdint.h>
  #include <inttypes.h>
 // #include <limits.h>

#include "plic.h"


/******************************************************************************
* Initialize PLIC module.
*
* @note Configure the priorities and priority threshold.
*
* @param irq, priority.
******************************************************************************/
void Uetrv32_Plic_Init(void)
{
  Uetrv32_Plic_Set_Priority(1, 5);
  Uetrv32_Plic_Set_Priority(2, 6);
  Uetrv32_Plic_Enable_IRQ(1);
  Uetrv32_Plic_Enable_IRQ(2);
}

/******************************************************************************
* Enable IRQ
*
* @note Enable the interrupts.
*
* @param irq, priority.
******************************************************************************/
void Uetrv32_Plic_Enable_IRQ(uint32_t irq)
{
	volatile uint32_t *enable_r = PLIC_IRQ_ENABLE_BASE_ADDRESS;

	enable_r += (irq >> 5);
	*enable_r |= (1 << (irq & 31));
}

/******************************************************************************
* Set priority.
*
* @note Configure the priority for the specific IRQ.
*
* @param irq, priority.
******************************************************************************/
void Uetrv32_Plic_Set_Priority(uint32_t irq, uint32_t priority)
{
	volatile uint32_t *prio_r = PLIC_PRIO_BASE_ADDRESS;

	if (priority > PLIC_MAX_PRIORITY)
		priority = PLIC_MAX_PRIORITY;

  /* Need to perform pointer typecast for proper indexing to the list of 
  priority registers */
	prio_r = prio_r + irq;
	*prio_r = priority;
}

/******************************************************************************
* IRQ handler.
*
* @note Configure the priority for the specific IRQ.
*
* @param irq, priority.
******************************************************************************/
void Uetrv32_Plic_Irq_Handler(void)
{
	volatile uint32_t *claim_complete_r = PLIC_CLAIM_COMPLETE_BASE_ADDRESS;
  uint32_t irq_number;

  // Claim the IRQ to execute the respective ISR
	irq_number = *claim_complete_r;
  
	// Execute desired ISR funcationality here

  // Complete the IRQ processing 
	*claim_complete_r = irq_number;
}





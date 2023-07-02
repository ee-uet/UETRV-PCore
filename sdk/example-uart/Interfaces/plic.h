

// Definitions for constants
#define PLIC_MAX_PRIORITY              7

/* PLIC module register address definitions */
#define PLIC_PRIO_BASE_ADDRESS                   ((volatile uint32_t *) 0x90000000)
#define PLIC_IRQ_ENABLE_BASE_ADDRESS             ((volatile uint32_t *) 0x90002000)
#define PLIC_CLAIM_COMPLETE_BASE_ADDRESS         ((volatile uint32_t *) 0x90200004)

// Function prototypes
void Uetrv32_Plic_Init(void);
void Uetrv32_Plic_Enable_IRQ(uint32_t irq);
void Uetrv32_Plic_Set_Priority(uint32_t irq, uint32_t priority);
void Uetrv32_Plic_Irq_Handler(void);


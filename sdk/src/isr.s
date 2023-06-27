# RISC-V Interrupt Service Routines (ISRs) 
# ALL supported ISRs should be put here

.section .text.isr

# External interrupt handler
.globl meip_handler
.globl mexc_handler
.globl sexc_handler

meip_handler:
  addi   sp,sp,-16
  sw	   ra,12(sp)
  sw	   a5,4(sp)
  sw	   a4,8(sp)
  call   Uetrv32_Plic_Irq_Handler
  lw	   a4,8(sp)  
  lw	   a5,4(sp)
  lw	   ra,12(sp)
  addi   sp,sp,16
  mret
  
  
mexc_handler:
  addi   sp,sp,-16
  sw	   ra,12(sp)
  sw	   a5,4(sp)
  sw	   a4,8(sp)
                    # Call system function
  lw	   a4,8(sp)  
  lw	   a5,4(sp)
  lw	   ra,12(sp)
  addi   sp,sp,16
  mret

sexc_handler:
  addi   sp,sp,-16
  sw	   ra,12(sp)
  sw	   a5,4(sp)
  sw	   a4,8(sp)
                    # Call system function
  lw	   a4,8(sp)  
  lw	   a5,4(sp)
  lw	   ra,12(sp)
  addi   sp,sp,16
  sret



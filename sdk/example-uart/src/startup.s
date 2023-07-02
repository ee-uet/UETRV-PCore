
.equ CSR_MSTATUS, 0x300
.equ CSR_MTVEC,   0x305
.equ CSR_MIE,     0x304
.equ CSR_MEPC,    0x341
.equ CSR_SSTATUS, 0x100
.equ CSR_SATP,    0x180

.equ MSTATUS_MIE, 0x00000008


 # Main interrupt vector table entries.

.global vtable
.type vtable, %object
.section .text.vector_table,"a",%progbits
 # this entry is to align reset_handler at address 0x04
  .word 0x00000013        
  j        reset_handler
  .align 6
vtable:
  j        mexc_handler
  .word 0
  .word 0
  j        msip_handler
  .word 0
  .word 0
  .word 0
  j        mtip_handler
  .word 0
  .word 0
  .word 0
  j        meip_handler
  .word 0
  .word 0
  .word 0
  .word 0
  j        uart_handler
  .word 0
  .word 0
  .word 0

# Weak aliases to point each exception handler to the
# 'default_interrupt_handler', unless the application defines
# a function with the same name to override the reference.

  .weak msip_handler
  .set  msip_handler, default_interrupt_handler
  .weak mtip_handler
  .set  mtip_handler, default_interrupt_handler
  .weak meip_handler
  .set  meip_handler, default_interrupt_handler
  .weak uart_handler
  .set  uart_handler, default_interrupt_handler

# Assembly 'reset handler' function to initialize core CPU registers.
.section .text.default_interrupt_handler,"ax",%progbits

.global reset_handler
.type reset_handler,@function

reset_handler:
# set mstatus.MIE=1 (enable M mode interrupt)
  li      t0, 0x8
  csrrs   zero, CSR_MSTATUS, t0

# set mie.MEIE=1 (enable M mode external interrupt)
  li      t0, 0x0800
  csrrs   zero, CSR_MIE, t0

# Load the initial stack pointer value.
  la   sp, _sp

# Set the vector table's base address.
  la   a0, vtable
  addi a0, a0, 1
  csrw CSR_MTVEC, a0


# Call user 'main(0,0)' (.data/.bss sections initialized there)
call_main:
  li   a0, 0
  li   a1, 0
  call main

# A 'default' interrupt handler, in case an interrupt triggers without its handler defined
default_interrupt_handler:
  j default_interrupt_handler

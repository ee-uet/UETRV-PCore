.section .text.start, "ax", @progbits
.globl _start
_start:
  li s0, 1
  slli s0, s0, 31
  csrr a0, mhartid
  la a1, _dtb
  jr s0

.section .rodata.dtb, "a", @progbits
.globl _dtb
.align 5, 0
_dtb:
.incbin "dtpcore.dtb"

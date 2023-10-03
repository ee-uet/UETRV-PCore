OUTPUT_ARCH( "riscv" )
ENTRY( _start )

MEMORY
{ 
  IMEM (rx)  : ORIGIN = 0x00001000, LENGTH = 4K
  DMEM (rwx) : ORIGIN = 0x80000000, LENGTH = 32000K
}


SECTIONS
{
  __stack_size = DEFINED(__stack_size) ? __stack_size : 400;

  . = ALIGN(4);

  .text :
  {
    KEEP (*(SORT_NONE(.text.start)))
  } >IMEM

  .text :
  { *(.text .text.*)
    *(.rodata .rodata.*)  
    *(.srodata .srodata.*)    
  } >IMEM


  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);

  _sidata = .;
  .data : AT( _sidata )
  {
    _sdata = .;
    *(.rdata) 
    *(.data .data.*)
    *(.sdata .sdata.*)
    . = ALIGN(4);
    _edata = .;
  } >DMEM

  PROVIDE( _edata = . );
  PROVIDE( edata = . );
  PROVIDE( _fbss = . );
  PROVIDE( __bss_start = . );

  .bss :
  {
    _sbss = .;
    *(.sbss*)
    *(.bss .bss.*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } >DMEM

  . = ALIGN(8);
  PROVIDE( _end = . );
  PROVIDE( end = . );

  .stack ORIGIN(DMEM) + LENGTH(DMEM) - __stack_size :
  {
    PROVIDE( _heap_end = . ); 
    . = __stack_size;  
    PROVIDE( _sp = . ); 
  } >DMEM
}

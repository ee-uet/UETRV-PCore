SECTIONS
{
    ROM_BASE = 0x00001000; /* ... but actually position independent */

    . = ROM_BASE;
    .text.start : { *(.text.start) }
    . = ROM_BASE + 0x20;
   /* .text.hang : { *(.text.hang) }
    . = ROM_BASE + 0x80; */
    .rodata.dtb : { *(.rodata.dtb) }
}

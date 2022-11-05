#ifndef _COMPLIANCE_MODEL_H
#define _COMPLIANCE_MODEL_H
// #define RVMODEL_DATA_SECTION \
//         .pushsection .tohost,"aw",@progbits;                            \
//         .align 8; .global tohost; tohost: .dword 0;                     \
//         .align 8; .global fromhost; fromhost: .dword 0;                 \
//         .popsection;                                                    \
//         .align 8; .global begin_regstate; begin_regstate:               \
//         .word 128;                                                      \
//         .align 8; .global end_regstate; end_regstate:                   \
//         .word 4;

// Pcore Halt code section
#define RVMODEL_HALT                                          \
    la   a0, begin_signature;                                 \
    la   a1, end_signature;                                   \
    li   a2, 0x88000000;                                      \
    signature_dump_loop:                                      \
      bge  a0, a1, signature_dump_end;                        \
      lw   t0, 0(a0);                                         \
      sw   t0, 0(a2);                                         \
      addi a0, a0, 4;                                         \
      j    signature_dump_loop;                               \
    signature_dump_end:                                       \
      nop;                                                    \
    terminate_simulation:                                     \
      li   a0, 0x8C000000;                                    \
      li   a1, 0xCAFECAFE;                                    \
      sw   a1, 0(a0);                                         \
      j    terminate_simulation;


#define RVMODEL_DATA_BEGIN                                    \
    .align 4; .global begin_signature; begin_signature:       \

#define RVMODEL_DATA_END                                      \
    .align 4; .global end_signature; end_signature:           \

#define RVMODEL_BOOT \
.section .text.init;                                          \
        .align  4;                                            \
        .globl _start;                                        \
_start:  

#define LOCAL_IO_WRITE_STR(_STR) RVMODEL_IO_WRITE_STR(x31, _STR)
#define RVMODEL_IO_WRITE_STR(_SP, _STR)
#define LOCAL_IO_PUSH(_SP)
#define LOCAL_IO_POP(_SP)
#define RVMODEL_IO_ASSERT_GPR_EQ(_SP, _R, _I)
#define RVMODEL_IO_ASSERT_SFPR_EQ(_F, _R, _I)
#define RVMODEL_IO_ASSERT_DFPR_EQ(_D, _R, _I)

#define RVMODEL_SET_MSW_INT
#define RVMODEL_CLEAR_MSW_INT
#define RVMODEL_CLEAR_MTIMER_INT
#define RVMODEL_CLEAR_MEXT_INT

#endif // _COMPLIANCE_MODEL_H
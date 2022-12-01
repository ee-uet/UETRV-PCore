// UETRV_PCore_CSR.svh
`ifndef UETRV_PCORE_CSR
`define UETRV_PCORE_CSR

`include "UETRV_PCore_defs.svh"

// ISA implementation related details
`define RVI_BASE                    `XLEN'h0100
`define RVM_EXTENTION               `XLEN'h1000
`define MISA_MXL_32                 `XLEN'h10000000

// Processor core identifiers
`define CSR_MVENDORID               `XLEN'h00000000
`define CSR_MHARTID                  0

// Machine ISA info
`define CSR_MISA                    `MISA_MXL_32 | `RVI_BASE | `RVM_EXTENTION

// Local parameters for setting up interrupt enable register
localparam int unsigned S_SOFT_INT_IDX  = 1;
localparam int unsigned M_SOFT_INT_IDX  = 3;
localparam int unsigned S_TIMER_INT_IDX = 5;
localparam int unsigned M_TIMER_INT_IDX = 7;
localparam int unsigned S_EXT_INT_IDX   = 9;
localparam int unsigned M_EXT_INT_IDX   = 11;

localparam logic [`XLEN-1:0] MIE_SSIP = 1 << S_SOFT_INT_IDX;
localparam logic [`XLEN-1:0] MIE_MSIP = 1 << M_SOFT_INT_IDX;
localparam logic [`XLEN-1:0] MIE_STIP = 1 << S_TIMER_INT_IDX;
localparam logic [`XLEN-1:0] MIE_MTIP = 1 << M_TIMER_INT_IDX;
localparam logic [`XLEN-1:0] MIE_SEIP = 1 << S_EXT_INT_IDX;
localparam logic [`XLEN-1:0] MIE_MEIP = 1 << M_EXT_INT_IDX;

localparam logic [`XLEN-1:0] MIE_MASK = MIE_SSIP | MIE_STIP | MIE_SEIP | MIE_MSIP | MIE_MTIP | MIE_MEIP;


// Parameters for trap setup and handling
localparam int unsigned CSR_MTVEC_BASE_ALIGN_VECTOR = 6;
localparam int unsigned CSR_MTVEC_BASE_ALIGN_DIRECT = 2;
localparam int unsigned MODE_BIT = 0;

localparam int unsigned CSR_STVEC_BASE_ALIGN_VECTOR = 6;
localparam int unsigned CSR_STVEC_BASE_ALIGN_DIRECT = 2;

//============== Control & Status Registers (CSRs) address definitions =============//
typedef enum logic [11:0] {
// Machine mode information registers (RO)
    CSR_ADDR_MVENDORID  = 12'hF11,
    CSR_ADDR_MARCHID    = 12'hF12,
    CSR_ADDR_MIMPID     = 12'hF13,
    CSR_ADDR_MHARTID    = 12'hF14,

    // Machine mode trap setup and handling registers 
    CSR_ADDR_MSTATUS    = 12'h300,  // Read-write
    CSR_ADDR_MISA       = 12'h301,  // Read-only
    CSR_ADDR_MEDELEG    = 12'h302,  // Read-write
    CSR_ADDR_MIDELEG    = 12'h303,  // Read-write
    CSR_ADDR_MIE        = 12'h304,  // Read-write
    CSR_ADDR_MTVEC      = 12'h305,  // Read-write
    CSR_ADDR_MCOUNTEREN = 12'h306,  // Read-write
    CSR_ADDR_MSTATUSH   = 12'h310,  // Read-write

    CSR_ADDR_MSCRATCH   = 12'h340,  // Read-write
    CSR_ADDR_MEPC       = 12'h341,  // Read-write
    CSR_ADDR_MCAUSE     = 12'h342,  // Read-write
    CSR_ADDR_MTVAL      = 12'h343,  // Read-write
    CSR_ADDR_MIP        = 12'h344,  // Read-only

    // Supervisor mode trap setup and handling registers
    CSR_ADDR_SSTATUS    = 12'h100,
    CSR_ADDR_SIE        = 12'h104,
    CSR_ADDR_STVEC      = 12'h105,
    CSR_ADDR_SCOUNTEREN = 12'h106,
    CSR_ADDR_SSCRATCH   = 12'h140,
    CSR_ADDR_SEPC       = 12'h141,
    CSR_ADDR_SCAUSE     = 12'h142,
    CSR_ADDR_STVAL      = 12'h143,
    CSR_ADDR_SIP        = 12'h144,
    CSR_ADDR_SATP       = 12'h180,
   
    // Machine mode cycle count, instruction retire and other counter registers 
    CSR_ADDR_MCYCLE         = 12'hB00,
    CSR_ADDR_MCYCLEH        = 12'hB80,
    CSR_ADDR_MINSTRET       = 12'hB02,
    CSR_ADDR_MINSTRETH      = 12'hB82,
    CSR_ADDR_MCOUNTINHIBIT  = 12'h320
} type_csr_addr_e;


//================================= Exception codes ================================//
localparam int unsigned EXC_CODE_WIDTH = 4;

typedef enum logic [EXC_CODE_WIDTH-1:0] {
    EXC_CODE_INSTR_MISALIGN        = 4'd0,     // Exception from execution module
    EXC_CODE_INSTR_ACCESS_FAULT    = 4'd1,     // Exception from fecth module
    EXC_CODE_ILLEGAL_INSTR         = 4'd2,     // Exception from CSR or decode module 
    EXC_CODE_BREAKPOINT            = 4'd3,     // Exception from decode module 
    EXC_CODE_LD_ADDR_MISALIGN      = 4'd4,     // Exception from memory/CSR module
    EXC_CODE_LD_ACCESS_FAULT       = 4'd5,     // Exception from memory/CSR module
    EXC_CODE_ST_ADDR_MISALIGN      = 4'd6,     // Exception from memory/CSR module
    EXC_CODE_ST_ACCESS_FAULT       = 4'd7,     // Exception from memory/CSR module
    EXC_CODE_ECALL_UMODE           = 4'd8,     // Ecall from user mode
    EXC_CODE_ECALL_SMODE           = 4'd9,     // Ecall from supervisor mode
    EXC_CODE_ECALL_MMODE           = 4'd11,    // Ecall from machine mode
    EXC_CODE_NO_EXCEPTION          = 4'd15     // No exception, normal behavior
} type_exc_code_e;

//============================= Interrupt request codes ============================//
localparam int unsigned IRQ_CODE_WIDTH = 4;

typedef enum logic [IRQ_CODE_WIDTH-1:0] {
    IRQ_CODE_S_SOFTWARE = 4'd1,     // S-mode software IRQ code 
    IRQ_CODE_M_SOFTWARE = 4'd3,     // M-mode software IRQ code 
    IRQ_CODE_S_TIMER    = 4'd5,     // S-mode timer IRQ code 
    IRQ_CODE_M_TIMER    = 4'd7,     // M-mode timer IRQ code
    IRQ_CODE_S_EXTERNAL = 4'd9,     // S-mode external IRQ code
    IRQ_CODE_M_EXTERNAL = 4'd11     // M-mode external IRQ code
} type_irq_code_e;

localparam logic [`XLEN-1:0] MIP_MASK = MIE_SSIP | MIE_STIP | MIE_SEIP | MIE_MSIP | MIE_MTIP | MIE_MEIP;


//=========================== Register bitfield definitions ==========================//

// Definitions for different privilege modes 
typedef enum logic[1:0] {
    PRIV_MODE_M = 2'b11,
    PRIV_MODE_S = 2'b01,
    PRIV_MODE_U = 2'b00
} type_priv_mode_e;


// Bitfield definitions for STATUS register
 typedef struct packed {
    logic              sd;     // signal dirty state - read-only
    logic [7:0]        wpri3;  // writes preserved reads ignored
    logic              tsr;    // trap sret
    logic              tw;     // time wait
    logic              tvm;    // trap virtual memory
    logic              mxr;    // make executable readable
    logic              sum;    // permit supervisor access to user memory 
    logic              mprv;   // modify privilege level for ld/st
    logic [1:0]        xs;     // status of user extension - hardwired to zero
    logic [1:0]        fs;     // status of floating point extension - hardwired to zero
    type_priv_mode_e   mpp;    // holds the previous privilege mode up to machine mode
    logic [1:0]        vs;     // status of vector extension - hardwired to zero
    logic              spp;    // holds the previous privilege mode up to supervisor mode
    logic              mpie;   // machine mode interrupts enable bit active prior to trap
    logic              ube;    // user mode memory endianess control
    logic              spie;   // supervisor mode interrupts enable bit active prior to trap
    logic              wpri2;  // writes preserved reads ignored
    logic              mie;    // machine interrupts enable
    logic              wpri1;  // writes preserved reads ignored
    logic              sie;    // supervisor interrupts enable
    logic              wpri0;  // writes preserved reads ignored
} type_status_reg_s;

// Masks for supervisor status register
localparam logic [`XLEN-1:0] STATUS_SIE  = 'h00000002;
localparam logic [`XLEN-1:0] STATUS_SPIE = 'h00000020;
localparam logic [`XLEN-1:0] STATUS_UBE  = 'h00000040;
localparam logic [`XLEN-1:0] STATUS_SPP  = 'h00000100;
localparam logic [`XLEN-1:0] STATUS_VS   = 'h00000600;
localparam logic [`XLEN-1:0] STATUS_FS   = 'h00006000;
localparam logic [`XLEN-1:0] STATUS_XS   = 'h00018000;
localparam logic [`XLEN-1:0] STATUS_SUM  = 'h00040000;
localparam logic [`XLEN-1:0] STATUS_MXR  = 'h00080000;
localparam logic [`XLEN-1:0] STATUS_SD   = 'h80000000;

// Read and write masks for SSTATUS register
localparam logic [`XLEN-1:0] SSTATUS_READ_MASK  = STATUS_SIE | STATUS_SPIE
                                                | STATUS_UBE | STATUS_SPP
                                                | STATUS_VS  | STATUS_FS
                                                | STATUS_XS  | STATUS_SUM
                                                | STATUS_MXR | STATUS_SD;
                                                   
                                                  
localparam logic [`XLEN-1:0] SSTATUS_WRITE_MASK = STATUS_SIE | STATUS_SPIE
                                                | STATUS_UBE | STATUS_SPP
                                                | STATUS_VS  | STATUS_FS
                                                | STATUS_XS  | STATUS_SUM
                                                | STATUS_MXR | STATUS_SD;

// Bitwidth parameters and bitfield definition for SATP register
localparam SATP_MODE_WIDTH = 1;
localparam SATP_ASID_WIDTH = 9;
localparam SATP_PPN_WIDTH  = 22;
localparam MODE_SV32       = 1;

typedef struct packed {
    logic [SATP_MODE_WIDTH-1:0] mode;
    logic [SATP_ASID_WIDTH-1:0] asid;
    logic [SATP_PPN_WIDTH-1:0]  ppn;
} type_satp_reg_s;

// Bitwidth parameters and bitfield definition for (machine/supervisor) trap vector (xTVEC) register
localparam TVEC_MODE_WIDTH = 2;
localparam TVEC_BASE_WIDTH = 30;

typedef struct packed {
    logic [TVEC_BASE_WIDTH-1:0] base;
    logic [TVEC_MODE_WIDTH-1:0] mode;
} type_tvec_reg_s;

// Bitfield definitions for machine interrupt enable (mie) and machine interrupt
// pending (mip) registers
typedef struct packed {
    logic [14:0]                warl7;   // write any read legal value
    logic                       uart;
    logic [3:0]                 warl6;
    logic                       meie;    // machine level external interrupt enable bit
    logic                       warl5;
    logic                       seie;    // supervisor level external interrupt enable bit
    logic                       warl4;
    logic                       mtie;    // machine level timer interrupt enable bit
    logic                       warl3;
    logic                       stie;    // supervisor level timer interrupt enable bit
    logic                       warl2;
    logic                       msie;    // machine level software interrupt enable bit
    logic                       warl1;
    logic                       ssie;    // supervisor level software interrupt enable bit
    logic                       warl0;
} type_mie_reg_s;

typedef struct packed {
    logic [14:0]                warl7;   // write any read legal value
    logic                       uart;
    logic [3:0]                 warl6;
    logic                       meip;    // machine level external interrupt pending bit
    logic                       warl5;
    logic                       seip;    // supervisor level external interrupt pending bit
    logic                       warl4;
    logic                       mtip;    // machine level timer interrupt pending bit
    logic                       warl3;
    logic                       stip;    // supervisor level timer interrupt pending bit
    logic                       warl2;
    logic                       msip;    // machine level software interrupt pending bit
    logic                       warl1;
    logic                       ssip;    // supervisor level software interrupt pending bit
    logic                       warl0;
} type_mip_reg_s;

// Bitfield definitions for supervisor interrupt enable (sie) and supervisor interrupt
// pending (sip) registers
typedef struct packed {
    logic [14:0]                warl10;   // write any read legal value
    logic                       uart;
    logic [3:0]                 warl9;
    logic                       warl8;   
    logic                       warl7;
    logic                       seie;    // supervisor level external interrupt enable bit
    logic                       warl6;
    logic                       warl5;    
    logic                       warl4;
    logic                       stie;    // supervisor level timer interrupt enable bit
    logic                       warl3;
    logic                       warl2;    
    logic                       warl1;
    logic                       ssie;    // supervisor level software interrupt enable bit
    logic                       warl0;
} type_sie_reg_s;

typedef struct packed {
    logic [14:0]                warl10;   // write any read legal value
    logic                       uart;
    logic [3:0]                 warl9;
    logic                       warl8;   
    logic                       warl7;
    logic                       seip;    // supervisor level external interrupt pending bit
    logic                       warl6;
    logic                       warl5;    
    logic                       warl4;
    logic                       stip;    // supervisor level timer interrupt pending bit
    logic                       warl3;
    logic                       warl2;    
    logic                       warl1;
    logic                       ssip;    // supervisor level software interrupt pending bit
    logic                       warl0;
} type_sip_reg_s;

typedef struct packed {
    logic [27:0]               warl1;
    logic                       hpm3;
    logic                       ir;
    logic                       warl0;
    logic                       cy;
} type_mcountinhibit_reg_s;

`endif // UETRV_PCORE_CSR

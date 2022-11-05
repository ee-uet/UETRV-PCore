// UETRV_PCore_defs.svh
`ifndef UETRV_PCORE_DEFS
`define UETRV_PCORE_DEFS

//============================= CORE PARAMETERS ========================//

// Width of main registers and buses
`define XLEN                        32

`define VALEN                       32
`define PALEN                       34
`define PAGE_SIZE                   4096  // 4k page size in bytes
`define VPAGE_AWIDTH                `VALEN-$clog2(`PAGE_SIZE)
`define PPN_WIDTH                   22


`define RF_AWIDTH                    5
`define RF_SIZE                     32

// Memory related parameters

`define IMEM_SIZE                    4096
`define IMEM_INST_REQ                1

`define DMEM_SIZE                    4096
`define IDMEM_SIZE                   24'hFFFFFF
`define MEM_ADDR_WIDTH               24

`define DEV_SEL_ADDR_HIGH            31
`define DEV_SEL_ADDR_LOW             28


`define DUALPORT_MEMORY              1

// Pipeline stage definitions
`define IF2ID_PIPELINE_STAGE         1
`define ID2EXE_PIPELINE_STAGE        1
`define EXE2LSU_PIPELINE_STAGE       1
`define LSU2WRB_PIPELINE_STAGE       1

`define INSTR_NOP                    32'h00000013

`ifdef COMPLIANCE_TEST
    `define PC_RESET                     32'h80000000    
`else
    `define PC_RESET                     32'h8000E000  
`endif           

// Address ranges for different peripheral modules
`define DBUS_ADDR_WIDTH              32
`define IMEM_ADDR_MASK               `DBUS_ADDR_WIDTH'h0FFFF
`define DMEM_ADDR_MASK               `DBUS_ADDR_WIDTH'hF0000
`define UART_ADDR_MASK               `DBUS_ADDR_WIDTH'hF0000
`define IMEM_ADDR_MATCH              4'h8
`define DMEM_ADDR_MATCH              4'h8
`define UART_ADDR_MATCH              4'h1
`define CLINT_ADDR_MATCH             4'h4

// All address space for Data Memory for Compliance Testing
`define COMPLIANCE_TEST              0

typedef enum logic [3:0] {
    MTIME_LOW_R     = 4'h0,
    MTIME_HIGH_R    = 4'h4,
    MTIMECMP_LOW_R  = 4'h8,
    MTIMECMP_HIGH_R = 4'hC
} type_mtime_regs_e;



`endif // UETRV_PCORE_SVH
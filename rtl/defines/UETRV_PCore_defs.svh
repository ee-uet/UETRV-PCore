// UETRV_PCore_defs.svh
`ifndef UETRV_PCORE_SVH
`define UETRV_PCORE_SVH

//============================= CORE PARAMETERS ========================//

// Width of main registers and buses
`define XLEN                       32

`define RF_AWIDTH                    5
`define RF_SIZE                     32


`define IMEM_SIZE                 1024
`define IMEM_INST_REQ                1

`define DMEM_SIZE                 1024
`define IDMEM_SIZE                2048

`define DUALPORT_MEMORY              1
`define IF2ID_PIPELINE_STAGE         1
`define EXE2MEM_PIPELINE_STAGE       1

`define INSTR_NOP                 32'h00000013


// Address ranges for different peripheral modules
`define DBUS_ADDR_WIDTH       16
`define DMEM_ADDR_MASK       `DBUS_ADDR_WIDTH'hF000
`define DMEM_ADDR_MATCH      `DBUS_ADDR_WIDTH'h1000
`define GPIO_ADDR_MASK       `DBUS_ADDR_WIDTH'hF000
`define GPIO_ADDR_MATCH      `DBUS_ADDR_WIDTH'h2000

`endif // UETRV_PCORE_SVH
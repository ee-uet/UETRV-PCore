// UETRV_PCore_defs.svh
`ifndef UETRV_PCORE_SVH
`define UETRV_PCORE_SVH

//============================= CORE PARAMETERS ========================//

// Width of main registers and buses
`define XLEN               32

`define RF_AWIDTH           5
`define RF_SIZE            32


`define IMEM_SIZE        1024
`define IMEM_INST_REQ       1

`define DMEM_SIZE        1024

// `define IF2ID_PIPELINE_STAGE 0

`define INSTR_NOP           32'h00000013

`endif // UETRV_PCORE_SVH
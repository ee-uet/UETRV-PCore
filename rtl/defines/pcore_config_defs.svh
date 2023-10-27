// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Muhammad Tahir, UET Lahore
// Date: 13.4.2022


`ifndef PCORE_CONFIG_DEFS
`define PCORE_CONFIG_DEFS

`ifndef COMPLIANCE
`define DRAM                         1
//`define RTL_SIMULATION               1 
`endif

`define ICACHE_SETS                  2048
`define DCACHE_SETS                  512

//============================= CORE PARAMETERS ========================//

// Width of main registers and buses
`define XLEN                         32

`define VALEN                        32
`define PALEN                        34
`define PAGE_SIZE                    4096  // 4k page size in bytes
`define VPAGE_AWIDTH                 `VALEN-$clog2(`PAGE_SIZE)
`define PPN_WIDTH                    22
`define RF_AWIDTH                    5
`define RF_SIZE                      32

// Memory address map related definitions
`define DMEM_ADDR_MATCH              4'h8
`define UART_ADDR_MATCH              8'h90
`define UART_NS_ADDR_MATCH           8'h98
`define SPI_ADDR_MATCH               8'h9C
`define PLIC_ADDR_MATCH              8'h94
`define CLINT_ADDR_MATCH             8'h02
`define BMEM_ADDR_MATCH              20'h00001

// Boot mode selection
`define LINUX_BOOT                   1

`ifndef COMPLIANCE
`ifdef LINUX_BOOT
`define PC_RESET                     32'h00001000  // Booting from boot memory to pass the device tree pointer                    
`else
`define PC_RESET                     32'h80000000  // Booting from data memory
`endif
`else 
`define PC_RESET                     32'h80000000
`endif

// Memory related parameters
`define IMEM_SIZE                    24'hFFFFFF
`define IMEM_INST_REQ                1

`define BMEM_SIZE                    4096

`define IDMEM_SIZE                   'h3FFFFFF
`define MEM_ADDR_WIDTH               26

`define DMEM_SEL_ADDR_HIGH           31
`define DMEM_SEL_ADDR_LOW            28

`define PERI_SEL_ADDR_HIGH           31
`define PERI_SEL_ADDR_LOW            24

`define BMEM_SEL_ADDR_HIGH           31
`define BMEM_SEL_ADDR_LOW            12

// Pipeline stage definitions
`define IF2ID_PIPELINE_STAGE         1
`define ID2EXE_PIPELINE_STAGE        1
`define EXE2LSU_PIPELINE_STAGE       1
`define LSU2WRB_PIPELINE_STAGE       1

`define INSTR_NOP                    32'h00000013

// Address ranges for different peripheral modules
`define DBUS_ADDR_WIDTH              32

`define UART_REG_OFFSET_WIDTH        12
`define PLIC_REG_OFFSET_WIDTH        24
`define CLINT_ADDR_WIDTH             16

typedef enum logic [`CLINT_ADDR_WIDTH-1:0] {
    MTIME_LOW_R     = 16'hbff8,
    MTIME_HIGH_R    = 16'hbffc,
    MTIMECMP_LOW_R  = 16'h4000,
    MTIMECMP_HIGH_R = 16'h4004
} type_mtime_regs_e;



`endif // PCORE_CONFIG_DEFS

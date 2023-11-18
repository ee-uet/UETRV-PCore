// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description:  
//
// Author: Muhammad Tahir, UET Lahore
// Date: 13.4.2022


`ifndef PCORE_INTERFACE_DEFS
`define PCORE_INTERFACE_DEFS

`include "pcore_config_defs.svh"
`include "pcore_csr_defs.svh"
`include "a_ext_defs.svh"

//============================== ISA related definitions ================================//

typedef enum logic [4:0] {
    OPCODE_LOAD_INST      = 5'b00000,
    OPCODE_STORE_INST     = 5'b01000,
    OPCODE_MEM_FENCE_INST = 5'b00011,
    OPCODE_IMM_INST       = 5'b00100,
    OPCODE_AUIPC_INST     = 5'b00101,
    OPCODE_ARITH_INST     = 5'b01100,
    OPCODE_LUI_INST       = 5'b01101,
    OPCODE_BRANCH_INST    = 5'b11000,
    OPCODE_JALR_INST      = 5'b11001,
    OPCODE_JAL_INST       = 5'b11011,
    OPCODE_AMO_INST       = 5'b01011,
    OPCODE_SYSTEM_INST    = 5'b11100
} type_rv_opcode_e;

// ALU operand 1 selection
typedef enum logic {
    ALU_OPR1_PC = '0,       // opr1 = program counter
    ALU_OPR1_REG            // opr1 = rs1
} type_alu_opr1_sel_e;

// ALU operand 2 selection
typedef enum logic {
    ALU_OPR2_IMM = '0,     // opr2 = immediate value 
    ALU_OPR2_REG           // opr2 = rs2
} type_alu_opr2_sel_e;

// ALU comparison operand 2 selection
typedef enum logic {
    ALU_CMP_OPR2_IMM = '0, // opr2 = immediate value
    ALU_CMP_OPR2_REG       // opr2 = rs2
} type_alu_cmp_opr2_sel_e;


typedef enum logic [3:0] {
    ALU_I_OPS_NONE = '0,   // ALU is idle 
    ALU_I_OPS_ADD,          // oprnd1 + oprnd2
    ALU_I_OPS_SUB,          // oprnd1 - oprnd2
    ALU_I_OPS_AND,          // oprnd1 & oprnd2
    ALU_I_OPS_OR,           // oprnd1 | oprnd2
    ALU_I_OPS_XOR,          // oprnd1 ^ oprnd2
    ALU_I_OPS_SLT,          // oprnd1 s< oprnd2
    ALU_I_OPS_SLTU,         // oprnd1 u< oprnd2
    ALU_I_OPS_SLL,          // oprnd1 << oprnd2
    ALU_I_OPS_SRL,          // oprnd1 >> oprnd2
    ALU_I_OPS_SRA,          // oprnd1 >>> oprnd2
    ALU_I_OPS_COPY_OPR1,    // Copy operand 1 to ALU output
    ALU_I_OPS_COPY_OPR2     // Copy operand 2 to ALU output
} type_alu_i_ops_e;


typedef enum logic [2:0] {
    ALU_M_OPS_NONE   = '0,   // ALU is idle 
    ALU_M_OPS_MUL    =  3'b100,        // low((oprnd1) * (oprnd2))
    ALU_M_OPS_MULHU  =  3'b101,        // high(oprnd1 * oprnd2)
    ALU_M_OPS_MULHSU =  3'b110,        // high(oprnd1 * (oprnd2))
    ALU_M_OPS_MULH   =  3'b111         // high((oprnd1) * (oprnd2))
} type_alu_m_ops_e;

typedef enum logic [2:0] {
    ALU_D_OPS_NONE   = '0,   // ALU is idle 
    ALU_D_OPS_DIV    =  3'b100,         // oprnd1 s/ oprnd2
    ALU_D_OPS_DIVU   =  3'b101,         // oprnd1 u/ oprnd2
    ALU_D_OPS_REM    =  3'b110,         // oprnd1 s% oprnd2
    ALU_D_OPS_REMU   =  3'b111          // oprnd1 u% oprnd2
} type_alu_d_ops_e;


typedef enum logic [2:0] {
// Operations for conditional branch instructions
    BR_OPS_NONE = '0,   // 
    BR_OPS_EQ,          // oprnd1 = oprnd2 
    BR_OPS_NE,          // oprnd1 != oprnd2
    BR_OPS_GE,          // oprnd1 s>= oprnd2
    BR_OPS_GEU,         // oprnd1 u>= oprnd2
    BR_OPS_LT,          // oprnd1 s< oprnd2
    BR_OPS_LTU          // oprnd1 u< oprnd2
} type_br_ops_e;

// MEM load/store operation types
typedef enum logic [2:0] {
    LD_OPS_NONE = '0,
    LD_OPS_LB,
    LD_OPS_LBU,
    LD_OPS_LH,
    LD_OPS_LHU,
    LD_OPS_LW
} type_ld_ops_e;

typedef enum logic [1:0] {
    ST_OPS_NONE = '0,
    ST_OPS_SB,
    ST_OPS_SH,
    ST_OPS_SW
} type_st_ops_e;

// Writeback source selection for register file 
typedef enum logic [2:0] {
    RD_WRB_NONE = '0,
    RD_WRB_ALU,                           // Writeback ALU result
    RD_WRB_INC_PC,                        // Writeback PC (return address) for JAL/JALR
    RD_WRB_DMEM,                          // Writeback selection for Load operation from DMEM
    RD_WRB_CSR,                           // Writeback for reading CSR
    RD_WRB_D_ALU                          // Writeback from M-Extension for divide
} type_rd_wrb_sel_e;


// System operations including CSR opertions
 typedef enum logic [2:0] {
    SYS_OPS_NONE = '0,
    SYS_OPS_SFENCE_VMA,
    SYS_OPS_SRET,
    SYS_OPS_MRET,
    SYS_OPS_WFI 
} type_sys_ops_e;

// CSR opertions
 typedef enum logic [1:0] {
    CSR_OPS_NONE = '0,
    CSR_OPS_WRITE,
    CSR_OPS_SET,
    CSR_OPS_CLEAR
} type_csr_ops_e;

// CSR operand selection
typedef enum logic {
    CSR_OPR_REG = '0,       // opr = rs1 (register)
    CSR_OPR_IMM             // opr = Immediate value 
} type_csr_opr_sel_e;


//======== Data and control signals among different pairs of communicating modules/stages =========//

// Bus interface from IF to imem  
typedef struct packed {                            
    logic [`XLEN-1:0]                addr;
    logic                            req; 
} type_if2imem_s;

// Bus interface from peripheral device to DBUS
typedef struct packed {                            
    logic [`XLEN-1:0]                r_data;
    logic                            ack;  
} type_imem2if_s;


// Fetch-2-Decode data signals
typedef struct packed {                            
    logic [`XLEN-1:0]                instr;
    logic [`XLEN-1:0]                pc;
    logic [`XLEN-1:0]                pc_next;
    type_exc_code_e                  exc_code;
    logic                            instr_flushed;
} type_if2id_data_s;

// Fetch-2-Decode control signals
typedef struct packed {                            
    logic                            exc_req;
    logic                            irq_req;
} type_if2id_ctrl_s;

// Decode-2-Execute data and control signals
typedef struct packed {                            
    logic [`XLEN-1:0]                rs1_data;     
    logic [`XLEN-1:0]                rs2_data;
    logic [`XLEN-1:0]                instr;
    logic [`XLEN-1:0]                pc;
    logic [`XLEN-1:0]                pc_next;
    logic [`XLEN-1:0]                imm;  
    type_exc_code_e                  exc_code;
    logic                            instr_flushed;   
} type_id2exe_data_s;

typedef struct packed {                           
    type_alu_i_ops_e                 alu_i_ops;
    type_alu_m_ops_e                 alu_m_ops;
    type_alu_d_ops_e                 alu_d_ops;
    type_ld_ops_e                    ld_ops;
    type_st_ops_e                    st_ops;
    type_br_ops_e                    branch_ops;
    type_csr_ops_e                   csr_ops;
    type_amo_ops_e                   amo_ops;
    type_sys_ops_e                   sys_ops;

    type_alu_opr1_sel_e              alu_opr1_sel;
    type_alu_opr2_sel_e              alu_opr2_sel;
    type_alu_cmp_opr2_sel_e          alu_cmp_opr2_sel;
    type_csr_opr_sel_e               csr_opr_sel;
    type_rd_wrb_sel_e                rd_wrb_sel;

    logic                            exc_req;
    logic                            rd_wr_req;
    logic                            jump_req;
    logic                            branch_req;
    logic                            fence_i_req;
    logic                            fence_req;
    logic                            irq_req;
} type_id2exe_ctrl_s;

// Execute-2-Memory data and control signals
typedef struct packed {                            
    logic [`XLEN-1:0]                alu_result;
    logic [`XLEN-1:0]                pc_next;
    logic [`XLEN-1:0]                rs2_data;
} type_exe2lsu_data_s;

typedef struct packed {  
    logic [4:0]                      rd_addr;                         
    type_rd_wrb_sel_e                rd_wrb_sel;
    type_ld_ops_e                    ld_ops;
    type_st_ops_e                    st_ops;
    type_amo_ops_e                   amo_ops;
    logic                            rd_wr_req;
    logic                            jump_req;
    logic                            branch_req;
    logic                            fence_req;
} type_exe2lsu_ctrl_s;


// Execute-2-CSR data and control signals
typedef struct packed {                            
    logic [11:0]                     csr_addr;
    logic [`XLEN-1:0]                pc;
    logic [`XLEN-1:0]                instr;
    logic [`XLEN-1:0]                csr_wdata;  
    type_exc_code_e                  exc_code; 
    logic                            instr_flushed;     
} type_exe2csr_data_s;

typedef struct packed {                           
    type_csr_ops_e                   csr_ops;
    type_sys_ops_e                   sys_ops;
    logic                            exc_req;
    logic                            irq_req;
    logic                            csr_rd_req;
    logic                            csr_wr_req;
    logic                            fence_i_req;
} type_exe2csr_ctrl_s;

// LSU-2-CSR data and control signals
typedef struct packed {                           
    type_ld_ops_e                    ld_ops;
    type_st_ops_e                    st_ops;
    logic                            ld_page_fault;
    logic                            st_page_fault;
    logic                            dcache_flush_ack;  
} type_lsu2csr_ctrl_s;

typedef struct packed {                            
    logic [`XLEN-1:0]                dbus_addr;
    logic [`XLEN-1:0]                pc_next; 
} type_lsu2csr_data_s;

// CSR-2-Writeback data and control signals
typedef struct packed {                            
    logic [`XLEN-1:0]                csr_rdata;     
} type_csr2wrb_data_s;


// Pipeline-2-CSR IRQ signals
typedef struct packed { 
    logic [`XLEN-1:0]                csr_mhartid;                           
    logic [1:0]                      ext_irq;   
    logic                            timer_irq;   
    logic                            soft_irq; 
    logic                            uart_irq;    
} type_pipe2csr_s;


// LSU-2-Writeback data and control signals
typedef struct packed {                            
    logic [`XLEN-1:0]                alu_result;
    logic [`XLEN-1:0]                pc_next;
    logic [`XLEN-1:0]                r_data;  
    logic [`RF_AWIDTH-1:0]           rd_addr; 
} type_lsu2wrb_data_s;

typedef struct packed {                           
    type_rd_wrb_sel_e                rd_wrb_sel;
    logic                            rd_wr_req;
} type_lsu2wrb_ctrl_s;


// Bus interface from LSU to DBUS (data bus)
typedef struct packed {                            
    logic [`XLEN-1:0]                addr;
    logic [`XLEN-1:0]                w_data;
    type_st_ops_e                    st_ops;
    logic                            ld_req;  
    logic                            st_req;  
} type_lsu2dbus_s;

// Bus interface from DBUS to LSU
typedef struct packed {                            
    logic [`XLEN-1:0]                r_data;
    logic                            ack;  
} type_dbus2lsu_s;

// Bus interface from DBUS to peripheral device 
typedef struct packed {                            
    logic [`XLEN-1:0]                addr;
    logic [`XLEN-1:0]                w_data;
    logic [3:0]                      sel_byte;  
    logic                            w_en;  
    logic                            req;
} type_dbus2peri_s;

// Bus interface from peripheral device to DBUS
typedef struct packed {                            
    logic [`XLEN-1:0]                r_data;
    logic                            ack;  
} type_peri2dbus_s;

// Execute-2-Fetch interface feedback signals
typedef struct packed {                            
    logic [`XLEN-1:0]                pc_new;
} type_exe2if_fb_s;

// CSR-2-Fetch interface feedback signals
typedef struct packed {                            
    logic [`XLEN-1:0]                pc_new;
    logic                            icache_flush; 
    logic                            irq_req;
} type_csr2if_fb_s;

// CSR-2-Decode interface feedback signals
typedef struct packed {                            
    type_priv_mode_e                 priv_mode;
} type_csr2id_fb_s;

// Writeback-2-Decode interface feedback signals
typedef struct packed {                            
    logic [`XLEN-1:0]                rd_data;
    logic [`RF_AWIDTH-1:0]           rd_addr;
    logic                            rd_wr_req;  
} type_wrb2id_fb_s;

// LSU-2-Forward_stall interface signals
typedef struct packed {                        
    logic [`RF_AWIDTH-1:0]           rd_addr;
    logic                            rd_wr_req;  
    logic                            lsu_req;
    logic                            lsu_ack;   
} type_lsu2fwd_s;

// Writeback-2-Forward_stall interface signals
typedef struct packed {                            
    logic [`RF_AWIDTH-1:0]           rd_addr;
    logic                            rd_wr_req;    
} type_wrb2fwd_s;

// Execute-2-Forwarding interface signals
typedef struct packed {                            
    logic [`RF_AWIDTH-1:0]           rs1_addr;
    logic [`RF_AWIDTH-1:0]           rs2_addr;
    logic                            new_pc_req;  
    logic                            use_rs1;
    logic                            use_rs2; 
} type_exe2fwd_s;

// CSR-2-Forward interface signals
typedef struct packed {                            
    logic                            new_pc_req; 
    logic                            irq_flush_lsu;
    logic                            wfi_req; 
    logic                            csr_read_req;
} type_csr2fwd_s;

// Forwarding-2-Fetch interface signals
typedef struct packed {  
    logic                            exe_new_pc_req;                            
    logic                            csr_new_pc_req;
    logic                            wfi_req; 
    logic                            if_stall;
} type_fwd2if_s;

// Forwarding-2-Execute interface signals
typedef struct packed {                            
    logic                            fwd_wrb_rs1;
    logic                            fwd_wrb_rs2; 
    logic                            fwd_lsu_rs1;
    logic                            fwd_lsu_rs2; 
} type_fwd2exe_s;

// Forwarding-2-Pipeline top interface signals
typedef struct packed {  
    logic                            if2id_pipe_flush; 
    logic                            if2id_pipe_stall;

    logic                            id2exe_pipe_flush;  
    logic                            id2exe_pipe_stall; 

    logic                            exe2lsu_pipe_stall;
    logic                            exe2lsu_pipe_flush;

    logic                            lsu2wrb_pipe_flush; 

    logic                            pipe_fwd_wrb_rs1; 
    logic                            pipe_fwd_wrb_rs2;                          
} type_fwd2ptop_s;

// Forwarding-2-CSR interface signals
typedef struct packed {  
    logic                            pipe_stall; 
} type_fwd2csr_s;

// Forwarding-2-LSU interface signals
typedef struct packed {  
    logic                            lsu_flush;                           
} type_fwd2lsu_s;

// CSR-2-LSU data signals
typedef struct packed {                            
    logic [`PPN_WIDTH-1:0]           satp_ppn;  
    logic                            en_vaddr;
    logic                            en_ld_st_vaddr;
    logic                            mxr; 
    logic                            lsu_flush;  
    logic                            tlb_flush;
    logic                            dcache_flush;
} type_csr2lsu_data_s;

// Clint-2-CSR machine timer signals
typedef struct packed {                            
    logic [`XLEN-1:0]                timer_val_low;  
    logic [`XLEN-1:0]                timer_val_high;  
} type_clint2csr_s;


typedef struct packed {                            
    logic [`XLEN-1:0]                reg_data;
    logic [`RF_AWIDTH-1:0]           reg_addr;
    logic                            reg_wr_req;  
} type_debug_port_s;


`endif // PCORE_INTERFACE_DEFS

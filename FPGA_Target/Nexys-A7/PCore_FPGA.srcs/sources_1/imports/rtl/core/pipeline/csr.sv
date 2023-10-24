// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The control status registers module implementing 
//              Privileged Architecture Version 1.11.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../../defines/pcore_interface_defs.svh"
`else
`include "pcore_interface_defs.svh"
`endif


module csr (

    input   logic                           rst_n,                    // reset
    input   logic                           clk,                      // clock

    // EXE <---> CSR interface
    input  wire type_exe2csr_data_s         exe2csr_data_i,
    input  wire type_exe2csr_ctrl_s         exe2csr_ctrl_i,            

    // LSU <---> CSR interface
    input  wire type_lsu2csr_data_s         lsu2csr_data_i,
    input  wire type_lsu2csr_ctrl_s         lsu2csr_ctrl_i,
    output type_csr2lsu_data_s              csr2lsu_data_o,

    // CLINT to CSR interface  
    input wire type_clint2csr_s             clint2csr_i,

    // Pipeline <---> CSR interface
    input wire type_pipe2csr_s              pipe2csr_i,

    // CSR <---> WRB interface
    output type_csr2wrb_data_s              csr2wrb_data_o,

    // CSR <---> Forward_stall interface
    input wire type_fwd2csr_s               fwd2csr_i,
    output type_csr2fwd_s                   csr2fwd_o,

    // CSR <---> Decode feedback interface
    output type_csr2id_fb_s                 csr2id_fb_o,

    // CSR <---> Fetch feedback interface
    output type_csr2if_fb_s                 csr2if_fb_o

);


//============================= Local signals and their assignments =============================//
// Interface signals
type_exe2csr_data_s              exe2csr_data;
type_exe2csr_ctrl_s              exe2csr_ctrl;   
type_lsu2csr_data_s              lsu2csr_data;
type_lsu2csr_ctrl_s              lsu2csr_ctrl;
type_csr2lsu_data_s              csr2lsu_data; 
         
type_csr2wrb_data_s              csr2wrb_data;
type_csr2if_fb_s                 csr2if_fb;
type_csr2id_fb_s                 csr2id_fb;
type_csr2fwd_s                   csr2fwd;
type_fwd2csr_s                   fwd2csr;
type_clint2csr_s                 clint2csr;

logic [`XLEN-1:0]                csr_rdata; 
logic [`XLEN-1:0]                csr_wdata;
logic                            csr_rd_exc_req;
logic                            csr_wr_exc_req;
logic                            csr_satp_exc_req;
type_exc_code_e                  csr_rd_exc_code; 
type_exc_code_e                  csr_wr_exc_code; 
logic                            csr_exc_req;
logic                            exc_req;
type_exc_code_e                  exc_code; 
logic                            irq_req_sync;

logic [`XLEN-1:0]                csr_pc_ff, csr_pc_next; 
logic                            pipe_stall_flush;

// CSR cycle, instruction retire and other counter register definitions
logic [`XLEN-1:0]                csr_mcycle_ff,  csr_mcycle_next;
logic [`XLEN-1:0]                csr_mcycleh_ff,  csr_mcycleh_next;
logic [`XLEN-1:0]                csr_minstret_ff,  csr_minstret_next;
logic [`XLEN-1:0]                csr_minstreth_ff,  csr_minstreth_next;
logic [`XLEN-1:0]                csr_mcounteren_ff,  csr_mcounteren_next;
type_mcountinhibit_reg_s         csr_mcountinhibit_ff,  csr_mcountinhibit_next; 

// Machine mode CSRs for trap setup
type_status_reg_s                csr_mstatus_ff,  csr_mstatus_next;
logic [`XLEN-1:0]                csr_medeleg_ff,  csr_medeleg_next;
logic [`XLEN-1:0]                csr_mideleg_ff,  csr_mideleg_next;
type_mie_reg_s                   csr_mie_ff,      csr_mie_next;
type_tvec_reg_s                  csr_mtvec_ff,    csr_mtvec_next;

// Machine mode CSRs for trap handling
logic [`XLEN-1:0]                csr_mscratch_ff, csr_mscratch_next;
logic [`XLEN-1:0]                csr_mepc_ff,     csr_mepc_next;
logic [`XLEN-1:0]                csr_mcause_ff,   csr_mcause_next;
logic [`XLEN-1:0]                csr_mtval_ff,    csr_mtval_next;
type_mip_reg_s                   csr_mip_ff,      csr_mip_next;

// Supervisor mode CSRs for trap setup and handling 
type_tvec_reg_s                  csr_stvec_ff,    csr_stvec_next; 
logic [`XLEN-1:0]                csr_sscratch_ff, csr_sscratch_next;
logic [`XLEN-1:0]                csr_sepc_ff,     csr_sepc_next;
logic [`XLEN-1:0]                csr_scause_ff,   csr_scause_next;
logic [`XLEN-1:0]                csr_stval_ff,    csr_stval_next;
type_satp_reg_s                  csr_satp_ff,     csr_satp_next;
logic [`XLEN-1:0]                csr_scounteren_ff,  csr_scounteren_next;

logic [`XLEN-1:0]                sip_mask;

// Machine mode CSR write update flags for cycle and performance counter registers 
logic                            csr_mcycle_wr_flag;
logic                            csr_mcycleh_wr_flag;
logic                            csr_minstret_wr_flag;
logic                            csr_minstreth_wr_flag;
logic                            csr_mcounteren_wr_flag;
logic                            csr_mcountinhibit_wr_flag;

// Machine mode CSR write update flags for trap setup and handling registers
logic                            csr_mstatus_wr_flag;
logic                            csr_medeleg_wr_flag;
logic                            csr_mideleg_wr_flag;
logic                            csr_mie_wr_flag;
logic                            csr_mtvec_wr_flag;
logic                            csr_mscratch_wr_flag;
logic                            csr_mepc_wr_flag;
logic                            csr_mcause_wr_flag;
logic                            csr_mtval_wr_flag;
logic                            csr_mip_wr_flag;

// Supervisor mode CSR write update flags for trap setup and handling registers
logic                            csr_sstatus_wr_flag;
logic                            csr_sscratch_wr_flag;
logic                            csr_sie_wr_flag;
logic                            csr_stvec_wr_flag;
logic                            csr_sepc_wr_flag;
logic                            csr_scause_wr_flag;
logic                            csr_stval_wr_flag;
logic                            csr_sip_wr_flag;
logic                            csr_satp_wr_flag;
logic                            csr_scounteren_wr_flag;

// Privilge mode definition to keep track of processor state 
type_priv_mode_e                 priv_mode_ff, priv_mode_next; 
type_priv_mode_e                 trap_priv_mode; 
logic                            irq_delegated_req;
logic                            exc_delegated_req;
                  
// IRQ related signals
type_pipe2csr_s                  pipe2csr;
type_irq_code_e                  irq_code; 
logic [`XLEN-1:0]                m_mode_new_pc;
logic [`XLEN-1:0]                s_mode_new_pc;
logic                            m_irq_req;
logic                            s_irq_req;
logic                            irq_req;
logic                            meip_irq_req;
logic                            mtip_irq_req;
logic                            msip_irq_req;
logic                            seip_irq_req;
logic                            stip_irq_req;
logic                            ssip_irq_req;
logic                            uart_irq_req;
logic                            timer_irq_ff;
logic                            ext_irq0_ff, ext_irq1_ff;
//logic                            irq_accept_flag;

// M-mode interrupt/exception related signals
logic                            m_mode_global_ie;
logic                            m_mode_exc_req;
logic                            m_mode_irq_req;
logic                            m_mode_pc_req;
logic                            m_mode_misalign_exc_req;
logic                            m_mode_lsu_pf_exc_req;
logic                            m_mode_ileg_inst_exc_req;
logic                            m_mode_i_pf_exc_req;
logic                            m_mode_break_exc_req;
logic                            ms_mode_ecall_req;
logic                            mret_pc_req;

// S-mode interrupt/exception related signals
logic                            s_mode_global_ie;
logic                            s_mode_exc_req;
logic                            s_mode_irq_req;
logic                            s_mode_pc_req;
logic                            s_mode_enabled;
logic                            s_mode_misalign_exc_req;
logic                            u_mode_ecall_req;
logic                            sret_pc_req;

// Exception requests from MMU
logic                            st_pf_exc_req;
logic                            ld_pf_exc_req;
logic                            i_pf_exc_req;
logic                            lsu_pf_exc_req;
logic                            break_exc_req;

// System operation related signals
logic                            sret_req;
logic                            mret_req;
logic                            sfence_vma_req;
logic                            wfi_req;
logic                            wfi_ff, wfi_next;
logic                            en_ld_st_vaddr_ff, en_ld_st_vaddr_next;

// Load-store related signals
logic [`XLEN-1:0]                ld_st_addr;
type_ld_ops_e                    ld_ops;
type_st_ops_e                    st_ops;
logic                            is_ld_st_ops;
logic                            ld_misalign_exc_req;
logic                            st_misalign_exc_req;

// Performance counter related signals
logic                            csr_mcycle_inc;
logic                            csr_mcycleh_inc;
logic                            csr_minstret_inc;
logic                            csr_minstreth_inc;
logic                            is_not_ebreak;
logic                            is_not_ecall;

// Virtual address generation and icache flush related signals
logic                            satp_mode;
logic                            csr_vaddr_iflush_req;
logic                            icache_flush_req;
logic                            fence_i_req;

// Input signal assignmnets
assign exe2csr_data = exe2csr_data_i;
assign exe2csr_ctrl = exe2csr_ctrl_i; 
assign lsu2csr_data = lsu2csr_data_i;
assign lsu2csr_ctrl = lsu2csr_ctrl_i; 
assign pipe2csr     = pipe2csr_i;
assign fwd2csr      = fwd2csr_i;
assign clint2csr    = clint2csr_i;

// Load store related signals and faults
assign ld_st_addr = lsu2csr_data.dbus_addr;
assign ld_ops     = lsu2csr_ctrl.ld_ops;
assign st_ops     = lsu2csr_ctrl.st_ops;
assign is_ld_st_ops = (|ld_ops) || (|st_ops);

assign ld_misalign_exc_req = ((ld_ops == LD_OPS_LW)  && (|ld_st_addr[1:0])) 
                           | ((ld_ops == LD_OPS_LH)  && (ld_st_addr[0]))
                           | ((ld_ops == LD_OPS_LHU) && (ld_st_addr[0]));

assign st_misalign_exc_req = ((st_ops == ST_OPS_SW)  && (|ld_st_addr[1:0])) 
                           | ((st_ops == ST_OPS_SH)  && (ld_st_addr[0]));

                    
//================================== CSR read operations ==================================//

// CSR read operation
always_comb begin
    csr_rdata  = '0;  
    csr_rd_exc_req = 1'b0;

    if(exe2csr_ctrl.csr_rd_req) begin
        case (exe2csr_data.csr_addr)
            // Machine information registers (read-only)
            CSR_ADDR_MVENDORID      : csr_rdata    = `UETLHR_MVENDORID; 
            CSR_ADDR_MARCHID        : csr_rdata    = `PCORE_MARCHID;
            CSR_ADDR_MIMPID         : csr_rdata    = '0;                     // Not implemented
            CSR_ADDR_MHARTID        : csr_rdata    = pipe2csr.csr_mhartid;

            // Machine mode cycle and performance counter registers
            CSR_ADDR_MCYCLE,
            CSR_ADDR_CYCLE          : csr_rdata    = csr_mcycle_ff;
            CSR_ADDR_MCYCLEH,
            CSR_ADDR_CYCLEH         : csr_rdata    = csr_mcycleh_ff;
            CSR_ADDR_TIME           : csr_rdata    = clint2csr.timer_val_low;
            CSR_ADDR_TIMEH          : csr_rdata    = clint2csr.timer_val_high;
            CSR_ADDR_MINSTRET,
            CSR_ADDR_INSTRET        : csr_rdata    = csr_minstret_ff;
            CSR_ADDR_MINSTRETH,
            CSR_ADDR_INSTRETH       : csr_rdata    = csr_minstreth_ff;
            CSR_ADDR_MCOUNTEREN     : csr_rdata    = csr_mcounteren_ff;
            CSR_ADDR_MCOUNTINHIBIT  : csr_rdata    = csr_mcountinhibit_ff;
            
            CSR_ADDR_MHPMCOUNTER3,
            CSR_ADDR_MHPMCOUNTER3H  : csr_rdata    = '0;                    // Not implemented

            // Read machine mode trap setup registers
            CSR_ADDR_MSTATUS        : csr_rdata    = csr_mstatus_ff;
            CSR_ADDR_MISA           : csr_rdata    = `CSR_MISA;
            CSR_ADDR_MEDELEG        : csr_rdata    = csr_medeleg_ff;
            CSR_ADDR_MIDELEG        : csr_rdata    = csr_mideleg_ff; 
            CSR_ADDR_MIE            : csr_rdata    = csr_mie_ff;
            CSR_ADDR_MTVEC          : csr_rdata    = csr_mtvec_ff;

            // Read machine mode trap handling registers
            CSR_ADDR_MSCRATCH       : csr_rdata    = csr_mscratch_ff;
            CSR_ADDR_MEPC           : csr_rdata    = csr_mepc_ff;
            CSR_ADDR_MCAUSE         : csr_rdata    = csr_mcause_ff;
            CSR_ADDR_MTVAL          : csr_rdata    = csr_mtval_ff;
            CSR_ADDR_MIP            : csr_rdata    = csr_mip_ff;

           // Read supervisor mode trap setup and handling registers
            CSR_ADDR_SSTATUS        : csr_rdata    = (csr_mstatus_ff & SSTATUS_READ_MASK);           
            CSR_ADDR_SIE            : csr_rdata    = csr_mie_ff & SIE_MASK;
            CSR_ADDR_SSCRATCH       : csr_rdata    = csr_sscratch_ff;
            CSR_ADDR_STVEC          : csr_rdata    = csr_stvec_ff;
            CSR_ADDR_SCAUSE         : csr_rdata    = csr_scause_ff;
            CSR_ADDR_STVAL          : csr_rdata    = csr_stval_ff;
            CSR_ADDR_SEPC           : csr_rdata    = csr_sepc_ff;
            CSR_ADDR_SIP            : csr_rdata    = csr_mip_ff & SIP_MASK;
            CSR_ADDR_SCOUNTEREN     : csr_rdata    = csr_scounteren_ff;
            CSR_ADDR_SATP           : begin
                // Reading SATP when in S-Mode and TVM = 1 is not permitted
                if ((priv_mode_ff == PRIV_MODE_S) && csr_mstatus_ff.tvm) begin
                    csr_rd_exc_req  = 1'b1;                   
                end else begin
                    csr_rdata = csr_satp_ff;
                end
            end
            CSR_ADDR_PMPCFG0,
            CSR_ADDR_PMPADDR0,
            CSR_ADDR_PMPADDR1,
            CSR_ADDR_PMPADDR2,
            CSR_ADDR_PMPADDR3       : csr_rdata    = '0;
            
            default                 : begin
                csr_rd_exc_req  = exe2csr_ctrl.csr_rd_req;              
            end
        endcase // exu2csr_data.csr_addr
    end
end

//============================= Prepare for CSR write operations =============================//

always_comb begin
    csr_wr_exc_req             = 1'b0;

    // Flag bits to perform write operation 
    csr_mcycle_wr_flag         = 1'b0;
    csr_mcycleh_wr_flag        = 1'b0;
    csr_minstret_wr_flag       = 1'b0;
    csr_minstreth_wr_flag      = 1'b0;
    csr_mcounteren_wr_flag     = 1'b0;
    csr_mcountinhibit_wr_flag  = 1'b0;


    csr_mstatus_wr_flag        = 1'b0;
    csr_medeleg_wr_flag        = 1'b0;
    csr_mideleg_wr_flag        = 1'b0; 
    csr_mie_wr_flag            = 1'b0;
    csr_mtvec_wr_flag          = 1'b0;
    csr_mscratch_wr_flag       = 1'b0;
    csr_mepc_wr_flag           = 1'b0;
    csr_mcause_wr_flag         = 1'b0;
    csr_mtval_wr_flag          = 1'b0;
    csr_mip_wr_flag            = 1'b0;

    csr_sscratch_wr_flag       = 1'b0;
    csr_sstatus_wr_flag        = 1'b0;
    csr_sie_wr_flag            = 1'b0;
    csr_stvec_wr_flag          = 1'b0;
    csr_sepc_wr_flag           = 1'b0;
    csr_scause_wr_flag         = 1'b0;
    csr_stval_wr_flag          = 1'b0;
    csr_sip_wr_flag            = 1'b0;
    csr_satp_wr_flag           = 1'b0;
    csr_scounteren_wr_flag     = 1'b0;

    if (exe2csr_ctrl.csr_wr_req) begin
        case (exe2csr_data.csr_addr)

            // Machine mode cycle and performance counter registers
            CSR_ADDR_MCYCLE         : csr_mcycle_wr_flag         = 1'b1;
            CSR_ADDR_MCYCLEH        : csr_mcycleh_wr_flag        = 1'b1;
            CSR_ADDR_MINSTRET       : csr_minstret_wr_flag       = 1'b1;
            CSR_ADDR_MINSTRETH      : csr_minstreth_wr_flag      = 1'b1;
            CSR_ADDR_MCOUNTEREN     : csr_mcounteren_wr_flag     = 1'b1;
            CSR_ADDR_MCOUNTINHIBIT  : csr_mcountinhibit_wr_flag  = 1'b1;

            CSR_ADDR_MHPMCOUNTER3,
            CSR_ADDR_MHPMCOUNTER3H  : begin end                       // Not implemented

            // Machine mode flags for trap setup and handling registers write operation
            CSR_ADDR_MSTATUS        : csr_mstatus_wr_flag  = 1'b1;
            CSR_ADDR_MEDELEG        : csr_medeleg_wr_flag  = 1'b1;
            CSR_ADDR_MIDELEG        : csr_mideleg_wr_flag  = 1'b1; 
            CSR_ADDR_MIE            : csr_mie_wr_flag      = 1'b1;
            CSR_ADDR_MTVEC          : csr_mtvec_wr_flag    = 1'b1;
            CSR_ADDR_MISA           : begin end                       // MISA is read only
            CSR_ADDR_MHARTID        : begin end                       // MHARTID is read only

            CSR_ADDR_MSCRATCH       : csr_mscratch_wr_flag = 1'b1;
            CSR_ADDR_MEPC           : csr_mepc_wr_flag     = 1'b1;
            CSR_ADDR_MCAUSE         : csr_mcause_wr_flag   = 1'b1;
            CSR_ADDR_MTVAL          : csr_mtval_wr_flag    = 1'b1;
            CSR_ADDR_MIP            : csr_mip_wr_flag      = 1'b1;                      

            // Supervisor mode flags for trap setup and handling registers write operation
            CSR_ADDR_SSTATUS        : csr_sstatus_wr_flag    = 1'b1;
            CSR_ADDR_SSCRATCH       : csr_sscratch_wr_flag   = 1'b1;
            CSR_ADDR_SIE            : csr_sie_wr_flag        = 1'b1;
            CSR_ADDR_STVEC          : csr_stvec_wr_flag      = 1'b1; 
            CSR_ADDR_SEPC           : csr_sepc_wr_flag       = 1'b1;
            CSR_ADDR_STVAL          : csr_stval_wr_flag      = 1'b1;
            CSR_ADDR_SIP            : csr_sip_wr_flag        = 1'b1;
            CSR_ADDR_SATP           : csr_satp_wr_flag       = 1'b1; 
            CSR_ADDR_SCOUNTEREN     : csr_scounteren_wr_flag = 1'b1;
            
            // PMP configuration (not implemented yet)
            CSR_ADDR_PMPCFG0,
            CSR_ADDR_PMPADDR0,
            CSR_ADDR_PMPADDR1,
            CSR_ADDR_PMPADDR2,
            CSR_ADDR_PMPADDR3       : begin    end 

            default                 : begin
                csr_wr_exc_req  = 1'b1;             
            end
        endcase // exu2csr_data.csr_addr
    end // exe2csr_ctrl.csr_wr_req
end

// Prepare the CSR write data
always_comb begin
    case (exe2csr_ctrl.csr_ops)
        CSR_OPS_WRITE  : csr_wdata =  exe2csr_data.csr_wdata;
        CSR_OPS_SET    : csr_wdata =  exe2csr_data.csr_wdata | csr_rdata;
        CSR_OPS_CLEAR  : csr_wdata = ~exe2csr_data.csr_wdata & csr_rdata;
        default        : csr_wdata = '0;
    endcase
end

// Decode the system instructions 
always_comb begin
sret_req       = 1'b0;
mret_req       = 1'b0;
wfi_req        = 1'b0;
sfence_vma_req = 1'b0;

    case (exe2csr_ctrl.sys_ops)
        SYS_OPS_SRET       : sret_req       = 1'b1;
        SYS_OPS_MRET       : mret_req       = 1'b1;
        SYS_OPS_WFI        : wfi_req        = 1'b1;
        SYS_OPS_SFENCE_VMA : sfence_vma_req = 1'b1;
        default            : begin  end 
    endcase
end 

// Prepare the PC value for exception handling
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_pc_ff <= '0;
    end else begin
        csr_pc_ff <= csr_pc_next;
    end
end

// The current PC is freezed in case of pipeline stall or flush
assign pipe_stall_flush = exe2csr_data.instr_flushed | fwd2csr.pipe_stall;

always_comb begin 
    csr_pc_next = exe2csr_data.pc;

    if (mret_pc_req ) begin
        csr_pc_next = m_mode_new_pc; 
    end else if (sret_pc_req) begin
        csr_pc_next = s_mode_new_pc; 
    end else if (pipe_stall_flush) begin
        csr_pc_next = csr_pc_ff; 
    end else if (wfi_req) begin
        csr_pc_next = lsu2csr_data.pc_next;
    end       
end

//=================== Updating cycle and performance counter registers =====================//
// Update the mcycle (machine cycle counter) CSR 
// ---------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mcycle_ff <= '0;
    end else begin
        csr_mcycle_ff <= csr_mcycle_next;
    end
end 

always_comb begin 

    // Condition to increment the cycle counter
    csr_mcycle_inc = ~csr_mcountinhibit_ff.cy;

    if (csr_mcycle_wr_flag) begin
        csr_mcycle_next = csr_wdata; 
    end else if (csr_mcycle_inc) begin                         
        csr_mcycle_next = csr_mcycle_ff + 1'b1; 
    end else begin
        csr_mcycle_next = csr_mcycle_ff;
    end    
end

// Update the mcycleh (machine cycle high counter) CSR 
// ---------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mcycleh_ff <= '0;
    end else begin
        csr_mcycleh_ff <= csr_mcycleh_next;
    end
end

always_comb begin 

    // Condition to increment the cycle high counter
    csr_mcycleh_inc = (&csr_mcycle_ff) & csr_mcycle_inc;

    if (csr_mcycleh_wr_flag) begin
        csr_mcycleh_next = csr_wdata; 
    end else if (csr_mcycleh_inc) begin                         // MT: check if the enable bit high
        csr_mcycleh_next = csr_mcycleh_ff + 1'b1;  
    end else begin
        csr_mcycleh_next = csr_mcycleh_ff;
    end      
end

// Update the minstret (machine instruction retire counter) CSR 
// ------------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_minstret_ff <= '0;
    end else begin
        csr_minstret_ff <= csr_minstret_next;
    end
end

always_comb begin 

    // Evaluate the condition to increment the instruction retire counter
    is_not_ecall  = ~(exe2csr_data.exc_code[3] & ~exe2csr_data.exc_code[2]);                        
    is_not_ebreak = exe2csr_data.exc_code != EXC_CODE_BREAKPOINT;

    csr_minstret_inc = (~csr_mcountinhibit_ff.ir)      
                     & (~(pipe_stall_flush 
                     | (exc_req & is_not_ecall & is_not_ebreak)));

    if (csr_minstret_wr_flag) begin
        csr_minstret_next = csr_wdata; 
    end else if (csr_minstret_inc) begin                         
        csr_minstret_next = csr_minstret_ff + 1'b1; 
    end else begin
        csr_minstret_next = csr_minstret_ff;
    end    
end

// Update the minstreth (machine instruction retire high counter) CSR 
// ------------------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_minstreth_ff <= '0;
    end else begin
        csr_minstreth_ff <= csr_minstreth_next;
    end
end

always_comb begin 

    // Condition to increment the cycle high counter
    csr_minstreth_inc = (&csr_minstret_ff) & csr_minstret_inc;

    if (csr_minstreth_wr_flag) begin
        csr_minstreth_next = csr_wdata; 
    end else if (csr_minstreth_inc) begin                         // MT: check if the enable bit high
        csr_minstreth_next = csr_minstreth_ff + 1'b1;  
    end else begin
        csr_minstreth_next = csr_minstreth_ff;
    end      
end


// Update the mcounteren (machine counter enable) CSR 
// --------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mcounteren_ff <= '0;
    end else begin
        csr_mcounteren_ff <= csr_mcounteren_next;
    end
end

always_comb begin 
    csr_mcounteren_next = csr_mcounteren_ff; 

    if (csr_mcounteren_wr_flag) begin
        csr_mcounteren_next = csr_wdata; 
    end       
end

// Update the mcountinhibit (machine counter inhibit) CSR 
// ------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mcountinhibit_ff <= '0;
    end else begin
        csr_mcountinhibit_ff <= csr_mcountinhibit_next;
    end
end

always_comb begin 
    csr_mcountinhibit_next = csr_mcountinhibit_ff; 

    if (csr_mcountinhibit_wr_flag) begin
        csr_mcountinhibit_next = csr_wdata; 
    end      
end

//================================ Updating trap setup CSRs ================================//

// Update mstatus/sstatus (machine/supervisor status) CSR and privilege mode
// -------------------------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mstatus_ff <= {`XLEN{1'b0}}; 
        priv_mode_ff   <= PRIV_MODE_M;
    end else begin
        csr_mstatus_ff <= csr_mstatus_next;
        priv_mode_ff   <= priv_mode_next;
    end
end

always_comb begin
    csr_mstatus_next = csr_mstatus_ff;
    priv_mode_next   = priv_mode_ff;

    case (1'b1)
        s_mode_exc_req,
        s_mode_irq_req      : begin
            csr_mstatus_next.sie  = 1'b0;                 // Disable the interrupts
            csr_mstatus_next.spie = csr_mstatus_ff.sie;   // Preserve the previous interrupt enable state
            csr_mstatus_next.spp  = priv_mode_ff[0];      // Save the privilege mode before trap 
            priv_mode_next        = trap_priv_mode;

        end
        m_mode_exc_req,
        m_mode_irq_req      : begin
            csr_mstatus_next.mie  = 1'b0;                 // Disable the interrupts
            csr_mstatus_next.mpie = csr_mstatus_ff.mie;   // Preserve the previous interrupt enable state
            csr_mstatus_next.mpp  = priv_mode_ff;         // Save the privilege mode before trap 
            priv_mode_next        = trap_priv_mode;
        end
        sret_req            : begin
            csr_mstatus_next.sie  = csr_mstatus_ff.spie; // Restore to previous interrupt enable state
            csr_mstatus_next.spie = 1'b1;                // Interrupt was enabled previously
            csr_mstatus_next.spp  = 1'b0;                // Set the previous privilege mode to user mode 
            priv_mode_next        = type_priv_mode_e'({1'b0, csr_mstatus_ff.spp});

        end
        mret_req            : begin
            csr_mstatus_next.mie  = csr_mstatus_ff.mpie; // Restore to previous interrupt enable state
            csr_mstatus_next.mpie = 1'b1;                // Interrupt was enabled previously
            csr_mstatus_next.mpp  = PRIV_MODE_U;         // Set the previous privilege mode to user mode 
            priv_mode_next        = csr_mstatus_ff.mpp;  // Restore the privilege mode

        end
        csr_mstatus_wr_flag : begin  
            csr_mstatus_next = csr_wdata;

        end       
        csr_sstatus_wr_flag : begin
            csr_mstatus_next = (csr_mstatus_ff & ~{SSTATUS_WRITE_MASK}) | {(csr_wdata & SSTATUS_WRITE_MASK)};
        end
        default            : begin        end
    endcase
end

// Update the medeleg (machine exception delegation) CSR 
// -----------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_medeleg_ff <= '0;
    end else begin
        csr_medeleg_ff <= csr_medeleg_next;
    end
end

always_comb begin 
    csr_medeleg_next = csr_medeleg_ff;

    if (csr_medeleg_wr_flag) begin
        csr_medeleg_next = csr_wdata; 
    end      
end

// Update the mideleg (machine interrupt delegation) CSR 
// -----------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mideleg_ff <= '0;
    end else begin
        csr_mideleg_ff <= csr_mideleg_next;
    end
end

always_comb begin 
    csr_mideleg_next = csr_mideleg_ff;

    if (csr_mideleg_wr_flag) begin
        csr_mideleg_next = csr_wdata; 
    end        
end

// Update the mie/sie (machine/supervisor interrupt enable) CSR 
// ------------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mie_ff <= '0;
    end else begin
        csr_mie_ff <= csr_mie_next;
    end
end

// Apply a mask to ensure that only writeable bits are updated.
always_comb begin   
    csr_mie_next = csr_mie_ff;

    if (csr_mie_wr_flag) begin
        csr_mie_next = (csr_wdata & MIE_MASK);  // | (csr_mie_ff & ~MIE_MASK) -- (do we need this)
    end else if (csr_sie_wr_flag) begin
        csr_mie_next = (csr_wdata & csr_mideleg_ff) | (csr_mie_ff & ~csr_mideleg_ff);  
    end 
end


// Update the mtvec (machine trap vector) CSR 
// ------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mtvec_ff <= '0;
    end else begin
        csr_mtvec_ff <= csr_mtvec_next;
    end
end

// Need to ensure that alignment is preserved. For direct mode 4-byte alignment is
// implemented, while for vectored mode we have imposed 64-byte alignment to manage  
// 16 interrupts in vectored mode.
always_comb begin
    csr_mtvec_next = csr_mtvec_ff;

    if(csr_mtvec_wr_flag) begin
        if (csr_wdata[MODE_BIT]) begin   
            csr_mtvec_next = {csr_wdata[(`XLEN-1):CSR_MTVEC_BASE_ALIGN_VECTOR], 
                              {CSR_MTVEC_BASE_ALIGN_VECTOR-1{1'b0}}, csr_wdata[MODE_BIT]}; 
        end else begin
            csr_mtvec_next = {csr_wdata[(`XLEN-1):CSR_MTVEC_BASE_ALIGN_DIRECT], 
                              {CSR_MTVEC_BASE_ALIGN_DIRECT-1{1'b0}}, csr_wdata[MODE_BIT]}; 
        end   
    end 
end


// Update the stvec (supervisor trap vector) CSR 
// ---------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_stvec_ff <= '0;
    end else begin
        csr_stvec_ff <= csr_stvec_next;
    end
end

// Need to ensure that alignment is preserved. The argument for csr_mtvec is also
// applicable to this CSR
always_comb begin
    csr_stvec_next = csr_stvec_ff;

    if(csr_stvec_wr_flag) begin
        if (csr_wdata[MODE_BIT]) begin   
            csr_stvec_next = {csr_wdata[(`XLEN-1):CSR_STVEC_BASE_ALIGN_VECTOR], 
                              {CSR_STVEC_BASE_ALIGN_VECTOR-1{1'b0}}, csr_wdata[MODE_BIT]}; 
        end else begin
            csr_stvec_next = {csr_wdata[(`XLEN-1):CSR_STVEC_BASE_ALIGN_DIRECT], 
                              {CSR_STVEC_BASE_ALIGN_DIRECT-1{1'b0}}, csr_wdata[MODE_BIT]}; 
        end   
    end 
end

//=============================== Update trap handling CSRs ===============================//

// Update the mcause (machine (exception/interrupt) cause) CSR 
// -----------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mcause_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_mcause_ff <= csr_mcause_next;
    end
end

always_comb begin
    csr_mcause_next = csr_mcause_ff;

    case (1'b1)
        m_mode_exc_req     : begin
            csr_mcause_next = {1'b0, {`XLEN-EXC_CODE_WIDTH-1{1'b0}}, exc_code};
        end
        m_mode_irq_req     : begin
            csr_mcause_next = {1'b1, {`XLEN-EXC_CODE_WIDTH-1{1'b0}}, irq_code};
        end
        csr_mcause_wr_flag : begin  
            csr_mcause_next = {csr_wdata[`XLEN-1], {`XLEN-EXC_CODE_WIDTH-1{1'b0}}, csr_wdata[EXC_CODE_WIDTH-1:0]};
        end
        default            : begin        end
    endcase
end

// Update the mepc (machine exception pc) CSR 
// ----------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mepc_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_mepc_ff <= csr_mepc_next;
    end
end

always_comb begin
    csr_mepc_next = csr_mepc_ff;

    case (1'b1)
        m_mode_irq_req   : begin
            csr_mepc_next = csr_pc_next;  // Incase of IRQ use pc+4
        end
        m_mode_exc_req   : begin
            csr_mepc_next = csr_pc_next;
        end
        csr_mepc_wr_flag : begin  
            csr_mepc_next = {csr_wdata[`XLEN-1:2], 2'b00};
        end
        default          : begin        end
    endcase
end


// Update the mip (machine interrupt pending) CSR 
// ----------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mip_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_mip_ff <= csr_mip_next;
    end
end

always_comb begin
    sip_mask = '0;
    csr_mip_next = csr_mip_ff;
    csr_mip_next.meip = ext_irq0_ff;
    csr_mip_next.seip = ext_irq1_ff;
    csr_mip_next.mtip = timer_irq_ff;
    csr_mip_next.msip = '0; // pipe2csr.soft_irq;

    if (csr_mip_wr_flag) begin
        csr_mip_next = (csr_wdata & SIP_MASK) | (csr_mip_ff & ~SIP_MASK);
    end else if (csr_sip_wr_flag) begin
        sip_mask     = SIP_MASK & csr_mideleg_ff;
        csr_mip_next = (csr_wdata & sip_mask) | (csr_mip_ff & ~sip_mask);
    end
end

// Timer interrupt enablement
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        ext_irq0_ff  <= 1'b0;
        ext_irq1_ff  <= 1'b0; 
        timer_irq_ff <= 1'b0; 
    end else begin
        ext_irq0_ff  <= pipe2csr.ext_irq[0];
        ext_irq1_ff  <= pipe2csr.ext_irq[1];
        timer_irq_ff <= pipe2csr.timer_irq;
    end
end

assign irq_req_sync = m_irq_req & m_mode_global_ie;

// Update the mscratch (machine scratch) CSR 
// -----------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mscratch_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_mscratch_ff <= csr_mscratch_next;
    end
end

always_comb begin
    if (csr_mscratch_wr_flag) begin
        csr_mscratch_next = csr_wdata;
    end else begin
        csr_mscratch_next = csr_mscratch_ff;
    end
end


// Update the mtval (machine trap value) CSR 
// -----------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_mtval_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_mtval_ff <= csr_mtval_next;
    end
end

// Make sure the misalign request is in machine mode
assign m_mode_misalign_exc_req  = (m_mode_exc_req) & (ld_misalign_exc_req | st_misalign_exc_req);
assign m_mode_lsu_pf_exc_req    = m_mode_exc_req & lsu_pf_exc_req;
assign m_mode_ileg_inst_exc_req = m_mode_exc_req & csr_exc_req;
assign m_mode_i_pf_exc_req      = m_mode_exc_req & i_pf_exc_req;
assign m_mode_break_exc_req     = m_mode_exc_req & break_exc_req;

always_comb begin
    case (1'b1)
        // MT: Currently implements only for load-store address misalign exceptions. 
        // When faluting exception is trapped, the corresponding virtual address is 
        // captured to mtval CSR.
        m_mode_misalign_exc_req: begin
            csr_mtval_next = lsu2csr_data.dbus_addr;
        end
        m_mode_ileg_inst_exc_req: begin
            csr_mtval_next = exe2csr_data.instr;
        end
        m_mode_lsu_pf_exc_req   : begin
            csr_mtval_next = lsu2csr_data.dbus_addr;
        end
        m_mode_i_pf_exc_req : begin
            csr_mtval_next = csr_pc_next;
        end
        (ms_mode_ecall_req | m_mode_break_exc_req | m_mode_irq_req) : begin
            csr_mtval_next = '0;
        end
        csr_mtval_wr_flag      : begin  
            csr_mtval_next = csr_wdata;
        end
        default                : begin
            csr_mtval_next = csr_mtval_ff;
        end
    endcase
end

// Update the scause (supervisor (exception/interrupt) cause) CSR 
// -----------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_scause_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_scause_ff <= csr_scause_next;
    end
end

always_comb begin
    case (1'b1)
        s_mode_exc_req     : begin
            csr_scause_next = {1'b0, {`XLEN-EXC_CODE_WIDTH-1{1'b0}}, exc_code};
        end
        s_mode_irq_req     : begin
            csr_scause_next = {1'b1, {`XLEN-EXC_CODE_WIDTH-1{1'b0}}, irq_code};
        end
        csr_scause_wr_flag : begin  
            csr_scause_next = {csr_wdata[`XLEN-1], {`XLEN-EXC_CODE_WIDTH-1{1'b0}}, csr_wdata[EXC_CODE_WIDTH-1:0]};
        end
        default            : begin
            csr_scause_next = csr_scause_ff;
        end
    endcase
end

// Update the scounteren (supervisor counter enable) CSR 
// -----------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_scounteren_ff <= '0;
    end else begin
        csr_scounteren_ff <= csr_scounteren_next;
    end
end

always_comb begin 
    csr_scounteren_next = csr_scounteren_ff; 

    if (csr_scounteren_wr_flag) begin
        csr_scounteren_next = csr_wdata; 
    end     
end

// Update the sscratch (supervisor scratch) CSR 
// --------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_sscratch_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_sscratch_ff <= csr_sscratch_next;
    end
end

always_comb begin
    if (csr_sscratch_wr_flag) begin
        csr_sscratch_next = csr_wdata;
    end else begin
        csr_sscratch_next = csr_sscratch_ff;
    end
end

// Update the stval (supervisor trap value) CSR 
// --------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_stval_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_stval_ff <= csr_stval_next;
    end
end

// Make sure the misalign request is in supervisor mode
assign s_mode_misalign_exc_req = exc_delegated_req & (ld_misalign_exc_req | st_misalign_exc_req);

always_comb begin
    case (1'b1)
        // MT: Currently implements only for load-store address misalign and 
        // page fault exceptions. 
        // When faluting exception is trapped, the corresponding virtual address is 
        // captured to stval CSR.
        s_mode_misalign_exc_req: begin
            csr_stval_next = lsu2csr_data.dbus_addr;
        end
        (s_mode_exc_req & lsu_pf_exc_req) : begin
            csr_stval_next = lsu2csr_data.dbus_addr; 
        end
        (s_mode_exc_req & i_pf_exc_req) : begin
            csr_stval_next = csr_pc_next;
        end
        ((s_mode_exc_req & (u_mode_ecall_req | break_exc_req)) | s_mode_irq_req) : begin
            csr_stval_next = '0;
        end
        csr_stval_wr_flag      : begin  
            csr_stval_next = csr_wdata;
        end
        default                : begin
            csr_stval_next = csr_stval_ff;
        end
    endcase
end


// Update the sepc (supervisor exception pc) CSR 
// ----------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_sepc_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_sepc_ff <= csr_sepc_next;
    end
end

always_comb begin

    case (1'b1)
        s_mode_irq_req   : begin
            csr_sepc_next = csr_pc_next;  
        end
        s_mode_exc_req   : begin
            csr_sepc_next = csr_pc_next;
        end
        csr_sepc_wr_flag : begin  
            csr_sepc_next = {csr_wdata[`XLEN-1:2], 2'b00};
        end
        default          : begin
            csr_sepc_next = csr_sepc_ff;
        end
    endcase
end

// Update the satp (supervisor address translation and protection) CSR 
// -------------------------------------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        csr_satp_ff <= {`XLEN{1'b0}}; 
    end else begin
        csr_satp_ff <= csr_satp_next;
    end
end

always_comb begin
    csr_satp_exc_req = 1'b0;
    csr_satp_next = csr_satp_ff;

    // We need to know the mode setting as write to SATP is dependent on the mode
    satp_mode = csr_wdata[31];

    if ((priv_mode_ff == PRIV_MODE_S) && csr_mstatus_ff.tvm) begin
        csr_satp_exc_req = 1'b1;  
    end else if (csr_satp_wr_flag) begin
        csr_satp_next = type_satp_reg_s'(csr_wdata & SATP_ASID_MASK); // Currently no ASID is implemented
        if (~satp_mode) begin   
            csr_satp_next = '0;
        end 
    end 
end


//=============================== Virtual address translation ===============================//
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        en_ld_st_vaddr_ff <= {1'b0}; 
    end else begin
        en_ld_st_vaddr_ff <= en_ld_st_vaddr_next;
    end
end

always_comb begin 
    en_ld_st_vaddr_next = csr2lsu_data.en_vaddr;

    if (csr_mstatus_ff.mprv && (csr_satp_ff.mode == MODE_SV32) && (csr_mstatus_ff.mpp != PRIV_MODE_M)) begin
        en_ld_st_vaddr_next = 1'b1;
    end 
end 

//=============================== System instructions ===============================//

// Wait for interrupt (wfi) instruction 
//-------------------------------------
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        wfi_ff <= 1'b0; 
    end else begin
        wfi_ff <= wfi_next;
    end
end

always_comb begin : wfi
    wfi_next = wfi_ff;

    // If any enabled interrupt becomes pending un-stall the core? Should it be enabled?
    if (irq_req | irq_req_sync) begin
        wfi_next = 1'b0;
    // raise the wait for interrupt flag here
    end else if (wfi_req) begin
        wfi_next = 1'b1;
    end 
end : wfi

//=============================== Interrupt/Exception response ===============================//
// Trap privilege mode
always_comb begin
    trap_priv_mode = PRIV_MODE_M;

    if ((irq_delegated_req || exc_delegated_req) && ~m_mode_exc_req && ~m_mode_irq_req) begin
        trap_priv_mode = (priv_mode_ff == PRIV_MODE_M) ? PRIV_MODE_M : PRIV_MODE_S;
    end 
end

// Exception requests from any source including CSR and earlier stages
assign csr_exc_req     = csr_rd_exc_req | csr_wr_exc_req | csr_satp_exc_req;  
assign ld_pf_exc_req   = lsu2csr_ctrl.ld_page_fault;
assign st_pf_exc_req   = lsu2csr_ctrl.st_page_fault;  
assign lsu_pf_exc_req  = ld_pf_exc_req | st_pf_exc_req;
assign i_pf_exc_req    = exe2csr_ctrl.exc_req & (exe2csr_data.exc_code == EXC_CODE_INST_PAGE_FAULT);

assign exc_req       = exe2csr_ctrl.exc_req | csr_exc_req | lsu_pf_exc_req
                     | ld_misalign_exc_req  | st_misalign_exc_req;

// Exception code corresponding to selected exception, priority is given to earlier exceptions
always_comb begin
    exc_code = EXC_CODE_NO_EXCEPTION;
    case (1'b1)
        exe2csr_ctrl.exc_req : exc_code = exe2csr_data.exc_code;
        csr_exc_req          : exc_code = EXC_CODE_ILLEGAL_INSTR;
        ld_pf_exc_req        : exc_code = EXC_CODE_LD_PAGE_FAULT;
        st_pf_exc_req        : exc_code = EXC_CODE_ST_PAGE_FAULT;
        ld_misalign_exc_req  : exc_code = EXC_CODE_LD_ADDR_MISALIGN;
        st_misalign_exc_req  : exc_code = EXC_CODE_ST_ADDR_MISALIGN;
    endcase
end

// Identifying the IRQ requests in machine mode
assign meip_irq_req = csr_mip_next.meip & csr_mie_ff.meie;
assign mtip_irq_req = csr_mip_next.mtip & csr_mie_ff.mtie;
assign msip_irq_req = csr_mip_next.msip & csr_mie_ff.msie;
// assign uart_irq_req = csr_mip_ff.uart & csr_mie_ff.uart;

assign seip_irq_req = csr_mip_ff.seip & csr_mie_ff.seie;
assign stip_irq_req = csr_mip_ff.stip & csr_mie_ff.stie;
assign ssip_irq_req = csr_mip_ff.ssip & csr_mie_ff.ssie;

assign m_irq_req = meip_irq_req | mtip_irq_req | msip_irq_req;
assign s_irq_req = seip_irq_req | stip_irq_req | ssip_irq_req;
assign irq_req   = exe2csr_ctrl.irq_req | s_irq_req;  // m_irq_req

// IRQ codes for cause register 
always_comb begin
    irq_code = type_irq_code_e'(IRQ_CODE_NONE);
    case (1'b1)
        meip_irq_req: irq_code = type_irq_code_e'(IRQ_CODE_M_EXTERNAL);
        msip_irq_req: irq_code = type_irq_code_e'(IRQ_CODE_M_SOFTWARE);
        mtip_irq_req: irq_code = type_irq_code_e'(IRQ_CODE_M_TIMER);
        seip_irq_req: irq_code = type_irq_code_e'(IRQ_CODE_S_EXTERNAL);
        ssip_irq_req: irq_code = type_irq_code_e'(IRQ_CODE_S_SOFTWARE);
        stip_irq_req: irq_code = type_irq_code_e'(IRQ_CODE_S_TIMER);
    endcase
end

// Signals for machine mode exception/interrupt response generation
assign m_mode_global_ie = ((priv_mode_ff == PRIV_MODE_M) & csr_mstatus_ff.mie) | (priv_mode_ff != PRIV_MODE_M) ; //// to be done
assign m_mode_irq_req   = irq_req && ~irq_delegated_req && m_mode_global_ie ;
assign m_mode_exc_req   = (exc_req && ~exc_delegated_req) || (exc_req && exc_delegated_req && (priv_mode_ff == PRIV_MODE_M));
assign mret_pc_req      = mret_req & ~m_mode_exc_req & ~m_mode_irq_req;

// New pc for machine mode
always_comb begin
    if (mret_pc_req) begin
        m_mode_new_pc = csr_mepc_ff;
    end else begin
        if (csr_mtvec_ff.mode[0]) begin  // vector mode
            case (1'b1)
                m_mode_exc_req: m_mode_new_pc = {csr_mtvec_ff.base, 2'd0};
                m_mode_irq_req: m_mode_new_pc = {csr_mtvec_ff.base[(TVEC_BASE_WIDTH-1):IRQ_CODE_WIDTH], irq_code, 2'd0};
                default       : m_mode_new_pc = {csr_mtvec_ff.base, 2'd0};
            endcase
        end else begin                  // direct mode
            m_mode_new_pc = {csr_mtvec_ff.base, 2'd0};
        end
    end
end


// Signals for supervisor mode exception/interrupt response generation
assign irq_delegated_req = s_irq_req & csr_mideleg_ff[irq_code];
assign exc_delegated_req = exc_req & csr_medeleg_ff[exc_code];

assign s_mode_enabled   = (priv_mode_ff == PRIV_MODE_S);
assign u_mode_ecall_req = (exc_code == EXC_CODE_ECALL_UMODE);
assign break_exc_req    = (exc_code == EXC_CODE_BREAKPOINT);
assign s_mode_exc_req   = exc_delegated_req && (priv_mode_ff != PRIV_MODE_M); //(break_exc_req | pf_exc_req | u_mode_ecall_req) & 


assign s_mode_global_ie = ((priv_mode_ff == PRIV_MODE_S) & csr_mstatus_ff.sie) | (priv_mode_ff == PRIV_MODE_U);
assign s_mode_irq_req   = s_mode_global_ie && irq_delegated_req;
assign sret_pc_req      = sret_req & ~s_mode_exc_req & ~s_mode_irq_req;

// New pc for supervisor mode
always_comb begin
    if (sret_pc_req) begin
        s_mode_new_pc = csr_sepc_ff;
    end else begin
        if (csr_stvec_ff.mode[0]) begin  // vector mode
            case (1'b1)
                s_mode_exc_req: s_mode_new_pc = {csr_stvec_ff.base, 2'd0};
                s_mode_irq_req: s_mode_new_pc = {csr_stvec_ff.base[(TVEC_BASE_WIDTH-1):IRQ_CODE_WIDTH], irq_code, 2'd0};
                default       : s_mode_new_pc = {csr_stvec_ff.base, 2'd0};
            endcase
        end else begin                   // direct mode
            s_mode_new_pc = {csr_stvec_ff.base, 2'd0};
        end
    end
end

// Prepare the new PC for either calling or returning from an interrupt/exception service routine 
// or due to instruction memory fence
assign s_mode_pc_req = sret_pc_req || s_mode_exc_req || s_mode_irq_req;
assign m_mode_pc_req = mret_pc_req || m_mode_exc_req || m_mode_irq_req;

// Instruction cache flush signal 
assign fence_i_req   = exe2csr_ctrl.fence_i_req;
assign icache_flush_req = fence_i_req & lsu2csr_ctrl.dcache_flush_ack;

// New PC value is fed-back to IF module 
assign csr_vaddr_iflush_req = csr_satp_wr_flag | icache_flush_req; // Pipeline flush in case page table base address is updated
// assign csr_virtual_addr_req = csr_satp_next[31] & ~csr_satp_ff[31];
assign csr2if_fb.pc_new    = s_mode_pc_req ? s_mode_new_pc        : m_mode_pc_req 
                                           ? m_mode_new_pc        : csr_vaddr_iflush_req
                                           ? lsu2csr_data.pc_next : csr_pc_next;
assign csr2if_fb.icache_flush = icache_flush_req;
assign csr2if_fb.irq_req = irq_req_sync;

// New PC request signal is sent to forwarding module and is processed along with
// Other PC update requests from other modules (e.g. new PC request from EXE module) 
assign csr2fwd.new_pc_req    = s_mode_pc_req || m_mode_pc_req || csr_vaddr_iflush_req;
assign csr2fwd.irq_flush_lsu = s_mode_irq_req || m_mode_irq_req;
// MT: send the wfi_req, to fetch stage, to stall the pipeline. When an interrupt occurs, the wfi_req
// is cleared and the corresponding ISR is called. Incase global interrupt is not enabled, but the  
// occuring interrupt is individually enabled, even in that case the wfi_req is cleared and execution  
// is resumed at pc+4. This can be noted from the generation of new_pc by the CSR to IF stage in the 
// feedback signal.
assign csr2fwd.wfi_req = wfi_next && ~(s_mode_pc_req || m_mode_pc_req); 

assign csr2fwd.csr_read_req = exe2csr_ctrl.csr_rd_req; 
 
// Prepare the output signal for writeback stage
assign csr2wrb_data.csr_rdata = csr_rdata;

// CSR to LSU signals
assign csr2lsu_data.satp_ppn  = csr_satp_next.ppn;
assign csr2lsu_data.en_vaddr  = (csr_satp_next.mode == MODE_SV32) && (priv_mode_next != PRIV_MODE_M)
                              ? 1'b1 : 1'b0;
assign csr2lsu_data.mxr       = csr_mstatus_ff.mxr; 
assign csr2lsu_data.tlb_flush = sfence_vma_req;
assign csr2lsu_data.lsu_flush = csr2fwd.new_pc_req | csr2fwd.wfi_req; 
assign csr2lsu_data.en_ld_st_vaddr = en_ld_st_vaddr_next;
assign csr2lsu_data.dcache_flush   = fence_i_req;


// CSR to ID feedback signal
assign csr2id_fb.priv_mode = priv_mode_ff;
  
// Update the module output signals
assign csr2wrb_data_o = csr2wrb_data;
assign csr2fwd_o      = csr2fwd;
assign csr2if_fb_o    = csr2if_fb;
assign csr2id_fb_o    = csr2id_fb;
assign csr2lsu_data_o = csr2lsu_data;

endmodule : csr

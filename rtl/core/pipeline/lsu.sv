// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The load/store unit for pipeline to MMU and data cache interface.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../../defines/mmu_defs.svh"
`include "../../defines/a_ext_defs.svh"
`else
`include "mmu_defs.svh"
`include "a_ext_defs.svh"
`endif

module lsu (

    input   logic                           rst_n,                    // reset
    input   logic                           clk,                      // clock

    // EXE <---> LSU interface
    input  wire type_exe2lsu_data_s         exe2lsu_data_i,
    input  wire type_exe2lsu_ctrl_s         exe2lsu_ctrl_i,            // Structure for control signals from execute to memory 

    // LSU <---> CSR interface
    input wire type_csr2lsu_data_s          csr2lsu_data_i,
    output type_lsu2csr_data_s              lsu2csr_data_o,
    output type_lsu2csr_ctrl_s              lsu2csr_ctrl_o,

    // AMO <---> LSU interface
    input  wire type_amo2lsu_data_s         amo2lsu_data_i, 
    input  wire type_amo2lsu_ctrl_s         amo2lsu_ctrl_i,              
    output type_lsu2amo_data_s              lsu2amo_data_o,
    output type_lsu2amo_ctrl_s              lsu2amo_ctrl_o,

    // LSU <---> WRB interface
    output type_lsu2wrb_data_s              lsu2wrb_data_o,
    output type_lsu2wrb_ctrl_s              lsu2wrb_ctrl_o,

    // LSU <---> EXE interface for feedback signals
    output logic [`XLEN-1:0]                lsu2exe_fb_alu_result_o,

    // LSU <---> Forward_stall interface for forwarding
    output type_lsu2fwd_s                   lsu2fwd_o,
    input wire type_fwd2lsu_s               fwd2lsu_i,

    // LSU <---> Data Bus (dbus) interface
    input  wire type_dbus2lsu_s             dbus2lsu_i,
    output type_lsu2dbus_s                  lsu2dbus_o,                // Signal to data bus 
    output logic                            dcache_flush_o,
    output logic                            lsu_flush_o,

    // LSU <---> MMU interface 
    input wire type_mmu2lsu_s               mmu2lsu_i, 
    output type_lsu2mmu_s                   lsu2mmu_o 

);

//============================= Local signals and their assignments =============================//
// Local signals
type_exe2lsu_data_s          exe2lsu_data;
type_exe2lsu_ctrl_s          exe2lsu_ctrl;
type_lsu2wrb_data_s          lsu2wrb_data;
type_lsu2wrb_ctrl_s          lsu2wrb_ctrl;
type_lsu2dbus_s              lsu2dbus;
type_dbus2lsu_s              dbus2lsu;
type_lsu2csr_data_s          lsu2csr_data;
type_lsu2csr_ctrl_s          lsu2csr_ctrl;
type_csr2lsu_data_s          csr2lsu_data;

type_amo2lsu_data_s          amo2lsu_data;
type_amo2lsu_ctrl_s          amo2lsu_ctrl;
type_lsu2amo_data_s          lsu2amo_data;
type_lsu2amo_ctrl_s          lsu2amo_ctrl;

type_lsu2fwd_s               lsu2fwd;
type_lsu2mmu_s               lsu2mmu;
type_mmu2lsu_s               mmu2lsu;

logic [`XLEN-1:0]            ld_st_addr;
logic [`XLEN-1:0]            rdata_word;
logic [15:0]                 rdata_hword;
logic [7:0]                  rdata_byte;
logic                        ld_req;
type_ld_ops_e                ld_ops;
logic                        st_req;
logic                        is_amo;
logic                        dcache_flush_req;

// Signals for LSU request/response                                                          
logic                        lsu_amo_req;
logic                        lsu_amo_ack; 

// Signal assignments
assign exe2lsu_data  = exe2lsu_data_i;
assign exe2lsu_ctrl  = exe2lsu_ctrl_i;
assign dbus2lsu      = dbus2lsu_i;
assign csr2lsu_data  = csr2lsu_data_i;
assign mmu2lsu       = mmu2lsu_i;

assign amo2lsu_data  = amo2lsu_data_i;
assign amo2lsu_ctrl  = amo2lsu_ctrl_i;

// Prepare the signals to perform load/store operations      
assign ld_ops        = exe2lsu_ctrl.ld_ops;

// AMO related signals
assign is_amo        = |(exe2lsu_ctrl.amo_ops);

//=================================== Memory load operation =====================================//
// Extract the right size from the read data  
always_comb begin
   rdata_byte  = '0;
   rdata_hword = '0;
   rdata_word  = '0;

   case (ld_ops)
      LD_OPS_LB,
      LD_OPS_LBU : begin
         case (lsu2dbus.addr[1:0]) 
            2'b00 : begin 
               rdata_byte = dbus2lsu.r_data[7:0]; 
            end 
            2'b01 : begin
               rdata_byte = dbus2lsu.r_data[15:8];
            end
            2'b10 : begin
               rdata_byte = dbus2lsu.r_data[23:16];
            end
            2'b11 : begin
               rdata_byte = dbus2lsu.r_data[31:24];
            end
            default : begin    
            end  
         endcase
      end // LD_OPS_LB, LD_OPS_LBU 
      LD_OPS_LH,
      LD_OPS_LHU : begin 
         case (lsu2dbus.addr[1]) 
            1'b0 : begin
               rdata_hword = dbus2lsu.r_data[15:0];
            end 
            1'b1 : begin
               rdata_hword = dbus2lsu.r_data[31:16];
            end
            default : begin    
            end  
         endcase
      end // LD_OPS_LH, LD_OPS_LHU
      LD_OPS_LW : begin
         rdata_word = dbus2lsu.r_data;
      end
      default : begin
      end
   endcase // ld_ops
end


// Extend the load data for sign/zero
always_comb begin
    lsu2wrb_data.r_data = '0;
   
    if (amo2lsu_ctrl.amo_done) begin                               // A-extension response               
        lsu2wrb_data.r_data = amo2lsu_data.amo_wrb_data;        
    end else if (dbus2lsu.ack) begin                  // Normal load operation
        case (ld_ops)
            LD_OPS_LB  : lsu2wrb_data.r_data = {{24{rdata_byte[7]}},   rdata_byte};
            LD_OPS_LBU : lsu2wrb_data.r_data = { 24'b0,                rdata_byte};
            LD_OPS_LH  : lsu2wrb_data.r_data = {{16{rdata_hword[15]}}, rdata_hword};
            LD_OPS_LHU : lsu2wrb_data.r_data = { 16'b0,                rdata_hword};
            LD_OPS_LW  : lsu2wrb_data.r_data = {                       rdata_word};
            default    : lsu2wrb_data.r_data = '0;
        endcase // ld_ops
    end 
end


always_comb begin

    if (is_amo) begin 
        ld_req                  = amo2lsu_ctrl.ld_req; 
        st_req                  = amo2lsu_ctrl.st_req;
        lsu2dbus.w_data         = amo2lsu_data.w_data;
        lsu2wrb_ctrl.rd_wr_req  = amo2lsu_ctrl.rd_wr_req;
    end else begin
        ld_req                  = |ld_ops; 
        st_req                  = |(exe2lsu_ctrl.st_ops);
        lsu2dbus.w_data         = exe2lsu_data.rs2_data;
        lsu2wrb_ctrl.rd_wr_req  = exe2lsu_ctrl.rd_wr_req;
    end
end

//=================================== Output signals update =====================================//

assign ld_st_addr = exe2lsu_data.alu_result;

// Feedback signals to EXE module
assign lsu2exe_fb_alu_result_o = exe2lsu_data.alu_result; 

// Update data for CSR module
assign lsu2csr_data.pc_next   = exe2lsu_data.pc_next;
assign lsu2csr_data.dbus_addr = ld_st_addr;

// Update control signals for CSR module
assign lsu2csr_ctrl.ld_ops = exe2lsu_ctrl.ld_ops;
assign lsu2csr_ctrl.st_ops = exe2lsu_ctrl.st_ops;

assign lsu2csr_ctrl.ld_page_fault = mmu2lsu.ld_page_fault;
assign lsu2csr_ctrl.st_page_fault = mmu2lsu.st_page_fault;
assign lsu2csr_ctrl.dcache_flush_ack = dbus2lsu.ack;

// Update signals for AMO module
assign lsu2amo_ctrl.amo_ops       = exe2lsu_ctrl.amo_ops;
assign lsu2amo_ctrl.is_amo        = is_amo;
assign lsu2amo_ctrl.amo_flush     = fwd2lsu_i.lsu_flush;
assign lsu2amo_ctrl.ack           = dbus2lsu.ack;

assign lsu2amo_data.lsu_addr      = ld_st_addr;
assign lsu2amo_data.rs2_operand   = exe2lsu_data.rs2_data;
assign lsu2amo_data.r_data        = dbus2lsu.r_data;

// Update signals for writeback  
assign lsu2wrb_data.alu_result    = exe2lsu_data.alu_result;  
assign lsu2wrb_data.pc_next       = exe2lsu_data.pc_next;
assign lsu2wrb_data.rd_addr       = exe2lsu_ctrl.rd_addr;               

// Update control signals for writeback
// If instruction is SC, then write back control signals will be updated to propagate 1 or 0 into rd
assign lsu2wrb_ctrl.rd_wrb_sel = exe2lsu_ctrl.rd_wrb_sel;

// Signals for forwarding module
assign lsu2fwd.rd_addr   = exe2lsu_ctrl.rd_addr; 
assign lsu2fwd.rd_wr_req = exe2lsu_ctrl.rd_wr_req;       // For SC, forwarding loop will also be updated

assign dcache_flush_req = exe2lsu_ctrl.fence_req | csr2lsu_data.dcache_flush;
assign lsu_amo_req = ld_req | st_req | is_amo | dcache_flush_req;

// Ack will be based on amo_done in case of amo_instruction
assign lsu_amo_ack = is_amo ? amo2lsu_ctrl.amo_done : dbus2lsu.ack;    

assign lsu2fwd.lsu_req = lsu_amo_req;
assign lsu2fwd.lsu_ack = lsu_amo_ack;

// Signals to data memory interface
assign lsu2dbus.addr   = mmu2lsu.d_paddr[`XLEN-1:0]; 
assign lsu2dbus.ld_req = ld_req & (mmu2lsu.d_hit);
assign lsu2dbus.st_req = st_req & (mmu2lsu.d_hit);
// MT: assign lsu2dbus.w_data = exe2lsu_data.rs2_data;
assign lsu2dbus.st_ops = exe2lsu_ctrl.st_ops;

// Signals for MMU
assign lsu2mmu.satp_ppn       = csr2lsu_data.satp_ppn;
assign lsu2mmu.en_vaddr       = csr2lsu_data.en_vaddr;
assign lsu2mmu.en_ld_st_vaddr = csr2lsu_data.en_ld_st_vaddr;
assign lsu2mmu.mxr            = csr2lsu_data.mxr;
assign lsu2mmu.tlb_flush      = csr2lsu_data.tlb_flush;

assign lsu2mmu.lsu_flush      = fwd2lsu_i.lsu_flush;
assign lsu2mmu.d_req          = ld_req | st_req;
assign lsu2mmu.st_req         = st_req;
assign lsu2mmu.is_amo         = is_amo;
assign lsu2mmu.d_vaddr        = ld_st_addr;

// Update the output signals with proper assignment
assign dcache_flush_o = dcache_flush_req;
assign lsu_flush_o    = fwd2lsu_i.lsu_flush;

assign lsu2csr_data_o = lsu2csr_data;
assign lsu2csr_ctrl_o = lsu2csr_ctrl;
assign lsu2wrb_data_o = lsu2wrb_data;
assign lsu2wrb_ctrl_o = lsu2wrb_ctrl;
assign lsu2amo_data_o = lsu2amo_data;   
assign lsu2amo_ctrl_o = lsu2amo_ctrl;

assign lsu2dbus_o     = lsu2dbus; 
assign lsu2fwd_o      = lsu2fwd;
assign lsu2mmu_o      = lsu2mmu;

endmodule : lsu

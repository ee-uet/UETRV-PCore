// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The pipeline controller module.
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../../defines/m_ext_defs.svh"
`else
`include "m_ext_defs.svh"
`endif


module forward_stall (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // Writeback <---> Forward_stall interface signals
    input wire type_wrb2fwd_s             wrb2fwd_i,

    // Memory <---> Forward_stall interface signals
    input wire type_lsu2fwd_s             lsu2fwd_i,

    // M-extension <---> Forward_stall interface signals
    input wire type_mul2fwd_s             mul2fwd_i,
    
    // EXE/CSR <---> Forward_stall interface signals
    input wire type_exe2fwd_s             exe2fwd_i,  
    input wire type_csr2fwd_s             csr2fwd_i,

    // Fetch <---> Forward_stall interface signals
    input wire                            if2fwd_stall_i,

    // Output signals from forward to different modules
    output type_fwd2if_s                  fwd2if_o,
    output type_fwd2exe_s                 fwd2exe_o,
    output type_fwd2csr_s                 fwd2csr_o,
    output type_fwd2lsu_s                 fwd2lsu_o,
    output type_fwd2ptop_s                fwd2ptop_o
);

//============================= Local signals and their assignments =============================//
 
type_lsu2fwd_s                       lsu2fwd;
type_wrb2fwd_s                       wrb2fwd;
type_exe2fwd_s                       exe2fwd;
type_csr2fwd_s                       csr2fwd;
type_mul2fwd_s                       mul2fwd;

logic                                rs1_valid;
logic                                rs2_valid;
logic                                lsu2rs1_hazard;
logic                                lsu2rs2_hazard;
logic                                ld_use_rs1_hazard;
logic                                ld_use_rs2_hazard;
logic                                ld_use_hazard;
logic                                lsu_mul_csr_req;

logic                                if_id_exe_stall;
logic                                lsu_mul_stall;
logic                                lsu_flush;

logic                                lsu_stall_ff;
logic                                lsu_stall_next;
logic                                mul_stall_ff;
logic                                mul_stall_next;
logic                                lsu_mul_stall_ff;

logic                                id_exe_flush;
logic                                exe_new_pc_req;

logic                                if2fwd_stall;

// Signal outputs to different modules
type_fwd2if_s                        fwd2if;
type_fwd2exe_s                       fwd2exe;
type_fwd2csr_s                       fwd2csr;
type_fwd2lsu_s                       fwd2lsu;
type_fwd2ptop_s                      fwd2ptop;                                                                

// Instantiate the local signals from inputs
assign lsu2fwd = lsu2fwd_i;
assign wrb2fwd = wrb2fwd_i;                          
assign exe2fwd = exe2fwd_i; 
assign csr2fwd = csr2fwd_i;
assign mul2fwd = mul2fwd_i;

assign if2fwd_stall = if2fwd_stall_i;  

// Check the validity of the source operands from EXE stage
assign rs1_valid = |exe2fwd.rs1_addr;  
assign rs2_valid = |exe2fwd.rs2_addr;                     

// Hazard detection
assign lsu2rs1_hazard = ((exe2fwd.rs1_addr == lsu2fwd.rd_addr) & lsu2fwd.rd_wr_req) & rs1_valid;
assign lsu2rs2_hazard = ((exe2fwd.rs2_addr == lsu2fwd.rd_addr) & lsu2fwd.rd_wr_req) & rs2_valid;

// Is it load, CSR or M-Extension operation
assign lsu_mul_csr_req = lsu2fwd.lsu_req | mul2fwd.mul_req | csr2fwd.csr_read_req;

// Generate the forwarding signals from LSU and writeback stages. The load-use RAW hazard
// can not be resolved by forwarding from LSU-2-execute stage. Rather one cycle stall is
// generated and the data read using DBUS is forwarded from writeback stage to execute
// stage to resolve the hazard. 
assign fwd2exe.fwd_lsu_rs1 = lsu2rs1_hazard & (~lsu_mul_csr_req); 
assign fwd2exe.fwd_lsu_rs2 = lsu2rs2_hazard & (~lsu_mul_csr_req); 
     
assign fwd2exe.fwd_wrb_rs1 = ((exe2fwd.rs1_addr == wrb2fwd.rd_addr) & wrb2fwd.rd_wr_req) & rs1_valid; 
assign fwd2exe.fwd_wrb_rs2 = ((exe2fwd.rs2_addr == wrb2fwd.rd_addr) & wrb2fwd.rd_wr_req) & rs2_valid; 

// Load, CSR or M-Extension hazard detection
assign ld_use_rs1_hazard = lsu2rs1_hazard & exe2fwd.use_rs1 & (lsu_mul_csr_req);
assign ld_use_rs2_hazard = lsu2rs2_hazard & exe2fwd.use_rs2 & (lsu_mul_csr_req);
assign ld_use_hazard     = (ld_use_rs1_hazard | ld_use_rs2_hazard) & ~lsu_mul_stall;

// New PC request from EXE stage is only processed when there is neither data hazard for the
// instruction in EXE stage due to operand dependency on the data from LSU stage, nor there is 
// a stall from LSU stage   
assign exe_new_pc_req = exe2fwd.new_pc_req & ~(ld_use_hazard | lsu_mul_stall);  

// Pipeline flush signals for different pipeline stages/modules 
assign id_exe_flush                = exe_new_pc_req | csr2fwd.new_pc_req | csr2fwd.wfi_req;
assign lsu_flush                   = csr2fwd.new_pc_req | csr2fwd.wfi_req;   
assign fwd2lsu.lsu_flush           = lsu_flush; 

assign fwd2ptop.if2id_pipe_flush   = id_exe_flush;
assign fwd2ptop.id2exe_pipe_flush  = id_exe_flush;
assign fwd2ptop.exe2lsu_pipe_flush = ld_use_hazard | lsu_flush; 
assign fwd2ptop.lsu2wrb_pipe_flush = csr2fwd.irq_flush_lsu;

// Pipeline stall signals for different ppeline stages/modules 
assign lsu_mul_stall               = lsu_stall_next | mul_stall_next;
assign if_id_exe_stall             = ld_use_hazard | lsu_mul_stall; 
 
assign fwd2ptop.if2id_pipe_stall   = if_id_exe_stall;
assign fwd2ptop.id2exe_pipe_stall  = if_id_exe_stall;
assign fwd2ptop.exe2lsu_pipe_stall = lsu_mul_stall;

assign fwd2ptop.pipe_fwd_wrb_rs1   = fwd2exe.fwd_wrb_rs1;
assign fwd2ptop.pipe_fwd_wrb_rs2   = fwd2exe.fwd_wrb_rs2;

assign fwd2csr.pipe_stall          = lsu_mul_stall_ff;

// Generate different PC update or stall signals for IF stage
assign fwd2if.exe_new_pc_req = exe_new_pc_req & (~csr2fwd.new_pc_req);
assign fwd2if.csr_new_pc_req = csr2fwd.new_pc_req;
assign fwd2if.wfi_req        = csr2fwd.wfi_req;
assign fwd2if.if_stall       = if_id_exe_stall;

// LSU related stall signal using the 'ack' from lsu module
always_ff @(posedge clk) begin
    if (~rst_n | lsu_flush) begin
        lsu_stall_ff <= '0;
    end else begin
        lsu_stall_ff <= lsu_stall_next;
    end
end

always_comb begin 
    lsu_stall_next = lsu_stall_ff; 

    if (lsu2fwd.lsu_ack ) begin
        lsu_stall_next = 1'b0;
    end else if (lsu2fwd.lsu_req) begin                         
        lsu_stall_next = 1'b1; 
    end        
end

// M-extension related stall signal  
always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n | lsu_flush) begin
        mul_stall_ff <= '0;
    end else begin
        mul_stall_ff <= mul_stall_next;
    end
end

always_comb begin
    mul_stall_next = mul_stall_ff; 

    if (mul2fwd.mul_ack) begin
        mul_stall_next = 0;
    end else if (mul2fwd.mul_req) begin                         
        mul_stall_next = 1'b1; 
    end   
end

always_ff @(posedge clk) begin
    if (~rst_n) begin
        lsu_mul_stall_ff <= '0;
    end else begin
        lsu_mul_stall_ff <= lsu_mul_stall;
    end
end

// Update the module output signals
assign fwd2if_o   = fwd2if;
assign fwd2exe_o  = fwd2exe; 
assign fwd2csr_o  = fwd2csr; 
assign fwd2lsu_o  = fwd2lsu; 
assign fwd2ptop_o = fwd2ptop;     

endmodule : forward_stall


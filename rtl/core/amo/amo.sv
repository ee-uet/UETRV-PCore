/*********************************************************************
 * Filename :    amo.sv
 * Date     :    05-10-2022
 * Author   :    
 * Written by Dr. Muhammad Tahir
 *
 * Description:  AMO module to execute atomic instructions.
                This module handle atomic request from core.
 *********************************************************************/
`define XLEN    32




/*
clk_i: 



*/
module atomic_unit
(
    input                 clk_i,
    input                 rst_i,
    input  [`XLEN-1 : 0]  core_addr_i,
    input                 core_rw_i,
    input  [`XLEN-1 : 0]  core_data_i,
    output                core_done_o,
    output [`XLEN-1 : 0]  core_data_o,
    input                 core_is_amo_i,
    input  [ 4 : 0]       core_amo_type_i,

    output [`XLEN-1 : 0]  M_DMEM_addr_o,
    output                M_DMEM_rw_o,
    output [`XLEN-1 : 0]  M_DMEM_data_o,
    input                 M_DMEM_done_i,
    input  [`XLEN-1 : 0]  M_DMEM_data_i
);

localparam Bypass           = 0,
           AmoRd            = 1,
           AmoWr            = 2,
           AmoFinish        = 3,
           AmoWaitCohere    = 4,
           Lr               = 5;

//====================================================
// Signals
//====================================================
logic  [`XLEN-1 : 0]    m_data;

// FSM
logic  [ 2 : 0]          state;
logic  [ 2 : 0]          state_next;

// LR/SC
logic  sc_fail=0;

// type
logic is_lr;
logic is_sc;

assign is_lr = (core_amo_type_i[1:0] == 2'b10);
assign is_sc = (core_amo_type_i[1:0] == 2'b11);

// amo to memory signals
//logic [`XLEN-1 : 0]     amo_addr;
logic                   amo_rw;
logic                   amo_done;
logic [`XLEN-1 : 0]     amo_data2core;
logic [`XLEN-1 : 0]     amo_data2mem;

// amo alu
logic [ 4 : 0]     op;
logic [`XLEN-1 : 0] rs1;   // from memory
logic [`XLEN-1 : 0] rs2;   // from core
logic  [`XLEN-1 : 0] result;


//====================================================
// Logic
//====================================================
// Finite State Machine
always @(posedge clk_i)
begin
    if (rst_i)
        state <= Bypass;
    else
        state <= state_next;
end

always @(*) begin
    case (state)
        Bypass:
            if (core_is_amo_i)
                if (is_sc & sc_fail)
                    state_next = AmoFinish;
                else
                    state_next = AmoRd;
            else
                state_next = Bypass;
        AmoRd:
            if (M_DMEM_done_i)
                if(is_lr)
                    state_next = AmoFinish;
                else
                    state_next = AmoWr;
            else
                state_next = AmoRd;
        AmoWr:
            if (M_DMEM_done_i)
                state_next = AmoFinish;
            else
                state_next = AmoWr;
        AmoFinish:
            state_next = Bypass;
        default: 
            state_next = Bypass;
    endcase
end

// buffer memory data
always @(posedge clk_i ) begin
    if (state == AmoRd)
        m_data <= M_DMEM_data_i;
end

// LR/SC logic
//integer i;

// amo alu signal
assign rs1         = m_data[`XLEN-1:0];
assign rs2         = core_data_i[`XLEN-1:0];
assign op          = core_amo_type_i;

// amo signal
assign amo_rw        = (state == AmoWr);
assign amo_data2core = is_sc ? sc_fail : result;
assign amo_data2mem  = result;
assign amo_done      = (state == AmoFinish);

// I/O
assign M_DMEM_addr_o    = core_addr_i;
assign M_DMEM_rw_o      = core_is_amo_i ? amo_rw        : core_rw_i;
assign M_DMEM_data_o    = core_is_amo_i ? amo_data2mem  : core_data_i;
assign core_done_o      = core_is_amo_i ? amo_done      : M_DMEM_done_i;
assign core_data_o      = core_is_amo_i ? amo_data2core : M_DMEM_data_i;

//====================================================
// Atomic Instructions ALU
//====================================================
//
localparam [4:0] SWAP = 5'b00001,
                 ADD  = 5'b00000,
                 XOR  = 5'b00100,
                 AND  = 5'b01100,
                 OR   = 5'b01000,
                 MIN  = 5'b10000,
                 MAX  = 5'b10100,
                 MINU = 5'b11000,
                 MAXU = 5'b11100,
                 SC   = 5'b00011;

logic               rs1_SLT_rs2;
logic signed [32:0] rs1_ext;
logic signed [32:0] rs2_ext;

//bit 4 of op_i for unsigned
assign rs1_ext = {(~op[3] & rs1[31]), rs1};
assign rs2_ext = {(~op[3] & rs2[31]), rs2};
assign rs1_SLT_rs2 = rs1_ext < rs2_ext;

always @(*) begin
    case (op)
        SC  : result = rs2;
        SWAP: result = rs2;
        ADD : result = rs1 + rs2;
        XOR : result = rs1 ^ rs2;
        AND : result = rs1 & rs2;
        OR  : result = rs1 | rs2;
        MIN : result = rs1_SLT_rs2 ? rs1 : rs2;
        MAX : result = rs1_SLT_rs2 ? rs2 : rs1;
        MINU: result = rs1_SLT_rs2 ? rs1 : rs2;
        MAXU: result = rs1_SLT_rs2 ? rs2 : rs1;
        default: result = rs2;
    endcase
end

endmodule

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

`default_nettype wire

module pipeline_top (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

   // IMEM interface
//    input   logic                      imem2if_resp_i,         // Instruction memory request acknowledgement
    output  logic                        if2imem_req_o,             // Instruction memory request
    output  logic [`XLEN-1:0]            if2imem_addr_o,            // Instruction memory address
    input   logic [`XLEN-1:0]            imem2if_rdata_i,           // Instruction memory read data

   // DMEM interface
    output type_signal_to_dmem_s         ptop2dmem_o,                // Signal to data memory 
    input  wire type_signal_from_dmem_s  dmem2ptop_i 
);


// Local signals
logic                                   if2imem_req;             // Instruction memory request
logic [`XLEN-1:0]                       if2imem_addr;            // Instruction memory address
logic [`XLEN-1:0]                       imem2if_rdata;           // Instruction memory read data

logic                                   id2if_rdy;             // Instruction memory request
logic [`XLEN-1:0]                       if2id_instr;            // Instruction 
logic [`XLEN-1:0]                       if2id_pc;            // PC

logic [`XLEN-1:0]                       id2exe_rs1_data;
logic [`XLEN-1:0]                       id2exe_rs2_data;

type_id2exe_ctrl_s                      id2exu_ctrl;
type_id2exe_data_s                      id2exu_data;

type_exe2mem_ctrl_s                     exe2mem_ctrl;
type_exe2mem_data_s                     exe2mem_data;

type_signal_to_dmem_s                   mem2dmem;               // Signal to data memory 
type_signal_from_dmem_s                 dmem2mem; 

type_mem2wb_ctrl_s                      mem2wb_ctrl;
type_mem2wb_data_s                      mem2wb_data;

logic                                   wb2id_rd_wr_req;
logic [`RF_AWIDTH-1:0]                  wb2id_rd_addr;
logic [`XLEN-1:0]                       wb2id_rd_data;
    

// Instruction Fetch module instantiation
fetch fetch_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IF module interface signals 
    .if2imem_req_o       (if2imem_req),
    .if2imem_addr_o      (if2imem_addr),
    .imem2if_rdata_i     (imem2if_rdata),
    .if2id_instr_o       (if2id_instr),
    .if2id_pc_o          (if2id_pc),
    .id2if_rdy_i         (id2if_rdy)
);

// Instruction Decode module instantiation
decode decode_module (
    .rst_n               (rst_n),
    .clk                 (clk),

    // ID module interface signals 
    .if2id_instr_i       (if2id_instr),
    .if2id_pc_i          (if2id_pc),
    .id2if_rdy_o         (id2if_rdy ),
    .id2exu_ctrl_o       (id2exu_ctrl),
    .id2exu_data_o       (id2exu_data),
    .wb2id_rd_wr_req_i   (wb2id_rd_wr_req),
    .wb2id_rd_addr_i     (wb2id_rd_addr),
    .wb2id_rd_data_i     (wb2id_rd_data)
);


// Instruction Execute module instantiation
execute execute_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Decode module interface signals 
    .id2exu_ctrl_i        (id2exu_ctrl),
    .id2exu_data_i        (id2exu_data),

    // Memory module interface signals
    .exe2mem_ctrl_o       (exe2mem_ctrl),
    .exe2mem_data_o       (exe2mem_data)
);

// Data Memory module instantiation
memory memory_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Execution module interface signals
    .exe2mem_ctrl_i       (exe2mem_ctrl),
    .exe2mem_data_i       (exe2mem_data),

    // Writeback module interface signals 
    .mem2wb_ctrl_o        (mem2wb_ctrl),
    .mem2wb_data_o        (mem2wb_data),

    .mem2dmem_o           (mem2dmem),      
    .dmem2mem_i           (dmem2mem)
);


// Writeback module instantiation
writeback writeback_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Data memory module interface signals 
    .mem2wb_ctrl_i        (mem2wb_ctrl),
    .mem2wb_data_i        (mem2wb_data),
    .wb2id_rd_wr_req_o    (wb2id_rd_wr_req),
    .wb2id_rd_addr_o      (wb2id_rd_addr),
    .wb2id_rd_data_o      (wb2id_rd_data)
);


assign if2imem_req_o    =   if2imem_req;              // Instruction memory request
assign if2imem_addr_o   =   if2imem_addr;             // Instruction memory address
assign imem2if_rdata    =   imem2if_rdata_i;           // Instruction memory read data

assign ptop2dmem_o      =   mem2dmem;
assign dmem2mem         =   dmem2ptop_i;

endmodule: pipeline_top


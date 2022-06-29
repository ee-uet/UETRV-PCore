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

   // Data bus interface
    output type_core2dbus_s              ptop2dbus_o,                // Signal to data bus 
    input  wire type_dbus2core_s         dbus2ptop_i 
);


// Local signals
logic                                   if2imem_req;             // Instruction memory request
logic [`XLEN-1:0]                       if2imem_addr;            // Instruction memory address
logic [`XLEN-1:0]                       imem2if_rdata;           // Instruction memory read data

logic                                   id2if_rdy;              // Instruction memory request

type_if2id_data_s                       if2id_data;
type_id2exe_ctrl_s                      id2exe_ctrl;
type_id2exe_data_s                      id2exe_data;

type_exe2mem_ctrl_s                     exe2mem_ctrl;
type_exe2mem_data_s                     exe2mem_data;

type_core2dbus_s                        ptop2dbus;               // Signal to data memory 
type_dbus2core_s                        dbus2ptop; 

type_mem2wrb_ctrl_s                     mem2wrb_ctrl;
type_mem2wrb_data_s                     mem2wrb_data;

type_exe2if_fb_s                        exe2if_fb;

type_wrb2id_fb_s                        wrb2id_fb;
type_fwd2exe_s                          fwd2exe;
type_exe2fwd_s                          exe2fwd;
type_wrb2fwd_s                          wrb2fwd;
logic [`XLEN-1:0]                       wrb2exe_fb_rd_data;


// Fetch <-----> Decode pipeline/nopipeline  
`ifdef IF2ID_PIPELINE_STAGE
  type_if2id_data_s                     if2id_data_pipe_ff;

  always_ff @(posedge clk) begin
      if (rst_n) begin
          if2id_data_pipe_ff <= '0;
      end else begin
          if2id_data_pipe_ff <= if2id_data;
      end
  end
`endif // IF2ID_PIPELINE_STAGE


// Execute <-----> Memory pipeline/nopipeline  
`ifdef EXE2MEM_PIPELINE_STAGE
  type_exe2mem_data_s                   exe2mem_data_pipe_ff;
  type_exe2mem_ctrl_s                   exe2mem_ctrl_pipe_ff;

  always_ff @(posedge clk) begin
      if (rst_n) begin
          exe2mem_data_pipe_ff <= '0;
          exe2mem_ctrl_pipe_ff <= '0;
      end else begin
          exe2mem_data_pipe_ff <= exe2mem_data;
          exe2mem_ctrl_pipe_ff <= exe2mem_ctrl;
      end
  end
`endif // EXE2MEM_PIPELINE_STAGE


// Instruction Fetch module instantiation
fetch fetch_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IF module interface signals 
    .if2imem_req_o       (if2imem_req),
    .if2imem_addr_o      (if2imem_addr),
    .imem2if_rdata_i     (imem2if_rdata),
    .if2id_data_o        (if2id_data),
    .id2if_fb_rdy_i      (id2if_rdy),
    .exe2if_fb_i         (exe2if_fb)
);


// Instruction Decode module instantiation
decode decode_module (
    .rst_n               (rst_n),
    .clk                 (clk),

    // ID module interface signals 
`ifdef IF2ID_PIPELINE_STAGE
    .if2id_data_i        (if2id_data_pipe_ff),
`else
    .if2id_data_i        (if2id_data),
`endif
    .id2if_fb_rdy_i      (id2if_rdy ),
    .id2exe_ctrl_o       (id2exe_ctrl),
    .id2exe_data_o       (id2exe_data),
    .wrb2id_fb_i          (wrb2id_fb)
);


// Instruction Execute module instantiation
execute execute_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Decode module interface signals 
    .id2exe_ctrl_i        (id2exe_ctrl),
    .id2exe_data_i        (id2exe_data),

    // Memory module interface signals
    .exe2mem_ctrl_o       (exe2mem_ctrl),
    .exe2mem_data_o       (exe2mem_data),

    // EXE <---> Forward_stall interface
    .fwd2exe_i            (fwd2exe),
    .exe2fwd_o            (exe2fwd),    

    // Memory module feedback signal from memory module to instruction fetch signal
    .exe2if_fb_o          (exe2if_fb),

    // WB <---> EXE feedback interface
    .wrb2exe_fb_rd_data_i  (wrb2exe_fb_rd_data)
 
);

// Data Memory module instantiation
memory memory_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Execution module interface signals 
`ifdef EXE2MEM_PIPELINE_STAGE
    .exe2mem_ctrl_i       (exe2mem_ctrl_pipe_ff),
    .exe2mem_data_i       (exe2mem_data_pipe_ff),

`else
    .exe2mem_ctrl_i       (exe2mem_ctrl),
    .exe2mem_data_i       (exe2mem_data),
`endif


    // Writeback module interface signals 
    .mem2wrb_ctrl_o        (mem2wrb_ctrl),
    .mem2wrb_data_o        (mem2wrb_data),

    .mem2dmem_o           (ptop2dbus),      
    .dmem2mem_i           (dbus2ptop)
);


// Writeback module instantiation
writeback writeback_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Data memory module interface signals 
    .mem2wrb_ctrl_i        (mem2wrb_ctrl),
    .mem2wrb_data_i        (mem2wrb_data),
    .wrb2id_fb_o           (wrb2id_fb),
    .wrb2exe_fb_rd_data_o  (wrb2exe_fb_rd_data),
    .wrb2fwd_o             (wrb2fwd)
);


// Forward_stall module instantiation
forward_stall forward_stall_module (
    .rst_n                (rst_n      ),
    .clk                  (clk        ),

    // Data memory module interface signals 
    .wrb2fwd_i            (wrb2fwd),
    .exe2fwd_i            (exe2fwd),
    .fwd2exe_o            (fwd2exe)
);

assign if2imem_req_o  =   if2imem_req;              // Instruction memory request
assign if2imem_addr_o =   if2imem_addr;             // Instruction memory address
assign imem2if_rdata  =   imem2if_rdata_i;          // Instruction memory read data

assign ptop2dbus_o    =   ptop2dbus;
assign dbus2ptop      =   dbus2ptop_i;

endmodule : pipeline_top


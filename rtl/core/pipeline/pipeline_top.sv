`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

`default_nettype wire

module pipeline_top (

    input   logic                       rst_n,                    // reset
    input   logic                       clk,                      // clock

   // IF <---> IMEM interface
    output type_if2imem_s               if2imem_o,                // Instruction memory request
    input wire type_imem2if_s           imem2if_i,                // Instruction memory response

   // Data bus interface
    output type_lsu2dbus_s              lsu2dbus_o,                // Signal to data bus 
    input  wire type_dbus2lsu_s         dbus2lsu_i,

   // IRQ interface
   input wire type_pipe2csr_s           core2pipe_i 
);


// Local signals

type_if2id_data_s                       if2id_data, if2id_data_next;
type_if2id_ctrl_s                       if2id_ctrl, if2id_ctrl_next;

type_id2exe_ctrl_s                      id2exe_ctrl, id2exe_ctrl_next;
type_id2exe_data_s                      id2exe_data, id2exe_data_next;

type_exe2lsu_ctrl_s                     exe2lsu_ctrl, exe2lsu_ctrl_next;
type_exe2lsu_data_s                     exe2lsu_data, exe2lsu_data_next;

// Interfaces for CSR module
type_exe2csr_data_s                     exe2csr_data, exe2csr_data_next;
type_exe2csr_ctrl_s                     exe2csr_ctrl, exe2csr_ctrl_next;
type_lsu2csr_data_s                     lsu2csr_data;
type_lsu2csr_ctrl_s                     lsu2csr_ctrl;

// Interfaces for data bus 
type_lsu2dbus_s                         lsu2dbus;               // Signal to data memory 
type_dbus2lsu_s                         dbus2lsu; 

// Interfaces for writeback module
type_lsu2wrb_ctrl_s                     lsu2wrb_ctrl;
type_lsu2wrb_data_s                     lsu2wrb_data;
type_csr2wrb_data_s                     csr2wrb_data;

// Interfaces for feedback signals
type_csr2if_fb_s                        csr2if_fb;
type_exe2if_fb_s                        exe2if_fb;
type_wrb2id_fb_s                        wrb2id_fb;

logic [`XLEN-1:0]                       lsu2exe_fb_alu_result;
logic [`XLEN-1:0]                       wrb2exe_fb_rd_data;

// Interfaces for forwarding module
// To forwarding module
type_exe2fwd_s                          exe2fwd;
type_wrb2fwd_s                          wrb2fwd;
type_lsu2fwd_s                          lsu2fwd;
type_csr2fwd_s                          csr2fwd;

// From forwarding module
type_fwd2exe_s                          fwd2exe;
type_fwd2if_s                           fwd2if;
type_fwd2csr_s                          fwd2csr;
type_fwd2ptop_s                         fwd2ptop;

//================================= Fetch to decode interface ==================================//
// Fetch <-----> Decode pipeline/nopipeline  
`ifdef IF2ID_PIPELINE_STAGE
type_if2id_data_s                       if2id_data_pipe_ff;
type_if2id_ctrl_s                       if2id_ctrl_pipe_ff;

always_ff @(posedge clk) begin
    if (~rst_n) begin
        if2id_data_pipe_ff.instr   <= 32'h00000013;
        if2id_data_pipe_ff.pc      <= '0;
        if2id_data_pipe_ff.pc_next <= '0;
        if2id_data_pipe_ff.instr_flushed <= 1'b0;

        if2id_ctrl_pipe_ff <= '0;
    end else begin
        if2id_data_pipe_ff <= if2id_data_next;
        if2id_ctrl_pipe_ff <= if2id_ctrl_next;
        
    end
end

always_comb begin

    if (fwd2ptop.if2id_pipe_flush) begin
        if2id_data_next.instr = `INSTR_NOP;
        if2id_data_next.instr_flushed = 1'b1;
     
    end else if (fwd2ptop.if2id_pipe_stall) begin
        if2id_data_next = if2id_data_pipe_ff;
        if2id_ctrl_next = if2id_ctrl_pipe_ff;

    end else begin
        if2id_data_next = if2id_data;
        if2id_ctrl_next = if2id_ctrl;
    end   
end 
`endif // IF2ID_PIPELINE_STAGE

// Instruction Fetch module instantiation
fetch fetch_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // IF module interface signals 
    .if2imem_o                  (if2imem_o),
    .imem2if_i                  (imem2if_i),

    .if2id_data_o               (if2id_data),
    .if2id_ctrl_o               (if2id_ctrl),
    .exe2if_fb_i                (exe2if_fb),
    .csr2if_fb_i                (csr2if_fb),
    .fwd2if_i                   (fwd2if)
);


// Instruction Decode module instantiation
decode decode_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // ID module interface signals 
`ifdef IF2ID_PIPELINE_STAGE
    .if2id_data_i               (if2id_data_pipe_ff),
    .if2id_ctrl_i               (if2id_ctrl_pipe_ff),
`else
    .if2id_data_i               (if2id_data),
    .if2id_ctrl_i               (if2id_ctrl),
`endif
    .id2exe_ctrl_o              (id2exe_ctrl),
    .id2exe_data_o              (id2exe_data),
    .wrb2id_fb_i                (wrb2id_fb)
);


//================================= Decode to execute interface ==================================//
// Decode <-----> Execute pipeline/nopipeline  
`ifdef ID2EXE_PIPELINE_STAGE
type_id2exe_data_s                      id2exe_data_pipe_ff;
type_id2exe_ctrl_s                      id2exe_ctrl_pipe_ff;

 always_ff @(posedge clk) begin
    if (~rst_n) begin
        id2exe_data_pipe_ff <= '0;
        id2exe_ctrl_pipe_ff <= '0;
    end else begin
        id2exe_data_pipe_ff <= id2exe_data_next;
        id2exe_ctrl_pipe_ff <= id2exe_ctrl_next;
    end
end

always_comb begin

    if (fwd2ptop.id2exe_pipe_flush) begin
        id2exe_ctrl_next = '0;

        // When pipeline decode and execute stages are flushed in case of jump/branch
        // instructions on incase of interrupt/return-from-interrupt, the PC in those 
        // flushed states should have a valid value to ensure that proper value of PC  
        // is saved in case of an (high-priority) interrupt occurence. This is achieved 
        // using instruction flushed flag signal.
    
        id2exe_data_next.instr_flushed = 1'b1;
        id2exe_data_next.pc_next = '0;

    end else if (fwd2ptop.id2exe_pipe_stall) begin
        id2exe_data_next = id2exe_data_pipe_ff;
        id2exe_ctrl_next = id2exe_ctrl_pipe_ff;

        // Due to pieline stall the updated register values are not available
        // in the following cycle and are rather forwarded from writeback
        // stage here.
        if (fwd2ptop.pipe_fwd_wrb_rs1) begin
            id2exe_data_next.rs1_data = wrb2id_fb.rd_data;
        end
        if (fwd2ptop.pipe_fwd_wrb_rs2) begin
            id2exe_data_next.rs2_data = wrb2id_fb.rd_data;
        end 
    end else begin
        id2exe_data_next = id2exe_data;
        id2exe_ctrl_next = id2exe_ctrl;
    end
end 
`endif // ID2EXE_PIPELINE_STAGE

// Instruction Execute module instantiation
execute execute_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // Decode <---> EXE module interface signals 
`ifdef ID2EXE_PIPELINE_STAGE
    .id2exe_data_i              (id2exe_data_pipe_ff),
    .id2exe_ctrl_i              (id2exe_ctrl_pipe_ff),
`else
    .id2exe_data_i              (id2exe_data),
    .id2exe_ctrl_i              (id2exe_ctrl),
`endif

    // EXE <---> LSU module interface signals
    .exe2lsu_ctrl_o             (exe2lsu_ctrl),
    .exe2lsu_data_o             (exe2lsu_data),

    // EXE <---> CSR module interface signals
    .exe2csr_ctrl_o             (exe2csr_ctrl),
    .exe2csr_data_o             (exe2csr_data),

    // EXE <---> Forward_stall interface
    .fwd2exe_i                  (fwd2exe),
    .exe2fwd_o                  (exe2fwd),    

    // EXE module feedback signal to instruction fetch signal
    .exe2if_fb_o                (exe2if_fb),

    // LSU/WB <---> EXE feedback interface
    .lsu2exe_fb_alu_result_i    (lsu2exe_fb_alu_result),
    .wrb2exe_fb_rd_data_i       (wrb2exe_fb_rd_data)
 
);

//================================= Execute to LSU interface ==================================//
// Execute <-----> LSU pipeline/nopipeline  
`ifdef EXE2LSU_PIPELINE_STAGE
type_exe2lsu_data_s                     exe2lsu_data_pipe_ff;
type_exe2lsu_ctrl_s                     exe2lsu_ctrl_pipe_ff;
type_exe2csr_data_s                     exe2csr_data_pipe_ff;
type_exe2csr_ctrl_s                     exe2csr_ctrl_pipe_ff;

always_ff @(posedge clk) begin
    if (~rst_n) begin
        exe2lsu_data_pipe_ff <= '0;
        exe2lsu_ctrl_pipe_ff <= '0;         
        exe2csr_data_pipe_ff <= '0;
        exe2csr_ctrl_pipe_ff <= '0;
     end else begin
        exe2lsu_data_pipe_ff <= exe2lsu_data_next;
        exe2lsu_ctrl_pipe_ff <= exe2lsu_ctrl_next;
        exe2csr_data_pipe_ff <= exe2csr_data_next;
        exe2csr_ctrl_pipe_ff <= exe2csr_ctrl_next;
    end
end

always_comb begin
    exe2csr_data_next = exe2csr_data;     
    if (fwd2ptop.exe2lsu_pipe_flush) begin
        exe2lsu_ctrl_next = '0;
        exe2csr_ctrl_next = '0;
        exe2csr_data_next.instr_flushed = 1'b1;
        exe2lsu_data_next.alu_result = exe2lsu_data_pipe_ff.alu_result;
    // Stall the exe2lsu/csr stage
    end else if (fwd2ptop.exe2lsu_pipe_stall) begin
        exe2lsu_ctrl_next = exe2lsu_ctrl_pipe_ff;
        exe2csr_ctrl_next = exe2csr_ctrl_pipe_ff;
        exe2lsu_data_next.alu_result = exe2lsu_data_pipe_ff.alu_result;
    end else begin
        exe2lsu_ctrl_next = exe2lsu_ctrl;
        exe2csr_ctrl_next = exe2csr_ctrl; 
        exe2lsu_data_next = exe2lsu_data;
    end
end 
`endif // EXE2LSU_PIPELINE_STAGE

// Load-store module instantiation
lsu lsu_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // Input interface signals from execution module  
`ifdef EXE2LSU_PIPELINE_STAGE
    .exe2lsu_ctrl_i             (exe2lsu_ctrl_pipe_ff),
    .exe2lsu_data_i             (exe2lsu_data_pipe_ff),

`else
    .exe2lsu_ctrl_i             (exe2lsu_ctrl),
    .exe2lsu_data_i             (exe2lsu_data),
`endif

    // CSR module interface signals 
    .lsu2csr_ctrl_o             (lsu2csr_ctrl),
    .lsu2csr_data_o             (lsu2csr_data),

    // Writeback module interface signals 
    .lsu2wrb_ctrl_o             (lsu2wrb_ctrl),
    .lsu2wrb_data_o             (lsu2wrb_data),

    .lsu2exe_fb_alu_result_o    (lsu2exe_fb_alu_result),

    // Forward_stall interface
    .lsu2fwd_o                  (lsu2fwd),

    // LSU to data bus interface
    .lsu2dbus_o                 (lsu2dbus),      
    .dbus2lsu_i                 (dbus2lsu)
);
  

// CSR module instantiation
csr csr_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // Execution module interface signals 
`ifdef EXE2LSU_PIPELINE_STAGE
    .exe2csr_ctrl_i             (exe2csr_ctrl_pipe_ff),
    .exe2csr_data_i             (exe2csr_data_pipe_ff),
`else
    .exe2csr_ctrl_i             (exe2csr_ctrl),
    .exe2csr_data_i             (exe2csr_data),
`endif

    // LSU module interface signals 
    .lsu2csr_ctrl_i             (lsu2csr_ctrl),
    .lsu2csr_data_i             (lsu2csr_data),

    // Writeback module interface signals 
 //    .csr2wrb_ctrl_o            (csr2wrb_ctrl),
    .csr2wrb_data_o             (csr2wrb_data),

    .pipe2csr_i                 (core2pipe_i),
    .fwd2csr_i                  (fwd2csr),
    .csr2fwd_o                  (csr2fwd),
    .csr2if_fb_o                (csr2if_fb)
);

//================================= LSU to writeback interface ==================================//
// LSU <-----> Writeback pipeline/nopipeline  
`ifdef LSU2WRB_PIPELINE_STAGE
type_lsu2wrb_data_s                     lsu2wrb_data_pipe_ff;
type_lsu2wrb_ctrl_s                     lsu2wrb_ctrl_pipe_ff;
type_csr2wrb_data_s                     csr2wrb_data_pipe_ff;

 always_ff @(posedge clk) begin
    if (~rst_n) begin
        lsu2wrb_data_pipe_ff <= '0;
        lsu2wrb_ctrl_pipe_ff <= '0;
        csr2wrb_data_pipe_ff <= '0;
    end else begin
        lsu2wrb_data_pipe_ff <= lsu2wrb_data;
        lsu2wrb_ctrl_pipe_ff <= lsu2wrb_ctrl;
        csr2wrb_data_pipe_ff <= csr2wrb_data;
    end
end
`endif // LSU2WRB_PIPELINE_STAGE


// Writeback module instantiation
writeback writeback_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // Writeback module interface signals
`ifdef LSU2WRB_PIPELINE_STAGE
    .lsu2wrb_ctrl_i             (lsu2wrb_ctrl_pipe_ff),
    .lsu2wrb_data_i             (lsu2wrb_data_pipe_ff),
    .csr2wrb_data_i             (csr2wrb_data_pipe_ff),
`else
    .lsu2wrb_ctrl_i             (lsu2wrb_ctrl),
    .lsu2wrb_data_i             (lsu2wrb_data),
    .csr2wrb_data_i             (csr2wrb_data),
`endif

    .wrb2id_fb_o                (wrb2id_fb),
    .wrb2exe_fb_rd_data_o       (wrb2exe_fb_rd_data),
    .wrb2fwd_o                  (wrb2fwd)
);


// Forward_stall module instantiation
forward_stall forward_stall_module (
    .rst_n                      (rst_n),
    .clk                        (clk),

    // Forward_stall module interface signals 
    .wrb2fwd_i                  (wrb2fwd),
    .lsu2fwd_i                  (lsu2fwd),
    .exe2fwd_i                  (exe2fwd),
    .csr2fwd_i                  (csr2fwd),
    .fwd2if_o                   (fwd2if),
    .fwd2exe_o                  (fwd2exe),
    .fwd2csr_o                  (fwd2csr),
    .fwd2ptop_o                 (fwd2ptop)
);


assign lsu2dbus_o     = lsu2dbus;
assign dbus2lsu       = dbus2lsu_i; 

endmodule : pipeline_top


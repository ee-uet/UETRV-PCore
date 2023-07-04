// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The main memory module. 
//
// Author: Muhammad Tahir, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../defines/mmu_defs.svh"
`include "../defines/cache_defs.svh"
`include "../defines/ddr_defs.svh"
`else
`include "mmu_defs.svh"
`include "cache_defs.svh"
`include "ddr_defs.svh"
`endif

module main_mem (

    input   logic                                   rst_n,                     // reset
    input   logic                                   clk,                       // clock

    // Cache <---> main memory interface
    input wire type_cache2mem_s                     cache2mem_i,
    output type_mem2cache_s                         mem2cache_o

`ifdef DRAM
    ,
    // DDR memory interface
    inout type_mem2ddr_data_s                       mem2ddr_data_io,
    output type_mem2ddr_ctrl_s                      mem2ddr_ctrl_o
`endif
);

// Local signals
type_mem2cache_s                      mem2cache;
type_cache2mem_s                      cache2mem;

logic [`MEM_ADDR_WIDTH-1:0]           mem_addr;
//logic [3:0]                           dmem_selbyte_ff;
logic                                 mem_wen;
logic                                 mem_req;


`ifndef DRAM

// Dual port memory instantiation and initialization
logic [`XLEN-1:0]          dualport_memory[`IDMEM_SIZE];

`ifdef COMPLIANCE
initial
begin
     // Reading the contents of imem.txt file to memory variable
     // Not required to $readmem for COMPLIANCE Tests
end

`elsif RTL_SIMULATION
initial 
begin
    // Reading the contents of example imem.txt file to memory variable
     $readmemh("imem.txt", dualport_memory);  
end
//`endif
`else
initial
begin
     // Reading the contents of example imem.txt file to memory variable
     $readmemh("sdk/example-linux/imem.txt", dualport_memory);  
end
`endif

//============================ Main memory module ============================//
// Connect the local signals to appropriate IOs of the module
assign cache2mem = cache2mem_i; 
assign mem_addr = {2'b0, cache2mem.addr[`MEM_ADDR_WIDTH-1:2]};
assign mem_req = cache2mem.req ;
assign mem_wen = cache2mem.w_en;


// Synchronous load and store operations for data memory
always_ff @(posedge clk) begin  

    if (mem_req & ~mem2cache.ack) begin
        
        if (mem_wen) begin
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b00}] <= cache2mem.w_data[31:0];
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b01}] <= cache2mem.w_data[63:32];
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b10}] <= cache2mem.w_data[95:64];
            dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b11}] <= cache2mem.w_data[127:96];
        end else begin
          //  dmem2dbus_ff.r_data <= dualport_memory[dmem_addr_ff];
            mem2cache.r_data[31:0]   <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b00}];   
            mem2cache.r_data[63:32]  <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b01}];   
            mem2cache.r_data[95:64]  <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b10}];   
            mem2cache.r_data[127:96] <= dualport_memory[{mem_addr[`MEM_ADDR_WIDTH-1:2],2'b11}]; 
            
        end

        mem2cache.ack <= 1'b1;
    end else begin
        mem2cache <= '0;
    end
end

//======================== DDR controller interface ==========================//

`else
 
//type_mem2ddr_data_s                   mem2ddr_data;
type_mem2ddr_ctrl_s                   mem2ddr_ctrl;
   
logic                                 dram_ren;
logic                                 dram_wen;
logic                                 ack;
logic [25:0]                          dram_addr;
logic [127:0]                         dram_din;
logic [127:0]                         dram_dout;

assign dram_ren = mem_req && (!mem_wen);    // we don't need to use a ready signal in read-enable because their state machine will
                                            // issue read command only when DRAM is ready
assign dram_wen = mem_req && mem_wen;       // we don't need to use a ready signal in write-enable because their state machine will
                                            // issue write command only when DRAM is ready
assign dram_addr = cache2mem.addr[26:1];
assign dram_din = cache2mem.w_data[127:0];
assign mem2cache.r_data = dram_dout;  // maybe need to use some ready or valid here ??
assign mem2cache.ack = ack;

DRAMController2 dc (
    // input clk, rst (active-low)
    .sys_clk(mig_clk),
    .sys_rst_x(mig_rst_x),

    // memory interface ports
    .ddr2_dq(mem2ddr_data_io.ddr2_dq),
    .ddr2_dqs_n(mem2ddr_data_io.ddr2_dqs_n),
    .ddr2_dqs_p(mem2ddr_data_io.ddr2_dqs_p),

    .ddr2_addr(mem2ddr_ctrl.ddr2_addr),
    .ddr2_ba(mem2ddr_ctrl.ddr2_ba),
    .ddr2_ras_n(mem2ddr_ctrl.ddr2_ras_n),
    .ddr2_cas_n(mem2ddr_ctrl.ddr2_cas_n),
    .ddr2_we_n(mem2ddr_ctrl.ddr2_we_n),
    .ddr2_ck_p(mem2ddr_ctrl.ddr2_ck_p),
    .ddr2_ck_n(mem2ddr_ctrl.ddr2_ck_n),
    .ddr2_cke(mem2ddr_ctrl.ddr2_cke),
    .ddr2_cs_n(mem2ddr_ctrl.ddr2_cs_n),
    .ddr2_dm(mem2ddr_ctrl.ddr2_dm),
    .ddr2_odt(mem2ddr_ctrl.ddr2_odt),
    // output clk, rst (active-low)
    .o_clk(mig_ui_clk),
    .o_rst_x(mig_ui_rst_x),
    // user interface ports
    .i_rd_en(dram_ren),
    .i_wr_en(dram_wen),
    .i_addr({1'b0, dram_addr}),     // almost confirmed that it is half-word's address
    .i_data(dram_din),  // can we write multiple words at once ??
//        .o_init_calib_complete(dram_init_calib_complete),   // used, and dealt with, in state machine
    .o_data(dram_dout),             // data out
    .o_ack(ack),                    // ack for read as well as write; implemented in state machine, but untested
    .o_data_valid(dram_dout_valid), // maybe ack for read ??
    .o_ready(dram_ready),           // dram combined ready for read and write
    .o_wdf_ready(dram_wdf_ready)    // dram write ready
//        ,.i_mask(data_mask)    // probably active low ??
);


assign mem2ddr_ctrl_o = mem2ddr_ctrl;

`endif

// Update the output signals
assign mem2cache_o = mem2cache;

endmodule : main_mem

`ifdef DRAM

/**************************************************************************************************/
module DRAMController2 (
    // input clk, rst (active-low)
    input  wire                         sys_clk,
    input  wire                         sys_rst_x,

    // memory interface ports
    inout  wire [DDR2_DQ_WIDTH-1:0]     ddr2_dq,
    inout  wire [DDR2_DQS_WIDTH-1:0]    ddr2_dqs_n,
    inout  wire [DDR2_DQS_WIDTH-1:0]    ddr2_dqs_p,

    output logic [DDR2_ADDR_WIDTH-1:0]  ddr2_addr,
    output logic [DDR2_BA_WIDTH-1:0]    ddr2_ba,
    output logic                         ddr2_ras_n,
    output logic                         ddr2_cas_n,
    output logic                         ddr2_we_n,
    output logic                         ddr2_ck_p,
    output logic                         ddr2_ck_n,
    output logic                         ddr2_cke,
    output logic                         ddr2_cs_n,
    output logic [DDR2_DM_WIDTH-1:0]     ddr2_dm,
    output logic                         ddr2_odt,
    // output clk, rst (active-low)
    output logic                         o_clk,
    output logic                         o_rst_x,
    // user interface ports
    input  wire                          i_rd_en,
    input  wire                          i_wr_en,
    input  wire [APP_ADDR_WIDTH-1:0]     i_addr,
    input  wire [APP_DATA_WIDTH-1:0]     i_data,
//         output wire                         o_init_calib_complete,       // we don't need it because their state machine takes care of
                                                                       // it; yet to confirm
    output logic                         o_ack,
    output logic [APP_DATA_WIDTH-1:0]    o_data,
    output logic                         o_data_valid,
    output logic                         o_ready,
    output logic                         o_wdf_ready
//         ,input  wire [3:0]                   i_mask
);

logic                        init_calib_complete;
logic [APP_DATA_WIDTH-1:0]   app_rd_data;
logic                        app_rd_data_valid;
logic                        app_rdy;
logic                        app_wdf_rdy;
logic                        clk;
logic                        rst;
logic [APP_ADDR_WIDTH-1:0]   app_addr;
logic [APP_CMD_WIDTH-1:0]    app_cmd;
logic                        app_en;
logic  [APP_DATA_WIDTH-1:0]  app_wdf_data;
logic                        app_wdf_wren;
logic                        ack;
// logic  [3:0]                  data_mask = 0;

type_ddr_states_e            state;

 
assign o_clk = clk;
assign o_rst_x = ~rst;
// assign o_init_calib_complete = init_calib_complete;
assign o_data = app_rd_data;
assign o_data_valid = app_rd_data_valid;
assign o_ready = app_rdy;
assign o_wdf_ready = app_wdf_rdy;
assign o_ack = ack;


always @(posedge clk) begin
    if (rst) begin
        state <= STATE_CALIB;
        app_cmd <= 0;
        app_addr <= 0;
        app_en <= 0;
        app_wdf_data <= 0;
        app_wdf_wren <= 0;
//                data_mask <= 0;
        ack <= 0;
    end else begin
        case (state)
            STATE_CALIB: begin
                if (init_calib_complete) begin
                    state <= STATE_IDLE;
                end
            end
            STATE_IDLE: begin
                ack <= 0;
                if (i_wr_en) begin
                    app_cmd <= CMD_WRITE;
                    app_addr <= i_addr;
                    app_en <= 1;
                    app_wdf_data <= i_data;
                    app_wdf_wren <= 1;
                    state <= STATE_ISSUE_CMD_WDATA;
//                            data_mask <= i_mask;
                end else if (i_rd_en) begin
                    app_wdf_wren <= 0;
                    app_cmd <= CMD_READ;
                    app_addr <= i_addr;
                    app_en <= 1;
                    state <= STATE_ISSUE_CMD;
//                            data_mask <= 0;
                end
            end
            STATE_ISSUE_CMD_WDATA: begin
                if (app_rdy && app_wdf_rdy) begin
                    if (i_wr_en) begin
                        app_cmd <= CMD_WRITE;
                        app_addr <= i_addr;
                        app_en <= 1;
                        app_wdf_data <= i_data;
                        app_wdf_wren <= 1;
                        state <= STATE_ISSUE_CMD_WDATA;
//                                data_mask <= i_mask;
                    end else if (i_rd_en) begin
                        app_wdf_wren <= 0;
                        app_cmd <= CMD_READ;
                        app_addr <= i_addr;
                        app_en <= 1;
                        state <= STATE_ISSUE_CMD;
//                                data_mask <= 0;
                    end else begin
                        app_en <= 0;
                        app_wdf_wren <= 0;
                        state <= STATE_IDLE;
                        ack <= 1;
                    end
                end else if (app_rdy) begin
                    app_en <= 0;
                    state <= STATE_ISSUE_WDATA;
                end else if (app_wdf_rdy) begin
                    app_wdf_wren <= 0;
                    state <= STATE_ISSUE_CMD;
                end
            end
            STATE_ISSUE_CMD: begin
                if (app_rdy) begin
                    if (i_wr_en) begin
                        app_cmd <= CMD_WRITE;
                        app_addr <= i_addr;
                        app_en <= 1;
                        app_wdf_data <= i_data;
                        app_wdf_wren <= 1;
                        state <= STATE_ISSUE_CMD_WDATA;
//                                data_mask <= i_mask;
                    end else if (i_rd_en) begin
                        app_wdf_wren <= 0;
                        app_cmd <= CMD_READ;
                        app_addr <= i_addr;
                        app_en <= 1;
                        state <= STATE_ISSUE_CMD;
//                                data_mask <= 0;
                    end else begin
                        app_en <= 0;
                        app_wdf_wren <= 0;
                        state <= STATE_IDLE;
                        ack <= 1;
                    end
                end
            end
            STATE_ISSUE_WDATA: begin
                if (app_wdf_rdy) begin
                    if (i_wr_en) begin
                        app_cmd <= CMD_WRITE;
                        app_addr <= i_addr;
                        app_en <= 1;
                        app_wdf_data <= i_data;
                        app_wdf_wren <= 1;
                        state <= STATE_ISSUE_CMD_WDATA;
//                                data_mask <= i_mask;
                    end else if (i_rd_en) begin
                        app_wdf_wren <= 0;
                        app_cmd <= CMD_READ;
                        app_addr <= i_addr;
                        app_en <= 1;
                        state <= STATE_ISSUE_CMD;
//                                data_mask <= 0;
                    end else begin
                        app_wdf_wren <= 0;
                        state <= STATE_IDLE;
                        ack <= 1;
                    end
                end
            end
            default: begin
                app_en <= 0;
                app_wdf_wren <= 0;
                state <= STATE_IDLE;
                ack <= 0;
             end
         endcase
    end
end


mig_7series_0 mig (
      // memory interface ports
      .ddr2_addr           (ddr2_addr),
      .ddr2_ba             (ddr2_ba),
      .ddr2_cas_n          (ddr2_cas_n),
      .ddr2_ck_n           (ddr2_ck_n),
      .ddr2_ck_p           (ddr2_ck_p),
      .ddr2_cke            (ddr2_cke),
      .ddr2_ras_n          (ddr2_ras_n),
      .ddr2_we_n           (ddr2_we_n),
      .ddr2_dq             (ddr2_dq),
      .ddr2_dqs_n          (ddr2_dqs_n),
      .ddr2_dqs_p          (ddr2_dqs_p),
      .ddr2_cs_n           (ddr2_cs_n),
      .ddr2_dm             (ddr2_dm),
      .ddr2_odt            (ddr2_odt),

      // calibration
      .init_calib_complete (init_calib_complete),
      // application interface ports
      .app_addr            (app_addr),
      .app_cmd             (app_cmd),
      .app_en              (app_en),
      .app_wdf_data        (app_wdf_data),
      .app_wdf_end         (app_wdf_wren), // to simplify the user logic, app_wdf_end and app_wdf_wren are tied together
      .app_wdf_wren        (app_wdf_wren), // to ensure that they are always driven together
      .app_rd_data         (app_rd_data),
      .app_rd_data_end     (),
      .app_rd_data_valid   (app_rd_data_valid),
      .app_rdy             (app_rdy),
      .app_wdf_rdy         (app_wdf_rdy),
      .app_sr_req          (1'b0),
      .app_ref_req         (1'b0),
      .app_zq_req          (1'b0),
      .app_sr_active       (),
      .app_ref_ack         (),
      .app_zq_ack          (),
      .ui_clk              (clk),
      .ui_clk_sync_rst     (rst),
//           .app_wdf_mask        ({{(APP_MASK_WIDTH-4){1'b1}}, data_mask}),
      .app_wdf_mask        ({(APP_MASK_WIDTH){1'b0}}),     // always write all 16 bytes ? probably active low, yet to confirm. Also,
                                                           // can we write more than 4 bytes at once? yet to confirm
      // system clock, reset ports
      .sys_clk_i           (sys_clk),
      .sys_rst             (sys_rst_x)
);


endmodule
/**************************************************************************************************/
`endif

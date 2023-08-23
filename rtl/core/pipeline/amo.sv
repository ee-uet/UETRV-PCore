// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The A-extension implementing atomic memory operations (AMOs) and 
//              single buffer based LR/SC instructions.
//
// Author: Umer Shahid, UET Lahore
// Date: 11.8.2022


`ifndef VERILATOR
`include "../../defines/a_ext_defs.svh"
`else
`include "a_ext_defs.svh"
`endif

module amo (

    input   logic                           rst_n,                    // reset
    input   logic                           clk,                      // clock

    // AMO <---> LSU interface
    input  wire type_lsu2amo_data_s         lsu2amo_data_i,
    input  wire type_lsu2amo_ctrl_s         lsu2amo_ctrl_i,             

    output type_amo2lsu_data_s              amo2lsu_data_o,
    output type_amo2lsu_ctrl_s              amo2lsu_ctrl_o
);

//============================= Local signals and their assignments =============================//
// Local signals
type_lsu2amo_data_s          lsu2amo_data;
type_lsu2amo_ctrl_s          lsu2amo_ctrl;
type_amo2lsu_data_s          amo2lsu_data;
type_amo2lsu_ctrl_s          amo2lsu_ctrl;

//logic [`XLEN-1:0]            ld_st_addr;
logic                        ld_req;
logic                        st_req;
logic                        rd_wr_req;
logic [`XLEN-1:0]            w_data;
logic [`XLEN-1:0]            amo_wrb_data;


// A-Extension signals
type_amo_ops_e               amo_ops;              // Signal added for AMO instructions
logic                        is_amo;               // A flag to check if the current instruction is ANO
logic                        is_lr;                // A flag to check if current instruction is LR.
logic [31:0]                 amo_buffer_data_ff;   // Signal used for latching the buffer data.
logic [31:0]                 amo_buffer_addr_ff;   // Signal used for latching the buffer data
logic [31:0]                 amo_operand_a;        // To fetch amo operand1 (i.e, value from data memory)
logic [31:0]                 amo_operand_a_ff;     // Signal used for latching the value of amo_operand_a
logic [31:0]                 amo_operand_b;        // To fetch amo operand2 (i.e, data from register file pointed by rs2)
logic [31:0]                 amo_result;         // Variable to store the result of amo_alu
logic                        amo_done;             // A flag to show the completeness of amo instruction
logic                        a_slt_b, a_uslt_b;    // Two flags used to compare amo_operand_a and amo_operand_b (signed/unsigned comparators)
logic                        is_sc;                // A signal to check if current instruction is SC.
logic                        sc_pass;              // A flag to verify if SC instruction was successfully completed
logic                        amo_reserve_ff;       // Signal used for latching the reserve signal.
logic                        amo_save;


// Signals for AMO State Machine
type_amo_states_e            state, state_next;

// Input signal assignments
assign lsu2amo_data = lsu2amo_data_i;
assign lsu2amo_ctrl = lsu2amo_ctrl_i;

// Signal assignments
assign amo_ops = lsu2amo_ctrl.amo_ops;

assign is_amo  = lsu2amo_ctrl.is_amo;      // Assignment of is_amo
                                           // is_amo if true, then it will command the following variations in the existing LSU:
                                           //   1. FOR AMO, the first part of instruction execution is 
                                           //      to load the data from the data memory, thus ld_ops will 
                                           //      be assigned as LW opcode to read data word from dbus.
                                           //   2. If its an AMO instruction, then lsu2fwd.ld_ack will 
                                           //      subjected to the completeness of amo instruction,
                                           //      thus, lsu2fwd.ld_ack will be updated to amo_done flag 
                                           //      instead of regular dbus2lsu.ack

assign is_lr  = amo_ops == AMO_OPS_LR;     // Assignment of is_lr
                                           // When 'is_lr' is set then following becomes true:
                                           //   1. The execution will be similar to LW instruction except
                                           //      that data and address will be saved in the respective buffer
                                           //   2. amo_reserve will be enabled
                                           //   3. Instruction will be considered completed after 
                                           //      dbus2lsu.ack will come, so amo_done logic will be 
                                           //      adjusted accordingly

assign is_sc  = amo_ops == AMO_OPS_SC;     // Assignment of is_sc
                                           // When 'is_sc' is set then following becomes true:
                                           //   1. Determine if current address and data matches with the 
                                           //      data/address stored in amo_buffer
                                           //   2. Determine if amo_reserve was enabled previously due to 
                                           //      earlier LR instruction
                                           //   3. Based on the above checks, determine if SC instruction 
                                           //      was successfull or not. Set sc_pass flag accordingly
                                           //   4. Update data to write_back stage.
                                           //       4a. lsu2wrb_data.alu_result will become equal to !sc_pass. 
                                           //           (0 if successfull, 1 if unsuccessfull)
                                           //       4b. lsu2wrb_ctrl.rd_wrb_sel will become equal to RD_WRB_ALU (1)
                                           //       4c. lsu2wrb_ctrl.rd_wr_req will be set (1). REMEMBER: for normal
                                           //           store, it was zero as there is no write basck for normal store

// Prepare the AMO operands                        
assign amo_operand_b = lsu2amo_data.rs2_operand;
assign amo_operand_a = (ld_req & lsu2amo_ctrl.ack) ? lsu2amo_data.r_data : amo_operand_a_ff;

// Prepare the signals to perform load/store operations      
assign a_slt_b  = $signed(amo_operand_a) < $signed(amo_operand_b);      // Comparison between operand_a and operand_b ==> To be used by AMO_ALU
assign a_uslt_b = $unsigned(amo_operand_a) < $unsigned(amo_operand_b);  // Comparison between operand_a and operand_b ==> To be used by AMO_ALU

// Logic for sc_pass, evaluation if instruction is SC, and amo_reserve was set (by 
// some LR instruction) and Data/Address of buffer matches with the current data
assign sc_pass  = is_sc & amo_reserve_ff
                & (amo_buffer_addr_ff == lsu2amo_data.lsu_addr) 
                & (amo_buffer_data_ff == amo_operand_a);

// AMO ALU implementation 
always_comb begin
    amo_result = '0;

    case (amo_ops)
        AMO_OPS_SC  : amo_result = amo_operand_b;
        AMO_OPS_SWAP: amo_result = amo_operand_b;
        AMO_OPS_ADD : amo_result = amo_operand_a + amo_operand_b;
        AMO_OPS_XOR : amo_result = amo_operand_a ^ amo_operand_b;
        AMO_OPS_AND : amo_result = amo_operand_a & amo_operand_b;
        AMO_OPS_OR  : amo_result = amo_operand_a | amo_operand_b;
        AMO_OPS_MIN : amo_result = a_slt_b  ? amo_operand_a : amo_operand_b;
        AMO_OPS_MAX : amo_result = a_slt_b  ? amo_operand_b : amo_operand_a;
        AMO_OPS_MINU: amo_result = a_uslt_b ? amo_operand_a : amo_operand_b;
        AMO_OPS_MAXU: amo_result = a_uslt_b ? amo_operand_b : amo_operand_a;
        default:      amo_result = amo_operand_b;
    endcase
end

// State machine for different AMO operations
always_ff @ (posedge clk or negedge rst_n) begin
    if (!rst_n | lsu2amo_ctrl.amo_flush) begin
	     state        <= AMO_IDLE;
    end else begin
	     state        <= state_next;
    end
end

always_comb begin
   amo_done   = '0; 
   amo_save   = '0; 
   state_next = AMO_IDLE;

   ld_req     = 1'b0; 
   st_req     = 1'b0;
   rd_wr_req  = 1'b0;
   w_data     = '0;

   case (state)
      AMO_IDLE: begin   
         if(is_amo) begin
            state_next = AMO_LOAD;
            ld_req     = 1'b1;
            st_req     = 1'b0;
            rd_wr_req  = 1'b0;
         end 
      end 
      AMO_LOAD: begin
         rd_wr_req  = 1'b0;
         if(lsu2amo_ctrl.ack) begin
            state_next = AMO_OP;
            ld_req     = 1'b1;
            st_req     = 1'b0;
            amo_save   = is_lr;
         end else begin
            state_next = AMO_LOAD;
            ld_req     = 1'b1;
            st_req     = 1'b0;
         end
      end

      AMO_OP: begin
            rd_wr_req = 1'b0;
            ld_req    = 1'b0;
            st_req    = 1'b0;
            // Donot Store in case of LR or when SC fails
            if(is_lr | (is_sc && !sc_pass)) begin
               state_next = AMO_DONE;
            end else  begin
               state_next = AMO_ST;
            end
      end

      AMO_ST: begin
         rd_wr_req = 1'b0;
         ld_req    = 1'b0;
         st_req    = 1'b1;

         if(is_sc) begin
            w_data = lsu2amo_data.rs2_operand;
         end else  begin
            w_data = amo_result;
         end
     
         if(lsu2amo_ctrl.ack) begin
            state_next = AMO_DONE;
         end else begin
            state_next = AMO_ST;         
         end
      end

      AMO_DONE: begin
            rd_wr_req  = 1'b1;
            state_next = AMO_IDLE;
            ld_req     = 1'b0;
            st_req     = 1'b0;
            amo_done   = 1'b1;
      end

      default: begin      end
   endcase
end

// Single AMO buffer for load reserve  
always_ff @( posedge clk or negedge rst_n) begin 
   if (~rst_n | (is_sc & amo_done)) begin
      amo_buffer_data_ff <= '0;
      amo_buffer_addr_ff <= '0;
      amo_reserve_ff     <= '0;
   end
   else if(amo_save) begin
      amo_buffer_data_ff <= lsu2amo_data.r_data; 
      amo_buffer_addr_ff <= lsu2amo_data.lsu_addr;
      amo_reserve_ff     <= 1;
   end   
end
 
// Buffering of AMO operand
always_ff @( posedge clk ) begin 
   if (~rst_n)
      amo_operand_a_ff <= '0;
   else if(ld_req & lsu2amo_ctrl.ack)
      amo_operand_a_ff <= lsu2amo_data.r_data; 
   else 
      amo_operand_a_ff <= amo_operand_a_ff;   
end

// AMO result preparation for writeback stage 
always_comb begin
    amo_wrb_data = '0;

    // In case SC passes return 0 else return 1 (non-zero value)
    if (is_sc) begin
        amo_wrb_data = {31'b0, ~sc_pass};
    end else begin
        amo_wrb_data = amo_operand_a; // For other AMO operations send the loaded data
    end 
end

//=================================== Output signals update =====================================//

assign amo2lsu_data.amo_wrb_data = amo_wrb_data;
assign amo2lsu_data.w_data       = w_data;

assign amo2lsu_ctrl.rd_wr_req    = rd_wr_req;
assign amo2lsu_ctrl.ld_req       = ld_req;
assign amo2lsu_ctrl.st_req       = st_req;
assign amo2lsu_ctrl.amo_done     = amo_done;

// Update the output signals with proper assignment
assign amo2lsu_data_o = amo2lsu_data;
assign amo2lsu_ctrl_o = amo2lsu_ctrl;

endmodule : amo

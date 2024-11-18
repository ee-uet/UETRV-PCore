// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: The Store Buffer module. 
//
// Author: Fazail Ali Butt, UET Lahore
// Date: 15.11.2024

module lsu_stb_controller (
    input  logic        clk,
    input  logic        rst_n,

    // LSU --> lsu_stb_controller
    input  logic        lsummu2stb_w_en,    // Write enable from LSU
    input  logic        lsummu2stb_req,     // Store request from LSU
    input  logic        dmem_sel_i,         // Input from LSU (data memory select)

    // store_buffer_datapath --> lsu_stb_controller 
    input  logic        stb_full,           // Store buffer stb_full flag
    input  logic        stb_empty,          // store buffer stb_empty flag

    // lsu_stb_controller --> LSU
    output logic        stb_ack,     // stb_acknowledgement signal
    output logic        stb_stall,    // Stall signal if buffer is stb_full

    // lsu_stb_controller --> store_buffer_datapath
    output logic        wr_en           // Store buffer write enable
);

    typedef enum logic [1:0] {
        SB_IDLE  = 2'b00,
        SB_WRITE = 2'b01,
        SB_FULL  = 2'b10
    } state_t;

    state_t current_state, next_state;

    // State transition logic (sequential)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            current_state <= SB_IDLE;
        else
            current_state <= next_state;
    end

    // Next state logic (combinational)
    always_comb begin
        // Default values
        wr_en = 1'b0;
        stb_stall = 1'b0;
        stb_ack   = 1'b0;

        case (current_state)
            SB_IDLE: begin
                if (dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req && !stb_full) begin
                    wr_en      = 1'b1;  // Enable write to buffer
                    stb_stall  = 1'b0;
                    stb_ack    = 1'b0;
                    next_state = SB_WRITE;
                end
                else if (dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req && stb_full) begin
                    stb_stall  = 1'b1;
                    wr_en      = 1'b0;
                    stb_ack    = 1'b0;
                    next_state = SB_FULL;   
                end else begin
                    stb_stall  = 1'b0;
                    wr_en      = 1'b0;
                    stb_ack    = 1'b0;
                    next_state = SB_IDLE;
                end
            end

            SB_WRITE: begin
                stb_ack   = 1'b1;
                if (dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req && !stb_full)begin
                    wr_en       = 1'b1;  // Enable write to buffer
                    stb_stall   = 1'b0;
                    next_state  = SB_WRITE;
                end
                else if (dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req && stb_full)begin
                    wr_en       = 1'b0;
                    stb_stall   = 1'b1;
                    next_state  = SB_FULL; 
                end
                else if (!stb_empty) begin
                    if (dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req) begin
                        wr_en      = 1'b1;
                        next_state = SB_WRITE;  // Transition to stb_full state if buffer is stb_full
                    end
                    else begin
                        wr_en      = 1'b0;
                        next_state = SB_IDLE;
                    end
                end 
            end

            SB_FULL: begin
                stb_stall = 1'b1;  // Stall signal if buffer is stb_full
                if (dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req && !stb_full) begin
                    wr_en      = 1'b1;
                    stb_stall  = 1'b0;
                    stb_ack    = 1'b0;
                    next_state = SB_WRITE;  // Go to idle once buffer is not stb_full
                end
                else if(dmem_sel_i && lsummu2stb_w_en && lsummu2stb_req && stb_full) begin
                    wr_en      = 1'b0;
                    stb_ack    = 1'b0;
                    next_state = SB_FULL;
                end
                else begin
                    wr_en      = 1'b0;
                    stb_stall  = 1'b0;
                    stb_ack    = 1'b0;
                    next_state = SB_IDLE;
                end        
            end

            default: next_state = SB_IDLE;
        endcase
    end

endmodule

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

    // lsu_stb_controller --> LSU
    output logic        stb_ack,     	    // stb_acknowledgement signal

    // lsu_stb_controller --> store_buffer_datapath
    output logic        wr_en               // Store buffer write enable
);

    typedef enum logic [1:0] {
        SB_IDLE  = 2'b00,
        SB_WRITE = 2'b01,
        SB_FULL  = 2'b10,
        SB_BYPASS = 2'b11
    } state_t;

    state_t current_state, next_state;
    logic full_ff;

    //State transition logic (sequential)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            current_state <= SB_IDLE;
            full_ff <= '0;
        end else begin
            current_state <= next_state;
            full_ff <= stb_full;
        end
    end

    // Next state logic (combinational)
    always_comb begin
        // Default values
        wr_en     = 1'b0;
        stb_ack   = 1'b0;
        
        case (current_state)
            SB_IDLE: begin
                stb_ack    = 1'b0;
                if (lsummu2stb_req ) begin
                    if (lsummu2stb_w_en) begin
                        if (full_ff) begin
                            wr_en      = 1'b0;
                            next_state = SB_FULL;
                        end else begin
                            wr_en      = 1'b1;
                            next_state = SB_WRITE;
                        end
                    end else begin
                        wr_en      = 1'b0;
                        next_state = SB_IDLE;  
                    end
                end else begin
                    wr_en      = 1'b0;
                    next_state = SB_IDLE;
                end
            end

            SB_WRITE: begin
                stb_ack   = 1'b1;
                if (lsummu2stb_req) begin
                    if (lsummu2stb_w_en) begin
                        if (full_ff) begin
                            wr_en       = 1'b0;
                            next_state  = SB_FULL;
                        end else begin
                            wr_en       = 1'b1; 
                            next_state  = SB_WRITE;
                        end
                    end else begin
                        wr_en       = 1'b0; 
                        next_state  = SB_IDLE;
                    end
                end else begin
                    wr_en      = 1'b0;
                    next_state = SB_IDLE;
                end
            end

            SB_FULL: begin
                stb_ack    = 1'b0;
                if (lsummu2stb_req) begin
                    if (lsummu2stb_w_en) begin
                        if (full_ff) begin
                            wr_en      = 1'b0;
                            next_state = SB_FULL; // Go to idle once buffer is not stb_full
                        end else begin
                            wr_en      = 1'b1;
                            next_state = SB_WRITE; 
                        end
                    end else begin
                        wr_en      = 1'b0;
                        next_state = SB_IDLE;
                    end
                end else begin
                    wr_en      = 1'b0;
                    next_state = SB_IDLE;
                end        
            end
            default: begin 
                next_state = SB_IDLE;
            end
        endcase
        
        if (~dmem_sel_i) begin
        	next_state = SB_IDLE;
        end
        
    end

endmodule

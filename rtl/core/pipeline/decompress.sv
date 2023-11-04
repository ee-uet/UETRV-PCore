// Copyright 2023 University of Engineering and Technology Lahore.
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.
// SPDX-License-Identifier: Apache-2.0
//
// Description: Fully Combinatorial 16-bit to 32-bit decoder for Compressed Instructions
//
// Author: Abdul Wadood, UET Lahore
// Date: 7.10.2023

`ifndef VERILATOR
`include "../../defines/cache_defs.svh"
`else
`include "cache_defs.svh"
`endif

module decompress (
  input wire type_icache2if_s                     ralgn2dcmp_i,
  input wire                                      req_kill_i,
  
  output type_icache2if_s                         dcmp2if_o
);


localparam OPCODE_LOAD     = 7'h03;
localparam OPCODE_OP_IMM   = 7'h13;
localparam OPCODE_STORE    = 7'h23;
localparam OPCODE_OP       = 7'h33;
localparam OPCODE_LUI      = 7'h37;
localparam OPCODE_BRANCH   = 7'h63;
localparam OPCODE_JALR     = 7'h67;
localparam OPCODE_JAL      = 7'h6f;

// local signals for internal use
type_icache2if_s            ralgn2dcmp, dcmp2if;
logic                       illegal_instr;
// Input signal assignment
assign ralgn2dcmp = ralgn2dcmp_i;

always_comb begin
  // By default, forward incoming instruction, mark it as legal.
  dcmp2if.r_data    = ralgn2dcmp.r_data;
  illegal_instr     = 1'b0;

  // Check if incoming instruction is compressed.
  unique case (ralgn2dcmp.r_data[1:0])
    // C0
    2'b00: begin
      unique case (ralgn2dcmp.r_data[15:14])
        2'b00: begin
          // c.addi4spn -> addi rd', x2, imm
          dcmp2if.r_data = {2'b0, ralgn2dcmp.r_data[10:7], ralgn2dcmp.r_data[12:11], ralgn2dcmp.r_data[5],
                    ralgn2dcmp.r_data[6], 2'b00, 5'h02, 3'b000, 2'b01, ralgn2dcmp.r_data[4:2], {OPCODE_OP_IMM}};
        end

        2'b01: begin
          // c.lw -> lw rd', imm(rs1')
          dcmp2if.r_data = {5'b0, ralgn2dcmp.r_data[5], ralgn2dcmp.r_data[12:10], ralgn2dcmp.r_data[6],
                    2'b00, 2'b01, ralgn2dcmp.r_data[9:7], 3'b010, 2'b01, ralgn2dcmp.r_data[4:2], {OPCODE_LOAD}};
        end

        2'b11: begin
          // c.sw -> sw rs2', imm(rs1')
          dcmp2if.r_data = {5'b0, ralgn2dcmp.r_data[5], ralgn2dcmp.r_data[12], 2'b01, ralgn2dcmp.r_data[4:2],
                    2'b01, ralgn2dcmp.r_data[9:7], 3'b010, ralgn2dcmp.r_data[11:10], ralgn2dcmp.r_data[6],
                    2'b00, {OPCODE_STORE}};
        end

        2'b10: begin
          illegal_instr = 1'b1;
        end

      endcase
    end

    // C1

    // Register address checks for RV32E are performed in the regular instruction decoder.
    // If this check fails, an illegal instruction exception is triggered and the controller
    // writes the actual faulting instruction to mtval.
    2'b01: begin
      unique case (ralgn2dcmp.r_data[15:13])
        3'b000: begin
          // c.addi -> addi rd, rd, nzimm
          // c.nop
          dcmp2if.r_data = {{6 {ralgn2dcmp.r_data[12]}}, ralgn2dcmp.r_data[12], ralgn2dcmp.r_data[6:2],
                    ralgn2dcmp.r_data[11:7], 3'b0, ralgn2dcmp.r_data[11:7], {OPCODE_OP_IMM}};
        end

        3'b001, 3'b101: begin
          // 001: c.jal -> jal x1, imm
          // 101: c.j   -> jal x0, imm
          dcmp2if.r_data = {ralgn2dcmp.r_data[12], ralgn2dcmp.r_data[8], ralgn2dcmp.r_data[10:9], ralgn2dcmp.r_data[6],
                    ralgn2dcmp.r_data[7], ralgn2dcmp.r_data[2], ralgn2dcmp.r_data[11], ralgn2dcmp.r_data[5:3],
                    {9 {ralgn2dcmp.r_data[12]}}, 4'b0, ~ralgn2dcmp.r_data[15], {OPCODE_JAL}};
        end

        3'b010: begin
          // c.li -> addi rd, x0, nzimm
          // (c.li hints are translated into an addi hint)
          dcmp2if.r_data = {{6 {ralgn2dcmp.r_data[12]}}, ralgn2dcmp.r_data[12], ralgn2dcmp.r_data[6:2], 5'b0,
                    3'b0, ralgn2dcmp.r_data[11:7], {OPCODE_OP_IMM}};
        end

        3'b011: begin
          // c.lui -> lui rd, imm
          // (c.lui hints are translated into a lui hint)
          dcmp2if.r_data = {{15 {ralgn2dcmp.r_data[12]}}, ralgn2dcmp.r_data[6:2], ralgn2dcmp.r_data[11:7], {OPCODE_LUI}};

          if (ralgn2dcmp.r_data[11:7] == 5'h02) begin
            // c.addi16sp -> addi x2, x2, nzimm
            dcmp2if.r_data = {{3 {ralgn2dcmp.r_data[12]}}, ralgn2dcmp.r_data[4:3], ralgn2dcmp.r_data[5], ralgn2dcmp.r_data[2],
                      ralgn2dcmp.r_data[6], 4'b0, 5'h02, 3'b000, 5'h02, {OPCODE_OP_IMM}};
          end

        end

        3'b100: begin
          unique case (ralgn2dcmp.r_data[11:10])
            2'b00,
            2'b01: begin
              // 00: c.srli -> srli rd, rd, shamt
              // 01: c.srai -> srai rd, rd, shamt
              // (c.srli/c.srai hints are translated into a srli/srai hint)
              dcmp2if.r_data = {1'b0, ralgn2dcmp.r_data[10], 5'b0, ralgn2dcmp.r_data[6:2], 2'b01, ralgn2dcmp.r_data[9:7],
                        3'b101, 2'b01, ralgn2dcmp.r_data[9:7], {OPCODE_OP_IMM}};
            end

            2'b10: begin
              // c.andi -> andi rd, rd, imm
              dcmp2if.r_data = {{6 {ralgn2dcmp.r_data[12]}}, ralgn2dcmp.r_data[12], ralgn2dcmp.r_data[6:2], 2'b01, ralgn2dcmp.r_data[9:7],
                        3'b111, 2'b01, ralgn2dcmp.r_data[9:7], {OPCODE_OP_IMM}};
            end

            2'b11: begin
              unique case (ralgn2dcmp.r_data[6:5])
                2'b00: begin
                  // c.sub -> sub rd', rd', rs2'
                  dcmp2if.r_data = {2'b01, 5'b0, 2'b01, ralgn2dcmp.r_data[4:2], 2'b01, ralgn2dcmp.r_data[9:7],
                                3'b000, 2'b01, ralgn2dcmp.r_data[9:7], {OPCODE_OP}};
                end

                2'b01: begin
                  // c.xor -> xor rd', rd', rs2'
                  dcmp2if.r_data = {7'b0, 2'b01, ralgn2dcmp.r_data[4:2], 2'b01, ralgn2dcmp.r_data[9:7], 3'b100,
                            2'b01, ralgn2dcmp.r_data[9:7], {OPCODE_OP}};
                end

                2'b10: begin
                  // c.or  -> or  rd', rd', rs2'
                  dcmp2if.r_data = {7'b0, 2'b01, ralgn2dcmp.r_data[4:2], 2'b01, ralgn2dcmp.r_data[9:7], 3'b110,
                            2'b01, ralgn2dcmp.r_data[9:7], {OPCODE_OP}};
                end

                2'b11: begin
                  // c.and -> and rd', rd', rs2'
                  dcmp2if.r_data = {7'b0, 2'b01, ralgn2dcmp.r_data[4:2], 2'b01, ralgn2dcmp.r_data[9:7], 3'b111,
                            2'b01, ralgn2dcmp.r_data[9:7], {OPCODE_OP}};
                end
              endcase
            end
          endcase
        end

        3'b110, 3'b111: begin
          // 0: c.beqz -> beq rs1', x0, imm
          // 1: c.bnez -> bne rs1', x0, imm
          dcmp2if.r_data = {{4 {ralgn2dcmp.r_data[12]}}, ralgn2dcmp.r_data[6:5], ralgn2dcmp.r_data[2], 5'b0, 2'b01,
                    ralgn2dcmp.r_data[9:7], 2'b00, ralgn2dcmp.r_data[13], ralgn2dcmp.r_data[11:10], ralgn2dcmp.r_data[4:3],
                    ralgn2dcmp.r_data[12], {OPCODE_BRANCH}};
        end
      endcase
    end

    // C2

    // Register address checks for RV32E are performed in the regular instruction decoder.
    // If this check fails, an illegal instruction exception is triggered and the controller
    // writes the actual faulting instruction to mtval.
    2'b10: begin
      unique case (ralgn2dcmp.r_data[15:14])
        2'b00: begin
          // c.slli -> slli rd, rd, shamt
          // (c.ssli hints are translated into a slli hint)
          dcmp2if.r_data = {7'b0, ralgn2dcmp.r_data[6:2], ralgn2dcmp.r_data[11:7], 3'b001, ralgn2dcmp.r_data[11:7], {OPCODE_OP_IMM}};
        end

        2'b01: begin
          // c.lwsp -> lw rd, imm(x2)
          dcmp2if.r_data = {4'b0, ralgn2dcmp.r_data[3:2], ralgn2dcmp.r_data[12], ralgn2dcmp.r_data[6:4], 2'b00, 5'h02,
                    3'b010, ralgn2dcmp.r_data[11:7], OPCODE_LOAD};
        end

        2'b10: begin
          if (ralgn2dcmp.r_data[12] == 1'b0) begin
            if (ralgn2dcmp.r_data[6:2] != 5'b0) begin
              // c.mv -> add rd/rs1, x0, rs2
              // (c.mv hints are translated into an add hint)
              dcmp2if.r_data = {7'b0, ralgn2dcmp.r_data[6:2], 5'b0, 3'b0, ralgn2dcmp.r_data[11:7], {OPCODE_OP}};
            end else begin
              // c.jr -> jalr x0, rd/rs1, 0
              dcmp2if.r_data = {12'b0, ralgn2dcmp.r_data[11:7], 3'b0, 5'b0, {OPCODE_JALR}};
            end
          end else begin
            if (ralgn2dcmp.r_data[6:2] != 5'b0) begin
              // c.add -> add rd, rd, rs2
              // (c.add hints are translated into an add hint)
              dcmp2if.r_data = {7'b0, ralgn2dcmp.r_data[6:2], ralgn2dcmp.r_data[11:7], 3'b0, ralgn2dcmp.r_data[11:7], {OPCODE_OP}};
            end else begin
              if (ralgn2dcmp.r_data[11:7] == 5'b0) begin
                // c.ebreak -> ebreak
                dcmp2if.r_data = {32'h00_10_00_73};
              end else begin
                // c.jalr -> jalr x1, rs1, 0
                dcmp2if.r_data = {12'b0, ralgn2dcmp.r_data[11:7], 3'b000, 5'b00001, {OPCODE_JALR}};
              end
            end
          end
        end

        2'b11: begin
          // c.swsp -> sw rs2, imm(x2)
          dcmp2if.r_data = {4'b0, ralgn2dcmp.r_data[8:7], ralgn2dcmp.r_data[12], ralgn2dcmp.r_data[6:2], 5'h02, 3'b010,
                    ralgn2dcmp.r_data[11:9], 2'b00, {OPCODE_STORE}};
        end
      endcase
    end

    // Incoming instruction is not compressed.
    2'b11: illegal_instr = 1'b1;
  endcase
end

assign dcmp2if.comp_ack = ~illegal_instr & ~req_kill_i;
assign dcmp2if.ack      = ralgn2dcmp.ack;

assign dcmp2if_o        = dcmp2if; 


endmodule : decompress
// Include some licensing info and file header 

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/M_EXT_defs.svh"

module muldiv (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // EXE <---> MUL interface
    input  wire type_exe2mul_s           exe2mul_i,

    input wire                           fwd2mul_stall_i,
    input wire                           fwd2mul_flush_i,

    // MUL <---> LSU interface
    output type_mul2lsu_s                mul2lsu_o
);


//============================= Local signals and their assignments =============================//
// Local control and data signal structures 
type_exe2mul_s                       exe2mul;
type_mul2lsu_s                       mul2lsu;

type_alu_m_ops_e                     alu_m_ops;

// ALU_M signals
logic  [`XLEN-1:0]                   alu_m_operand_1;
logic  [`XLEN-1:0]                   alu_m_operand_2;


logic                                alu_m_req_next, alu_m_req_ff;
logic                                alu_m_ack_next, alu_m_ack_ff, alu_m_ack_ff_ff;
logic  [`XLEN-1:0]                   alu_m_result_next;
logic  [`XLEN-1:0]                   alu_m_result_ff;

logic  [2*`XLEN-1:0]                 mult;
logic  [2*`XLEN-1:0]                 mult_ss;
logic  [2*`XLEN-1:0]                 mult_su;
logic  [`XLEN-1:0]                   div;
logic  [`XLEN-1:0]                   div_u;
logic  [`XLEN-1:0]                   rem;
logic  [`XLEN-1:0]                   rem_u;

assign exe2mul = exe2mul_i;

assign alu_m_ops       = type_alu_m_ops_e'(exe2mul.alu_m_ops);
assign alu_m_operand_1 = exe2mul.alu_operand_1;
assign alu_m_operand_2 = exe2mul.alu_operand_2;

assign alu_m_req_next            = |alu_m_ops;

always_comb begin
    mult    = alu_m_operand_1          * alu_m_operand_2;
    mult_ss = $signed(alu_m_operand_1) * $signed(alu_m_operand_2);
    mult_su = $signed(alu_m_operand_1) * alu_m_operand_2;
    div_u   = alu_m_operand_1          / alu_m_operand_2;
    div     = $signed(alu_m_operand_1) / $signed(alu_m_operand_2);
    rem_u   = alu_m_operand_1          % alu_m_operand_2;
    rem     = $signed(alu_m_operand_1) % $signed(alu_m_operand_2);
end

always_comb begin
    alu_m_result_next = '0;
    alu_m_ack_next    = '0;

    case (alu_m_ops)
        ALU_M_OPS_MUL    : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult_ss[31:0];
        end
        ALU_M_OPS_MULH   : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult_ss[63:32];
        end
        ALU_M_OPS_MULHSU : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult_su[63:32];
        end
        ALU_M_OPS_MULHU  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult[63:32];
        end
        ALU_M_OPS_DIV  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = div;
        end
        ALU_M_OPS_DIVU  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = div_u;
        end
        ALU_M_OPS_REM  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = rem;
        end
        ALU_M_OPS_REMU  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = rem_u;
        end
        default : begin
            alu_m_ack_next    = 1'b0;
            alu_m_result_next = '0;
        end
    endcase
end

always_ff @(negedge rst_n, posedge clk ) begin

    if (~rst_n | fwd2mul_flush_i) begin
        alu_m_req_ff    <= 1'b0;
        alu_m_result_ff <= '0;
    end else if (fwd2mul_stall_i) begin
        alu_m_result_ff <= alu_m_result_ff; 
        alu_m_req_ff    <= alu_m_req_ff;
    end else begin
        alu_m_result_ff <= alu_m_result_next; 
        alu_m_req_ff    <= alu_m_req_next;
    end
end


always_ff @(negedge rst_n, posedge clk ) begin

    if (~rst_n) begin
        alu_m_ack_ff <= 1'b0;       
    end else begin
        alu_m_ack_ff <= alu_m_req_next; 
    end
end


always_ff @(negedge rst_n, posedge clk ) begin

    if (~rst_n) begin
        alu_m_ack_ff_ff <= 1'b0;       
    end else begin
        alu_m_ack_ff_ff <= alu_m_ack_ff; 
    end
end

// Request from M-Extension
assign mul2lsu.alu_m_req    = alu_m_req_ff;
assign mul2lsu.alu_m_result = alu_m_result_ff;

// Response from M-Extension
assign mul2lsu.alu_m_ack    = alu_m_ack_ff_ff;

assign mul2lsu_o = mul2lsu;

endmodule
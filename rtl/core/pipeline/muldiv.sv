// Include some licensing info and file header 

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/M_EXT_defs.svh"

module muldiv (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // EXE <---> MUL interface
    input  wire type_exe2mul_data_s      exe2mul_data_i,
    input  wire type_exe2mul_ctrl_s      exe2mul_ctrl_i,            // Structure for control signals from decode to execute 

    // MUL <---> LSU interface
    output type_mul2lsu_data_s           mul2lsu_data_o,
    output type_mul2lsu_ctrl_s           mul2lsu_ctrl_o
);


//============================= Local signals and their assignments =============================//
// Local control and data signal structures 
type_exe2mul_ctrl_s                  exe2mul_ctrl;
type_exe2mul_data_s                  exe2mul_data;
type_mul2lsu_ctrl_s                  mul2lsu_ctrl;
type_mul2lsu_data_s                  mul2lsu_data;

type_alu_m_ops_e                     alu_m_operator;

// ALU_M signals
logic                                alu_m_res;
logic  [`XLEN-1:0]                   alu_m_operand_1;
logic  [`XLEN-1:0]                   alu_m_operand_2;
logic  [`XLEN-1:0]                   alu_m_result;
logic  [2*`XLEN-1:0]                 mult;
logic  [2*`XLEN-1:0]                 mult_ss;
logic  [2*`XLEN-1:0]                 mult_su;

assign exe2mul_data = exe2mul_data_i;
assign exe2mul_ctrl = exe2mul_ctrl_i;

assign alu_m_operator  = type_alu_m_ops_e'(exe2mul_ctrl.alu_m_ops);
assign alu_m_operand_1 = exe2mul_data.alu_operand_1;
assign alu_m_operand_2 = exe2mul_data.alu_operand_2;

always_comb begin
    mult    = alu_m_operand_1          * alu_m_operand_2;
    mult_ss = $signed(alu_m_operand_1) * $signed(alu_m_operand_2);
    mult_su = $signed(alu_m_operand_1) * alu_m_operand_2;
end

always_comb begin
    alu_m_result = '0;
    alu_m_res    = '0;
    case (alu_m_operator)
        ALU_M_OPS_MUL    : begin
            alu_m_res    = 1'b1;
            alu_m_result = mult_ss[31:0];
        end
        ALU_M_OPS_MULH   : begin
            alu_m_res    = 1'b1;
            alu_m_result = mult_ss[63:32];
        end
        ALU_M_OPS_MULHSU : begin
            alu_m_res    = 1'b1;
            alu_m_result = mult_su[63:32];
        end
        ALU_M_OPS_MULHU  : begin
            alu_m_res    = 1'b1;
            alu_m_result = mult[63:32];
        end
        default : begin
            alu_m_res    = 1'b0;
            alu_m_result = '0;
        end
    endcase
end

assign mul2lsu_data.alu_m_result = alu_m_result;
assign mul2lsu_ctrl.alu_m_res    = alu_m_res;

assign mul2lsu_data_o = mul2lsu_data;
assign mul2lsu_ctrl_o = mul2lsu_ctrl;

endmodule
// Include some licensing info and file header 
`ifndef VERILATOR
`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/M_EXT_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "M_EXT_defs.svh"
`endif

module muldiv (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // EXE <---> M-extension interface
    input  wire type_exe2mul_s           exe2mul_i,

    input wire                           fwd2mul_stall_i,
    input wire                           fwd2mul_flush_i,

    // M-extension <---> Forward-stall interface
    output type_mul2fwd_s                mul2fwd_o,

    output type_mul2wrb_s                mul2wrb_o
);


//============================= Local signals and their assignments =============================//
// Local control and data signal structures 
type_exe2mul_s                       exe2mul;
type_mul2fwd_s                       mul2fwd;
type_mul2wrb_s                       mul2wrb;

type_alu_m_ops_e                     alu_m_ops;
type_alu_m_ops_e                     alu_m_ops_ff;
logic                                alu_m_ops_en;

// ALU_M signals
logic  [`XLEN-1:0]                   alu_m_operand_1;
logic  [`XLEN-1:0]                   alu_m_operand_2;
logic  [`XLEN-1:0]                   alu_m_operand_1_ff;
logic  [`XLEN-1:0]                   alu_m_operand_2_ff;
logic                                alu_m_operand_1_en;
logic                                alu_m_operand_2_en;


logic                                alu_m_req_next, alu_m_req_ff;
logic                                alu_m_ack_next, alu_m_ack_ff, alu_m_ack_ff_ff;
logic  [`XLEN-1:0]                   alu_m_result_next;
logic  [`XLEN-1:0]                   alu_m_result_ff;

logic  [2*`XLEN-1:0]                 mult;
logic  [2*`XLEN-1:0]                 mult_ss;
logic  [2*`XLEN-1:0]                 mult_su;
logic  [2*`XLEN-1:0]                 mult_su_int;
logic  [`XLEN-1:0]                   div;
logic  [`XLEN-1:0]                   div_u;
logic  [`XLEN-1:0]                   rem;
logic  [`XLEN-1:0]                   rem_u;
logic                                div_start_ff;
logic                                div_done;
logic                                div_valid;

type_muldiv_states_e                 state, state_next;

assign exe2mul = exe2mul_i;

assign alu_m_ops       = type_alu_m_ops_e'(exe2mul.alu_m_ops);
assign alu_m_operand_1 = exe2mul.alu_operand_1;
assign alu_m_operand_2 = exe2mul.alu_operand_2;
assign alu_m_operand_2_ff_is_zero = !(|alu_m_operand_2_ff);

assign alu_m_req_next            = |alu_m_ops || |alu_m_ops_ff;

always_ff @( posedge clk ) begin 
    if ( ~rst_n ) begin
        div_start_ff <= 0;
    end else begin
        div_start_ff <= alu_m_ops_en && alu_m_ops[3];
    end
end

always_ff @( posedge clk ) begin 
    if (~rst_n) begin
        alu_m_operand_1_ff <= '0;
    end else if (alu_m_operand_1_en) begin
        if ( alu_m_ops == ALU_M_OPS_DIV ||  alu_m_ops == ALU_M_OPS_REM) begin
            alu_m_operand_1_ff <= alu_m_operand_1[`XLEN-1] ? (~alu_m_operand_1+1) : alu_m_operand_1;
        end else begin
            alu_m_operand_1_ff <= alu_m_operand_1;
        end
    end
end

always_ff @( posedge clk ) begin 
    if (~rst_n) begin
        alu_m_operand_2_ff <= '0;
    end else if (alu_m_operand_2_en) begin
        if ( alu_m_ops == ALU_M_OPS_DIV ||  alu_m_ops == ALU_M_OPS_REM) begin
            alu_m_operand_2_ff <= alu_m_operand_2[`XLEN-1] ? (~alu_m_operand_2+1) : alu_m_operand_2;
        end else begin
            alu_m_operand_2_ff <= alu_m_operand_2;
        end
    end
end

always_ff @( posedge clk ) begin 
    if (~rst_n) begin
        alu_m_ops_ff <= ALU_M_OPS_NONE;
    end else if (alu_m_ops_en) begin
        alu_m_ops_ff <= alu_m_ops;
    end
end

always_ff @( posedge clk ) begin
    if (~rst_n) begin
        state <= MULDIV_IDLE;
    end else begin
        state <= state_next;
    end
end

divu_int divider_module( // width of numbers in bits
    .clk(clk),              // clock
    .rst(rst_n),              // reset
    .start(div_start_ff),            // start calculation
    .done(div_done),             // calculation is complete (high for one tick)
    .valid(div_valid),            // result is valid
    .a(alu_m_operand_1_ff),    // dividend (numerator)
    .b(alu_m_operand_2_ff),    // divisor (denominator)
    .val(div_u),  // result value: quotient
    .rem(rem_u)   // result: remainder
    );

always_comb begin
    alu_m_operand_1_en = '0;
    alu_m_operand_2_en = '0;
    alu_m_ops_en       = '0;
    case (state)
        MULDIV_IDLE: begin
            if (alu_m_req_next) begin
                state_next = MULDIV_START;
                alu_m_operand_1_en = '1;
                alu_m_operand_2_en = '1;
                alu_m_ops_en       = '1;
            end else begin
                state_next = MULDIV_IDLE;
            end
        end
        MULDIV_START: begin
            if(alu_m_ack_next) begin
                if (alu_m_req_next) begin  // When another instruction comes
                    state_next = MULDIV_START;
                    alu_m_operand_1_en = '1;
                    alu_m_operand_2_en = '1;
                    alu_m_ops_en       = '1;
                end else begin
                    state_next = MULDIV_IDLE;
                end
            end else begin
                state_next = MULDIV_START;
            end
        end
    endcase
end

always_comb begin
    mult    = alu_m_operand_1_ff          * alu_m_operand_2_ff;
    mult_ss = $signed(alu_m_operand_1_ff) * $signed(alu_m_operand_2_ff);
   // mult_su = $signed(alu_m_operand_1_ff) * alu_m_operand_2_ff;
    mult_su = $signed(alu_m_operand_1_ff[31] ? (~alu_m_operand_1_ff + 1) : alu_m_operand_1_ff) * (alu_m_operand_2_ff);

    // if(alu_m_operand_2_ff_is_zero) begin
    //     // div_u = {32{1'b1}};
    //     div   = {32{1'b1}};
    //     rem   = alu_m_operand_1_ff;
    //     // rem_u = alu_m_operand_1_ff;
    // end else begin
    //     // div_u   = alu_m_operand_1_ff          / alu_m_operand_2_ff;
    //     if(alu_m_operand_1_ff == (-2**31) && alu_m_operand_2_ff == -1) begin
    //         div = alu_m_operand_1_ff;
    //         rem = '0;
    //     end else begin 
    //         div     = $signed(alu_m_operand_1_ff) / $signed(alu_m_operand_2_ff);
    //         rem     = $signed(alu_m_operand_1_ff) % $signed(alu_m_operand_2_ff);
    //     end
    //     // rem_u   = alu_m_operand_1_ff          % alu_m_operand_2_ff;
    // end
end

always_comb begin
    alu_m_result_next = '0;
    alu_m_ack_next    = '0;

    case (alu_m_ops_ff)
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
            mult_su_int       = alu_m_operand_1_ff[31] ? (~mult_su + 1) : mult_su;
            alu_m_result_next = mult_su_int[63:32];
        end
        ALU_M_OPS_MULHU  : begin
            alu_m_ack_next    = 1'b1;
            alu_m_result_next = mult[63:32];
        end
        ALU_M_OPS_DIV  : begin
            alu_m_ack_next    = div_valid && div_done;
            alu_m_result_next = ((alu_m_operand_1_ff[`XLEN-1] ^ alu_m_operand_1_ff[`XLEN-1]) && div_u[`XLEN-1] ) ? (~div_u+1): div_u;
        end
        ALU_M_OPS_DIVU  : begin
            alu_m_ack_next    = div_valid && div_done;
            alu_m_result_next = div_u;
        end
        ALU_M_OPS_REM  : begin
            alu_m_ack_next    = div_valid && div_done;
            alu_m_result_next = ((alu_m_operand_1_ff[`XLEN-1] ^ alu_m_operand_1_ff[`XLEN-1]) && rem_u[`XLEN-1] ) ? (~rem_u+1): rem_u;
        end
        ALU_M_OPS_REMU  : begin
            alu_m_ack_next    = div_valid && div_done;
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
        alu_m_ack_ff <= alu_m_ack_next; 
    end
end


always_ff @(negedge rst_n, posedge clk ) begin

    if (~rst_n) begin
        alu_m_ack_ff_ff <= 1'b0;       
    end else begin
        alu_m_ack_ff_ff <= alu_m_ack_ff; 
    end
end

// Request from M-extension
assign mul2fwd.mul_req    = alu_m_req_next;

// Response from M-extension
assign mul2wrb.alu_m_result = alu_m_result_next;
assign mul2fwd.mul_ack    = alu_m_ack_next;

assign mul2fwd_o = mul2fwd;
assign mul2wrb_o = mul2wrb;

endmodule

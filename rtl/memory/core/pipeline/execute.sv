`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module execute (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // ID <---> EXE interface
    input  wire type_id2exe_data_s           id2exu_data_i,
    input  wire type_id2exe_ctrl_s           id2exu_ctrl_i,              // Structure for control signals from decode to execute 

    // EXE <---> MEM interface
    output type_exe2mem_data_s          exe2mem_data_o,
    output type_exe2mem_ctrl_s          exe2mem_ctrl_o
);


// Local signals
type_id2exe_ctrl_s                   id2exu_ctrl;
type_id2exe_data_s                   id2exu_data;
type_alu_ops_sel_e                   alu_operator;

logic  [`XLEN-1:0]                   rs1_operand;
logic  [`XLEN-1:0]                   rs2_operand;
logic  [`XLEN-1:0]                   exe2mem_alu_result;
logic  [`XLEN-1:0]                   alu_adder_out;
logic  [`XLEN-1:0]                   alu_shifter_out;
logic  [`XLEN-1:0]                   alu_compare_out;
logic  [4:0]                         shift_amt;
logic                                illegal_instr;
logic                                sign_bit;
logic                                is_less;


// Instantiate input control and data structures and get the ALU operator
assign alu_operator   =   type_alu_ops_sel_e'(id2exu_ctrl_i.alu_ops);
assign id2exu_ctrl    =   id2exu_ctrl_i;
assign id2exu_data    =   id2exu_data_i;

   // Prepare the two operands
   always_comb begin
          rs1_operand = (id2exu_ctrl.alu_opr1_sel  ==   ALU_OPR1_PC)
                      ? (id2exu_data.pc)                            // Operand 1 is PC
                      : (id2exu_data.rs1_data);                     // Operand 1 is register

 
          rs2_operand = (id2exu_ctrl.alu_opr2_sel  ==   ALU_OPR2_IMM)
                      ? (id2exu_data.imm)                           // Operand 2 is immediate
                      : (id2exu_data.rs2_data);                     // Operand 2 is register
 
   end


   // Implementation of different ALU operations
   // Addition and subtraction
   always_comb begin
          alu_adder_out = (alu_operator != ALU_OPS_ADD)
                      ? ({1'b0, rs1_operand} - {1'b0, rs2_operand})   // Subtraction and comparison
                      : ({1'b0, rs1_operand} + {1'b0, rs2_operand});  // Addition
 
   end
 
   // Comparison for rs1 less than rs2 (valid for both signed and unsigned)
   always_comb begin
          sign_bit = 1'b0;

          if ((alu_operator == ALU_OPS_SLT) || (alu_operator == ALU_OPS_BLT) || (alu_operator == ALU_OPS_BGE)) begin
              sign_bit = 1'b1;
          end

          is_less  = ($signed({sign_bit & rs1_operand[`XLEN-1], rs1_operand})  <  $signed({sign_bit & rs2_operand[`XLEN-1], rs2_operand}));
   end


   // Operand for shift operations 
   always_comb begin
           shift_amt   =   rs2_operand[4:0];
   end

   // MUX for output result 
   always_comb begin
        exe2mem_alu_result   =  '0;

        case (alu_operator)
            ALU_OPS_AND : begin
                exe2mem_alu_result   =   rs1_operand & rs2_operand;
            end
            ALU_OPS_OR : begin
                exe2mem_alu_result   =   rs1_operand | rs2_operand;
            end
            ALU_OPS_XOR : begin
                exe2mem_alu_result   =   rs1_operand ^ rs2_operand;
            end
            ALU_OPS_ADD : begin
                exe2mem_alu_result   =   alu_adder_out;
            end
            ALU_OPS_SUB : begin
                exe2mem_alu_result   =   alu_adder_out;
            end
            ALU_OPS_SRL : begin
                exe2mem_alu_result   =   rs1_operand >> shift_amt;
            end

           
         

         

            default: ; // default case to suppress warning
        endcase
   end

// Update the output data signals
assign exe2mem_data_o.alu_result   =   exe2mem_alu_result;
assign exe2mem_data_o.instr        =   id2exu_data.instr;
assign exe2mem_data_o.pc           =   id2exu_data.pc;
assign exe2mem_data_o.rs2_data     =   id2exu_data.rs2_data; // MT: This should be updated when implementing forwarding

// Assign the control signals 
assign exe2mem_ctrl_o.rd_wb_sel    =   id2exu_ctrl.rd_wb_sel;
assign exe2mem_ctrl_o.mem_ops      =   id2exu_ctrl.mem_ops;
assign exe2mem_ctrl_o.rd_wr_req    =   id2exu_ctrl.rd_wr_req;
assign exe2mem_ctrl_o.jump_req     =   id2exu_ctrl.jump_req;                          
assign exe2mem_ctrl_o.branch_req   =   id2exu_ctrl.branch_req;                          
assign exe2mem_ctrl_o.mret_req     =   id2exu_ctrl.mret_req;                      
assign exe2mem_ctrl_o.fencei_req   =   id2exu_ctrl.fencei_req;                         
assign exe2mem_ctrl_o.wfi_req      =   id2exu_ctrl.wfi_req;                    

endmodule: execute


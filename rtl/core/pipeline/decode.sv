`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module decode (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // Fetch <---> Decode interface
    input   logic [`XLEN-1:0]            if2id_pc_i,              // pc from fetch stage
    input   logic [`XLEN-1:0]            if2id_instr_i,           // Instruction from IF module
//    input   logic                        if2id_err_i,             // Instruction access fault 

    output  logic                        id2if_rdy_o,             // Ready signal from ID module 
//    input   logic                        if2id_valid_i,           // Valid response from IF module

    // Decode <---> Execute interface
    output  type_id2exe_data_s           id2exe_data_o,
    output  type_id2exe_ctrl_s           id2exe_ctrl_o,             // Structure for control signals  

    // Writeback <---> Decode feedback interface
    input   logic                        wb2id_rd_wr_req_i,        // write request
    input   logic [`RF_AWIDTH-1:0]       wb2id_rd_addr_i,          // rd write address
    input   logic [`XLEN-1:0]            wb2id_rd_data_i           // rd write data from write-back

);


// Local signals
logic [`RF_AWIDTH-1:0]               id2rf_rs1_addr;            // RF rs1 address
logic [`RF_AWIDTH-1:0]               id2rf_rs2_addr;            // RF rs2 address
logic [`RF_AWIDTH-1:0]               id2exe_rd_addr;            // RF rd address

logic                                illegal_instr;
logic [`XLEN-1:0]                    instr_codeword;
logic [`XLEN-1:0]                    rf2id_rs1_data;            // RF rs1 data
logic [`XLEN-1:0]                    rf2id_rs2_data;            // RF rs2 data

logic [2:0]                          funct3_opcode;
logic [6:0]                          funct7_opcode;
logic [11:0]                         funct12_opcode;
logic [4:0]                          shift_amt;

type_rv_opcode_e                     instr_opcode;
type_id2exe_ctrl_s                   id2exe_ctrl;
type_id2exe_data_s                   id2exe_data;

// Instruction opcodes
assign instr_codeword = if2id_instr_i;
assign instr_opcode   = type_rv_opcode_e'(instr_codeword[6:2]); 
assign funct7_opcode  = instr_codeword[31:25];
assign funct3_opcode  = instr_codeword[14:12];

// Register file related decodings
assign id2rf_rs1_addr = instr_codeword[19:15];
assign id2rf_rs2_addr = instr_codeword[24:20];
assign id2exe_rd_addr = instr_codeword[11:7];

assign shift_amt      = instr_codeword[24:20]; 


// Defining decoder logic for control signals and preparing datapath signals
always_comb begin
    // Default values for control signals
    id2exe_ctrl.alu_ops          = ALU_OPS_NONE;
    id2exe_ctrl.rd_wb_sel        = RD_WB_NONE;
    id2exe_ctrl.mem_ld_ops       = MEM_LD_OPS_NONE;
    id2exe_ctrl.mem_st_ops       = MEM_ST_OPS_NONE;
    id2exe_ctrl.branch_ops       = BR_NONE;
    id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_REG;
    id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_REG;
    id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
    id2exe_ctrl.rd_wr_req        = 1'b0;
    id2exe_ctrl.jump_req         = 1'b0;
    id2exe_ctrl.branch_req       = 1'b0;
    id2exe_ctrl.mret_req         = 1'b0;
    id2exe_ctrl.fencei_req       = 1'b0;
    id2exe_ctrl.wfi_req          = 1'b0;

    // Default values for datapath signals
    id2exe_data.imm      = {{21{instr_codeword[31]}}, instr_codeword[30:20]};
    id2exe_data.rs1_data = rf2id_rs1_data;   // These operands need to be updated in case of forwarding
    id2exe_data.rs2_data = rf2id_rs2_data;   // These operands need to be updated in case of forwarding
    id2exe_data.instr    = instr_codeword;
    id2exe_data.pc       = if2id_pc_i;
    
    // Default values for local signals
    illegal_instr        = 1'b0;

    // Check for Instruction Memory fault
 /*   if (if2id_err_i) begin
        id2exe_cmd_o.exc_req     = 1'b1;
        id2exe_cmd_o.exc_code    = ERR_CODE_IMEM_FAULT;
        
    end else begin  // no imem fault
 */       

         case (instr_opcode)
             OPCODE_ARITH_INST  : begin
                 
                 id2exe_ctrl.rd_wb_sel        = RD_WB_ALU;
                 id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_REG;
                 id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_REG;
                 id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
                 id2exe_ctrl.rd_wr_req        = 1'b1;

                 case (funct7_opcode)
                            7'b0000000 : begin
                                case (funct3_opcode)
                                    3'b000 : id2exe_ctrl.alu_ops = ALU_OPS_ADD;   // ADD
                                    3'b001 : id2exe_ctrl.alu_ops = ALU_OPS_SLL;   // Shift Left Logical
                                    3'b010 : id2exe_ctrl.alu_ops = ALU_OPS_SLT;   // Set Less Than
                                    3'b011 : id2exe_ctrl.alu_ops = ALU_OPS_SLTU;  // Set Less Than Unsigned
                                    3'b100 : id2exe_ctrl.alu_ops = ALU_OPS_XOR;   // XOR Logical
                                    3'b101 : id2exe_ctrl.alu_ops = ALU_OPS_SRL;   // Shift Right Logical 
                                    3'b110 : id2exe_ctrl.alu_ops = ALU_OPS_OR;    // OR Logical
                                    3'b111 : id2exe_ctrl.alu_ops = ALU_OPS_AND;   // AND Logical
                                endcase // funct3_opcode
                            end // 7'b0000000

                            7'b0100000 : begin
                                case (funct3_opcode)
                                    3'b000  : id2exe_ctrl.alu_ops = ALU_OPS_SUB;
                                    3'b101  : id2exe_ctrl.alu_ops = ALU_OPS_SRA;
                                    default : illegal_instr       = 1'b1;
                                endcase // funct3_opcode
                            end // 7'b0100000
`ifdef RISCV_M_EXT
                            7'b0000001 : begin
                                case (funct3_opcode)
                                    3'b000 : id2exe_ctrl.alu_ops = ALU_OPS_MUL;
                                    3'b001 : id2exe_ctrl.alu_ops = ALU_OPS_MULH;
                                    3'b010 : id2exe_ctrl.alu_ops = ALU_OPS_MULSU;
                                    3'b011 : id2exe_ctrl.alu_ops = ALU_OPS_MULHU;
                                    3'b100 : id2exe_ctrl.alu_ops = ALU_OPS_DIV;
                                    3'b101 : id2exe_ctrl.alu_ops = ALU_OPS_DIVU;
                                    3'b110 : id2exe_ctrl.alu_ops = ALU_OPS_REM;
                                    3'b111 : id2exe_ctrl.alu_ops = ALU_OPS_REMU;
                                endcase // funct3_opcode
                            end // 7'b0000001
`endif  // RISCV_M_EXT
                            default : illegal_instr = 1'b1;
                 endcase // funct7_opcode
                 
             end // OPCODE_ARITH_INST


             // IMM operation
             OPCODE_IMM_INST : begin
 
                 id2exe_ctrl.rd_wb_sel        =   RD_WB_ALU;
                 id2exe_ctrl.alu_opr1_sel     =   ALU_OPR1_REG;
                 id2exe_ctrl.alu_opr2_sel     =   ALU_OPR2_IMM;
                 id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_IMM;
                 id2exe_ctrl.rd_wr_req        =   1'b1;

                 case (funct3_opcode)
                            3'b000 : id2exe_ctrl.alu_ops = ALU_OPS_ADD;           // ADD Immediate
                            3'b010 : id2exe_ctrl.alu_ops = ALU_OPS_SLT;           // SLT Immediate
                            3'b011 : id2exe_ctrl.alu_ops = ALU_OPS_SLTU;          // SLTU Immediate 
                            3'b100 : id2exe_ctrl.alu_ops = ALU_OPS_XOR;           // XOR Immediate
                            3'b110 : id2exe_ctrl.alu_ops = ALU_OPS_OR;            // OR Immediate
                            3'b111 : id2exe_ctrl.alu_ops = ALU_OPS_AND;           // AND Immediate
                            3'b001 : begin
                                      id2exe_data.imm     = `XLEN'(shift_amt);     // Zero Extend the shift amount
                                      id2exe_ctrl.alu_ops = ALU_OPS_SLL;           // Shift Left Logical Immediate
                            end
                            3'b101 : begin
                                case (funct7_opcode)
                                    
                                    7'b0000000 : begin
                                        id2exe_data.imm     = `XLEN'(shift_amt);   
                                        id2exe_ctrl.alu_ops = ALU_OPS_SRL;          // Shift Right Logical Immediate
                                    end
                                 
                                    7'b0100000 : begin
                                        id2exe_data.imm     = `XLEN'(shift_amt);   
                                        id2exe_ctrl.alu_ops = ALU_OPS_SRA;          // Shift Right Arithmetic Immediate
                                    end
                                    
                                    default : illegal_instr  =  1'b1;
                                endcase // funct7_opcode
                            end
                  endcase // funct3_opcode
                
             end // OPCODE_IMM_INST


             // AUIPC operation
             OPCODE_AUIPC_INST : begin
                 id2exe_ctrl.rd_wb_sel    = RD_WB_ALU;
                 id2exe_ctrl.alu_opr1_sel = ALU_OPR1_PC;
                 id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_ops      = ALU_OPS_ADD;
                 id2exe_ctrl.rd_wr_req    = 1'b1;                 
                 id2exe_data.imm          = {instr_codeword[31:12], 12'b0};
                
             end // OPCODE_AUIPC_INST


             // LUI operation
             OPCODE_LUI_INST : begin
                 id2exe_ctrl.rd_wb_sel    = RD_WB_ALU;
                 id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_ops      = ALU_OPS_COPY_OPR2;
                 id2exe_ctrl.rd_wr_req    = 1'b1;                
                 id2exe_data.imm          = {instr_codeword[31:12], 12'b0};

                
             end // OPCODE_LUI_INST

             // Load operations
             OPCODE_LOAD_INST : begin
                 id2exe_ctrl.rd_wb_sel    = RD_WB_MEM;
                 id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                 id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_ops      = ALU_OPS_ADD;
                 id2exe_ctrl.rd_wr_req    = 1'b1;

                 case (funct3_opcode)
                            3'b000  : id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_LB;            // Load byte signed
                            3'b001  : id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_LH;            // Load halfword signed 
                            3'b010  : id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_LW;            // Load word  
                            3'b100  : id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_LBU;           // Load byte unsigned 
                            3'b101  : id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_LHU;           // Load halfword unsigned 
                            default : id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_NONE;          // Load type unknown 
                 endcase // funct3_opcode
                
             end // OPCODE_LOAD_INST

             // Store operations
             OPCODE_STORE_INST : begin
                 id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                 id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_ops      = ALU_OPS_ADD;
                 id2exe_data.imm          = {{21{instr_codeword[31]}}, instr_codeword[30:25], instr_codeword[11:7]};

                 case (funct3_opcode)
                            3'b000  : id2exe_ctrl.mem_st_ops = MEM_ST_OPS_SB;            // Store byte signed
                            3'b001  : id2exe_ctrl.mem_st_ops = MEM_ST_OPS_SH;            // Store halfword signed 
                            3'b010  : id2exe_ctrl.mem_st_ops = MEM_ST_OPS_SW;            // Store word
                            default : id2exe_ctrl.mem_st_ops = MEM_ST_OPS_NONE;          // Store word  
                 endcase // funct3_opcode
                           
             end // OPCODE_STORE_INST

             // Other memory operations
             OPCODE_MEM_FENCE_INST : begin

 

                
             end // OPCODE_MEM_INST

             // Branch operation
             OPCODE_BRANCH_INST : begin
                 id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_PC;
                 id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
                 id2exe_ctrl.alu_ops          = ALU_OPS_ADD;
                 id2exe_ctrl.branch_req       = 1'b1;
                 id2exe_data.imm              = {{20{instr_codeword[31]}}, instr_codeword[7], instr_codeword[30:25], instr_codeword[11:8], 1'b0};

                 case (funct3_opcode)
                            3'b000  : id2exe_ctrl.branch_ops = BR_EQ;            // Branch equal
                            3'b001  : id2exe_ctrl.branch_ops = BR_NE;            // Branch not equal 
                            3'b100  : id2exe_ctrl.branch_ops = BR_LT;            // Branch less than 
                            3'b101  : id2exe_ctrl.branch_ops = BR_GE;            // Branch greater than or equal signed
                            3'b110  : id2exe_ctrl.branch_ops = BR_LTU;           // Branch less than unsigned 
                            3'b111  : id2exe_ctrl.branch_ops = BR_GEU;           // Branch greater than or equal unsigned
                            default : id2exe_ctrl.branch_ops = BR_NONE;          // No branch  
                 endcase // funct3_opcode
                           
             end // OPCODE_BRANCH_INST


             // JALR operation
             OPCODE_JALR_INST : begin
                 id2exe_ctrl.rd_wb_sel    = RD_WB_INC_PC;
                 id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                 id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_ops      = ALU_OPS_ADD;
                 id2exe_ctrl.rd_wr_req    = 1'b1;
                 id2exe_ctrl.jump_req     = 1'b1;
            //     id2exe_data.imm           =   {{12{instr_codeword[31]}}, instr_codeword[19:12], instr_codeword[20], instr_codeword[30:21], 1'b0};
                
             end // OPCODE_JALR_INST

             // JAL operation
             OPCODE_JAL_INST : begin
                 id2exe_ctrl.rd_wb_sel    = RD_WB_INC_PC;
                 id2exe_ctrl.alu_opr1_sel = ALU_OPR1_PC;
                 id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                 id2exe_ctrl.alu_ops      = ALU_OPS_ADD;
                 id2exe_ctrl.rd_wr_req    = 1'b1;
                 id2exe_ctrl.jump_req     = 1'b1;
                 id2exe_data.imm          = {{12{instr_codeword[31]}}, instr_codeword[19:12], instr_codeword[20], instr_codeword[30:21], 1'b0};

                
             end // OPCODE_JAL_INST

             // SYS operations
             OPCODE_SYSTEM_INST : begin

 

                
             end // OPCODE_SYS_INST


             default : begin
                illegal_instr = 1'b1;
             end

         endcase // Instruction Opcode 
 

   // Handle the illegal instruction
   if(illegal_instr)  begin
      id2exe_ctrl.alu_ops    = ALU_OPS_NONE;
      id2exe_ctrl.rd_wb_sel  = RD_WB_NONE;
      id2exe_ctrl.mem_ld_ops = MEM_LD_OPS_NONE;
      id2exe_ctrl.mem_st_ops = MEM_ST_OPS_NONE;
      id2exe_ctrl.jump_req   = 1'b0;
      id2exe_ctrl.branch_req = 1'b0;
      id2exe_ctrl.mret_req   = 1'b0;
      id2exe_ctrl.fencei_req = 1'b0;
      id2exe_ctrl.wfi_req    = 1'b0;
      id2exe_ctrl.rd_wr_req  = 1'b0;

   end

end // Decoder logic

// MT TODO: Feedforward (pipeline) signals should be made configurable for enabling/disabling pipeline stage 
assign id2exe_ctrl_o          =   id2exe_ctrl;
assign id2exe_data_o          =   id2exe_data; 

// Feedback signals
assign id2if_rdy_o            =   '1;


// Instantiation of register file
reg_file rf_module (
    .rst_n                (rst_n            ),
    .clk                  (clk              ),

    // ID <---> RF interface
    .id2rf_rs1_addr_i     (id2rf_rs1_addr),
    .rf2id_rs1_data_o     (rf2id_rs1_data),
    .id2rf_rs2_addr_i     (id2rf_rs2_addr),
    .rf2id_rs2_data_o     (rf2id_rs2_data),
    .id2rf_rd_wr_req_i    (wb2id_rd_wr_req_i),
    .id2rf_rd_addr_i      (wb2id_rd_addr_i ),
    .id2rf_rd_data_i      (wb2id_rd_data_i )
);


endmodule : decode


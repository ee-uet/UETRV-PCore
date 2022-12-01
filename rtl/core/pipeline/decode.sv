<<<<<<< HEAD
`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module decode (

    input   logic                             rst_n,                  // reset
    input   logic                             clk,                    // clock

    // Fetch <---> Decode interface
    input wire type_if2id_data_s              if2id_data_i,
    input wire type_if2id_ctrl_s              if2id_ctrl_i,

    // Decode <---> Execute interface
    output  type_id2exe_data_s                id2exe_data_o,
    output  type_id2exe_ctrl_s                id2exe_ctrl_o,          // Structure for control signals  

    // Writeback <---> Decode feedback interface
    input wire type_wrb2id_fb_s               wrb2id_fb_i
);

//============================= Local signals and their assignments =============================//
// Local signals
logic [`RF_AWIDTH-1:0]               id2rf_rs1_addr;            // RF rs1 address
logic [`RF_AWIDTH-1:0]               id2rf_rs2_addr;            // RF rs2 address
//logic [`RF_AWIDTH-1:0]               id2exe_rd_addr;            // RF rd address

logic [`XLEN-1:0]                    instr_codeword;
logic [`XLEN-1:0]                    rf2id_rs1_data;            // RF rs1 data
logic [`XLEN-1:0]                    rf2id_rs2_data;            // RF rs2 data

// 
logic                                illegal_instr;

logic [2:0]                          funct3_opcode;
logic [6:0]                          funct7_opcode;
logic [4:0]                          funct5_opcode;
logic [4:0]                          shift_amt;

// Control and data signal structures
type_if2id_ctrl_s                    if2id_ctrl;
type_if2id_data_s                    if2id_data;

type_id2exe_ctrl_s                   id2exe_ctrl;
type_id2exe_data_s                   id2exe_data;
type_rv_opcode_e                     instr_opcode;

// Input signal assigments
assign if2id_ctrl     = if2id_ctrl_i;
assign if2id_data     = if2id_data_i;

// Instruction opcodes
assign instr_codeword = if2id_data.instr;
assign instr_opcode   = type_rv_opcode_e'(instr_codeword[6:2]); 
assign funct7_opcode  = instr_codeword[31:25];
assign funct3_opcode  = instr_codeword[14:12];
assign funct5_opcode  = instr_codeword[24:20];

// Register file related decodings
assign id2rf_rs1_addr = instr_codeword[19:15];
assign id2rf_rs2_addr = instr_codeword[24:20];
//assign id2exe_rd_addr = instr_codeword[11:7];

assign shift_amt      = instr_codeword[24:20]; 

//========================== Decoder logic implementation for control signals ==========================//
always_comb begin

    // Define decoder logic for control signals and prepare datapath signals for
    // execution phase. Set to default values for control signals when decoding 
    // an instruction.  
 
    // Operation selecion for different modules
    id2exe_ctrl.alu_i_ops  = ALU_I_OPS_NONE;
    id2exe_ctrl.alu_m_ops  = ALU_M_OPS_NONE;
    id2exe_ctrl.ld_ops     = LD_OPS_NONE;
    id2exe_ctrl.st_ops     = ST_OPS_NONE;
    id2exe_ctrl.branch_ops = BR_OPS_NONE;
    id2exe_ctrl.csr_ops    = CSR_OPS_NONE;
    id2exe_ctrl.amo_ops    = AMO_OPS_NONE;
    id2exe_ctrl.sys_ops    = SYS_OPS_NONE;

    // Operand selection for different modules
    id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_PC;
    id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
    id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
    id2exe_ctrl.csr_opr_sel      = CSR_OPR_REG;
    id2exe_ctrl.sys_ops          = SYS_OPS_NONE;
    id2exe_ctrl.rd_wrb_sel       = RD_WRB_NONE;
    id2exe_ctrl.exc_code         = EXC_CODE_NO_EXCEPTION;
    id2exe_ctrl.rd_wr_req        = 1'b0;
    id2exe_ctrl.jump_req         = 1'b0;
    id2exe_ctrl.branch_req       = 1'b0;
    id2exe_ctrl.exc_req          = 1'b0;
    id2exe_ctrl.fence_i_req      = 1'b0;

    // Default values for datapath signals
    id2exe_data.imm      = {{21{instr_codeword[31]}}, instr_codeword[30:20]};
    id2exe_data.rs1_data = rf2id_rs1_data;   // These operands need to be updated in case of forwarding
    id2exe_data.rs2_data = rf2id_rs2_data;   // These operands need to be updated in case of forwarding
    id2exe_data.instr    = instr_codeword;
    id2exe_data.pc       = if2id_data.pc;
    id2exe_data.pc_next  = if2id_data.pc_next;
    id2exe_data.instr_flushed = if2id_data.instr_flushed;
    
    // Default values for local signals
    illegal_instr       = 1'b0;

    // Check for instruction memory access fault
    if (if2id_ctrl.exc_req) begin
        id2exe_ctrl.exc_req  = 1'b1;
        id2exe_ctrl.exc_code = if2id_ctrl.exc_code;    
        
    end else begin  // no instruction memory access fault
        case (instr_opcode)
            OPCODE_ARITH_INST  : begin
                
                id2exe_ctrl.rd_wrb_sel       = RD_WRB_ALU;
                id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_REG;
                id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
                id2exe_ctrl.rd_wr_req        = 1'b1;
                 case (funct7_opcode)
                    7'b0000000 : begin
                        case (funct3_opcode)
                            3'b000 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_ADD;   // ADD
                            3'b001 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLL;   // Shift Left Logical
                            3'b010 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLT;   // Set Less Than
                            3'b011 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLTU;  // Set Less Than Unsigned
                            3'b100 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_XOR;   // XOR Logical
                            3'b101 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRL;   // Shift Right Logical 
                            3'b110 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_OR;    // OR Logical
                            3'b111 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_AND;   // AND Logical
                        endcase // funct3_opcode
                    end // 7'b0000000
                     7'b0100000 : begin
                        case (funct3_opcode)
                            3'b000  : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SUB;
                            3'b101  : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRA;
                            default : illegal_instr       = 1'b1;
                        endcase // funct3_opcode
                    end // 7'b0100000

                    7'b0000001 : begin
                        id2exe_ctrl.rd_wrb_sel       = RD_WRB_M_ALU;
                        case (funct3_opcode)
                            3'b000 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MUL;
                            3'b001 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MULH;
                            3'b010 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MULHSU;
                            3'b011 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MULHU;
                            3'b100 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_DIV;
                            3'b101 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_DIVU;
                            3'b110 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_REM;
                            3'b111 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_REMU;
                        endcase // funct3_opcode
                    end // 7'b0000001

                    default : illegal_instr = 1'b1;
                endcase // funct7_opcode
               
            end // OPCODE_ARITH_INST

            // IMM operation
            OPCODE_IMM_INST : begin

                id2exe_ctrl.rd_wrb_sel       = RD_WRB_ALU;
                id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
                id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_IMM;
                id2exe_ctrl.rd_wr_req        = 1'b1;
                case (funct3_opcode)
                    3'b000 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_ADD;           // ADD Immediate
                    3'b010 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLT;           // SLT Immediate
                    3'b011 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLTU;          // SLTU Immediate 
                    3'b100 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_XOR;           // XOR Immediate
                    3'b110 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_OR;            // OR Immediate
                    3'b111 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_AND;           // AND Immediate
                    3'b001 : begin
                              id2exe_data.imm     = `XLEN'(shift_amt);     // Zero Extend the shift amount
                              id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLL;           // Shift Left Logical Immediate
                    end
                    3'b101 : begin
                        case (funct7_opcode)
                            
                            7'b0000000 : begin
                                id2exe_data.imm     = `XLEN'(shift_amt);   
                                id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRL;          // Shift Right Logical Immediate
                            end
                         
                            7'b0100000 : begin
                                id2exe_data.imm     = `XLEN'(shift_amt);   
                                id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRA;          // Shift Right Arithmetic Immediate
                            end
                            
                            default : illegal_instr  =  1'b1;
                        endcase // funct7_opcode
                    end
                endcase // funct3_opcode
               
            end // OPCODE_IMM_INST

            // AUIPC operation
            OPCODE_AUIPC_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_ALU;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_PC;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;                 
                id2exe_data.imm          = {instr_codeword[31:12], 12'b0};
               
            end // OPCODE_AUIPC_INST

            // LUI operation
            OPCODE_LUI_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_ALU;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_COPY_OPR2;
                id2exe_ctrl.rd_wr_req    = 1'b1;                
                id2exe_data.imm          = {instr_codeword[31:12], 12'b0};
                
            end // OPCODE_LUI_INST
             // Load operations
            OPCODE_LOAD_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_DMEM;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;
                case (funct3_opcode)
                    3'b000  : id2exe_ctrl.ld_ops = LD_OPS_LB;            // Load byte signed
                    3'b001  : id2exe_ctrl.ld_ops = LD_OPS_LH;            // Load halfword signed 
                    3'b010  : id2exe_ctrl.ld_ops = LD_OPS_LW;            // Load word  
                    3'b100  : id2exe_ctrl.ld_ops = LD_OPS_LBU;           // Load byte unsigned 
                    3'b101  : id2exe_ctrl.ld_ops = LD_OPS_LHU;           // Load halfword unsigned 
                    default : illegal_instr      =  1'b1;                // Illegal instruction 
                endcase // funct3_opcode
               
            end // OPCODE_LOAD_INST
             // Store operations
            OPCODE_STORE_INST : begin
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_data.imm          = {{21{instr_codeword[31]}}, instr_codeword[30:25], instr_codeword[11:7]};
                case (funct3_opcode)
                    3'b000  : id2exe_ctrl.st_ops = ST_OPS_SB;            // Store byte signed
                    3'b001  : id2exe_ctrl.st_ops = ST_OPS_SH;            // Store halfword signed 
                    3'b010  : id2exe_ctrl.st_ops = ST_OPS_SW;            // Store word
                    default : illegal_instr      =  1'b1;                // Illegal instruction  
                endcase // funct3_opcode
                          
            end // OPCODE_STORE_INST

             // Memory fence operations
            OPCODE_MEM_FENCE_INST : begin
 
                case (funct3_opcode)
                    3'b000  : begin      end                             // fence instruction is effectively NOP
                    3'b001  : id2exe_ctrl.fence_i_req = 1'b1;            // fence.i leads to pipeline flush                     
                    default : illegal_instr           = 1'b1;            // Default case  
                endcase // funct3_opcode                
            end // OPCODE_MEM_FENCE_INST

             // Branch operation
            OPCODE_BRANCH_INST : begin
                id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_PC;
                id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
                id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
                id2exe_ctrl.alu_i_ops        = ALU_I_OPS_ADD;
                id2exe_ctrl.branch_req       = 1'b1;
                id2exe_data.imm              = {{20{instr_codeword[31]}}, instr_codeword[7], instr_codeword[30:25], instr_codeword[11:8], 1'b0};
                case (funct3_opcode)
                    3'b000  : id2exe_ctrl.branch_ops = BR_OPS_EQ;            // Branch equal
                    3'b001  : id2exe_ctrl.branch_ops = BR_OPS_NE;            // Branch not equal 
                    3'b100  : id2exe_ctrl.branch_ops = BR_OPS_LT;            // Branch less than 
                    3'b101  : id2exe_ctrl.branch_ops = BR_OPS_GE;            // Branch greater than or equal signed
                    3'b110  : id2exe_ctrl.branch_ops = BR_OPS_LTU;           // Branch less than unsigned 
                    3'b111  : id2exe_ctrl.branch_ops = BR_OPS_GEU;           // Branch greater than or equal unsigned
                    default : begin                                          // Illegal instruction  
                        illegal_instr          = 1'b1;
                        id2exe_ctrl.branch_req = 1'b0;
                    end
                endcase // funct3_opcode  */
                          
            end // OPCODE_BRANCH_INST

            // JALR operation
            OPCODE_JALR_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_INC_PC;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;
                id2exe_ctrl.jump_req     = 1'b1;
           //     id2exe_data.imm           =   {{12{instr_codeword[31]}}, instr_codeword[19:12], instr_codeword[20], instr_codeword[30:21], 1'b0};
               
            end // OPCODE_JALR_INST
             // JAL operation
            OPCODE_JAL_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_INC_PC;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_PC;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;
                id2exe_ctrl.jump_req     = 1'b1;
                id2exe_data.imm          = {{12{instr_codeword[31]}}, instr_codeword[19:12], instr_codeword[20], instr_codeword[30:21], 1'b0};
                
            end // OPCODE_JAL_INST
 
            // SYS operations
            OPCODE_SYSTEM_INST : begin
                case (funct3_opcode)
                    3'b001 : begin              // CSRRW
                        id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                        id2exe_ctrl.rd_wrb_sel   = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops      = CSR_OPS_WRITE;
                        id2exe_ctrl.csr_opr_sel  = CSR_OPR_REG;
                    end
                    3'b010 : begin              // CSRRS
                        id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                        id2exe_ctrl.rd_wrb_sel   = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops      = CSR_OPS_SET;
                        id2exe_ctrl.csr_opr_sel  = CSR_OPR_REG;
                    end
                    3'b011 : begin             // CSRRC
                        id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                        id2exe_ctrl.rd_wrb_sel   = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops      = CSR_OPS_CLEAR;
                        id2exe_ctrl.csr_opr_sel  = CSR_OPR_REG;
                    end
                    3'b101 : begin             // CSRIW
                        id2exe_ctrl.rd_wrb_sel  = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops     = CSR_OPS_WRITE;
                        id2exe_ctrl.csr_opr_sel = CSR_OPR_IMM;
                    end
                    3'b110 : begin             // CSRIS
                        id2exe_ctrl.rd_wrb_sel  = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops     = CSR_OPS_SET;
                        id2exe_ctrl.csr_opr_sel = CSR_OPR_IMM;
                    end
                    3'b111 : begin             // CSRIC
                        id2exe_ctrl.rd_wrb_sel  = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops     = CSR_OPS_CLEAR;
                        id2exe_ctrl.csr_opr_sel = CSR_OPR_IMM;
                    end
                    3'b000 : begin
                                                         
                        case (funct7_opcode)
                            7'b0000000 : begin        
                                case (funct5_opcode)
                                    5'b00000 : begin  // ECALL                     
                                        id2exe_ctrl.exc_req  = 1'b1;
                                        id2exe_ctrl.exc_code = EXC_CODE_ECALL_MMODE;
                                    end
                                    5'b00001 : begin  // EBREAK
                                        id2exe_ctrl.exc_req  = 1'b1;
                                        id2exe_ctrl.exc_code = EXC_CODE_BREAKPOINT;
                                    end
                                    default : illegal_instr  =  1'b1; 
                                endcase // funct5_opcode
                            end
                            7'b0001000 : begin        
                                case (funct5_opcode)
                                    5'b00010 : begin  // SRET                     
                                        id2exe_ctrl.sys_ops    = SYS_OPS_SRET;
                                    end
                                    5'b00101 : begin  // WFI
                                        id2exe_ctrl.sys_ops    = SYS_OPS_WFI;  
                                    end
                                    default : illegal_instr  =  1'b1; 
                                endcase // funct5_opcode                           
                            end
                            7'b0011000 : begin        // MRET
                                id2exe_ctrl.sys_ops    = SYS_OPS_MRET;                               
                            end
                            7'b0001001 : begin        // SFENCE.VMA
                                id2exe_ctrl.sys_ops    = SYS_OPS_SFENCE_VMA;                               
                            end
                            default : illegal_instr = 1'b1;
                        endcase // funct7_opcode
                         
                    end
                                    
                    default : illegal_instr = 1'b1;   // illegal instruction  
                endcase // funct3_opcode                                     
            end // OPCODE_SYS_INST

             // Atomic memory operations (AMO)
            OPCODE_AMO_INST : begin
             //   id2exe_ctrl.rd_wrb_sel   = RD_WRB_DMEM;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_REG;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_COPY_OPR1;
             //   id2exe_ctrl.rd_wr_req    = 1'b1;  

                if (funct3_opcode == 3'b010) begin              
                    case (funct7_opcode[6:2])
                        5'b00000  : id2exe_ctrl.amo_ops = AMO_OPS_ADD;                  // Atomic addition
                        5'b00001  : id2exe_ctrl.amo_ops = AMO_OPS_SWAP;                 // Atomic swap
                        5'b00010  : begin 
                            id2exe_ctrl.amo_ops = AMO_OPS_LR;                           // Load restricted                            
                            if (funct5_opcode != '0) illegal_instr = 1'b1;
                        end
                        5'b00011  : id2exe_ctrl.amo_ops = AMO_OPS_SC;                   // Store conditional
                        5'b00100  : id2exe_ctrl.amo_ops = AMO_OPS_XOR;                  // Atomic XOR
                        5'b01000  : id2exe_ctrl.amo_ops = AMO_OPS_OR;                   // Atomic OR
                        5'b01100  : id2exe_ctrl.amo_ops = AMO_OPS_AND;                  // Atomic AND
                        5'b10000  : id2exe_ctrl.amo_ops = AMO_OPS_MIN;                  // Atomic MIN
                        5'b10100  : id2exe_ctrl.amo_ops = AMO_OPS_MAX;                  // Atomic MAX
                        5'b11000  : id2exe_ctrl.amo_ops = AMO_OPS_MINU;                 // Atomic MIN unsigned
                        5'b11100  : id2exe_ctrl.amo_ops = AMO_OPS_MAXU;                 // Atomic MAX unsigned
                        default   : illegal_instr       = 1'b1;                         // Illegal instructio 
                    endcase // funct7_opcode[6:2]
                end else begin
                    illegal_instr = 1'b1;
                end  //
            end // OPCODE_AMO_INST

            default : begin
                illegal_instr = 1'b1;
            end
        endcase // instr_opcode (Instruction opcode) 
    end // no instruction memory fault

   // Handle the illegal instruction
  if(illegal_instr)  begin
     id2exe_ctrl.alu_i_ops   = ALU_I_OPS_NONE;
     id2exe_ctrl.alu_m_ops   = ALU_M_OPS_NONE;
     id2exe_ctrl.ld_ops      = LD_OPS_NONE;
     id2exe_ctrl.st_ops      = ST_OPS_NONE;
     id2exe_ctrl.branch_ops  = BR_OPS_NONE;
     id2exe_ctrl.csr_ops     = CSR_OPS_NONE;
     id2exe_ctrl.amo_ops     = AMO_OPS_NONE;
     id2exe_ctrl.sys_ops     = SYS_OPS_NONE;

     id2exe_ctrl.rd_wrb_sel  = RD_WRB_NONE;
     id2exe_ctrl.exc_code    = EXC_CODE_ILLEGAL_INSTR;
     id2exe_ctrl.exc_req     = 1'b1;
     id2exe_ctrl.rd_wr_req   = 1'b0;
     id2exe_ctrl.jump_req    = 1'b0;
     id2exe_ctrl.branch_req  = 1'b0;
     id2exe_ctrl.fence_i_req = 1'b0;
   end

    
end // Decoder logic

//=================================== Output signals update ====================================//

// MT TODO: Feedforward (pipeline) signals should be made configurable for enabling/disabling 
// pipeline stages 
assign id2exe_ctrl_o = id2exe_ctrl;
assign id2exe_data_o = id2exe_data; 

//================================ Instantiation of submodules =================================//
// Instantiation of register file
reg_file rf_module (
   .rst_n                (rst_n            ),
   .clk                  (clk              ),
    // ID <---> RF interface
   .id2rf_rs1_addr_i     (id2rf_rs1_addr),
   .rf2id_rs1_data_o     (rf2id_rs1_data),
   .id2rf_rs2_addr_i     (id2rf_rs2_addr),
   .rf2id_rs2_data_o     (rf2id_rs2_data),
   .id2rf_rd_wr_req_i    (wrb2id_fb_i.rd_wr_req),
   .id2rf_rd_addr_i      (wrb2id_fb_i.rd_addr ),
   .id2rf_rd_data_i      (wrb2id_fb_i.rd_data)
);


endmodule : decode

=======
//`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module decode (

    input   logic                             rst_n,                  // reset
    input   logic                             clk,                    // clock

    // Fetch <---> Decode interface
    input wire type_if2id_data_s              if2id_data_i,
    input wire type_if2id_ctrl_s              if2id_ctrl_i,

    // Decode <---> Execute interface
    output type_id2exe_data_s                 id2exe_data_o,
    output type_id2exe_ctrl_s                 id2exe_ctrl_o,          // Structure for control signals  

    // CSR <---> Decode feedback interface
    input wire type_csr2id_fb_s               csr2id_fb_i,

    // Writeback <---> Decode feedback interface
    input wire type_wrb2id_fb_s               wrb2id_fb_i
);

//============================= Local signals and their assignments =============================//
// Local signals
logic [`RF_AWIDTH-1:0]               id2rf_rs1_addr;            // RF rs1 address
logic [`RF_AWIDTH-1:0]               id2rf_rs2_addr;            // RF rs2 address
//logic [`RF_AWIDTH-1:0]               id2exe_rd_addr;            // RF rd address

logic [`XLEN-1:0]                    instr_codeword;
logic [`XLEN-1:0]                    rf2id_rs1_data;            // RF rs1 data
logic [`XLEN-1:0]                    rf2id_rs2_data;            // RF rs2 data

// 
logic                                illegal_instr;

logic [2:0]                          funct3_opcode;
logic [6:0]                          funct7_opcode;
logic [4:0]                          funct5_opcode;
logic [4:0]                          shift_amt;

// Control and data signal structures
type_if2id_ctrl_s                    if2id_ctrl;
type_if2id_data_s                    if2id_data;
type_id2exe_ctrl_s                   id2exe_ctrl;
type_id2exe_data_s                   id2exe_data;

type_csr2id_fb_s                     csr2id_fb;
type_rv_opcode_e                     instr_opcode;

// Input signal assigments
assign if2id_ctrl = if2id_ctrl_i;
assign if2id_data = if2id_data_i;
assign csr2id_fb  = csr2id_fb_i;

// Instruction opcodes
assign instr_codeword = if2id_data.instr;
assign instr_opcode   = type_rv_opcode_e'(instr_codeword[6:2]); 
assign funct7_opcode  = instr_codeword[31:25];
assign funct3_opcode  = instr_codeword[14:12];
assign funct5_opcode  = instr_codeword[24:20];

// Register file related decodings
assign id2rf_rs1_addr = instr_codeword[19:15];
assign id2rf_rs2_addr = instr_codeword[24:20];
//assign id2exe_rd_addr = instr_codeword[11:7];

assign shift_amt      = instr_codeword[24:20]; 

//========================== Decoder logic implementation for control signals ==========================//
always_comb begin

    // Define decoder logic for control signals and prepare datapath signals for
    // execution phase. Set to default values for control signals when decoding 
    // an instruction.  
 
    // Operation selecion for different modules
    id2exe_ctrl.alu_i_ops  = ALU_I_OPS_NONE;
    id2exe_ctrl.alu_m_ops  = ALU_M_OPS_NONE;
    id2exe_ctrl.ld_ops     = LD_OPS_NONE;
    id2exe_ctrl.st_ops     = ST_OPS_NONE;
    id2exe_ctrl.branch_ops = BR_OPS_NONE;
    id2exe_ctrl.csr_ops    = CSR_OPS_NONE;
    id2exe_ctrl.amo_ops    = AMO_OPS_NONE;
    id2exe_ctrl.sys_ops    = SYS_OPS_NONE;

    // Operand selection for different modules
    id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_PC;
    id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
    id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
    id2exe_ctrl.csr_opr_sel      = CSR_OPR_REG;
    id2exe_ctrl.sys_ops          = SYS_OPS_NONE;
    id2exe_ctrl.rd_wrb_sel       = RD_WRB_NONE;
    id2exe_ctrl.exc_code         = EXC_CODE_NO_EXCEPTION;
    id2exe_ctrl.rd_wr_req        = 1'b0;
    id2exe_ctrl.jump_req         = 1'b0;
    id2exe_ctrl.branch_req       = 1'b0;
    id2exe_ctrl.exc_req          = 1'b0;
    id2exe_ctrl.fence_i_req      = 1'b0;

    // Default values for datapath signals
    id2exe_data.imm      = {{21{instr_codeword[31]}}, instr_codeword[30:20]};
    id2exe_data.rs1_data = rf2id_rs1_data;   // These operands need to be updated in case of forwarding
    id2exe_data.rs2_data = rf2id_rs2_data;   // These operands need to be updated in case of forwarding
    id2exe_data.instr    = instr_codeword;
    id2exe_data.pc       = if2id_data.pc;
    id2exe_data.pc_next  = if2id_data.pc_next;
    id2exe_data.instr_flushed = if2id_data.instr_flushed;
    
    // Default values for local signals
    illegal_instr       = 1'b0;

    // Check for instruction memory access fault
    if (if2id_ctrl.exc_req) begin
        id2exe_ctrl.exc_req  = 1'b1;
        id2exe_ctrl.exc_code = if2id_ctrl.exc_code;    
        
    end else begin  // no instruction memory access fault
        case (instr_opcode)
            OPCODE_ARITH_INST  : begin
                
                id2exe_ctrl.rd_wrb_sel       = RD_WRB_ALU;
                id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_REG;
                id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
                id2exe_ctrl.rd_wr_req        = 1'b1;
                 case (funct7_opcode)
                    7'b0000000 : begin
                        case (funct3_opcode)
                            3'b000 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_ADD;   // ADD
                            3'b001 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLL;   // Shift Left Logical
                            3'b010 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLT;   // Set Less Than
                            3'b011 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLTU;  // Set Less Than Unsigned
                            3'b100 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_XOR;   // XOR Logical
                            3'b101 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRL;   // Shift Right Logical 
                            3'b110 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_OR;    // OR Logical
                            3'b111 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_AND;   // AND Logical
                        endcase // funct3_opcode
                    end // 7'b0000000
                     7'b0100000 : begin
                        case (funct3_opcode)
                            3'b000  : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SUB;
                            3'b101  : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRA;
                            default : illegal_instr       = 1'b1;
                        endcase // funct3_opcode
                    end // 7'b0100000

                    7'b0000001 : begin
                        case (funct3_opcode)
                            3'b000 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MUL;
                            3'b001 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MULH;
                            3'b010 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MULHSU;
                            3'b011 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_MULHU;
                            3'b100 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_DIV;
                            3'b101 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_DIVU;
                            3'b110 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_REM;
                            3'b111 : id2exe_ctrl.alu_m_ops = ALU_M_OPS_REMU;
                        endcase // funct3_opcode
                    end // 7'b0000001

                    default : illegal_instr = 1'b1;
                endcase // funct7_opcode
               
            end // OPCODE_ARITH_INST

            // IMM operation
            OPCODE_IMM_INST : begin

                id2exe_ctrl.rd_wrb_sel       = RD_WRB_ALU;
                id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
                id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_IMM;
                id2exe_ctrl.rd_wr_req        = 1'b1;
                case (funct3_opcode)
                    3'b000 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_ADD;           // ADD Immediate
                    3'b010 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLT;           // SLT Immediate
                    3'b011 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLTU;          // SLTU Immediate 
                    3'b100 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_XOR;           // XOR Immediate
                    3'b110 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_OR;            // OR Immediate
                    3'b111 : id2exe_ctrl.alu_i_ops = ALU_I_OPS_AND;           // AND Immediate
                    3'b001 : begin
                              id2exe_data.imm     = `XLEN'(shift_amt);     // Zero Extend the shift amount
                              id2exe_ctrl.alu_i_ops = ALU_I_OPS_SLL;           // Shift Left Logical Immediate
                    end
                    3'b101 : begin
                        case (funct7_opcode)
                            
                            7'b0000000 : begin
                                id2exe_data.imm     = `XLEN'(shift_amt);   
                                id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRL;          // Shift Right Logical Immediate
                            end
                         
                            7'b0100000 : begin
                                id2exe_data.imm     = `XLEN'(shift_amt);   
                                id2exe_ctrl.alu_i_ops = ALU_I_OPS_SRA;          // Shift Right Arithmetic Immediate
                            end
                            
                            default : illegal_instr  =  1'b1;
                        endcase // funct7_opcode
                    end
                endcase // funct3_opcode
               
            end // OPCODE_IMM_INST

            // AUIPC operation
            OPCODE_AUIPC_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_ALU;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_PC;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;                 
                id2exe_data.imm          = {instr_codeword[31:12], 12'b0};
               
            end // OPCODE_AUIPC_INST

            // LUI operation
            OPCODE_LUI_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_ALU;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_COPY_OPR2;
                id2exe_ctrl.rd_wr_req    = 1'b1;                
                id2exe_data.imm          = {instr_codeword[31:12], 12'b0};
                
            end // OPCODE_LUI_INST
             // Load operations
            OPCODE_LOAD_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_DMEM;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;
                case (funct3_opcode)
                    3'b000  : id2exe_ctrl.ld_ops = LD_OPS_LB;            // Load byte signed
                    3'b001  : id2exe_ctrl.ld_ops = LD_OPS_LH;            // Load halfword signed 
                    3'b010  : id2exe_ctrl.ld_ops = LD_OPS_LW;            // Load word  
                    3'b100  : id2exe_ctrl.ld_ops = LD_OPS_LBU;           // Load byte unsigned 
                    3'b101  : id2exe_ctrl.ld_ops = LD_OPS_LHU;           // Load halfword unsigned 
                    default : illegal_instr      =  1'b1;                // Illegal instruction 
                endcase // funct3_opcode
               
            end // OPCODE_LOAD_INST
             // Store operations
            OPCODE_STORE_INST : begin
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_data.imm          = {{21{instr_codeword[31]}}, instr_codeword[30:25], instr_codeword[11:7]};
                case (funct3_opcode)
                    3'b000  : id2exe_ctrl.st_ops = ST_OPS_SB;            // Store byte signed
                    3'b001  : id2exe_ctrl.st_ops = ST_OPS_SH;            // Store halfword signed 
                    3'b010  : id2exe_ctrl.st_ops = ST_OPS_SW;            // Store word
                    default : illegal_instr      =  1'b1;                // Illegal instruction  
                endcase // funct3_opcode
                          
            end // OPCODE_STORE_INST

             // Memory fence operations
            OPCODE_MEM_FENCE_INST : begin
 
                case (funct3_opcode)
                    3'b000  : begin      end                             // fence instruction is effectively NOP
                    3'b001  : id2exe_ctrl.fence_i_req = 1'b1;            // fence.i leads to pipeline flush                     
                    default : illegal_instr           = 1'b1;            // Default case  
                endcase // funct3_opcode                
            end // OPCODE_MEM_FENCE_INST

             // Branch operation
            OPCODE_BRANCH_INST : begin
                id2exe_ctrl.alu_opr1_sel     = ALU_OPR1_PC;
                id2exe_ctrl.alu_opr2_sel     = ALU_OPR2_IMM;
                id2exe_ctrl.alu_cmp_opr2_sel = ALU_CMP_OPR2_REG;
                id2exe_ctrl.alu_i_ops        = ALU_I_OPS_ADD;
                id2exe_ctrl.branch_req       = 1'b1;
                id2exe_data.imm              = {{20{instr_codeword[31]}}, instr_codeword[7], instr_codeword[30:25], instr_codeword[11:8], 1'b0};
                case (funct3_opcode)
                    3'b000  : id2exe_ctrl.branch_ops = BR_OPS_EQ;            // Branch equal
                    3'b001  : id2exe_ctrl.branch_ops = BR_OPS_NE;            // Branch not equal 
                    3'b100  : id2exe_ctrl.branch_ops = BR_OPS_LT;            // Branch less than 
                    3'b101  : id2exe_ctrl.branch_ops = BR_OPS_GE;            // Branch greater than or equal signed
                    3'b110  : id2exe_ctrl.branch_ops = BR_OPS_LTU;           // Branch less than unsigned 
                    3'b111  : id2exe_ctrl.branch_ops = BR_OPS_GEU;           // Branch greater than or equal unsigned
                    default : begin                                          // Illegal instruction  
                        illegal_instr          = 1'b1;
                        id2exe_ctrl.branch_req = 1'b0;
                    end
                endcase // funct3_opcode  */
                          
            end // OPCODE_BRANCH_INST

            // JALR operation
            OPCODE_JALR_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_INC_PC;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;
                id2exe_ctrl.jump_req     = 1'b1;
           //     id2exe_data.imm           =   {{12{instr_codeword[31]}}, instr_codeword[19:12], instr_codeword[20], instr_codeword[30:21], 1'b0};
               
            end // OPCODE_JALR_INST
             // JAL operation
            OPCODE_JAL_INST : begin
                id2exe_ctrl.rd_wrb_sel   = RD_WRB_INC_PC;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_PC;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_IMM;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_ADD;
                id2exe_ctrl.rd_wr_req    = 1'b1;
                id2exe_ctrl.jump_req     = 1'b1;
                id2exe_data.imm          = {{12{instr_codeword[31]}}, instr_codeword[19:12], instr_codeword[20], instr_codeword[30:21], 1'b0};
                
            end // OPCODE_JAL_INST
 
            // SYS operations
            OPCODE_SYSTEM_INST : begin
                case (funct3_opcode)
                    3'b001 : begin              // CSRRW
                        id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                        id2exe_ctrl.rd_wrb_sel   = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops      = CSR_OPS_WRITE;
                        id2exe_ctrl.csr_opr_sel  = CSR_OPR_REG;
                    end
                    3'b010 : begin              // CSRRS
                        id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                        id2exe_ctrl.rd_wrb_sel   = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops      = CSR_OPS_SET;
                        id2exe_ctrl.csr_opr_sel  = CSR_OPR_REG;
                    end
                    3'b011 : begin             // CSRRC
                        id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                        id2exe_ctrl.rd_wrb_sel   = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops      = CSR_OPS_CLEAR;
                        id2exe_ctrl.csr_opr_sel  = CSR_OPR_REG;
                    end
                    3'b101 : begin             // CSRIW
                        id2exe_ctrl.rd_wrb_sel  = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops     = CSR_OPS_WRITE;
                        id2exe_ctrl.csr_opr_sel = CSR_OPR_IMM;
                    end
                    3'b110 : begin             // CSRIS
                        id2exe_ctrl.rd_wrb_sel  = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops     = CSR_OPS_SET;
                        id2exe_ctrl.csr_opr_sel = CSR_OPR_IMM;
                    end
                    3'b111 : begin             // CSRIC
                        id2exe_ctrl.rd_wrb_sel  = RD_WRB_CSR;
                        id2exe_ctrl.csr_ops     = CSR_OPS_CLEAR;
                        id2exe_ctrl.csr_opr_sel = CSR_OPR_IMM;
                    end
                    3'b000 : begin
                                                         
                        case (funct7_opcode)
                            7'b0000000 : begin        
                                case (funct5_opcode)
                                    5'b00000 : begin  // ECALL                     
                                        id2exe_ctrl.exc_req  = 1'b1;
                                        case (csr2id_fb.priv_mode)
                                            PRIV_MODE_M: id2exe_ctrl.exc_code = EXC_CODE_ECALL_MMODE;
                                            PRIV_MODE_S: id2exe_ctrl.exc_code = EXC_CODE_ECALL_SMODE;
                                            PRIV_MODE_U: id2exe_ctrl.exc_code = EXC_CODE_ECALL_UMODE;
                                            default:       ; // this should not have happened
                                        endcase

                                        id2exe_ctrl.exc_code = EXC_CODE_ECALL_MMODE;
                                    end
                                    5'b00001 : begin  // EBREAK
                                        id2exe_ctrl.exc_req  = 1'b1;
                                        id2exe_ctrl.exc_code = EXC_CODE_BREAKPOINT;
                                    end
                                    default : illegal_instr  =  1'b1; 
                                endcase // funct5_opcode
                            end
                            7'b0001000 : begin        
                                case (funct5_opcode)
                                    5'b00010 : begin  // SRET                     
                                        id2exe_ctrl.sys_ops    = SYS_OPS_SRET;
                                    end
                                    5'b00101 : begin  // WFI
                                        id2exe_ctrl.sys_ops    = SYS_OPS_WFI;  
                                    end
                                    default : illegal_instr  =  1'b1; 
                                endcase // funct5_opcode                           
                            end
                            7'b0011000 : begin        // MRET
                                id2exe_ctrl.sys_ops    = SYS_OPS_MRET;                               
                            end
                            7'b0001001 : begin        // SFENCE.VMA
                                id2exe_ctrl.sys_ops    = SYS_OPS_SFENCE_VMA;                               
                            end
                            default : illegal_instr = 1'b1;
                        endcase // funct7_opcode
                         
                    end
                                    
                    default : illegal_instr = 1'b1;   // illegal instruction  
                endcase // funct3_opcode                                     
            end // OPCODE_SYS_INST

             // Atomic memory operations (AMO)
            OPCODE_AMO_INST : begin
             //   id2exe_ctrl.rd_wrb_sel   = RD_WRB_DMEM;
                id2exe_ctrl.alu_opr1_sel = ALU_OPR1_REG;
                id2exe_ctrl.alu_opr2_sel = ALU_OPR2_REG;
                id2exe_ctrl.alu_i_ops    = ALU_I_OPS_COPY_OPR1;
             //   id2exe_ctrl.rd_wr_req    = 1'b1;  

                if (funct3_opcode == 3'b010) begin              
                    case (funct7_opcode[6:2])
                        5'b00000  : id2exe_ctrl.amo_ops = AMO_OPS_ADD;                  // Atomic addition
                        5'b00001  : id2exe_ctrl.amo_ops = AMO_OPS_SWAP;                 // Atomic swap
                        5'b00010  : begin 
                            id2exe_ctrl.amo_ops = AMO_OPS_LR;                           // Load restricted                            
                            if (funct5_opcode != '0) illegal_instr = 1'b1;
                        end
                        5'b00011  : id2exe_ctrl.amo_ops = AMO_OPS_SC;                   // Store conditional
                        5'b00100  : id2exe_ctrl.amo_ops = AMO_OPS_XOR;                  // Atomic XOR
                        5'b01000  : id2exe_ctrl.amo_ops = AMO_OPS_OR;                   // Atomic OR
                        5'b01100  : id2exe_ctrl.amo_ops = AMO_OPS_AND;                  // Atomic AND
                        5'b10000  : id2exe_ctrl.amo_ops = AMO_OPS_MIN;                  // Atomic MIN
                        5'b10100  : id2exe_ctrl.amo_ops = AMO_OPS_MAX;                  // Atomic MAX
                        5'b11000  : id2exe_ctrl.amo_ops = AMO_OPS_MINU;                 // Atomic MIN unsigned
                        5'b11100  : id2exe_ctrl.amo_ops = AMO_OPS_MAXU;                 // Atomic MAX unsigned
                        default   : illegal_instr       = 1'b1;                         // Illegal instructio 
                    endcase // funct7_opcode[6:2]
                end else begin
                    illegal_instr = 1'b1;
                end  //
            end // OPCODE_AMO_INST

            default : begin
                illegal_instr = 1'b1;
            end
        endcase // instr_opcode (Instruction opcode) 
    end // no instruction memory fault

   // Handle the illegal instruction
  if(illegal_instr)  begin
     id2exe_ctrl.alu_i_ops   = ALU_I_OPS_NONE;
     id2exe_ctrl.alu_m_ops   = ALU_M_OPS_NONE;
     id2exe_ctrl.ld_ops      = LD_OPS_NONE;
     id2exe_ctrl.st_ops      = ST_OPS_NONE;
     id2exe_ctrl.branch_ops  = BR_OPS_NONE;
     id2exe_ctrl.csr_ops     = CSR_OPS_NONE;
     id2exe_ctrl.amo_ops     = AMO_OPS_NONE;
     id2exe_ctrl.sys_ops     = SYS_OPS_NONE;

     id2exe_ctrl.rd_wrb_sel  = RD_WRB_NONE;
     id2exe_ctrl.exc_code    = EXC_CODE_ILLEGAL_INSTR;
     id2exe_ctrl.exc_req     = 1'b1;
     id2exe_ctrl.rd_wr_req   = 1'b0;
     id2exe_ctrl.jump_req    = 1'b0;
     id2exe_ctrl.branch_req  = 1'b0;
     id2exe_ctrl.fence_i_req = 1'b0;
   end

    
end // Decoder logic

//=================================== Output signals update ====================================//

// MT TODO: Feedforward (pipeline) signals should be made configurable for enabling/disabling 
// pipeline stages 
assign id2exe_ctrl_o = id2exe_ctrl;
assign id2exe_data_o = id2exe_data; 

//================================ Instantiation of submodules =================================//
// Instantiation of register file
reg_file rf_module (
   .rst_n                (rst_n            ),
   .clk                  (clk              ),
    // ID <---> RF interface
   .id2rf_rs1_addr_i     (id2rf_rs1_addr),
   .rf2id_rs1_data_o     (rf2id_rs1_data),
   .id2rf_rs2_addr_i     (id2rf_rs2_addr),
   .rf2id_rs2_data_o     (rf2id_rs2_data),
   .id2rf_rd_wr_req_i    (wrb2id_fb_i.rd_wr_req),
   .id2rf_rd_addr_i      (wrb2id_fb_i.rd_addr ),
   .id2rf_rd_data_i      (wrb2id_fb_i.rd_data)
);


endmodule : decode

>>>>>>> d62810222fb662b33be2c33273d34ca765819f8e

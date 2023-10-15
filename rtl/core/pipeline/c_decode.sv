//verilator lint_off UNUSED
module c_decode (
    input logic [31:0] inst,input logic  pc,pc_missallign,  output logic next_comp16, output logic [31:0] compressed_inst_out
);
    logic [1:0] comp_opcode;
    logic [11:0] comp_load_i_type, comp_imm_stack_store,comp_imm_load_store, imm_Li, comp_i_tpye;
    logic [4:0] rs2, rs1,rd ;//change addded
    logic [19:0] imm_jump, imm_LUI, imm_LUI_addi_16_sp;
    logic [2:0] comp_func3;
    logic [4:0] comp_rs1, comp_rs2, comp_rd;
    
    logic [15:0] comp_inst;
    logic illegal;	//change added
    logic [4:0]imm_sLLI;	//change added 
    logic [7:0]imm;		//change added
    logic [11:0] comp_imm_branch, comp_addi_14_sp, imm_ANDI;
    logic [31:0] inst_load, inst_store, inst_load_stack, inst_store_stack, inst_jal , inst_j, inst_jalr,inst_jr, inst_branch_not, inst_branch_equal,inst_LI, inst_LUI, inst_r_type, inst_r_comp_type,inst_nop, inst_i_type, inst_addi_16_sp, inst_addi_14_sp, inst_SLLI, inst_sRLI, inst_sRAI, inst_ADD, inst_ANDI, inst_MV, inst_AND, inst_OR, inst_XOR, inst_SUB,inst_E_Break;	//change added

    logic [6:0] load_opcode, store_opcode, R_type_opcode, I_type_opcode, Jal_opcode, B_type_opcode, Jalr_opcode,LUI_opcode, AUIPC_opcode ;

    assign illegal =| comp_inst;//change
    assign comp_opcode = comp_inst [1:0];
    assign comp_load_i_type = (({{6'b0},{comp_inst[3:2]},{comp_inst[12]}, {comp_inst[6:4]}}) << 2); //for i type instruction 
    assign comp_imm_stack_store = (({{6'b0},{comp_inst[8:7]},{comp_inst[12:9]}}) << 2);  //to to store with stack register as a refernce	change
    assign imm = comp_inst[12:5];   //wide immediate
    assign comp_imm_load_store = (({{7'b0},{comp_inst[5]},{comp_inst[12:10]}, {comp_inst[6]}}) << 2); //for load and store unit   change> 7bits added
    assign comp_imm_branch = {{3{comp_inst[12]}}, {comp_inst[12]},{comp_inst[6:5]},{comp_inst[2]}, {comp_inst[11:10]}, {comp_inst[4:3]}, {1'b0}}; //for branch immediate
    assign rs2 = comp_inst [6:2];   // normal 5 bit address for rs2 
    assign rs1 = comp_inst [11:7];  // nomeal 5 bit address for rs1 and rd
    assign rd =rs1;     	    //cahnge added
    assign comp_rs1 = {{2'b01},{comp_inst[9:7]}};   // for accessing x8 -x15 registers
    assign comp_rs2 = {{2'b01},{comp_inst[4:2]}};   // for accessing x8 -x15 registers
    assign comp_rd = {{2'b01},{comp_inst[4:2]}};    // for accessing x8 -x15 registers
    assign imm_jump =  (({{8{comp_inst[12]}},{comp_inst[12]}, {comp_inst[8]},{comp_inst[10:9]} , {comp_inst[6]} , {comp_inst[7]} , {comp_inst[2]} , {comp_inst[11]} , {comp_inst[5:3]} , 1'b0 })); //immediate for jump
    assign imm_Li = {{6{comp_inst[12]}} , {comp_inst[12]} , {comp_inst[6:2]}};
    assign imm_LUI = { {2{comp_inst[12]} },{comp_inst[12]} , {comp_inst [6:2]}, {12'b0}};
    assign imm_LUI_addi_16_sp =  {{10{comp_inst[12]}} ,{comp_inst[12]}, {comp_inst [4:3]},{comp_inst[5]},{comp_inst[2]},{comp_inst[6]} ,{4'b0} } ;
    assign comp_addi_14_sp = (({{4'b0}, {comp_inst[10:7]} ,  {comp_inst[12:11]},{comp_inst[5]} , {comp_inst[6]}} ) << 4);
    assign imm_sLLI = comp_inst[6:2] ;		    // for RVC32 bit 4 of shamt shouold be zero  change 12 bit is dropped  
    assign imm_ANDI = {{6{comp_inst[12]}} , {comp_inst[12]} , {comp_inst[6:2]}};
    assign comp_i_tpye = {{6{comp_inst[12]} }  ,  {comp_inst[12]}, {comp_inst [6:2]}};
    assign comp_func3 = comp_inst[15:13];
    assign load_opcode = 7'b0000011;
    assign store_opcode =7'b0100011;
    assign R_type_opcode =7'b0110011;
    assign I_type_opcode = 7'b0010011;
    assign B_type_opcode = 7'b1100011;
    assign Jal_opcode =7'b1101111;
    assign Jalr_opcode = 7'b1100111;
    assign LUI_opcode =7'b0110111;
    assign AUIPC_opcode= 7'b0010111;


    always_comb begin // a sel that we use to isolate the compressed instruction , we read the LSD of pc bit 1 and find if we are at 0x2 or 0x4
    if (pc_missallign) begin 
        comp_inst = inst[15:0]; //if missalligned instruction has occured, chose the lower bits
    end
    else begin 
        if(pc) comp_inst = inst[31:16];
        else comp_inst = inst[15:0];//change
    end
    end

    always_comb begin // this is the sel which tells the pc to do +2 and inst_mem to to address>>1
    if (illegal) begin //check for illegal inst all zeros 					      
    case (comp_opcode)
       2'b00 : next_comp16 =1'b1;
       2'b01 : next_comp16=1'b1;
       2'b10 : next_comp16=1'b1;
       2'b11 : next_comp16 =1'b0; 
        default: next_comp16 =1'b0;
    
    endcase
    end
    
    else next_comp16= 1'b0;
    end

    always_comb begin // this is to select what output the instruction is according to the compressed opcode 
        if (~next_comp16) compressed_inst_out = inst;
        else begin 
            case (comp_opcode)
            2'b00 : begin 
                    case (comp_func3)
                    3'b000 :  compressed_inst_out = inst_addi_14_sp;
                    3'b010 :  compressed_inst_out = inst_load;
                    3'b110 :  compressed_inst_out = inst_store;
                    default compressed_inst_out = 32'h0000_0013;//change
                    endcase
                end 
            2'b01 : begin 
                    case(comp_func3)
                    3'b000 : begin 
                            if (comp_inst[11:7] == 5'b0) compressed_inst_out = 32'h0000_0013;//change
                            else compressed_inst_out = inst_i_type;
                            end
                    3'b001 : compressed_inst_out = inst_jal;
                    3'b010 : compressed_inst_out = inst_LI;
                    3'b011 : begin  if (rd == 5'h02 & rd!=5'h00)  compressed_inst_out = inst_addi_16_sp;
                                    else compressed_inst_out = inst_LUI;
                            end
                    3'b100 : begin 
                            case (comp_inst[11:10])
                            2'b00 : compressed_inst_out = inst_sRLI;
                            2'b01 : compressed_inst_out = inst_sRAI;
                            2'b10 : compressed_inst_out = inst_ANDI;
                            2'b11 : begin 
                                    case (comp_inst[6:5])
                                    2'b00 : compressed_inst_out = inst_SUB;
                                    2'b01 : compressed_inst_out = inst_XOR;
                                    2'b10 : compressed_inst_out = inst_OR;
                                    2'b11 : compressed_inst_out = inst_AND;

                                    endcase
                                    end
                            default compressed_inst_out = 32'h0000_0013;
                            endcase
                            end
                    3'b101 : compressed_inst_out = inst_j;
                    3'b110 : compressed_inst_out = inst_branch_equal;
                    3'b111 : compressed_inst_out = inst_branch_not;
                    endcase

                    end
            2'b10 : begin 
                    case (comp_func3)
                    3'b000 : compressed_inst_out = inst_SLLI;
                    3'b010 : compressed_inst_out =inst_load_stack;
                    3'b100 :  begin
                        case(comp_inst[12])
                        1'b0 : begin 
                            if((rs2 == 5'h00) & (rs1!=5'h00)) compressed_inst_out = inst_jr;
                            else compressed_inst_out = inst_MV;
                                end
                        1'b1 : begin
                            if ((rs1==5'h00) & (rs2 == 5'h00)) compressed_inst_out =inst_E_Break;
                            else if ((rs1!=5'h00) & (rs2 == 5'h00))compressed_inst_out= inst_jalr;
                            else compressed_inst_out = inst_ADD;
                        end
                        endcase
                                end 
                    3'b110 : compressed_inst_out = inst_store_stack;
                    default compressed_inst_out = 32'h0000_0013;
                    endcase
                    end
            2'b11 : compressed_inst_out = inst;
            endcase
        end


    end


    always_comb begin  // this is the block in which we make extend the compressed to whole instructions
        inst_load_stack = { {comp_load_i_type}, {5'h02} , {comp_func3} , {rs1}, {load_opcode}};     // lw rd ,offset[7:2](x2)
        inst_store_stack = {{comp_imm_stack_store[11:5]} , {rs2}, {5'h02},{3'b010}, {comp_imm_stack_store[4:0]}, {store_opcode}};   //sw rs2, offset[7:2](x2)
        inst_load = {{comp_imm_load_store}, {comp_rs1}, {comp_func3}, {comp_rd}, {load_opcode}};    // lw rd', offset[6:2](rs1')
        inst_store = {{comp_imm_load_store[11:5]}, {comp_rs2},{comp_rs1}, {3'b010}, {comp_imm_load_store[4:0]}, {store_opcode}};    //sw rs2', offset[6:2](rs1')
        inst_jal = {  {{imm_jump[19]},{imm_jump[9:0]},{imm_jump[10]},{imm_jump[18:11]}} , {5'h01}, {Jal_opcode}};  // jal x1, offset[11:1].
        inst_j = {  {{imm_jump[19]},{imm_jump[9:0]},{imm_jump[10]},{imm_jump[18:11]}} , {5'h00}, {Jal_opcode}};    //  jal x0, offset[11:1].
        inst_jr = {{12'h0} , {rs1} , {3'b0}, {5'h00}, {Jalr_opcode}};   //jalr x0, rs1, 0.
        inst_jalr= {{12'h0} , {rs1} , {3'b0}, {5'h01}, {Jalr_opcode}};  //jalr x1, rs1, 0.
        inst_branch_equal = {{{comp_imm_branch[11]} , {comp_imm_branch [9:4]}} ,{5'h00} ,  {comp_rs1} , {3'b000} , {{comp_imm_branch[3:0]},{comp_imm_branch[10]}} ,  {B_type_opcode}};  // beq rs1', x0, offset[8:1].
        inst_branch_not = {{{comp_imm_branch[11]} , {comp_imm_branch [9:4]}} ,{5'h00} ,  {comp_rs1} , {3'b001} , {{comp_imm_branch[3:0]},{comp_imm_branch[10]}} ,  {B_type_opcode}};    // bne rs1', x0, offset[8:1]
        inst_LI = {{imm_Li}, {5'h00} , {3'b0} , {rd} , {I_type_opcode}};                                // addi rd, x0, imm[5:0]
        inst_LUI = { {imm_LUI} , {rd} , {LUI_opcode}};                                                  // lui rd, nzuimm[17:12]
        inst_i_type = { {comp_i_tpye} , {rs1} , {comp_func3} , {rs1} , {I_type_opcode}}  ;              // only for  addi rd, rd, nzimm[5:0]
        inst_addi_16_sp = {{imm_LUI_addi_16_sp} , {5'h02} , {LUI_opcode}};                              // addi x2, x2, nzimm[9:4].
        inst_addi_14_sp = {{comp_addi_14_sp}, {5'h02} , {comp_func3} , {comp_rd} , {I_type_opcode}};    // addi rd', x2, nzuimm[9:2].
        inst_SLLI = {{7'b0} , {imm_sLLI} ,{rs1} , {3'b001}, {rs1}, {I_type_opcode}};                    // slli rd, rd, shamt[5:0]
        inst_sRLI = {{7'b0} , {imm_sLLI} ,{comp_rs1} , {3'b101}, {comp_rs1}, {I_type_opcode}};          // srli rd', rd', shamt[5:0]
        inst_sRAI = {{7'b0100000} , {imm_sLLI} ,{comp_rs1} , {3'b101}, {comp_rs1}, {I_type_opcode}};    // srai rd', rd', shamt[5:0]
        inst_ANDI = {{imm_ANDI} ,{comp_rs1}, {3'b111}, {comp_rs1}, {I_type_opcode}};                    // andi rd', rd', imm[5:0]
        inst_ADD = {{7'b0}, {rs2}, {rs1}, {3'b0} , {rs1} , {R_type_opcode} };                           // add rd, rd, rs2.
        inst_MV ={{7'b0}, {rs2}, {5'b0}, {3'b0} , {rs1} , {R_type_opcode} };                            // add rd, x0, rs2
        inst_AND = {{7'b0}, {comp_rs2}, {comp_rs1}, {3'b111} , {comp_rs1} , {R_type_opcode} };           // and rd', rd', rs2'
        inst_OR = {{7'b0}, {comp_rs2}, {comp_rs1}, {3'b110} , {comp_rs1} , {R_type_opcode} };            // or rd', rd', rs2'
        inst_XOR = {{7'b0}, {comp_rs2}, {comp_rs1}, {3'b100} , {comp_rs1} , {R_type_opcode} };           // xor rd', rd', rs2'
        inst_SUB = {{7'b0100000}, {comp_rs2}, {comp_rs1}, {3'b000} , {comp_rs1} , {R_type_opcode} };     // sub rd', rd', rs2'
	    inst_E_Break ={{12'b000000000001},{5'b0},{3'b0},{5'b0},{7'b1110011}};
    end
endmodule

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/MMU_defs.svh"

module fetch (

    input   logic                                   rst_n,           // reset
    input   logic                                   clk,             // clock

   // IF <---> IMEM interface
    output type_if2imem_s                           if2imem_o,       // Instruction memory request
    input wire type_imem2if_s                       imem2if_i,       // Instruction memory response

   // IF <---> MMU interface
    output type_if2mmu_s                            if2mmu_o,        // Instruction memory request
    input wire type_mmu2if_s                        mmu2if_i,        // Instruction memory response

    // IF <---> ID interface
    output type_if2id_data_s                        if2id_data_o,
    output type_if2id_ctrl_s                        if2id_ctrl_o, 

    // EXE <---> Fetch feedback interface
    input wire type_exe2if_fb_s                     exe2if_fb_i,

    // CSR <---> Fetch feedback interface
    input wire type_csr2if_fb_s                     csr2if_fb_i,
    
    // Forward <---> Fetch interface
    input wire type_fwd2if_s                        fwd2if_i,
    output logic                                    if2fwd_stall_o
);


// Local siganls       
type_imem2if_s                       imem2if;
type_if2mmu_s                        if2mmu;
type_mmu2if_s                        mmu2if;

type_if2id_data_s                    if2id_data;
type_if2id_ctrl_s                    if2id_ctrl;

type_exe2if_fb_s                     exe2if_fb;
type_csr2if_fb_s                     csr2if_fb;

type_fwd2if_s                        fwd2if;

// Exception related signals
type_exc_code_e                      exc_code;
logic                                exc_req;

// Imem address generation
logic [`XLEN-1:0]                    pc_ff;              // Current value of program counter (PC)
logic [`XLEN-1:0]                    pc_next;            // Updated value of PC
logic                                if_stall;
logic                                pc_misaligned;


assign imem2if   = imem2if_i;
assign mmu2if    = mmu2if_i;

assign exe2if_fb = exe2if_fb_i;
assign csr2if_fb = csr2if_fb_i;
assign fwd2if    = fwd2if_i;

// Evaluation for misaligned address
assign pc_misaligned = pc_ff[1] | pc_ff[0];

// Stall signal for IF stage
assign if_stall = fwd2if.if_stall | (~imem2if.ack);

// PC update state machine
always_ff @(posedge clk) begin
    if (~rst_n) begin
        pc_ff <= `PC_RESET;
    end else begin
        pc_ff <= pc_next;
    end
end

always_comb begin
    pc_next = '0;

    case (1'b1)
        fwd2if.csr_new_pc_req : begin
            pc_next = csr2if_fb.pc_new;
        end
        fwd2if.wfi_req        : begin
            pc_next = csr2if_fb.pc_new;  
        end
        fwd2if.exe_new_pc_req : begin
            pc_next = exe2if_fb.pc_new;  
        end
        if_stall              : begin  
            pc_next = pc_ff;
        end
        default                 : begin
            pc_next = (pc_ff + 32'd4);
        end
    endcase
end

always_comb begin
    exc_req  = 1'b0;
    exc_code = EXC_CODE_NO_EXCEPTION;

    // Instruction address generated is misaligned
    if (pc_misaligned) begin
        exc_req  = 1'b1;
        exc_code = EXC_CODE_INSTR_MISALIGN; 
    end

    // Deal with instruction access fault as well (EXC_CODE_INSTR_ACCESS_FAULT)
end


// Update the outputs to MMU and Imem modules
assign if2mmu.i_vaddr = pc_next;
assign if2mmu.i_req   = `IMEM_INST_REQ;
assign if2imem_o.addr = mmu2if.i_paddr[`XLEN-1:0]; // pc_next; 
assign if2imem_o.req  = mmu2if.i_hit;              // `IMEM_INST_REQ; 

// Update the outputs to ID stage
assign if2id_data.instr         = imem2if.ack ? imem2if.r_data : `INSTR_NOP;
assign if2id_data.pc            = pc_ff;
assign if2id_data.pc_next       = pc_next;
assign if2id_data.instr_flushed = 1'b0;

assign if2id_ctrl.exc_code      = exc_code;
assign if2id_ctrl.exc_req       = exc_req;

// Generate stall request to forward_stall module
assign if2fwd_stall_o           = if2mmu.i_req & ~imem2if.ack;

assign if2id_data_o             = if2id_data;
assign if2id_ctrl_o             = if2id_ctrl;

assign if2mmu_o                 = if2mmu;

endmodule : fetch


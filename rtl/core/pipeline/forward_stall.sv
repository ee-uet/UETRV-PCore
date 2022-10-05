// Include some licensing info and file header 

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module forward_stall (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // Writeback <---> Forward_stall interface signals
    input wire type_wrb2fwd_s             wrb2fwd_i,

    // Memory <---> Forward_stall interface for forwarding
    input wire type_lsu2fwd_s             lsu2fwd_i,
    
    // EXE/CSR <---> Forward_stall interface signals
    input wire type_exe2fwd_s             exe2fwd_i,  
    input wire type_csr2fwd_s             csr2fwd_i,

    // Output signals from forward to different modules
    output type_fwd2if_s                  fwd2if_o,
    output type_fwd2exe_s                 fwd2exe_o,
    output type_fwd2csr_s                 fwd2csr_o,
    output type_fwd2ptop_s                fwd2ptop_o
);

//============================= Local signals and their assignments =============================//
 
type_lsu2fwd_s                       lsu2fwd;
type_wrb2fwd_s                       wrb2fwd;
type_exe2fwd_s                       exe2fwd;
type_csr2fwd_s                       csr2fwd;

logic                                rs1_valid;
logic                                rs2_valid;
logic                                lsu2rs1_hazard;
logic                                lsu2rs2_hazard;
logic                                ld_use_rs1_hazard;
logic                                ld_use_rs2_hazard;
logic                                ld_use_hazard;
logic                                ld_csr_read_req;
logic                                lsu_flush;
logic                                ld_stall;
logic                                ld_stall_ff;
logic                                ld_stall_next;
logic                                id_exe_flush;
logic                                exe_new_pc_req;

// Signals driving outputs to different modules
type_fwd2if_s                        fwd2if;
type_fwd2exe_s                       fwd2exe;
type_fwd2csr_s                       fwd2csr;
type_fwd2ptop_s                      fwd2ptop;                                                                

// Instantiate the local signals from inputs
assign lsu2fwd = lsu2fwd_i;
assign wrb2fwd = wrb2fwd_i;                          
assign exe2fwd = exe2fwd_i; 
assign csr2fwd = csr2fwd_i;  

// Check the validity of the source operands from EXE stage
assign rs1_valid = |exe2fwd.rs1_addr;  
assign rs2_valid = |exe2fwd.rs2_addr;                     

// Hazard detection
assign lsu2rs1_hazard = ((exe2fwd.rs1_addr == lsu2fwd.rd_addr) & lsu2fwd.rd_wr_req) & rs1_valid;
assign lsu2rs2_hazard = ((exe2fwd.rs2_addr == lsu2fwd.rd_addr) & lsu2fwd.rd_wr_req) & rs2_valid;

// Is it load or CSR read operation
assign ld_csr_read_req = lsu2fwd.ld_req | csr2fwd.csr_read_req;

// Check the 'ack' signal for the load operation
assign ld_stall = ld_stall_next;                  // lsu2fwd.ld_req & (~lsu2fwd.ld_ack);

always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        ld_stall_ff <= '0;
    end else begin
        ld_stall_ff <= ld_stall_next;
    end
end

always_comb begin 
    if (lsu2fwd.ld_ack ) begin
        ld_stall_next = 1'b0;
    end else if (lsu2fwd.ld_req) begin                         
        ld_stall_next = 1'b1; 
    end else begin                         
        ld_stall_next = ld_stall_ff; 
    end        
end


// Generate the forwarding signals from LSU and writeback stages. The load-use RAW hazard
// can not be resolved by forwarding from LSU-2-execute stage. Rather one cycle stall is
// generated and the data read using DBUS is forwarded from writeback stage to execute
// stage to resolve the hazard. 
assign fwd2exe.fwd_lsu_rs1 = lsu2rs1_hazard & (~ld_csr_read_req);
assign fwd2exe.fwd_lsu_rs2 = lsu2rs2_hazard & (~ld_csr_read_req);
     
assign fwd2exe.fwd_wrb_rs1 = ((exe2fwd.rs1_addr == wrb2fwd.rd_addr) & wrb2fwd.rd_wr_req) & rs1_valid;
assign fwd2exe.fwd_wrb_rs2 = ((exe2fwd.rs2_addr == wrb2fwd.rd_addr) & wrb2fwd.rd_wr_req) & rs2_valid;

// Load/CSR use hazard detection
assign ld_use_rs1_hazard = lsu2rs1_hazard & exe2fwd.use_rs1 & (ld_csr_read_req);
assign ld_use_rs2_hazard = lsu2rs2_hazard & exe2fwd.use_rs2 & (ld_csr_read_req);
assign ld_use_hazard     = (ld_use_rs1_hazard | ld_use_rs2_hazard) & ~ld_stall;

// New PC request from EXE stage is only processed when there is neither data hazard for the
// instruction in EXE stage due to operand dependency on the data from LSU stage, nor there is 
// a stall from LSU stage   
assign exe_new_pc_req = exe2fwd.new_pc_req & ~(ld_use_hazard | ld_stall);

// Pipeline flush signal for ID, EXE and LSU stages

assign id_exe_flush = exe_new_pc_req | csr2fwd.new_pc_req | csr2fwd.wfi_req;
assign lsu_flush    = csr2fwd.new_pc_req | csr2fwd.wfi_req;   

assign fwd2ptop.if2id_pipe_flush  = id_exe_flush;
assign fwd2ptop.id2exe_pipe_flush = id_exe_flush;

assign fwd2ptop.if2id_pipe_stall   = ld_use_hazard | ld_stall;
assign fwd2ptop.id2exe_pipe_stall  = ld_use_hazard | ld_stall;
assign fwd2ptop.exe2lsu_pipe_stall = ld_stall;
assign fwd2ptop.exe2lsu_pipe_flush = ld_use_hazard | lsu_flush;

assign fwd2ptop.pipe_fwd_wrb_rs1   = fwd2exe.fwd_wrb_rs1;
assign fwd2ptop.pipe_fwd_wrb_rs2   = fwd2exe.fwd_wrb_rs2;

assign fwd2csr.pipe_stall          = ld_use_hazard;

// Generate different PC update or stall signals for IF stage
assign fwd2if.exe_new_pc_req = exe_new_pc_req & (~csr2fwd.new_pc_req);
assign fwd2if.csr_new_pc_req = csr2fwd.new_pc_req;
assign fwd2if.wfi_req        = csr2fwd.wfi_req;
assign fwd2if.if_stall       = ld_use_hazard | ld_stall;

// Update the module output signals
assign fwd2if_o   = fwd2if;
assign fwd2exe_o  = fwd2exe; 
assign fwd2csr_o  = fwd2csr; 
assign fwd2ptop_o = fwd2ptop;     

endmodule : forward_stall


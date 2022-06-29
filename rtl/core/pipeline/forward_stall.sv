// Include some licensing info and file header 

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module forward_stall (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // Writeback <---> Forward_stall interface signals
    input wire type_wrb2fwd_s             wrb2fwd_i,
    
    // EXE <---> Forward_stall interface signals
    input wire type_exe2fwd_s            exe2fwd_i,    
    output type_fwd2exe_s                fwd2exe_o
);

//============================= Local signals and their assignments =============================//
 
type_wrb2fwd_s                       wrb2fwd;
type_exe2fwd_s                       exe2fwd;
type_fwd2exe_s                       fwd2exe;

// Instantiate the local signals from inputs
assign wrb2fwd = wrb2fwd_i;                          
assign exe2fwd = exe2fwd_i;                          

// Generate the forwarding signals       
assign fwd2exe.fwd_rs1 = ((exe2fwd.rs1_addr == wrb2fwd.rd_addr) & wrb2fwd.rd_wr_req) & (|exe2fwd.rs1_addr);
assign fwd2exe.fwd_rs2 = ((exe2fwd.rs2_addr == wrb2fwd.rd_addr) & wrb2fwd.rd_wr_req) & (|exe2fwd.rs2_addr);

// Update the module output signals
assign fwd2exe_o = fwd2exe;
       

endmodule : forward_stall


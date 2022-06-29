`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module writeback (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // MEM <---> Writeback interface
    input wire type_mem2wrb_data_s           mem2wrb_data_i,
    input wire type_mem2wrb_ctrl_s           mem2wrb_ctrl_i,

    // Writeback <---> ID interface for feedback signals
    output type_wrb2id_fb_s                  wrb2id_fb_o,

    // Writeback <---> Memory interface for feedback signals
    output logic [`XLEN-1:0]                wrb2exe_fb_rd_data_o,

    // Writeback <---> Forward_stall interface for feedback signals
    output type_wrb2fwd_s                    wrb2fwd_o
);

// Local signals
type_mem2wrb_data_s            mem2wrb_data;
type_mem2wrb_ctrl_s            mem2wrb_ctrl;
type_wrb2id_fb_s               wrb2id_fb;
logic [`XLEN-1:0]              wrb_rd_data;

// Assign appropriate values to the output signals
assign mem2wrb_data = mem2wrb_data_i;
assign mem2wrb_ctrl = mem2wrb_ctrl_i;
 
// Writeback MUX for output signal selection
always_comb begin
     wrb_rd_data = '0;
      case (mem2wrb_ctrl.rd_wrb_sel)
         RD_WB_ALU : begin
             wrb_rd_data = mem2wrb_data.alu_result;
         end
         RD_WB_INC_PC : begin
             wrb_rd_data = mem2wrb_data.pc + 32'd4;;
         end
         RD_WB_MEM : begin
             wrb_rd_data = mem2wrb_data.dmem_rdata;
         end
         RD_WB_CSR : begin
             wrb_rd_data = mem2wrb_data.csr_data;
         end
         default : wrb_rd_data  = '0; // default case 
     endcase
end

// Prepare the signals for output 
assign wrb2id_fb.rd_data    = wrb_rd_data; 
assign wrb2id_fb.rd_addr    = mem2wrb_data.rd_addr; 
assign wrb2id_fb.rd_wr_req  = mem2wrb_ctrl.rd_wr_req;

// Update the module output signals
assign wrb2id_fb_o          = wrb2id_fb;

assign wrb2fwd_o.rd_addr    = mem2wrb_data.rd_addr; 
assign wrb2fwd_o.rd_wr_req  = mem2wrb_ctrl.rd_wr_req;
assign wrb2exe_fb_rd_data_o = wrb_rd_data;

endmodule : writeback


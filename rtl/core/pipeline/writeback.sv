`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module writeback (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // MEM <---> WB interface
    input wire type_mem2wb_data_s           mem2wb_data_i,
    input wire type_mem2wb_ctrl_s           mem2wb_ctrl_i,

    // WB <---> ID interface for feedback signals
    output   logic                     wb2id_rd_wr_req_o,       // write request
    output   logic [`RF_AWIDTH-1:0]    wb2id_rd_addr_o,         // rd write address
    output   logic [`XLEN-1:0]         wb2id_rd_data_o          // rd write data from write-back

);

// Local signals
type_mem2wb_data_s           mem2wb_data;
type_mem2wb_ctrl_s           mem2wb_ctrl;
logic [`XLEN-1:0]            wb2id_rd_data;

// Assign appropriate values to the output signals
assign mem2wb_data        =  mem2wb_data_i;
assign mem2wb_ctrl        =  mem2wb_ctrl_i;

assign wb2id_rd_addr_o    =  mem2wb_data.rd_addr; 
assign wb2id_rd_wr_req_o  =  mem2wb_ctrl.rd_wr_req;

 
  // Writeback MUX for output signal selection
  always_comb begin
        wb2id_rd_data  = '0;

        case (mem2wb_ctrl.rd_wb_sel)
            RD_WB_ALU : begin
                wb2id_rd_data  =  mem2wb_data.alu_result;
            end
            RD_WB_INC_PC : begin
                wb2id_rd_data  =  mem2wb_data.pc + 4'b0100;;
            end
            RD_WB_MEM : begin
                wb2id_rd_data  =  mem2wb_data.dmem_data;
            end
            RD_WB_CSR : begin
                wb2id_rd_data  =  mem2wb_data.csr_data;
            end
            default :                ; // default case to suppress warning
        endcase
   end


// The output signal update
 assign wb2id_rd_data_o  =  wb2id_rd_data;

endmodule: writeback


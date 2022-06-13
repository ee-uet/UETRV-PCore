`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module memory (

    input   logic                           rst_n,                    // reset
    input   logic                           clk,                      // clock

    // EXE <---> MEM interface
    input  wire type_exe2mem_data_s         exe2mem_data_i,
    input  wire type_exe2mem_ctrl_s         exe2mem_ctrl_i,            // Structure for control signals from execute to memory 

    // MEM <---> WB interface
    output type_mem2wb_data_s               mem2wb_data_o,
    output type_mem2wb_ctrl_s               mem2wb_ctrl_o,

    // Memory module (memory) to Data memory (dmem) interface
    output type_signal_to_dmem_s            mem2dmem_o,                // Signal to data memory 
    input  wire type_signal_from_dmem_s     dmem2mem_i 

);

// Local signals
type_exe2mem_data_s          exe2mem_data;
type_exe2mem_ctrl_s          exe2mem_ctrl;
type_mem2wb_data_s           mem2wb_data;
type_mem2wb_ctrl_s           mem2wb_ctrl;
type_signal_to_dmem_s        mem2dmem;
type_signal_from_dmem_s      dmem2mem;

// Signal assignments
assign  exe2mem_data  =  exe2mem_data_i;
assign  exe2mem_ctrl  =  exe2mem_ctrl_i;

assign  dmem2mem      =  dmem2mem_i;

// Prepare the signals to perform load/store operations
assign  mem2dmem.addr     = exe2mem_data.alu_result;
assign  mem2dmem.data_in  = exe2mem_data.rs2_data; 
assign  mem2dmem.cs       = ~|exe2mem_ctrl.mem_ops;                                 // Chip select is active low
assign  mem2dmem.wr       =  (exe2mem_ctrl.mem_ops[3] | exe2mem_ctrl.mem_ops[2]);  // Memory write/store is active low

// Prepare the mask for load store  
always_comb begin
   mem2dmem.mask   =  '0;

   case (exe2mem_ctrl.mem_ops)
      MEM_OPS_SB, MEM_OPS_LB, MEM_OPS_LBU : begin
         mem2dmem.mask   =   4'b0001;
      end
      
      MEM_OPS_SH, MEM_OPS_LH, MEM_OPS_LHU : begin
         mem2dmem.mask   =   4'b0011;
      end

      MEM_OPS_SW, MEM_OPS_LW : begin
         mem2dmem.mask   =   4'b1111;
      end

      default :  mem2dmem.mask   =   4'b0000;
   endcase // mem_ops
end


assign  mem2wb_data.alu_result  =  exe2mem_data.alu_result;
assign  mem2wb_data.pc          =  exe2mem_data.pc;
assign  mem2wb_data.rd_addr     =  exe2mem_data.instr[11:7];  
assign  mem2wb_data.dmem_data   =  dmem2mem.data_out;       

assign  mem2wb_ctrl.rd_wb_sel   =  exe2mem_ctrl.rd_wb_sel;
assign  mem2wb_ctrl.rd_wr_req   =  exe2mem_ctrl.rd_wr_req;



assign  mem2wb_data_o  =  mem2wb_data;
assign  mem2wb_ctrl_o  =  mem2wb_ctrl;   

assign  mem2dmem_o     =  mem2dmem; 


endmodule: memory


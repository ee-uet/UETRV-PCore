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

logic [`XLEN-1:0]            dmem_rdata_word;
logic [15:0]                 dmem_rdata_hword;
logic [7:0]                  dmem_rdata_byte;
logic                        st_ops;

// Signal assignments
assign exe2mem_data  =  exe2mem_data_i;
assign exe2mem_ctrl  =  exe2mem_ctrl_i;
assign dmem2mem      =  dmem2mem_i;

// Prepare the signals to perform load/store operations
assign st_ops        = |exe2mem_ctrl.mem_st_ops;
assign mem2dmem.addr = exe2mem_data.alu_result;
assign mem2dmem.cs   = ~(st_ops | (|exe2mem_ctrl.mem_ld_ops)); // Chip select is active low
assign mem2dmem.wr   = ~st_ops;  // Memory write/store is active low

//=================================== Memory store operation =====================================//
// Prepare the write data and mask for store  
always_comb begin
   mem2dmem.data_wr = '0;
   mem2dmem.mask    = '0;

   case (exe2mem_ctrl.mem_st_ops)
      MEM_ST_OPS_SB : begin
         case (mem2dmem.addr[1:0]) 
            2'b00 : begin 
               mem2dmem.data_wr[7:0]   = exe2mem_data.rs2_data[7:0]; 
               mem2dmem.mask = 4'b0001;
            end 
            2'b01 : begin
               mem2dmem.data_wr[15:8]  = exe2mem_data.rs2_data[15:8];
               mem2dmem.mask = 4'b0010;
            end
            2'b10 : begin
               mem2dmem.data_wr[23:16] = exe2mem_data.rs2_data[23:16];
               mem2dmem.mask = 4'b0100;
            end
            2'b11 : begin
               mem2dmem.data_wr[31:24] = exe2mem_data.rs2_data[31:24];
               mem2dmem.mask = 4'b1000;
            end
            default : begin    
            end  
         endcase
      end // MEM_ST_OPS_SB   
      MEM_ST_OPS_SH : begin 
         case (mem2dmem.addr[1]) 
            1'b0 : begin
               mem2dmem.data_wr[15:0]  = exe2mem_data.rs2_data[15:0];
               mem2dmem.mask = 4'b0011;
            end 
            1'b1 : begin
               mem2dmem.data_wr[31:16]  = exe2mem_data.rs2_data[31:16];
               mem2dmem.mask = 4'b1100;
            end
            default : begin    
            end  
         endcase
      end // MEM_ST_OPS_SH
      MEM_ST_OPS_SW : begin
         mem2dmem.data_wr = exe2mem_data.rs2_data;
         mem2dmem.mask = 4'b1111;
      end
      default : begin
         mem2dmem.data_wr = '0;
      end
   endcase // mem_st_ops
end

//=================================== Memory load operation =====================================//
// Extract the right size from the read data  
always_comb begin
   dmem_rdata_byte  = '0;
   dmem_rdata_hword = '0;
   dmem_rdata_word  = '0;

   case (exe2mem_ctrl.mem_ld_ops)
      MEM_LD_OPS_LB,
      MEM_LD_OPS_LBU : begin
         case (mem2dmem.addr[1:0]) 
            2'b00 : begin 
               dmem_rdata_byte = dmem2mem.data_rd[7:0]; 
            end 
            2'b01 : begin
               dmem_rdata_byte = dmem2mem.data_rd[15:8];
            end
            2'b10 : begin
               dmem_rdata_byte = dmem2mem.data_rd[23:16];
            end
            2'b11 : begin
               dmem_rdata_byte = dmem2mem.data_rd[31:24];
            end
            default : begin    
            end  
         endcase
      end // MEM_LD_OPS_LB, MEM_LD_OPS_LBU 
      MEM_LD_OPS_LH,
      MEM_LD_OPS_LHU : begin 
         case (mem2dmem.addr[1]) 
            1'b0 : begin
               dmem_rdata_hword = dmem2mem.data_rd[15:0];
            end 
            1'b1 : begin
               dmem_rdata_hword = dmem2mem.data_rd[31:16];
            end
            default : begin    
            end  
         endcase
      end // MEM_LD_OPS_LH, MEM_LD_OPS_LHU
      MEM_LD_OPS_LW : begin
         dmem_rdata_word = dmem2mem.data_rd;
      end
      default : begin
      end
   endcase // mem_ld_ops
end


// Extend the load data for sign/zero
always_comb begin
    case (exe2mem_ctrl.mem_ld_ops)
        MEM_LD_OPS_LB  : mem2wb_data.dmem_rdata = {{24{dmem_rdata_byte[7]}},  dmem_rdata_byte};
        MEM_LD_OPS_LBU : mem2wb_data.dmem_rdata = { 24'b0,                    dmem_rdata_byte};
        MEM_LD_OPS_LH  : mem2wb_data.dmem_rdata = {{16{dmem_rdata_byte[15]}}, dmem_rdata_hword};
        MEM_LD_OPS_LHU : mem2wb_data.dmem_rdata = { 16'b0,                    dmem_rdata_hword};
        MEM_LD_OPS_LW  : mem2wb_data.dmem_rdata = {                           dmem_rdata_word};
        default        : mem2wb_data.dmem_rdata = '0;
    endcase // mem_ld_ops
end

// Update data for writeback
assign  mem2wb_data.alu_result =  exe2mem_data.alu_result;
assign  mem2wb_data.pc         =  exe2mem_data.pc;
assign  mem2wb_data.rd_addr    =  exe2mem_data.instr[11:7];  
//assign  mem2wb_data.dmem_rdata =  dmem2mem.data_rd;       

// Update control signals for writeback
assign  mem2wb_ctrl.rd_wb_sel  =  exe2mem_ctrl.rd_wb_sel;
assign  mem2wb_ctrl.rd_wr_req  =  exe2mem_ctrl.rd_wr_req;

// Update the output signals with proper assignment
assign  mem2wb_data_o  =  mem2wb_data;
assign  mem2wb_ctrl_o  =  mem2wb_ctrl;   
assign  mem2dmem_o     =  mem2dmem; 


endmodule : memory


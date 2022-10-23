`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/MMU_defs.svh"

module lsu (

    input   logic                           rst_n,                    // reset
    input   logic                           clk,                      // clock

    // EXE <---> LSU interface
    input  wire type_exe2lsu_data_s         exe2lsu_data_i,
    input  wire type_exe2lsu_ctrl_s         exe2lsu_ctrl_i,            // Structure for control signals from execute to memory 

    // LSU <---> CSR interface
    input wire type_csr2lsu_data_s          csr2lsu_data_i,
    output type_lsu2csr_data_s              lsu2csr_data_o,
    output type_lsu2csr_ctrl_s              lsu2csr_ctrl_o,

    // LSU <---> WRB interface
    output type_lsu2wrb_data_s              lsu2wrb_data_o,
    output type_lsu2wrb_ctrl_s              lsu2wrb_ctrl_o,

    // LSU <---> EXE interface for feedback signals
    output logic [`XLEN-1:0]                lsu2exe_fb_alu_result_o,

    // LSU <---> Forward_stall interface for forwarding
    output type_lsu2fwd_s                   lsu2fwd_o,

    // LSU module to data bus (dbus) interface
    output type_lsu2dbus_s                 lsu2dbus_o,                // Signal to data bus 
    input  wire type_dbus2lsu_s            dbus2lsu_i,

    output type_lsu2mmu_s                  lsu2mmu_o 

);

//============================= Local signals and their assignments =============================//
// Local signals
type_exe2lsu_data_s          exe2lsu_data;
type_exe2lsu_ctrl_s          exe2lsu_ctrl;
type_lsu2wrb_data_s          lsu2wrb_data;
type_lsu2wrb_ctrl_s          lsu2wrb_ctrl;
type_lsu2dbus_s              lsu2dbus;
type_dbus2lsu_s              dbus2lsu;
type_lsu2csr_data_s          lsu2csr_data;
type_lsu2csr_ctrl_s          lsu2csr_ctrl;
type_csr2lsu_data_s          csr2lsu_data;

type_lsu2fwd_s               lsu2fwd;
type_lsu2mmu_s               lsu2mmu;


logic [`XLEN-1:0]            rdata_word;
logic [15:0]                 rdata_hword;
logic [7:0]                  rdata_byte;
logic                        ld_req;
type_ld_ops_e                ld_ops;

// Signal assignments
assign exe2lsu_data  = exe2lsu_data_i;
assign exe2lsu_ctrl  = exe2lsu_ctrl_i;
assign dbus2lsu      = dbus2lsu_i;
assign csr2lsu_data  = csr2lsu_data_i;

// Prepare the signals to perform load/store operations      
assign ld_ops        = exe2lsu_ctrl.ld_ops;
assign ld_req        = |ld_ops; 
assign st_req        = |(exe2lsu_ctrl.st_ops);

//=================================== Memory load operation =====================================//
// Extract the right size from the read data  
always_comb begin
   rdata_byte  = '0;
   rdata_hword = '0;
   rdata_word  = '0;

   case (ld_ops)
      LD_OPS_LB,
      LD_OPS_LBU : begin
         case (lsu2dbus.addr[1:0]) 
            2'b00 : begin 
               rdata_byte = dbus2lsu.r_data[7:0]; 
            end 
            2'b01 : begin
               rdata_byte = dbus2lsu.r_data[15:8];
            end
            2'b10 : begin
               rdata_byte = dbus2lsu.r_data[23:16];
            end
            2'b11 : begin
               rdata_byte = dbus2lsu.r_data[31:24];
            end
            default : begin    
            end  
         endcase
      end // LD_OPS_LB, LD_OPS_LBU 
      LD_OPS_LH,
      LD_OPS_LHU : begin 
         case (lsu2dbus.addr[1]) 
            1'b0 : begin
               rdata_hword = dbus2lsu.r_data[15:0];
            end 
            1'b1 : begin
               rdata_hword = dbus2lsu.r_data[31:16];
            end
            default : begin    
            end  
         endcase
      end // LD_OPS_LH, LD_OPS_LHU
      LD_OPS_LW : begin
         rdata_word = dbus2lsu.r_data;
      end
      default : begin
      end
   endcase // ld_ops
end


// Extend the load data for sign/zero
always_comb begin
    if (dbus2lsu.ack) begin
        case (ld_ops)
            LD_OPS_LB  : lsu2wrb_data.r_data = {{24{rdata_byte[7]}},   rdata_byte};
            LD_OPS_LBU : lsu2wrb_data.r_data = { 24'b0,                rdata_byte};
            LD_OPS_LH  : lsu2wrb_data.r_data = {{16{rdata_hword[15]}}, rdata_hword};
            LD_OPS_LHU : lsu2wrb_data.r_data = { 16'b0,                rdata_hword};
            LD_OPS_LW  : lsu2wrb_data.r_data = {                       rdata_word};
            default    : lsu2wrb_data.r_data = '0;
        endcase // ld_ops
    end else begin
        lsu2wrb_data.r_data = '0;
    end
end

//=================================== Output signals update =====================================//

assign d_addr = exe2lsu_data.alu_result;

// Update data for CSR module
assign lsu2csr_data.pc_next   = exe2lsu_data.pc_next;
assign lsu2csr_data.dbus_addr = d_addr;

// Update control signals for CSR module
assign lsu2csr_ctrl.ld_ops = exe2lsu_ctrl.ld_ops;
assign lsu2csr_ctrl.st_ops = exe2lsu_ctrl.st_ops;

assign lsu2dbus.addr   = d_addr;
assign lsu2dbus.w_data = exe2lsu_data.rs2_data;
assign lsu2dbus.ld_req = ld_req;
assign lsu2dbus.st_ops = exe2lsu_ctrl.st_ops;

// Update data for writeback
assign lsu2wrb_data.alu_result = exe2lsu_data.alu_result;
assign lsu2wrb_data.pc_next    = exe2lsu_data.pc_next;
assign lsu2wrb_data.rd_addr    = exe2lsu_ctrl.rd_addr;        

// Update control signals for writeback
assign lsu2wrb_ctrl.rd_wrb_sel = exe2lsu_ctrl.rd_wrb_sel;
assign lsu2wrb_ctrl.rd_wr_req  = exe2lsu_ctrl.rd_wr_req;

// Signals for forwarding module
assign lsu2fwd.rd_addr         = exe2lsu_ctrl.rd_addr; 
assign lsu2fwd.rd_wr_req       = exe2lsu_ctrl.rd_wr_req;
assign lsu2fwd.ld_req          = ld_req;
assign lsu2fwd.ld_ack          = dbus2lsu.ack;

// Signals for forwading to EXE module
assign lsu2exe_fb_alu_result_o = exe2lsu_data.alu_result; 

// Signals for MMU
assign lsu2mmu.satp_ppn       = csr2lsu_data.satp_ppn;
assign lsu2mmu.en_vaddr       = csr2lsu_data.en_vaddr;
assign lsu2mmu.en_ld_st_vaddr = csr2lsu_data.en_ld_st_vaddr;
assign lsu2mmu.mxr            = csr2lsu_data.mxr;
assign lsu2mmu.tlb_flush      = csr2lsu_data.tlb_flush;
assign lsu2mmu.lsu_flush      = csr2lsu_data.lsu_flush;
assign lsu2mmu.d_req          = ld_req | st_req;
assign lsu2mmu.st_req         = st_req;
assign lsu2mmu.d_vaddr        = d_addr;

// Update the output signals with proper assignment
assign lsu2csr_data_o = lsu2csr_data;
assign lsu2csr_ctrl_o = lsu2csr_ctrl;
assign lsu2wrb_data_o = lsu2wrb_data;
assign lsu2wrb_ctrl_o = lsu2wrb_ctrl;   
assign lsu2dbus_o     = lsu2dbus; 
assign lsu2fwd_o      = lsu2fwd;
assign lsu2mmu_o      = lsu2mmu;

endmodule : lsu
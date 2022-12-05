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

    // LSU <---> Data Bus (dbus) interface
    input  wire type_dbus2lsu_s             dbus2lsu_i,
    output type_lsu2dbus_s                  lsu2dbus_o,                // Signal to data bus 

    // LSU <---> MMU interface 
    input wire type_mmu2lsu_s               mmu2lsu_i, 
    output type_lsu2mmu_s                   lsu2mmu_o 

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
type_mmu2lsu_s               mmu2lsu;


logic [`XLEN-1:0]            ld_st_addr;
logic [`XLEN-1:0]            rdata_word;
logic [15:0]                 rdata_hword;
logic [7:0]                  rdata_byte;
logic                        ld_req;
type_ld_ops_e                ld_ops;
type_amo_ops_e               amo_ops;
logic                        amo_req;
logic                        is_lr;
logic [31:0]                 amo_buffer_data;
logic [31:0]                 amo_buffer_data_ff;
logic [31:0]                 amo_buffer_addr;
logic [31:0]                 amo_buffer_addr_ff;
logic [31:0]                 amo_operand_a;
logic [31:0]                 amo_operand_a_ff;
logic [31:0]                 amo_operand_b;
logic [31:0]                 amo_result_o;
logic                        amo_done;
logic                        amo_load_ack_ff;
logic                        A_SLT_B, A_USLT_B;
logic                        is_amo;
logic                        is_sc;
logic                        sc_pass;
logic                        amo_reserve;
logic                        amo_reserve_ff;
// Signal assignments
assign is_amo        = |amo_ops;
assign is_lr         = amo_ops == AMO_OPS_LR;
assign is_sc         = amo_ops == AMO_OPS_SC;
assign amo_buffer_data    = is_lr ? lsu2wrb_data.r_data : amo_buffer_data_ff;
assign amo_buffer_addr    = is_lr ? exe2lsu_data.alu_result : amo_buffer_addr_ff;
assign amo_reserve        = is_lr ? 1 : amo_reserve_ff;


assign exe2lsu_data  = exe2lsu_data_i;
assign exe2lsu_ctrl  = exe2lsu_ctrl_i;
assign dbus2lsu      = dbus2lsu_i;
assign csr2lsu_data  = csr2lsu_data_i;
assign mmu2lsu       = mmu2lsu_i;
assign amo_operand_b = exe2lsu_data.rs2_data;
assign amo_operand_a = dbus2lsu.ack ? dbus2lsu.r_data : amo_operand_a_ff;

// Prepare the signals to perform load/store operations      
assign ld_ops        = is_amo ? LD_OPS_LW : exe2lsu_ctrl.ld_ops;
assign ld_req        = |ld_ops; 
assign st_req        = |(exe2lsu_ctrl.st_ops);
assign amo_ops       = exe2lsu_ctrl.amo_ops;
assign A_SLT_B = $signed(amo_operand_a) < $signed(amo_operand_b);
assign A_USLT_B = amo_operand_a < amo_operand_b;
assign amo_done = is_lr ? dbus2lsu.ack : amo_load_ack_ff;
assign sc_pass  = (is_sc & amo_reserve & (amo_buffer_addr_ff == exe2lsu_data.alu_result) & (amo_buffer_data_ff == amo_operand_a) && amo_done);

always_comb begin
    case (amo_ops)
        AMO_OPS_SC  : amo_result_o = amo_operand_b;
        AMO_OPS_SWAP: amo_result_o = amo_operand_b;
        AMO_OPS_ADD : amo_result_o = amo_operand_a + amo_operand_b;
        AMO_OPS_XOR : amo_result_o = amo_operand_a ^ amo_operand_b;
        AMO_OPS_AND : amo_result_o = amo_operand_a & amo_operand_b;
        AMO_OPS_OR  : amo_result_o = amo_operand_a | amo_operand_b;
        AMO_OPS_MIN : amo_result_o = A_SLT_B ? amo_operand_a : amo_operand_b;
        AMO_OPS_MAX : amo_result_o = A_SLT_B ? amo_operand_b : amo_operand_a;
        AMO_OPS_MINU: amo_result_o = A_USLT_B ? amo_operand_a : amo_operand_b;
        AMO_OPS_MAXU: amo_result_o = A_USLT_B ? amo_operand_b : amo_operand_a;
        default: amo_result_o = amo_operand_b;
    endcase
end

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
always_ff @( posedge clk ) begin 
   if (~rst_n | (is_sc & amo_done))
   begin
      amo_buffer_data_ff <= 0;
      amo_buffer_addr_ff <= 0;
      amo_reserve_ff     <= 0;
   end
   else if(is_lr) 
   begin
      amo_buffer_data_ff <= lsu2wrb_data.r_data;
      amo_buffer_addr_ff <= exe2lsu_data.alu_result;
      amo_reserve_ff     <= 1;
   end   
end
always_ff @( posedge clk ) begin 
   if (~rst_n | is_lr)
      amo_load_ack_ff <= 0;
   else
      amo_load_ack_ff <= dbus2lsu.ack;   
end
always_ff @( posedge clk ) begin 
   if (~rst_n)
      amo_operand_a_ff <= 0;
   else if(dbus2lsu.ack)
      amo_operand_a_ff <= dbus2lsu.r_data ;   
end

//=================================== Output signals update =====================================//

assign ld_st_addr = exe2lsu_data.alu_result;

// Update data for CSR module
assign lsu2csr_data.pc_next   = exe2lsu_data.pc_next;
assign lsu2csr_data.dbus_addr = ld_st_addr;

// Update control signals for CSR module
assign lsu2csr_ctrl.ld_ops = exe2lsu_ctrl.ld_ops;
assign lsu2csr_ctrl.st_ops = exe2lsu_ctrl.st_ops;

// Update data for writeback
assign lsu2wrb_data.alu_result = is_sc ? !sc_pass : exe2lsu_data.alu_result;
assign lsu2wrb_data.pc_next    = exe2lsu_data.pc_next;
assign lsu2wrb_data.rd_addr    = exe2lsu_ctrl.rd_addr;        

// Update control signals for writeback
assign lsu2wrb_ctrl.rd_wrb_sel = is_sc ? RD_WRB_ALU: exe2lsu_ctrl.rd_wrb_sel;
assign lsu2wrb_ctrl.rd_wr_req  = is_sc ? 1: exe2lsu_ctrl.rd_wr_req;

// Signals for forwarding module
assign lsu2fwd.rd_addr         = exe2lsu_ctrl.rd_addr; 
assign lsu2fwd.rd_wr_req       = is_sc ? 1: exe2lsu_ctrl.rd_wr_req;
assign lsu2fwd.ld_req          = ld_req;
assign lsu2fwd.ld_ack          = is_amo ? amo_done : dbus2lsu.ack;

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
assign lsu2mmu.d_vaddr        = ld_st_addr;

// Signals to data memory interface
assign lsu2dbus.addr   = ld_st_addr; // mmu2lsu.d_paddr[`XLEN-1:0];
assign lsu2dbus.ld_req = ld_req; // & (mmu2lsu.d_hit);
assign lsu2dbus.st_req = ((is_amo & amo_load_ack_ff) | (sc_pass)) ? 1 : st_req; // & (mmu2lsu.d_hit);
assign lsu2dbus.w_data = ((is_amo & amo_load_ack_ff) | (sc_pass)) ? amo_result_o : exe2lsu_data.rs2_data;
assign lsu2dbus.st_ops = ((is_amo & amo_load_ack_ff) | (sc_pass)) ? ST_OPS_SW : exe2lsu_ctrl.st_ops;

// Update the output signals with proper assignment
assign lsu2csr_data_o = lsu2csr_data;
assign lsu2csr_ctrl_o = lsu2csr_ctrl;
assign lsu2wrb_data_o = lsu2wrb_data;
assign lsu2wrb_ctrl_o = lsu2wrb_ctrl;   
assign lsu2dbus_o     = lsu2dbus; 
assign lsu2fwd_o      = lsu2fwd;
assign lsu2mmu_o      = lsu2mmu;

endmodule : lsu

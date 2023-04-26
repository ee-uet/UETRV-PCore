`ifndef VERILATOR
`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/MMU_defs.svh"
`include "../../defines/cache_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "cache_defs.svh"
`include "MMU_defs.svh"
`endif

module wb_dcache_top (
    input  wire                        clk_i,
    input  wire                        rst_ni,
    input  wire                        dmem_sel_i,
    input  wire                        dcache_flush_i,


    // LSU/MMU to data cache interface
    input wire type_lsummu2dcache_s    lsummu2dcache_i,
    output type_dcache2lsummu_s        dcache2lsummu_o,
  
    // Data cache to data memory interface  
    input wire type_dmem2dcache_s      dmem2dcache_i,
    output type_dcache2dmem_s          dcache2dmem_o
);

logic                              cache_hit;
logic                              cache_dirty_bit;
logic                              cache_wr;
logic                              cache_line_wr;
logic                              cache_writeback_req;

type_lsummu2dcache_s               lsummu2dcache;
type_dcache2lsummu_s               dcache2lsummu;

type_dmem2dcache_s                 dmem2dcache;
type_dcache2dmem_s                 dcache2dmem;

assign lsummu2dcache      = lsummu2dcache_i;
assign dmem2dcache.r_data = dmem2dcache_i.r_data;
assign dmem2dcache.ack    = dmem2dcache_i.ack;


wb_dcache_controller wb_dcache_controller_module(
  .clk_i                   (clk_i), 
  .rst_ni                  (rst_ni),

   // Interface signals for cache datapath
  .cache_hit_i             (cache_hit),
  .cache_dirty_bit_i       (cache_dirty_bit),
  .cache_wr_o              (cache_wr),
  .cache_line_wr_o         (cache_line_wr),
  .cache_writeback_req_o   (cache_writeback_req),    

  // LSU/MMU <---> data cache signals
  .lsummu2dcache_req_i     (lsummu2dcache.req),
  .lsummu2dcache_wr_i      (lsummu2dcache.w_en),
  .dcache2lsummu_ack_o     (dcache2lsummu.ack),

  // Data memory <---> data cache signals
  .dmem2dcache_ack_i       (dmem2dcache.ack),
  .dcache2dmem_req_o       (dcache2dmem.req),
  .dcache2dmem_wr_o        (dcache2dmem.w_en),
  .dmem_sel_i              (dmem_sel_i)
);  

wb_dcache_datapath wb_dcache_datapath_module(
  .clk_i                   (clk_i),
  .rst_ni                  (rst_ni),

  // Interface signals for cache datapath
  .cache_wr_i              (cache_wr),
  .cache_line_wr_i         (cache_line_wr),
  .cache_writeback_req_i   (cache_writeback_req),    
  .cache_hit_o             (cache_hit),
  .cache_dirty_bit_o       (cache_dirty_bit),

  // LSU/MMU <---> data cache signals
  .dcache_flush_i          (dcache_flush_i),
  .lsummu2dcache_addr_i    (lsummu2dcache.addr),
  .lsummu2dcache_wdata_i   (lsummu2dcache.w_data),
  .sel_byte_i              (lsummu2dcache.sel_byte),
  .dcache2lsummu_data_o    (dcache2lsummu.r_data),
  
  // Data memory <---> data cache signals
  .dmem2dcache_data_i      (dmem2dcache.r_data),
  .dcache2dmem_data_o      (dcache2dmem.w_data),
  .dcache2dmem_addr_o      (dcache2dmem.addr)
);


assign dcache2lsummu_o = dcache2lsummu;
assign dcache2dmem_o   = dcache2dmem;


endmodule

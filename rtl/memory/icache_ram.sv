// import cache_pkg::*;
`ifndef VERILATOR
`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"
`include "../defines/MMU_defs.svh"
`include "../defines/cache_pkg.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "cache_pkg.svh"
`include "MMU_defs.svh"
`endif
module icache_ram (
  input  wire logic                  clk_i,
  input  wire logic                  rst_ni,
  input  wire logic                  cache_rw_i,
  input  wire logic [IndexBits-1:0]  index_i,
  input  wire logic [TagBits-1:0]    write_tag_i,
  input  wire logic [LineWidth-1:0]  write_cldata_i,
  input  wire logic                  write_valid_i,

  output logic [TagBits-1:0]   read_tag_o,
  output logic [LineWidth-1:0] read_cldata_o,
  output logic                 read_valid_o
  );
  
  tag_ram ctag(
    .clk_i, 
    .rst_ni,
    .write_en_i   (cache_rw_i ),
    .tag_addr_i   (index_i    ),
    .tag_write_i  (write_tag_i),
    .tag_read_o   (read_tag_o )
  );
  valid_ram cvalid(
    .clk_i, 
    .rst_ni,
    .write_en_i     (cache_rw_i   ),
    .valid_addr_i   (index_i      ),
    .valid_write_i  (write_valid_i),
    .valid_read_o   (read_valid_o )
  );
  data_ram cdata(
    .clk_i, 
    .rst_ni,
    .write_en_i   (cache_rw_i    ),
    .data_addr_i  (index_i       ),
    .data_write_i (write_cldata_i),
    .data_read_o  (read_cldata_o )
  );

endmodule

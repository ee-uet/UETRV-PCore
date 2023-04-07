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

module tag_ram(
    input  wire logic                 clk_i, 
    input  wire logic                 rst_ni,
    input  wire logic                 icache_flush,
    input  wire logic                 write_en_i,
    input  wire logic [IndexBits-1:0] tag_addr_i,
    input  wire logic [TagBits-1:0]   tag_write_i,

    output logic [TagBits-1:0]   tag_read_o
  );

  logic [TagBits-1:0] TAG_RAM[0:n_of_Sets-1];

  assign tag_read_o = TAG_RAM[tag_addr_i];

  always_ff @(posedge(clk_i) or negedge(rst_ni) or posedge(icache_flush)) begin
    if (!rst_ni) begin
        for (integer i = 0; i < (n_of_Sets-1); i = i + 1) begin
            TAG_RAM[i] = {TagBits{1'b0}};
        end
    end else if (write_en_i) begin
        TAG_RAM[tag_addr_i] <= tag_write_i;
    end
  end
  
endmodule

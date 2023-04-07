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

module valid_ram(
    input  wire logic                 clk_i, 
    input  wire logic                 rst_ni,
    input  wire logic                 icache_flush,
    input  wire logic                 write_en_i,
    input  wire logic [IndexBits-1:0] valid_addr_i,
    input  wire logic                 valid_write_i,

    output logic                 valid_read_o
  );

  logic  VALID_RAM[0:n_of_Sets-1];

  assign valid_read_o = VALID_RAM[valid_addr_i];

  always_ff @(posedge(clk_i) or negedge(rst_ni) or posedge(icache_flush)) begin
    if (!rst_ni) begin
      for (integer i = 0; i < (n_of_Sets-1); i = i + 1) begin
        VALID_RAM[i] = 1'b0;
      end
    end else if (write_en_i) begin
      VALID_RAM[valid_addr_i] <= valid_write_i;
    end
  end
  
endmodule

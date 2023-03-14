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

module data_ram (
    input  wire logic                 clk_i, 
    input  wire logic                 rst_ni,
    input  wire logic                 write_en_i,
    input  wire logic [IndexBits-1:0] data_addr_i,
    input  wire logic [LineWidth-1:0] data_write_i,

    output logic [LineWidth-1:0] data_read_o
    );


  logic [LineWidth-1:0] DATA_RAM[0:n_of_Sets-1];

  assign data_read_o =  DATA_RAM[data_addr_i] ;

  always_ff @(posedge(clk_i) or negedge(rst_ni)) begin
    if (!rst_ni) begin
      for (integer i = 0; i < (n_of_Sets-1); i = i + 1) begin
            DATA_RAM[i] = {LineWidth{1'b0}};
        end
    end else if (write_en_i) begin
        DATA_RAM[data_addr_i] <= data_write_i;
    end
  end
  
endmodule

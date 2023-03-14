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

module icache_datapath(
  input  wire logic       clk_i,
  input  wire logic       rst_ni,
  input  wire logic       cache_rw_i,
  output logic            cache_hit_o,

  // Instruction Fetch to Instruction Cache Interface
  input wire logic  [AddrWidth-1:0] if2icache_addr_i,
  output logic [DataWidth-1:0]      icache2if_data_o,
  
  // Intruction Cache to Instruction Memory Interface
  input  wire logic [LineWidth-1:0]    imem2icache_data_i,
  output logic [DataWidth-1:0]         icache2imem_addr_o
  
  );
  logic [DataWidth-1:0] icache2if_data_ff;

    always_ff@(posedge clk_i) begin
    if(!rst_ni) begin
        icache2if_data_o <= '0;
    end else begin
        icache2if_data_o <= icache2if_data_ff;
    end
  end
  
  type_if2icache_s       if2icache;
  type_icache2imem_s     icache2imem;
  logic [TagBits-1:0]    req_tag;
  logic [1:0]            blk_sel;

  logic [DataWidth-1:0]   cc_resp_data_o;
  logic [IndexBits-1:0]   cache_indx, req_indx;
  cache_ram_t             cache_ram_read, cache_ram_write;

  assign req_tag  = if2icache_addr_i[31:TagLSB];
  assign req_indx = if2icache_addr_i[TagLSB-1:BlkOffMSB+1];
  assign blk_sel  = if2icache_addr_i[BlkOffMSB:2];

  assign cache_indx  = req_indx;
  assign cache_hit_o = (req_tag == cache_ram_read.tag) && cache_ram_read.valid;
  assign cache_ram_write.tag       = req_tag;
  assign cache_ram_write.valid     = 1'b1;
  assign cache_ram_write.data_line = imem2icache_data_i;
  
  assign icache2imem_addr_o       = if2icache_addr_i;
  assign icache2if_data_ff         = cc_resp_data_o;

  always_comb begin
    unique case (blk_sel)
      2'b00:    cc_resp_data_o = cache_ram_read.data_line[31:0]  ;
      2'b01:    cc_resp_data_o = cache_ram_read.data_line[63:32] ;
      2'b10:    cc_resp_data_o = cache_ram_read.data_line[95:64] ;
      2'b11:    cc_resp_data_o = cache_ram_read.data_line[127:96];
      default:  cc_resp_data_o = '0;
    endcase
  end

  icache_ram ram(
    .clk_i,
    .rst_ni,
    .cache_rw_i     (cache_rw_i               ),
    .index_i        (cache_indx               ),
    .write_tag_i    (cache_ram_write.tag      ),
    .write_cldata_i (cache_ram_write.data_line),
    .write_valid_i  (cache_ram_write.valid    ),
    .read_tag_o     (cache_ram_read.tag       ),
    .read_cldata_o  (cache_ram_read.data_line ),
    .read_valid_o   (cache_ram_read.valid     )
  );

endmodule
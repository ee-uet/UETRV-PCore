

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

module icache(
  input  wire logic             clk_i,
  input  wire logic             rst_ni,
  input  wire logic             imem_sel_i,

  

  // Instruction Fetch to Instruction Cache Interface
  input wire type_if2icache_s   if2icache_i,
  output type_icache2if_s       icache2if_o,
  
  // Instruction Cache to Instruction memory Interface  
  input wire type_imem2icache_s imem2icache_i,
  output type_icache2imem_s     icache2imem_o
  );

  // cpu2cc_request_t cpu_req_d, cpu_req_q;
  // logic cc_ready;
  logic cache_hit;
  logic cache_rw;
  // logic cc2mem_valid;


  type_if2icache_s   if2icache;
  type_imem2icache_s imem2icache;
  type_icache2if_s   icache2if;
  type_icache2imem_s icache2imem;

  assign if2icache.addr = if2icache_i.addr;
  assign if2icache.req  = if2icache_i.req;
  

  assign imem2icache.data = imem2icache_i.data;
  assign imem2icache.ack  = imem2icache_i.ack;

  // assign cpu_req_d = cpu2cc_request_i;

  // always_ff @( posedge clk_i or negedge rst_ni) begin
  //   if (!rst_ni) begin
  //     cpu_req_q <= {'0,'0,'0};
  //   end else if (ccncpu_ready_o) begin
  //     cpu_req_q <= cpu_req_d;
  //   end
  // end

  // val_ready_p dvr(
  //   .clk_i    (clk_i         ),
  //   .rst_ni   (rst_ni        ), 
  //   .valid_i  (cpu2cc_valid_i),
  //   .ready_i  (cc_ready      ),
  //   .start_o  (ccncpu_ready_o)
  // );

  icache_controller icache_controller_module(
  .clk_i                (clk_i), 
  .rst_ni               (rst_ni),
  .cache_hit_i          (cache_hit),
  .cache_rw_o           (cache_rw),

  .if2icache_request_i  (if2icache.req),
  .icache2if_ack_o      (icache2if.ack),

  .imem2icache_ack_i    (imem2icache.ack),
  .icache2imem_request_o(icache2imem.req),
  .imem_sel_i           (imem_sel_i)
  );  

  icache_datapath icache_datapath(
  .clk_i(clk_i),
  .rst_ni(rst_ni),
  .cache_rw_i(cache_rw),
  .cache_hit_o(cache_hit),

  // Instruction Fetch to Instruction Cache Interface
  .icache_flush(if2icache.icache_flush),
  .if2icache_addr_i(if2icache.addr),
  .icache2if_data_o(icache2if.r_data),
  
  // Intruction Cache to Instruction Memory Interface
  .imem2icache_data_i(imem2icache.data),
  .icache2imem_addr_o(icache2imem.addr)
  
  );



  assign icache2if_o = icache2if;
  assign icache2imem_o = icache2imem;


endmodule
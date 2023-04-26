`ifndef VERILATOR
`include "../defines/UETRV_PCore_ISA.svh"
`include "../defines/MMU_defs.svh"
`include "../defines/cache_defs.svh"
`else
`include "UETRV_PCore_ISA.svh"
`include "MMU_defs.svh"
`include "cache_defs.svh"
`endif

module mem_top (

    input   logic                                   rst_n,                   // reset
    input   logic                                   clk,                     // clock

  // Instruction cache memory interface
    input  wire type_if2icache_s                    if2icache_i,             // Bus interface from IF to icache 
    output type_icache2if_s                         icache2if_o,             // From imem to IF

  // MMU interface
    input  wire type_mmu2dmem_s                     mmu2dmem_i,              // Interface from MMU 
    output type_dmem2mmu_s                          dmem2mmu_o,              // From data memory to MMU

  // DBus <---> Data cache interface
    input   wire type_dbus2peri_s                   dbus2dmem_i,             // Data memory input signals
    output  type_peri2dbus_s                        dmem2dbus_o,             // Data memory output signals
    output  type_peri2dbus_s                        bmem2dbus_o,             // Boot memory output signals
    input wire                                      dcache_flush_i,

 // Selection signal from address decoder of dbus interconnect 
    input   logic                                   dmem_sel_i,
    input   logic                                   bmem_sel_i
);


// Local signals
type_if2icache_s                        if2icache;                           // Instruction memory address
type_icache2if_s                        icache2if; 
type_icache2if_s                        bmem2if;  
type_icache2imem_s                      icache2imem;
type_imem2icache_s                      imem2icache;

type_mmu2dmem_s                         mmu2dmem;               
type_dmem2mmu_s                         dmem2mmu;

type_dbus2peri_s                        dbus2peri; // lsummu2dmem;
type_peri2dbus_s                        dmem2dbus; // dmem2lsummu;              // Signals from data memory
type_peri2dbus_s                        bmem2dbus;  



type_lsummu2dcache_s                    lsummu2dcache;
type_dcache2lsummu_s                    dcache2lsummu;
type_dmem2dcache_s                      dmem2dcache;
type_dcache2dmem_s                      dcache2dmem;

// Peripheral module selection lines from the address decoder
logic                                   dmem_sel;
logic                                   bmem_sel;
logic                                   bmem_iaddr_match;

// Signal assignments
assign if2icache = if2icache_i;
assign mmu2dmem  = mmu2dmem_i;
assign dbus2peri = dbus2dmem_i;
assign dmem_sel  = dmem_sel_i;
assign bmem_sel  = bmem_sel_i;

assign bmem_iaddr_match = (if2icache.addr[`BMEM_SEL_ADDR_HIGH:`BMEM_SEL_ADDR_LOW] == `BMEM_ADDR_MATCH);

bmem_interface bmem_interface_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2bmem_i          (dbus2peri),
    .bmem_d_sel_i         (bmem_sel),
    .bmem2dbus_o          (bmem2dbus),

   // Instruction memory interface signals 
    .if2bmem_i            (if2icache),
    .bmem_iaddr_match_i   (bmem_iaddr_match),
    .bmem2if_o            (bmem2if)
    
);

//============================= Data bus arbitration for data cache =============================//
// Arbitration between LSU and MMU interfaces for data cache access
type_dmem_bus_states_e             state_next, state_ff; 

always_ff @(negedge rst_n, posedge clk) begin
    if (~rst_n) begin
        state_ff <= DMEM_IDLE; 
    end else begin
        state_ff <= state_next;
    end
end

always_comb begin
lsummu2dcache = '0;
dmem2dbus   = '0;
dmem2mmu    = '0;
state_next  = state_ff;

   case (state_ff)

       DMEM_IDLE: begin
           if (dmem_sel) begin
               lsummu2dcache.addr     = dbus2peri.addr;
               lsummu2dcache.w_data   = dbus2peri.w_data;
               lsummu2dcache.sel_byte = dbus2peri.sel_byte;
               lsummu2dcache.w_en     = dbus2peri.w_en;
               lsummu2dcache.req      = dbus2peri.cyc;
               state_next = DMEM_LSU;
           end else if (~dmem_sel & mmu2dmem.r_req) begin
               lsummu2dcache.addr     = mmu2dmem.paddr;
               lsummu2dcache.w_data   = '0;
               lsummu2dcache.sel_byte = '0;
               lsummu2dcache.w_en     = '0;
               lsummu2dcache.req      = 1'b1;
               state_next = DMEM_MMU;
           end
       end

       DMEM_LSU: begin

           if (dcache2lsummu.ack) begin
               dmem2dbus.r_data = dcache2lsummu.r_data;
               dmem2dbus.ack    = 1'b1;
               state_next = DMEM_IDLE;
           end else begin
               state_next = DMEM_LSU;
               lsummu2dcache.addr     = dbus2peri.addr;
               lsummu2dcache.w_data   = dbus2peri.w_data;
               lsummu2dcache.sel_byte = dbus2peri.sel_byte;
               lsummu2dcache.w_en     = dbus2peri.w_en;
               lsummu2dcache.req      = dbus2peri.cyc;
           end 

       end

       DMEM_MMU: begin

           if (dcache2lsummu.ack) begin
               dmem2mmu.r_data  = dcache2lsummu.r_data;
               dmem2mmu.r_valid = 1'b1;
               state_next = DMEM_IDLE;
           end else begin
               state_next = DMEM_MMU;
               lsummu2dcache.addr     = mmu2dmem.paddr;
               lsummu2dcache.w_data   = '0;
               lsummu2dcache.sel_byte = '0;
               lsummu2dcache.w_en     = '0;
               lsummu2dcache.req      = 1'b1;
           end 
       end

      default: begin     end
   endcase
 
end

//============================= Dual port memory interface =============================//
dualport_mem dualport_mem_module (
    .rst_n                  (rst_n),
    .clk                    (clk),

    // Data memory interface signals 
    .dcache2dmem_i          (dcache2dmem),
    .dmem2dcache_o          (dmem2dcache),
    .dmem_sel_i             (dmem_sel | mmu2dmem.r_req),

   // Instruction memory interface signals 
    .icache2imem_i          (icache2imem),
    .imem2icache_o          (imem2icache),
    .imem_sel_i             (~bmem_iaddr_match)
);

//=========================== Instruction cache top module =============================//
icache_top icache_top_module(
    .clk_i                  (clk),
    .rst_ni                 (rst_n),

    // Instruction fetch to instruction cache interface
    .if2icache_i            (if2icache),
    .icache2if_o            (icache2if),
  
    // Instruction cache to instruction memory interface  
    .imem2icache_i          (imem2icache),
    .icache2imem_o          (icache2imem),
    .imem_sel_i             (~bmem_iaddr_match)
);

//=========================== Data cache top module =============================//
wb_dcache_top wb_dcache_top_module(
    .clk_i                  (clk),
    .rst_ni                 (rst_n),

    // LSU/MMU to data cache interface
    .lsummu2dcache_i        (lsummu2dcache), // lsummu2dmem
    .dcache2lsummu_o        (dcache2lsummu), // dmem2lsummu
  
    // Data cache to data memory interface  
    .dmem2dcache_i          (dmem2dcache),
    .dcache2dmem_o          (dcache2dmem),
    .dcache_flush_i         (dcache_flush_i),
    .dmem_sel_i             (dmem_sel | mmu2dmem.r_req)
);



// Output signal assignments
assign icache2if_o   = bmem2if.ack ? bmem2if : icache2if; 
assign bmem2dbus_o = bmem2dbus;
assign dmem2dbus_o = dmem2dbus;  
assign dmem2mmu_o  = dmem2mmu; 

endmodule : mem_top


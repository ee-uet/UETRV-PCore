
`ifndef VERILATOR
`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"
`include "../defines/MMU_defs.svh"
`include "../defines/PLIC_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "MMU_defs.svh"
`include "PLIC_defs.svh"
`endif

module core_top (

    input   logic                        rst_n,                  // reset
    input   logic                        clk,                     // clock

    input   logic                        irq_ext_i,
    input   logic                        irq_soft_i,
    
    input   logic                        uart_rxd_i,
    output                               uart_txd_o 

);

// Local signals
type_if2imem_s                          if2imem;            // Instruction memory address
type_imem2if_s                          imem2if;  

type_mmu2dmem_s                         mmu2dmem;               
type_dmem2mmu_s                         dmem2mmu;

type_lsu2dbus_s                         lsu2dbus;           // Signal to data memory 
type_dbus2lsu_s                         dbus2lsu; 

type_dbus2peri_s                        dbus2peri;
type_pipe2csr_s                         core2pipe;


type_clint2csr_s                        clint2csr;

// Peripheral module selection lines from the address decoder
logic                                   dmem_sel;
logic                                   uart_sel;
logic                                   clint_sel;
logic                                   plic_sel;
logic                                   bmem_sel;


// IRQ ignals
logic                                   irq_uart;
logic                                   irq_clint_timer;
logic                                   irq_plic_target_0, irq_plic_target_1;

// Interfaces for different peripheral modules (for read mux)
type_peri2dbus_s                        dmem2dbus;              // Signals from data memory 
type_peri2dbus_s                        uart2dbus; 
type_peri2dbus_s                        clint2dbus;
type_peri2dbus_s                        plic2dbus; 
type_peri2dbus_s                        bmem2dbus;              // Signals from boot memory 

// Input assignment to local signals
assign core2pipe.csr_mhartid = `CSR_MHARTID;
assign core2pipe.ext_irq     = irq_plic_target_0 | irq_plic_target_1;
assign core2pipe.timer_irq   = irq_clint_timer;
assign core2pipe.soft_irq    = irq_soft_i;
assign core2pipe.uart_irq    = '0; // irq_uart

pipeline_top pipeline_top_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IMEM interface signals 
    .if2imem_o           (if2imem),   
    .imem2if_i           (imem2if),

    // MMU interface signals
    .dmem2mmu_i          (dmem2mmu),
    .mmu2dmem_o          (mmu2dmem),

    // DBUS interface signals
    .lsu2dbus_o          (lsu2dbus),       // Signal to data bus 
    .dbus2lsu_i          (dbus2lsu),

    .clint2csr_i         (clint2csr),

    // IRQ lines
    .core2pipe_i         (core2pipe)
);


dbus_interconnect dbus_interconnect_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data memory interface signals 
    .lsu2dbus_i            (lsu2dbus),
    .dbus2lsu_o            (dbus2lsu),

    // Peripheral (data memory and GPIO) selection signals
    .dmem_sel_o            (dmem_sel),
    .uart_sel_o            (uart_sel),
    .clint_sel_o           (clint_sel), 
    .plic_sel_o            (plic_sel),
    .bmem_sel_o            (bmem_sel), 

    // Signals from dbus to peripherals
    .dbus2peri_o           (dbus2peri),

   // Data memory and peripheral interface signals 
    .dmem2dbus_i           (dmem2dbus),
    .uart2dbus_i           (uart2dbus),
    .clint2dbus_i          (clint2dbus),
    .plic2dbus_i           (plic2dbus),
    .bmem2dbus_i           (bmem2dbus)
);


uart uart_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus and IO interface signals 
    .dbus2uart_i           (dbus2peri),  // This should be updated after the WB/AHBL bus interface is used
    .uart_sel_i            (uart_sel),
    .uart2dbus_o           (uart2dbus),
    .uart_irq_o            (irq_uart),
    .uart_rxd_i            (uart_rxd_i),
    .uart_txd_o            (uart_txd_o)
);

clint clint_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus and peripheral interface signals 
    .dbus2clint_i          (dbus2peri),  // This should be updated if the bus interface is updated
    .clint_sel_i           (clint_sel),
    .clint2dbus_o          (clint2dbus),

    .clint2csr_o           (clint2csr),
    .clint_timer_irq_o     (irq_clint_timer)
);

plic plic_module (
    .rst_n                 (rst_n    ),
    .clk                   (clk      ),

    // Data bus interface signals 
    .dbus2plic_i           (dbus2peri),  // This should be updated if the bus interface is updated
    .plic_sel_i            (plic_sel),
    .plic2dbus_o           (plic2dbus),
    .edge_select_i         (PLIC_SOURCE_COUNT'(3)),
    .irq_src_i             ({irq_uart, irq_ext_i}),
    .irq_targets_o         ({irq_plic_target_1, irq_plic_target_0})
);


mem_top mem_top_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2dmem_i          (dbus2peri),
    .dmem_sel_i           (dmem_sel),
    .dmem2dbus_o          (dmem2dbus),
    .bmem2dbus_o          (bmem2dbus),

   // MMU <---> data memory interface signals 
    .mmu2dmem_i           (mmu2dmem),
    .dmem2mmu_o           (dmem2mmu),

   // Instruction memory interface signals 
    .if2imem_i            (if2imem),
    .bmem_sel_i           (bmem_sel),
    .imem2if_o            (imem2if)
);


endmodule : core_top



`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

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

type_lsu2dbus_s                         lsu2dbus;               // Signal to data memory 
type_dbus2lsu_s                         dbus2lsu; 

type_dbus2peri_s                        dbus2peri;
type_pipe2csr_s                         core2pipe;

// Peripheral module selection lines from the address decoder
logic                                   dmem_sel;
logic                                   uart_sel;
logic                                   clint_sel;

// IRQ ignals
logic                                   irq_uart;
logic                                   irq_clint_timer;

// Interfaces for different peripheral modules (for read mux)
type_peri2dbus_s                        dmem2dbus;              // Signals from data memory 
type_peri2dbus_s                        uart2dbus; 
type_peri2dbus_s                        clint2dbus; 

// Input assignment to local signals
assign core2pipe.csr_mhartid = `CSR_MHARTID;
assign core2pipe.ext_irq     = irq_ext_i;
assign core2pipe.timer_irq   = irq_clint_timer;
assign core2pipe.soft_irq    = irq_soft_i;
assign core2pipe.uart_irq    = irq_uart;

pipeline_top pipeline_top_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IMEM interface signals 
    .if2imem_o           (if2imem),
    
    .imem2if_i           (imem2if),

    // DBUS interface signals
    .lsu2dbus_o          (lsu2dbus    ),       // Signal to data bus 
    .dbus2lsu_i          (dbus2lsu    ),

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

    // Signals from dbus to peripherals
    .dbus2peri_o           (dbus2peri),

   // Data memory and GPIO interface signals 
    .dmem2dbus_i           (dmem2dbus),
    .uart2dbus_i           (uart2dbus),
    .clint2dbus_i          (clint2dbus)
);


uart uart_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2uart_i           (dbus2peri),  // This should be updated after the WB/AHBL bus interface is used
    .uart_sel_i            (uart_sel),
    .uart2dbus_o           (uart2dbus),
    .uart_irq_o            (irq_uart),
    .uart_rxd_i            (uart_rxd_i),
    .uart_txd_o            (uart_txd_o)
);

clint clint_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2clint_i          (dbus2peri),  // This should be updated if the bus interface is updated
    .clint_sel_i           (clint_sel),
    .clint2dbus_o          (clint2dbus),
    .clint_timer_irq_o     (irq_clint_timer)
);


`ifdef DUALPORT_MEMORY
dualport_mem dualport_mem_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2dmem_i          (dbus2peri),
    .dmem_sel_i           (dmem_sel),
    .dmem2dbus_o          (dmem2dbus),

   // Instruction memory interface signals 
    .if2imem_i            (if2imem ),
    .imem2if_o            (imem2if)
);

`else
// Data memory
dmem dmem_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2dmem_i          (dbus2peri),
    .dmem_sel_i           (dmem_sel),
    .dmem2dbus_o          (dmem2dbus)
);


// Instruction memory
imem imem_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // Instruction memory interface signals 
    .if2imem_req_i       (if2imem_req  ),
    .if2imem_addr_i      (if2imem_addr ),
    .imem2if_rdata_o     (imem2if_rdata)
);
`endif


endmodule : core_top


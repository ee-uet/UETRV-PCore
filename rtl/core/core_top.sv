`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module core_top (

    input   logic                        rst_n,                  // reset
    input   logic                        clk,                     // clock

    input   logic [7:0]                  gpio_port_i,
    output  logic [7:0]                  gpio_port_o

);

// Local signals
logic                                   if2imem_req;             // Instruction memory request
logic [`XLEN-1:0]                       if2imem_addr;            // Instruction memory address
logic [`XLEN-1:0]                       imem2if_rdata;  
type_core2dbus_s                        ptop2dbus;               // Signal to data memory 
type_dbus2core_s                        dbus2ptop; 


// Interface for signals between dbus and core
type_dbus2core_s                        dbus2core;               // Signals to core
type_core2dbus_s                        core2dbus;

// Peripheral module selection lines from the address decoder
logic                                   dmem_sel;
logic                                   gpio_sel;

// Interfaces for different peripheral modules (for read mux)
type_dbus2core_s                        dmem2dbus;              // Signals from data memory 
type_dbus2core_s                        gpio2dbus; 


pipeline_top pipeline_top_module (
    .rst_n               (rst_n        ),
    .clk                 (clk          ),

    // IMEM interface signals 
    .if2imem_req_o       (if2imem_req  ),
    .if2imem_addr_o      (if2imem_addr ),
    .imem2if_rdata_i     (imem2if_rdata),

    // DMEM interface signals
    .ptop2dbus_o         (ptop2dbus    ),       // Signal to data memory 
    .dbus2ptop_i         (dbus2ptop    )
);


dbus_interconnect dbus_interconnect_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .core2dbus_i           (ptop2dbus),
    .dbus2core_o           (dbus2ptop),

    // Peripheral selection signals
    .dmem_sel_o            (dmem_sel),
    .gpio_sel_o            (gpio_sel), 

   // Instruction memory interface signals 
    .dmem2dbus_i           (dmem2dbus),
    .gpio2dbus_i           (gpio2dbus)
);


gpio gpio_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .dbus2gpio_i           (ptop2dbus),
    .gpio_sel_i            (gpio_sel),
    .gpio2dbus_o           (gpio2dbus),
    .gpio_port_i           (gpio_port_i),
    .gpio_port_o           (gpio_port_o)
);


`ifdef DUALPORT_MEMORY
dualport_mem dualport_mem_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .mem2dmem_i           (ptop2dbus),
    .dmem_sel_i           (dmem_sel),
    .dmem2mem_o           (dmem2dbus),

   // Instruction memory interface signals 
    .if2imem_req_i       (if2imem_req  ),
    .if2imem_addr_i      (if2imem_addr ),
    .imem2if_rdata_o     (imem2if_rdata)
);

`else
// Data memory
dmem dmem_module (
    .rst_n                (rst_n    ),
    .clk                  (clk      ),

    // Data memory interface signals 
    .mem2dmem_i           (ptop2dbus),
    .dmem_sel_i           (dmem_sel),
    .dmem2mem_o           (dmem2dbus)
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


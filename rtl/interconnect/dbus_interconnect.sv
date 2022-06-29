`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"

module dbus_interconnect (

    input   logic                                  rst_n,                    // reset
    input   logic                                  clk,                      // clock

    // Core to dbus interface
    input wire type_core2dbus_s                    core2dbus_i,

    // Interface for signals from dbus to core
    output type_dbus2core_s                        dbus2core_o,               // Signals to core

    // Peripheral module selection lines
    output logic                                   dmem_sel_o,
    output logic                                   gpio_sel_o, 

    // Interfaces for different peripheral modules (for read mux)
    input wire type_dbus2core_s                    dmem2dbus_i,              // Signals from data memory 
    input wire type_dbus2core_s                    gpio2dbus_i               // Signals from gpio module
);


// Local signals
//type_core_to_dbus_s                   core2dbus;
logic [`XLEN-1:0]                     dbus_addr;
logic                                 dbus_req;
logic                                 dmem_sel;
logic                                 gpio_sel;


// Connect the local signals to appropriate IOs of the module
assign dbus_addr = core2dbus_i.addr; 
assign dbus_req = core2dbus_i.req; 
assign addr_instr_space = |(dbus_addr & `IMEM_ADDR_MASK);

// Address decoder for peripheral module selection
always_comb begin
    dmem_sel = 1'b0;
    gpio_sel = 1'b0;
    if (((dbus_addr & `DMEM_ADDR_MASK) == `DMEM_ADDR_MATCH) || addr_instr_space) begin
        dmem_sel = 1'b1;
    end else if ((dbus_addr & `GPIO_ADDR_MASK) == `GPIO_ADDR_MATCH) begin
        gpio_sel = 1'b1;
    end
end

// Mux for the peripheral module read data
assign dbus2core_o = dmem_sel ? dmem2dbus_i 
                   : gpio_sel ? gpio2dbus_i 
                   : '0;

// Peripheral module selection signals from address decoder 
assign dmem_sel_o = dmem_sel;
assign gpio_sel_o = gpio_sel;


endmodule : dbus_interconnect


`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"

module gpio (

    input   logic                                  rst_n,                    // reset
    input   logic                                  clk,                      // clock

  // Dbus to GPIO module interface
    input   wire type_dbus2peri_s                  dbus2gpio_i,              // GPIO dbus input signals
    output  type_peri2dbus_s                       gpio2dbus_o,              // GPIO dbus output signals

  // Selection signal from address decoder of dbus interconnect 
    input   logic                                  gpio_sel_i,

  // IO signals from GPIO ports 
    input   logic [7:0]                            gpio_port_i,
    output  logic [7:0]                            gpio_port_o

);


// Local signals
type_dbus2peri_s                      dbus2gpio; 
type_peri2dbus_s                      gpio2dbus;              
logic [`XLEN-1:0]                     w_data_ff;
logic [`XLEN-1:0]                     addr_ff;
logic [3:0]                           mask_ff;
logic                                 wr_ff;
logic                                 req_ff;

logic                                 gpio_sel;
logic [7:0]                           gpio_rdata_reg;
logic [7:0]                           gpio_wdata_reg;

// Connect the local signals to appropriate IOs of the module
assign dbus2gpio = dbus2gpio_i; 
assign gpio_sel = gpio_sel_i;

always_ff @(posedge clk)
  begin
   if (~rst_n) begin
       req_ff     <= '0;
       wr_ff      <= '0;
       mask_ff    <= '0;
       addr_ff    <= '0;
       w_data_ff <= '0;
    end 
    else begin
       req_ff     <= dbus2gpio.req;
       wr_ff      <= dbus2gpio.wr;
       mask_ff    <= dbus2gpio.mask;
       w_data_ff <= dbus2gpio.w_data;
       addr_ff    <= dbus2gpio.addr[11:0];              // Address range is 12 bit 
    end
  end


// GPIO port read write operation 
always_ff @(negedge clk)
begin  
   if (!req_ff && !wr_ff && gpio_sel) begin           // Write operation
       gpio_wdata_reg <= w_data_ff[7:0];
   end else if (!req_ff && wr_ff && gpio_sel) begin   // Read operation
       gpio_rdata_reg <= gpio_port_i;
   end 
end

assign gpio_port_o = gpio_wdata_reg;
assign gpio2dbus_o.r_data[7:0] = gpio_rdata_reg;

endmodule : gpio


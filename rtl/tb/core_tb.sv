`timescale 1 ns / 100 ps

`include "../defines/UETRV_PCore_defs.svh"


module amo_tb();
reg clk, reset;
reg [31:0] loop_count;
wire [7:0] count;
reg  irq_ext, irq_soft;
reg  uart_rx;
wire uart_tx;

integer write_data;

core_top dut (
.clk                     (clk),
.rst_n                   (reset),
.irq_ext_i               (irq_ext),
.irq_soft_i              (irq_soft),
.uart_rxd_i              (uart_rx),
.uart_txd_o              (uart_tx)
); 


initial begin 
clk=0;
forever #5 clk=~clk;
end

initial begin
reset=0;
#20;
reset=1;
end

initial begin
irq_ext = 0;
irq_soft = 0;
uart_rx = 1;
end

initial
 begin
    $dumpfile("core_tb.vcd");
    $dumpvars(0, amo_tb);
    
    begin
         repeat (100) @ (posedge clk);
    end
    $display("End of simulation");
    $finish; 
 end


endmodule
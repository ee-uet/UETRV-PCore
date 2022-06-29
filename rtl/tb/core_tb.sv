`timescale 1 ns / 100 ps

`include "../defines/UETRV_PCore_defs.svh"


module core_tb();
reg clk, reset;
reg [31:0] loop_count;
reg  port_in;
wire port_out;
wire [7:0] count;


core_top dut (
.clk                     (clk),
.rst_n                   (reset),
.gpio_port_i             (port_in),
.gpio_port_o             (port_out)
); 


initial begin 
clk=0;
forever #5 clk=~clk;
end

initial begin
reset=1;
#20;
reset=0;
end

initial
 begin
    $dumpfile("core_tb.vcd");
    $dumpvars(0, core_tb);

    for (loop_count = 0; loop_count < 100; loop_count = loop_count + 1)
    begin
         repeat (1) @ (posedge clk);
    end
    $display("End of simulation");
    $finish; 
 end


endmodule
`timescale 1 ns / 100 ps

`include "../defines/UETRV_PCore_defs.svh"


module core_tb();
reg clk, reset;
reg [33:0] loop_count;
wire [7:0] count;
reg  irq_ext, irq_soft;
reg  uart_rx;
wire uart_tx;

integer tracelog_filepointer, uartlog_filepointer;
logic flag = 0, flag2 = 0;

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
  //  $dumpfile("core_tb.vcd");
  //  $dumpvars(0, core_tb);

    tracelog_filepointer = $fopen("trace_logdata.txt");
    uartlog_filepointer = $fopen("uart_logdata.txt");

    for (loop_count = 0; loop_count < 80000000; loop_count = loop_count + 1)
    begin
         repeat (1) @ (posedge clk);


         if (dut.uart_module.tx_valid_ff == 1)
             $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);


    end

    $display("End of simulation");
    $fclose(tracelog_filepointer);
    $fclose(uartlog_filepointer);
    $finish; 
 end


endmodule
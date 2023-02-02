`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../defines/UETRV_PCore_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`endif

`ifndef VERILATOR
module core_tb();
`else
module core_tb(input bit clk);
`endif

`ifdef VERILATOR
reg clk;
`endif
reg reset;
reg [31:0] loop_count;
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

`ifndef VERILATOR
initial begin 
clk=0;
forever #5 clk=~clk;
end

initial begin
reset=0;
#20;
reset=1;
end
`endif

initial begin
irq_ext = 0;
irq_soft = 0;
uart_rx = 1;
end

`ifndef VERILATOR
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
`else
initial
 begin
  //  $dumpfile("core_tb.vcd");
  //  $dumpvars(0, core_tb);
    $display("Start of simulation");
    loop_count = 0;
    tracelog_filepointer = $fopen("trace_logdata.txt", "w");
    uartlog_filepointer = $fopen("uart_logdata.txt", "w");

    // for (loop_count = 0; loop_count < 80000000; loop_count = loop_count + 1)
    // begin
    //      repeat (1) @ (posedge clk);


    //      if (dut.uart_module.tx_valid_ff == 1)
    //          $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);


    // end
 end

always_ff @(posedge clk ) begin
if(loop_count <= 9) reset=0;
else reset=1;
end

always_ff@(posedge clk) begin
  loop_count = loop_count + 1;
  if (dut.uart_module.tx_valid_ff == 1)
    $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);

  if(loop_count == {32{1'b1}}) begin
    $display("End of simulation");
    $fclose(tracelog_filepointer);
    $fclose(uartlog_filepointer);
    $finish; 
  end
end

`endif


endmodule
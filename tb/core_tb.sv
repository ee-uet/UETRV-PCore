`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "./rtl/defines/pcore_interface_defs.svh"
`else
`include "pcore_interface_defs.svh"
`endif

`ifndef VERILATOR
logic flag2, clk;
module core_tb();
`else
module core_tb(input bit clk, output reg flag2);
`endif

type_debug_port_s           debug_port;
logic                       reset;
logic [35:0]                loop_count;
logic [7:0]                 count;
logic [31:0]                log_count=0, base_time=0;
logic                       irq_ext, irq_soft;
logic                       uart_rx, uart_tx;
logic                       spi_clk, spi_cs, spi_mosi, spi_miso;

logic [7:0]                 offset;
logic [7:0]                 tx_ch;

integer tracelog_filepointer, uartlog_filepointer;
logic flag = 0, irq_flag = 0;

soc_top dut (
.clk                     (clk),
.rst_n                   (reset),
.irq_ext_i               (irq_ext),
.irq_soft_i              (irq_soft),
.uart_rxd_i              (uart_rx),
.uart_txd_o              (uart_tx),
.spi_clk_o               (spi_clk),
.spi_cs_o                (spi_cs),
.spi_miso_i              (spi_miso),
.spi_mosi_o              (spi_mosi),
.debug_port_i            (debug_port)
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
irq_ext   = 0;
irq_soft  = 0;
uart_rx   = 1;
spi_miso  = 1;
flag2     = 0;
irq_flag  = 0;

debug_port.reg_data   = '0;
debug_port.reg_addr   = '0;
debug_port.reg_wr_req = '0;
end

`ifndef VERILATOR
initial begin
    $display("Start of simulation");
    uartlog_filepointer = $fopen("uart_logdata.txt", "w");   
end

initial begin

    for (loop_count = 0; loop_count < 64'd8000000000; loop_count = loop_count + 1) begin
        repeat (1) @ (posedge clk);

        if (dut.uart_module.tx_valid_ff == 1)
            $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);
    end

    if(loop_count == {32'h0e000000}) begin 
        $display("End of simulation");
        $fclose(uartlog_filepointer);
        $finish; 
    end
end

`else
initial
 begin
  //  $dumpfile("core_tb.vcd");
  //  $dumpvars(0, core_tb);
    $display("Start of simulation");
    loop_count = 0;
    uartlog_filepointer = $fopen("uart_logdata.txt", "w");
end

always_ff @(posedge clk ) begin
if(loop_count <= 9) reset=0;
else reset=1;
end 


always_ff@(posedge clk) begin
  loop_count = loop_count + 1;
  if (dut.uart_module.tx_valid_ff == 1)
    $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);

  if(loop_count == {32'h0e000000} || log_count == 3000) begin 
    $display("End of simulation");
    $fclose(uartlog_filepointer);
    $finish; 
  end

end

`endif

endmodule

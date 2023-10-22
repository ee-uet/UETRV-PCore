`timescale 1 ns / 100 ps
`include "pcore_interface_defs.svh"

module pcore_tb(input bit clk, input bit reset);

reg                       irq_ext;
reg                       irq_soft;
reg                       uart_rx;
wire                      uart_tx;
logic                     spi_clk, spi_cs, spi_mosi, spi_miso;
reg [1023:0]              firmware;
reg [1023:0]              max_cycles;
reg [1023:0]              main_time = '0;

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
  .spi_mosi_o              (spi_mosi)
); 

initial begin
  irq_ext   = 0;
  irq_soft  = 0;
  uart_rx   = 1;
  spi_miso  = 1;

  // Load hex instructions
  if($value$plusargs("imem=%s",firmware)) begin
    $display("Loading Instruction Memory from %0s", firmware);
    $readmemh(firmware, dut.mem_top_module.main_mem_module.dualport_memory);
  end

  if($value$plusargs("max_cycles=%d",max_cycles)) begin
    $display("Timeout set as %0d cycles\n", max_cycles);
  end
end

always_ff@(posedge clk ) begin
  if(main_time < max_cycles) begin
    main_time <= main_time + 1;
  end else begin
    $display("Timeout: Exiting after %0d cycles\n", main_time);
    $finish;
  end
end

`ifndef COMPLIANCE
/*    Logic to dump UART logs, instruction trace or any other type 
      of logs must be added here      */

// ====================== UART logs ========================== //

integer     uartlog_filepointer;

initial begin
  uartlog_filepointer = $fopen("uart_logdata.log", "w");
end

always_ff@(posedge clk) begin
  if (dut.uart_module.tx_valid_ff == 1)
    $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);
end

`else
// ====================== For RISC-V architecture tests ========================== //

wire sig_en  = (dut.dbus2peri.addr == 32'h8E000000) & dut.mem_top_module.wb_dcache_top_module.cache_wr;
wire halt_en = (dut.dbus2peri.addr == 32'h8F000000) & dut.mem_top_module.wb_dcache_top_module.cache_wr;
  
reg [1023:0] signature_file;

integer write_sig=0;
  
initial begin
  write_sig = $fopen("DUT-pcore.signature", "w"); // Open file for writing
  if (write_sig == 0) begin
    $display("Error opening file for writing");
    $finish;
  end
end
  
always_ff@(posedge clk) begin 
  if(sig_en & (write_sig!=0))
    $fwrite(write_sig,"%h\n",dut.dbus2peri.w_data);
  else if(halt_en) begin
    $display("Test Complete");
    $fclose(write_sig);
    $finish;
  end
end

`endif 
endmodule

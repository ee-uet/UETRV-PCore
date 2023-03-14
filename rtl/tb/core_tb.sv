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

`ifndef VERILATOR
reg clk;
`endif

reg reset;
reg [35:0] loop_count;
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
flag2 = 0;
end


`ifndef VERILATOR
initial
 begin
  //  $dumpfile("core_tb.vcd");
  //  $dumpvars(0, core_tb);

    tracelog_filepointer = $fopen("trace_logdata.txt");
    uartlog_filepointer = $fopen("uart_logdata.txt");

    for (loop_count = 0; loop_count < 64'd8000000000; loop_count = loop_count + 1)
    begin
         repeat (1) @ (posedge clk);

      /*   if (loop_count == 62) irq_ext = 1;
         else irq_ext = 0;

         if (loop_count == 260) 
             uart_rx = 0;

         if (loop_count == 276) uart_rx = 1;
         if (loop_count == 292) uart_rx = 1; 
         if (loop_count == 308) uart_rx = 0;
         if (loop_count == 324) uart_rx = 0; 

         if (loop_count == 340) uart_rx = 1;
         if (loop_count == 356) uart_rx = 0; 
         if (loop_count == 372) uart_rx = 1;
         if (loop_count == 388) uart_rx = 0; 
         if (loop_count == 404) uart_rx = 1; 
      */

         if ((dut.pipeline_top_module.csr_module.exe2csr_data.instr_flushed == 1'b0) &&
             (dut.pipeline_top_module.forward_stall_module.lsu_mul_stall_ff == 1'b0) && flag2) begin
            $fwrite(tracelog_filepointer, "%d \t %h \n", loop_count, dut.pipeline_top_module.csr_module.exe2csr_data.pc); 
                                                             //  dut.pipeline_top_module.execute_module.id2exe_data.instr); 
      //   $fwrite(tracelog_filepointer, "\t %h", dut.pipeline_top_module.execute_module.exe2lsu_data_o.alu_result); 
      //   $fwrite(tracelog_filepointer, "\t %h", dut.pipeline_top_module.execute_module.exe2lsu_ctrl_o.ld_ops);
	 end

         if (dut.uart_module.tx_valid_ff == 1)
             $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);

         if (dut.uart_ns_module.tx_valid_ff == 1)
             $fwrite(uartlog_filepointer, "%c", dut.uart_ns_module.uart_reg_tx_ff);


         if (dut.pipeline_top_module.csr_module.csr_satp_wr_flag == 1'b1)
             flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'h80000498)
		flag = 1;

         if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc0401654)
		flag2 = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc0001974)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc040189c)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc0406418)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc047b234)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc0001dfc)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc0020228)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc001ef50)
		flag = 1;
	
	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc001ef64)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc06d4ce4)
		flag = 1;


	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc07d39bc)
		flag = 1;

	 if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc06d60e8)
		flag = 1;


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

  if (dut.uart_ns_module.tx_valid_ff == 1)
    $fwrite(uartlog_filepointer, "%c", dut.uart_ns_module.uart_reg_tx_ff);

  if ((dut.pipeline_top_module.csr_module.exe2csr_data.instr_flushed == 1'b0) &&
             (dut.pipeline_top_module.forward_stall_module.lsu_mul_stall_ff == 1'b0) && flag) begin
            $fwrite(tracelog_filepointer, "%d \t %h \n", loop_count, dut.pipeline_top_module.csr_module.exe2csr_data.pc);
   end

 /* if ((dut.clint_module.mtimecmp_ff[35:32] == 3'h3) || ((dut.clint_module.timer_clk_ff == 1'b0) &&
             (dut.clint_module.timer_clk_next == 1'b1) && flag)) begin
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \n", loop_count, dut.clint_module.mtimecmp_ff[35:0],  	
                                                                           dut.clint_module.mtime_ff[35:0]);
   end */

  if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc003ffa8 ) // c027517c   hc003ffa8 hc0268c74
		flag = 1; 

  if(loop_count == {32'h08000000}) begin
    $display("End of simulation");
    $fclose(tracelog_filepointer);
    $fclose(uartlog_filepointer);
    $finish; 
  end
end

`endif

endmodule

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
reg flag = 0;

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

         if (dut.pipeline_top_module.execute_module.id2exe_ctrl.jump_req == 1'b1)
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \n\r", loop_count, dut.pipeline_top_module.execute_module.id2exe_data.pc,                    dut.pipeline_top_module.execute_module.id2exe_data.pc_next); 
      //   $fwrite(tracelog_filepointer, "\t %h", dut.pipeline_top_module.execute_module.exe2lsu_data_o.alu_result); 
      //   $fwrite(tracelog_filepointer, "\t %h", dut.pipeline_top_module.execute_module.exe2lsu_ctrl_o.ld_ops);


         if (dut.uart_module.tx_valid_ff == 1)
             $fwrite(uartlog_filepointer, "%c", dut.uart_module.uart_reg_tx_ff);


         if (dut.pipeline_top_module.csr_module.csr_satp_wr_flag == 1'b1)
             flag = 1;
    end

    $display("End of simulation");
    $fclose(tracelog_filepointer);
    $fclose(uartlog_filepointer);
    $finish; 
 end


endmodule
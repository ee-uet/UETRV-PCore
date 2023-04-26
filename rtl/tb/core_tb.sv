`timescale 1 ns / 100 ps

`ifndef VERILATOR
`include "../defines/UETRV_PCore_ISA.svh"
`else
`include "UETRV_PCore_ISA.svh"
`endif

`ifndef VERILATOR
module core_tb();
`else
module core_tb(input bit clk, output reg flag2);
`endif

`ifndef VERILATOR
reg clk;
`endif

reg reset;
reg [35:0] loop_count;
wire [7:0] count;
reg [31:0] log_count=0, base_time=0;
reg  irq_ext, irq_soft;
reg  uart_rx;
wire uart_tx;
type_debug_port_s         debug_port;

reg [7:0] offset;
reg [7:0] tx_ch;

integer tracelog_filepointer, uartlog_filepointer, tracelog_fp2;
logic flag = 0, flag2 = 0, irq_flag = 0;

core_top dut (
.clk                     (clk),
.rst_n                   (reset),
.irq_ext_i               (irq_ext),
.irq_soft_i              (irq_soft),
.uart_rxd_i              (uart_rx),
.uart_txd_o              (uart_tx),
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
irq_ext = 0;
irq_soft = 0;
uart_rx = 1;
flag2 = 0;
irq_flag = 0;
base_time = 32'd224650200;
offset = 5;
tx_ch = 8'h33;

debug_port.reg_data = '0;
debug_port.reg_addr = '0;
debug_port.reg_wr_req = '0;
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

/*	if (loop_count == 2598) irq_ext = 1;
        if (loop_count == 2610) irq_ext = 0;

	if (loop_count == 6201) irq_ext = 1;
        if (loop_count == 6300) irq_ext = 0;

	if (loop_count == 9502) irq_ext = 1;
        if (loop_count == 9602) irq_ext = 0;

         if (loop_count == 62) irq_ext = 1;
         else irq_ext = 0;

         if (loop_count == 9500) begin
             base_time = loop_count + 1;
             tx_ch = 8'h6c;
         end

         if (loop_count == 14500) begin
             base_time = loop_count + 1;
             tx_ch = 8'h73;
         end

        if (loop_count == 19500) begin
             base_time = loop_count + 1;
             tx_ch = 8'h0a;
         end

         if (loop_count == base_time) 
             uart_rx = 0;

         if (loop_count == base_time+offset*1) uart_rx = tx_ch[0];
         if (loop_count == base_time+offset*2) uart_rx = tx_ch[1]; 
         if (loop_count == base_time+offset*3) uart_rx = tx_ch[2];
         if (loop_count == base_time+offset*4) uart_rx = tx_ch[3]; 

         if (loop_count == base_time+offset*5) uart_rx = tx_ch[4];
         if (loop_count == base_time+offset*6) uart_rx = tx_ch[5]; 
         if (loop_count == base_time+offset*7) uart_rx = tx_ch[6];
         if (loop_count == base_time+offset*8) uart_rx = tx_ch[7]; 
         if (loop_count == base_time+offset*9) uart_rx = 1; 
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

         if (dut.pipeline_top_module.forward_stall_module.if2fwd_stall == 1)
		 flag = 1;
           //  $fwrite(uartlog_filepointer, "%c", dut.uart_ns_module.uart_reg_tx_ff);

         if (loop_count == 7058300) begin
             flag = 1;
         end

         if (dut.pipeline_top_module.csr_module.csr_satp_wr_flag == 1'b1)
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
	/*
	 if (loop_count == 2000) begin
	     debug_port.reg_data = 32'ha;
             debug_port.reg_addr = 5'ha;
             debug_port.reg_wr_req = 1'b1;
         end else begin
	     debug_port.reg_data = '0;
             debug_port.reg_addr = '0;
             debug_port.reg_wr_req = '0;
         end
	*/

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
    tracelog_fp2        = $fopen("proc_log.txt", "w");     // ../../Debug/

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
             (dut.pipeline_top_module.csr_module.lsu2csr_data.pc_next != dut.pipeline_top_module.csr_module.exe2csr_data.pc)  &&
             (dut.pipeline_top_module.forward_stall_module.lsu_mul_stall_ff == 1'b0) && flag) begin //  (loop_count > 21)
            $fwrite(tracelog_fp2, "%h \t %h \t %d \n", dut.pipeline_top_module.csr_module.exe2csr_data.pc,
                                                                     dut.pipeline_top_module.csr_module.exe2csr_data.instr, loop_count);
   end 

/*
  if (dut.pipeline_top_module.csr_module.lsu_pf_exc_req == 1'b1) begin
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \t %h \n", loop_count, dut.pipeline_top_module.csr_module.exc_code,
                                                                     dut.pipeline_top_module.csr_module.lsu2csr_ctrl.vaddr,  
                                                                     dut.pipeline_top_module.csr_module.exe2csr_data.instr);
   end 

 if (dut.pipeline_top_module.csr_module.i_pf_exc_req == 1'b1) begin
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \t %h \n", loop_count, dut.pipeline_top_module.csr_module.exc_code,

                                                                     dut.pipeline_top_module.csr_module.lsu2csr_ctrl.vaddr,  
                                                                     dut.pipeline_top_module.csr_module.exe2csr_data.instr);
   end 


  if ((dut.clint_module.timer_overflow_ff == 1'b0) &&
             (dut.clint_module.timer_overflow_next == 1'b1)) begin
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \n", loop_count, dut.clint_module.mtimecmp_ff[35:0],  	
                                                                           dut.clint_module.mtime_ff[35:0]);
   end  

*/
   if (dut.pipeline_top_module.csr_module.exc_req == 1'b1) begin

	if (dut.pipeline_top_module.csr_module.exe2csr_data.instr == 32'h00000073) begin
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \t %h \t %d \n", loop_count, dut.pipeline_top_module.csr_module.exc_code,
                                                                     dut.pipeline_top_module.csr_module.exe2csr_data.pc,  
                                                                     dut.pipeline_top_module.csr_module.exe2csr_data.instr,                  
                                                                     dut.pipeline_top_module.decode_module.rf_module.register_file[17]);
        end else begin
            $fwrite(tracelog_filepointer, "%d \t %h \t %h \t %h \n", loop_count, dut.pipeline_top_module.csr_module.exc_code,
                                                                     dut.pipeline_top_module.csr_module.lsu2csr_data.dbus_addr,  
                                                                     dut.pipeline_top_module.csr_module.exe2csr_data.instr);
        end

   end

/*  if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'h80000498 && (dut.clint_module.timer_overflow_ff == 1'b1) && ~irq_flag) begin 
	irq_flag = 1; 
	reg_log();
     //  $fclose(tracelog_filepointer);
  end 

  if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc000262c && irq_flag ) begin // c00e78dc   hc003ffa8 hc0268c74
	irq_flag = 0; 
	reg_log();
     //  $fclose(tracelog_filepointer);
  end
*/


  if (dut.pipeline_top_module.csr_module.exe2csr_data.pc == 32'hc025f588) begin // c027517c   hc003ffa8 hc0268c74
	irq_flag = 1; 
 //	$fwrite(tracelog_filepointer, "%d \t %h \n", loop_count, dut.pipeline_top_module.csr_module.csr_satp_ff);
     //  $fclose(tracelog_filepointer);
     //  $fclose(uartlog_filepointer);
     //  $finish;
  end 

  // reg_log();
 if (dut.uart_module.uart_reg_tx_next == 8'h4f && irq_flag == 1) begin 
    flag = 1;
 //   reg_log();
 end 

// if (loop_count == {32'd157186100}) flag2 = 1;
// if (loop_count == {32'd1}) flag2 = 1;

// if (dut.uart_module.rx_valid == 1) flag2 = 1;

// if (flag2)   log_count = log_count + 1;

  if(loop_count == {32'h0d000000} || log_count == 300000) begin // || log_count == 500000 
    $display("End of simulation");
    $fclose(tracelog_filepointer);
    $fclose(tracelog_fp2);
    $fclose(uartlog_filepointer);
    $finish; 
  end


	/* if (loop_count == 32'd157186110) begin
	     debug_port.reg_data = 32'h1;
             debug_port.reg_addr = 5'ha;
             debug_port.reg_wr_req = 1'b1;
         end else begin
	     debug_port.reg_data = '0;
             debug_port.reg_addr = '0;
             debug_port.reg_wr_req = 1'b0;
         end

        if (loop_count == 32'd172820084) begin
             base_time = loop_count + 1;
             tx_ch = 8'h6c;
         end

         if (loop_count == 32'd178650200) begin
             base_time = loop_count + 1;
             tx_ch = 8'h73;
         end

        if (loop_count == 32'd184650200) begin
             base_time = loop_count + 1;
             tx_ch = 8'h0a;
         end

         if (loop_count == base_time) 
             uart_rx = 0;

         if (loop_count == base_time+offset*1) uart_rx = tx_ch[0];
         if (loop_count == base_time+offset*2) uart_rx = tx_ch[1]; 
         if (loop_count == base_time+offset*3) uart_rx = tx_ch[2];
         if (loop_count == base_time+offset*4) uart_rx = tx_ch[3]; 

         if (loop_count == base_time+offset*5) uart_rx = tx_ch[4];
         if (loop_count == base_time+offset*6) uart_rx = tx_ch[5]; 
         if (loop_count == base_time+offset*7) uart_rx = tx_ch[6];
         if (loop_count == base_time+offset*8) uart_rx = tx_ch[7]; 
         if (loop_count == base_time+offset*9) uart_rx = 1; 
	*/

end


function reg_log ();

    $fwrite(tracelog_filepointer, "x0  %h \t ra  %h \t sp  %h \t gp  %h\n",  
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[0],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[1],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[2],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[3]);
     $fwrite(tracelog_filepointer, "tp  %h \t t0  %h \t t1  %h \t t2  %h\n", 
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[4],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[5],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[6],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[7]);
     $fwrite(tracelog_filepointer, "s0  %h \t s1  %h \t a0  %h \t a1  %h\n", 
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[8],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[9],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[10],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[11]);
     $fwrite(tracelog_filepointer, "a2  %h \t a3  %h \t a4  %h \t a5  %h\n", 
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[12],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[13],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[14],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[15]);
     $fwrite(tracelog_filepointer, "a6  %h \t a7  %h \t s2  %h \t s3  %h\n", 
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[16],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[17],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[18],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[19]);
     $fwrite(tracelog_filepointer, "s4  %h \t s5  %h \t s6  %h \t s7  %h\n", 
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[20],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[21],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[22],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[23]);
     $fwrite(tracelog_filepointer, "s8  %h \t s9  %h \t s10 %h \t s11 %h\n", 
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[24],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[25],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[26],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[27]);
     $fwrite(tracelog_filepointer, "t3  %h \t t4  %h \t t5  %h \t t6  %h\n \n \n",            
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[28],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[29],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[30],
                                                             dut.pipeline_top_module.decode_module.rf_module.register_file[31]);
endfunction

`endif

endmodule

`timescale 1 ns / 100 ps

`include "../defines/UETRV_PCore_defs.svh"


module core_tb();
parameter timeout = 18000;
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
    $dumpvars(0, core_tb);

    write_data = $fopen("pcore.log");

    for (loop_count = 0; loop_count < timeout; loop_count = loop_count + 1)
    begin
         repeat (1) @ (posedge clk);

         if (loop_count == 62) irq_ext = 1;
         else irq_ext = 0;

         if (loop_count == 260) uart_rx = 0;

         if (loop_count == 276) uart_rx = 1;
         if (loop_count == 292) uart_rx = 1; 
         if (loop_count == 308) uart_rx = 0;
         if (loop_count == 324) uart_rx = 0; 

         if (loop_count == 340) uart_rx = 1;
         if (loop_count == 356) uart_rx = 0; 
         if (loop_count == 372) uart_rx = 1;
         if (loop_count == 388) uart_rx = 0; 
         if (loop_count == 404) uart_rx = 1; 

         $fdisplay(write_data, "%d \t %h \t %h", loop_count, dut.pipeline_top_module.if2id_data.pc, dut.imem2if.r_data);
    end
    $display("End of simulation");
    $fclose(write_data);
    $finish; 
 end

 // Signature Dump for Compliance Testing
`ifdef COMPLIANCE_TEST
    wire sig_en  = (dut.dbus2peri.addr == 32'h88000000) & dut.dbus2peri.w_en & dut.dmem_sel;
    wire halt_en = (dut.dbus2peri.addr == 32'h8C000000) & dut.dbus2peri.w_en & dut.dmem_sel;

    reg [1023:0] signature_file;
    reg [1023:0] firmware;

    integer write_sig=0;

    initial begin
         if($value$plusargs("memfile=%s",firmware)) begin
            $display("Loading Instruction Memory from %0s", firmware);
            `ifdef DUALPORT_MEMORY
               $readmemh(firmware, dut.dualport_mem_module.dualport_memory);
            `else
               $readmemh(firmware, dut.imem_module.inst_memory);
            `endif
         end
        
         if($value$plusargs("signature=%s",signature_file)) begin
            $display("Writing signature to %0s", signature_file);
            write_sig=$fopen(signature_file,"w");
         end
    end

    always_ff @ (posedge clk) begin 
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
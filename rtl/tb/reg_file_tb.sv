`timescale 1 ns / 100 ps

`include "../defines/UETRV_PCore_defs.svh"


module reg_file_tb();
reg clk, reset;
reg [31:0] loop_count;
wire [7:0] count;

    logic [`RF_AWIDTH-1:0]       idu2rf_rs1_addr_i;        // rs1 read address
    logic [`XLEN-1:0]            rf2idu_rs1_data_o;        // rs1 read data
    logic [`RF_AWIDTH-1:0]       idu2rf_rs2_addr_i;        // rs2 read address
    logic [`XLEN-1:0]            rf2idu_rs2_data_o;        // rs2 read data
    logic                        idu2rf_wr_req_i;          // write request
    logic [`RF_AWIDTH-1:0]       idu2rf_rd_addr_i;         // rd write address
    logic [`XLEN-1:0]            idu2rf_rd_data_i;          // rd write data


reg_file dut (
.clk                     (clk),
.rst_n                   (reset),
.id2rf_rs1_addr_i       (idu2rf_rs1_addr_i),
.id2rf_rs2_addr_i       (idu2rf_rs2_addr_i),
.rf2id_rs1_data_o       (rf2idu_rs1_data_o),
.rf2id_rs2_data_o       (rf2idu_rs2_data_o),
.id2rf_wr_req_i         (idu2rf_wr_req_i),
.id2rf_rd_addr_i        (idu2rf_rd_addr_i),
.id2rf_rd_data_i        (idu2rf_rd_data_i)
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
    $dumpfile("reg_file_tb.vcd");
    $dumpvars(0, reg_file_tb);

    for (loop_count = 0; loop_count < 100; loop_count = loop_count + 1)
          begin

	idu2rf_wr_req_i = 1;
	idu2rf_rd_addr_i = 3;
	idu2rf_rd_data_i = 40;
	idu2rf_rs1_addr_i = 3;
	
          repeat (1) @ (posedge clk);
          
	idu2rf_wr_req_i = 1;
	idu2rf_rd_addr_i = 4;
	idu2rf_rd_data_i = 35;	
        idu2rf_rs2_addr_i = 4;
	   repeat (1) @ (posedge clk);
          
          end
    $display("End of simulation");
    $finish; 
 end


endmodule
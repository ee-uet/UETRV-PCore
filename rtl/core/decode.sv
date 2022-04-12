`include "../defines/UETRV_PCore.svh"

module decode (

    input   logic                        rst_n,                    // reset
    input   logic                        clk,                      // clock

    // IDU <---> RF interface
    input   logic [`XLEN-1:0]            ifu2idu_pc_i,             // pc from fetch stage
    input   logic [`XLEN-1:0]            ifu2idu_inst_i,           // instruction from fetch stage
    output  logic [`XLEN-1:0]            idu2exe_rs1_data_o,       // rs1 to execute stage
    output  logic [`XLEN-1:0]            idu2exe_rs2_data_o,        // rs2 to execute stage

    input   logic                        wb2idu_wr_req_i,          // write request
    input   logic [`RF_AWIDTH-1:0]       wb2idu_rd_addr_i,         // rd write address
    input   logic [`XLEN-1:0]            wb2idu_rd_data_i          // rd write data

);


// register file instantiation
logic         [`XLEN-1:0]             reg_file[`RF_SIZE];

// control signals for validity of regiter file read/write operations
assign  rs1_addr_valid  =   |idu2rf_rs1_addr_i;
assign  rs2_addr_valid  =   |idu2rf_rs2_addr_i;
assign  rf_wr_valid     =   |idu2rf_rd_addr_i & idu2rf_wr_req_i;

// asynchronous read operation for two register operands
assign  rf2idu_rs1_data_o = ( rs1_addr_valid ) ? reg_file[idu2rf_rs1_addr_i] : '0;
assign  rf2idu_rs2_data_o = ( rs2_addr_valid ) ? reg_file[idu2rf_rs2_addr_i] : '0;

// write operation
always_ff @( posedge clk) begin
    if ( rst_n ) begin
        reg_file <= '{default: '0};
    end else if ( rf_wr_valid ) begin
        reg_file[idu2rf_rd_addr_i] <= idu2rf_rd_data_i;
    end
end


endmodule: reg_file


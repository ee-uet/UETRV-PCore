`ifndef VERILATOR
`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"
`include "../defines/MMU_defs.svh"
`include "../defines/cache_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "MMU_defs.svh"
`include "cache_defs.svh"
`endif

module dualport_mem (

    input   logic                                   rst_n,                     // reset
    input   logic                                   clk,                       // clock

 // Instruction cache memory interface
    input wire type_icache2imem_s                   icache2imem_i,             // Bus interface from IF to icache 
    output type_imem2icache_s                       imem2icache_o,             // From icache to IF

  // Data cache <---> Data memory interface
    input wire type_dcache2dmem_s                   dcache2dmem_i,
    output type_dmem2dcache_s                       dmem2dcache_o,

 // Selection signal from address decoder of dbus interconnect 
    input   logic                                   dmem_sel_i,
    input   logic                                   imem_sel_i
);


// Dual port memory instantiation and initialization
logic [`XLEN-1:0]          dualport_memory[`IDMEM_SIZE];

initial
begin
     // Reading the contents of imem.txt file to memory variable
     $readmemh("imem.txt", dualport_memory); 
end

//================================= Ibus interface ==================================//
// Local signals
type_icache2imem_s                    icache2imem;               
type_imem2icache_s                    imem2icache_ff;

logic [`MEM_ADDR_WIDTH-1:0]           imem_addr, imem_addr_ff;
logic                                 imem_rd_req, imem_rd_req_ff;

// Local signal assignments
assign icache2imem = icache2imem_i;
assign imem_rd_req = icache2imem.req & imem_sel_i;
assign imem_addr   = {2'b0, icache2imem.addr[`MEM_ADDR_WIDTH-1:2]};  // Memory is word addressable

// The memory address is captured on the negative edge of the clock, 
// while the read data is made available synchronously on the next 
// positive edge
always_ff @(negedge clk) begin
   if (~rst_n) begin
       imem_rd_req_ff <= '0;
       imem_addr_ff   <= '0;
    end 
    else begin
       imem_rd_req_ff <= imem_rd_req;
       imem_addr_ff   <= imem_addr;              
    end
end


// Synchronous memory read operation
always_ff @ (posedge clk) begin 
    if (imem_rd_req_ff) begin                         
        imem2icache_ff.ack          <= 1'b1;

        imem2icache_ff.r_data[31:0]   <= dualport_memory[{imem_addr_ff[`MEM_ADDR_WIDTH-1:2],2'b00}];   
        imem2icache_ff.r_data[63:32]  <= dualport_memory[{imem_addr_ff[`MEM_ADDR_WIDTH-1:2],2'b01}];   
        imem2icache_ff.r_data[95:64]  <= dualport_memory[{imem_addr_ff[`MEM_ADDR_WIDTH-1:2],2'b10}];   
        imem2icache_ff.r_data[127:96] <= dualport_memory[{imem_addr_ff[`MEM_ADDR_WIDTH-1:2],2'b11}];     
    end else begin
        imem2icache_ff.ack    <= 1'b0;
    end 
end


assign imem2icache_o = imem2icache_ff;   


//================================= Dbus interface ==================================//

// Local signals
type_dmem2dcache_s                    dmem2dcache;
type_dcache2dmem_s                    dcache2dmem;

logic [`MEM_ADDR_WIDTH-1:0]           dmem_addr;
//logic [3:0]                           dmem_selbyte_ff;
logic                                 dmem_wen;
logic                                 dmem_sel;

// Connect the local signals to appropriate IOs of the module
assign dcache2dmem = dcache2dmem_i; 
assign dmem_addr = {2'b0, dcache2dmem.addr[`MEM_ADDR_WIDTH-1:2]};
assign dmem_sel = (dcache2dmem.req & dmem_sel_i);
assign dmem_wen = dcache2dmem.w_en;


// Synchronous load and store operations for data memory
always_ff @(posedge clk) begin  

    if (dmem_sel & ~dmem2dcache.ack) begin
        
        if (dmem_wen) begin
            dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b00}] <= dcache2dmem.w_data[31:0];
            dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b01}] <= dcache2dmem.w_data[63:32];
            dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b10}] <= dcache2dmem.w_data[95:64];
            dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b11}] <= dcache2dmem.w_data[127:96];
        end else begin
          //  dmem2dbus_ff.r_data <= dualport_memory[dmem_addr_ff];
            dmem2dcache.r_data[31:0]   <= dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b00}];   
            dmem2dcache.r_data[63:32]  <= dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b01}];   
            dmem2dcache.r_data[95:64]  <= dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b10}];   
            dmem2dcache.r_data[127:96] <= dualport_memory[{dmem_addr[`MEM_ADDR_WIDTH-1:2],2'b11}]; 
            
        end

        dmem2dcache.ack <= 1'b1;
    end else begin
        dmem2dcache <= '0;
    end
end

                     
//assign dmem2dbus_o.r_data = dmem2dbus_ff.r_data;
//assign dmem2dbus_o.ack =  dmem2dbus_ff.ack;

assign dmem2dcache_o = dmem2dcache;

endmodule : dualport_mem



/*********************************************************************
 * Filename :    clint.sv
 * Date     :    04-09-2022
 * Author   :    Muhammad Tahir
 * 
 *
 * Description:  Core level interruptor (CLINT) module with memory mapped timer.
 *********************************************************************/

`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"


 module clint ( 
     input logic                                    rst_n,                    // reset
     input logic                                    clk,                      // clock
 //    input logic                                    clk_rtc,                  // RTC clock if avialable

     // Dbus to CLINT module interface
     input wire type_dbus2peri_s                    dbus2clint_i,             // GPIO dbus input signals
     output type_peri2dbus_s                        clint2dbus_o,             // GPIO dbus output signals

     // Selection signal from address decoder of dbus interconnect 
     input logic                                    clint_sel_i,
	
     // Interrupt signal from memory mapped timer that will be wired MTIP bit of MIP
     output logic				    clint_timer_irq_o
);


// Signal definitions for dbus interface
// Read and write signals for registers
logic [`XLEN-1:0]                       r_data; 
logic [`XLEN-1:0]                       w_data;
logic [3:0]                             addr_offset;
logic                                   r_req;
logic                                   w_req;
	
logic [63:0]                            mtime_ff, mtime_next;
logic [63:0]                            mtimecmp_ff, mtimecmp_next;                              
   
// Register address decoding signals
logic                                   mtime_lo_wr_flag;
logic                                   mtime_hi_wr_flag;
logic                                   mtimecmp_lo_wr_flag;
logic                                   mtimecmp_hi_wr_flag;
	
// Local sinals for internal use
logic                                   timer_overflow_ff, timer_overflow_next;
	
//============================ Memory mapped timer register read operations =============================//
always_comb begin
    r_data  = '0; 

    if(r_req) begin
        case (addr_offset)
            // machine timer registers
            MTIME_LOW_R     : r_data = mtime_ff[31:0];
            MTIME_HIGH_R    : r_data = mtime_ff[63:32];
            
            // machine timer compare registers
            MTIMECMP_LOW_R  : r_data = mtimecmp_ff[31:0];
            MTIMECMP_HIGH_R : r_data = mtimecmp_ff[63:32];
            default         : r_data = '0;
        endcase // reg_addr
    end
end

//================================= Memory mapped timer register write operations ==================================//
always_comb begin

    mtime_lo_wr_flag    = 1'b0;
    mtime_hi_wr_flag    = 1'b0;
    mtimecmp_lo_wr_flag = 1'b0;
    mtimecmp_hi_wr_flag = 1'b0;
  
    // Register write flag evaluation
    if(w_req) begin
        case (addr_offset)
            // mtime low 32-bits write flag
            MTIME_LOW_R     : mtime_lo_wr_flag = 1'b1;
            
            // mtime high 32-bits write flag
            MTIME_HIGH_R    : mtime_hi_wr_flag = 1'b1;

             // mtimecmp low 32-bits write flag
            MTIMECMP_LOW_R  : mtimecmp_lo_wr_flag = 1'b1;
            
            // mtimecmp high 32-bits write flag
            MTIMECMP_HIGH_R : mtimecmp_hi_wr_flag = 1'b1;
            default         : begin    end
        endcase // reg_addr
    end
end

// Update mtime register 
// ----------------------------
always_comb begin

    if (mtime_lo_wr_flag) begin
        mtime_next[31:0] = w_data;
    end else if (mtime_hi_wr_flag) begin
        mtime_next[63:32] = w_data;
    end else begin
        mtime_next = mtime_ff + 1'b1;
    end
end

always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
        mtime_ff <= '0;
    end else begin       
        mtime_ff <= mtime_next;
    end
end

// Update mtimecmp register 
// ----------------------------
always_comb begin

    if (mtimecmp_lo_wr_flag) begin
        mtimecmp_next[31:0] = w_data;
    end else if (mtimecmp_hi_wr_flag) begin
        mtimecmp_next[63:32] = w_data;
    end else begin
        mtimecmp_next = mtimecmp_ff;
    end
end

always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
        mtimecmp_ff <= '0;
    end else begin       
        mtimecmp_ff <= mtimecmp_next;
    end
end

//=================================== Timer IRQ =====================================//
// Timer interrupt generation
assign timer_overflow_next = (mtime_ff >= mtimecmp_ff);

always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
        timer_overflow_ff <= '0;
    end else begin       
        timer_overflow_ff <= timer_overflow_next;
    end
end
	
//================================= Dbus interface ==================================//
type_peri2dbus_s                      clint2dbus_ff;

// Signal interface to Wishbone bus
assign addr_offset = type_mtime_regs_e'(dbus2clint_i.addr[5:2]);
assign w_data      = dbus2clint_i.w_data;
assign r_req       = !dbus2clint_i.w_en && dbus2clint_i.cyc && clint_sel_i;
assign w_req       = dbus2clint_i.w_en  && dbus2clint_i.cyc && clint_sel_i;

// Synchronous read operation 
always_ff @(posedge clk) begin  
    clint2dbus_ff <= '0;
    if (r_req &  ~clint2dbus_ff.ack) begin
            clint2dbus_ff.ack <= 1'b1;
            clint2dbus_ff.r_data <= r_data;  
        
    end  
end  


// Update output signals 
assign clint_timer_irq_o = timer_overflow_ff;

// Response signals to dbus 
assign clint2dbus_o = clint2dbus_ff;

        
endmodule	
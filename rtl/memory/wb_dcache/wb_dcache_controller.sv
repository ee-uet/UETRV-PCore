`ifndef VERILATOR
`include "../../defines/UETRV_PCore_defs.svh"
`include "../../defines/UETRV_PCore_ISA.svh"
`include "../../defines/MMU_defs.svh"
`include "../../defines/cache_defs.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "cache_defs.svh"
`include "MMU_defs.svh"
`endif


module wb_dcache_controller (
    input wire                            clk_i, 
    input wire                            rst_ni,

    // Interface signals to/from cache datapath
    input wire                            cache_hit_i,
    input wire                            cache_dirty_bit_i,
    output logic                          cache_wr_o,
    output logic                          cache_line_wr_o,
    output logic                          cache_writeback_req_o,
 
    // LSU/MMU to data cache interface
    input wire                            lsummu2dcache_req_i,
    input wire                            lsummu2dcache_wr_i,
    output logic                          dcache2lsummu_ack_o,

    // Data memory to data cache interface
    input  wire                           mem2dcache_ack_i,
    output logic                          dcache2mem_req_o,
    output logic                          dcache2mem_wr_o,
    input wire                            dmem_sel_i
);
         

type_dcache_states_e                  dcache_state_ff, dcache_state_next;

logic                                 lsummu2dcache_wr;
logic                                 dcache2lsummu_ack;
logic                                 dcache_hit;
logic                                 dcache_miss;
logic                                 dcache_dirty;

assign lsummu2dcache_wr = lsummu2dcache_wr_i;

assign dcache_hit   = lsummu2dcache_req_i & dmem_sel_i & cache_hit_i;
assign dcache_miss  = lsummu2dcache_req_i & dmem_sel_i & ~cache_hit_i ;
assign dcache_dirty = cache_dirty_bit_i;

// Cache controller state machine
always_ff @(posedge clk_i) begin
  if (!rst_ni) begin
      dcache_state_ff <= DCACHE_IDLE;
  end else begin
      dcache_state_ff <= dcache_state_next;
  end
end

 
always_comb begin
    dcache_state_next = dcache_state_ff;
    dcache2lsummu_ack = 1'b0;
    dcache2mem_req_o = 1'b0;
    dcache2mem_wr_o  = 1'b0;
    cache_writeback_req_o = 1'b0;
    cache_line_wr_o   = 1'b0;
    cache_wr_o        = 1'b0;
    
    unique case (dcache_state_ff)
        DCACHE_IDLE: begin
            // In case of hit, perform the cache read/write operation    
            if (dcache_hit) begin  
                if (lsummu2dcache_wr) begin
                    dcache_state_next = DCACHE_WRITE;
                    cache_wr_o        = 1'b1;
                end else begin 
                    dcache_state_next = DCACHE_READ;
                end
            end else if (dcache_miss) begin           
               if (dcache_dirty) begin
                    dcache_state_next = DCACHE_WRITE_BACK;
                    dcache2mem_req_o  = 1'b1;
                    dcache2mem_wr_o   = 1'b1;
                    cache_writeback_req_o = 1'b1;
                end else begin 
                    dcache_state_next = DCACHE_ALLOCATE;
                end
            end else begin
                dcache_state_next = DCACHE_IDLE;
            end
        end
        DCACHE_READ: begin  
            // Send ack from cache, data will be returned by cache datapath          
            dcache_state_next = DCACHE_IDLE;
            dcache2lsummu_ack = 1'b1;
        end
        DCACHE_WRITE: begin  
            // Ack from cache, data is written simultaneously          
            dcache_state_next = DCACHE_IDLE;
            dcache2lsummu_ack = 1'b1;      
        end
        DCACHE_ALLOCATE: begin  
            // Response from main memory is received          
            if (mem2dcache_ack_i) begin
                dcache_state_next = DCACHE_IDLE;
                cache_line_wr_o   = 1'b1;
            end else begin
               dcache_state_next = DCACHE_ALLOCATE;
               dcache2mem_req_o = 1'b1;
            end
        end
        DCACHE_WRITE_BACK: begin  
            // Response from main memory is received          
            if (mem2dcache_ack_i) begin
                dcache_state_next = DCACHE_ALLOCATE;
            end else begin
                dcache_state_next = DCACHE_WRITE_BACK;
                dcache2mem_req_o = 1'b1;
                dcache2mem_wr_o = 1'b1;
                cache_writeback_req_o = 1'b1;
            end
        end 
   endcase

    // Kill any ongoing request if the data memory is not addressed 
    if (~dmem_sel_i) begin
        dcache_state_next = DCACHE_IDLE;
        cache_wr_o        = 1'b0;
        dcache2mem_req_o = 1'b0;
    end

end

assign dcache2lsummu_ack_o = dcache2lsummu_ack;
  
endmodule

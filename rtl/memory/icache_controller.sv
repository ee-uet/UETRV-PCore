`ifndef VERILATOR
`include "../defines/UETRV_PCore_defs.svh"
`include "../defines/UETRV_PCore_ISA.svh"
`include "../defines/MMU_defs.svh"
`include "../defines/cache_pkg.svh"
`else
`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"
`include "cache_pkg.svh"
`include "MMU_defs.svh"
`endif


module icache_controller (
  input  wire logic clk_i , 
  input  wire logic rst_ni,
  input  wire logic cache_hit_i,
  output logic       cache_rw_o,
  input  wire logic  imem_sel_i,

  // Instruction fetch to Instruction Cache Interface
  input  wire logic if2icache_request_i,
  output logic      icache2if_ack_o,

  // Instruction Memory to Instruction Cache Interface
  input  wire logic imem2icache_ack_i,
  output logic     icache2imem_request_o
  );

  typedef enum {
    StIdle, StRead, StReadMiss, StReadMemory, StAllocate
  } states_e;

  states_e state_d, state_q;
  logic icache2if_ack_ff;

  always_ff@(posedge clk_i) begin
    if(!rst_ni) begin
        icache2if_ack_o <= '0;
    end else begin
        icache2if_ack_o <= icache2if_ack_ff;
    end
  end

  always_comb begin
    state_q = state_d;
    cache_rw_o = '0;
    unique case (state_d)

        StIdle: begin
            if (if2icache_request_i) begin
                    state_q = StRead;
                    icache2if_ack_ff = 1'b0;
            end else begin
                state_q = StIdle;
            end
        end

        StRead: begin
            if (cache_hit_i) begin
                state_q = StIdle;
                icache2if_ack_ff = 1;
            end else begin
                icache2if_ack_ff = 1'b0;
                state_q = StReadMiss;
            end
        end

        StReadMiss: begin
            icache2if_ack_ff = 1'b0;
            icache2imem_request_o = 1'b1;
            state_q = StReadMemory;
        end

        StReadMemory: begin
            icache2if_ack_ff = 1'b0;
            if (imem2icache_ack_i) begin
                state_q = StAllocate;
                cache_rw_o = 1'b1;
            end else begin
                state_q = StReadMemory;
            end
        end

        StAllocate: begin
            if (cache_hit_i) begin
                state_q = StIdle;
                icache2if_ack_ff = 1;
            end else begin
                state_q = StAllocate;
            end
        end

    endcase
  end

   always_ff @(posedge clk_i or negedge rst_ni ) begin
    if (!rst_ni || ~imem_sel_i) begin
        state_d <= StIdle;
    end else begin
        state_d <= state_q;
    end
   end
   
endmodule

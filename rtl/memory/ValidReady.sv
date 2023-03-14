module val_ready_p (
  input  wire logic clk_i,
  input  wire logic rst_ni, 
  input  wire logic valid_i,
  input  wire logic ready_i,
  output logic start_o
  );

  typedef enum { StIdle, StWait_for_ready, StWait_for_valid, StTransfer } states_e;
  states_e state_d, state_q;

  always_ff @( posedge clk_i or negedge rst_ni ) begin
    if (!rst_ni) begin
        state_d <= StIdle;
    end else begin
        state_d <= state_q;   
    end
  end

  always_comb begin
    start_o = '0;
    case (state_d)
        StIdle: begin
            if (valid_i) begin
                state_q = StWait_for_ready;
            end else if (ready_i) begin
                state_q = StWait_for_valid;
            end else if (valid_i && ready_i) begin
                state_q = StTransfer;
            end else begin
                state_q = StIdle;
            end
        end

        StWait_for_ready: begin 
            if (ready_i) begin
                state_q = StTransfer;
            end else begin
                state_q = StWait_for_ready;
            end
        end

        StWait_for_valid: begin
            if (valid_i) begin
                state_q = StTransfer;
            end else begin
                state_q = StWait_for_valid;
            end
        end

        StTransfer: begin
            start_o = 1'b1;
            if (!ready_i & !valid_i) begin
                state_q = StIdle;
            end else if (!ready_i) begin
                state_q = StWait_for_ready;
            end else if (!valid_i) begin
                state_q = StWait_for_valid;
            end
        end 
    endcase
    
  end

endmodule
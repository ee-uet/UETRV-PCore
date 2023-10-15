module c_misalign (
    input   logic           clk, 
    input   logic           reset, 

    input   logic           sel_for_branch,
    input   logic   [31:0]  pc_in, 
    input   logic   [31:0]  inst_in,

    output  logic           stall_pc,
    output  logic           pc_misaligned_o,
    output  logic   [31:0]  pc_out, 
    output  logic   [31:0]  inst_out
);

    logic [15:0] upper_16;
    logic [31:0] conc_32_misallign;
    logic is_missaligned, next_misaligned;

    typedef enum logic[1:0] {s0 = 2'b00, s1= 2'b01, s2=2'b10} states;
    states current_state, next_state;

    always_comb begin // missallignment check
        if((inst_in[17:16] == 2'b11) )begin
             is_missaligned =1'b1;
        end
        else is_missaligned =1'b0;
    end

    always_ff @( posedge clk  ) begin   // to continue the misallignement into the next cycle
        if (reset) next_misaligned<=1'b0;
        else next_misaligned<=is_missaligned;
        
    end

    always_ff @( posedge clk ) begin // a register that hold the upper 16 bits of the previous instruction that will be concatinated with the current instruction and sent forwards
        if (reset) upper_16 <=16'b0;
        else begin
        if (current_state != s1) begin 
            if (is_missaligned & (current_state == s0)) upper_16<= inst_in[31:16];
            else if ((next_misaligned)& (current_state == s2))upper_16<=conc_32_misallign[31:16];
        end
        else upper_16 <=upper_16;
    end
    end

    always_ff @( negedge clk ) begin // the register that holds the entire missalligned instruction
        if (reset) conc_32_misallign<=32'b0;
        else begin 
            if (current_state == s1) conc_32_misallign<=inst_in;
            else if (current_state == s0) conc_32_misallign<=32'b0;

        end
    end


    always_ff @( posedge clk ) begin //the fsm's flipflop
        if (reset) current_state<=s0;
        else current_state<=next_state;
    end


    always_comb begin  // the fsm's combinations states and outputs of the module
        stall_pc = 1'b0;
        pc_out=pc_in;
        inst_out=inst_in;
        pc_misaligned_o =1'b0;

        case(current_state)
        s0 : begin // checking for missalligned instruction
                pc_out=pc_in;
                inst_out=inst_in;
                stall_pc=1'b0;
                pc_misaligned_o =1'b0;
                
                if (is_missaligned) next_state = s1;
                else begin 
                    next_state =s0;
                end
        end
        s1 : begin //missalligned confirmed now fetch the next instruction, while feeding a nop thorugh the pipeline
            pc_out = pc_in+32'd2;
            inst_out =32'h0000_0013;
            stall_pc =1'b1;
            pc_misaligned_o =1'b1;
            if (sel_for_branch) next_state = s0;  // if a brach or jump occurs, priotize the jump. thus resetting the realligner
            else  next_state =s2;            

        end
        s2 : begin  // instruction fetched and concatinated, turn off the stall signal and keep the pc as it is
            inst_out = {{conc_32_misallign[15:0]},{upper_16}};
            pc_out = pc_in; 
            pc_misaligned_o =1'b1;
            stall_pc = 1'b0;
            if (sel_for_branch) next_state=s0;
            else begin
                if (next_misaligned ) next_state =s1;        // if the missalignment is in the s1 stage, go to s1 instead of s0 after s2
                else next_state =s0;
            end

        end

        default next_state =s0;
        endcase
    end
endmodule

module store_buffer_top #(
    parameter BLEN = 4,                // Buffer Length
    parameter ADDR_WIDTH = 32,         // Address width
    parameter DATA_WIDTH = 32,         // Data width
    parameter BYTE_SEL_WIDTH = 4       // Byte selection width
)(
    input  logic                        clk,                        // Clock
    input  logic                        rst_n,                      // Reset, active low

    // LSU --> store_buffer_top
    input  logic [ADDR_WIDTH-1:0]       lsummu2stb_addr,            // Address input from LSU
    input  logic [DATA_WIDTH-1:0]       lsummu2stb_wdata,           // Data input from LSU
    input  logic [BYTE_SEL_WIDTH-1:0]   lsummu2stb_sel_byte,        // Byte selection from LSU
    input  logic                        lsummu2stb_w_en,            // Write enable from LSU
    input  logic                        lsummu2stb_req,             // Store request from LSU
    input  logic                        dmem_sel_i,                 // Data memory select from LSU

    // store_buffer_top --> LSU
    output logic                        stb2lsummu_stall,           // Stall signal (from LSU controller)
    output logic                        stb2lsummu_ack,             // Store Buffer acknowledges the write

    output logic [DATA_WIDTH-1:0]       stb2lsummu_rdata,           // Cache to LSU

    // store_buffer_top --> dcache
    output logic [ADDR_WIDTH-1:0]       stb2dcache_addr,            // Address to Cache
    output logic [DATA_WIDTH-1:0]       stb2dcache_wdata,           // Data to Cache
    output logic [BYTE_SEL_WIDTH-1:0]   stb2dcache_sel_byte,        // Byte select to Cache
    output logic                        stb2dcache_w_en,            // Write enable from Store Buffer
    output logic                        stb2dcache_req,             // Store request from Store Buffer
    output logic                        stb2dcache_empty,           // store buffer empty signal to dcache
    output logic                        dmem_sel_o,                 // Data memory select from Store Buffer

    // dCache --> store_buffer_top  
    input  logic [DATA_WIDTH-1:0]       dcache2stb_rdata,           
    input  logic                        dcache2stb_ack              // Cache acknowledges the write
);

    // Internal Signals
    logic stb_wr_en;    // Store Buffer Write Enable (from LSU controller)
    logic stb_rd_en;    // Store Buffer Read Enable (from Cache controller)
    logic stb_full;     // Store Buffer full signal
    logic stb_empty;    // Store Buffer empty signal
    logic rd_sel;       // selection for read mux
    logic stb_bypass;

    assign stb2lsummu_rdata = dcache2stb_rdata;                     // bypassing rdata signal
    assign stb_bypass = ((lsummu2stb_req & !lsummu2stb_w_en) | (!lsummu2stb_req & !lsummu2stb_w_en)) & dmem_sel_i & stb_empty;

    // Instantiate the Store Buffer Datapath
    store_buffer_datapath #(
        .BLEN(BLEN),
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .BYTE_SEL_WIDTH(BYTE_SEL_WIDTH)
    ) u_store_buffer (
        .clk                    (clk),
        .rst_n                  (rst_n),
        
        // LSU --> store_buffer_datapath
        .lsummu2stb_addr        (lsummu2stb_addr),
        .lsummu2stb_wdata       (lsummu2stb_wdata),
        .lsummu2stb_sel_byte    (lsummu2stb_sel_byte),

        // lsu_stb_controller --> store_buffer_datapath
        .stb_wr_en              (stb_wr_en),

        // stb_cache_controller --> store_buffer_datapath
        .stb_rd_en              (stb_rd_en),
        .rd_sel                 (rd_sel),

        // store_buffer_datapath --> dcache
        .stb2dcache_addr        (stb2dcache_addr),
        .stb2dcache_wdata       (stb2dcache_wdata),
        .stb2dcache_sel_byte    (stb2dcache_sel_byte),

        // store_buffer --> store_buffer_controllers
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        .stb_bypass             (stb_bypass)
    );

    // Instantiate the LSU to Store Buffer Controller
    lsu_stb_controller u_lsu_stb_controller (
        .clk                    (clk),
        .rst_n                  (rst_n),

        // LSU --> lsu_stb_controller
        .lsummu2stb_w_en        (lsummu2stb_w_en),
        .lsummu2stb_req         (lsummu2stb_req),
        .dmem_sel_i             (dmem_sel_i),

        // store_buffer_datapath --> lsu_stb_controller 
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        .stb_bypass             (stb_bypass),   

        // dcache --> stb_cache_controller
        .dcache2stb_ack         (dcache2stb_ack),     

        // lsu_stb_controller --> LSU
        .stb2lsummu_ack         (stb2lsummu_ack),

        // lsu_stb_controller --> store_buffer_datapath
        .stb_wr_en              (stb_wr_en),
    
        // lsu_stb_controller --> LSU
        .stb2lsummu_stall       (stb2lsummu_stall)
    );

    // Instantiate the Store Buffer to Cache Controller
    stb_cache_controller u_stb_cache_controller (
        .clk                    (clk),
        .rst_n                  (rst_n),

        // store_buffer_datapath --> stb_cache_controller
        .stb_full               (stb_full),
        .stb_empty              (stb_empty),

        .stb_bypass             (stb_bypass),

        // LSU --> lsu_stb_controller
        .lsummu2stb_w_en        (lsummu2stb_w_en),
        .lsummu2stb_req         (lsummu2stb_req),
        .dmem_sel_i             (dmem_sel_i),

        // dcache --> stb_cache_controller
        .dcache2stb_ack         (dcache2stb_ack),

        // stb_cache_controller --> store_buffer_datapath
        .stb_rd_en              (stb_rd_en),
        .rd_sel                 (rd_sel),

        // stb_cache_controller --> dcache
        .stb2dcache_req         (stb2dcache_req),
        .stb2dcache_w_en        (stb2dcache_w_en),
        .dmem_sel_o             (dmem_sel_o)
    );
    
assign stb2dcache_empty = stb_empty;

endmodule

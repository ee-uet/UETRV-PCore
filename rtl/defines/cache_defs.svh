`ifndef CACHE_DEFS
`define CACHE_DEFS

`include "UETRV_PCore_ISA.svh"

//=========================== Instruction Cache related definitions ===========================//
parameter ICACHE_ADDR_WIDTH  = `XLEN;
parameter ICACHE_DATA_WIDTH  = `XLEN;
parameter ICACHE_LINE_WIDTH  = 128;            // Line width is in bits
parameter ICACHE_NO_OF_SETS  = 512;

parameter ICACHE_OFFSET_BITS = $clog2(ICACHE_LINE_WIDTH/8);
parameter ICACHE_IDX_BITS    = $clog2(ICACHE_NO_OF_SETS); 
parameter ICACHE_TAG_BITS    = ICACHE_ADDR_WIDTH - ICACHE_IDX_BITS - ICACHE_OFFSET_BITS; 
parameter ICACHE_TAG_LSB     = ICACHE_ADDR_WIDTH - ICACHE_TAG_BITS; 

typedef enum {
    ICACHE_IDLE, 
    ICACHE_READ_MISS, 
    ICACHE_READ_MEMORY, 
    ICACHE_ALLOCATE 
} type_icache_states_e; 

// Bus interface from IF to icache  
typedef struct packed {                            
    logic [ICACHE_ADDR_WIDTH-1:0]    addr;
    logic                            req;
    logic                            req_kill;
    logic                            icache_flush; 
} type_if2icache_s;

// Bus interface from Icache to IF
typedef struct packed {                            
    logic [ICACHE_DATA_WIDTH-1:0]    r_data;
    logic                            ack;  
} type_icache2if_s;


typedef struct packed {
    logic [ICACHE_ADDR_WIDTH-1:0]    addr;
    logic                            req;
} type_icache2imem_s;

typedef struct packed {
    logic [ICACHE_LINE_WIDTH-1:0]    r_data;
    logic                            ack;
} type_imem2icache_s;

  
typedef struct packed {
    logic [ICACHE_TAG_BITS-1:0]      tag;
    logic                            valid;
    logic [ICACHE_LINE_WIDTH-1:0]    data_line;
} type_icache_line_s;


//=========================== Data Cache related definitions ===========================//
parameter DCACHE_ADDR_WIDTH  = `XLEN;
parameter DCACHE_DATA_WIDTH  = `XLEN;
parameter DCACHE_LINE_WIDTH  = 128;            // Line width is in bits
parameter DCACHE_NO_OF_SETS  = 256;

parameter DCACHE_OFFSET_BITS = $clog2(DCACHE_LINE_WIDTH/8);
parameter DCACHE_IDX_BITS    = $clog2(DCACHE_NO_OF_SETS); 
parameter DCACHE_TAG_BITS    = DCACHE_ADDR_WIDTH - DCACHE_IDX_BITS - DCACHE_OFFSET_BITS; 
parameter DCACHE_TAG_LSB     = DCACHE_ADDR_WIDTH - DCACHE_TAG_BITS; 

typedef enum {
    DCACHE_IDLE, 
    DCACHE_READ,
    DCACHE_WRITE,  
    DCACHE_ALLOCATE, 
    DCACHE_WRITE_BACK 
} type_dcache_states_e; 

// Bus interface from IF to icache  
typedef struct packed {                            
    logic [DCACHE_ADDR_WIDTH-1:0]    addr;
    logic [DCACHE_DATA_WIDTH-1:0]    w_data;
    logic [3:0]                      sel_byte;  
    logic                            w_en;  
    logic                            req; 
  //  logic                            cyc; 
 //   logic                            dcache_flush; 
} type_lsummu2dcache_s;

// Bus interface from Icache to IF
typedef struct packed {                            
    logic [DCACHE_DATA_WIDTH-1:0]    r_data;
    logic                            ack;   
} type_dcache2lsummu_s;


typedef struct packed {
    logic [DCACHE_ADDR_WIDTH-1:0]    addr;
    logic [DCACHE_LINE_WIDTH-1:0]    w_data;
    logic                            req;
    logic                            w_en;  
} type_dcache2dmem_s;

typedef struct packed {
    logic [DCACHE_LINE_WIDTH-1:0]    r_data;
    logic                            ack;
} type_dmem2dcache_s;

  
typedef struct packed {
 //   logic [DCACHE_LINE_WIDTH-1:0]    data;
    logic [DCACHE_TAG_BITS-1:0]      tag;
    logic                            valid;
    logic                            dirty;
} type_dcache_tag_s;

typedef bit [DCACHE_LINE_WIDTH-1:0] type_dcache_data_s;
// typedef type_dbus2peri_s type_lsu2dcache_s;

`endif

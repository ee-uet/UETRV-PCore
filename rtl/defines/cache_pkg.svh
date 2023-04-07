`ifndef cache_pkg
`define cache_pkg
// package cache_pkg;
  parameter AddrWidth = 32;
  parameter DataWidth = 32;
  parameter LineWidth = 128;
  parameter TagBits   = 18;
  parameter IndexBits = 10;
  parameter TagLSB    = 14;
  parameter BlkOffMSB = 3;
  parameter n_of_Sets = 1024;
  

// Bus interface from IF to icache  
typedef struct packed {                            
    logic [AddrWidth-1:0]            addr;
    logic                            req;
    logic                            icache_flush; 
} type_if2icache_s;

// Bus interface from Icache to IF
typedef struct packed {                            
    logic [DataWidth-1:0] r_data;
    logic                 ack;  
} type_icache2if_s;


  typedef struct packed {
    logic [AddrWidth-1:0] addr;
    logic                 req;
  } type_icache2imem_s;

  typedef struct packed {
    logic [LineWidth-1:0] data;
    logic                 ack;
  } type_imem2icache_s;


//  typedef logic [LineWidth-1:0] type_imem2icache_s;
//  typedef logic [IndexBits-1:0] cache_index_t;
  
  typedef struct packed {
    logic [TagBits-1:0]   tag;
    logic                 valid;
    logic [LineWidth-1:0] data_line;
  } cache_ram_t;

// endpackage
`endif
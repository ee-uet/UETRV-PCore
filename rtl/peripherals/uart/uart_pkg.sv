`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.07.2022 10:50:21
// Design Name: 
// Module Name: uart_pkg
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


package uart_pkg;
   
   typedef struct packed {
   logic [3:0] dataBits;
   logic [1:0] stopBits;  
   logic [3:0] divisorBits;
   logic [1:0] oversample;
   logic [3:0] nSamples  ;
   logic [3:0] nTxEntries ;
   logic [2:0] nRxEntries ;
   }uart_cfg; 
   
    localparam uart_cfg UART_Default_Config = '{
    dataBits     : 8,
    stopBits     : 2,
    divisorBits  : 10,
    oversample   : 2,
    nSamples     : 3,
    nTxEntries   : 4,
    nRxEntries   : 4
    };
    
    function automatic void check_cfg (uart_cfg cfg);
        logic [3:0] oversampleFactor = 1 << cfg.oversample;
        assert (cfg.divisorBits > cfg.oversample);
        assert (oversampleFactor > cfg.nSamples);
    endfunction      
endpackage

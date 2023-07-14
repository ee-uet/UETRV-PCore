// Copyright 2023 University of Engineering and Technology Lahore.                
// Licensed under the Apache License, Version 2.0, see LICENSE file for details.  
// SPDX-License-Identifier: Apache-2.0                                            
//                                                                                
// Description: The boot memory module. This is an auto generated file and should 
//              not be modified.                                                  
//                                                                                
// Author: Muhammad Tahir, UET Lahore                                             
// Date: 26.6.2023                                                                


`ifndef VERILATOR                                                              
`include "../defines/cache_defs.svh"                            
`else                                                                          
`include "cache_defs.svh"                                       
`endif        


module bmem (   
    input wire [`XLEN-1:0]                      if2bmem_addr_i,     // Address from IF  
    input wire                                  if2bmem_req_i,                 
    output logic [`XLEN-1:0]                    bmem2if_data_o      // Instruction from boot memory to IF   
);                                                                       
 
  
localparam BMEM_SIZE          = 2048;   // Memory size is in words 
localparam BMEM_ADDR_BUS_SIZE = $clog2(BMEM_SIZE); 

logic [`XLEN-1:0]                      if2bmem_addr;     
 
assign if2bmem_addr = if2bmem_addr_i - 4096;     

logic [`XLEN-1:0] bmem [BMEM_SIZE]; 

initial 
begin
    // Reading the contents of example imem.txt file to memory variable
     $readmemh("/work/tayyeb/uet_core/freedom-e-sdk/software/uetr/debug/uetr.txt", bmem);  
end                             

/*
const logic [`XLEN-1:0] bmem [BMEM_SIZE] = '{                                
    32'h08000513,
    32'h01200593,
    32'h01851513,
    32'h00b52023,
    32'h00052603,
    32'h09000513,
    32'h01851513,
    32'h04200593,
    32'h0d900613,
    32'h00c52c23,
    32'h00b52023,
    32'h00000013,
    32'h00000013,
    32'h00000013,
    32'h00000013,
    32'h00000013
};*/


assign bmem2if_data_o = if2bmem_req_i ? bmem[if2bmem_addr[BMEM_ADDR_BUS_SIZE:2]] : '0; 

endmodule : bmem 
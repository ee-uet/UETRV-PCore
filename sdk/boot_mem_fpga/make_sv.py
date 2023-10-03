
#  *********************************************************************/
#  * Filename :    make_sv.py
#  * Date     :    26-6-2023
#  *
#  * Description:  Prepare the bmem.sv from .txt file.
#  *********************************************************************/


# Place this script and bmem.txt file in the same directory. Otherwise, specify the path of bmem.txt file.

import sys
infile  = sys.argv[-1]
outfile = "./build/bmem.sv" # sys.argv[-1]

src_file = open(infile , "r")
des_file = open(outfile , "w")

index = 0
inst_data = src_file.readlines()
line_count = len(inst_data)

des_file.write("// Copyright 2023 University of Engineering and Technology Lahore.                \n")
des_file.write("// Licensed under the Apache License, Version 2.0, see LICENSE file for details.  \n")
des_file.write("// SPDX-License-Identifier: Apache-2.0                                            \n")
des_file.write("//                                                                                \n")
des_file.write("// Description: The boot memory module. This is an auto generated file and should \n")
des_file.write("//              not be modified.                                                  \n")
des_file.write("//                                                                                \n")
des_file.write("// Author: Muhammad Tahir, UET Lahore                                             \n")
des_file.write("// Date: 26.6.2023                                                                \n")
des_file.write("\n\n")

des_file.write("`ifndef VERILATOR                                                              \n")
des_file.write("`include"+ " \""+"../defines/cache_defs.svh"+"\""+"                            \n")
des_file.write("`else                                                                          \n")
des_file.write("`include"+ " \""+"cache_defs.svh"+"\""+"                                       \n")
des_file.write("`endif        \n")
des_file.write("\n\n")

des_file.write("module bmem (   \n")
des_file.write("    input wire [`XLEN-1:0]                      if2bmem_addr_i,     // Address from IF  \n")
des_file.write("    input wire                                  if2bmem_req_i,                 \n")
des_file.write("    output logic [`XLEN-1:0]                    bmem2if_data_o      // Instruction from boot memory to IF   \n")
des_file.write(");                                                                       \n \n  \n")

des_file.write("localparam BMEM_SIZE          = "+str(line_count)+";   // Memory size is in words \n\
localparam BMEM_ADDR_BUS_SIZE = $clog2(BMEM_SIZE); \n\n")

des_file.write("logic [BMEM_ADDR_BUS_SIZE-1:0]         if2bmem_addr;     \n \n\
assign if2bmem_addr = if2bmem_addr_i[BMEM_ADDR_BUS_SIZE+1:2];                                   \n \n\
const logic [`XLEN-1:0] bmem [BMEM_SIZE] = '{                                \n")

for src_line in inst_data:
    index+=1
    if index < line_count:
        des_file.write(" "*4+"32'h"+src_line[0:8]+","+ "\n")
    else:
        des_file.write(" "*4+"32'h"+src_line[0:8]+ "\n" +"};" + "\n\n") 
    

des_file.write("assign bmem2if_data_o = if2bmem_req_i ? bmem[if2bmem_addr] : '0; \n\n\
endmodule : bmem ")

des_file.close()
src_file.close()

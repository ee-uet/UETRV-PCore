//////////////////////////////////////////////////////////////////////////////////
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`ifndef M_EXT_DEFS
`define M_EXT_DEFS

`include "UETRV_PCore_defs.svh"
`include "UETRV_PCore_ISA.svh"

typedef struct packed {                            
    logic [`XLEN-1:0]                alu_operand_1;     
    logic [`XLEN-1:0]                alu_operand_2; 
} type_exe2mul_data_s;

typedef struct packed {                        
    type_alu_m_ops_e                 alu_m_ops;
} type_exe2mul_ctrl_s;

typedef struct packed {                            
    logic [`XLEN-1:0]                alu_m_result; 
} type_mul2wrb_data_s;

typedef struct packed {                        
    logic                            alu_m_res;
} type_mul2wrb_ctrl_s;

`endif // M_EXT_DEFS


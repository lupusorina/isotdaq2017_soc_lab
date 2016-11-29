vlib work
vlib activehdl

vlib activehdl/processing_system7_bfm_v2_0_5
vlib activehdl/xil_defaultlib

vmap processing_system7_bfm_v2_0_5 activehdl/processing_system7_bfm_v2_0_5
vmap xil_defaultlib activehdl/xil_defaultlib

vlog -work processing_system7_bfm_v2_0_5  -v2k5 "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" \
"../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl/processing_system7_bfm_v2_0_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" \
"../../../bd/PSDesign/ip/PSDesign_processing_system7_0_0/sim/PSDesign_processing_system7_0_0.v" \

vcom -work xil_defaultlib -93 \
"../../../bd/PSDesign/hdl/PSDesign.vhd" \


vlog -work xil_defaultlib "glbl.v"


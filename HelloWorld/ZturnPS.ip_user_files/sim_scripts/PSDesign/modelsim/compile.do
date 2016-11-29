vlib work
vlib msim

vlib msim/processing_system7_bfm_v2_0_5
vlib msim/xil_defaultlib

vmap processing_system7_bfm_v2_0_5 msim/processing_system7_bfm_v2_0_5
vmap xil_defaultlib msim/xil_defaultlib

vlog -work processing_system7_bfm_v2_0_5 -64 -incr "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" \
"../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl/processing_system7_bfm_v2_0_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" "+incdir+../../../../ZTurnPs.srcs/sources_1/bd/PSDesign/ipshared/2527/hdl" \
"../../../bd/PSDesign/ip/PSDesign_processing_system7_0_0/sim/PSDesign_processing_system7_0_0.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/PSDesign/hdl/PSDesign.vhd" \


vlog -work xil_defaultlib "glbl.v"

############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project NodeDetector
set_top nodeDetector
add_files NodeDetector/src/nodedetector.cpp
add_files -tb NodeDetector/src/nodedetectorTest.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 7.5 -name default
config_compile -no_signed_zeros=0 -unsafe_math_optimizations=0
config_schedule -effort medium -enable_dsp_full_reg=0 -relax_ii_for_timing=0 -verbose=0
config_export -format ip_catalog -rtl verilog -vivado_phys_opt place -vivado_report_level 0
config_bind -effort medium
config_sdx -optimization_level none -target none
set_clock_uncertainty 12.5%
source "./NodeDetector/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog

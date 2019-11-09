// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (win64) Build 2405991 Thu Dec  6 23:38:27 MST 2018
// Date        : Thu May 23 21:28:28 2019
// Host        : Muehle running 64-bit Service Pack 1  (build 7601)
// Command     : write_verilog -force -mode synth_stub
//               G:/Vivado_Projects/HDMI_Get_Started/HDMI_Get_Started.srcs/sources_1/bd/design_1/ip/design_1_nodeDetector_0_0/design_1_nodeDetector_0_0_stub.v
// Design      : design_1_nodeDetector_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "nodeDetector,Vivado 2018.3" *)
module design_1_nodeDetector_0_0(s_axi_CRTL_BUS_AWADDR, 
  s_axi_CRTL_BUS_AWVALID, s_axi_CRTL_BUS_AWREADY, s_axi_CRTL_BUS_WDATA, 
  s_axi_CRTL_BUS_WSTRB, s_axi_CRTL_BUS_WVALID, s_axi_CRTL_BUS_WREADY, 
  s_axi_CRTL_BUS_BRESP, s_axi_CRTL_BUS_BVALID, s_axi_CRTL_BUS_BREADY, 
  s_axi_CRTL_BUS_ARADDR, s_axi_CRTL_BUS_ARVALID, s_axi_CRTL_BUS_ARREADY, 
  s_axi_CRTL_BUS_RDATA, s_axi_CRTL_BUS_RRESP, s_axi_CRTL_BUS_RVALID, 
  s_axi_CRTL_BUS_RREADY, ap_clk, ap_rst_n, inStream_TVALID, inStream_TREADY, inStream_TDATA, 
  inStream_TDEST, inStream_TKEEP, inStream_TSTRB, inStream_TUSER, inStream_TLAST, 
  inStream_TID, outStream_TVALID, outStream_TREADY, outStream_TDATA, outStream_TDEST, 
  outStream_TKEEP, outStream_TSTRB, outStream_TUSER, outStream_TLAST, outStream_TID, out_0_V, 
  out_1_V, out_2_V, out_3_V, out_4_V, out_5_V, out_6_V, out2_0_V, out2_1_V, out2_2_V, out2_3_V, 
  out2_4_V, out2_5_V, out2_6_V)
/* synthesis syn_black_box black_box_pad_pin="s_axi_CRTL_BUS_AWADDR[6:0],s_axi_CRTL_BUS_AWVALID,s_axi_CRTL_BUS_AWREADY,s_axi_CRTL_BUS_WDATA[31:0],s_axi_CRTL_BUS_WSTRB[3:0],s_axi_CRTL_BUS_WVALID,s_axi_CRTL_BUS_WREADY,s_axi_CRTL_BUS_BRESP[1:0],s_axi_CRTL_BUS_BVALID,s_axi_CRTL_BUS_BREADY,s_axi_CRTL_BUS_ARADDR[6:0],s_axi_CRTL_BUS_ARVALID,s_axi_CRTL_BUS_ARREADY,s_axi_CRTL_BUS_RDATA[31:0],s_axi_CRTL_BUS_RRESP[1:0],s_axi_CRTL_BUS_RVALID,s_axi_CRTL_BUS_RREADY,ap_clk,ap_rst_n,inStream_TVALID,inStream_TREADY,inStream_TDATA[23:0],inStream_TDEST[5:0],inStream_TKEEP[2:0],inStream_TSTRB[2:0],inStream_TUSER[1:0],inStream_TLAST[0:0],inStream_TID[4:0],outStream_TVALID,outStream_TREADY,outStream_TDATA[23:0],outStream_TDEST[5:0],outStream_TKEEP[2:0],outStream_TSTRB[2:0],outStream_TUSER[1:0],outStream_TLAST[0:0],outStream_TID[4:0],out_0_V[0:0],out_1_V[0:0],out_2_V[0:0],out_3_V[0:0],out_4_V[0:0],out_5_V[0:0],out_6_V[0:0],out2_0_V[0:0],out2_1_V[0:0],out2_2_V[0:0],out2_3_V[0:0],out2_4_V[0:0],out2_5_V[0:0],out2_6_V[0:0]" */;
  input [6:0]s_axi_CRTL_BUS_AWADDR;
  input s_axi_CRTL_BUS_AWVALID;
  output s_axi_CRTL_BUS_AWREADY;
  input [31:0]s_axi_CRTL_BUS_WDATA;
  input [3:0]s_axi_CRTL_BUS_WSTRB;
  input s_axi_CRTL_BUS_WVALID;
  output s_axi_CRTL_BUS_WREADY;
  output [1:0]s_axi_CRTL_BUS_BRESP;
  output s_axi_CRTL_BUS_BVALID;
  input s_axi_CRTL_BUS_BREADY;
  input [6:0]s_axi_CRTL_BUS_ARADDR;
  input s_axi_CRTL_BUS_ARVALID;
  output s_axi_CRTL_BUS_ARREADY;
  output [31:0]s_axi_CRTL_BUS_RDATA;
  output [1:0]s_axi_CRTL_BUS_RRESP;
  output s_axi_CRTL_BUS_RVALID;
  input s_axi_CRTL_BUS_RREADY;
  input ap_clk;
  input ap_rst_n;
  input inStream_TVALID;
  output inStream_TREADY;
  input [23:0]inStream_TDATA;
  input [5:0]inStream_TDEST;
  input [2:0]inStream_TKEEP;
  input [2:0]inStream_TSTRB;
  input [1:0]inStream_TUSER;
  input [0:0]inStream_TLAST;
  input [4:0]inStream_TID;
  output outStream_TVALID;
  input outStream_TREADY;
  output [23:0]outStream_TDATA;
  output [5:0]outStream_TDEST;
  output [2:0]outStream_TKEEP;
  output [2:0]outStream_TSTRB;
  output [1:0]outStream_TUSER;
  output [0:0]outStream_TLAST;
  output [4:0]outStream_TID;
  output [0:0]out_0_V;
  output [0:0]out_1_V;
  output [0:0]out_2_V;
  output [0:0]out_3_V;
  output [0:0]out_4_V;
  output [0:0]out_5_V;
  output [0:0]out_6_V;
  output [0:0]out2_0_V;
  output [0:0]out2_1_V;
  output [0:0]out2_2_V;
  output [0:0]out2_3_V;
  output [0:0]out2_4_V;
  output [0:0]out2_5_V;
  output [0:0]out2_6_V;
endmodule

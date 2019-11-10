set moduleName nodeDetector
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_none
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {nodeDetector}
set C_modelType { void 0 }
set C_modelArgList {
	{ inStream_V_data_V int 24 regular {axi_s 0 volatile  { inStream Data } }  }
	{ inStream_V_keep_V int 3 regular {axi_s 0 volatile  { inStream Keep } }  }
	{ inStream_V_strb_V int 3 regular {axi_s 0 volatile  { inStream Strb } }  }
	{ inStream_V_user_V int 2 regular {axi_s 0 volatile  { inStream User } }  }
	{ inStream_V_last_V int 1 regular {axi_s 0 volatile  { inStream Last } }  }
	{ inStream_V_id_V int 5 regular {axi_s 0 volatile  { inStream ID } }  }
	{ inStream_V_dest_V int 6 regular {axi_s 0 volatile  { inStream Dest } }  }
	{ outStream_V_data_V int 24 regular {axi_s 1 volatile  { outStream Data } }  }
	{ outStream_V_keep_V int 3 regular {axi_s 1 volatile  { outStream Keep } }  }
	{ outStream_V_strb_V int 3 regular {axi_s 1 volatile  { outStream Strb } }  }
	{ outStream_V_user_V int 2 regular {axi_s 1 volatile  { outStream User } }  }
	{ outStream_V_last_V int 1 regular {axi_s 1 volatile  { outStream Last } }  }
	{ outStream_V_id_V int 5 regular {axi_s 1 volatile  { outStream ID } }  }
	{ outStream_V_dest_V int 6 regular {axi_s 1 volatile  { outStream Dest } }  }
	{ enable_V int 8 regular {axi_slave 0}  }
	{ pos_0_V int 16 regular {axi_slave 0}  }
	{ pos_1_V int 16 regular {axi_slave 0}  }
	{ pos_2_V int 16 regular {axi_slave 0}  }
	{ pos_3_V int 16 regular {axi_slave 0}  }
	{ pos_4_V int 16 regular {axi_slave 0}  }
	{ pos_5_V int 16 regular {axi_slave 0}  }
	{ pos_6_V int 16 regular {axi_slave 0}  }
	{ out_0_V int 1 regular {pointer 1}  }
	{ out_1_V int 1 regular {pointer 1}  }
	{ out_2_V int 1 regular {pointer 1}  }
	{ out_3_V int 1 regular {pointer 1}  }
	{ out_4_V int 1 regular {pointer 1}  }
	{ out_5_V int 1 regular {pointer 1}  }
	{ out_6_V int 1 regular {pointer 1}  }
	{ out2_0_V int 1 regular {pointer 1}  }
	{ out2_1_V int 1 regular {pointer 1}  }
	{ out2_2_V int 1 regular {pointer 1}  }
	{ out2_3_V int 1 regular {pointer 1}  }
	{ out2_4_V int 1 regular {pointer 1}  }
	{ out2_5_V int 1 regular {pointer 1}  }
	{ out2_6_V int 1 regular {pointer 1}  }
	{ horizontalPos_V int 16 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "inStream_V_data_V", "interface" : "axis", "bitwidth" : 24, "direction" : "READONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "inStream.V.data.V","cData": "uint24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "inStream_V_keep_V", "interface" : "axis", "bitwidth" : 3, "direction" : "READONLY", "bitSlice":[{"low":0,"up":2,"cElement": [{"cName": "inStream.V.keep.V","cData": "uint3","bit_use": { "low": 0,"up": 2},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "inStream_V_strb_V", "interface" : "axis", "bitwidth" : 3, "direction" : "READONLY", "bitSlice":[{"low":0,"up":2,"cElement": [{"cName": "inStream.V.strb.V","cData": "uint3","bit_use": { "low": 0,"up": 2},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "inStream_V_user_V", "interface" : "axis", "bitwidth" : 2, "direction" : "READONLY", "bitSlice":[{"low":0,"up":1,"cElement": [{"cName": "inStream.V.user.V","cData": "uint2","bit_use": { "low": 0,"up": 1},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "inStream_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "inStream.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "inStream_V_id_V", "interface" : "axis", "bitwidth" : 5, "direction" : "READONLY", "bitSlice":[{"low":0,"up":4,"cElement": [{"cName": "inStream.V.id.V","cData": "uint5","bit_use": { "low": 0,"up": 4},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "inStream_V_dest_V", "interface" : "axis", "bitwidth" : 6, "direction" : "READONLY", "bitSlice":[{"low":0,"up":5,"cElement": [{"cName": "inStream.V.dest.V","cData": "uint6","bit_use": { "low": 0,"up": 5},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_data_V", "interface" : "axis", "bitwidth" : 24, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":23,"cElement": [{"cName": "outStream.V.data.V","cData": "uint24","bit_use": { "low": 0,"up": 23},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_keep_V", "interface" : "axis", "bitwidth" : 3, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":2,"cElement": [{"cName": "outStream.V.keep.V","cData": "uint3","bit_use": { "low": 0,"up": 2},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_strb_V", "interface" : "axis", "bitwidth" : 3, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":2,"cElement": [{"cName": "outStream.V.strb.V","cData": "uint3","bit_use": { "low": 0,"up": 2},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_user_V", "interface" : "axis", "bitwidth" : 2, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":1,"cElement": [{"cName": "outStream.V.user.V","cData": "uint2","bit_use": { "low": 0,"up": 1},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "outStream.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_id_V", "interface" : "axis", "bitwidth" : 5, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":4,"cElement": [{"cName": "outStream.V.id.V","cData": "uint5","bit_use": { "low": 0,"up": 4},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "outStream_V_dest_V", "interface" : "axis", "bitwidth" : 6, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":5,"cElement": [{"cName": "outStream.V.dest.V","cData": "uint6","bit_use": { "low": 0,"up": 5},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "enable_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "enable.V","cData": "int8","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "pos_0_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "pos_1_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "pos_2_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}], "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "pos_3_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}], "offset" : {"in":48}, "offset_end" : {"in":55}} , 
 	{ "Name" : "pos_4_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}], "offset" : {"in":56}, "offset_end" : {"in":63}} , 
 	{ "Name" : "pos_5_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 5,"up" : 5,"step" : 2}]}]}], "offset" : {"in":64}, "offset_end" : {"in":71}} , 
 	{ "Name" : "pos_6_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "pos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 6,"up" : 6,"step" : 2}]}]}], "offset" : {"in":72}, "offset_end" : {"in":79}} , 
 	{ "Name" : "out_0_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "out_1_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "out_2_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "out_3_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "out_4_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "out_5_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "out_6_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_0_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_1_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_2_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_3_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_4_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_5_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "out2_6_V", "interface" : "wire", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "out2.V","cData": "int1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "horizontalPos_V", "interface" : "axi_slave", "bundle":"CRTL_BUS","type":"ap_none","bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "horizontalPos.V","cData": "int16","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":80}, "offset_end" : {"in":87}} ]}
# RTL Port declarations: 
set portNum 51
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ inStream_TDATA sc_in sc_lv 24 signal 0 } 
	{ inStream_TVALID sc_in sc_logic 1 invld 6 } 
	{ inStream_TREADY sc_out sc_logic 1 inacc 6 } 
	{ inStream_TKEEP sc_in sc_lv 3 signal 1 } 
	{ inStream_TSTRB sc_in sc_lv 3 signal 2 } 
	{ inStream_TUSER sc_in sc_lv 2 signal 3 } 
	{ inStream_TLAST sc_in sc_lv 1 signal 4 } 
	{ inStream_TID sc_in sc_lv 5 signal 5 } 
	{ inStream_TDEST sc_in sc_lv 6 signal 6 } 
	{ outStream_TDATA sc_out sc_lv 24 signal 7 } 
	{ outStream_TVALID sc_out sc_logic 1 outvld 13 } 
	{ outStream_TREADY sc_in sc_logic 1 outacc 7 } 
	{ outStream_TKEEP sc_out sc_lv 3 signal 8 } 
	{ outStream_TSTRB sc_out sc_lv 3 signal 9 } 
	{ outStream_TUSER sc_out sc_lv 2 signal 10 } 
	{ outStream_TLAST sc_out sc_lv 1 signal 11 } 
	{ outStream_TID sc_out sc_lv 5 signal 12 } 
	{ outStream_TDEST sc_out sc_lv 6 signal 13 } 
	{ out_0_V sc_out sc_lv 1 signal 22 } 
	{ out_1_V sc_out sc_lv 1 signal 23 } 
	{ out_2_V sc_out sc_lv 1 signal 24 } 
	{ out_3_V sc_out sc_lv 1 signal 25 } 
	{ out_4_V sc_out sc_lv 1 signal 26 } 
	{ out_5_V sc_out sc_lv 1 signal 27 } 
	{ out_6_V sc_out sc_lv 1 signal 28 } 
	{ out2_0_V sc_out sc_lv 1 signal 29 } 
	{ out2_1_V sc_out sc_lv 1 signal 30 } 
	{ out2_2_V sc_out sc_lv 1 signal 31 } 
	{ out2_3_V sc_out sc_lv 1 signal 32 } 
	{ out2_4_V sc_out sc_lv 1 signal 33 } 
	{ out2_5_V sc_out sc_lv 1 signal 34 } 
	{ out2_6_V sc_out sc_lv 1 signal 35 } 
	{ s_axi_CRTL_BUS_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_AWADDR sc_in sc_lv 7 signal -1 } 
	{ s_axi_CRTL_BUS_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_CRTL_BUS_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_CRTL_BUS_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_ARADDR sc_in sc_lv 7 signal -1 } 
	{ s_axi_CRTL_BUS_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_CRTL_BUS_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_CRTL_BUS_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_CRTL_BUS_BRESP sc_out sc_lv 2 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_CRTL_BUS_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "AWADDR" },"address":[{"name":"nodeDetector","role":"start","value":"0","valid_bit":"0"},{"name":"nodeDetector","role":"continue","value":"0","valid_bit":"4"},{"name":"nodeDetector","role":"auto_start","value":"0","valid_bit":"7"},{"name":"enable_V","role":"data","value":"16"},{"name":"pos_0_V","role":"data","value":"24"},{"name":"pos_1_V","role":"data","value":"32"},{"name":"pos_2_V","role":"data","value":"40"},{"name":"pos_3_V","role":"data","value":"48"},{"name":"pos_4_V","role":"data","value":"56"},{"name":"pos_5_V","role":"data","value":"64"},{"name":"pos_6_V","role":"data","value":"72"},{"name":"horizontalPos_V","role":"data","value":"80"}] },
	{ "name": "s_axi_CRTL_BUS_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "AWVALID" } },
	{ "name": "s_axi_CRTL_BUS_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "AWREADY" } },
	{ "name": "s_axi_CRTL_BUS_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "WVALID" } },
	{ "name": "s_axi_CRTL_BUS_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "WREADY" } },
	{ "name": "s_axi_CRTL_BUS_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "WDATA" } },
	{ "name": "s_axi_CRTL_BUS_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "WSTRB" } },
	{ "name": "s_axi_CRTL_BUS_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "ARADDR" },"address":[{"name":"nodeDetector","role":"start","value":"0","valid_bit":"0"},{"name":"nodeDetector","role":"done","value":"0","valid_bit":"1"},{"name":"nodeDetector","role":"idle","value":"0","valid_bit":"2"},{"name":"nodeDetector","role":"ready","value":"0","valid_bit":"3"},{"name":"nodeDetector","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_CRTL_BUS_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "ARVALID" } },
	{ "name": "s_axi_CRTL_BUS_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "ARREADY" } },
	{ "name": "s_axi_CRTL_BUS_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "RVALID" } },
	{ "name": "s_axi_CRTL_BUS_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "RREADY" } },
	{ "name": "s_axi_CRTL_BUS_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "RDATA" } },
	{ "name": "s_axi_CRTL_BUS_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "RRESP" } },
	{ "name": "s_axi_CRTL_BUS_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "BVALID" } },
	{ "name": "s_axi_CRTL_BUS_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "BREADY" } },
	{ "name": "s_axi_CRTL_BUS_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "CRTL_BUS", "role": "BRESP" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "inStream_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "inStream_V_data_V", "role": "default" }} , 
 	{ "name": "inStream_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "inStream_V_dest_V", "role": "default" }} , 
 	{ "name": "inStream_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "inStream_V_dest_V", "role": "default" }} , 
 	{ "name": "inStream_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inStream_V_keep_V", "role": "default" }} , 
 	{ "name": "inStream_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inStream_V_strb_V", "role": "default" }} , 
 	{ "name": "inStream_TUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "inStream_V_user_V", "role": "default" }} , 
 	{ "name": "inStream_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "inStream_V_last_V", "role": "default" }} , 
 	{ "name": "inStream_TID", "direction": "in", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "inStream_V_id_V", "role": "default" }} , 
 	{ "name": "inStream_TDEST", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "inStream_V_dest_V", "role": "default" }} , 
 	{ "name": "outStream_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":24, "type": "signal", "bundle":{"name": "outStream_V_data_V", "role": "default" }} , 
 	{ "name": "outStream_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "outStream_V_dest_V", "role": "default" }} , 
 	{ "name": "outStream_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "outStream_V_data_V", "role": "default" }} , 
 	{ "name": "outStream_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "outStream_V_keep_V", "role": "default" }} , 
 	{ "name": "outStream_TSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "outStream_V_strb_V", "role": "default" }} , 
 	{ "name": "outStream_TUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "outStream_V_user_V", "role": "default" }} , 
 	{ "name": "outStream_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "outStream_V_last_V", "role": "default" }} , 
 	{ "name": "outStream_TID", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "outStream_V_id_V", "role": "default" }} , 
 	{ "name": "outStream_TDEST", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "outStream_V_dest_V", "role": "default" }} , 
 	{ "name": "out_0_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_0_V", "role": "default" }} , 
 	{ "name": "out_1_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_1_V", "role": "default" }} , 
 	{ "name": "out_2_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_2_V", "role": "default" }} , 
 	{ "name": "out_3_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_3_V", "role": "default" }} , 
 	{ "name": "out_4_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_4_V", "role": "default" }} , 
 	{ "name": "out_5_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_5_V", "role": "default" }} , 
 	{ "name": "out_6_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out_6_V", "role": "default" }} , 
 	{ "name": "out2_0_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_0_V", "role": "default" }} , 
 	{ "name": "out2_1_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_1_V", "role": "default" }} , 
 	{ "name": "out2_2_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_2_V", "role": "default" }} , 
 	{ "name": "out2_3_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_3_V", "role": "default" }} , 
 	{ "name": "out2_4_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_4_V", "role": "default" }} , 
 	{ "name": "out2_5_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_5_V", "role": "default" }} , 
 	{ "name": "out2_6_V", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "out2_6_V", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "nodeDetector",
		"Protocol" : "ap_ctrl_none",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "921605", "EstimateLatencyMax" : "921605",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "inStream_V_data_V", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "inStream_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "inStream_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "inStream_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "inStream_V_user_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "inStream_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "inStream_V_id_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "inStream_V_dest_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "outStream_V_data_V", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "outStream_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "outStream_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "outStream_V_strb_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "outStream_V_user_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "outStream_V_last_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "outStream_V_id_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "outStream_V_dest_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "enable_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_0_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_1_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_2_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_3_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_4_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_5_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "pos_6_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "out_0_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out_1_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out_2_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out_3_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out_4_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out_5_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out_6_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_0_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_1_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_2_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_3_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_4_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_5_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "out2_6_V", "Type" : "None", "Direction" : "O"},
			{"Name" : "horizontalPos_V", "Type" : "None", "Direction" : "I"},
			{"Name" : "detections_0", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections_2", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections_4", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections_6", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_0", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_1", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_2", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_3", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_4", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_5", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "detections2_6", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.nodeDetector_CRTL_BUS_s_axi_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	nodeDetector {
		inStream_V_data_V {Type I LastRead 1 FirstWrite -1}
		inStream_V_keep_V {Type I LastRead 1 FirstWrite -1}
		inStream_V_strb_V {Type I LastRead 1 FirstWrite -1}
		inStream_V_user_V {Type I LastRead 1 FirstWrite -1}
		inStream_V_last_V {Type I LastRead 1 FirstWrite -1}
		inStream_V_id_V {Type I LastRead 1 FirstWrite -1}
		inStream_V_dest_V {Type I LastRead 1 FirstWrite -1}
		outStream_V_data_V {Type O LastRead -1 FirstWrite 4}
		outStream_V_keep_V {Type O LastRead -1 FirstWrite 4}
		outStream_V_strb_V {Type O LastRead -1 FirstWrite 4}
		outStream_V_user_V {Type O LastRead -1 FirstWrite 4}
		outStream_V_last_V {Type O LastRead -1 FirstWrite 4}
		outStream_V_id_V {Type O LastRead -1 FirstWrite 4}
		outStream_V_dest_V {Type O LastRead -1 FirstWrite 4}
		enable_V {Type I LastRead 0 FirstWrite -1}
		pos_0_V {Type I LastRead 2 FirstWrite -1}
		pos_1_V {Type I LastRead 2 FirstWrite -1}
		pos_2_V {Type I LastRead 2 FirstWrite -1}
		pos_3_V {Type I LastRead 2 FirstWrite -1}
		pos_4_V {Type I LastRead 2 FirstWrite -1}
		pos_5_V {Type I LastRead 2 FirstWrite -1}
		pos_6_V {Type I LastRead 2 FirstWrite -1}
		out_0_V {Type O LastRead -1 FirstWrite 3}
		out_1_V {Type O LastRead -1 FirstWrite 3}
		out_2_V {Type O LastRead -1 FirstWrite 3}
		out_3_V {Type O LastRead -1 FirstWrite 3}
		out_4_V {Type O LastRead -1 FirstWrite 3}
		out_5_V {Type O LastRead -1 FirstWrite 3}
		out_6_V {Type O LastRead -1 FirstWrite 3}
		out2_0_V {Type O LastRead -1 FirstWrite 3}
		out2_1_V {Type O LastRead -1 FirstWrite 3}
		out2_2_V {Type O LastRead -1 FirstWrite 3}
		out2_3_V {Type O LastRead -1 FirstWrite 3}
		out2_4_V {Type O LastRead -1 FirstWrite 3}
		out2_5_V {Type O LastRead -1 FirstWrite 3}
		out2_6_V {Type O LastRead -1 FirstWrite 3}
		horizontalPos_V {Type I LastRead 0 FirstWrite -1}
		detections_0 {Type IO LastRead -1 FirstWrite -1}
		detections_1 {Type IO LastRead -1 FirstWrite -1}
		detections_2 {Type IO LastRead -1 FirstWrite -1}
		detections_3 {Type IO LastRead -1 FirstWrite -1}
		detections_4 {Type IO LastRead -1 FirstWrite -1}
		detections_5 {Type IO LastRead -1 FirstWrite -1}
		detections_6 {Type IO LastRead -1 FirstWrite -1}
		detections2_0 {Type IO LastRead -1 FirstWrite -1}
		detections2_1 {Type IO LastRead -1 FirstWrite -1}
		detections2_2 {Type IO LastRead -1 FirstWrite -1}
		detections2_3 {Type IO LastRead -1 FirstWrite -1}
		detections2_4 {Type IO LastRead -1 FirstWrite -1}
		detections2_5 {Type IO LastRead -1 FirstWrite -1}
		detections2_6 {Type IO LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "921605", "Max" : "921605"}
	, {"Name" : "Interval", "Min" : "921606", "Max" : "921606"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	inStream_V_data_V { axis {  { inStream_TDATA in_data 0 24 } } }
	inStream_V_keep_V { axis {  { inStream_TKEEP in_data 0 3 } } }
	inStream_V_strb_V { axis {  { inStream_TSTRB in_data 0 3 } } }
	inStream_V_user_V { axis {  { inStream_TUSER in_data 0 2 } } }
	inStream_V_last_V { axis {  { inStream_TLAST in_data 0 1 } } }
	inStream_V_id_V { axis {  { inStream_TID in_data 0 5 } } }
	inStream_V_dest_V { axis {  { inStream_TVALID in_vld 0 1 }  { inStream_TREADY in_acc 1 1 }  { inStream_TDEST in_data 0 6 } } }
	outStream_V_data_V { axis {  { outStream_TDATA out_data 1 24 }  { outStream_TREADY out_acc 0 1 } } }
	outStream_V_keep_V { axis {  { outStream_TKEEP out_data 1 3 } } }
	outStream_V_strb_V { axis {  { outStream_TSTRB out_data 1 3 } } }
	outStream_V_user_V { axis {  { outStream_TUSER out_data 1 2 } } }
	outStream_V_last_V { axis {  { outStream_TLAST out_data 1 1 } } }
	outStream_V_id_V { axis {  { outStream_TID out_data 1 5 } } }
	outStream_V_dest_V { axis {  { outStream_TVALID out_vld 1 1 }  { outStream_TDEST out_data 1 6 } } }
	out_0_V { ap_none {  { out_0_V out_data 1 1 } } }
	out_1_V { ap_none {  { out_1_V out_data 1 1 } } }
	out_2_V { ap_none {  { out_2_V out_data 1 1 } } }
	out_3_V { ap_none {  { out_3_V out_data 1 1 } } }
	out_4_V { ap_none {  { out_4_V out_data 1 1 } } }
	out_5_V { ap_none {  { out_5_V out_data 1 1 } } }
	out_6_V { ap_none {  { out_6_V out_data 1 1 } } }
	out2_0_V { ap_none {  { out2_0_V out_data 1 1 } } }
	out2_1_V { ap_none {  { out2_1_V out_data 1 1 } } }
	out2_2_V { ap_none {  { out2_2_V out_data 1 1 } } }
	out2_3_V { ap_none {  { out2_3_V out_data 1 1 } } }
	out2_4_V { ap_none {  { out2_4_V out_data 1 1 } } }
	out2_5_V { ap_none {  { out2_5_V out_data 1 1 } } }
	out2_6_V { ap_none {  { out2_6_V out_data 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}

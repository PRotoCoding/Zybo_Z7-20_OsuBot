// ==============================================================
// File generated on Thu May 23 21:23:41 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xnodedetector.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XNodedetector_CfgInitialize(XNodedetector *InstancePtr, XNodedetector_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Crtl_bus_BaseAddress = ConfigPtr->Crtl_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XNodedetector_Set_enable_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_ENABLE_V_DATA, Data);
}

u32 XNodedetector_Get_enable_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_ENABLE_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_0_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_0_V_DATA, Data);
}

u32 XNodedetector_Get_pos_0_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_0_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_1_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_1_V_DATA, Data);
}

u32 XNodedetector_Get_pos_1_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_1_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_2_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_2_V_DATA, Data);
}

u32 XNodedetector_Get_pos_2_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_2_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_3_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_3_V_DATA, Data);
}

u32 XNodedetector_Get_pos_3_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_3_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_4_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_4_V_DATA, Data);
}

u32 XNodedetector_Get_pos_4_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_4_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_5_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_5_V_DATA, Data);
}

u32 XNodedetector_Get_pos_5_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_5_V_DATA);
    return Data;
}

void XNodedetector_Set_pos_6_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_6_V_DATA, Data);
}

u32 XNodedetector_Get_pos_6_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_POS_6_V_DATA);
    return Data;
}

void XNodedetector_Set_horizontalPos_V(XNodedetector *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNodedetector_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_HORIZONTALPOS_V_DATA, Data);
}

u32 XNodedetector_Get_horizontalPos_V(XNodedetector *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNodedetector_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XNODEDETECTOR_CRTL_BUS_ADDR_HORIZONTALPOS_V_DATA);
    return Data;
}


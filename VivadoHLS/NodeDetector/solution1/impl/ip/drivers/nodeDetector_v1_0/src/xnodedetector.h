// ==============================================================
// File generated on Thu May 23 21:23:41 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XNODEDETECTOR_H
#define XNODEDETECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xnodedetector_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Crtl_bus_BaseAddress;
} XNodedetector_Config;
#endif

typedef struct {
    u32 Crtl_bus_BaseAddress;
    u32 IsReady;
} XNodedetector;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XNodedetector_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XNodedetector_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XNodedetector_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XNodedetector_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XNodedetector_Initialize(XNodedetector *InstancePtr, u16 DeviceId);
XNodedetector_Config* XNodedetector_LookupConfig(u16 DeviceId);
int XNodedetector_CfgInitialize(XNodedetector *InstancePtr, XNodedetector_Config *ConfigPtr);
#else
int XNodedetector_Initialize(XNodedetector *InstancePtr, const char* InstanceName);
int XNodedetector_Release(XNodedetector *InstancePtr);
#endif


void XNodedetector_Set_enable_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_enable_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_0_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_0_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_1_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_1_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_2_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_2_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_3_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_3_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_4_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_4_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_5_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_5_V(XNodedetector *InstancePtr);
void XNodedetector_Set_pos_6_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_pos_6_V(XNodedetector *InstancePtr);
void XNodedetector_Set_horizontalPos_V(XNodedetector *InstancePtr, u32 Data);
u32 XNodedetector_Get_horizontalPos_V(XNodedetector *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif

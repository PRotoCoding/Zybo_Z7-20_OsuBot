// ==============================================================
// File generated on Thu May 23 21:23:41 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xnodedetector.h"

extern XNodedetector_Config XNodedetector_ConfigTable[];

XNodedetector_Config *XNodedetector_LookupConfig(u16 DeviceId) {
	XNodedetector_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XNODEDETECTOR_NUM_INSTANCES; Index++) {
		if (XNodedetector_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XNodedetector_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XNodedetector_Initialize(XNodedetector *InstancePtr, u16 DeviceId) {
	XNodedetector_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XNodedetector_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XNodedetector_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif


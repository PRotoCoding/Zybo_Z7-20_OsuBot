/************************************************************************/
/*																		*/
/*	video_demo.c	--	ZYBO Video demonstration 						*/
/*																		*/
/************************************************************************/
/*	Author: Sam Bobrowicz												*/
/*	Copyright 2015, Digilent Inc.										*/
/************************************************************************/
/*  Module Description: 												*/
/*																		*/
/*		This file contains code for running a demonstration of the		*/
/*		Video input and output capabilities on the ZYBO. It is a good	*/
/*		example of how to properly use the display_ctrl and				*/
/*		video_capture drivers.											*/
/*																		*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/* 																		*/
/*		11/25/2015(SamB): Created										*/
/*																		*/
/************************************************************************/

/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */

#include "video_demo.h"
#include "video_capture/video_capture.h"
#include "display_ctrl/display_ctrl.h"
#include "intc/intc.h"
#include <stdio.h>
#include "xuartps.h"
#include "math.h"
#include <ctype.h>
#include <stdlib.h>
#include "xil_types.h"
#include "xil_cache.h"
#include "timer_ps/timer_ps.h"
#include "xparameters.h"
#include "sleep.h"
#include "xnodedetector.h"
#include "xttcps.h"

/*
 * XPAR redefines
 */
#define NODEDETECTOR_ID			XPAR_NODEDETECTOR_0_DEVICE_ID
#define DYNCLK_BASEADDR 		XPAR_AXI_DYNCLK_0_BASEADDR
#define VDMA_ID 				XPAR_AXIVDMA_0_DEVICE_ID
#define HDMI_OUT_VTC_ID 		XPAR_V_TC_OUT_DEVICE_ID
#define HDMI_IN_VTC_ID 			XPAR_V_TC_IN_DEVICE_ID
#define HDMI_IN_GPIO_ID 		XPAR_AXI_GPIO_VIDEO_DEVICE_ID
#define HDMI_IN_VTC_IRPT_ID 	XPAR_FABRIC_V_TC_IN_IRQ_INTR
#define HDMI_IN_GPIO_IRPT_ID 	XPAR_FABRIC_AXI_GPIO_VIDEO_IP2INTC_IRPT_INTR
#define SCU_TIMER_ID 			XPAR_SCUTIMER_DEVICE_ID
#define UART_BASEADDR 			XPAR_PS7_UART_1_BASEADDR
#define SWITCHES_ID				XPAR_AXI_GPIO_SWS_DEVICE_ID
#define DETECT_ID				XPAR_AXI_GPIO_DETECT_DEVICE_ID
#define SWITCHES_IRPT_ID		XPAR_FABRIC_AXI_GPIO_SWS_IP2INTC_IRPT_INTR
#define DETECT_IRPT_ID			XPAR_FABRIC_AXI_GPIO_DETECT_IP2INTC_IRPT_INTR

#define SWS_INT					XGPIO_IR_CH2_MASK
#define DETECT_INT				XGPIO_IR_CH1_MASK

XGpio SwitchesInst, DetectorInst;

/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */

/*
 * Display and Video Driver structs
 */
XNodedetector nodeDetector;
DisplayCtrl dispCtrl;
XAxiVdma vdma;
VideoCapture videoCapt;
XTtcPs TtcInstance;
XTtcPs_Config* TtcConfig;
XTtcPs Ttc1Instance;
XTtcPs_Config* Ttc1Config;
INTC intc;
char fRefresh; //flag used to trigger a refresh of the Menu on video detect

void SwitchesISR(void* InstancePtr);
void DetectISR(void *InstancePtr);
void ttcISR(void *InstancePtr);
void ManageSwitches();

static u32 MatchValue;

/*
 * Framebuffers for video data
 */
u8 frameBuf[DISPLAY_NUM_FRAMES][DEMO_MAX_FRAME] __attribute__((aligned(0x20)));
u8 *pFrames[DISPLAY_NUM_FRAMES]; //array of pointers to the frame buffers

#define SwitchesGpioIvt(x,y)\
	{x, (XInterruptHandler)SwitchesISR, y, 0xA0, 0x3}

#define DetectGpioIvt(x,y)\
	{x, (XInterruptHandler)DetectISR, y, 0xA0, 0x3}

#define ttcIvt(x,y)\
	{x, (XInterruptHandler)ttcISR, y, 0xA0, 0x3}

/*
 * Interrupt vector table
 */
const ivt_t ivt[] = {
	videoGpioIvt(HDMI_IN_GPIO_IRPT_ID, &videoCapt),
	videoVtcIvt(HDMI_IN_VTC_IRPT_ID, &(videoCapt.vtc)),
	ttcIvt(XPAR_XTTCPS_0_INTR, &TtcInstance)//,
	//SwitchesGpioIvt(SWITCHES_IRPT_ID, &SwitchesInst)
};

typedef struct {
      u32 OutputHz;     /* Output frequency */
      u16 Interval;     /* Interval value */
      u8 Prescaler;     /* Prescaler value */
      u16 Options;      /* Option settings */
} TmrCntrSetup;

static TmrCntrSetup SettingsTable[1] = {
      {1000000, 0, 0, 0},    /* Ticker timer counter initial setup, only output freq */
};


/* ------------------------------------------------------------ */
/*				Procedure Definitions							*/
/* ------------------------------------------------------------ */

static int SetupInterruptSystem(u16 IntcDeviceID,
				    XScuGic *IntcInstancePtr)
{
	int Status;
	XScuGic_Config *IntcConfig; /* The configuration parameters of the
					interrupt controller */

	/*
	 * Initialize the interrupt controller driver
	 */
	IntcConfig = XScuGic_LookupConfig(IntcDeviceID);
	if (NULL == IntcConfig) {
		return XST_FAILURE;
	}

	Status = XScuGic_CfgInitialize(IntcInstancePtr, IntcConfig,
					IntcConfig->CpuBaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Connect the interrupt controller interrupt handler to the hardware
	 * interrupt handling logic in the ARM processor.
	 */
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler) XScuGic_InterruptHandler,
			IntcInstancePtr);

	/*
	 * Enable interrupts in the ARM
	 */
	Xil_ExceptionEnable();

	return XST_SUCCESS;
}

int main1(void)
{
	int Status = XGpio_Initialize(&SwitchesInst, SWITCHES_ID);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Switches error\n");
		return XST_FAILURE;
	}

	Status = XGpio_Initialize(&DetectorInst, DETECT_ID);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Switches error\n");
		return XST_FAILURE;
	}

	XGpio_SetDataDirection(&SwitchesInst, SWS_INT, 0xFF);
	XGpio_InterruptEnable(&SwitchesInst, SWS_INT);
	XGpio_InterruptGlobalEnable(&SwitchesInst);
	XGpio_SetDataDirection(&DetectorInst, DETECT_INT, 0xFF);
	XGpio_InterruptEnable(&DetectorInst, DETECT_INT);
	XGpio_InterruptGlobalEnable(&DetectorInst);

	SetupInterruptSystem(INTC_DEVICE_ID, &intc);

	/* TTC init */
	TtcConfig = XTtcPs_LookupConfig(XPAR_XTTCPS_0_DEVICE_ID);
	Status = XTtcPs_CfgInitialize(&TtcInstance, TtcConfig, TtcConfig->BaseAddress);
	if (Status == XST_DEVICE_IS_STARTED) {
		XTtcPs_Stop(&TtcInstance);
		Status = XTtcPs_CfgInitialize(&TtcInstance, TtcConfig, TtcConfig->BaseAddress);
		if (Status != XST_SUCCESS) {
				return XST_FAILURE;
		}
	}
	else if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	TmrCntrSetup* TimerSetup = &SettingsTable[0];
	TimerSetup->Options |= (XTTCPS_OPTION_INTERVAL_MODE | XTTCPS_OPTION_MATCH_MODE);
	XTtcPs_SetOptions(&TtcInstance, TimerSetup->Options);
	XTtcPs_CalcIntervalFromFreq(&TtcInstance, TimerSetup->OutputHz,&(TimerSetup->Interval), &(TimerSetup->Prescaler));
	XTtcPs_SetInterval(&TtcInstance, TimerSetup->Interval);
	XTtcPs_SetMatchValue(&TtcInstance, 0, TimerSetup->Interval / 8);
	XTtcPs_SetMatchValue(&TtcInstance, 1, TimerSetup->Interval / 8);
	XTtcPs_SetMatchValue(&TtcInstance, 2, TimerSetup->Interval / 8);
	XTtcPs_SetPrescaler(&TtcInstance, TimerSetup->Prescaler);

	/* TTC1 init */
	Ttc1Config = XTtcPs_LookupConfig(XPAR_XTTCPS_1_DEVICE_ID);
	Status = XTtcPs_CfgInitialize(&Ttc1Instance, Ttc1Config, Ttc1Config->BaseAddress);
	if (Status == XST_DEVICE_IS_STARTED) {
		XTtcPs_Stop(&Ttc1Instance);
		Status = XTtcPs_CfgInitialize(&Ttc1Instance, Ttc1Config, Ttc1Config->BaseAddress);
		if (Status != XST_SUCCESS) {
				return XST_FAILURE;
		}
	}
	else if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	TmrCntrSetup* Timer1Setup = &SettingsTable[0];
	Timer1Setup->Options |= (XTTCPS_OPTION_INTERVAL_MODE | XTTCPS_OPTION_MATCH_MODE);
	XTtcPs_SetOptions(&Ttc1Instance, Timer1Setup->Options);
	XTtcPs_CalcIntervalFromFreq(&Ttc1Instance, Timer1Setup->OutputHz,&(Timer1Setup->Interval), &(Timer1Setup->Prescaler));
	XTtcPs_SetInterval(&Ttc1Instance, Timer1Setup->Interval);
	XTtcPs_SetMatchValue(&Ttc1Instance, 0, Timer1Setup->Interval / 8);
	XTtcPs_SetMatchValue(&Ttc1Instance, 1, Timer1Setup->Interval / 8);
	XTtcPs_SetMatchValue(&Ttc1Instance, 2, Timer1Setup->Interval / 8);
	XTtcPs_SetPrescaler(&Ttc1Instance, Timer1Setup->Prescaler);


	XScuGic_Connect(&intc, XPAR_XTTCPS_0_INTR, (Xil_ExceptionHandler)ttcISR, (void*)&MatchValue);
	XScuGic_Enable(&intc, XPAR_XTTCPS_0_INTR);
	XTtcPs_EnableInterrupts(&TtcInstance, XTTCPS_IXR_ALL_MASK);

	XScuGic_Connect(&intc, XPAR_XTTCPS_3_INTR, (Xil_ExceptionHandler)ttcISR, (void*)&MatchValue);
	XScuGic_Enable(&intc, XPAR_XTTCPS_3_INTR);
	XTtcPs_EnableInterrupts(&Ttc1Instance, XTTCPS_IXR_ALL_MASK);

	u32 ClockReg = XTtcPs_ReadReg(TtcInstance.Config.BaseAddress, XTTCPS_CLK_CNTRL_OFFSET);
	XTtcPs_WriteReg(TtcInstance.Config.BaseAddress, XTTCPS_CLK_CNTRL_OFFSET, ClockReg);

	u32 CntReg = XTtcPs_ReadReg(TtcInstance.Config.BaseAddress, XTTCPS_CNT_CNTRL_OFFSET);

	u32 ierReg = XTtcPs_ReadReg(TtcInstance.Config.BaseAddress, XTTCPS_IER_OFFSET);
	CntReg = 0b0111010;
	//CntReg = XTTCPS_CNT_CNTRL_EN_WAVE_MASK || XTTCPS_CNT_CNTRL_POL_WAVE_MASK;
	//XTtcPs_WriteReg(TtcInstance.Config.BaseAddress, XTTCPS_CNT_CNTRL_OFFSET, CntReg);

	XTtcPs_Start(&TtcInstance);
	XTtcPs_Start(&Ttc1Instance);

	u32 cntVal;
	while(1) {
		cntVal =  XTtcPs_ReadReg(TtcInstance.Config.BaseAddress, XTTCPS_COUNT_VALUE_OFFSET);
		u32 cntVal2 =  XTtcPs_ReadReg(Ttc1Instance.Config.BaseAddress, XTTCPS_COUNT_VALUE_OFFSET);

		xil_printf("count val: %d, count val2: %d, isr: %d\n", cntVal, cntVal2, XTtcPs_ReadReg(TtcInstance.Config.BaseAddress, XTTCPS_ISR_OFFSET));
		usleep(2050);
	}

	DemoInitialize();

	XScuGic_SetPriorityTriggerType(&intc, SWITCHES_IRPT_ID, 0xA, 0x3);
	XScuGic_Connect(&intc, SWITCHES_IRPT_ID, (Xil_ExceptionHandler)SwitchesISR, &SwitchesInst);
	XScuGic_Enable(&intc, SWITCHES_IRPT_ID);
	XScuGic_SetPriorityTriggerType(&intc, DETECT_IRPT_ID, 0xA, 0x3);
	XScuGic_Connect(&intc, DETECT_IRPT_ID, (Xil_ExceptionHandler)DetectISR, &DetectorInst);
	XScuGic_Enable(&intc, DETECT_IRPT_ID);
	XScuGic_SetPriorityTriggerType(&intc, XPAR_XTTCPS_0_INTR, 0xA, 0x3);


#define START_POINT 496
#define LINE_WIDTH 45
#define VERT 200
	XNodedetector_Set_horizontalPos_V(&nodeDetector, VERT);
	XNodedetector_Set_pos_0_V(&nodeDetector, START_POINT - LINE_WIDTH * 6);
	XNodedetector_Set_pos_1_V(&nodeDetector, START_POINT - LINE_WIDTH * 5);
	XNodedetector_Set_pos_2_V(&nodeDetector, START_POINT - LINE_WIDTH * 4);
	XNodedetector_Set_pos_3_V(&nodeDetector, START_POINT - LINE_WIDTH * 3);
	XNodedetector_Set_pos_4_V(&nodeDetector, START_POINT - LINE_WIDTH * 2);
	XNodedetector_Set_pos_5_V(&nodeDetector, START_POINT - LINE_WIDTH * 1);
	XNodedetector_Set_pos_6_V(&nodeDetector, START_POINT);

	ManageSwitches();
	DemoRun();

	return 0;
}

void DemoInitialize()
{
	int Status;
	XAxiVdma_Config *vdmaConfig;
	XNodedetector_Config *nodedetectorConfig;
	int i;

	/*
	 * Initialize an array of pointers to the 3 frame buffers
	 */
	for (i = 0; i < DISPLAY_NUM_FRAMES; i++)
	{
		pFrames[i] = frameBuf[i];
	}

	/*
	 * Initialize a timer used for a simple delay
	 */
	TimerInitialize(SCU_TIMER_ID);


	/*
	 * Initialize NodeDetector
	 */
	nodedetectorConfig = XNodedetector_LookupConfig(NODEDETECTOR_ID);
	if(nodedetectorConfig)
	{
		if(XNodedetector_CfgInitialize(&nodeDetector,nodedetectorConfig) != XST_SUCCESS) {
			xil_printf("Error initializing nodedetector\n");
		}
	}

	/*
	 * Initialize VDMA driver
	 */
	vdmaConfig = XAxiVdma_LookupConfig(VDMA_ID);
	if (!vdmaConfig)
	{
		xil_printf("No video DMA found for ID %d\r\n", VDMA_ID);
		return;
	}
	Status = XAxiVdma_CfgInitialize(&vdma, vdmaConfig, vdmaConfig->BaseAddress);
	if (Status != XST_SUCCESS)
	{
		xil_printf("VDMA Configuration Initialization failed %d\r\n", Status);
		//return;
	}

	/*
	 * Initialize the Display controller and start it
	 */
	Status = DisplayInitialize(&dispCtrl, &vdma, HDMI_OUT_VTC_ID, DYNCLK_BASEADDR, pFrames, DEMO_STRIDE);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Display Ctrl initialization failed during demo initialization%d\r\n", Status);
		return;
	}
	Status = DisplayStart(&dispCtrl);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Couldn't start display during demo initialization%d\r\n", Status);
		//return;
	}

	/*
	 * Initialize the Interrupt controller and start it.
	 */
	Status = fnInitInterruptController(&intc);
	if(Status != XST_SUCCESS) {
		xil_printf("Error initializing interrupts");
		return;
	}
	fnEnableInterrupts(&intc, &ivt[0], sizeof(ivt)/sizeof(ivt[0]));

	/*
	 * Initialize the Video Capture device
	 */
	Status = VideoInitialize(&videoCapt, &intc, &vdma, HDMI_IN_GPIO_ID, HDMI_IN_VTC_ID, HDMI_IN_VTC_IRPT_ID, pFrames, DEMO_STRIDE, DEMO_START_ON_DET);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Video Ctrl initialization failed during demo initialization%d\r\n", Status);
		//return;
	}

	/*
	 * Set the Video Detect callback to trigger the menu to reset, displaying the new detected resolution
	 */
	//VideoSetCallback(&videoCapt, DemoISR, &fRefresh);

	//DemoPrintTest(dispCtrl.framePtr[dispCtrl.curFrame], dispCtrl.vMode.width, dispCtrl.vMode.height, dispCtrl.stride, DEMO_PATTERN_1);

	return;
}

void DemoRun()
{
	int nextFrame = 0;
	char userInput = 0;
	int horizontalPos = 200;
	/* Flush UART FIFO */
	while (XUartPs_IsReceiveData(UART_BASEADDR))
	{
		XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
	}

	while(1) {
		uint32_t val = XGpio_DiscreteRead(&DetectorInst, DETECT_INT);
		//XUartPs_SendByte(UART_BASEADDR, val & 0xFF);

		usleep(500);
	}

	while (userInput != 'q')
	{
		fRefresh = 0;
		DemoPrintMenu();

		/* Wait for data on UART */
		while (!XUartPs_IsReceiveData(UART_BASEADDR) && !fRefresh)
		{}

		/* Store the first character in the UART receive FIFO and echo it */
		if (XUartPs_IsReceiveData(UART_BASEADDR))
		{
			userInput = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
			xil_printf("%c", userInput);
		}
		else  //Refresh triggered by video detect interrupt
		{
			userInput = 'r';
		}

		switch (userInput)
		{
		case '1':
			DemoChangeRes();
			break;
		case '2':
			nextFrame = dispCtrl.curFrame + 1;
			if (nextFrame >= DISPLAY_NUM_FRAMES)
			{
				nextFrame = 0;
			}
			DisplayChangeFrame(&dispCtrl, nextFrame);
			break;
		case '3':
			DemoPrintTest(pFrames[dispCtrl.curFrame], dispCtrl.vMode.width, dispCtrl.vMode.height, DEMO_STRIDE, DEMO_PATTERN_0);
			break;
		case '4':
			DemoPrintTest(pFrames[dispCtrl.curFrame], dispCtrl.vMode.width, dispCtrl.vMode.height, DEMO_STRIDE, DEMO_PATTERN_1);
			break;
		case '5':
			if (videoCapt.state == VIDEO_STREAMING)
				VideoStop(&videoCapt);
			else
				VideoStart(&videoCapt);
			break;
		case '6':
			nextFrame = videoCapt.curFrame + 1;
			if (nextFrame >= DISPLAY_NUM_FRAMES)
			{
				nextFrame = 0;
			}
			VideoChangeFrame(&videoCapt, nextFrame);
			break;
		case '7':
			nextFrame = videoCapt.curFrame + 1;
			if (nextFrame >= DISPLAY_NUM_FRAMES)
			{
				nextFrame = 0;
			}
			VideoStop(&videoCapt);
			DemoInvertFrame(pFrames[videoCapt.curFrame], pFrames[nextFrame], videoCapt.timing.HActiveVideo, videoCapt.timing.VActiveVideo, DEMO_STRIDE);
			VideoStart(&videoCapt);
			DisplayChangeFrame(&dispCtrl, nextFrame);
			break;
		case '8':
			nextFrame = videoCapt.curFrame + 1;
			if (nextFrame >= DISPLAY_NUM_FRAMES)
			{
				nextFrame = 0;
			}
			VideoStop(&videoCapt);
			DemoScaleFrame(pFrames[videoCapt.curFrame], pFrames[nextFrame], videoCapt.timing.HActiveVideo, videoCapt.timing.VActiveVideo, dispCtrl.vMode.width, dispCtrl.vMode.height, DEMO_STRIDE);
			VideoStart(&videoCapt);
			DisplayChangeFrame(&dispCtrl, nextFrame);
			break;
		case '9':
			XNodedetector_Set_horizontalPos_V(&nodeDetector, ++horizontalPos);
			break;
		case 'q':
			break;
		case 'r':
			break;
		default :
			xil_printf("\n\rInvalid Selection");
			TimerDelay(500000);
		}
	}

	return;
}

void DemoPrintMenu()
{
	xil_printf("\x1B[H"); //Set cursor to top left of terminal
	xil_printf("\x1B[2J"); //Clear terminal
	xil_printf("**************************************************\n\r");
	xil_printf("*                ZYBO Video Demo                 *\n\r");
	xil_printf("**************************************************\n\r");
	xil_printf("*Display Resolution: %28s*\n\r", dispCtrl.vMode.label);
	printf("*Display Pixel Clock Freq. (MHz): %15.3f*\n\r", dispCtrl.pxlFreq);
	xil_printf("*Display Frame Index: %27d*\n\r", dispCtrl.curFrame);
	if (videoCapt.state == VIDEO_DISCONNECTED) xil_printf("*Video Capture Resolution: %22s*\n\r", "!HDMI UNPLUGGED!");
	else xil_printf("*Video Capture Resolution: %17dx%-4d*\n\r", videoCapt.timing.HActiveVideo, videoCapt.timing.VActiveVideo);
	xil_printf("*Video Frame Index: %29d*\n\r", videoCapt.curFrame);
	xil_printf("**************************************************\n\r");
	xil_printf("\n\r");
	xil_printf("1 - Change Display Resolution\n\r");
	xil_printf("2 - Change Display Framebuffer Index\n\r");
	xil_printf("3 - Print Blended Test Pattern to Display Framebuffer\n\r");
	xil_printf("4 - Print Color Bar Test Pattern to Display Framebuffer\n\r");
	xil_printf("5 - Start/Stop Video stream into Video Framebuffer\n\r");
	xil_printf("6 - Change Video Framebuffer Index\n\r");
	xil_printf("7 - Grab Video Frame and invert colors\n\r");
	xil_printf("8 - Grab Video Frame and scale to Display resolution\n\r");
	xil_printf("9 - Increment horizontal cursor\n");
	xil_printf("q - Quit\n\r");
	xil_printf("\n\r");
	xil_printf("\n\r");
	xil_printf("Enter a selection:");
}

void DemoChangeRes()
{
	int fResSet = 0;
	int status;
	char userInput = 0;

	/* Flush UART FIFO */
	while (XUartPs_IsReceiveData(UART_BASEADDR))
	{
		XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
	}

	while (!fResSet)
	{
		DemoCRMenu();

		/* Wait for data on UART */
		while (!XUartPs_IsReceiveData(UART_BASEADDR))
		{}

		/* Store the first character in the UART recieve FIFO and echo it */
		userInput = XUartPs_ReadReg(UART_BASEADDR, XUARTPS_FIFO_OFFSET);
		xil_printf("%c", userInput);
		status = XST_SUCCESS;
		switch (userInput)
		{
		case '1':
			status = DisplayStop(&dispCtrl);
			DisplaySetMode(&dispCtrl, &VMODE_640x480);
			DisplayStart(&dispCtrl);
			fResSet = 1;
			break;
		case '2':
			status = DisplayStop(&dispCtrl);
			DisplaySetMode(&dispCtrl, &VMODE_800x600);
			DisplayStart(&dispCtrl);
			fResSet = 1;
			break;
		case '3':
			status = DisplayStop(&dispCtrl);
			DisplaySetMode(&dispCtrl, &VMODE_1280x720);
			DisplayStart(&dispCtrl);
			fResSet = 1;
			break;
		case '4':
			status = DisplayStop(&dispCtrl);
			DisplaySetMode(&dispCtrl, &VMODE_1280x1024);
			DisplayStart(&dispCtrl);
			fResSet = 1;
			break;
		case '5':
			status = DisplayStop(&dispCtrl);
			DisplaySetMode(&dispCtrl, &VMODE_1600x900);
			DisplayStart(&dispCtrl);
			fResSet = 1;
			break;
		case '6':
			status = DisplayStop(&dispCtrl);
			DisplaySetMode(&dispCtrl, &VMODE_1920x1080);
			DisplayStart(&dispCtrl);
			fResSet = 1;
			break;
		case 'q':
			fResSet = 1;
			break;
		default :
			xil_printf("\n\rInvalid Selection");
			TimerDelay(500000);
		}
		if (status == XST_DMA_ERROR)
		{
			xil_printf("\n\rWARNING: AXI VDMA Error detected and cleared\n\r");
		}
	}
}

void DemoCRMenu()
{
	xil_printf("\x1B[H"); //Set cursor to top left of terminal
	xil_printf("\x1B[2J"); //Clear terminal
	xil_printf("**************************************************\n\r");
	xil_printf("*                ZYBO Video Demo                 *\n\r");
	xil_printf("**************************************************\n\r");
	xil_printf("*Current Resolution: %28s*\n\r", dispCtrl.vMode.label);
	printf("*Pixel Clock Freq. (MHz): %23.3f*\n\r", dispCtrl.pxlFreq);
	xil_printf("**************************************************\n\r");
	xil_printf("\n\r");
	xil_printf("1 - %s\n\r", VMODE_640x480.label);
	xil_printf("2 - %s\n\r", VMODE_800x600.label);
	xil_printf("3 - %s\n\r", VMODE_1280x720.label);
	xil_printf("4 - %s\n\r", VMODE_1280x1024.label);
	xil_printf("5 - %s\n\r", VMODE_1600x900.label);
	xil_printf("6 - %s\n\r", VMODE_1920x1080.label);
	xil_printf("q - Quit (don't change resolution)\n\r");
	xil_printf("\n\r");
	xil_printf("Select a new resolution:");
}

void DemoInvertFrame(u8 *srcFrame, u8 *destFrame, u32 width, u32 height, u32 stride)
{
	u32 xcoi, ycoi;
	u32 lineStart = 0;
	for(ycoi = 0; ycoi < height; ycoi++)
	{
		for(xcoi = 0; xcoi < (width * 3); xcoi+=3)
		{
			destFrame[xcoi + lineStart] = ~srcFrame[xcoi + lineStart];         //Red
			destFrame[xcoi + lineStart + 1] = ~srcFrame[xcoi + lineStart + 1]; //Blue
			destFrame[xcoi + lineStart + 2] = ~srcFrame[xcoi + lineStart + 2]; //Green
		}
		lineStart += stride;
	}
	/*
	 * Flush the framebuffer memory range to ensure changes are written to the
	 * actual memory, and therefore accessible by the VDMA.
	 */
	Xil_DCacheFlushRange((unsigned int) destFrame, DEMO_MAX_FRAME);
}


/*
 * Bilinear interpolation algorithm. Assumes both frames have the same stride.
 */
void DemoScaleFrame(u8 *srcFrame, u8 *destFrame, u32 srcWidth, u32 srcHeight, u32 destWidth, u32 destHeight, u32 stride)
{
	float xInc, yInc; // Width/height of a destination frame pixel in the source frame coordinate system
	float xcoSrc, ycoSrc; // Location of the destination pixel being operated on in the source frame coordinate system
	float x1y1, x2y1, x1y2, x2y2; //Used to store the color data of the four nearest source pixels to the destination pixel
	int ix1y1, ix2y1, ix1y2, ix2y2; //indexes into the source frame for the four nearest source pixels to the destination pixel
	float xDist, yDist; //distances between destination pixel and x1y1 source pixels in source frame coordinate system

	int xcoDest, ycoDest; // Location of the destination pixel being operated on in the destination coordinate system
	int iy1; //Used to store the index of the first source pixel in the line with y1
	int iDest; //index of the pixel data in the destination frame being operated on

	int i;

	xInc = ((float) srcWidth - 1.0) / ((float) destWidth);
	yInc = ((float) srcHeight - 1.0) / ((float) destHeight);

	ycoSrc = 0.0;
	for (ycoDest = 0; ycoDest < destHeight; ycoDest++)
	{
		iy1 = ((int) ycoSrc) * stride;
		yDist = ycoSrc - ((float) ((int) ycoSrc));

		/*
		 * Save some cycles in the loop below by presetting the destination
		 * index to the first pixel in the current line
		 */
		iDest = ycoDest * stride;

		xcoSrc = 0.0;
		for (xcoDest = 0; xcoDest < destWidth; xcoDest++)
		{
			ix1y1 = iy1 + ((int) xcoSrc) * 3;
			ix2y1 = ix1y1 + 3;
			ix1y2 = ix1y1 + stride;
			ix2y2 = ix1y1 + stride + 3;

			xDist = xcoSrc - ((float) ((int) xcoSrc));

			/*
			 * For loop handles all three colors
			 */
			for (i = 0; i < 3; i++)
			{
				x1y1 = (float) srcFrame[ix1y1 + i];
				x2y1 = (float) srcFrame[ix2y1 + i];
				x1y2 = (float) srcFrame[ix1y2 + i];
				x2y2 = (float) srcFrame[ix2y2 + i];

				/*
				 * Bilinear interpolation function
				 */
				destFrame[iDest] = (u8) ((1.0-yDist)*((1.0-xDist)*x1y1+xDist*x2y1) + yDist*((1.0-xDist)*x1y2+xDist*x2y2));
				iDest++;
			}
			xcoSrc += xInc;
		}
		ycoSrc += yInc;
	}

	/*
	 * Flush the framebuffer memory range to ensure changes are written to the
	 * actual memory, and therefore accessible by the VDMA.
	 */
	Xil_DCacheFlushRange((unsigned int) destFrame, DEMO_MAX_FRAME);

	return;
}

void DemoPrintTest(u8 *frame, u32 width, u32 height, u32 stride, int pattern)
{
	u32 xcoi, ycoi;
	u32 iPixelAddr;
	u8 wRed, wBlue, wGreen;
	u32 wCurrentInt;
	double fRed, fBlue, fGreen, fColor;
	u32 xLeft, xMid, xRight, xInt;
	u32 yMid, yInt;
	double xInc, yInc;


	switch (pattern)
	{
	case DEMO_PATTERN_0:

		xInt = width / 4; //Four intervals, each with width/4 pixels
		xLeft = xInt * 3;
		xMid = xInt * 2 * 3;
		xRight = xInt * 3 * 3;
		xInc = 256.0 / ((double) xInt); //256 color intensities are cycled through per interval (overflow must be caught when color=256.0)

		yInt = height / 2; //Two intervals, each with width/2 lines
		yMid = yInt;
		yInc = 256.0 / ((double) yInt); //256 color intensities are cycled through per interval (overflow must be caught when color=256.0)

		fBlue = 0.0;
		fRed = 256.0;
		for(xcoi = 0; xcoi < (width*3); xcoi+=3)
		{
			/*
			 * Convert color intensities to integers < 256, and trim values >=256
			 */
			wRed = (fRed >= 256.0) ? 255 : ((u8) fRed);
			wBlue = (fBlue >= 256.0) ? 255 : ((u8) fBlue);
			iPixelAddr = xcoi;
			fGreen = 0.0;
			for(ycoi = 0; ycoi < height; ycoi++)
			{

				wGreen = (fGreen >= 256.0) ? 255 : ((u8) fGreen);
				frame[iPixelAddr] = wRed;
				frame[iPixelAddr + 1] = wBlue;
				frame[iPixelAddr + 2] = wGreen;
				if (ycoi < yMid)
				{
					fGreen += yInc;
				}
				else
				{
					fGreen -= yInc;
				}

				/*
				 * This pattern is printed one vertical line at a time, so the address must be incremented
				 * by the stride instead of just 1.
				 */
				iPixelAddr += stride;
			}

			if (xcoi < xLeft)
			{
				fBlue = 0.0;
				fRed -= xInc;
			}
			else if (xcoi < xMid)
			{
				fBlue += xInc;
				fRed += xInc;
			}
			else if (xcoi < xRight)
			{
				fBlue -= xInc;
				fRed -= xInc;
			}
			else
			{
				fBlue += xInc;
				fRed = 0;
			}
		}
		/*
		 * Flush the framebuffer memory range to ensure changes are written to the
		 * actual memory, and therefore accessible by the VDMA.
		 */
		Xil_DCacheFlushRange((unsigned int) frame, DEMO_MAX_FRAME);
		break;
	case DEMO_PATTERN_1:

		xInt = width / 7; //Seven intervals, each with width/7 pixels
		xInc = 256.0 / ((double) xInt); //256 color intensities per interval. Notice that overflow is handled for this pattern.

		fColor = 0.0;
		wCurrentInt = 1;
		for(xcoi = 0; xcoi < (width*3); xcoi+=3)
		{

			/*
			 * Just draw white in the last partial interval (when width is not divisible by 7)
			 */
			if (wCurrentInt > 7)
			{
				wRed = 255;
				wBlue = 255;
				wGreen = 255;
			}
			else
			{
				if (wCurrentInt & 0b001)
					wRed = (u8) fColor;
				else
					wRed = 0;

				if (wCurrentInt & 0b010)
					wBlue = (u8) fColor;
				else
					wBlue = 0;

				if (wCurrentInt & 0b100)
					wGreen = (u8) fColor;
				else
					wGreen = 0;
			}

			iPixelAddr = xcoi;

			for(ycoi = 0; ycoi < height; ycoi++)
			{
				frame[iPixelAddr] = wRed;
				frame[iPixelAddr + 1] = wBlue;
				frame[iPixelAddr + 2] = wGreen;
				/*
				 * This pattern is printed one vertical line at a time, so the address must be incremented
				 * by the stride instead of just 1.
				 */
				iPixelAddr += stride;
			}

			fColor += xInc;
			if (fColor >= 256.0)
			{
				fColor = 0.0;
				wCurrentInt++;
			}
		}
		/*
		 * Flush the framebuffer memory range to ensure changes are written to the
		 * actual memory, and therefore accessible by the VDMA.
		 */
		Xil_DCacheFlushRange((unsigned int) frame, DEMO_MAX_FRAME);
		break;
	default :
		xil_printf("Error: invalid pattern passed to DemoPrintTest");
	}
}

void DemoISR(void *callBackRef, void *pVideo)
{
	char *data = (char *) callBackRef;
	*data = 1; //set fRefresh to 1
}

void SwitchesISR(void* InstancePtr) {
	XGpio_InterruptDisable(&SwitchesInst, SWS_INT);

	ManageSwitches();

	XGpio_InterruptClear(&SwitchesInst, SWS_INT);
	XGpio_InterruptEnable(&SwitchesInst, SWS_INT);
}

void ManageSwitches() {
	uint32_t val = XGpio_DiscreteRead(&SwitchesInst, SWS_INT);

	uint8_t enable = 0x00;
	if(val != 0) {
		enable = (val << 4) | 0xF;
	}
	XNodedetector_Set_enable_V(&nodeDetector, enable);
}

void DetectISR(void *InstancePtr) {
	XGpio_InterruptDisable(&DetectorInst, DETECT_INT);

	uint32_t val = XGpio_DiscreteRead(&DetectorInst, DETECT_INT);
	XUartPs_SendByte(UART_BASEADDR, val & 0xFF);

	XGpio_InterruptClear(&DetectorInst, DETECT_INT);
	XGpio_InterruptEnable(&DetectorInst, DETECT_INT);
}


void ttcISR(void *InstancePtr) {
	//xil_printf("Interrupt\n");
	XTtcPs_ClearInterruptStatus(&TtcInstance, XTTCPS_IXR_INTERVAL_MASK);
}

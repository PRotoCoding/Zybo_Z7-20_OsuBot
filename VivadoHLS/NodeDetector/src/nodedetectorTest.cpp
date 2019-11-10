#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <stdio.h>

typedef ap_axiu<24,2,5,6> intSdCh;
#define NUMBER_OF_NODELINES 7
#define PICTURE_WIDTH 1280
#define PICTURE_HEIGHT 720
#define PICTURE_PIXEL_COUNT PICTURE_WIDTH * PICTURE_HEIGHT

void nodeDetector(hls::stream<intSdCh> &inStream, hls::stream<intSdCh> &outStream, ap_int<NUMBER_OF_NODELINES+1> enable, ap_int<16> pos0, ap_int<16> pos1, ap_int<16> pos2, ap_int<16> pos3, ap_int<16> pos4, ap_int<16> pos5, ap_int<16> pos6, ap_int<16> horizontalPos, ap_int<4>* detectionOut);
int main() {
	hls::stream<intSdCh> inputStream;
	hls::stream<intSdCh> outputStream;

	int randomArray[NUMBER_OF_NODELINES] = {0,0,0,0};
	int error_flag = 0;

	for(int i = 0; i <PICTURE_PIXEL_COUNT; i++) {
		intSdCh valIn;

		// Start of frame
		valIn.user = i == 0 ? 1 : 0;
		// End of line
		valIn.last = ((i % PICTURE_WIDTH) == (PICTURE_WIDTH - 1)) ? 1 : 0;

		valIn.data = 0x000000;
		valIn.keep = 1;
		valIn.strb = 1;
		valIn.id = 0;
		valIn.dest = 0;

		inputStream << valIn;
	}

	nodeDetector(inputStream, outputStream, 360, 0, 0, 0, 0, 0, 0, 0, 0);
	int greenCnt = 0;
	int blueCnt = 0;
	for (int row = 0; row < PICTURE_HEIGHT; row++) {
		for (int col = 0; col < PICTURE_WIDTH; col++) {
			intSdCh valOut;
			outputStream.read(valOut);
			if(valOut.data == 0xF0FF00) {
				printf("Blue in row %d, col %d\n", row, col);
				blueCnt++;
			}

			if(valOut.data == 0x0000FF) {
				printf("Green in row %d, col %d\n", row, col);
				greenCnt++;
			}
		}
	}
	printf("GreenCnt: %d, BlueCnt: %d\n", greenCnt, blueCnt);
	if(!((greenCnt == PICTURE_HEIGHT - 1) && blueCnt == PICTURE_WIDTH)){
		printf("**********************************************\n");
		printf("FAIL: Output does not match the golden output!\n");
		printf("**********************************************\n");
		return 1;
	}
	else {
		printf("*******************************************\n");
		printf("PASS: The output matches the golden output!\n");
		printf("*******************************************\n");
		return 0;
	}
}

#include "nodedetector.h"
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/mat.hpp>
#include <string>

#define NUM_OF_TESTS 1
#define MAX_NUM_OF_TESTS 5

#define RED(x) ((x >> 8) & 0xFF)
#define GREEN(x) ((x >> 16) & 0xFF)
#define BLUE(x) ((x >> 0) & 0xFF)

#define START_POINT 496
#define LINE_WIDTH 45
#define VERTICAL 200
#define POSITION(x) START_POINT - LINE_WIDTH * x

int main() {
	bool success = true;

	ap_int<NUMBER_OF_NODELINES> outRef[MAX_NUM_OF_TESTS][NUMBER_OF_HORIZONTAL_LINES] = {{0x0A, 0x0A}, {0x06, 0x06}, {0x03, 0x03}, {0x14, 0x14}, {0x00, 0x00}};

	ap_int<NUMBER_OF_NODELINES+1> enable = 0xFF;
	ap_int<16> pos[NUMBER_OF_NODELINES] = {POSITION(6), POSITION(5), POSITION(4), POSITION(3), POSITION(2), POSITION(1), POSITION(0)};
	//ap_int<NUMBER_OF_NODELINES> out[NUMBER_OF_HORIZONTAL_LINES] = {0xFF, 0xFF};
	bool out[NUMBER_OF_HORIZONTAL_LINES][NUMBER_OF_NODELINES] = {0};
	ap_int<16> horizontalPos[NUMBER_OF_HORIZONTAL_LINES] = {VERTICAL, VERTICAL + 1};

	for(int testNumber = 0; testNumber < NUM_OF_TESTS; testNumber++) {
		std::string fileName = "G:/Vivado_Projects/Zybo_Z7-20_OsuBot/VivadoHLS/NodeDetector/TestPictures/test";
		fileName += std::to_string(testNumber);
		fileName += ".jpg";

		cv::Mat loadedPic = cv::imread(fileName, CV_LOAD_IMAGE_UNCHANGED);

		cv::Mat originalPic = cv::Mat(PICTURE_HEIGHT, PICTURE_WIDTH, CV_8UC3, cv::Scalar(0, 0, 0));
		resize(loadedPic, originalPic, originalPic.size(), 0, 0, cv::INTER_CUBIC);
		cv::Mat modifiedPic = cv::Mat(PICTURE_HEIGHT, PICTURE_WIDTH, CV_8UC3, cv::Scalar(0, 0, 0));

		hls::stream<intSdCh> inputStream;
		hls::stream<intSdCh> outputStream;

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

			cv::Vec3b color = originalPic.at<cv::Vec3b>(cv::Point(i % PICTURE_WIDTH, i / PICTURE_WIDTH));
			valIn.data = ((int) color.val[0] << 8) | ((int) color.val[1] << 16) | color.val[2];
			inputStream << valIn;
		}

		nodeDetector(inputStream, outputStream, enable, pos, out, horizontalPos);

		// Read results
		int greenCnt = 0;
		int blueCnt = 0;
		for (int row = 0; row < PICTURE_HEIGHT; row++) {
			for (int col = 0; col < PICTURE_WIDTH; col++) {
				intSdCh valOut;
				//nodeDetector(inputStream, outputStream, enable, pos, out, horizontalPos);
				outputStream.read(valOut);
				cv::Vec3b color = cv::Vec3b(RED(valOut.data), GREEN(valOut.data), BLUE(valOut.data));
				modifiedPic.at<cv::Vec3b>(cv::Point(col, row)) = color;
				if(valOut.data == 0x00FF00) {
					blueCnt++;
				}
			}
		}

		// Check blue lines
		if(blueCnt != (PICTURE_WIDTH * NUMBER_OF_HORIZONTAL_LINES + PICTURE_HEIGHT * NUMBER_OF_NODELINES - NUMBER_OF_NODELINES * NUMBER_OF_HORIZONTAL_LINES)){
			printf("Error: BlueCnt %d\n", blueCnt);
			success = false;
		}

		// Check note detection
		printf("\nTest %d\n", testNumber);
		for(int i = 0; i < NUMBER_OF_HORIZONTAL_LINES; i++) {

			for (int j = 0; j < NUMBER_OF_NODELINES; j++) {
				printf(" %d ", out[i][j]);
			}
			printf("\n");
			/*if(out[i] != outRef[testNumber][i]) {
				success = false;
				//printf("Error: note detection failed (test %d, out: 0x%02X, outRef: 0x%02X)\n", testNumber, out[i].range(0, NUMBER_OF_NODELINES - 1).to_int(), outRef[testNumber][i].range(0, NUMBER_OF_NODELINES - 1).to_int());
			}*/
		}
		printf("\n");
		// Show results
		cv::imshow("modifiedPic", modifiedPic);
		cv::imshow("originalPic", originalPic);
		cv::waitKey(0);
		cv::destroyAllWindows();
		if(!success) break;
	}
	if(success) {
		printf("*******************************************\n");
		printf("PASS: The output matches the golden output!\n");
		printf("*******************************************\n");
		return 0;
	}
	else {
		printf("**********************************************\n");
		printf("FAIL: Output does not match the golden output!\n");
		printf("**********************************************\n");
		return 1;
	}
}

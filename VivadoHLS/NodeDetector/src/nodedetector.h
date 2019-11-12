#include <hls_stream.h>
#include <ap_axi_sdata.h>

typedef ap_axiu<24,2,5,6> intSdCh;
#define NUMBER_OF_NODELINES 7
#define NUMBER_OF_HORIZONTAL_LINES 2
#define PICTURE_WIDTH 1280
#define PICTURE_HEIGHT 720
#define PICTURE_PIXEL_COUNT PICTURE_WIDTH * PICTURE_HEIGHT

void nodeDetector(hls::stream<intSdCh> &inStream, hls::stream<intSdCh> &outStream, ap_int<NUMBER_OF_NODELINES+1> enable,
		ap_int<16> pos[NUMBER_OF_NODELINES], ap_int<NUMBER_OF_NODELINES> out[NUMBER_OF_HORIZONTAL_LINES], ap_int<16> horizontalPos[NUMBER_OF_HORIZONTAL_LINES]);

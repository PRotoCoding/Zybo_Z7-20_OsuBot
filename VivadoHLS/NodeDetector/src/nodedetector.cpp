#include "nodedetector.h"

#define ENABLED(x) ((enable >> (x + 1)) & 0x1)
#define ENABLED_HOR (enable & 0x1)

#define RED(x) ((x >> 16) & 0xFF)
#define GREEN(x) ((x >> 0) & 0xFF)
#define BLUE(x) ((x >> 8) & 0xFF)

#define DETECTION(x) if(RED(valIn.data) > 100 || GREEN(valIn.data) > 100 || BLUE(valIn.data) > 100) a |= (0x1 << x); else a &= (~(0x1 << x));

void nodeDetector(hls::stream<intSdCh> &inStream, hls::stream<intSdCh> &outStream, ap_int<NUMBER_OF_NODELINES+1> enable,
		ap_int<16> pos[NUMBER_OF_NODELINES], ap_int<NUMBER_OF_NODELINES> out[NUMBER_OF_HORIZONTAL_LINES], ap_int<16> horizontalPos[NUMBER_OF_HORIZONTAL_LINES])
{
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream
#pragma HLS INTERFACE s_axilite port=pos bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=enable bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=horizontalPos bundle=CRTL_BUS
//#pragma HLS INTERFACE ap_ctrl_none port=return bundle=CTRL_BUS
//#pragma HLS INTERFACE ap_none port=out
#pragma HLS ARRAY_PARTITION variable=pos complete dim=1
#pragma HLS ARRAY_PARTITION variable=horizontalPos complete dim=1
#pragma HLS ARRAY_PARTITION variable=out complete dim=1

	ap_int<32> pixelCnt = 0;
	ap_int<16> rowCnt = 0;
	ap_int<16> columnCnt = 0;

	nodeDetector_pipelining:for(int i = 0; i < (720*1280); i++) {
		ap_int<1> drawBlue = 0;
		ap_int<1> isNote = 0;

		intSdCh valIn = inStream.read();
		intSdCh valOut;

		// Start Of Frame
		if(valIn.user == 1) {
			columnCnt = 0;
			rowCnt = 0;
		}

		// Is this pixel potentially a note?
		if(valIn.data.range(23, 16) > 100 || valIn.data.range(7, 0) > 100 || valIn.data.range(15, 8) > 100) {
			isNote = 1;
		}

		ap_int<1> verticalMatch[NUMBER_OF_NODELINES] = {0, 0, 0, 0, 0, 0, 0};
		for(int j = 0; j < NUMBER_OF_NODELINES; j++) {
#pragma HLS UNROLL

			if(enable.get_bit(j)) {
				// Is this pixel on the vertical line?
				if(columnCnt == pos[j]) {
					verticalMatch[j].set_bit(0, 1);
					drawBlue.set_bit(0, 1);
				}
			}

		}

		ap_int<1> horizontalMatch[NUMBER_OF_HORIZONTAL_LINES] = {0, 0};
		// Is this pixel on the horizontal line?
		if(enable.get_bit(7)) {
			for(int j = 0; j < NUMBER_OF_HORIZONTAL_LINES; j++) {
#pragma HLS UNROLL
				if(rowCnt == horizontalPos[j]) {
					drawBlue.set_bit(0, 1);
					horizontalMatch[j].set_bit(0, 1);
				}
			}
		}

		for(int hor = 0; hor < NUMBER_OF_HORIZONTAL_LINES; hor++) {
			for(int vert = 0; vert < NUMBER_OF_NODELINES; vert++) {
				if(verticalMatch[vert].get_bit(0) && horizontalMatch[hor].get_bit(0))
				{
					out[hor].set_bit(vert, isNote);
				}
			}
		}

		if(drawBlue.get_bit(0)) {
			valOut.data = 0x00FF00;
		}
		else {
			valOut.data = valIn.data;
		}

		// End Of Line
		if(valIn.last == 1) {
			columnCnt = 0;
			rowCnt++;
		}
		else {
			columnCnt++;
		}

		valOut.keep = valIn.keep;
		valOut.strb = valIn.strb;
		valOut.user = valIn.user;
		valOut.last = valIn.last;
		valOut.id = valIn.id;
		valOut.dest = valIn.dest;

		outStream.write(valOut);
	}
}

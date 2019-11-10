#include <hls_stream.h>
#include <ap_axi_sdata.h>

#define NUMBER_OF_NODELINES 7
#define NUMBER_OF_HORIZONTAL_LINES 2
#define ENABLED(x) ((enable >> (x + 1)) & 0x1)
#define ENABLED_HOR (enable & 0x1)

#define RED(x) ((x >> 16) & 0xFF)
#define GREEN(x) ((x >> 0) & 0xFF)
#define BLUE(x) ((x >> 8) & 0xFF)

#define DETECTION(x) if(RED(valIn.data) > 100 || GREEN(valIn.data) > 100 || BLUE(valIn.data) > 100) a |= (0x1 << x); else a &= (~(0x1 << x));

typedef ap_axiu<24,2,5,6> intSdCh;

void nodeDetector(hls::stream<intSdCh> &inStream, hls::stream<intSdCh> &outStream, ap_int<NUMBER_OF_NODELINES+1> enable,
		ap_int<16> pos[NUMBER_OF_NODELINES], ap_int<NUMBER_OF_NODELINES> out[NUMBER_OF_HORIZONTAL_LINES], ap_int<16> horizontalPos[NUMBER_OF_HORIZONTAL_LINES])
{
#pragma HLS ARRAY_PARTITION variable=out complete dim=1
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream
#pragma HLS INTERFACE s_axilite port=pos bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=enable bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=horizontalPos bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE ap_ctrl_none port=return bundle=CTRL_BUS
#pragma HLS INTERFACE ap_none port=out
#pragma HLS ARRAY_PARTITION variable=pos complete dim=1
#pragma HLS ARRAY_PARTITION variable=horizontalPos complete dim=1

	ap_int<32> pixelCnt = 0;
	ap_int<16> rowCnt = 0;
	ap_int<16> columnCnt = 0;

	nodeDetector_pipelining:for(int i = 0; i < (720*1280); i++) {
//#pragma HLS PIPELINE

		ap_int<1> drawBlue = 0;
		ap_int<1> horizontalMatch = 0;
		ap_int<1> isNote = 0;
		ap_int<1> horizontalIndex = 0;
		ap_int<NUMBER_OF_NODELINES> detectionOut[NUMBER_OF_HORIZONTAL_LINES] = {0, 0};
		//detectionOut[0] = out[0];

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

		// Is this pixel on the horizontal line?
		if(enable.get_bit(7)) {
			for(int j = 0; j < NUMBER_OF_HORIZONTAL_LINES; j++) {
				if(rowCnt == horizontalPos[j]) {
					horizontalIndex.set_bit(0, j);
					drawBlue.set_bit(0, 1);
					horizontalMatch.set_bit(0, 1);
				}
			}
		}

		for(int j = 0; j < NUMBER_OF_NODELINES; j++) {
			ap_int<1> verticalMatch = 0;
			if(enable.get_bit(j)) {
				// Is this pixel on the vertical line?
				if(columnCnt == pos[j]) {
					verticalMatch.set_bit(0, 1);
					drawBlue.set_bit(0, 1);
				}
			}
			if(verticalMatch && horizontalMatch)
			{
				detectionOut[horizontalIndex].set_bit(j, isNote);
			}
		}

		if(drawBlue) {
			valOut.data = 0x00FF00;
		}
		else {
			valOut.data = valIn.data;
		}

		out[0] = detectionOut[0];
		out[1] = detectionOut[1];

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

#include <hls_stream.h>
#include <ap_axi_sdata.h>

#define NUMBER_OF_NODELINES 7
#define ENABLED(x) ((enable >> (x + 1)) & 0x1)
#define ENABLED_HOR (enable & 0x1)

#define RED(x) ((x >> 16) & 0xFF)
#define GREEN(x) ((x >> 0) & 0xFF)
#define BLUE(x) ((x >> 8) & 0xFF)

#define DETECTION(x) if(RED(valIn.data) > 100 || GREEN(valIn.data) > 100 || BLUE(valIn.data) > 100) a |= (0x1 << x); else a &= (~(0x1 << x));

typedef ap_axiu<24,2,5,6> intSdCh;

void nodeDetector(hls::stream<intSdCh> &inStream, hls::stream<intSdCh> &outStream, ap_int<NUMBER_OF_NODELINES+1> enable,
		ap_int<16> pos[NUMBER_OF_NODELINES], ap_int<1> out[NUMBER_OF_NODELINES], ap_int<1> out2[NUMBER_OF_NODELINES], ap_int<16> horizontalPos)
{
#pragma HLS ARRAY_PARTITION variable=out complete dim=1
#pragma HLS ARRAY_PARTITION variable=out2 complete dim=1
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream
#pragma HLS INTERFACE s_axilite port=pos bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=enable bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=horizontalPos bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE ap_ctrl_none port=return bundle=CTRL_BUS
#pragma HLS INTERFACE ap_none port=out
#pragma HLS INTERFACE ap_none port=out2
#pragma HLS ARRAY_PARTITION variable=pos complete dim=1

	int pixelCnt = 0;
	int rowCnt = 0;
	int columnCnt = 0;

	static bool detections[NUMBER_OF_NODELINES] = {0,0,0,0,0,0,0};
	static bool detections2[NUMBER_OF_NODELINES] = {0,0,0,0,0,0,0};

	for(int i = 0; i < (720*1280); i++) {
//#pragma HLS PIPELINE

		intSdCh valIn = inStream.read();
		intSdCh valOut;

		// Start Of Frame
		if(valIn.user == 1) {
			pixelCnt = 0;
			columnCnt = 0;
			rowCnt = 0;
		}
		else {
			pixelCnt++;
		}

		// Logic
		if((ENABLED(0) && columnCnt == pos[0]) || (ENABLED(1) && columnCnt == pos[1]) || (ENABLED(2) && columnCnt == pos[2]) || (ENABLED(3) && columnCnt == pos[3]) || (ENABLED(4) && columnCnt == pos[4]) || (ENABLED(5) && columnCnt == pos[5]) || (ENABLED(6) && columnCnt == pos[6]))
					valOut.data = 0x00FF00;
		else if((ENABLED_HOR && (rowCnt == horizontalPos)) || (ENABLED_HOR && (rowCnt == horizontalPos + 1)) ) {
			valOut.data = 0x00FF00;
		}
		else
		{
			valOut.data = valIn.data;
		}

		for(int j = 0; j < NUMBER_OF_NODELINES; j++) {
			if(ENABLED(j)) {
				if(rowCnt == horizontalPos && columnCnt == pos[j])
				{
					if(RED(valIn.data) > 100 || GREEN(valIn.data) > 100 || BLUE(valIn.data) > 100) {
						detections[j] = 1;
					}
					else
					{
						detections[j] = 0;
					}
				}
			}
			else {
				detections[j] = 0;
			}
			out[j] = detections[j];
		}

		for(int j = 0; j < NUMBER_OF_NODELINES; j++) {
			if(ENABLED(j)) {
				if((rowCnt == (horizontalPos + 1)) && columnCnt == pos[j])
				{
					if(RED(valIn.data) > 100 || GREEN(valIn.data) > 100 || BLUE(valIn.data) > 100) {
						detections2[j] = 1;
					}
					else
					{
						detections2[j] = 0;
					}
				}
			}
			else {
				detections2[j] = 0;
			}
			out2[j] = detections2[j];
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

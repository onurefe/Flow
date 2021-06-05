/* -*- C -*- */

#include "demodulation.h"

quint0_16_t SineTable[] = {
	0x0,    0x101,  0x203,  0x304,  0x405,  0x507,  0x608,  0x709,  0x80b, 
0x90c,  0xa0d,  0xb0e,  0xc0f,  0xd10,  0xe11,  0xf12,  0x1013,         
0x1114,         0x1215,         0x1315,         0x1416,         0x1516,         0x1617,         0x1717,         0x1817,         
0x1918,         0x1a18,         0x1b18,         0x1c17,         0x1d17,         0x1e17,         0x1f16,         0x2016,         
0x2115,         0x2214,         0x2313,         0x2412,         0x2511,         0x260f,         0x270e,         0x280c,         
0x290a,         0x2a08,         0x2b06,         0x2c03,         0x2d01,         0x2dfe,         0x2efb,         0x2ff8,         
0x30f5,         0x31f1,         0x32ee,         0x33ea,         0x34e6,         0x35e1,         0x36dd,         0x37d8,         
0x38d3,         0x39ce,         0x3ac8,         0x3bc3,         0x3cbd,         0x3db7,         0x3eb0,         0x3faa,         
0x40a3,         0x419c,         0x4295,         0x438d,         0x4485,         0x457d,         0x4674,         0x476c,         
0x4863,         0x4959,         0x4a50,         0x4b46,         0x4c3c,         0x4d31,         0x4e27,         0x4f1b,         
0x5010,         0x5104,         0x51f8,         0x52ec,         0x53df,         0x54d2,         0x55c5,         0x56b7,         
0x57a9,         0x589b,         0x598c,         0x5a7d,         0x5b6e,         0x5c5e,         0x5d4e,         0x5e3d,         
0x5f2c,         0x601b,         0x6109,         0x61f7,         0x62e5,         0x63d2,         0x64bf,         0x65ab,         
0x6697,         0x6783,         0x686e,         0x6959,         0x6a43,         0x6b2d,         0x6c16,         0x6cff,         
0x6de8,         0x6ed0,         0x6fb8,         0x709f,         0x7186,         0x726d,         0x7353,         0x7438,         
0x751d,         0x7602,         0x76e6,         0x77ca,         0x78ad,         0x7990,         0x7a72,         0x7b54,         
0x7c35,         0x7d16,         0x7df6,         0x7ed6,         0x7fb5,         0x8094,         0x8172,         0x8250,         
0x832d,         0x840a,         0x84e6,         0x85c2,         0x869d,         0x8778,         0x8852,         0x892b,         
0x8a04,         0x8add,         0x8bb5,         0x8c8c,         0x8d63,         0x8e39,         0x8f0f,         0x8fe4,         
0x90b9,         0x918d,         0x9260,         0x9333,         0x9405,         0x94d7,         0x95a8,         0x9679,         
0x9748,         0x9818,         0x98e6,         0x99b5,         0x9a82,         0x9b4f,         0x9c1b,         0x9ce7,         
0x9db2,         0x9e7c,         0x9f46,         0xa00f,         0xa0d8,         0xa1a0,         0xa267,         0xa32e,         
0xa3f4,         0xa4b9,         0xa57e,         0xa642,         0xa705,         0xa7c8,         0xa88a,         0xa94b,         
0xaa0c,         0xaacc,         0xab8b,         0xac4a,         0xad08,         0xadc5,         0xae82,         0xaf3e,         
0xaff9,         0xb0b4,         0xb16d,         0xb227,         0xb2df,         0xb397,         0xb44e,         0xb504,         
0xb5ba,         0xb66f,         0xb723,         0xb7d6,         0xb889,         0xb93b,         0xb9ec,         0xba9d,         
0xbb4d,         0xbbfc,         0xbcaa,         0xbd58,         0xbe05,         0xbeb1,         0xbf5c,         0xc007,         
0xc0b0,         0xc159,         0xc202,         0xc2a9,         0xc350,         0xc3f6,         0xc49b,         0xc540,         
0xc5e3,         0xc686,         0xc728,         0xc7ca,         0xc86a,         0xc90a,         0xc9a9,         0xca47,         
0xcae4,         0xcb81,         0xcc1c,         0xccb7,         0xcd51,         0xcdeb,         0xce83,         0xcf1b,         
0xcfb2,         0xd048,         0xd0dd,         0xd171,         0xd205,         0xd298,         0xd32a,         0xd3bb,         
0xd44b,         0xd4da,         0xd569,         0xd5f7,         0xd684,         0xd710,         0xd79b,         0xd825,         
0xd8af,         0xd937,         0xd9bf,         0xda46,         0xdacc,         0xdb51,         0xdbd5,         0xdc59,         
0xdcdb,         0xdd5d,         0xddde,         0xde5e,         0xdedd,         0xdf5b,         0xdfd8,         0xe055,         
0xe0d0,         0xe14b,         0xe1c5,         0xe23e,         0xe2b6,         0xe32d,         0xe3a3,         0xe418,         
0xe48c,         0xe500,         0xe573,         0xe5e4,         0xe655,         0xe6c5,         0xe734,         0xe7a2,         
0xe80f,         0xe87b,         0xe8e6,         0xe951,         0xe9ba,         0xea23,         0xea8a,         0xeaf1,         
0xeb57,         0xebbc,         0xec1f,         0xec82,         0xece4,         0xed46,         0xeda6,         0xee05,         
0xee63,         0xeec0,         0xef1d,         0xef78,         0xefd3,         0xf02c,         0xf085,         0xf0dd,         
0xf133,         0xf189,         0xf1de,         0xf232,         0xf285,         0xf2d7,         0xf327,         0xf377,         
0xf3c7,         0xf415,         0xf462,         0xf4ae,         0xf4f9,         0xf543,         0xf58d,         0xf5d5,         
0xf61c,         0xf663,         0xf6a8,         0xf6ec,         0xf730,         0xf772,         0xf7b4,         0xf7f4,         
0xf834,         0xf872,         0xf8b0,         0xf8ec,         0xf928,         0xf962,         0xf99c,         0xf9d5,         
0xfa0c,         0xfa43,         0xfa79,         0xfaad,         0xfae1,         0xfb14,         0xfb45,         0xfb76,         
0xfba6,         0xfbd5,         0xfc02,         0xfc2f,         0xfc5b,         0xfc86,         0xfcaf,         0xfcd8,         
0xfd00,         0xfd27,         0xfd4c,         0xfd71,         0xfd95,         0xfdb8,         0xfdd9,         0xfdfa,         
0xfe1a,         0xfe39,         0xfe56,         0xfe73,         0xfe8f,         0xfeaa,         0xfec3,         0xfedc,         
0xfef4,         0xff0b,         0xff20,         0xff35,         0xff49,         0xff5b,         0xff6d,         0xff7e,         
0xff8d,         0xff9c,         0xffaa,         0xffb6,         0xffc2,         0xffcc,         0xffd6,         0xffdf,         
0xffe6,         0xffed,         0xfff2,         0xfff7,         0xfffa,         0xfffd,         0xfffe,         0xffff};

void getHalfHarmonics(uint16_t *adcBuffer, Bool_t secondHalf, float *m0Real, float *m0Img, float *m1Real, float *m1Img)
{
	qint0_31_t qm0_real = 0;
	qint0_31_t qm0_img = 0;
	qint0_31_t qm1_real = 0;
	qint0_31_t qm1_img = 0;

	uint16_t quarter_period_samples = SAMPLES_PER_MEASUREMENT >> 2;
	quint0_16_t sine, cosine;
	uint16_t sidx = 0;

	do
	{
		// For i element of 4N.
		sine = SineTable[sidx];
		cosine = SineTable[quarter_period_samples - sidx];

		qm0_real += adcBuffer[sidx];
		qm0_real += adcBuffer[sidx + quarter_period_samples];

		qm1_real += ((uint32_t)adcBuffer[sidx] * cosine) >> 7;
		qm1_img -= ((uint32_t)adcBuffer[sidx] * sine) >> 7;

		qm1_real -= ((uint32_t)adcBuffer[sidx + quarter_period_samples] * sine) >> 7;
		qm1_img -= ((uint32_t)adcBuffer[sidx + quarter_period_samples] * cosine) >> 7;
		sidx++;

		// For i element of 4N+1
		sine = SineTable[sidx];
		cosine = SineTable[quarter_period_samples - sidx];

		qm0_img -= adcBuffer[sidx];
		qm0_img -= adcBuffer[sidx + quarter_period_samples];

		qm1_real -= ((uint32_t)adcBuffer[sidx] * sine) >> 7;
		qm1_img -= ((uint32_t)adcBuffer[sidx] * cosine) >> 7;

		qm1_real -= ((uint32_t)adcBuffer[sidx + quarter_period_samples] * cosine) >> 7;
		qm1_img += ((uint32_t)adcBuffer[sidx + quarter_period_samples] * sine) >> 7;
		sidx++;

		// For i element of 4N+2
		sine = SineTable[sidx];
		cosine = SineTable[quarter_period_samples - sidx];

		qm0_real -= adcBuffer[sidx];
		qm0_real -= adcBuffer[sidx + quarter_period_samples];

		qm1_real -= ((uint32_t)adcBuffer[sidx] * cosine) >> 7;
		qm1_img += ((uint32_t)adcBuffer[sidx] * sine) >> 7;

		qm1_real += ((uint32_t)adcBuffer[sidx + quarter_period_samples] * sine) >> 7;
		qm1_img += ((uint32_t)adcBuffer[sidx + quarter_period_samples] * cosine) >> 7;
		sidx++;

		// For i element of 4N+3
		sine = SineTable[sidx];
		cosine = SineTable[quarter_period_samples - sidx];

		qm0_img += adcBuffer[sidx];
		qm0_img += adcBuffer[sidx + quarter_period_samples];

		qm1_real += ((uint32_t)adcBuffer[sidx] * sine) >> 7;
		qm1_img += ((uint32_t)adcBuffer[sidx] * cosine) >> 7;

		qm1_real += ((uint32_t)adcBuffer[sidx + quarter_period_samples] * cosine) >> 7;
		qm1_img -= ((uint32_t)adcBuffer[sidx + quarter_period_samples] * sine) >> 7;
		sidx++;
	} while (sidx < quarter_period_samples);

	// Invert sign if at second half period.
	if (secondHalf)
	{
		qm1_real = -qm1_real;
		qm1_img = -qm1_img;
	}
	
	// Set return value.
	float m0_real, m0_img, m1_real, m1_img;
	*m0Real = ((float)qm0_real) / ((1 << 12) * SAMPLES_PER_MEASUREMENT);
	*m0Img = ((float)qm0_img) / ((1 << 12) * SAMPLES_PER_MEASUREMENT);
	*m1Real = ((float)qm1_real) / ((1 << 20) * SAMPLES_PER_MEASUREMENT);
	*m1Img = ((float)qm1_img) / ((1 << 20) * SAMPLES_PER_MEASUREMENT);	
}
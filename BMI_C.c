#include "BMI_C.h"
unsigned char reverseBit8u(unsigned char value) {
	unsigned char result = 0;
	//result |= (value >> 7) & 1;
	//result |= (value >> 5) & 2;
	//result |= (value >> 3) & 4;
	//result |= (value >> 1) & 8;
	//result |= (value << 1) & 16;
	//result |= (value << 3) & 32;
	//result |= (value << 5) & 64;
	//result |= (value << 7) & 128;
	for (unsigned int i = 0; i < 4; i++) {
		result |= (value >> (7 - (2 * i)))& (1 << i);
		result |= (value << ((2 * i) + 1)) & (16 << i);
	}
	return result;
}
unsigned int reverseBit32u(unsigned int value) {
	unsigned int result = 0;
	for (unsigned int i = 0; i < 16; i++) {
		result |= (value >> (31 - (2 * i)))& (1 << i);
		result |= (value << ((2 * i) + 1)) & (65536 << i);
	}
	return result;
}

void printfBit8u(unsigned char value) {
	unsigned char b0 = value & 1;
	unsigned char b1 = (value >> 1) & 1;
	unsigned char b2 = (value >> 2) & 1;
	unsigned char b3 = (value >> 3) & 1;
	unsigned char b4 = (value >> 4) & 1;
	unsigned char b5 = (value >> 5) & 1;
	unsigned char b6 = (value >> 6) & 1;
	unsigned char b7 = (value >> 7);
	printf("%d%d%d%d%d%d%d%d\n", b7, b6, b5, b4, b3, b2, b1, b0);
}
void printfBit32u(unsigned int value) {
	unsigned char b0 = value & 1, b8 = (value >> 8) & 1, b16 = (value >> 16) & 1, b24 = (value >> 24) & 1;
	unsigned char b1 = (value >> 1) & 1, b9 = (value >> 9) & 1, b17 = (value >> 17) & 1, b25 = (value >> 25) & 1;
	unsigned char b2 = (value >> 2) & 1, b10 = (value >> 10) & 1, b18 = (value >> 18) & 1, b26 = (value >> 26) & 1;
	unsigned char b3 = (value >> 3) & 1, b11 = (value >> 11) & 1, b19 = (value >> 19) & 1, b27 = (value >> 27) & 1;
	unsigned char b4 = (value >> 4) & 1, b12 = (value >> 12) & 1, b20 = (value >> 20) & 1, b28 = (value >> 28) & 1;
	unsigned char b5 = (value >> 5) & 1, b13 = (value >> 13) & 1, b21 = (value >> 21) & 1, b29 = (value >> 29) & 1;
	unsigned char b6 = (value >> 6) & 1, b14 = (value >> 14) & 1, b22 = (value >> 22) & 1, b30 = (value >> 30) & 1;
	unsigned char b7 = (value >> 7) & 1, b15 = (value >> 15) & 1, b23 = (value >> 23) & 1, b31 = (value >> 31) & 1;
	printf("%d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d\n",
		b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6,
		b5, b4, b3, b2, b1, b0);
}
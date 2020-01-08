#include "DataEncryptionStandard.h"
#define ROLB28(value, shift) (((value << shift) & 0xFFFFFFF) | (value >> (28 - shift)))

#define S_DES {{14,  	4, 	13, 	1,  	2, 	15, 	11, 	8, 	3, 	10, 	6, 	12, 	5, 	9, 	0, 	7,\
0, 	15, 	7, 	4, 	14, 	2, 	13, 	1,  	10, 	6, 	12, 	11, 	9, 	5, 	3, 	8,\
4, 	1,  	14, 	8, 	13, 	6, 	2, 	11, 	15, 	12, 	9, 	7, 	3, 	10, 	5, 	0,\
15, 	12, 	8, 	2, 	4, 	9, 	1,  	7, 	5, 	11, 	3, 	14, 	10, 	0, 	6, 	13 },\
{15,  	1,  	8, 	14, 	6, 	11, 	3, 	4, 	9, 	7, 	2, 	13, 	12, 	0, 	5, 	10,\
3, 	13, 	4, 	7, 	15, 	2, 	8, 	14, 	12, 	0, 	1,  	10, 	6, 	9, 	11, 	5,\
0, 	14,	7, 	11, 	10, 	4, 	13, 	1,  	5, 	8, 	12, 	6, 	9, 	3, 	2, 	15,\
13, 	8, 	10, 	1,  	3, 	15, 	4, 	2, 	11, 	6, 	7, 	12, 	0, 	5, 	14, 	9 },\
{10, 	0, 	9, 	14, 	6, 	3, 	15, 	5, 	1,  	13, 	12, 	7, 	11, 	4, 	2, 	8,\
13, 	7, 	0, 	9, 	3, 	4, 	6, 	10, 	2, 	8, 	5, 	14, 	12, 	11, 	15, 	1,\
13, 	6, 	4, 	9, 	8, 	15, 	3, 	0, 	11, 	1,  	2, 	12, 	5, 	10, 	14, 	7,\
1,  	10, 	13, 	0, 	6, 	9, 	8, 	7, 	4, 	15, 	14, 	3, 	11, 	5, 	2, 	12 },\
{7, 	13, 	14,	3, 	0, 	6, 	9, 	10, 	1,  	2, 	8, 	5, 	11, 	12, 	4, 	15,\
13, 	8, 	11, 	5, 	6, 	15, 	0, 	3, 	4, 	7, 	2, 	12, 	1,  	10, 	14, 	9,\
10, 	6, 	9, 	0, 	12, 	11, 	7, 	13, 	15, 	1,  	3, 	14, 	5, 	2, 	8, 	4,\
3, 	15, 	0, 	6, 	10, 	1,  	13, 	8, 	9, 	4, 	5, 	11, 	12, 	7, 	2, 	14 },\
{2, 	12, 	4, 	1,  	7, 	10,	11, 	6, 	8, 	5, 	3, 	15, 	13, 	0, 	14, 	9,\
14, 	11, 	2, 	12, 	4, 	7, 	13, 	1,  	5, 	0, 	15, 	10, 	3, 	9, 	8, 	6,\
4, 	2, 	1,  	11, 	10, 	13, 	7, 	8, 	15, 	9, 	12, 	5, 	6, 	3, 	0, 	14,\
11, 	8, 	12, 	7, 	1,  	14, 	2, 	13, 	6, 	15, 	0, 	9, 	10, 	4, 	5, 	3},\
{12,  1,		10, 	15, 	9, 	2, 	6, 	8, 	0, 	13, 	3, 	4, 	14, 	7, 	5, 	11,\
10, 	15, 	4, 	2, 	7, 	12, 	9, 	5, 	6, 	1,  	13, 	14, 	0, 	11, 	3, 	8,\
9, 	14, 	15, 	5, 	2, 	8, 	12, 	3, 	7, 	0, 	4, 	10, 	1,  	13, 	11, 	6,\
4, 	3, 	2, 	12, 	9, 	5, 	15, 	10, 	11, 	14, 	1,  	7, 	6, 	0, 	8, 	13},\
{4, 	11, 	2, 	14, 	15, 	0, 	8, 	13, 	3, 	12, 	9, 	7, 	5, 	10, 	6, 	1,\
13, 	0, 	11, 	7, 	4, 	9, 	1,  	10, 	14, 	3, 	5, 	12, 	2, 	15, 	8, 	6,\
1,  	4, 	11, 	13, 	12, 	3, 	7, 	14, 	10, 	15, 	6, 	8, 	0, 	5, 	9, 	2,\
6, 	11, 	13, 	8, 	1,  	4, 	10, 	7, 	9, 	5, 	0, 	15, 	14, 	2, 	3, 	12},\
{13,	2, 	8, 	4, 	6, 	15,  	11, 	1,  	10, 	9, 	3, 	14, 	5, 	0, 	12, 	7,\
1,  	15, 	13, 	8, 	10, 	3, 	7, 	4, 	12, 	5, 	6, 	11, 	0, 	14, 	9, 	2,\
7, 	11, 	4, 	1,  	9, 	12, 	14, 	2, 	0, 	6, 	10, 	13, 	15, 	3, 	5, 	8,\
2, 	1,  	14, 	7, 	4, 	10, 	8, 	13, 	15, 	12, 	9, 	0, 	3, 	5, 	6, 	11 } };
//inline void reverseBit(uint64_t* number) {
//	for (size_t i = 0; i < 32; i++) {
//		uint64_t leftValue = (*number >> (31 + i)) & 1;
//		uint64_t rightValue = (*number >> i) & 1;
//		*number ^= leftValue ^ rightValue;
//	}
//}
inline uint64_t getBit(uint64_t number, uint8_t shift) {
	return (number >> shift) & 1;
}
inline void printBinary(uint64_t number, uint8_t numberBits) {
	printf("\n");
	for (size_t i = 0; i < numberBits; i++) {
		if (i % 8 == 0)
			printf(" ");
		printf("%lld", getBit(number, numberBits - 1 - i));
	}
}
inline uint64_t reverseBit(uint64_t number) {
	uint64_t result = 0;
	for (size_t i = 0; i < 64; i++) {
		result ^= ((number >> (63 - i)) & 1) << i;
	}
	return result;
}
inline uint64_t parity8ByteValue(uint64_t value) {
	for (uint8_t i = 0; i < 8; i++) {
		uint64_t numberBit = 0;
		for (uint8_t j = 0; j < 8; j++) {
			numberBit += ((value >> (i * 8)) >> j) & 1;
		}
		numberBit = (numberBit % 2) + 1;
		value ^= numberBit << (i * 8 + 7);
	}
	return value;
}
inline uint64_t combine(uint64_t leftValue, uint64_t rightValue, uint8_t border) {
	return (leftValue << border) | rightValue;
}
inline uint64_t permute(uint64_t key, uint8_t* permuteTable, uint8_t sizePermuteTable) {
	uint64_t result = 0;
	for (uint8_t i = 0; i < sizePermuteTable; i++) {
		uint8_t shift = permuteTable[i];
		result ^= ((key >> shift) & 1) << i;
	}
	return result;
}
inline void splitNumber(uint64_t value, uint8_t numberBitValue, uint8_t border, uint64_t* right, uint64_t* left) {
	*left = ((value << (64 - numberBitValue)) >> ((64 - numberBitValue) + border));
	*right = (value << (64 - numberBitValue + border)) >> (64 - numberBitValue + border);
}
inline uint32_t functionFeistel(uint32_t data, uint64_t key) {
	uint32_t result = 0;
	uint64_t vectorE = 0;
	uint8_t bitBlocks[8] = { 0,0,0,0,0,0,0,0 };
	uint8_t E[] = {
		31, 	0, 	1, 	2, 	3, 	4,
		3, 	4, 	5, 	6, 	7, 	8,
		7, 	8, 	9, 	10, 	11, 	12,
		11, 	12, 	13,	14, 	15, 	16,
		15, 	16, 	17, 	18, 	19, 	20,
		19, 	20, 	21, 	22, 	23, 	24,
		23, 	24, 	25, 	26, 	27, 	28,
		27, 	28, 	29, 	30, 	31, 	0
	};
	//uint8_t P[] = { 16, 	7, 	20, 	21, 	29, 	12, 	28, 	17,
	//	1, 	15, 	23, 	26, 	5, 	18, 	31, 	10,
	//	2, 	8, 	24, 	14, 	32, 	27, 	3, 	9,
	//	19, 	13, 	30, 	6, 	22, 	11, 	4, 	25 };
	uint8_t P[] = { 7, 28, 21, 10, 26, 2, 19, 13, 23, 29, 5, 0, 18, 8, 24, 30, 22, 1, 14, 27, 6, 9, 17, 31, 15, 4, 20, 3, 11, 12, 25, 16 };
	uint8_t S[8][64] = S_DES;
	vectorE = permute(data, E, sizeof(E));
	vectorE ^= key;
	for (size_t i = 0, k = 0; i < sizeof(bitBlocks); i++) {
		for (size_t j = 0; j < 6; j++) {
			bitBlocks[i] ^= ((vectorE >> k) & 1) << j;
			k++;
		}
	}
	for (size_t i = 0; i < sizeof(bitBlocks); i++) {
		uint8_t a = ((bitBlocks[i] >> 4) & 2) | (bitBlocks[i] & 1);
		uint8_t b = (bitBlocks[i] >> 1) & 15;
		uint32_t value = S[sizeof(bitBlocks) - 1 - i][a * 16 + b];
		result ^= value << (i * 4);
	}
	result = permute(result, P, sizeof(P));
	return result;
}

inline void initBlocks(uint8_t* input, size_t lengthInput, uint64_t** blocks, size_t* numberBlocks)
{
	if (input && blocks && numberBlocks) {
		size_t lengthAdd = lengthInput % 8 ? (8 - lengthInput % 8) : 0;
		size_t lengthData = lengthInput + lengthAdd;
		*numberBlocks = lengthData / 8;
		*blocks = (uint64_t*)calloc(1, lengthData);
		if (*blocks) {
			memcpy(*blocks, input, lengthInput);
			//memset(*blocks + lengthInput, '#', lengthAdd);
		}
	}
}

inline void keyGeneration(uint64_t RoundKeys[16], uint64_t key) {
	uint8_t  parityBitDropTable[] = { 60,52,44,36,59,51,43,35,27,19,11,3,58,50,42,34,26,18,10,2,57,49,41,33,25,17,9,1,28,20,12,4,61,53,45,37,29,21,13,5,62,54,46,38,30,22,14,6,63,55,47,39,31,23,15,7 };
	uint8_t shift[] = { 1,	1,	2,	2, 	2, 	2, 	2, 	2, 	1,	2, 	2, 	2 ,	2, 	2 ,	2 ,	1 };
	//uint8_t keyCompressionTable[] = { 42,39,45,32,55,51,53,28,41,50,35,46,33,37,44,52,30,48,40,49,29,36,43,54,15,4,25,19,9,1,26,16,5,11,23,8,12,7,17,0,22,3,10,14,6,20,27,24 };
	uint8_t keyCompressionTable[] = { 24, 27, 20, 6, 14, 10, 3, 22, 0, 17, 7, 12, 8, 23, 11, 5, 16, 26, 1, 9, 19, 25, 4, 15, 54, 43, 36, 29, 49, 40, 48, 30, 52, 44, 37, 33, 46, 35, 50, 41, 28, 53, 51, 55, 32, 45, 39, 42 };
	uint64_t preRoundKey = 0;
	uint64_t leftKey = 0;
	uint64_t rightKey = 0;
	uint64_t parityKey = parity8ByteValue(key);
	//key = reverseBit(parityKey);

	uint64_t cipherKey = permute(key, parityBitDropTable, sizeof(parityBitDropTable));
	splitNumber(cipherKey, 56, 28, &rightKey, &leftKey);
	for (size_t j = 0; j < sizeof(shift); j++) {
		rightKey = ROLB28(rightKey, shift[j]);
		leftKey = ROLB28(leftKey, shift[j]);
		preRoundKey = combine(leftKey, rightKey, 28);
		RoundKeys[j] = permute(preRoundKey, keyCompressionTable, sizeof(keyCompressionTable));
		//printBinary(RoundKeys[j], 64);
	}
}

inline uint64_t initPermutationIP(uint64_t data) {
	uint64_t result = 0;
	const uint8_t initIP[] = { 57,  49,  41,  33,  25,  17,  9,  1,
		59,  51,  43,  35,  27,  19,  11, 03,
		61,  53,  45,  37,  29,  21,  13,  05,
		63,  55,  47,  39,  31,  23,  15,  7,
		56,  48,  40,  32,  24,  16,  8,  0,
		58,  50,  42,  34,  26,  18,  10,  2,
		60,  52,  44,  36,  28,  20,  12,  4,
		62,  54,  46,  38,  30,  22,  14,  6 };
	//uint8_t initIP[] = { 6,14,22,30,38,46,54,62,4,12,20,28,36,44,52,60,2,10,18,26,34,42,50,58,0,8,16,24,32,40,48,56,7,15,23,31,39,47,55,63,5,13,21,29,37,45,53,61,3,11,19,27,35,43,51,59,1,9,17,25,33,41,49,57 };
	//for (size_t i = 0; i < 64; i++) {
	//	printf("%d,", 63 - initIP[i]);
	//}
	for (size_t i = 0; i < sizeof(initIP); i++) {
		result ^= ((data >> initIP[i]) & 1) << i;
	}
	return result;
}

inline uint64_t reversePermutationIP(uint64_t data) {
	uint64_t result = 0;
	//const uint8_t ip[] = { 40,  8,  48,  16, 56,  24, 64,  32,
	//	39 , 07,  47,  15,  55,  23,  63,  31,
	//	38,  6,  46,  14,  54,  22,  62,  30,
	//	37,  05,  45,  13,  53,  21,  61,  29,
	//	36,  04,  44,  12,  52,  20,  60,  28,
	//	35,  03,  43,  11,  51,  19,  59,  27,
	//	34,  02,  42,  10,  50,  18,  58,  26,
	//	33,  01,  41,  9,  49,  17,  57, 25 };
	uint8_t ip[] = { 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48, 16, 56, 24 };
	//for (size_t i = 0; i < sizeof(ip); i++)
	//	printf("%d,", ip[i] - 1);
	return permute(data, ip, sizeof(ip));
}
inline uint64_t EncryptionCycles(uint64_t data, uint64_t key[16]) {
	uint32_t R0 = ((uint32_t*)&data)[0];
	uint32_t L0 = ((uint32_t*)&data)[1];
	for (size_t i = 0; i < 16; i++) {
		uint32_t L = R0;
		uint32_t R = L0 ^ functionFeistel(R0, key[i]);
		R0 = R;
		L0 = L;
	}
	return ((uint64_t)R0 << 32) + (uint64_t)L0;
}

inline uint64_t DecryptionCycles(uint64_t data, uint64_t key[16]) {
	uint32_t R0 = ((uint32_t*)&data)[0];
	uint32_t L0 = ((uint32_t*)&data)[1];
	for (size_t i = 0; i < 16; i++) {
		uint32_t L = R0;
		uint32_t R = L0 ^ functionFeistel(R0, key[15 - i]);
		R0 = R;
		L0 = L;
	}
	return ((uint64_t)R0 << 32) + (uint64_t)L0;
}

struct DESinfo DataEncryptionStandardEncrypt(uint8_t* data, size_t lengthData, uint64_t key) {
	struct DESinfo cryptData = { 0 };
	uint64_t keys[16];
	keyGeneration(keys, key);
	initBlocks(data, lengthData, &cryptData.blocks, &cryptData.numberBlocks);
	if (cryptData.blocks) {
		for (size_t i = 0; i < cryptData.numberBlocks; i++) {
			uint64_t startValue = initPermutationIP(cryptData.blocks[i]);
			startValue = EncryptionCycles(startValue, keys);
			cryptData.blocks[i] = reversePermutationIP(startValue);
		}
	}
	return cryptData;
}

void DataEncryptionStandardDecrypt(struct DESinfo* data, uint64_t key) {
	uint64_t keys[16];
	keyGeneration(keys, key);
	if (data->blocks) {
		for (size_t i = 0; i < data->numberBlocks; i++) {
			uint64_t startValue = initPermutationIP(data->blocks[i]);
			startValue = DecryptionCycles(startValue, keys);
			data->blocks[i] = reversePermutationIP(startValue);
		}
	}
}
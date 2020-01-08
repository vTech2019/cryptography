#include "CRC32.h"

unsigned int crc32_u8(unsigned int crc, unsigned char v) {
	uint8_t tmp_1 = reverseBit8u(v);
	printfBit8u(tmp_1);
	printfBit8u(v);
	uint32_t tmp2 = reverseBit32u(crc);
	printfBit32u(crc);
	printfBit32u(tmp2);
	int c = 0;
}
uint32_t CRC32_Hash(uint8_t* data, size_t lengthData)
{
	uint32_t crc = 0xFFFFFFFF;
	for (size_t index = 0; index < lengthData; index++)
		crc = crc32_u8(crc, data[index]);
	crc ^= 0xFFFFFFFF;
	return crc;
}
uint32_t CRC32_HW_Hash(uint8_t* data, size_t lengthData) {
	uint32_t crc = 0xFFFFFFFF;
	for (size_t index = 0; index < lengthData; index++)
		crc = _mm_crc32_u8(crc, data[index]);
	crc ^= 0xFFFFFFFF;
	return crc;
}

uint32_t CRC64_HW_Hash(uint64_t data) {
	uint64_t crc = 0xFFFFFFFFFFFFFFFF;
	crc = _mm_crc32_u64(crc, data);
	crc ^= 0xFFFFFFFFFFFFFFFF;
	return crc;
}


size_t CRC32BirthdayParadox(size_t numberSymbols) {
	uint64_t* data = (uint64_t*)malloc(numberSymbols * sizeof(uint64_t));
	uint64_t* output = (uint64_t*)malloc(numberSymbols * sizeof(uint64_t));
	uint32_t *ptrData = (uint32_t*)data;
	uint32_t value; 

	CRC32_Hash(data, 1);

	for (size_t i = 0; i < numberSymbols; i++) {
		_rdrand64_step(&data[i]);
		for (size_t j = 0; j < i; j++) {
			if (data[i] == data[j]) {
				_rdrand64_step(&data[i]);
				j = 0;
			}
		}
	}
	for (size_t i = 0; i < numberSymbols; i++) {
		output[i] = CRC64_HW_Hash(data[i]);
	}
	gnomeSortU64(output, numberSymbols, data, 8);
	for (size_t i = 0; i < numberSymbols; i++) {
		//printf("%u \n", output[i]);
		if (output[i] == output[i + 1]) {
			//printf("Collision! %d %d %d\n", output[i], data[i], data[i + 1]);
			free(data);
			free(output);
			return 1;
		}
	}
	free(data);
	free(output);
	return 0;
}

void createHistogramCRC32BirthdayParadox(size_t numberValues, size_t stepNumberSymbols, size_t numberIterations, size_t maximumHistSymbols) {
	size_t* hist = (size_t*)calloc(numberValues, sizeof(size_t));
	ptrdiff_t i = 0;
//#pragma omp parallel for
	for (i = 0; i < numberValues; i++) {
		for (size_t j = 0; j < numberIterations; j++) {
			hist[i] += CRC32BirthdayParadox(i * stepNumberSymbols);
		}
	}
	size_t max = 0;
	for (size_t i = 0; i < numberValues; i++) {
		if (max < hist[i])
			max = hist[i];
	}
	if (max)
	for (size_t i = 0; i < numberValues; i++) {
		printf("\n");
		printf("%zd :", hist[i]);
		size_t size = maximumHistSymbols * ((double)hist[i] / max);
		for (size_t j = 0; j < size; j++)
			printf("#");
	}
	if (hist)free(hist);
}
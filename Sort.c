#include "Sort.h"


void gnomeSortU8(uint8_t* array, size_t length, uint8_t* data, size_t length_block) {
	for (size_t i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) {
			for (size_t k = 0; k < length_block; k++) {
				uint8_t tmp = data[i * length_block + k];
				data[i * length_block + k] = data[(i + 1) * length_block + k];
				data[(i + 1) * length_block + k] = tmp;
			}
			uint8_t tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i -= i == 0 ? 0 : 2;
		}
	}
}

void gnomeSortU64(uint64_t* array, size_t length, uint8_t* data, size_t length_block) {
	if (length)
	for (size_t i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) {
			size_t k = 0;
			for (; k + 7 < length_block; k+=8) {
				uint64_t tmp = *((uint64_t*)&data[i * length_block + k]);
				*((uint64_t*)&data[i * length_block + k]) = *((uint64_t*)&data[(i + 1) * length_block + k]);
				*((uint64_t*)&data[(i + 1) * length_block + k]) = tmp;
			}
			for (; k < length_block; k++) {
				uint8_t tmp = data[i * length_block + k];
				data[i * length_block + k] = data[(i + 1) * length_block + k];
				data[(i + 1) * length_block + k] = tmp;
			}
			uint64_t tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i -= i == 0 ? 0 : 2;
		}
	}
}

void gnomeSortU32(uint32_t* array, size_t length, uint8_t* data, size_t length_block) {
	for (size_t i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) {
			for (size_t k = 0; k < length_block; k++) {
				uint8_t tmp = data[i * length_block + k];
				data[i * length_block + k] = data[(i + 1) * length_block + k];
				data[(i + 1) * length_block + k] = tmp;
			}
			uint32_t tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i -= i == 0 ? 0 : 2;
		}
	}
}
void gnomeSortU16(uint16_t* array, size_t length, uint8_t* data, size_t length_block) {
	for (size_t i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) {
			for (size_t k = 0; k < length_block; k++) {
				uint8_t tmp = data[i * length_block + k];
				data[i * length_block + k] = data[(i + 1) * length_block + k];
				data[(i + 1) * length_block + k] = tmp;
			}
			uint16_t tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i -= i == 0 ? 0 : 2;
		}
	}
}

void gnomeSortSZ(size_t* array, size_t length, uint8_t* data, size_t length_block) {
	for (size_t i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) {
			for (size_t k = 0; k < length_block; k++) {
				uint8_t tmp = data[i * length_block + k];
				data[i * length_block + k] = data[(i + 1) * length_block + k];
				data[(i + 1) * length_block + k] = tmp;
			}
			size_t tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i -= i == 0 ? 0 : 2;
		}
	}
}

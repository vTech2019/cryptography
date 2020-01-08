#include "RivestCipher4.h"

size_t get_bit(size_t number, uint8_t shift)
{
	return (number >> shift) & 1;
}

void set_bit(uint8_t* value, uint8_t number, uint8_t shift)
{
	*value ^= (number & 1) << shift;
}

uint8_t get_random(uint8_t* S_box, size_t* i, size_t* j) {
	*i = (*i + 1) & 255;
	const size_t s_data = S_box[*i];
	*j = (*j + s_data) & 255;
	S_box[*i] = S_box[*j];
	S_box[*j] = s_data;
	const size_t index = ((size_t)S_box[*i] + S_box[*j]) & 255;
	return S_box[index];
}

void RivestCipher4Encrypt(uint8_t* data, size_t lengthData, uint8_t* key, size_t keyLength)
{
	uint8_t S_box[256];
	size_t i = 0;
	size_t j = 0;
	for (size_t i = 0; i < 256; i++)
		S_box[i] = i;
	for (size_t i = 0, index = 0; i < 256; i++) {
		size_t temp = S_box[i];
		index = (index + key[i % keyLength] + temp) & 255;
		S_box[i] = S_box[index];
		S_box[index] = temp;
	}
	if (data) {
		for (ptrdiff_t index = 0; index < lengthData; index++) {
			uint8_t crypt_xor = get_random(S_box, &i, &j);
			data[index] = data[index] ^ crypt_xor;
		}
	}
}
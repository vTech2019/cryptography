
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include "RSA.h"
uint32_t simpleNumber(uint64_t number) {
	if (number == 0)
		return 0;
	for (uint64_t i = 2; i < number; i++)
	{
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}
uint64_t EulerFunction(uint64_t x0, uint64_t x1) {
	return (x0 - 1) * (x1 - 1);
}
uint64_t EuclideanAlgorithm(uint64_t number_0, uint64_t number_1) {
	size_t max_tmp = number_0 < number_1 ? number_1 : number_0;
	size_t min_tmp = number_1 < number_0 ? number_1 : number_0;
	size_t number_2 = 1;
	while (number_2) {
		size_t i = max_tmp / min_tmp;
		number_2 = max_tmp - (i * min_tmp);
		max_tmp = min_tmp;
		min_tmp = number_2;
	}
	return max_tmp;
}
int64_t ExEuclideanAlgorithm(int64_t a, int64_t b, int64_t* x, int64_t* y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t d = ExEuclideanAlgorithm(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return d;
}

int64_t invModule(int64_t a, int64_t m) {
	int64_t x, y;
	ExEuclideanAlgorithm(a, m, &x, &y);
	x = (x % m + m) % m;
	return x;
}

void genKeys(struct RSA_data* data) {
	srand(0);
	while (!simpleNumber(data->publicKey)) {
		data->publicKey = 0;
		data->publicKey |= (uint64_t)rand();
		data->publicKey |= (uint64_t)rand() << 16;
		data->publicKey |= (uint64_t)rand() << 32;
		data->publicKey |= (uint64_t)rand() << 48;

		data->publicKey %= 2048;///////////////////////
		//data->publicKey = UINT64_MAX * (float)rand() / RAND_MAX;
	}
	while (!simpleNumber(data->secretKey)) {
		data->secretKey = 0;
		data->secretKey |= (uint64_t)rand();
		data->secretKey |= (uint64_t)rand() << 16;
		data->secretKey |= (uint64_t)rand() << 32;
		data->secretKey |= (uint64_t)rand() << 48;

		data->secretKey %= 2048;///////////////////////////
	}
	//data->publicKey = 3557;
	//data->secretKey = 2579;

	data->n = data->secretKey * data->publicKey;
	uint64_t e_number = EulerFunction(data->publicKey, data->secretKey);
	uint64_t exp = 4;
	while (!simpleNumber(exp)) {
		exp = 0;
		exp |= (uint64_t)rand();
		exp |= (uint64_t)rand() << 16;
		exp |= (uint64_t)rand() << 32;
		exp |= (uint64_t)rand() << 48;

		exp %= 128; /////////////////////////////
	}
	//exp = 3;
	//uint64_t value = EuclideanAlgorithm(exp, e_number);   
	uint64_t secret_exp = invModule(exp, e_number);
	//uint64_t secret_exp = (uint64_t)(1.0 / exp) % e_number;
	data->publicKey = exp;
	data->secretKey = secret_exp;
}

uint8_t* cryptRSA(uint8_t* text, size_t lengthText, struct RSA_data* data) {
	uint8_t* text_cipher = (uint8_t*)malloc(lengthText);
	uint64_t cipher = 0;
	for (size_t i = 0; i < lengthText; i++) {
		cipher |= (uint64_t)text[i] << i * 8;
	}
	struct BigInteger cipherBigInteger = initBigInteger64U(cipher);
	struct BigInteger publicKeyBigInteger = initBigInteger64U(data->publicKey);
	struct BigInteger cipherValue = powBigInteger(&cipherBigInteger, &publicKeyBigInteger);
	freeBigInteger(&cipherBigInteger);
	freeBigInteger(&publicKeyBigInteger);

	cipher = ((uint64_t)pow(cipher, data->publicKey)) % data->n;
	for (size_t i = 0; i < lengthText; i++) {
		text_cipher[i] = (cipher >> i * 8) & 255;
	}
	return text_cipher;
}
uint8_t* decryptRSA(uint8_t* cipher, size_t lengthText, struct RSA_data* data) {
	uint8_t* text_decrypt = (uint8_t*)malloc(lengthText);
	uint64_t text = 0;
	for (size_t i = 0; i < lengthText; i++) {
		text |= (uint64_t)cipher[i] << i * 8;
	}
	//double value = pow(text, data->secretKey);  //ERROR INF
	text = ((uint64_t)pow(text, data->secretKey)) % data->n;
	for (size_t i = 0; i < lengthText; i++) {
		text_decrypt[i] = (text >> i * 8) & 255;
	}
	return text_decrypt;
}

void testRSA() {
	struct RSA_data data;
	genKeys(&data);
	uint8_t text[] = { "ok!" };
	uint8_t* cryptData = cryptRSA(text, sizeof(text), &data);
	uint8_t* decryptData = decryptRSA(cryptData, sizeof(text), &data);
	if (cryptData) free(cryptData);
	if (decryptData) free(decryptData);
}
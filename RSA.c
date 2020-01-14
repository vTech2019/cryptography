#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include "RSA.h"
uint32_t primeNumber(uint64_t number) {
	if (number < 2)
		return 0;
	const uint64_t end = sqrt(number);
	;

	for (uint64_t i = 2; i <= end; i++) 
		if (number % i == 0)
			return 0;

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
	srand(time(0));
	while (!primeNumber(data->publicKey)) {
		data->publicKey = 0;
		data->publicKey |= (uint64_t)rand();
		data->publicKey |= (uint64_t)rand() << 16;
		data->publicKey |= (uint64_t)rand() << 32;
		data->publicKey |= (uint64_t)rand() << 48;

		//data->publicKey %= 2048;///////////////////////
	}
	while (!primeNumber(data->secretKey)) {
		data->secretKey = 0;
		data->secretKey |= (uint64_t)rand();
		data->secretKey |= (uint64_t)rand() << 16;
		data->secretKey |= (uint64_t)rand() << 32;
		data->secretKey |= (uint64_t)rand() << 48;

		//data->secretKey %= 2048;///////////////////////////
	}

	data->n = data->secretKey * data->publicKey;
	uint64_t e_number = EulerFunction(data->publicKey, data->secretKey);
	uint64_t exp = 4;
	while (!primeNumber(exp)) {
		exp = 0;
		exp |= (uint64_t)rand();
		exp |= (uint64_t)rand() << 16;
		exp |= (uint64_t)rand() << 32;
		exp |= (uint64_t)rand() << 48;

		//exp %= 128; /////////////////////////////
	}
	//uint64_t value = EuclideanAlgorithm(exp, e_number);
	uint64_t secret_exp = invModule(exp, e_number);
	data->publicKey = exp;
	data->secretKey = secret_exp;
}

struct BigInteger cryptRSA(uint8_t* text, size_t lengthText, struct RSA_data* data) {
	struct BigInteger remainderCipherValue = { 0 };
	uint8_t* numberText = (uint8_t*)malloc(3 * lengthText);
	if (numberText) {
		size_t j = 0;
		for (size_t i = 0; i < lengthText; i++) {
			uint8_t value_0 = (text[i] / 100) % 10;
			uint8_t value_1 = (text[i] / 10) % 10;
			uint8_t value_2 = (text[i] / 1) % 10;
			if (value_0 != 0) {
				numberText[j++] = value_0 + '0';
				numberText[j++] = value_1 + '0';
			}
			else if (value_1 != 0) {
				numberText[j++] = value_1 + '0';
			}
			numberText[j++] = value_2 + '0';
		}

		struct BigInteger cipherBigInteger = initBigInteger8U(numberText, j);
		struct BigInteger nBigInteger = initBigInteger64U(data->n);
		struct BigInteger publicKeyBigInteger = initBigInteger64U(data->publicKey);
		//struct BigInteger cipherValue_0 = powBigInteger(&cipherBigInteger, &publicKeyBigInteger);
		struct BigInteger cipherValue = fastPowBigInteger(&cipherBigInteger, &publicKeyBigInteger);

		struct BigInteger result = divideBigIntegerPPP(&cipherValue, &nBigInteger, &remainderCipherValue);

		freeBigInteger(&cipherBigInteger);
		freeBigInteger(&nBigInteger);
		freeBigInteger(&publicKeyBigInteger);
		freeBigInteger(&cipherValue);
		freeBigInteger(&result);
		free(numberText);
		return remainderCipherValue;
	}
	return remainderCipherValue;
}
uint8_t* decryptRSA(struct BigInteger* cipher, struct RSA_data* data) {
	struct BigInteger decryptBigInteger = initBigInteger(cipher);
	struct BigInteger secretKeyBigInteger = initBigInteger64U(data->secretKey);
	struct BigInteger nBigInteger = initBigInteger64U(data->n);
	struct BigInteger remainderCipherValue = { 0 };
	struct BigInteger cipherValue = fastPowBigInteger(&decryptBigInteger, &secretKeyBigInteger);
	struct BigInteger result = divideBigIntegerPPP(&cipherValue, &nBigInteger, &remainderCipherValue);
	freeBigInteger(&decryptBigInteger);
	freeBigInteger(&secretKeyBigInteger);
	freeBigInteger(&nBigInteger);
	freeBigInteger(&cipherValue);
	freeBigInteger(&result);
	return remainderCipherValue.value;
}

void testRSA() { 
	struct RSA_data data;
	//genKeys(&data);
	data.n = 9173503; //test https://ru.wikipedia.org/wiki/RSA
	data.publicKey = 3;
	data.secretKey = 6111579;
	uint8_t text[] = { 1,1,1,1,1,1,0 };
	struct BigInteger cryptData = cryptRSA(text, sizeof(text) - 1, &data);
	uint8_t* decryptData = decryptRSA(&cryptData, &data);
	printf("text : %s\n", text);
	printf("crypt : %s\n", cryptData);
	printf("decrypt : %s\n", decryptData);
	freeBigInteger(&cryptData);
	if (decryptData) free(decryptData);
}
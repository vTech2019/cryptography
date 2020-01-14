#include <stdint.h>
#include "BigInteger.h"
struct RSA_data {
	uint64_t publicKey;
	uint64_t secretKey;
	uint64_t n;
};
#ifndef __RSA__
#define __RSA__

void genKeys(struct RSA_data* data);
uint8_t* decryptRSA(struct BigInteger* cipher, struct RSA_data* data);
struct BigInteger cryptRSA(uint8_t* text, size_t lengthText, struct RSA_data* data);

void testRSA();
#endif
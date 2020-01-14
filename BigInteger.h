
#include <stdint.h>


#ifndef __BIGINTEGER__
#define __BIGINTEGER__
#define __TEST_BIGINTEGER__
struct BigInteger {
	uint32_t* value;
	size_t numberValue;
	int8_t sign;
};

struct BigInteger initBigInteger(struct BigInteger* value);
struct BigInteger initBigInteger8U(uint8_t* value, size_t lengthValue);
struct BigInteger initBigInteger64U(uint64_t value);
int8_t compareBigInteger(struct BigInteger* leftValue, struct BigInteger* rightValue);

void decBigInteger(struct BigInteger* value);
void incBigInteger(struct BigInteger* value);
uint8_t notNullBigInteger(struct BigInteger* value);
void addBigInteger(struct BigInteger* left, struct BigInteger* right, struct BigInteger* result);
void subtractBigInteger(struct BigInteger* left, struct BigInteger* right, struct BigInteger* result);

void multiplyBigInteger(struct BigInteger* left, struct BigInteger* right, struct BigInteger* result);

void freeBigInteger(struct BigInteger* value);
void printConsoleBigInteger(struct BigInteger* value);

struct BigInteger fastPowBigInteger(struct BigInteger* value, struct BigInteger* exp);
struct BigInteger powBigInteger(struct BigInteger* value, struct BigInteger* exp);

struct BigInteger divideBigIntegerP32U(struct BigInteger* numerator, unsigned int denominator, uint64_t* remainder);
struct BigInteger divideBigIntegerPPP(struct BigInteger* numerator, struct BigInteger* denominator, struct BigInteger* remainder);

#ifdef __TEST_BIGINTEGER__
void testConsoleBigInteger();
#endif

#endif 
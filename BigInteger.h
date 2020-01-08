
#include <stdint.h>


#ifndef __BIGINTEGER__
#define __BIGINTEGER__
struct BigInteger {
	uint64_t* value;
	size_t numberValue;
	int8_t sign;
};
struct BigInteger initBigInteger(struct BigInteger* value);
struct BigInteger initBigInteger8U(uint8_t* value, size_t lengthValue);
struct BigInteger initBigInteger64U(uint64_t value);
int8_t compareBigInteger(struct BigInteger* leftValue, struct BigInteger* rightValue);
uint64_t getNumberValuesBigInteger(struct BigInteger* value);
void decBigInteger(struct BigInteger* value);
void incBigInteger(struct BigInteger* value);
uint8_t notNullBigInteger(struct BigInteger* value);
struct BigInteger powBigInteger(struct BigInteger* value, struct BigInteger* exp);
struct BigInteger subtractBigInteger(struct BigInteger* left, struct BigInteger* right);
struct BigInteger multiplyBigInteger(struct BigInteger* value_0, struct BigInteger* value_1);
struct BigInteger divideBigInteger(struct BigInteger* numerator, struct BigInteger* denominator);
void freeBigInteger(struct BigInteger* value);
void printConsoleBigInteger(struct BigInteger* value);
#endif 
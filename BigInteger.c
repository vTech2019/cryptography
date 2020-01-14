#include "BigInteger.h"
#include <math.h>
#include <malloc.h>
#define UINT_NUM_BITS	(sizeof(unsigned int) * 8)

uint64_t stringToInteger64U(uint8_t* stringValue, size_t length, int8_t step) {
	uint64_t value = 0;
	for (size_t i = 0; i < length; i++) {
		uint64_t add = stringValue[i * step] - '0';
		for (size_t j = 0; j < i; j++)
			add *= 10;
		value += add;
	}
	return value;
}
uint32_t stringToInteger32U(uint8_t* stringValue, size_t length, int8_t step) {
	uint32_t value = 0;
	for (size_t i = 0; i < length; i++) {
		uint32_t add = stringValue[i * step] - '0';
		for (size_t j = 0; j < i; j++)
			add *= 10;
		value += add;
	}
	return value;
}
size_t deleteNULLBigInteger(struct BigInteger* value) {
	for (size_t i = 0; i < value->numberValue; i++) {
		if (value->value[value->numberValue - 1 - i] != 0ull) {
			value->numberValue -= i;
			value->value = (uint32_t*)realloc(value->value, value->numberValue * sizeof(uint32_t));
			break;
		}
	}
}
uint64_t pow10(uint64_t n) {
	uint64_t result = 1;
	for (uint64_t i = 1; i <= n; ++i)
		result *= 10;
	return result;
}
void initBigIntegerP8U(struct BigInteger* initInteger, uint8_t* value, size_t lengthValue) {
	if (value) {
		if (*value == '-')
			initInteger->sign = -1,
			lengthValue--,
			value++;
		else
			initInteger->sign = 1;
	}
	size_t length64U = lengthValue / 9;
	length64U += lengthValue % 9 ? 1 : 0;
	initInteger->numberValue = length64U;
	initInteger->value = (uint32_t*)realloc(initInteger->value, length64U * sizeof(uint32_t));
	if (initInteger->value == NULL) {
		initInteger->numberValue = 0;
		length64U = 0;
	}
	for (size_t i = 0, lengthNumber = 9, offsetNumber = 0; i < length64U; i++) {
		lengthNumber = (lengthValue - (length64U - 1 - i) * 9) > 9 ? 9 : (lengthValue - (length64U - 1 - i) * 9);
		initInteger->value[length64U - 1 - i] = stringToInteger32U(value + offsetNumber + lengthNumber - 1, lengthNumber, -1);
		offsetNumber += lengthNumber;
	}
}

struct BigInteger initBigInteger8U(uint8_t* value, size_t lengthValue) {
	struct BigInteger localInteger = { 0 };
	initBigIntegerP8U(&localInteger, value, lengthValue);
	return localInteger;
}

struct BigInteger initBigInteger64U(uint64_t value) {
	struct BigInteger localInteger = { 0 };
	localInteger.numberValue = 3;
	localInteger.value = (uint32_t*)malloc(3 * sizeof(uint32_t));
	localInteger.value[0] = value % 1000000000;
	localInteger.value[1] = (value / 1000000000) % 1000000000000000000;
	localInteger.value[2] = value / 1000000000000000000;
	localInteger.sign = 1;
	deleteNULLBigInteger(&localInteger);
	return localInteger;
}

struct BigInteger initBigInteger(struct BigInteger* value) {
	struct BigInteger localInteger = { 0 };
	localInteger.numberValue = value->numberValue;
	localInteger.value = (uint32_t*)malloc(value->numberValue * sizeof(uint32_t));
	if (localInteger.value == NULL)
		localInteger.numberValue = 0;
	for (size_t i = 0; i < value->numberValue; i++)
		localInteger.value[i] = value->value[i];
	localInteger.sign = value->sign;
	return localInteger;
}

void decBigInteger(struct BigInteger* value) {
	if (value->sign == 1)
		for (size_t i = 0; i < value->numberValue; i++) {
			if (value->value[i] > 0) {
				value->value[i]--;
				break;
			}
			else {
				value->value[i] = 999999999;
			}
		}
	else
		for (size_t i = 0; i < value->numberValue; i++) {
			if (value->value[i] != 999999999) {
				value->value[i]++;
				break;
			}
			else {
				value->value[i] = 0;
			}
		}
}

void incBigInteger(struct BigInteger* value) {
	value->sign *= -1;
	decBigInteger(value);
	value->sign *= -1;
}
//0 - NULL
//1 - not NULL
uint8_t notNullBigInteger(struct BigInteger* value)
{
	for (size_t i = 0; i < value->numberValue; i++)
		if (value->value[i] > 0)
			return 1;
	return 0;
}
//-1 left < right
//0 left == right
//1 left > right
int8_t compareBigInteger(struct BigInteger* leftValue, struct BigInteger* rightValue) {
	if ((int64_t)leftValue->sign * leftValue->numberValue < (int64_t)rightValue->sign * rightValue->numberValue)
		return -1;
	if ((int64_t)leftValue->sign * leftValue->numberValue > (int64_t)rightValue->sign* rightValue->numberValue)
		return 1;
	for (uint64_t i = leftValue->numberValue - 1; i != UINT64_MAX; i--) {
		if (leftValue->sign * leftValue->value[i] < rightValue->sign * rightValue->value[i]) {
			return -1;
		}
		else if (leftValue->sign * leftValue->value[i] > rightValue->sign* rightValue->value[i]) {
			return 1;
		}
	}
	return 0;
}

void addBigInteger(struct BigInteger* left, struct BigInteger* right, struct BigInteger* result) {
	right->sign *= -1;
	subtractBigInteger(left, right, result);
	right->sign *= -1;
}

void subtractBigInteger(struct BigInteger* left, struct BigInteger* right, struct BigInteger* result) {
	int8_t sLeft = left->sign;
	int8_t sRight = right->sign;
	left->sign = 1;
	right->sign = 1;
	if (compareBigInteger(left, right) == -1) {
		left->sign = sLeft;
		right->sign = sRight;
		subtractBigInteger(right, left, result);
		result->sign *= -1;
	}
	left->sign = sLeft;
	right->sign = sRight;
	*result = initBigInteger(left);
	int64_t carry = 0;
	for (size_t i = 0; i < right->numberValue; i++) {
		int64_t rightNumber = right->sign * (int64_t)right->value[i];
		int64_t leftNumber = result->sign * (int64_t)result->value[i];
		leftNumber = leftNumber - rightNumber - carry;
		carry = ((uint64_t)(result->sign * leftNumber) / 1000000000) > 0 ? result->sign : 0;
		result->value[i] = result->sign * (carry * 1000000000 + leftNumber);
	}
}

void multiplyBigInteger(struct BigInteger* left, struct BigInteger* right, struct BigInteger* result) {
	result->numberValue = left->numberValue + right->numberValue;
	result->value = (uint32_t*)realloc(result->value, result->numberValue * sizeof(uint32_t));
	right->value = (uint32_t*)realloc(right->value, result->numberValue * sizeof(uint32_t));
	if ((size_t)right->value & (size_t)result->value) {
		for (size_t i = 0; i < result->numberValue; i++)
			result->value[i] = 0;
		for (size_t i = right->numberValue; i < result->numberValue; i++)
			right->value[i] = 0;
		for (size_t i = 0; i < left->numberValue; i++) {
			uint64_t carry = 0;
			uint64_t value_0 = left->value[i];
			for (size_t j = 0; (j < right->numberValue) | (carry != 0); ++j) {
				uint64_t value_1 = right->value[j];
				uint64_t current = result->value[i + j];
				current += value_1 * value_0 + carry;
				carry = current / 1000000000;
				result->value[i + j] = current % 1000000000;
			}
		}
		right->numberValue = result->numberValue;
		deleteNULLBigInteger(right);
		deleteNULLBigInteger(result);
		result->sign = left->sign * right->sign;
	}
}

struct BigInteger multiplyBigIntegerPI(struct BigInteger* left, int32_t right) {
	struct BigInteger result = { 0 };
	result.numberValue = left->numberValue + 1;
	result.value = (uint32_t*)calloc(result.numberValue, sizeof(uint32_t));
	for (size_t i = 0; i < left->numberValue; i++) {
		uint64_t carry = 0;
		uint64_t value_0 = left->value[i];
		for (size_t j = 0; j < 1 || carry != 0; ++j) {
			uint64_t value_1 = j < 1 ? right : 0;
			uint64_t value_2 = result.value[i + j];
			uint64_t current = value_2 + value_1 * value_0 + carry;

			value_2 = current % 1000000000;
			carry = current / 1000000000;

			result.value[i + j] = value_2;
		}
	}
	deleteNULLBigInteger(&result);
	result.sign = left->sign * (right >= 0 ? 1 : -1);
	return result;
}

struct BigInteger divideBigIntegerP32U(struct BigInteger* numerator, unsigned int denominator, uint64_t* remainder) {
	struct BigInteger result = initBigInteger(numerator);
	if (denominator == 0 || denominator >= 1000000000)
		return result;
	uint64_t _carry = 0;
	for (size_t i = numerator->numberValue - 1; i != SIZE_MAX; --i) {
		uint64_t value = numerator->value[i] + _carry * 1000000000;
		result.value[i] = value / denominator;
		_carry = value % denominator;
	}
	*remainder = _carry;
	deleteNULLBigInteger(&result);
	return result;
}

void shiftRight(struct BigInteger* value) {
	value->numberValue++;
	value->value = realloc(value->value, value->numberValue * sizeof(uint32_t));
	for (size_t i = value->numberValue - 1; i > 0; i--)
		value->value[i] = value->value[i - 1];
	value->value[0] = 0;
}

uint64_t getNumberValuesBigInteger(struct BigInteger* value) {
	uint64_t result = 0;
	size_t i = value->numberValue - 1;
	for (; i != SIZE_MAX; i--) {
		uint32_t number = value->value[i];
		if (number != 0) {
			do {
				result += number > 0 ? 1 : 0;
				number /= 10;
			} while (number != 0);
			break;
		}
	}
	i = i == SIZE_MAX ? 0 : i;
	result += i * 9;
	return result;
}

uint8_t getNumericDigitBigInteger(struct BigInteger* value, size_t positionDigit) {
	uint64_t i = positionDigit / 9;
	uint64_t offset = positionDigit % 9;
	uint64_t div = pow10(offset);
	uint64_t data = value->value[i] / div;
	return data % 10;
}

void setNumericDigitBigInteger(struct BigInteger* value, size_t positionDigit, uint8_t digit) {
	uint64_t i = positionDigit / 9;
	uint64_t offset = positionDigit % 9;
	uint64_t div = pow10(offset);
	uint64_t null = (value->value[i] / div) % 10;
	offset = digit * div;
	value->value[i] -= null * div;
	value->value[i] += offset;
}
void shiftLeftAllNumericDigitBigInteger(struct BigInteger* value) {
	uint64_t numberDigits = getNumberValuesBigInteger(value);
	if (numberDigits == value->numberValue * 9) {
		value->numberValue++;
		value->value = (uint32_t*)realloc(value->value, value->numberValue * sizeof(uint32_t));
		value->value[value->numberValue - 1] = 0;
	}
	uint64_t carry = 0;
	for (size_t i = 0; i < value->numberValue; i++) {
		uint64_t current = value->value[i];
		current *= 10;
		current += carry;
		carry = current / 1000000000;
		value->value[i] = current % 1000000000;
	}
}

struct BigInteger divideBigIntegerPPP(struct BigInteger* numerator, struct BigInteger* denominator, struct BigInteger* remainder) {
	int8_t nSign = numerator->sign;
	int8_t dSign = denominator->sign;
	numerator->sign = 1;
	denominator->sign = 1;
	struct BigInteger result = { 0 };
	if (notNullBigInteger(denominator) == 0)
		return result;
	if (compareBigInteger(numerator, denominator) == -1)
		return result;
	struct BigInteger current = { 0 };
	current.numberValue = denominator->numberValue + 1;
	current.value = (uint32_t*)calloc(current.numberValue, sizeof(uint32_t));
	current.sign = 1;
	*remainder = initBigInteger(numerator);

	numerator->sign = nSign;
	denominator->sign = dSign;

	uint64_t numberDenominatorValues = getNumberValuesBigInteger(denominator);
	uint64_t numericDigitDenominator = denominator->value[denominator->numberValue - 1];
	for (uint8_t i = 0, end = numberDenominatorValues % 18 - 1; i < end; i++) {
		numericDigitDenominator /= 10ull;
	}
	uint64_t numberNumeratorValues = getNumberValuesBigInteger(remainder);
	uint64_t end = numberDenominatorValues;
	while (compareBigInteger(remainder, denominator) != -1) {
		uint64_t modifyArea = numberNumeratorValues - end;
		uint64_t numberSub = 0;
		for (size_t i = 0; i < end; i++) {
			setNumericDigitBigInteger(&current, end - i - 1, getNumericDigitBigInteger(remainder, numberNumeratorValues - 1 - i));
		}
		current.numberValue = (end / 9) + (end % 9 > 0 ? 1 : 0);

		struct BigInteger resultSub = { 0 };
		while (compareBigInteger(&current, denominator) != -1) {
			subtractBigInteger(&current, denominator, &resultSub);
			freeBigInteger(&current);
			current = resultSub;
			numberSub++;
		}
		uint64_t numberCurrentValues_1 = getNumberValuesBigInteger(&current);

		for (size_t i = 0; i < end; i++) {
			if (i < numberCurrentValues_1) {
				uint8_t digit = getNumericDigitBigInteger(&current, i);
				setNumericDigitBigInteger(remainder, modifyArea + i, digit);
			}
			else
				setNumericDigitBigInteger(remainder, modifyArea + i, 0);
		}
		end = numberCurrentValues_1;
		shiftLeftAllNumericDigitBigInteger(&result);
		setNumericDigitBigInteger(&result, 0, numberSub);
		deleteNULLBigInteger(remainder);
		numberNumeratorValues = modifyArea + end;
		end++;
	};
	freeBigInteger(&current);
	remainder->sign = numerator->sign * denominator->sign;
	result.sign = numerator->sign * denominator->sign;
	return result;
}

struct BigInteger fastPowBigInteger(struct BigInteger* value, struct BigInteger* exp) {
	struct BigInteger counter = initBigInteger(exp);
	struct BigInteger localValue = initBigInteger(value);
	struct BigInteger result = initBigInteger64U(1);
	struct BigInteger tmp_0 = { 0 };
	struct BigInteger tmp_1 = { 0 };
	struct BigInteger tmp_2 = { 0 };
	uint64_t remainder = 0;
	while (notNullBigInteger(&counter)) {
		tmp_0 = divideBigIntegerP32U(&counter, 2, &remainder);
		freeBigInteger(&counter);
		counter = tmp_0;
		tmp_0.value = 0;
		if (remainder) {
			multiplyBigInteger(&result, &localValue, &tmp_1);
			freeBigInteger(&result);
			result = tmp_1;
			tmp_1.value = 0;
		}
		multiplyBigInteger(&localValue, &localValue, &tmp_2);
		freeBigInteger(&localValue);
		localValue = tmp_2;
		tmp_2.value = 0;
	}
	freeBigInteger(&tmp_0);
	freeBigInteger(&tmp_1);
	freeBigInteger(&tmp_2);
	freeBigInteger(&counter);
	freeBigInteger(&localValue);
	return result;
}
struct BigInteger powBigInteger(struct BigInteger* value, struct BigInteger* exp) {
	struct BigInteger counter = initBigInteger(exp);
	struct BigInteger localValue = initBigInteger(value);
	struct BigInteger newPtrValue = { 0 };
	if (notNullBigInteger(&counter))
		decBigInteger(&counter);
	while (notNullBigInteger(&counter)) {
		multiplyBigInteger(&localValue, value, &newPtrValue);
		freeBigInteger(&localValue);
		localValue = newPtrValue;
		decBigInteger(&counter);
	}
	freeBigInteger(&counter);
	return localValue;
}
//struct BigInteger multiplyBigInteger(struct BigInteger* value_0, struct BigInteger* value_1) {
//	struct BigInteger result = { 0 };
//	size_t maxLength = 0;
//	size_t minLength = 0;
//	struct BigInteger* maxValue = NULL;
//	struct BigInteger* minValue = NULL;
//	if (value_0->numberValue > value_1->numberValue) {
//		maxLength = value_0->numberValue;
//		minLength = value_1->numberValue;
//		maxValue = value_0;
//		minValue = value_1;
//	}
//	else {
//		maxLength = value_1->numberValue;
//		minLength = value_0->numberValue;
//		maxValue = value_1;
//		minValue = value_0;
//	}
//	result.sign = value_0->sign * value_1->sign;
//	result.numberValue = maxLength + minLength;
//	result.value = (int64_t*)calloc(result.numberValue + 1, sizeof(uint64_t));
//	uint32_t* ptrValue = (uint32_t*)result.value;
//	for (size_t j = 0; j < minLength; j++) {
//		uint64_t lr_value_0[2] = { minValue->value[j] % (1'000'000'000ull),
//			minValue->value[j] / (1'000'000'000ull) };
//		for (size_t j_i = 0; j_i < 2; j_i++) {
//			for (size_t i = 0; i < maxLength; i++) {
//				uint64_t lr_value_1[2] = { maxValue->value[i] % (1'000'000'000),
//					maxValue->value[i] / (1'000'000'000) };
//				for (size_t i_j = 0; i_j < 2; i_j++) {
//					uint64_t resultValue = lr_value_0[j_i] * lr_value_1[i_j];
//					for (size_t local_j = 2 * (j + i) + j_i + i_j; local_j < 2 * (result.numberValue + 1) && resultValue; local_j++) {
//						uint64_t l_result = resultValue / 1'000'000'000ull;
//						uint64_t r_result = resultValue % 1'000'000'000ull;
//
//						uint64_t r_value = result.value[local_j / 2];
//						uint64_t l_value = result.value[(local_j + 2) / 2];
//						uint64_t lr_value_0 = 0;
//						uint64_t lr_value_1 = 0;
//						if (local_j % 2 == 0) {
//							lr_value_1 = l_value / 1'000'000'000ull;
//							lr_value_0 = l_value % 1'000'000'000ull;
//							l_value = r_value / 1'000'000'000ull;
//							r_value -= l_value * 1'000'000'000ull;
//						}
//						else {
//							lr_value_1 = r_value % 1'000'000'000ull;
//							lr_value_0 = l_value / 1'000'000'000ull;
//							r_value = r_value / 1'000'000'000ull;
//							l_value = l_value - (lr_value_0 * 1'000'000'000ull);
//						}
//
//						uint64_t r_copyValue = r_result + r_value;
//						uint64_t l_copyValue = l_result + l_value;
//						uint64_t r_largeValue = (r_copyValue / (1'000'000'000ull)) * 1'000'000'000ull;
//						l_copyValue += r_largeValue / 1'000'000'000ull;
//						uint64_t l_largeValue = (l_copyValue / (1'000'000'000ull)) * 1'000'000'000ull;
//						l_copyValue -= l_largeValue;
//						r_copyValue -= r_largeValue;
//
//						r_largeValue = l_largeValue / 1'000'000'000ull;
//						r_result = r_largeValue + lr_value_0;
//						l_largeValue = (r_result / (1'000'000'000ull)) * 1'000'000'000ull;
//						r_result -= l_largeValue;
//
//						if (local_j % 2 == 0) {
//							lr_value_1 *= 1'000'000'000ull;
//							l_copyValue *= 1'000'000'000ull;
//							result.value[local_j / 2] = l_copyValue + r_copyValue;
//							result.value[(local_j + 2) / 2] = lr_value_1 + r_result;
//						}
//						else {
//							r_copyValue *= 1'000'000'000ull;
//							r_result *= 1'000'000'000ull;
//							result.value[local_j / 2] = r_copyValue + lr_value_1;
//							result.value[(local_j + 2) / 2] = r_result + l_copyValue;
//						}
//						resultValue = l_largeValue / 1'000'000'000ull;
//					}
//					//printConsoleBigInteger(&result);
//				}
//			}
//		}
//	}
//	for (size_t i = 0; i < result.numberValue; i++) {
//		if (result.value[result.numberValue - 1 - i] != 0ull) {
//			result.numberValue -= i;
//			result.value = (int64_t*)realloc(result.value, result.numberValue * sizeof(uint64_t));
//			break;
//		}
//	}
//	return result;
//}

void printConsoleBigInteger(struct BigInteger* value) {
	if (value->sign == -1)
		printf("-");
	else
		printf("+");
	for (size_t i = value->numberValue - 1; i + 1 != 0; i--) {
		printf("%09u", value->value[i]);
	}
	printf("\n");
}

void freeBigInteger(struct BigInteger* value)
{
	if (value->value) {
		free(value->value);
		value->numberValue = 0;
		value->value = NULL;
	}
}

void testConsoleBigInteger() {
	struct BigInteger value_0 = initBigInteger8U("-45743734853763429873427693874693726983758609734697409687467834886348654865485486548", 84);
	struct BigInteger value_1 = initBigInteger8U("2566585685678678678934868", 25);
	printConsoleBigInteger(&value_0);
	printConsoleBigInteger(&value_1);

	struct BigInteger remainder = { 0 };
	struct BigInteger result_0 = divideBigIntegerPPP(&value_0, &value_1, &remainder);
	struct BigInteger result_1 = { 0 };
	struct BigInteger result_2 = { 0 };
	multiplyBigInteger(&result_0, &value_1, &result_1);
	addBigInteger(&result_1, &remainder, &result_2);
	printConsoleBigInteger(&result_0);
	printConsoleBigInteger(&result_1);
	printConsoleBigInteger(&result_2);
	printConsoleBigInteger(&remainder);
}
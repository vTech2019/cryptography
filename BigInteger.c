#include "BigInteger.h"
#include <math.h>
#include <malloc.h>
uint64_t stringToInteger64U(uint8_t* stringValue, size_t length, int8_t step) {
	uint64_t value = 0;
	for (ptrdiff_t i = 0; i < length; i++) {
		uint64_t add = stringValue[i * step] - '0';
		for (ptrdiff_t j = 0; j < i; j++)
			add *= 10;
		value += add;
	}
	return value;
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
	size_t length64U = lengthValue / 18;
	length64U += lengthValue % 18 ? 1 : 0;
	initInteger->numberValue = length64U;
	initInteger->value = (uint64_t*)realloc(initInteger->value, length64U * sizeof(uint64_t));
	if (initInteger->value == NULL) {
		initInteger->numberValue = 0;
		length64U = 0;
	}
	for (size_t i = 0, lengthNumber = 18, offsetNumber = 0; i < length64U; i++) {
		lengthNumber = (lengthValue - (length64U - 1 - i) * 18) > 18 ? 18 : (lengthValue - (length64U - 1 - i) * 18);
		initInteger->value[length64U - 1 - i] = stringToInteger64U(value + offsetNumber + lengthNumber - 1, lengthNumber, -1);
		offsetNumber += lengthNumber;
	}
}

struct BigInteger initBigInteger8U(uint8_t* value, size_t lengthValue) {
	struct BigInteger localInteger = { 0 };
	if (value) {
		if (*value == '-')
			localInteger.sign = -1,
			lengthValue--,
			value++;
		else
			localInteger.sign = 1;
	}
	size_t length64U = lengthValue / 18;
	length64U += lengthValue % 18 ? 1 : 0;
	localInteger.numberValue = length64U;
	localInteger.value = (uint64_t*)realloc(localInteger.value, length64U * sizeof(uint64_t));
	if (localInteger.value == NULL) {
		localInteger.numberValue = 0; 
		length64U = 0;
	}
	for (size_t i = 0, lengthNumber = 18, offsetNumber = 0; i < length64U; i++) {
		lengthNumber = (lengthValue - (length64U - 1 - i) * 18) > 18 ? 18 : (lengthValue - (length64U - 1 - i) * 18);
		localInteger.value[length64U - 1 - i] = stringToInteger64U(value + offsetNumber + lengthNumber - 1, lengthNumber, -1);
		offsetNumber += lengthNumber;
	}
	return localInteger;
}

struct BigInteger initBigInteger64U(uint64_t value) {
	struct BigInteger localInteger = { 0 };
	localInteger.numberValue = 1;
	localInteger.value = (uint64_t*)malloc(1 * sizeof(uint64_t));
	localInteger.value[0] = value;
	localInteger.sign = 1;
	return localInteger;
}

struct BigInteger initBigInteger(struct BigInteger* value) {
	struct BigInteger localInteger = { 0 };
	localInteger.numberValue = value->numberValue;
	localInteger.value = (uint64_t*)malloc(value->numberValue * sizeof(uint64_t)); 
	if (localInteger.value == NULL) 
		localInteger.numberValue = 0;
	for (size_t i = 0; i < value->numberValue; i++)
		localInteger.value[i] = value->value[i];
	localInteger.sign = value->sign;
	return localInteger;
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
//	result.numberValue = maxLength + minLength;
//	result.value = (int64_t*)calloc(result.numberValue + 1, sizeof(uint64_t));
//	for (size_t j = 0; j < minLength; j++) {
//		uint64_t l_value_0 = minValue->value[j] / (1'000'000'000ull);
//		uint64_t r_value_0 = minValue->value[j] - (l_value_0 * 1'000'000'000ull);
//		for (size_t i = 0; i < maxLength; i++) {
//			uint64_t l_value_1 = maxValue->value[i] / (1'000'000'000);
//			uint64_t r_value_1 = maxValue->value[i] - (l_value_1 * 1'000'000'000ull);
//			uint64_t l_result = l_value_0 * l_value_1;
//			uint64_t r_result = r_value_0 * r_value_1;
//			l_result += r_result / (1'000'000'000ull);
//			r_result -= (r_result / (1'000'000'000ull));
//			size_t largeValue = l_result > (1'000'000'000'000'000'000ull) ? (l_result / (1'000'000'000'000'000'000ull)) * 1'000'000'000'000'000'000ull : 0;
//			l_result -= largeValue;
//			uint64_t result_value = r_result + (l_result - (l_result / (1'000'000'000ull)))* (1'000'000'000ull);
//
//			for (size_t j = i, local_largeValue = 0; j < result.numberValue + 1 && result_value; j++) {
//				uint64_t copyValue = result.value[j] + result_value;
//				local_largeValue = copyValue > (1'000'000'000'000'000'000ull) ? (copyValue / (1'000'000'000'000'000'000ull)) * 1'000'000'000'000'000'000ull : 0;
//				copyValue -= local_largeValue;
//				result.value[j] = copyValue;
//				result_value = local_largeValue / 1'000'000'000'000'000'000ull;
//			}
//			result_value = l_result / (1'000'000'000ull) + (largeValue * (1'000'000'000ull));
//			for (size_t j = i + 1, local_largeValue = 0; j < result.numberValue && result_value; j++) {
//				uint64_t copyValue = result.value[j] + result_value;
//				local_largeValue = copyValue > (1'000'000'000'000'000'000ull) ? (copyValue / (1'000'000'000'000'000'000ull)) * 1'000'000'000'000'000'000ull : 0;
//				copyValue -= local_largeValue;
//				result.value[j] = copyValue;
//				result_value = local_largeValue / 1'000'000'000'000'000'000ull;
//			}
//			printConsoleBigInteger(&result);
//		}
//	}
//	return result;
//}

void decBigInteger(struct BigInteger* value) {
	if (value->sign == 1)
		for (size_t i = 0; i < value->numberValue; i++) {
			if (value->value[i] > 0) {
				value->value[i]--;
				break;
			}
			else {
				value->value[i] = 999'999'999'999'999'999ull;
			}
		}
	else
		for (size_t i = 0; i < value->numberValue; i++) {
			if (value->value[i] != 999'999'999'999'999'999ull) {
				value->value[i]++;
				break;
			}
			else {
				value->value[i] = 0ull;
			}
		}
}

void incBigInteger(struct BigInteger* value) {
	if (value->sign == -1)
		for (size_t i = 0; i < value->numberValue; i++) {
			if (value->value[i] > 0) {
				value->value[i]--;
				break;
			}
			else {
				value->value[i] = 999'999'999'999'999'999ull;
			}
		}
	else
		for (size_t i = 0; i < value->numberValue; i++) {
			if (value->value[i] != 999'999'999'999'999'999ull) {
				value->value[i]++;
				break;
			}
			else {
				value->value[i] = 0ull;
			}
		}
}
//0 - NULL
//1 - not NULL
uint8_t notNullBigInteger(struct BigInteger * value)
{
	for (size_t i = 0; i < value->numberValue; i++)
		if (value->value[i] > 0ull)
			return 1;
	return 0;
}
//-1 left < right
//0 left == right
//1 left > right
int8_t compareBigInteger(struct BigInteger* leftValue, struct BigInteger* rightValue) {
	if ((int64_t)leftValue->sign * leftValue->numberValue < (int64_t)rightValue->sign * rightValue->numberValue)
		return -1;
	if ((int64_t)leftValue->sign * leftValue->numberValue > (int64_t)rightValue->sign * rightValue->numberValue)
		return 1;
	int8_t result = 0;
	for (size_t i = 0; i < leftValue->numberValue; i++) {
		if (leftValue->sign * leftValue->value[i] < rightValue->sign *  rightValue->value[i]) {
			result = -1;
		}
		else if (leftValue->sign * leftValue->value[i] > rightValue->sign* rightValue->value[i]) {
			result = 1;
		}
		else
			result = 0;
	}
	return result;
}

void subAddBigInteger(struct BigInteger localResult, struct BigInteger localLeft, struct BigInteger localRight, int64_t signMul) {
	size_t maxLength = localLeft.numberValue > localRight.numberValue ? localLeft.numberValue : localRight.numberValue;
	for (size_t i = 0; i < maxLength; i++) {
		int64_t leftNumber = i < localLeft.numberValue ? localLeft.value[i] : 0;
		int64_t rightNumber = i < localRight.numberValue ? localRight.value[i] : 0;
		leftNumber *= localLeft.sign;
		rightNumber *= localRight.sign;
		rightNumber *= signMul;
		int64_t result = leftNumber + rightNumber;
		int64_t transfer = 0;
		if (leftNumber < 0 && rightNumber < 0) {
			if (result > -999'999'999'999'999'999) {
				transfer = result / 1'000'000'000'000'000'000ll;
				result -= transfer * 1'000'000'000'000'000'000ll;
			}
		}
		else if (leftNumber > 0 && rightNumber > 0) {
			if (result > 999'999'999'999'999'999) {
				transfer = result / 1'000'000'000'000'000'000ll;
				result -= transfer * 1'000'000'000'000'000'000ll;
			}
		}
		else if (leftNumber > 0 && rightNumber < 0) {
			if ((result % 1) < (leftNumber % 1)) {
				transfer = -1;
				result += 1'000'000'000'000'000'000ll;
			}
		}
		else if (leftNumber < 0 && rightNumber > 0) {
			if (result > 0) {
				transfer = result / 1'000'000'000'000'000'000ll;
				result -= transfer * 1'000'000'000'000'000'000ll;
			}
		}
		localResult.value[i] = result < 0 ? -result : result;
		for (size_t j = i + 1; j < localLeft.numberValue; j++) {
			int64_t result = localLeft.value[j];
			if (result != 0 && result < 999'999'999'999'999'999 || (result == 0 && transfer > 0) || (result == 999'999'999'999'999'999 && transfer < 0)) {
				result *= localLeft.sign;
				result += transfer;
				result *= localLeft.sign;
				localLeft.value[j] = result;
				break;
			}
			else if (result == 0 && transfer < 0) {
				result = 999'999'999'999'999'999ull;
			}
			else if (result == 999'999'999'999'999'999ull && transfer > 0) {
				result = 0;
			}
			localLeft.value[j] = (uint64_t)result;
		}
	}
}

struct BigInteger subtractBigInteger(struct BigInteger* left, struct BigInteger* right) {
	struct BigInteger localResult = { 0 };
	struct BigInteger localLeft = initBigInteger(left);
	struct BigInteger localRight = initBigInteger(right);
	size_t maxLength = left->numberValue > right->numberValue ? left->numberValue : right->numberValue;
	localResult.numberValue = maxLength;
	localResult.value = (uint64_t*)malloc(maxLength * sizeof(uint64_t));
	int8_t signLeft = localLeft.sign;
	int8_t signRight = localRight.sign;
	localLeft.sign = 1;
	localRight.sign = 1;
	if (compareBigInteger(&localLeft, &localRight) == -1) {
		localLeft.sign = signLeft;
		localRight.sign = signRight;
		subAddBigInteger(localResult, localRight, localLeft, -1);
		localResult.sign = -1 * signLeft;/////////////////////
	}
	else {
		localLeft.sign = signLeft;
		localRight.sign = signRight;
		subAddBigInteger(localResult, localLeft, localRight, -1);
		localResult.sign = 1 * signLeft;//////////////////////
	}
	freeBigInteger(&localLeft);
	freeBigInteger(&localRight);
	return localResult;
}

uint64_t pow10(uint64_t n) {
	uint64_t result = 1;
	for (uint64_t i = 1; i <= n; ++i)
		result *= 10;
	return result;
}

uint64_t getNumberValuesBigInteger(struct BigInteger* value) {
	uint64_t result = 0;
	for (size_t i = value->numberValue - 1; i != SIZE_MAX; i--) {
		uint64_t number = value->value[i];
		while (number != 0ull){
			result++;
			number /= 10ull;
		}
	}
	return result;
}
uint8_t getValueBigInteger(struct BigInteger* number, uint64_t offsetNumber) {
	if (offsetNumber < number->numberValue * 18) {
		uint64_t indexValue = offsetNumber / 18;
		uint64_t offsetValue = offsetNumber % 18;
		uint64_t value = number->value[indexValue] % (pow10(1 + offsetValue));
		if (offsetValue)
			value /= pow10(offsetValue);
		return (uint8_t)value;
	}
	return 0;
}

struct BigInteger divideBigInteger(struct BigInteger* numerator, struct BigInteger* denominator) {
	int8_t nSign = numerator->sign;
	int8_t dSign = denominator->sign;
	struct BigInteger result = { 0 };
	if (notNullBigInteger(denominator) == 0)
		return result;
	numerator->sign = 1;
	denominator->sign = 1;
	if (compareBigInteger(numerator, denominator) == -1)
		return result;
	struct BigInteger tmp = { 0 };
	struct BigInteger remainder = initBigInteger(numerator);
	struct BigInteger localNumerator = initBigInteger(numerator);
	struct BigInteger localDenominator = initBigInteger(denominator);

	numerator->sign = nSign;
	denominator->sign = dSign;

	uint64_t numberDenominatorValues = getNumberValuesBigInteger(&localDenominator);
	uint64_t numberNumeratorValues = getNumberValuesBigInteger(&localNumerator);
	uint64_t numericDigitDenominator = localDenominator.value[localDenominator.numberValue - 1];
	for (uint8_t i = 0, end = numberDenominatorValues % 18 - 1; i < end; i++) {
		numericDigitDenominator /= 10ull;
	}
	uint8_t* stringNumber = (uint8_t*)malloc( numberDenominatorValues * sizeof(uint8_t));
	if (stringNumber) {
		while (compareBigInteger(&remainder, &localDenominator) != -1) {
			for (size_t i = 0, flag = 0, end = numberDenominatorValues; i < end; i++) {
				uint8_t valueN = getValueBigInteger(&localNumerator, numberNumeratorValues - 1 - i) + '0';
				uint8_t valueD = getValueBigInteger(&localDenominator, numberDenominatorValues - 1 - i) + '0';
				stringNumber[i] = valueN;
				if (!flag)
					if (valueN < valueD)
						flag = 1,
						end++;
			}
			initBigIntegerP8U(&tmp, stringNumber, numberDenominatorValues);
			//printConsoleBigInteger(&tmp);


		}
		free(stringNumber);
	}
	freeBigInteger(&tmp);
	freeBigInteger(&localNumerator);
	freeBigInteger(&localDenominator);
	return result;
}

struct BigInteger powBigInteger(struct BigInteger* value, struct BigInteger* exp) {
	struct BigInteger counter = initBigInteger(exp);
	struct BigInteger localValue = initBigInteger(value);
	struct BigInteger newPtrValue = { 0 };
	if (notNullBigInteger(&counter))
		decBigInteger(&counter);
	while (notNullBigInteger(&counter)) {
		newPtrValue = multiplyBigInteger(&localValue, value);
		freeBigInteger(&localValue);
		localValue = newPtrValue;
		decBigInteger(&counter);
		//printConsoleBigInteger(&localValue);
	}
	freeBigInteger(&counter);
	//freeBigInteger(&newPtrValue);
	return localValue;
}

struct BigInteger multiplyBigInteger(struct BigInteger* value_0, struct BigInteger* value_1) {
	struct BigInteger result = { 0 };
	size_t maxLength = 0;
	size_t minLength = 0;
	struct BigInteger* maxValue = NULL;
	struct BigInteger* minValue = NULL;
	if (value_0->numberValue > value_1->numberValue) {
		maxLength = value_0->numberValue;
		minLength = value_1->numberValue;
		maxValue = value_0;
		minValue = value_1;
	}
	else {
		maxLength = value_1->numberValue;
		minLength = value_0->numberValue;
		maxValue = value_1;
		minValue = value_0;
	}
	result.numberValue = maxLength + minLength;
	result.value = (int64_t*)calloc(result.numberValue + 1, sizeof(uint64_t));
	uint32_t* ptrValue = (uint32_t*)result.value;
	for (size_t j = 0; j < minLength; j++) {
		uint64_t lr_value_0[2] = { minValue->value[j] - ((minValue->value[j] / (1'000'000'000ull)) * 1'000'000'000ull),
			minValue->value[j] / (1'000'000'000ull) };
		for (size_t j_i = 0; j_i < 2; j_i++) {
			for (size_t i = 0; i < maxLength; i++) {
				uint64_t lr_value_1[2] = { maxValue->value[i] - ((maxValue->value[i] / (1'000'000'000ull)) * 1'000'000'000ull),
					maxValue->value[i] / (1'000'000'000) };
				for (size_t i_j = 0; i_j < 2; i_j++) {
					uint64_t resultValue = lr_value_0[j_i] * lr_value_1[i_j];
					for (size_t local_j = 2 * (j + i) + j_i + i_j; local_j < 2 * (result.numberValue + 1) && resultValue; local_j++) {
						uint64_t l_result = resultValue / 1'000'000'000ull;
						uint64_t r_result = resultValue - (l_result * 1'000'000'000ull);

						uint64_t r_value = result.value[local_j / 2];
						uint64_t l_value = result.value[(local_j + 2) / 2];
						uint64_t lr_value_0 = 0;
						uint64_t lr_value_1 = 0;
						if (local_j % 2 == 0) {
							lr_value_1 = l_value / 1'000'000'000ull;
							lr_value_0 = l_value - (lr_value_1 * 1'000'000'000ull);
							l_value = r_value / 1'000'000'000ull;
							r_value -= l_value * 1'000'000'000ull;
						}
						else {
							lr_value_1 = r_value - ((r_value / 1'000'000'000ull) * 1'000'000'000ull);

							lr_value_0 = l_value / 1'000'000'000ull;
							r_value = r_value / 1'000'000'000ull;
							l_value = l_value - (lr_value_0 * 1'000'000'000ull);
						}

						uint64_t r_copyValue = r_result + r_value;
						uint64_t l_copyValue = l_result + l_value;
						uint64_t r_largeValue = r_copyValue >= (1'000'000'000ull) ? (r_copyValue / (1'000'000'000ull)) * 1'000'000'000ull : 0;
						l_copyValue += r_largeValue / 1'000'000'000ull;
						uint64_t l_largeValue = l_copyValue >= (1'000'000'000ull) ? (l_copyValue / (1'000'000'000ull)) * 1'000'000'000ull : 0;
						l_copyValue -= l_largeValue;
						r_copyValue -= r_largeValue;

						r_largeValue = l_largeValue / 1'000'000'000ull;
						r_result = r_largeValue + lr_value_0;
						l_largeValue = r_result >= (1'000'000'000ull) ? (r_result / (1'000'000'000ull)) * 1'000'000'000ull : 0;
						r_result -= l_largeValue;

						if (local_j % 2 == 0) {
							lr_value_1 *= 1'000'000'000ull;
							l_copyValue *= 1'000'000'000ull;
							result.value[local_j / 2] = l_copyValue + r_copyValue;
							result.value[(local_j + 2) / 2] = lr_value_1 + r_result;
						}
						else {
							r_copyValue *= 1'000'000'000ull;
							r_result *= 1'000'000'000ull;
							result.value[local_j / 2] = r_copyValue + lr_value_1;
							result.value[(local_j + 2) / 2] = r_result + l_copyValue;
						}
						resultValue = l_largeValue / 1'000'000'000ull;
					}
					//printConsoleBigInteger(&result);
				}
			}
		}
	}
	for (size_t i = 0; i < result.numberValue; i++) {
		if (result.value[result.numberValue - 1 - i] != 0ull) {
			result.numberValue -= i;
			result.value = (int64_t*)realloc(result.value, result.numberValue * sizeof(uint64_t));
			break;
		}
	}
	return result;
}

void printConsoleBigInteger(struct BigInteger* value) {
		if (value->sign == -1)
			printf("-");
	for (size_t i = value->numberValue - 1; i + 1 != 0; i--) {
		printf("%018llu", value->value[i]);
	}
	printf("\n");
}

void freeBigInteger(struct BigInteger * value)
{
	if (value->value) {
		free(value->value);
		value->numberValue = 0;
		value->value = NULL;
	}
}
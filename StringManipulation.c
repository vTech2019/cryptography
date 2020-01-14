#include "StringManipulation.h"

void intToString(int32_t number, uint8_t* string, size_t* numberDigit) {
	size_t _numberDigit = 0;
	size_t lengthString = strlen(string);
	lengthString = lengthString > 9 ? 9 : lengthString;
	while (number != 0) {
		if (lengthString != 0)
			string[lengthString--] = (number % 10) + '0';
		_numberDigit++;
		number /= 10;
	}
	if (numberDigit) *numberDigit = _numberDigit;
}
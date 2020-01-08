#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include <nmmintrin.h>
#include <immintrin.h>
#include "Sort.h"

#ifndef __CRC32__
#define __CRC32__
#include "BMI_C.h"
uint32_t CRC32_Hash(uint8_t* data, size_t lengthData);
uint32_t CRC32_HW_Hash(uint8_t* data, size_t lengthData);

void createHistogramCRC32BirthdayParadox(size_t numberValues, size_t stepNumberSymbols, size_t numberIterations, size_t maximumHistSymbols);

#endif
#include <stdint.h>
#include "Sort.h"
#include "FileOperations.h"
#ifndef __STATISTICS__
#define __STATISTICS__
void statisticFileTestASCII(const char* fileName, size_t** histogram, uint8_t** statisticSymbol);
#endif
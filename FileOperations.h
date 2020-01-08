#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>

#ifndef  __FILEOPERATIONS__
#define __FILEOPERATIONS__
errno_t readStrings(const char* nameFile, uint8_t** memory, uint8_t*** strings, size_t numberText, size_t* lengthText);
errno_t readFile(const char* nameFile, uint8_t** memory, int32_t* sizeFile);
errno_t writeFile(const char* nameFile, uint8_t* memory, int32_t sizeMemory);
#endif
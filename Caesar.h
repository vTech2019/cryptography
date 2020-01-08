#pragma once

#include <stddef.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

#ifndef __CAESARCRYPT__
#define __CAESARCRYPT__
#include "FileOperations.h"
#include "Sort.h"

uint8_t* cryptCaesar(uint8_t* text, size_t lengthText, uint8_t addParameter);
size_t* histogram8_U8(uint8_t* text, size_t lengthText);
uint8_t* decryptCaesar8(uint8_t* text, size_t lengthText, uint8_t* dictionary, size_t lengthDictionary);
uint8_t* decryptCaesar16(uint8_t* text, size_t lengthText, uint8_t* dictionary, size_t lengthDictionary);
uint8_t* testDecryptCaesar16(uint8_t* testText, size_t lengthTestText, uint8_t* text, size_t lengthText, uint8_t* dictionary, size_t lengthDictionary);

uint8_t* testCaesarOneSymbol(uint8_t* text, uint8_t* dictionary, uint8_t* decryptFileName, uint8_t addParameter);

#endif

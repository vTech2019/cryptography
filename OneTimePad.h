#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "Sort.h"
#include "FileOperations.h"
struct cryptData {
	size_t code[256];
	uint64_t histogram[256];
	uint8_t offsetCode[256][256];
};
#ifndef __ONETIMEPAD__
#define __ONETIMEPAD__


void printBinaryASCII();
void printHexASCII();
void printTable(size_t heightTable, size_t widthTable, size_t* table);
void createStatisticText(uint8_t* text, size_t lengthText, uint8_t** sortStatisticSymbol, size_t* lengthStatistic, uint8_t offsetHistogramBorder);
uint8_t* genKey(size_t lengthKey);
uint8_t* OneTimePadCrypt(uint8_t* text, size_t lengthText, uint8_t* key);

uint8_t* manyTimePadDecryptText(uint8_t* statisticDictionary, size_t lengthStatisticDictionary, uint8_t** cryptTexts, size_t numberCrypts, size_t lengthCrypt);
void testManyTimePadAttack(const char* nameDictionary, const char* nameText, const char* nameDecryptText, const size_t numberFiles, uint8_t borderHistDictionary);
#endif
#include "OneTimePad.h"
#include "FileOperations.h"
#include "StringManipulation.h"
#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>

void createStatisticText(uint8_t* text, size_t lengthText, uint8_t** sortStatisticSymbol, size_t* lengthStatistic, uint8_t offsetHistogramBorder) {
	if (text && sortStatisticSymbol) {
		size_t histogram[256];
		for (size_t i = 0; i < 256; i++)
			histogram[i] = 0;
		*sortStatisticSymbol = (uint8_t*)realloc(*sortStatisticSymbol, 256);
		if (sortStatisticSymbol) {
			for (size_t i = 0; i < 256; i++)
				(*sortStatisticSymbol)[i] = (uint8_t)i;
			for (size_t i = 0; i < lengthText; i++) {
				histogram[text[i]]++;
			}
			gnomeSortSZ(histogram, 256, *sortStatisticSymbol, 1);
			for (size_t i = 0; i < 128; i++) {
				sortStatisticSymbol[0][i] ^= sortStatisticSymbol[0][255 - i];
				sortStatisticSymbol[0][255 - i] ^= sortStatisticSymbol[0][i];
				sortStatisticSymbol[0][i] ^= sortStatisticSymbol[0][255 - i];
			}
			for (size_t i = 0; i < 256 && i < offsetHistogramBorder; i++) {
				*lengthStatistic = i;
				if (histogram[255 - i] == 0) {
					i = 256;
				}
			}
		}
	}
}

void printBinaryASCII() {
	for (size_t i = 0; i < 16; i++) {
		for (size_t j = 0; j < 16; j++) {
			uint8_t code = i * 16 + j;
			if (i * 16 + j < 16) {
				printf(" N ");
				for (size_t m_i = 0; m_i < 8; m_i++)
					printf("%d", (code >> (7 - m_i)) & 1);
			}
			else {
				printf(" %c ", code);
				for (size_t m_i = 0; m_i < 8; m_i++)
					printf("%d", (code >> (7 - m_i)) & 1);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void printHexASCII() {
	for (size_t i = 0; i < 16; i++) {
		for (size_t j = 0; j < 16; j++) {
			uint8_t code = i * 16 + j;
			if (i * 16 + j < 16) {
				printf(" N ");

				for (size_t m_i = 0; m_i < 2; m_i++)
					printf("%x", (code >> (4 * (1 - m_i))) & 15);
			}
			else {
				printf(" %c ", code);
				for (size_t m_i = 0; m_i < 2; m_i++)
					printf("%x", (code >> (4 * (1 - m_i))) & 15);
			}
		}
		printf("\n");
	}
	printf("\n");
}

//void printTableC99(size_t heightTable, size_t widthTable, size_t table[heightTable][widthTable]) {
//	for (size_t i = 0; i < heightTable; i++) {
//		for (size_t j = 0; j < widthTable; j++) {
//			printf("%zd ", table[i][j]);
//		}
//		printf("\n");
//	}
//}

void printTable(size_t heightTable, size_t widthTable, size_t* table) {
	for (size_t i = 0; i < heightTable; i++) {
		for (size_t j = 0; j < widthTable; j++) {
			printf("%zd ", table[i * widthTable + j]);
		}
		printf("\n");
	}
	printf("\n");
}

uint8_t* genKey(size_t lengthKey) {
	uint8_t* key = (uint8_t*)malloc(lengthKey);
	for (size_t i = 0; i < lengthKey; i++) {
		key[i] = rand();
	}
	return key;
}

uint8_t* OneTimePadCrypt(uint8_t* text, size_t lengthText, uint8_t* key) {
	uint8_t* cryptText = (uint8_t*)malloc(lengthText);

	//for (size_t k = 0; k < 10; k++) {
	//	printf("%c ", text[k]);
	//}
	//printf("\n");
	for (size_t i = 0; i < lengthText; i++) {
		cryptText[i] = text[i] ^ key[i];
	}
	return cryptText;
}

void getOptions(uint8_t** matrixXor, size_t numberCrypts, size_t offsetSymbolsMatrix, size_t lengthStatisticDictionary, uint8_t* statisticDictionary, uint8_t** results, size_t* lengthResult) {
	*lengthResult = 0;
	results[0] = (uint8_t*)realloc(results[0], numberCrypts * numberCrypts);
	for (size_t p = 0; p < lengthStatisticDictionary; p++) {
		uint8_t predict = statisticDictionary[p];
		for (size_t i = 0; i < numberCrypts; i++) {
			results[0][i + *lengthResult] = matrixXor[i * numberCrypts + 0][offsetSymbolsMatrix] ^ predict;
		}
		for (size_t i = 0; i < numberCrypts; i++) {
			for (size_t j = i; j < numberCrypts; j++) {
				if ((results[0][i + *lengthResult] ^ results[0][j + *lengthResult]) != matrixXor[i * numberCrypts + j][offsetSymbolsMatrix]) {
					i = numberCrypts;
					j = numberCrypts;
					for (size_t j = i; j < numberCrypts; j++)
						results[0][j + *lengthResult] = 0;
				}
			}
			if (i == numberCrypts - 1) {
				size_t find = 0;
				for (size_t j = 1; j < numberCrypts; j++)
					for (size_t i = 0; i < lengthStatisticDictionary; i++)
						if (results[0][j + *lengthResult] == statisticDictionary[i]) {
							find++;
							break;
						}
				if (find == numberCrypts - 1) {
					*lengthResult += numberCrypts;
					if (*lengthResult > numberCrypts* numberCrypts - numberCrypts)
						results[0] = (uint8_t*)realloc(results[0], *lengthResult + numberCrypts);
				}
				break;
			}
		}
	}
}

size_t spaceDecrypt(uint8_t** matrixXor, size_t numberCrypts, size_t offsetString, uint8_t* optionSymbols, size_t numberOptions) {
	size_t trueOption = 0;
	size_t* voteSpace = (size_t*)calloc(2 * numberCrypts, sizeof(size_t));
	size_t* maxIndexSpace = voteSpace + numberCrypts;
	for (size_t i = 0; i < numberCrypts; i++)
		maxIndexSpace[i] = i;
	for (size_t i = 0; i < numberCrypts; i++) {
		for (size_t j = 0; j < numberCrypts; j++) {
			uint8_t symbol = matrixXor[j * numberCrypts + i][offsetString] ^ ' ';
			if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || symbol == 0) {
				voteSpace[j]++;
				voteSpace[i]++;
			}
		}
	}
	//printf("\n");
	//for (size_t j = 0; j < numberCrypts; j++) {
	//	printf("%d ", voteSpace[j]);
	//}
	//printf("\n");
	gnomeSortSZ(voteSpace, numberCrypts, (uint8_t*)maxIndexSpace, sizeof(size_t));
	size_t maxVote = 0;
	for (size_t i = 0; i < numberOptions; i++) {
		size_t maxSum = 0;
		for (size_t j = 0; j < numberCrypts; j++) {
			if (optionSymbols[i * numberCrypts + maxIndexSpace[j]] == ' ') {
				maxSum += voteSpace[j];
				if (maxVote < maxSum) {
					maxVote = maxSum;
					trueOption = i;
				}
			}
		}
	}
	//for (size_t i = 0; i < numberOptions; i++) {
	//	for (size_t j = 0; j < numberCrypts; j++) {
	//		char s = optionSymbols[i * numberCrypts + j];
	//			printf("%c ", s < 32 ? 127 : s);
	//	}
	//	printf("\n");
	//}
	//printf("\n");

	//for (size_t j = 0; j < numberCrypts; j++) {
	//	char s = optionSymbols[trueOption * numberCrypts + j];
	//		printf("%c ", s < 32 ? 127 : s);
	//}
	//printf("\n");
	//for (size_t j = 0; j < numberCrypts; j++) {
	//	printf("%d ", voteSpace[j]);
	//}
	//printf("\n");
	if (voteSpace) free(voteSpace);
	return trueOption;
}

uint8_t* manyTimePadDecryptText(uint8_t* statisticDictionary, size_t lengthStatisticDictionary, uint8_t** cryptTexts, size_t numberCrypts, size_t lengthCrypt) {
	uint8_t* decryptText = (uint8_t*)malloc(numberCrypts * lengthCrypt);
	size_t matrixSizeText = numberCrypts * numberCrypts * lengthCrypt;
	size_t matrixNumberPtrXor = numberCrypts * numberCrypts * sizeof(uint8_t*);
	uint8_t** ptrXorTexts = NULL;
	uint8_t* memoryXor = (uint8_t*)malloc(matrixSizeText + matrixNumberPtrXor);

	uint8_t** optionsSymbols = (uint8_t**)calloc(lengthCrypt, sizeof(uint8_t*));
	size_t* lengthOptions = (size_t*)calloc(lengthCrypt, sizeof(size_t));

	ptrXorTexts = (uint8_t**)(memoryXor + matrixSizeText);
	for (size_t i = 0; i < numberCrypts * numberCrypts; i++) {
		ptrXorTexts[i] = memoryXor + i * lengthCrypt;
	}

	for (size_t i = 0; i < numberCrypts; i++) {
		for (size_t j = 0; j < numberCrypts; j++) {
			for (size_t k = 0; k < lengthCrypt; k++) {
				ptrXorTexts[i * numberCrypts + j][k] = cryptTexts[i][k] ^ cryptTexts[j][k];
			}
		}
	}
	//printf("\n");

	for (size_t i = 0; i < lengthCrypt; i++) {
		getOptions(ptrXorTexts, numberCrypts, i, lengthStatisticDictionary, statisticDictionary, &optionsSymbols[i], &lengthOptions[i]);
		if (lengthOptions[i]) {
			size_t trueOption = spaceDecrypt(ptrXorTexts, numberCrypts, i, optionsSymbols[i], lengthOptions[i] / numberCrypts);
			size_t offsetResult = trueOption * numberCrypts;
			for (size_t j = 0; j < numberCrypts; j++) { //здесь должен быть выбор оптимальной комбинации (единственный вариант - проверка слов на предмет существовани€(есть ли слово в словаре))
				decryptText[j * lengthCrypt + i] = optionsSymbols[i][offsetResult + j];
				//cryptTexts[j][i] = optionsSymbols[i][j];
			}
		}
		else
			for (size_t j = 0; j < numberCrypts; j++) {
				decryptText[j * lengthCrypt + i] = '?'; // мен€ем границы отсечени€ гистограммы словар€
			}
	}

	//for (size_t i = 0; i < numberCrypts; i++) {
	//	for (size_t k = 0; k < lengthCrypt; k++) {
	//		printf("%c", cryptTexts[i][k]);
	//	}
	//	printf("\n");
	//}

	for (size_t i = 0; i < lengthCrypt; i++) {
		if (optionsSymbols[i]) {
			free(optionsSymbols[i]);
		}
	}
	if (memoryXor) free(memoryXor);
	if (optionsSymbols) free(optionsSymbols);
	if (lengthOptions) free(lengthOptions);

	return decryptText;
}
void exTestManyTimePadAttack(const char* nameDictionary, const char* nameText, const char* nameDecryptText, const size_t numberFiles) {
	ptrdiff_t i = 40;
	size_t length = strlen(nameDecryptText);
#pragma omp parallel for
	for (i = 40; i < 200; i++) {
		uint8_t* nameDecText = (uint8_t*)calloc(length + sizeof("0000000000.txt") + 1, sizeof(uint8_t));
		if (nameDecText) {
			memcpy(nameDecText, nameDecryptText, length);
			memcpy(nameDecText + length, "0000000000.txt", sizeof("0000000000.txt") - 1);
			uint8_t* ptr = nameDecText + length;
			int32_t _i = i;
			intToString(_i, ptr, NULL);
			testManyTimePadAttack(nameDictionary, nameText, nameDecText, 10, i);
			free(nameDecText);
		}
	}
}

void testManyTimePadAttack(const char* nameDictionary, const char* nameText, const char* nameDecryptText, const size_t numberFiles, uint8_t borderHistDictionary)
{
	uint8_t** cipherText = (uint8_t**)malloc(numberFiles * sizeof(uint8_t*));
	uint8_t* dictionary = NULL;
	uint8_t* statisticDictionary = NULL;
	uint8_t** texts = NULL;
	uint8_t* textMemory = NULL;
	int32_t lengthDictionary = 0;
	size_t lengthStatistic = 0;
	size_t lengthText = 0;
	readFile(nameDictionary, &dictionary, &lengthDictionary);
	readStrings(nameText, &textMemory, &texts, numberFiles, &lengthText);
	createStatisticText(dictionary, lengthDictionary, &statisticDictionary, &lengthStatistic, borderHistDictionary);
	uint8_t* key = genKey(lengthText);
	for (size_t i = 0; i < numberFiles; i++) {
		cipherText[i] = OneTimePadCrypt(texts[i], lengthText, key);
	}
	uint8_t* decryptText = manyTimePadDecryptText(statisticDictionary, lengthStatistic, cipherText, numberFiles, lengthText);
	writeFile(nameDecryptText, decryptText, numberFiles * lengthText);
	for (size_t i = 0; i < numberFiles; i++) {
		if (cipherText[i]) free(cipherText[i]);
	}
	if (cipherText) free(cipherText);
	if (statisticDictionary) free(statisticDictionary);
	if (dictionary) free(dictionary);
	if (key) free(key);
	if (textMemory) free(textMemory);
	if (decryptText) free(decryptText);
}
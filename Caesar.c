#include "Caesar.h"

void printHistogramSZ(size_t* histogram, size_t height, size_t width) {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			printf("%zd ", histogram[i * width + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printHistogramNotNullSZ(size_t* histogram, size_t length) {
	for (size_t i = 0; i < length; i++) {
		if (histogram[i])
			printf("%zd ", histogram[i]);
	}
	printf("\n");
}
void printHistogramsWithSymbolsNotNullSZ(size_t* histogram_0, size_t* histogram_1, uint8_t* codeText0, uint8_t* codeText1,size_t stepText, size_t lengthHistogram) {
	for (size_t i = 0; i < lengthHistogram; i++) {
		if (histogram_0[i] || histogram_1[i]) {
			printf("%zd %zd ", histogram_0[i], histogram_1[i]);
			for (size_t j = 0; j < stepText; j++) {
				printf("%c", codeText0[i * stepText + j]);
			}
			printf(" ");
			for (size_t j = 0; j < stepText; j++) {
				printf("%c", codeText1[i * stepText + j]);
			}
			printf("\n");
		}
	}
	printf("\n");
}

uint8_t* cryptCaesar(uint8_t* text, size_t lengthText, uint8_t addParameter) {
	uint8_t* cryptText = (uint8_t*)malloc(lengthText + 2);
	if (cryptText) {
		size_t i = 0;
		for (; i < lengthText; i++) {
			cryptText[i] = text[i] + addParameter;
		}
		cryptText[i] = 0;
	}
	return cryptText;
}

size_t* histogram8_U8(uint8_t* text, size_t lengthText) {
	size_t* histogram = (size_t*)calloc(256, sizeof(size_t));
	if (histogram)
		for (size_t i = 0; i < lengthText; i++) {
			histogram[text[i]]++;
		}
	return histogram;
}
size_t* histogram16_U8(uint8_t* text, size_t lengthText) {
	size_t* histogram = (size_t*)calloc(65536, sizeof(size_t));
	if (histogram) {
		for (size_t i = 0; i < lengthText - 1; i++) {
			uint16_t* index = (uint16_t*)(text + i);
			histogram[*index]++;
		}
	}
	return histogram;
}

uint8_t* decryptCaesar8(uint8_t* text, size_t lengthText, uint8_t* dictionary, size_t lengthDictionary) {
	uint8_t* decryptText;
	uint8_t* codeDecryptText;
	uint8_t* codeCryptText;
	size_t* histogram;
	size_t* histogramDictionary;
	decryptText = (uint8_t*)malloc(lengthText + 1);

	histogram = histogram8_U8(text, lengthText);
	histogramDictionary = histogram8_U8(dictionary, lengthDictionary);
	printHistogramSZ(histogram, 16, 16);
	printHistogramSZ(histogramDictionary, 16, 16);

	codeDecryptText = (uint8_t*)malloc(256 + 1);
	codeCryptText = (uint8_t*)malloc(256 + 1);
	if (codeCryptText && codeDecryptText) {
		for (size_t i = 0; i < 256; ++i) {
			codeDecryptText[i] = i;
			codeCryptText[i] = i;
		}
		gnomeSortSZ(histogram, 256, codeCryptText, 1);
		gnomeSortSZ(histogramDictionary, 256, codeDecryptText, 1);
		gnomeSortU8(codeCryptText, 256, codeDecryptText, 1);
		for (size_t i = 0; i < lengthText; i++) {
			decryptText[i] = codeDecryptText[text[i]];
		}
	}

	if (histogram) free(histogram);
	if (histogramDictionary) free(histogramDictionary);
	if (codeDecryptText) free(codeDecryptText);
	if (codeCryptText) free(codeCryptText);
	return decryptText;
}
uint8_t* decryptCaesar16(uint8_t* text, size_t lengthText, uint8_t* dictionary, size_t lengthDictionary) {
	uint8_t* decryptText;
	uint16_t* codeDecryptText;
	uint16_t* codeCryptText;
	size_t* histogram;
	size_t* histogramDictionary;
	decryptText = (uint8_t*)malloc(lengthText + 1);

	histogram = histogram16_U8(text, lengthText);
	histogramDictionary = histogram16_U8(dictionary, lengthDictionary);
	//printHistogramNotNullSZ(histogram, 65536);
	//printHistogramNotNullSZ(histogramDictionary, 65536);

	codeDecryptText = (uint16_t*)malloc(65536 * sizeof(uint16_t));
	codeCryptText = (uint16_t*)malloc(65536 * sizeof(uint16_t));
	if (codeCryptText && codeDecryptText) {
		for (size_t i = 0; i < 65536; ++i) {
			codeDecryptText[i] = i;
			codeCryptText[i] = i;
		}
		gnomeSortSZ(histogram, 65536, (uint8_t*)codeCryptText, 2);
		gnomeSortSZ(histogramDictionary, 65536, (uint8_t*)codeDecryptText, 2);
		//printHistogramsWithSymbolsNotNullSZ(histogram, histogramDictionary, codeDecryptText, codeCryptText, 2, 65536);

		gnomeSortU16(codeCryptText, 65536, (uint8_t*)codeDecryptText, 2);
		for (size_t i = 0; i < lengthText; i++) {
			decryptText[i] = codeDecryptText[text[i]];
		}
	}

	if (histogram) free(histogram);
	if (histogramDictionary) free(histogramDictionary);
	if (codeDecryptText) free(codeDecryptText);
	if (codeCryptText) free(codeCryptText);
	return decryptText;
}


uint8_t* testDecryptCaesar16(uint8_t* testText, size_t lengthTestText, uint8_t* text, size_t lengthText, uint8_t* dictionary, size_t lengthDictionary) {
	uint8_t* decryptText;
	uint16_t* codeDecryptText;
	uint16_t* codeCryptText;
	size_t* histogram;
	size_t* histogramDictionary;
	decryptText = (uint8_t*)malloc(lengthText + 1);

	histogram = histogram16_U8(text, lengthText);
	histogramDictionary = histogram16_U8(dictionary, lengthDictionary);
	//printHistogramNotNullSZ(histogram, 65536);
	//printHistogramNotNullSZ(histogramDictionary, 65536);

	codeDecryptText = (uint16_t*)malloc(65536 * sizeof(uint16_t));
	codeCryptText = (uint16_t*)malloc(65536 * sizeof(uint16_t));
	if (codeCryptText && codeDecryptText) {
		for (size_t i = 0; i < 65536; ++i) {
			codeDecryptText[i] = i;
			codeCryptText[i] = i;
		}
		gnomeSortSZ(histogram, 65536, (uint8_t*)codeCryptText, 2);
		gnomeSortSZ(histogramDictionary, 65536, (uint8_t*)codeDecryptText, 2);
		//printHistogramsWithSymbolsNotNullSZ(histogram, histogramDictionary, codeDecryptText, codeCryptText, 2, 65536);

		gnomeSortU16(codeCryptText, 65536, (uint8_t*)codeDecryptText, 2);
		for (size_t i = 0; i < lengthText; i++) {
			decryptText[i] = codeDecryptText[text[i]];
		}
	}

	if (histogram) free(histogram);
	if (histogramDictionary) free(histogramDictionary);
	if (codeDecryptText) free(codeDecryptText);
	if (codeCryptText) free(codeCryptText);
	return decryptText;
}

uint8_t* testCaesarOneSymbol(uint8_t* text, uint8_t* dictionary, uint8_t* decryptFileName, uint8_t addParameter) {
	uint8_t* dictionaryData = NULL;
	int32_t lengthDictionary = 0;
	uint8_t* textData = NULL;
	int32_t lengthText = 0;
	readFile(dictionary, &dictionaryData, &lengthDictionary);
	readFile(text, &textData, &lengthText);
	uint8_t* cipher = cryptCaesar(textData, lengthText, addParameter);
	uint8_t* decryptText = decryptCaesar8(cipher, lengthText, dictionaryData, lengthDictionary);
	writeFile(decryptFileName, decryptText, lengthText);
	if (decryptText) free(decryptText);
	if (cipher) free(cipher);
	if (textData) free(textData);
	if (dictionaryData) free(dictionaryData);
}
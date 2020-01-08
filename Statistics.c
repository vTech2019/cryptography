#include "Statistics.h"

void statisticFileTestASCII(const char* fileName, size_t** histogram, uint8_t** statisticSymbol)
{
	if (!statisticSymbol)
		return;
	uint32_t sizeFile = 0;
	uint8_t* memory = NULL;
	size_t* l_histogram = (size_t*)calloc(256, sizeof(size_t));
	*statisticSymbol = (uint8_t*)calloc(256, sizeof(uint8_t));
	for (size_t i = 0; i < 256; i++)
		(*statisticSymbol)[i] = i;
	if (!readFile(fileName, &memory, &sizeFile)) {
		for (size_t i = 0; i < sizeFile; i++) {
			l_histogram[memory[i]]++;
		}
		//for (size_t i = 0; i < 16; i++) {
		//	for (size_t j = 0; j < 16; j++) 
		//		printf("%zd ", l_histogram[i * 16 + j]);
		//	printf("\n");
		//}
		gnomeSortSZ(l_histogram, 256, *statisticSymbol, 1);
		//for (size_t i = 0; i < 16; i++) {
		//	for (size_t j = 0; j < 16; j++)
		//		printf("%zd (%x) ", l_histogram[i * 16 + j], (*statisticSymbol)[i * 16 + j]);
		//	printf("\n");
		//}
		if (histogram)
			*histogram = l_histogram;
		else
			free(l_histogram);
	}
	else {
		if (*statisticSymbol) free(*statisticSymbol);
		if (l_histogram) free(l_histogram);
		*statisticSymbol = NULL;
	}
}

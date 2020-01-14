#pragma once
#define _CRT_RAND_S
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <immintrin.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZEOF(X)  sizeof(X) / sizeof(*X)



typedef struct __testParameters {
	int		n;
	int		blockFrequencyBlockLength;
	int		nonOverlappingTemplateBlockLength;
	int		overlappingTemplateBlockLength;
	int		serialBlockLength;
	int		linearComplexitySequenceLength;
	int		approximateEntropyBlockLength;
	int		numOfBitStreams;
} test_parameters;

#ifndef __STATISTIC_TEST__
#define __STATISTIC_TEST__

extern char* options[];
extern char* statistical_test[];

void lcg(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void quadRes1(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void quadRes2(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void cubicRes(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void exclusiveOR(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void modExp(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void bbs(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void micali_schnorr(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);



void testRand(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void testSRand(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void testRDRand(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp);


void statisticsTest(char* nameFile, void(**functions)(FILE*, unsigned char*, size_t*, test_parameters), char** nameFunctions, size_t number_functions, unsigned char* epsilon, size_t* test_vector, test_parameters tp);
void testStatisticsTest(char* nameFile);

#endif
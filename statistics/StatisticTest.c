#pragma once
#include "StatisticTest.h"
#include "include/decls.h"
#include "include/generators.h"
#include <stdlib.h>
#include "include/cephes.h"
#include "include/matrix.h"
#include "include/genutils.h"

//#ifndef __DFFT__
//#define __DFFT__
//#include "src/dfft.c"
//#endif

static char* options[] = { "Linear-Congruential",
"Quadratic-Congruential-1",
"Quadratic-Congruential-2",
"Cubic-Congruential",
"XOR",
"Modular-Exponentiation",
"Blum-Blum-Shub",
"Micali-Schnorr",
"G using SHA-1" };

static char* statistical_test[] = { "[01] Frequency",
"[02] Block Frequency",
"[03] Cumulative Sums",
"[04] Runs",
"[05] Longest Run of Ones",
"[06] Rank",
"[07] Discrete Fourier Transform",
"[08] Nonperiodic Template Matchings",
"[09] Overlapping Template Matchings",
"[10] Universal Statistical",
"[11] Approximate Entropy",
"[12] Random Excursions",
"[13] Random Excursions Variant",
"[14] Serial",
"[15] Linear Complexity" };

#define MAX(x,y)             ((x) <  (y)  ? (y)  : (x))
#define MIN(x,y)             ((x) >  (y)  ? (y)  : (x))
#define isNonPositive(x)     ((x) <= 0.e0 ?   1  : 0)
#define isPositive(x)        ((x) >  0.e0 ?   1 : 0)
#define isNegative(x)        ((x) <  0.e0 ?   1 : 0)
#define isGreaterThanOne(x)  ((x) >  1.e0 ?   1 : 0)
#define isZero(x)            ((x) == 0.e0 ?   1 : 0)
#define isOne(x)             ((x) == 1.e0 ?   1 : 0)
#define ALPHA							0.01	/* SIGNIFICANCE LEVEL */
#define	TEST_FREQUENCY					1
#define	TEST_BLOCK_FREQUENCY			2
#define	TEST_CUSUM						3
#define	TEST_RUNS						4
#define	TEST_LONGEST_RUN				5
#define	TEST_RANK						6
#define	TEST_FFT						7
#define	TEST_NONPERIODIC				8
#define	TEST_OVERLAPPING				9
#define	TEST_UNIVERSAL					10
#define	TEST_APEN						11
#define	TEST_RND_EXCURSION				12
#define	TEST_RND_EXCURSION_VAR			13
#define	TEST_SERIAL						14
#define	TEST_LINEARCOMPLEXITY			15



//size_t option = SIZEOF(options);
//size_t statistical_test_vector[SIZEOF(statistical_test) + 1] = { 1 };

int convertToBits(BYTE* x, int xBitLength, int bitsNeeded, int* num_0s, int* num_1s, int* bitsRead, unsigned char* epsilon) {
	int		i, j, count, bit;
	BYTE	mask;
	int		zeros, ones;

	count = 0;
	zeros = ones = 0;
	for (i = 0; i < (xBitLength + 7) / 8; i++) {
		mask = 0x80;
		for (j = 0; j < 8; j++) {
			if (*(x + i) & mask) {
				bit = 1;
				(*num_1s)++;
				ones++;
			}
			else {
				bit = 0;
				(*num_0s)++;
				zeros++;
			}
			mask >>= 1;
			epsilon[*bitsRead] = bit;
			(*bitsRead)++;
			if (*bitsRead == bitsNeeded)
				return 1;
			if (++count == xBitLength)
				return 0;
		}
	}

	return 0;
}

void Frequency(int n, FILE** stats, unsigned char* epsilon)
{
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "FREQUENCY.txt", "a+")) {
	//		return;
	//	}
	//}

	int		i;
	double	f, s_obs, p_value, sum, sqrt2 = 1.41421356237309504880;

	sum = 0.0;
	for (i = 0; i < n; i++)
		sum += 2 * (int)epsilon[i] - 1;
	s_obs = fabs(sum) / sqrt(n);
	f = s_obs / sqrt2;
	p_value = erfc(f);
	fprintf(*stats, "\t\t\t      FREQUENCY TEST\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\t(a) The nth partial sum = %d\n", (int)sum);
	fprintf(*stats, "\t\t(b) S_n/n               = %f\n", sum / n);
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
	fflush(*stats);
}
void BlockFrequency(int M, int n, FILE** stats, unsigned char* epsilon) {

	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "BLOCKFREQUENCY.txt", "a+")) {
	//		return;
	//	}
	//}

	int		i, j, N, blockSum;
	double	p_value, sum, pi, v, chi_squared;

	N = n / M; 		/* # OF SUBSTRING BLOCKS      */
	sum = 0.0;

	for (i = 0; i < N; i++) {
		blockSum = 0;
		for (j = 0; j < M; j++)
			blockSum += epsilon[j + i * M];
		pi = (double)blockSum / (double)M;
		v = pi - 0.5;
		sum += v * v;
	}
	chi_squared = 4.0 * M * sum;
	p_value = cephes_igamc(N / 2.0, chi_squared / 2.0);

	fprintf(*stats, "\t\t\tBLOCK FREQUENCY TEST\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\t(a) Chi^2           = %f\n", chi_squared);
	fprintf(*stats, "\t\t(b) # of substrings = %d\n", N);
	fprintf(*stats, "\t\t(c) block length    = %d\n", M);
	fprintf(*stats, "\t\t(d) Note: %d bits were discarded.\n", n % M);
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
	fflush(*stats);
}

void CumulativeSums(int n, FILE** stats, unsigned char* epsilon) {
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "CUMULATIVESUMS.txt", "a+")) {
	//		return;
	//	}
	//}
	int		S, sup, inf, z, zrev, k;
	double	sum1, sum2, p_value;

	S = 0;
	sup = 0;
	inf = 0;
	for (k = 0; k < n; k++) {
		epsilon[k] ? S++ : S--;
		if (S > sup)
			sup++;
		if (S < inf)
			inf--;
		z = (sup > -inf) ? sup : -inf;
		zrev = (sup - S > S - inf) ? sup - S : S - inf;
	}

	// forward
	sum1 = 0.0;
	for (k = (-n / z + 1) / 4; k <= (n / z - 1) / 4; k++) {
		sum1 += cephes_normal(((4 * k + 1) * z) / sqrt(n));
		sum1 -= cephes_normal(((4 * k - 1) * z) / sqrt(n));
	}
	sum2 = 0.0;
	for (k = (-n / z - 3) / 4; k <= (n / z - 1) / 4; k++) {
		sum2 += cephes_normal(((4 * k + 3) * z) / sqrt(n));
		sum2 -= cephes_normal(((4 * k + 1) * z) / sqrt(n));
	}

	p_value = 1.0 - sum1 + sum2;

	fprintf(*stats, "\t\t      CUMULATIVE SUMS (FORWARD) TEST\n");
	fprintf(*stats, "\t\t-------------------------------------------\n");
	fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(*stats, "\t\t-------------------------------------------\n");
	fprintf(*stats, "\t\t(a) The maximum partial sum = %d\n", z);
	fprintf(*stats, "\t\t-------------------------------------------\n");

	if (isNegative(p_value) || isGreaterThanOne(p_value))
		fprintf(*stats, "\t\tWARNING:  P_VALUE IS OUT OF RANGE\n");

	fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);

	sum1 = 0.0;
	for (k = (-n / zrev + 1) / 4; k <= (n / zrev - 1) / 4; k++) {
		sum1 += cephes_normal(((4 * k + 1) * zrev) / sqrt(n));
		sum1 -= cephes_normal(((4 * k - 1) * zrev) / sqrt(n));
	}
	sum2 = 0.0;
	for (k = (-n / zrev - 3) / 4; k <= (n / zrev - 1) / 4; k++) {
		sum2 += cephes_normal(((4 * k + 3) * zrev) / sqrt(n));
		sum2 -= cephes_normal(((4 * k + 1) * zrev) / sqrt(n));
	}
	p_value = 1.0 - sum1 + sum2;

	fprintf(*stats, "\t\t      CUMULATIVE SUMS (REVERSE) TEST\n");
	fprintf(*stats, "\t\t-------------------------------------------\n");
	fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(*stats, "\t\t-------------------------------------------\n");
	fprintf(*stats, "\t\t(a) The maximum partial sum = %d\n", zrev);
	fprintf(*stats, "\t\t-------------------------------------------\n");

	if (isNegative(p_value) || isGreaterThanOne(p_value))
		fprintf(*stats, "\t\tWARNING:  P_VALUE IS OUT OF RANGE\n");

	fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
	fflush(*stats);
}

void Runs(int n, FILE** stats, unsigned char* epsilon) {
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "RUNS.txt", "a+")) {
	//		return;
	//	}
	//}
	int		S, k;
	double	pi, V, erfc_arg, p_value;

	S = 0;
	for (k = 0; k < n; k++)
		if (epsilon[k])
			S++;
	pi = (double)S / (double)n;

	if (fabs(pi - 0.5) > (2.0 / sqrt(n))) {
		fprintf(*stats, "\t\t\t\tRUNS TEST\n");
		fprintf(*stats, "\t\t------------------------------------------\n");
		fprintf(*stats, "\t\tPI ESTIMATOR CRITERIA NOT MET! PI = %f\n", pi);
		p_value = 0.0;
	}
	else {

		V = 1;
		for (k = 1; k < n; k++)
			if (epsilon[k] != epsilon[k - 1])
				V++;

		erfc_arg = fabs(V - 2.0 * n * pi * (1 - pi)) / (2.0 * pi * (1 - pi) * sqrt(2 * n));
		p_value = erfc(erfc_arg);

		fprintf(*stats, "\t\t\t\tRUNS TEST\n");
		fprintf(*stats, "\t\t------------------------------------------\n");
		fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
		fprintf(*stats, "\t\t------------------------------------------\n");
		fprintf(*stats, "\t\t(a) Pi                        = %f\n", pi);
		fprintf(*stats, "\t\t(b) V_n_obs (Total # of runs) = %d\n", (int)V);
		fprintf(*stats, "\t\t(c) V_n_obs - 2 n pi (1-pi)\n");
		fprintf(*stats, "\t\t    -----------------------   = %f\n", erfc_arg);
		fprintf(*stats, "\t\t      2 sqrt(2n) pi (1-pi)\n");
		fprintf(*stats, "\t\t------------------------------------------\n");
		if (isNegative(p_value) || isGreaterThanOne(p_value))
			fprintf(*stats, "WARNING:  P_VALUE IS OUT OF RANGE.\n");

		fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
		fflush(*stats);
	}
	//fprintf(*stats, "%f\n", p_value); fflush(*stats);
}

void LongestRunOfOnes(int n, FILE** stats, unsigned char* epsilon) {
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "LONGESTRUNOFONES.txt", "a+")) {
	//		return;
	//	}
	//}
	//else
	//	return;

	double			pval, chi2, pi[7];
	int				run, v_n_obs, N, i, j, K, M, V[7];
	unsigned int	nu[7] = { 0, 0, 0, 0, 0, 0, 0 };

	if (n < 128) {
		fprintf(*stats, "\t\t\t  LONGEST RUNS OF ONES TEST\n");
		fprintf(*stats, "\t\t---------------------------------------------\n");
		fprintf(*stats, "\t\t   n=%d is too short\n", n);
		return;
	}
	if (n < 6272) {
		K = 3;
		M = 8;
		V[0] = 1; V[1] = 2; V[2] = 3; V[3] = 4;
		pi[0] = 0.21484375;
		pi[1] = 0.3671875;
		pi[2] = 0.23046875;
		pi[3] = 0.1875;
	}
	else if (n < 750000) {
		K = 5;
		M = 128;
		V[0] = 4; V[1] = 5; V[2] = 6; V[3] = 7; V[4] = 8; V[5] = 9;
		pi[0] = 0.1174035788;
		pi[1] = 0.242955959;
		pi[2] = 0.249363483;
		pi[3] = 0.17517706;
		pi[4] = 0.102701071;
		pi[5] = 0.112398847;
	}
	else {
		K = 6;
		M = 10000;
		V[0] = 10; V[1] = 11; V[2] = 12; V[3] = 13; V[4] = 14; V[5] = 15; V[6] = 16;
		pi[0] = 0.0882;
		pi[1] = 0.2092;
		pi[2] = 0.2483;
		pi[3] = 0.1933;
		pi[4] = 0.1208;
		pi[5] = 0.0675;
		pi[6] = 0.0727;
	}

	N = n / M;
	for (i = 0; i < N; i++) {
		v_n_obs = 0;
		run = 0;
		for (j = 0; j < M; j++) {
			if (epsilon[i * M + j] == 1) {
				run++;
				if (run > v_n_obs)
					v_n_obs = run;
			}
			else
				run = 0;
		}
		if (v_n_obs < V[0])
			nu[0]++;
		for (j = 0; j <= K; j++) {
			if (v_n_obs == V[j])
				nu[j]++;
		}
		if (v_n_obs > V[K])
			nu[K]++;
	}

	chi2 = 0.0;
	for (i = 0; i <= K; i++)
		chi2 += ((nu[i] - N * pi[i]) * (nu[i] - N * pi[i])) / (N * pi[i]);

	pval = cephes_igamc((double)(K / 2.0), chi2 / 2.0);

	fprintf(*stats, "\t\t\t  LONGEST RUNS OF ONES TEST\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\t(a) N (# of substrings)  = %d\n", N);
	fprintf(*stats, "\t\t(b) M (Substring Length) = %d\n", M);
	fprintf(*stats, "\t\t(c) Chi^2                = %f\n", chi2);
	fprintf(*stats, "\t\t---------------------------------------------\n");
	fprintf(*stats, "\t\t      F R E Q U E N C Y\n");
	fprintf(*stats, "\t\t---------------------------------------------\n");

	if (K == 3) {
		fprintf(*stats, "\t\t  <=1     2     3    >=4   P-value  Assignment");
		fprintf(*stats, "\n\t\t %3d %3d %3d  %3d ", nu[0], nu[1], nu[2], nu[3]);
	}
	else if (K == 5) {
		fprintf(*stats, "\t\t<=4  5  6  7  8  >=9 P-value  Assignment");
		fprintf(*stats, "\n\t\t %3d %3d %3d %3d %3d  %3d ", nu[0], nu[1], nu[2],
			nu[3], nu[4], nu[5]);
	}
	else {
		fprintf(*stats, "\t\t<=10  11  12  13  14  15 >=16 P-value  Assignment");
		fprintf(*stats, "\n\t\t %3d %3d %3d %3d %3d %3d  %3d ", nu[0], nu[1], nu[2],
			nu[3], nu[4], nu[5], nu[6]);
	}
	if (isNegative(pval) || isGreaterThanOne(pval))
		fprintf(*stats, "WARNING:  P_VALUE IS OUT OF RANGE.\n");

	fprintf(*stats, "%s\t\tp_value = %f\n\n", pval < ALPHA ? "FAILURE" : "SUCCESS", pval);
	fflush(*stats);
}

void Rank(int n, FILE** stats, unsigned char* epsilon) {
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "RANK.txt", "a+")) {
	//		return;
	//	}
	//}
	//else
	//	return;
	int			N, i, k, r;
	double		p_value, product, chi_squared, arg1, p_32, p_31, p_30, R, F_32, F_31, F_30;
	unsigned char** matrix = (unsigned char**)calloc(32, sizeof(unsigned char*));
	for (size_t i = 0; i < 32; i++) {
		matrix[i] = (unsigned char*)calloc(32, sizeof(unsigned char));
	}
	N = n / (32 * 32);
	if (isZero(N)) {
		fprintf(stats[TEST_RANK], "\t\t\t\tRANK TEST\n");
		fprintf(stats[TEST_RANK], "\t\tError: Insuffucient # Of Bits To Define An 32x32 (%dx%d) Matrix\n", 32, 32);
		p_value = 0.00;
	}
	else {
		r = 32;					/* COMPUTE PROBABILITIES */
		product = 1;
		for (i = 0; i <= r - 1; i++)
			product *= ((1.e0 - pow(2, i - 32)) * (1.e0 - pow(2, i - 32))) / (1.e0 - pow(2, i - r));
		p_32 = pow(2, r * (32 + 32 - r) - 32 * 32) * product;

		r = 31;
		product = 1;
		for (i = 0; i <= r - 1; i++)
			product *= ((1.e0 - pow(2, i - 32)) * (1.e0 - pow(2, i - 32))) / (1.e0 - pow(2, i - r));
		p_31 = pow(2, r * (32 + 32 - r) - 32 * 32) * product;

		p_30 = 1 - (p_32 + p_31);

		F_32 = 0;
		F_31 = 0;
		for (k = 0; k < N; k++) {
			for (int i = 0; i < 32; i++)
				for (int j = 0; j < 32; j++)
					matrix[i][j] = epsilon[k * (32 * 32) + j + i * 32];
#if (DISPLAY_MATRICES == 1)
			display_matrix(32, 32, matrix);
#endif
			R = computeRank(32, 32, (unsigned char**)matrix);
			if (R == 32)
				F_32++;			/* DETERMINE FREQUENCIES */
			if (R == 31)
				F_31++;
		}
		F_30 = (double)N - (F_32 + F_31);

		chi_squared = (pow(F_32 - N * p_32, 2) / (double)(N * p_32) +
			pow(F_31 - N * p_31, 2) / (double)(N * p_31) +
			pow(F_30 - N * p_30, 2) / (double)(N * p_30));

		arg1 = -chi_squared / 2.e0;

		fprintf(*stats, "\t\t\t\tRANK TEST\n");
		fprintf(*stats, "\t\t---------------------------------------------\n");
		fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
		fprintf(*stats, "\t\t---------------------------------------------\n");
		fprintf(*stats, "\t\t(a) Probability P_%d = %f\n", 32, p_32);
		fprintf(*stats, "\t\t(b)             P_%d = %f\n", 31, p_31);
		fprintf(*stats, "\t\t(c)             P_%d = %f\n", 30, p_30);
		fprintf(*stats, "\t\t(d) Frequency   F_%d = %d\n", 32, (int)F_32);
		fprintf(*stats, "\t\t(e)             F_%d = %d\n", 31, (int)F_31);
		fprintf(*stats, "\t\t(f)             F_%d = %d\n", 30, (int)F_30);
		fprintf(*stats, "\t\t(g) # of matrices    = %d\n", N);
		fprintf(*stats, "\t\t(h) Chi^2            = %f\n", chi_squared);
		fprintf(*stats, "\t\t(i) NOTE: %d BITS WERE DISCARDED.\n", n % (32 * 32));
		fprintf(*stats, "\t\t---------------------------------------------\n");

		p_value = exp(arg1);
		if (isNegative(p_value) || isGreaterThanOne(p_value))
			fprintf(*stats, "WARNING:  P_VALUE IS OUT OF RANGE.\n");

	}
	for (size_t i = 0; i < 32; i++) {
		free(matrix[i]);
	}
	free(matrix);
	fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
	fflush(*stats);
	//fprintf(results[TEST_RANK], "%f\n", p_value); fflush(results[TEST_RANK]);
}
void DiscreteFourierTransform(int n, FILE** stats, unsigned char* epsilon) {
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "DiscreteFourierTransform.txt", "a+")) {
	//		return;
	//	}
	//}
	//else
	//	return;
	double	p_value, upperBound, percentile, N_l, N_o, d, * m = NULL, * X = NULL, * wsave = NULL;
	int		i, count, ifac[15];

	if (((X = (double*)calloc(n, sizeof(double))) == NULL) ||
		((wsave = (double*)calloc(2 * n, sizeof(double))) == NULL) ||
		((m = (double*)calloc(n / 2 + 1, sizeof(double))) == NULL)) {
		fprintf(*stats, "\t\tUnable to allocate working arrays for the DFT.\n");
		if (X != NULL)
			free(X);
		if (wsave != NULL)
			free(wsave);
		if (m != NULL)
			free(m);
		return;
	}
	for (i = 0; i < n; i++)
		X[i] = 2 * (int)epsilon[i] - 1;

	__ogg_fdrffti(n, wsave, ifac);		/* INITIALIZE WORK ARRAYS */
	__ogg_fdrfftf(n, X, wsave, ifac);	/* APPLY FORWARD FFT */

	m[0] = sqrt(X[0] * X[0]);	    /* COMPUTE MAGNITUDE */

	for (i = 0; i < n / 2; i++)
		m[i + 1] = sqrt(pow(X[2 * i + 1], 2) + pow(X[2 * i + 2], 2));
	count = 0;				       /* CONFIDENCE INTERVAL */
	upperBound = sqrt(2.995732274 * n);
	for (i = 0; i < n / 2; i++)
		if (m[i] < upperBound)
			count++;
	percentile = (double)count / (n / 2) * 100;
	N_l = (double)count;       /* number of peaks less than h = sqrt(3*n) */
	N_o = (double)0.95 * n / 2.0;
	d = (N_l - N_o) / sqrt(n / 4.0 * 0.95 * 0.05);
	p_value = erfc(fabs(d) / sqrt(2.0));

	fprintf(*stats, "\t\t\t\tFFT TEST\n");
	fprintf(*stats, "\t\t-------------------------------------------\n");
	fprintf(*stats, "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(*stats, "\t\t-------------------------------------------\n");
	fprintf(*stats, "\t\t(a) Percentile = %f\n", percentile);
	fprintf(*stats, "\t\t(b) N_l        = %f\n", N_l);
	fprintf(*stats, "\t\t(c) N_o        = %f\n", N_o);
	fprintf(*stats, "\t\t(d) d          = %f\n", d);
	fprintf(*stats, "\t\t-------------------------------------------\n");

	fprintf(*stats, "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value);
	fprintf(*stats, "%f\n", p_value);

	free(X);
	free(wsave);
	free(m);
	//if (stats || fileno(*stats) != -1)
	//	fclose(*stats);
}

void NonOverlappingTemplateMatchings(int m, int n, FILE** stats, unsigned char* epsilon) {
	//if (stats || fileno(*stats) != -1) {
	//	fclose(*stats);
	//	if (fopen_s(stats, "NonOverlappingTemplateMatchings.txt", "a+")) {
	//		return;
	//	}
	//}
	//else if (fopen_s(stats, "NonOverlappingTemplateMatchings.txt", "a+"))
	//	return;
	int		numOfTemplates[100] = { 0, 0, 2, 4, 6, 12, 20, 40, 74, 148, 284, 568, 1116,
		2232, 4424, 8848, 17622, 35244, 70340, 140680, 281076, 562152 };
	/*----------------------------------------------------------------------------
	NOTE:  Should additional templates lengths beyond 21 be desired, they must
	first be constructed, saved into files and then the corresponding
	number of nonperiodic templates for that file be stored in the m-th
	position in the numOfTemplates variable.
	----------------------------------------------------------------------------*/
	unsigned int	bit, W_obs, nu[6], * Wj = NULL;
	FILE* fp = NULL;
	double			sum, chi2, p_value, lambda, pi[6], varWj;
	int				i, j, jj, k, match, SKIP, M, N, K = 5;
	char			directory[100];
	BitSequence* sequence = NULL;

	N = 8;
	M = n / N;

	if ((Wj = (unsigned int*)calloc(N, sizeof(unsigned int))) == NULL) {
		fprintf(*stats, "\tNONOVERLAPPING TEMPLATES TESTS ABORTED DUE TO ONE OF THE FOLLOWING : \n");
		fprintf(*stats, "\tInsufficient memory for required work space.\n");
		return;
	}
	lambda = (M - m + 1) / pow(2, m);
	varWj = M * (1.0 / pow(2.0, m) - (2.0 * m - 1.0) / pow(2.0, 2.0 * m));
	sprintf(directory, "templates/template%d", m);

	if (((isNegative(lambda)) || (isZero(lambda))) ||
		((fp = fopen(directory, "r")) == NULL) ||
		((sequence = (BitSequence*)calloc(m, sizeof(BitSequence))) == NULL)) {
		fprintf(*stats, "\tNONOVERLAPPING TEMPLATES TESTS ABORTED DUE TO ONE OF THE FOLLOWING : \n");
		fprintf(*stats, "\tLambda (%f) not being positive!\n", lambda);
		fprintf(*stats, "\tTemplate file <%s> not existing\n", directory);
		fprintf(*stats, "\tInsufficient memory for required work space.\n");
		if (sequence != NULL)
			free(sequence);
	}
	else {
		fprintf(*stats, "\t\t  NONPERIODIC TEMPLATES TEST\n");
		fprintf(*stats, "-------------------------------------------------------------------------------------\n");
		fprintf(*stats, "\t\t  COMPUTATIONAL INFORMATION\n");
		fprintf(*stats, "-------------------------------------------------------------------------------------\n");
		fprintf(*stats, "\tLAMBDA = %f\tM = %d\tN = %d\tm = %d\tn = %d\n", lambda, M, N, m, n);
		fprintf(*stats, "-------------------------------------------------------------------------------------\n");
		fprintf(*stats, "\t\tF R E Q U E N C Y\n");
		fprintf(*stats, "Template   W_1  W_2  W_3  W_4  W_5  W_6  W_7  W_8    Chi^2   P_value Assignment Index\n");
		fprintf(*stats, "-------------------------------------------------------------------------------------\n");

		if (numOfTemplates[m] < MAXNUMOFTEMPLATES)
			SKIP = 1;
		else
			SKIP = (int)(numOfTemplates[m] / MAXNUMOFTEMPLATES);
		numOfTemplates[m] = (int)numOfTemplates[m] / SKIP;

		sum = 0.0;
		for (i = 0; i < 2; i++) {                      /* Compute Probabilities */
			pi[i] = exp(-lambda + i * log(lambda) - cephes_lgam(i + 1));
			sum += pi[i];
		}
		pi[0] = sum;
		for (i = 2; i <= K; i++) {                      /* Compute Probabilities */
			pi[i - 1] = exp(-lambda + i * log(lambda) - cephes_lgam(i + 1));
			sum += pi[i - 1];
		}
		pi[K] = 1 - sum;

		for (jj = 0; jj < MIN(MAXNUMOFTEMPLATES, numOfTemplates[m]); jj++) {
			sum = 0;

			for (k = 0; k < m; k++) {
				fscanf(fp, "%d", &bit);
				sequence[k] = bit;
				fprintf(*stats, "%d", sequence[k]);
			}
			fprintf(*stats, " ");
			for (k = 0; k <= K; k++)
				nu[k] = 0;
			for (i = 0; i < N; i++) {
				W_obs = 0;
				for (j = 0; j < M - m + 1; j++) {
					match = 1;
					for (k = 0; k < m; k++) {
						if ((int)sequence[k] != (int)epsilon[i * M + j + k]) {
							match = 0;
							break;
						}
					}
					if (match == 1) {
						W_obs++;
						j += m - 1;
					}
				}
				Wj[i] = W_obs;
			}
			sum = 0;
			chi2 = 0.0;                                   /* Compute Chi Square */
			for (i = 0; i < N; i++) {
				if (m == 10)
					fprintf(*stats, "%3d  ", Wj[i]);
				else
					fprintf(*stats, "%4d ", Wj[i]);
				chi2 += pow(((double)Wj[i] - lambda) / pow(varWj, 0.5), 2);
			}
			p_value = cephes_igamc(N / 2.0, chi2 / 2.0);

			if (isNegative(p_value) || isGreaterThanOne(p_value))
				fprintf(*stats, "\t\tWARNING:  P_VALUE IS OUT OF RANGE.\n");

			fprintf(*stats, "%9.6f %f %s %3d\n", chi2, p_value, p_value < ALPHA ? "FAILURE" : "SUCCESS", jj);
			if (SKIP > 1)
				fseek(fp, (long)(SKIP - 1) * 2 * m, SEEK_CUR);
			fprintf(*stats, "%f\n", p_value);
			fflush(*stats);
		}
	}

	fprintf(*stats, "\n"); fflush(*stats);
	if (sequence != NULL)
		free(sequence);

	free(Wj);
	//if (fp != NULL)
	//	fclose(fp);
}

void nist_test_suite(FILE** stats, unsigned char* epsilon, size_t* testVector, test_parameters tp) {
	if ((testVector[0] == 1) || (testVector[TEST_FREQUENCY] == 1))
		Frequency(tp.n, stats, epsilon);

	if ((testVector[0] == 1) || (testVector[TEST_BLOCK_FREQUENCY] == 1))
		BlockFrequency(tp.blockFrequencyBlockLength, tp.n, stats, epsilon);

	if ((testVector[0] == 1) || (testVector[TEST_CUSUM] == 1))
		CumulativeSums(tp.n, stats, epsilon);

	if ((testVector[0] == 1) || (testVector[TEST_RUNS] == 1))
		Runs(tp.n, stats, epsilon);

	if ((testVector[0] == 1) || (testVector[TEST_LONGEST_RUN] == 1))
		LongestRunOfOnes(tp.n, stats, epsilon);

	if ((testVector[0] == 1) || (testVector[TEST_RANK] == 1))
		Rank(tp.n, stats, epsilon);

	if ((testVector[0] == 1) || (testVector[TEST_FFT] == 1))
		DiscreteFourierTransform(tp.n, stats, epsilon);

	//if ((testVector[0] == 1) || (testVector[TEST_NONPERIODIC] == 1))
	//	NonOverlappingTemplateMatchings(tp.nonOverlappingTemplateBlockLength, tp.n, stats, epsilon);

	//if ((testVector[0] == 1) || (testVector[TEST_OVERLAPPING] == 1))
	//	OverlappingTemplateMatchings(tp.overlappingTemplateBlockLength, tp.n);

	//if ((testVector[0] == 1) || (testVector[TEST_UNIVERSAL] == 1))
	//	Universal(tp.n);

	//if ((testVector[0] == 1) || (testVector[TEST_APEN] == 1))
	//	ApproximateEntropy(tp.approximateEntropyBlockLength, tp.n);

	//if ((testVector[0] == 1) || (testVector[TEST_RND_EXCURSION] == 1))
	//	RandomExcursions(tp.n);

	//if ((testVector[0] == 1) || (testVector[TEST_RND_EXCURSION_VAR] == 1))
	//	RandomExcursionsVariant(tp.n);

	//if ((testVector[0] == 1) || (testVector[TEST_SERIAL] == 1))
	//	Serial(tp.serialBlockLength, tp.n);

	//if ((testVector[0] == 1) || (testVector[TEST_LINEARCOMPLEXITY] == 1))
	//	LinearComplexity(tp.linearComplexitySequenceLength, tp.n);
}

double lcg_rand(int N, double SEED, double* DUNIF, int NDIM) {
	int    i;
	double	DZ, DOVER, DZ1, DZ2, DOVER1, DOVER2;
	double	DTWO31, DMDLS, DA1, DA2;

	DTWO31 = 2147483648.0; /* DTWO31=2**31  */
	DMDLS = 2147483647.0; /* DMDLS=2**31-1 */
	DA1 = 41160.0;       /* DA1=950706376 MOD 2**16 */
	DA2 = 950665216.0;   /* DA2=950706376-DA1 */

	DZ = SEED;
	if (N > NDIM)
		N = NDIM;
	for (i = 1; i <= N; i++) {
		DZ = floor(DZ);
		DZ1 = DZ * DA1;
		DZ2 = DZ * DA2;
		DOVER1 = floor(DZ1 / DTWO31);
		DOVER2 = floor(DZ2 / DTWO31);
		DZ1 = DZ1 - DOVER1 * DTWO31;
		DZ2 = DZ2 - DOVER2 * DTWO31;
		DZ = DZ1 + DZ2 + DOVER1 + DOVER2;
		DOVER = floor(DZ / DMDLS);
		DZ = DZ - DOVER * DMDLS;
		DUNIF[i - 1] = DZ / DMDLS;
		SEED = DZ;
	}
	return SEED;
}

void lcg(FILE* stats, unsigned char* epsilon, size_t* test_vector, test_parameters tp) {
	//if (!stats || fileno(stats) != -1) {
	//	fclose(stats);
	//	if (fopen_s(&stats, "lcg.txt", "a+")) {
	//		return;
	//	}
	//}
	//else if (fopen_s(&stats, "lcg.txt", "a+"))
	//	return;
	double* DUNIF, SEED;
	int		i, counter;
	unsigned bit;
	int		num_0s, num_1s, v, bitsRead;

	SEED = 23482349.0;
	if (((epsilon = (unsigned char*)calloc(tp.n, sizeof(unsigned char))) == NULL) ||
		((DUNIF = (double*)calloc(tp.n, sizeof(double))) == NULL)) {
		printf("Insufficient memory available.\n");
		return;
	}
	counter = 1;

	for (v = 0; v < tp.numOfBitStreams; v++) {
		num_0s = 0;
		num_1s = 0;
		bitsRead = 0;
		SEED = lcg_rand(tp.n, SEED, DUNIF, tp.n);
		for (i = 0; i < tp.n; i++) {
			if (DUNIF[i] < 0.5) {
				bit = 0;
				num_0s++;
			}
			else {
				bit = 1;
				num_1s++;
			}
			bitsRead++;
			epsilon[i] = bit;
		}
		fprintf(stats, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s);
		fflush(stats);
		nist_test_suite(&stats, epsilon, test_vector, tp);
	}
	free(DUNIF);
	free(epsilon);
}

void quadRes1(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	//if (!freqfp || fileno(freqfp) != -1) {
	//	fclose(freqfp);
	//	if (fopen_s(&freqfp, "quadRes1.txt", "a+")) {
	//		return;
	//	}
	//}
	//else if (fopen_s(&freqfp, "quadRes1.txt", "a+"))
	//	return;
	int		k, num_0s, num_1s, bitsRead, done;
	BYTE	p[64], g[64], x[128];

	if (((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL)) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	ahtopb("987b6a6bf2c56a97291c445409920032499f9ee7ad128301b5d0254aa1a9633fdbd378d40149f1e23a13849f3d45992f5c4c6b7104099bc301f6005f9d8115e1", p, 64);
	ahtopb("3844506a9456c564b8b8538e0cc15aff46c95e69600f084f0657c2401b3c244734b62ea9bb95be4923b9b7e84eeaf1a224894ef0328d44bc3eb3e983644da3f5", g, 64);
	num_0s = 0;
	num_1s = 0;
	done = 0;
	bitsRead = 0;
	for (k = 0; k < tp.numOfBitStreams; k++) {
		num_0s = 0;
		num_1s = 0;
		done = 0;
		bitsRead = 0;
		do {
			memset(x, 0x00, 128);
			ModMult(x, g, 64, g, 64, p, 64);
			memcpy(g, x + 64, 64);
			done = convertToBits(g, 512, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
		} while (!done);
		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);

	//fclose(freqfp);
	//return;
}

void quadRes2(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	BYTE	g[64], x[129], t1[65];
	BYTE	One[1], Two, Three[1];
	int		k, num_0s, num_1s, bitsRead, done;

	if (((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL)) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	One[0] = 0x01;
	Two = 0x02;
	Three[0] = 0x03;

	ahtopb("7844506a9456c564b8b8538e0cc15aff46c95e69600f084f0657c2401b3c244734b62ea9bb95be4923b9b7e84eeaf1a224894ef0328d44bc3eb3e983644da3f5", g, 64);

	for (k = 0; k < tp.numOfBitStreams; k++) {
		num_0s = 0;
		num_1s = 0;
		done = 0;
		bitsRead = 0;
		do {
			memset(t1, 0x00, 65);
			memset(x, 0x00, 129);
			smult(t1, Two, g, 64);		/* 2x */
			add(t1, 65, Three, 1);		/* 2x+3 */
			Mult(x, t1, 65, g, 64);		/* x(2x+3) */
			add(x, 129, One, 1);		/* x(2x+3)+1 */
			memcpy(g, x + 65, 64);
			done = convertToBits(g, 512, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
		} while (!done);
		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);

	return;
}

void cubicRes(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	BYTE	g[64], tmp[128], x[192];
	int		k, num_0s, num_1s, bitsRead, done;

	if (((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL)) {
		printf("Insufficient memory available.\n");
		exit(1);
	}

	ahtopb("7844506a9456c564b8b8538e0cc15aff46c95e69600f084f0657c2401b3c244734b62ea9bb95be4923b9b7e84eeaf1a224894ef0328d44bc3eb3e983644da3f5", g, 64);

	for (k = 0; k < tp.numOfBitStreams; k++) {
		num_0s = 0;
		num_1s = 0;
		bitsRead = 0;
		done = 0;
		do {
			memset(tmp, 0x00, 128);
			memset(x, 0x00, 192);
			Mult(tmp, g, 64, g, 64);
			Mult(x, tmp, 128, g, 64); // Don't need to mod by 2^512, just take low 64 bytes
			memcpy(g, x + 128, 64);
			done = convertToBits(g, 512, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
		} while (!done);
		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);

	return;
}

void exclusiveOR(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	int		i, num_0s, num_1s, bitsRead;
	BYTE	bit_sequence[127];

	if (((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL)) {
		printf("Insufficient memory available.\n");
		exit(1);
	}

	memcpy(bit_sequence, "0001011011011001000101111001001010011011101101000100000010101111111010100100001010110110000000000100110000101110011111111100111", 127);
	num_0s = 0;
	num_1s = 0;
	bitsRead = 0;
	for (i = 0; i < 127; i++) {
		if (bit_sequence[i]) {
			epsilon[bitsRead] = 1;
			num_1s++;
		}
		else {
			epsilon[bitsRead] = 0;
			num_1s++;
		}
		bitsRead++;
	}
	for (i = 127; i < tp.n * tp.numOfBitStreams; i++) {
		if (bit_sequence[(i - 1) % 127] != bit_sequence[(i - 127) % 127]) {
			bit_sequence[i % 127] = 1;
			epsilon[bitsRead] = 1;
			num_1s++;
		}
		else {
			bit_sequence[i % 127] = 0;
			epsilon[bitsRead] = 0;
			num_0s++;
		}
		bitsRead++;
		if (bitsRead == tp.n) {
			fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
			nist_test_suite(&freqfp, epsilon, test_vector, tp);
			num_0s = 0;
			num_1s = 0;
			bitsRead = 0;
		}
	}
	free(epsilon);

	return;
}

void modExp(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	int		k, num_0s, num_1s, bitsRead, done;
	BYTE	p[64], g[64], x[192], y[20];

	if ((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	ahtopb("7AB36982CE1ADF832019CDFEB2393CABDF0214EC", y, 20);
	ahtopb("987b6a6bf2c56a97291c445409920032499f9ee7ad128301b5d0254aa1a9633fdbd378d40149f1e23a13849f3d45992f5c4c6b7104099bc301f6005f9d8115e1", p, 64);
	ahtopb("3844506a9456c564b8b8538e0cc15aff46c95e69600f084f0657c2401b3c244734b62ea9bb95be4923b9b7e84eeaf1a224894ef0328d44bc3eb3e983644da3f5", g, 64);

	for (k = 0; k < tp.numOfBitStreams; k++) {
		num_0s = 0;
		num_1s = 0;
		bitsRead = 0;
		done = 0;
		do {
			memset(x, 0x00, 128);
			ModExp(x, g, 64, y, 20, p, 64);	      /* NOTE:  g must be less than p */
			done = convertToBits(x, 512, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
			memcpy(y, x + 44, 20);
		} while (!done);
		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);

	return;
}

void bbs(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	int		i, v, bitsRead;
	BYTE	p[64], q[64], n[128], s[64], x[256];
	int		num_0s, num_1s;

	if ((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	ahtopb("E65097BAEC92E70478CAF4ED0ED94E1C94B154466BFB9EC9BE37B2B0FF8526C222B76E0E915017535AE8B9207250257D0A0C87C0DACEF78E17D1EF9DC44FD91F", p, 64);
	ahtopb("E029AEFCF8EA2C29D99CB53DD5FA9BC1D0176F5DF8D9110FD16EE21F32E37BA86FF42F00531AD5B8A43073182CC2E15F5C86E8DA059E346777C9A985F7D8A867", q, 64);
	memset(n, 0x00, 128);
	Mult(n, p, 64, q, 64);
	memset(s, 0x00, 64);
	ahtopb("10d6333cfac8e30e808d2192f7c0439480da79db9bbca1667d73be9a677ed31311f3b830937763837cb7b1b1dc75f14eea417f84d9625628750de99e7ef1e976", s, 64);
	memset(x, 0x00, 256);
	ModSqr(x, s, 64, n, 128);

	for (v = 0; v < tp.numOfBitStreams; v++) {
		num_0s = 0;
		num_1s = 0;
		bitsRead = 0;
		for (i = 0; i < tp.n; i++) {
			ModSqr(x, x, 128, n, 128);
			memcpy(x, x + 128, 128);
			if ((x[127] & 0x01) == 0) {
				num_0s++;
				epsilon[i] = 0;
			}
			else {
				num_1s++;
				epsilon[i] = 1;
			}
			bitsRead++;
			if ((i % 50000) == 0)
				printf("\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s);
		}

		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);
}

void micali_schnorr(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	long	i, j;
	int		k = 837, num_0s, num_1s, bitsRead, done;
	BYTE	p[64], q[64], n[128], e[1], X[128], Y[384], Tail[105];

	if ((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	ahtopb("E65097BAEC92E70478CAF4ED0ED94E1C94B154466BFB9EC9BE37B2B0FF8526C222B76E0E915017535AE8B9207250257D0A0C87C0DACEF78E17D1EF9DC44FD91F", p, 64);
	ahtopb("E029AEFCF8EA2C29D99CB53DD5FA9BC1D0176F5DF8D9110FD16EE21F32E37BA86FF42F00531AD5B8A43073182CC2E15F5C86E8DA059E346777C9A985F7D8A867", q, 64);
	memset(n, 0x00, 128);
	Mult(n, p, 64, q, 64);
	e[0] = 0x0b;
	memset(X, 0x00, 128);
	ahtopb("237c5f791c2cfe47bfb16d2d54a0d60665b20904ec822a6", X + 104, 24);

	for (i = 0; i < tp.numOfBitStreams; i++) {
		num_0s = 0;
		num_1s = 0;
		bitsRead = 0;
		do {
			ModExp(Y, X, 128, e, 1, n, 128);
			memcpy(Tail, Y + 23, 105);
			for (j = 0; j < 3; j++)
				bshl(Tail, 105);
			done = convertToBits(Tail, k, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
			memset(X, 0x00, 128);
			memcpy(X + 104, Y, 24);
			for (j = 0; j < 5; j++)
				bshr(X + 104, 24);
		} while (!done);

		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);
}

////  Uses 160 bit Xkey and no XSeed (b=160)
////  This is the generic form of the generator found on the last page of the Change Notice for FIPS 186-2
//void SHA1(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
//{
//	ULONG	A, B, C, D, E, temp, Wbuff[16];
//	BYTE	Xkey[20], G[20], M[64];
//	BYTE	One[1] = { 0x01 };
//	int		i, num_0s, num_1s, bitsRead;
//	int		done;
//	ULONG	tx[5] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
//
//	if (((epsilon = (BitSequence*)calloc(tp.n, sizeof(BitSequence))) == NULL)) {
//		printf("Insufficient memory available.\n");
//		exit(1);
//	}
//
//	ahtopb("ec822a619d6ed5d9492218a7a4c5b15d57c61601", Xkey, 20);
//	//	ahtopb("E65097BAEC92E70478CAF4ED0ED94E1C94B15446", Xkey, 20);
//	//	ahtopb("6BFB9EC9BE37B2B0FF8526C222B76E0E91501753", Xkey, 20);
//	//	ahtopb("5AE8B9207250257D0A0C87C0DACEF78E17D1EF9D", Xkey, 20);
//	//	ahtopb("D99CB53DD5FA9BC1D0176F5DF8D9110FD16EE21F", Xkey, 20);
//
//	for (i = 0; i < tp.numOfBitStreams; i++) {
//		num_0s = 0;
//		num_1s = 0;
//		bitsRead = 0;
//		do {
//			memcpy(M, Xkey, 20);
//			memset(M + 20, 0x00, 44);
//
//			// Start: SHA Steps A-E
//			A = tx[0];
//			B = tx[1];
//			C = tx[2];
//			D = tx[3];
//			E = tx[4];
//
//			memcpy((BYTE*)Wbuff, M, 64);
//#ifdef LITTLE_ENDIAN
//			byteReverse(Wbuff, 20);
//#endif
//			sub1Round1(0);  sub1Round1(1);  sub1Round1(2);  sub1Round1(3);
//			sub1Round1(4);  sub1Round1(5);  sub1Round1(6);  sub1Round1(7);
//			sub1Round1(8);  sub1Round1(9);  sub1Round1(10); sub1Round1(11);
//			sub1Round1(12); sub1Round1(13); sub1Round1(14); sub1Round1(15);
//			sub2Round1(16); sub2Round1(17); sub2Round1(18); sub2Round1(19);
//			Round2(20); Round2(21); Round2(22); Round2(23);
//			Round2(24); Round2(25); Round2(26); Round2(27);
//			Round2(28); Round2(29); Round2(30); Round2(31);
//			Round2(32); Round2(33); Round2(34); Round2(35);
//			Round2(36); Round2(37); Round2(38); Round2(39);
//			Round3(40); Round3(41); Round3(42); Round3(43);
//			Round3(44); Round3(45); Round3(46); Round3(47);
//			Round3(48); Round3(49); Round3(50); Round3(51);
//			Round3(52); Round3(53); Round3(54); Round3(55);
//			Round3(56); Round3(57); Round3(58); Round3(59);
//			Round4(60); Round4(61); Round4(62); Round4(63);
//			Round4(64); Round4(65); Round4(66); Round4(67);
//			Round4(68); Round4(69); Round4(70); Round4(71);
//			Round4(72); Round4(73); Round4(74); Round4(75);
//			Round4(76); Round4(77); Round4(78); Round4(79);
//
//			A += tx[0];
//			B += tx[1];
//			C += tx[2];
//			D += tx[3];
//			E += tx[4];
//
//			memcpy(G, (BYTE*)&A, 4);
//			memcpy(G + 4, (BYTE*)&B, 4);
//			memcpy(G + 8, (BYTE*)&C, 4);
//			memcpy(G + 12, (BYTE*)&D, 4);
//			memcpy(G + 16, (BYTE*)&E, 4);
//#ifdef LITTLE_ENDIAN
//			byteReverse((ULONG*)G, 20);
//#endif
//			// End: SHA Steps A-E
//
//			done = convertToBits(G, 160, tp.n, &num_0s, &num_1s, &bitsRead);
//			add(Xkey, 20, G, 20);
//			add(Xkey, 20, One, 1);
//		} while (!done);
//		fprintf(freqfp, "\t\tBITSREAD = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); fflush(freqfp);
//		nist_test_suite(&freqfp, epsilon, test_vector, tp);
//	}
//	free(epsilon);
//}

void testRand(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp) {

	if ((epsilon = (unsigned char*)calloc(tp.n, sizeof(unsigned char))) == NULL) {
		printf("Insufficient memory available.\n");
		exit(1);
	}

	short number = 0;
	for (int i = 0; i < tp.numOfBitStreams; i++) {
		int num_0s = 0;
		int num_1s = 0;
		int done;
		int bitsRead = 0;
		do {
			number = rand();
			done = convertToBits(&number, 16, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
		} while (!done);

		fprintf(freqfp, "\t\t testRand = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s); 
		fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);
}

void testSRand(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp) {

	if ((epsilon = (unsigned char*)calloc(tp.n, sizeof(unsigned char))) == NULL) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	srand(time(0));
	unsigned int number = 0;
	for (int i = 0; i < tp.numOfBitStreams; i++) {
		int num_0s = 0;
		int num_1s = 0;
		int done;
		int bitsRead = 0;
		do {
			number = rand_s(&number);
			done = convertToBits(&number, 32, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
		} while (!done);

		fprintf(freqfp, "\t\t testSRand = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s);
		fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);
}

void testRDRand(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp) {

	if ((epsilon = (unsigned char*)calloc(tp.n, sizeof(unsigned char))) == NULL) {
		printf("Insufficient memory available.\n");
		exit(1);
	}
	unsigned int number = 0;
	for (int i = 0; i < tp.numOfBitStreams; i++) {
		int num_0s = 0;
		int num_1s = 0;
		int done;
		int bitsRead = 0;
		do {
			_rdrand32_step(&number);
			done = convertToBits(&number, 32, tp.n, &num_0s, &num_1s, &bitsRead, epsilon);
		} while (!done);

		fprintf(freqfp, "\t\t testRDRand = %d 0s = %d 1s = %d\n", bitsRead, num_0s, num_1s);
		fflush(freqfp);
		nist_test_suite(&freqfp, epsilon, test_vector, tp);
	}
	free(epsilon);
}
//C++
//void testMersenneTwisterEngine(FILE* freqfp, unsigned char* epsilon, size_t* test_vector, test_parameters tp) {
//
//	if ((epsilon = (unsigned char*)calloc(tp.n, sizeof(unsigned char))) == NULL) {
//		printf("Insufficient memory available.\n");
//		exit(1);
//	}    
//	std::random_device rd;
//	std::mt19937 gen(rd());
//
//	std::mt19937::mersenne_twister_engine<unsigned int, 32, 624, 397,
//		31, 0x9908b0df,
//		11, 0xffffffff,
//		7, 0x9d2c5680,
//		15, 0xefc60000,
//		18, 1812433253> mt19937;
//
//	unsigned int number = 0;
//	for (size_t i = 0; i < tp.n; i++) {
//		_rdrand32_step(&number);
//		epsilon[i] = number & 1;
//	}
//	nist_test_suite(&freqfp, epsilon, test_vector, tp);
//	free(epsilon);
//}

void statisticsTest(char* nameFile, void (**functions)(FILE*, unsigned char*, size_t*, test_parameters), char** nameFunctions, size_t number_functions, unsigned char* epsilon, size_t* test_vector, test_parameters tp)
{
	FILE* streamFile = NULL;
	fopen_s(&streamFile, nameFile, "a+");
	fprintf(streamFile, "________________________________________________________________________________\n\n");
	fprintf(streamFile, "\t\tFILE = %s\t\tALPHA = %6.4f\n", streamFile, ALPHA);
	fprintf(streamFile, "________________________________________________________________________________\n\n");

	for (size_t i = 0; i < number_functions; i++) {
		fprintf(streamFile, "\n\n\n\n");
		fprintf(streamFile, "\t\tTEST = %s\t\t\n", nameFunctions[i]);
		fprintf(streamFile, "\n\n\n\n");
		functions[i](streamFile, epsilon, test_vector, tp);
	}

	printf("     Statistical Testing Complete!!!!!!!!!!!!\n\n");
	fclose(streamFile);
}

void testStatisticsTest(char* nameFile) {

	size_t testVector[15];
	for (size_t i = 0; i < SIZEOF(testVector); i++)
		testVector[i] = 1;
	unsigned char* epsilon = 0;
	void (*functions[])(FILE*, unsigned char*, size_t*, test_parameters) = { testRand, testSRand, testRDRand, lcg, quadRes1 };
	char* nameFunctions[] = { "testRand", "testSRand", "testRDRand", "lcg", "quadRes1" };

	test_parameters tp;

	tp.n = 256000;
	tp.blockFrequencyBlockLength = 128;
	tp.nonOverlappingTemplateBlockLength = 9;
	tp.overlappingTemplateBlockLength = 9;
	tp.approximateEntropyBlockLength = 10;
	tp.serialBlockLength = 16;
	tp.linearComplexitySequenceLength = 500;
	tp.numOfBitStreams = 1;

	statisticsTest(nameFile, functions, nameFunctions, SIZEOF(functions), epsilon, testVector, tp);
}
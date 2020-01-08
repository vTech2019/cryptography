#pragma once

//https://www.cosic.esat.kuleuven.be/nessie/testvectors/bc/des/Des-64-64.test-vectors
#include <stdint.h>
#include "DataEncryptionStandard.h"
struct DES_test {
	uint64_t key;
	uint64_t plain;
	uint64_t cipher;
	uint64_t encrypted;
	uint64_t decrypted;
	uint64_t iterated_100_times;
	uint64_t iterated_1000_times;
};
#ifdef __DEBUG__DES__
#ifdef __cplusplus
extern "C" {
#endif

	void DataEncryptionStandardConsoleDebugTest();

#ifdef __cplusplus
}
#endif
#endif
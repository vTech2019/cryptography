#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#ifndef __DES__
#define __DES__
#define __DEBUG__DES__

struct DESinfo {
	uint64_t* blocks;
	size_t numberBlocks;
};
#ifdef __cplusplus
extern "C" {
#endif
	struct DESinfo DataEncryptionStandardEncrypt(uint8_t* data, size_t lengthData, uint64_t key);
	void DataEncryptionStandardDecrypt(struct DESinfo* data, uint64_t key);
#ifdef __cplusplus
}
#endif
#endif
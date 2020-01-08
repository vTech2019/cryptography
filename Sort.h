#pragma once
#include <stdint.h>
#include <stddef.h>
//#define gnomeSort(X, Y, Z, W)          \
//    _Generic((X),       \
//    uint8_t*: gnomeSortU8,       \
//    size_t*: gnomeSortSZ     \
//)(X, Y, Z, W)

void gnomeSortU8(uint8_t* array, size_t length, uint8_t* data, size_t length_block);
void gnomeSortSZ(size_t* array, size_t length, uint8_t* data, size_t length_block);
void gnomeSortU16(uint16_t* array, size_t length, uint8_t* data, size_t length_block);
void gnomeSortU32(uint32_t* array, size_t length, uint8_t* data, size_t length_block);
void gnomeSortU64(uint64_t* array, size_t length, uint8_t* data, size_t length_block);

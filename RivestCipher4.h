#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#ifndef __RivestCipher4__
#define __RivestCipher4__

#ifdef _DEBUG
#include "RivestCipher4Debug.h"
#endif 

void RivestCipher4Encrypt(uint8_t* data, size_t lengthData, uint8_t* key, size_t keyLength);
#endif
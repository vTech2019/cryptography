#include "FileOperations.h"

errno_t readStrings(const char* nameFile, uint8_t** memory, uint8_t*** strings, size_t numberText, size_t* lengthText) {
	FILE* file = NULL;
	errno_t errorCode = 0;
	if (errorCode = fopen_s(&file, nameFile, "rb")) goto error;
	if (fseek(file, 0, SEEK_END)) goto error;
	*lengthText = ftell(file) / numberText;
	if (fseek(file, 0, SEEK_SET)) goto error;
	if (!(*memory = (uint8_t*)malloc(*lengthText * numberText + numberText * sizeof(uint8_t*)))) goto error;
	if (!fread(*memory, *lengthText * numberText, 1, file)) goto error;
	size_t offset = *lengthText * numberText;
	size_t* ptrText = (size_t*)(*memory + offset);
	for (size_t i = 0; i < numberText; i++) {
		ptrText[i] = (size_t)(*memory + i * *lengthText);
	}
	*strings = (uint8_t**)ptrText;
	if (fclose(file))goto error;
	return 0;
error:
	if (*memory) free(*memory);
	if (file) errorCode = ferror(file);
	fprintf(stderr, "Error message : %s\n", strerror(errorCode));
	*memory = NULL;
	*strings = NULL;
	*lengthText = 0;
	return errorCode;
}

errno_t readFile(const char* nameFile, uint8_t** memory, int32_t* sizeFile)
{
	FILE* file = NULL;
	errno_t errorCode = 0;
	if (errorCode = fopen_s(&file, nameFile, "rb")) goto error;
	if (fseek(file, 0, SEEK_END)) goto error;
	*sizeFile = ftell(file);
	if (fseek(file, 0, SEEK_SET)) goto error;
	if (!(*memory = (uint8_t*)malloc(*sizeFile))) goto error;
	if (!fread(*memory, *sizeFile, 1, file)) goto error;
	if (fclose(file))goto error;
	return 0;
error:
	if (*memory) free(*memory);
	if (file) errorCode = ferror(file);
	fprintf(stderr, "Error message : %s\n", strerror(errorCode));
	*memory = NULL;
	return errorCode;
}

errno_t writeFile(const char* nameFile, uint8_t* memory, int32_t sizeMemory)
{
	FILE* file = NULL;
	errno_t errorCode = 0;
	if (errorCode = fopen_s(&file, nameFile, "wb")) goto error;
	if (!fwrite(memory, sizeMemory, 1, file)) goto error;
	if (fclose(file))goto error;
	return 0;
error:
	if (file) errorCode = ferror(file);
	fprintf(stderr, "Error message : %s\n", strerror(errorCode));
	return errorCode;
}

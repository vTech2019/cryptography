#include "CRC32.h"
#include "DataEncryptionStandard.h"
#include "FileOperations.h"
#include "OneTimePad.h"
#include "RivestCipher4.h"
#include "Caesar.h"
#include "RSA.h"
#include "BigInteger.h"
#include "statistics/StatisticTest.h"

int main() {	
	//testConsoleBigInteger();//необходим для работы RSA

	//testStatisticsTest("E://resultTest.txt");
	//testCaesarOneSymbol("E://dictionary.txt", "E://text.txt", "E://decryptText.txt", 10);
	//exTestManyTimePadAttack("E://dictionary.txt", "E://text.txt", "E://decryptText", 10);
	//DataEncryptionStandardConsoleDebugTest();
	//createHistogramCRC32BirthdayParadox(20, 200, 20000, 60);
	//RC4Debug();
	testRSA(); // нужны быстрые алгоритмы возведения в степень и деление 
	return 0;
}
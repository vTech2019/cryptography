#include "CRC32.h"
#include "DataEncryptionStandard.h"
#include "FileOperations.h"
#include "OneTimePad.h"
#include "RivestCipher4.h"
#include "Caesar.h"
#include "RSA.h"
#include "BigInteger.h"
int main() {
	struct BigInteger value_0 = initBigInteger8U("-45743734853763429873427693874693726983758609734697409687467834886348654865485486548", 84);
	struct BigInteger value_1 = initBigInteger8U("-4364374734673827609374609732409687309673209476983746983274986734967389476938476938756", 86);
	printConsoleBigInteger(&value_0);
	printConsoleBigInteger(&value_1);
	//struct BigInteger result = subtractBigInteger(&value_1, &value_0);
	struct BigInteger result = divideBigInteger(&value_1, &value_0);
	printConsoleBigInteger(&result);
	//testCaesarOneSymbol("dictionary.txt", "text.txt", "decryptText.txt", 10);
	//testManyTimePadAttack("dictionary.txt", "text.txt", "decryptText.txt", 10, 255);
	//DataEncryptionStandardConsoleDebugTest();
	//createHistogramCRC32BirthdayParadox(20, 200, 20000, 60);
	//RC4Debug();
	testRSA();
	return 0;
}
#include "Helpers.h"
#include "src/config/Config.h"
#include <math.h>
#include <iostream>

unsigned char Helpers::BinaryStringToChar(const String& binStr) {
	unsigned binStrLength = binStr.getLength();
	String reversed = binStr.reverse();
	unsigned char res = 0;

	for (size_t i = 0; i < binStrLength; i++)
	{
		if (reversed[i] == '1') {
			res += pow(2, i);
		}
	}

	return res;
}

String Helpers::CharToBinaryString(unsigned char symbol) {
	String res;

	while (symbol) {
		res += (symbol % 2 != 0) + '0';
		symbol /= 2;
	}

	unsigned int resLength = res.getLength();
	res = res.reverse();

	while (res.getLength() != 8) {
		res = String{ "0" } + res;
	}

	return res;
}

String Helpers::convertCodeForDebugging(const String& binCode) {
	String res;
	unsigned int binCodeLength = binCode.getLength();
	for (unsigned int i = 0; i < binCodeLength; i += 8)
	{
		res += binCode.substring(i, 8);
		if (i != binCodeLength - 9) {
			res += " ";
		}
	}

	return res;
}

void Helpers::exitProgram() {
	unsigned int commandsParametersSize = Config::commandsParameters.getSize();
	for (size_t i = 0; i < commandsParametersSize; i++)
	{
		delete Config::commandsParameters[i];
	}

	exit(EXIT_SUCCESS);
}
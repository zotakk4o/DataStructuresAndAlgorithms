#include "Helpers.h"
#include <math.h>

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
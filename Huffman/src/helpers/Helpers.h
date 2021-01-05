#ifndef HELPERS_H
#define HELPERS_H

#include "include/String.h"

class Helpers
{
	public:
		static unsigned char BinaryStringToChar(const String&);
		static String CharToBinaryString(unsigned char);
		static String convertCodeForDebugging(const String&);
		static void exitProgram();
		virtual ~Helpers() = 0;
};

#endif


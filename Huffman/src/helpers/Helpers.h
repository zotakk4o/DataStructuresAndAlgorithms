#ifndef HELPERS_H
#define HELPERS_H

#include "include/String.h"

class Helpers
{
	public:
		static unsigned char BinaryStringToChar(const String&);
		virtual ~Helpers() = 0;
};

#endif


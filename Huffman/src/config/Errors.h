#ifndef ERRORS_H
#define ERRORS_H

#include "include/String.h"

class Errors {
	public:
		static const String wrongCommandError;
		static const String invalidInput;
		static const String invalidSymbol;
		virtual ~Errors() = 0;
};

#endif
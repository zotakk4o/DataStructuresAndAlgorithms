#ifndef ERRORS_H
#define ERRORS_H

#include "include/String.h"

class Errors {
	public:
		static const String wrongCommandError;
		static const String invalidInput;
		static const String invalidSymbol;
		static const String couldNotSaveCodeError;
		static const String couldNotSaveTreeError;
		static const String couldNotReadCodeError;
		static const String couldNotReadTreeError;
		virtual ~Errors() = 0;
};

#endif
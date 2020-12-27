#ifndef COMMANDPARAMETER_H
#define COMMANDPARAMETER_H

#include "include/String.h"

class CommandParameter{
	public:
		virtual void execute(const String&) const = 0;
		virtual String toString() const = 0;
		bool isValid(const String&) const;
};

#endif
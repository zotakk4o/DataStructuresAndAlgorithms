#ifndef FILECOMMAND_H
#define FILECOMMAND_H

#include "include/String.h"

class Command
{
	public:
		virtual void execute() const = 0;
		virtual String toString() const = 0;
		bool isValid(const String&) const;
};

#endif

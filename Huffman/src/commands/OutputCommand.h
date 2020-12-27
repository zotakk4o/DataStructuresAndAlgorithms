#ifndef OUTPUTCOMMAND_H
#define OUTPUTCOMMAND_H

#include "BaseClasses/CommandParameter.h"
#include "include/String.h"

class OutputCommand :
	public CommandParameter
{
	public:
		virtual void execute(const String&) const;
		virtual String toString() const;
};

#endif


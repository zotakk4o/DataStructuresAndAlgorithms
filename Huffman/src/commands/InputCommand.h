#ifndef INPUTCOMMAND_H
#define INPUTCOMMAND_H

#include "BaseClasses/CommandParameter.h"
#include "include/String.h"

class InputCommand :
	public CommandParameter
{
	public:
		virtual void execute(const String&) const;
		virtual String toString() const;
};

#endif


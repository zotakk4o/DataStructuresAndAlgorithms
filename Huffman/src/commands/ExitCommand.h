#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "BaseClasses/Command.h"
#include "include/String.h"

class ExitCommand :
	public Command
{
	public:
		virtual void execute() const;
		virtual String toString() const;
};

#endif


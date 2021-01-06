#ifndef DEBUGCOMMAND_H
#define DEBUGCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

/// <summary>
/// A Class responsible for handling the debuging process. Command usage is "debug"
/// </summary>
class DebugCommand :
	public CommandParameters
{
	public:
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


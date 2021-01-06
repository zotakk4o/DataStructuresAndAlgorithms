#ifndef INPUTCOMMAND_H
#define INPUTCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

/// <summary>
/// A Class responsible for indicating the input file. Command usage is "i <file-name>"
/// </summary>
class InputCommand :
	public CommandParameters
{
	public:
		virtual unsigned int getKeywordsCount() const;
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


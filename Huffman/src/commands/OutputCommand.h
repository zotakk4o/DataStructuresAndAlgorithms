#ifndef OUTPUTCOMMAND_H
#define OUTPUTCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

/// <summary>
/// A Class responsible for indicating the output file. Command usage is "o <file-name>"
/// </summary>
class OutputCommand :
	public CommandParameters
{
	public:
		virtual unsigned int getKeywordsCount() const;
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


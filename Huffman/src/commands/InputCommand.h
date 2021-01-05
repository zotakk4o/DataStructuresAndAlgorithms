#ifndef INPUTCOMMAND_H
#define INPUTCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

class InputCommand :
	public CommandParameters
{
	public:
		virtual unsigned int getKeywordsCount() const;
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


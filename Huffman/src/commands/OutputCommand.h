#ifndef OUTPUTCOMMAND_H
#define OUTPUTCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

class OutputCommand :
	public CommandParameters
{
	public:
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


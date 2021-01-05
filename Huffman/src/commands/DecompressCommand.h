#ifndef DECOMPRESSCOMMAND_H
#define DECOMPRESSCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

class DecompressCommand : public CommandParameters
{
	public:
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


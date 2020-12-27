#ifndef DECOMPRESSCOMMAND_H
#define DECOMPRESSCOMMAND_H

#include "BaseClasses/Command.h"
#include "include/String.h"

class DecompressCommand : public Command
{
	public:
		virtual void execute() const;
		virtual String toString() const;
};

#endif


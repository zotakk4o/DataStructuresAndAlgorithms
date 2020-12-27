#ifndef COMPRESSCOMMAND_H
#define COMPRESSCOMMAND_H

#include "BaseClasses/Command.h"

class CompressCommand : public Command {
	public:
		virtual void execute() const;
		virtual String toString() const;
};

#endif

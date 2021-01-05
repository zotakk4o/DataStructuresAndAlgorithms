#ifndef COMPRESSCOMMAND_H
#define COMPRESSCOMMAND_H

#include "BaseClasses/CommandParameters.h"

class CompressCommand : public CommandParameters {
	public:
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif

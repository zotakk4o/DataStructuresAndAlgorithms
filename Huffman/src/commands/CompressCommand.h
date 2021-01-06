#ifndef COMPRESSCOMMAND_H
#define COMPRESSCOMMAND_H

#include "BaseClasses/CommandParameters.h"

/// <summary>
/// A Class responsible for handling the compression process. Command usage is "c"
/// </summary>
class CompressCommand : public CommandParameters {
	public:
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif

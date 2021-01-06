#ifndef DECOMPRESSCOMMAND_H
#define DECOMPRESSCOMMAND_H

#include "BaseClasses/CommandParameters.h"
#include "include/String.h"

/// <summary>
/// A Class responsible for handling the decompression process. Command usage is "d"
/// </summary>
class DecompressCommand : public CommandParameters
{
	public:
		virtual void execute(Vector<String*>&) const;
		virtual String toString() const;
};

#endif


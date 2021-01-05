#ifndef COMMANDPARAMETERS_H
#define COMMANDPARAMETERS_H

#include "include/String.h"

class CommandParameters{
	public:
		virtual unsigned int getKeywordsCount() const;
		virtual void execute(Vector<String*>&) const = 0;
		virtual String toString() const = 0;
		bool isValid(const Vector<String>&) const;
};

#endif
#ifndef DBCOMMANDSPROCESSOR_H
#define DBCOMMANDSPROCESSOR_H

#include "include/String.h"
#include "CommandsProcessor.h"

class CommandsProcessor {
	protected:
		void parseCommands();
		bool parseCommand(const String&);
	public:
		void start();
};

#endif 

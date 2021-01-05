#ifndef DBCOMMANDSPROCESSOR_H
#define DBCOMMANDSPROCESSOR_H

#include "include/String.h"
#include "CommandsProcessor.h"

/// <summary>
/// Class responsible for command pattern execution
/// </summary>
class CommandsProcessor {
	private:
		String inputFileName;
		String outputFileName;

		void parseCommands();
		bool parseCommand(const String&);
	public:
		void start();
};

#endif 

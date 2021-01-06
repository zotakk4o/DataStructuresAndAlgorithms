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

		/// <summary>
		/// Parses input commands from console
		/// </summary>
		void parseCommands();

		/// <summary>
		/// Parses a given command
		/// </summary>
		bool parseCommand(const String&);
	public:
		void start();
};

#endif 

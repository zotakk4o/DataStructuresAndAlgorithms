#ifndef CONFIG_H
#define CONFIG_H

#include "include/String.h"
#include "include/Vector.cpp"
#include "../commands/BaseClasses/CommandParameters.h"
#include <iostream>

/// <summary>
/// Class responsible for storing project configuration
/// </summary>
class Config {
	public:
		static const char commandDelimiter;
		static std::istream& inputStream;
		static const Vector<CommandParameters*> commandsParameters;
		static const String treeFileNameSuffix;
		static const String inputFileCommand;
		static const String outputFileCommand;
		virtual ~Config() = 0;
};
 
#endif
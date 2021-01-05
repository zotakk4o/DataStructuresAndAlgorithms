#include "CommandsProcessor.h"
#include "config/Config.h"
#include "config/Errors.h"
#include "include/File.h"

void CommandsProcessor::parseCommands() {
	String command;
	while (true)
	{
		String::getLine(Config::inputStream, command);
		try {
			if (!this->parseCommand(command)) {
				std::cerr << Errors::wrongCommandError << std::endl;
			}
		}
		catch (const String& err) {
			std::cerr << err << std::endl;
		}
		
	}
}

bool CommandsProcessor::parseCommand(const String& command) {
	if (!command.getLength()) {
		return false;
	}

	Vector<String> keywords = command.split(Config::commandDelimiter);
	Vector<String*> parameters;
	if (keywords.getSize() == 2) {
		parameters.pushBack(&keywords[1]);
	}
	parameters.pushBack(&this->inputFileName);
	parameters.pushBack(&this->outputFileName);
	
	unsigned int commandsParametersSize = Config::commandsParameters.getSize();
	for (unsigned int i = 0; i < commandsParametersSize; i++)
	{
		if (Config::commandsParameters[i]->isValid(keywords)) {
			Config::commandsParameters[i]->execute(parameters);
			return true;
		}
	}

	return false;
}

void CommandsProcessor::start() {
	this->parseCommands();
}
#include "CommandsProcessor.h"
#include "config/Config.h"
#include "config/Errors.h"
#include "include/File.h"
#include "config/Errors.h"

void CommandsProcessor::parseCommands() {
	String command;
	File file;

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

	unsigned int dbCommandsSize = Config::commands.getSize();
	for (unsigned int i = 0; i < dbCommandsSize; i++)
	{
		if (Config::commands[i]->isValid(keywords[0])) {
			Config::commands[i]->execute();
			return true;
		}
	}

	if (keywords.getSize() != 2) {
		return false;
	}

	unsigned int dbCommandsParametersSize = Config::commandsParameter.getSize();
	for (unsigned int i = 0; i < dbCommandsParametersSize; i++) {
		if (Config::commandsParameter[i]->isValid(keywords[0])) {
			Config::commandsParameter[i]->execute(keywords[1]);
			return true;
		}
	}

	return false;
}

void CommandsProcessor::start() {
	this->parseCommands();
}
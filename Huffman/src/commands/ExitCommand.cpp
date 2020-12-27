#include "ExitCommand.h"
#include "src/config/Config.h"
#include <stdlib.h>

void ExitCommand::execute() const {
	//Delete commands
	for (size_t i = 0; i < Config::commands.getSize(); i++)
	{
		delete Config::commands[i];
	}

	for (size_t i = 0; i < Config::commandsParameter.getSize(); i++)
	{
		delete Config::commandsParameter[i];
	}

	exit(EXIT_SUCCESS);
}

String ExitCommand::toString() const {
	return "exit";
}
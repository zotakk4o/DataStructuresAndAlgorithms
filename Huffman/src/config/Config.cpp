#include "Config.h"
#include "src/commands/CompressCommand.h"
#include "src/commands/DecompressCommand.h"
#include "src/commands/InputCommand.h"
#include "src/commands/OutputCommand.h"
#include "src/commands/ExitCommand.h"

const char Config::commandDelimiter = ' ';

std::istream& Config::inputStream = std::cin;

const String Config::treeFileNameSuffix = "-tree.dat";

const Vector<Command*> Config::commands{
	new CompressCommand(),
	new DecompressCommand(),
	new ExitCommand()
};

const Vector<CommandParameter*> Config::commandsParameter{
	new InputCommand(),
	new OutputCommand()
};

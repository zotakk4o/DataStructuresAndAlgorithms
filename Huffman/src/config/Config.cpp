#include "Config.h"
#include "src/commands/CompressCommand.h"
#include "src/commands/DecompressCommand.h"
#include "src/commands/InputCommand.h"
#include "src/commands/OutputCommand.h"
#include "src/commands/DebugCommand.h"

const char Config::commandDelimiter = ' ';

std::istream& Config::inputStream = std::cin;

const String Config::treeFileNameSuffix = "-tree.dat";

static const String inputFileCommand = InputCommand{}.toString();
static const String outputFileCommand = OutputCommand{}.toString();

const Vector<CommandParameters*> Config::commandsParameters{
	new CompressCommand(),
	new DecompressCommand(),
	new InputCommand(),
	new OutputCommand(),
	new DebugCommand()
};

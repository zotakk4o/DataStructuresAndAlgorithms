#include "DebugCommand.h"

#include "src/HuffmanDecoder.h"
#include "src/helpers/Helpers.h"
#include "include/File.h"

void DebugCommand::execute(Vector<String*>& filesNames) const {
	HuffmanDecoder::debug(*filesNames[0]);
	Helpers::exitProgram();
}

String DebugCommand::toString() const {
	return "debug";
}
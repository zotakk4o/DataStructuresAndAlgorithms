#include "OutputCommand.h"

unsigned int OutputCommand::getKeywordsCount() const {
	return 2;
}

void OutputCommand::execute(Vector<String*>& parameters) const {
	*parameters[2] = *parameters[0];
}

String OutputCommand::toString() const {
	return "o";
}
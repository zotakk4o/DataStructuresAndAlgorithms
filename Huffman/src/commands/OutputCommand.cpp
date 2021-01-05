#include "OutputCommand.h"

void OutputCommand::execute(Vector<String*>& parameters) const {
	*parameters[2] = *parameters[0];
}

String OutputCommand::toString() const {
	return "o";
}
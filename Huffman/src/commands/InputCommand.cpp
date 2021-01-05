#include "InputCommand.h"

unsigned int InputCommand::getKeywordsCount() const {
	return 2;
}

void InputCommand::execute(Vector<String*>& parameters) const {
	*parameters[1] = *parameters[0];
}

String InputCommand::toString() const {
	return "i";
}
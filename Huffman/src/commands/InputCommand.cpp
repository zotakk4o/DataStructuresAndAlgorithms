#include "InputCommand.h"

void InputCommand::execute(Vector<String*>& parameters) const {
	*parameters[1] = *parameters[0];
}

String InputCommand::toString() const {
	return "i";
}
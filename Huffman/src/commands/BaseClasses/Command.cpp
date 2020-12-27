#include "Command.h"

bool Command::isValid(const String& keyword) const {
	return this->toString() == keyword;
}
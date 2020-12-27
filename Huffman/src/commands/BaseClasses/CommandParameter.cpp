#include "CommandParameter.h"

bool CommandParameter::isValid(const String& keyword) const {
	return this->toString() == keyword;
}
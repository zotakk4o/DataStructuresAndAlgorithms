#include "CommandParameters.h"

bool CommandParameters::isValid(const Vector<String>& keywords) const {
	return this->toString() == keywords[0];
}
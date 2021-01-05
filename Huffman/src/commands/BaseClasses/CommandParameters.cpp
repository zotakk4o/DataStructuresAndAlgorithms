#include "CommandParameters.h"

unsigned int CommandParameters::getKeywordsCount() const {
	return 1;
}

bool CommandParameters::isValid(const Vector<String>& keywords) const {
	return this->toString() == keywords[0] && keywords.getSize() == this->getKeywordsCount();
}
#include "Flavoured.h"

Flavoured::Flavoured(const String& _flavour) : flavour(_flavour) {}

Flavoured::~Flavoured() {}

void Flavoured::setFlavour(const String& _flavour) {
	this->flavour = _flavour;
}

String Flavoured::getFlavour() const {
	return this->flavour;
}
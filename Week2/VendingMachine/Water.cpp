#include "Water.h"

Water::Water(const double& price, const int& _bottleSize) : Item(price), bottleSize(_bottleSize) {}

void Water::setBottleSize(const int& bottleSize) {
	this->bottleSize = bottleSize;
}
int Water::getBottleSize(const int&) const {
	return this->bottleSize;
}
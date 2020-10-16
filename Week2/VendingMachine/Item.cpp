#include "Item.h"

Item::Item(const double& _price) : price(_price) {}

Item::~Item() {}

void Item::setPrice(const double& _price) {
	this->price = _price;
}

double Item::getPrice() const {
	return this->price;
}
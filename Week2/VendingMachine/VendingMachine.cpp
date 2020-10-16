#include "VendingMachine.h"
#include<iostream>
int VendingMachine::slots = 4;

VendingMachine::VendingMachine() {
	for (size_t i = 0; i < VendingMachine::slots; i++)
	{
		this->items.pushBack(Stack<Item*>{});
	}
}
VendingMachine::~VendingMachine() {
	for (size_t i = 0; i < this->items.getSize(); i++)
	{
		while (!this->items[i].isEmpty()) {
			delete this->items[i].pop();
		}
	}
}

bool VendingMachine::hasEmpty() const {
	if (this->items.getSize() == 0) {
		return true;
	}

	for (size_t i = 0; i < this->items.getSize(); i++)
	{
		if (this->items[i].isEmpty()) {
			return true;
		}
	}

	return false;
}

void VendingMachine::addItems(const int& slot, Stack<Item*>& items) {
	while (!items.isEmpty()) {
		this->items[slot].push(items.pop());
	}
}

Item* VendingMachine::consume(const int& slot) {
	return this->items[slot].pop();
}
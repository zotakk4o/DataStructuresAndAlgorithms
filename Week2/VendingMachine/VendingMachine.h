#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "include/Vector.cpp"
#include "include/Stack.cpp"
#include "Item.h"

class VendingMachine {
	private:
		static int slots;
		Vector<Stack<Item*>> items;
	public:
		VendingMachine();
		~VendingMachine();

		bool hasEmpty() const;
		void addItems(const int&, Stack<Item*>&);
		Item* consume(const int&);
};

#endif
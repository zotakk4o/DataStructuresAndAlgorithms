#include<iostream>
#include "VendingMachine.h"
#include "Cola.h"
#include "Croissant.h"
#include "BakeRolls.h"
#include "Water.h"

int main() {
	VendingMachine testMachine;
	Stack<Item*> colas;
	colas.push(new Cola("cherry", 5));
	colas.push(new Cola("lemon", 4.5));
	testMachine.addItems(0, colas);
	delete testMachine.consume(0);
	std::cout << testMachine.hasEmpty();

	return 0;
}
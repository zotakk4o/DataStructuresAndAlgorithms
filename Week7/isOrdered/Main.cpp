#include "include/BST.cpp"
#include <iostream>
int main() {
	BST<int, int> test{ {{0, 0}, {1, 1}, {0, 0}, {2, 2}} };
	std::cout << test.isOrdered() << std::endl;
	BST<int, int> test2{ {{0, 0}, {1, 1}, {2, 2}} };
	std::cout << test2.isOrdered() << std::endl;
	return 0;
}
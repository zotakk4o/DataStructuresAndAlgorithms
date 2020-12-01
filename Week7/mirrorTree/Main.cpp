#include "include/BST.cpp"
#include <iostream>

int main() {
	BST<int, int> test{ {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}} };
	std::cout << "Before Mirror: " << std::endl;
	test.prittyPrint();
	test.mirrorTree();
	std::cout << "After Mirror: " << std::endl;
	test.prittyPrint();
	test.mirrorTree();
	std::cout << "After Mirror: " << std::endl;
	test.prittyPrint();
	test.remove(0);
	test.remove(1);
	std::cout << "Before Mirror: " << std::endl;
	test.prittyPrint();
	test.mirrorTree();
	std::cout << "After Mirror: " << std::endl;
	test.prittyPrint();
	return 0;
}
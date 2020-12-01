#include "include/BST.cpp"
#include <iostream>
int main() {
	BST<int, int> test{ {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}} };
	std::cout << test.isBalanced() << std::endl;
	test.remove(0);
	std::cout << test.isBalanced() << std::endl;
	test.remove(1);
	std::cout << test.isBalanced() << std::endl;
	test.insert(5, 5);
	std::cout << test.isBalanced() << std::endl;
	BST<int, int> test2{ {{0, 0}, {1, 1}, {2, 2}} };
	std::cout << test2.isBalanced() << std::endl;
	return 0;
}
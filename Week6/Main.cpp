#include <iostream>
#include "BST.cpp"

int main() {
	BST<int, int> testTree{ {{0, 0}, {1, 1}, {2, 2}, {3, 3}} };
	std::cout << testTree.calculateHeight();
	return 0;
}
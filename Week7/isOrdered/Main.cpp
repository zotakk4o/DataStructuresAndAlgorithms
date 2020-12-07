#include "include/BST.cpp"
#include <iostream>
int main() {
	BST<int, int> test{ {{0, 0}, {1, 1}, {0, 0}, {2, 2}} };
	std::cout << test.isOrdered(INT32_MIN, INT32_MAX) << std::endl;
	BST<int, int> test2{ {{3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}} };
	std::cout << test2.isOrdered(INT32_MIN, INT32_MAX) << std::endl;
	return 0;
}
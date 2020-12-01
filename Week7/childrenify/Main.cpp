#include "include/BST.cpp"
#include <iostream>

int main() {
	BST<int, int> test;
	test.insert(3, 3);
	test.insert(2, 2);
	test.insert(1, 1);
	test.insert(0, 0);
	test.childrenify();
	test.prittyPrint();
	std::cout << "!!!!!TREE DIVIDER!!!!!" << std::endl;
	BST<int, int> test2;
	test2.insert(10, 10);
	test2.insert(5, 5);
	test2.insert(2, 2);
	test2.insert(20, 20);
	test2.insert(15, 15);
	test2.insert(25, 25);
	test2.insert(22, 22);
	test2.childrenify();
	test2.prittyPrint();
	return 0;
}
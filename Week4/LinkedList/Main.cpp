#include "include/LinkedList.cpp"
#include <iostream>

int main() {
	LinkedList<int> test;
	LinkedList<int> test2;

	test.insertEnd(5);
	test.insertEnd(4);
	test.insertEnd(3);
	test.insertEnd(2);
	test.insertEnd(1);
	test2.insertBeg(7);
	test2.insertBeg(6);
	std::cout << test.getMidNode() << std::endl;
	std::cout << test.getNth(3) << std::endl;
	test.recursiveReverse();
	LinkedList<int>::append(test, test2);
	while (!test.empty()) {
		std::cout << test.pop();
	}
	return 0;
}
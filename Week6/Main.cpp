#include <iostream>
#include "BST.cpp"
#include <fstream>

int main() {
	BST<int, int> testTree{ {{0, 5}, {0, 0}, {1, 1}, {2, 2}, {2, 3}, {3, 4}} };
	testTree.prittyPrint();
	std::cout << "Tree Height: " << testTree.calculateHeight() << std::endl;
	std::cout << "Tree contains 5?: " << testTree.contains(5) << std::endl;
	std::cout << "Tree contains 4?: " << testTree.contains(4) << std::endl;
	std::cout << "Tree contains 3?: " << testTree.contains(3) << std::endl;
	std::cout << "Tree contains 2?: " << testTree.contains(2) << std::endl;
	std::cout << "Tree contains 1?: " << testTree.contains(1) << std::endl;
	std::cout << "Tree contains 0?: " << testTree.contains(0) << std::endl;
	std::cout << "Tree contains -1?: " << testTree.contains(-1) << std::endl;
	std::cout << "Tree leaves sum: " << testTree.sumLeaves() << std::endl;
	std::cout << "Tree leaves count: " << testTree.countLeaves() << std::endl;
	std::cout << "Remove first key 0: " << testTree.remove(2) << std::endl;
	testTree.prittyPrint();
	std::ofstream testStream;
	testStream.open("test.txt", std::fstream::trunc);
	testTree.serializeTree(testStream);
	testStream.close();
	return 0;
}
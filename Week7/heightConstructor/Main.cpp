#include "include/BST.cpp"

void createPerfectlyBalancedBinaryTree(BST<unsigned int, unsigned int>& tree, const unsigned int& height) {
	Vector<std::pair<unsigned int, unsigned int>> input;
	int currNode = 0;
	for (size_t currHeight = 0; currHeight <= height; currHeight++)
	{
		for (size_t j = 0; j < pow(2, currHeight); j++) {
			input.pushBack({ currNode, currNode });
			currNode++;
		}
	}

	tree = BST<unsigned int, unsigned int>{input};
}

int main() {
	BST<unsigned int, unsigned int> test;
	createPerfectlyBalancedBinaryTree(test, 3);
	test.prittyPrint();
	return 0;
}
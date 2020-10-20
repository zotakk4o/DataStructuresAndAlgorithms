#include "StackMax.cpp"
#include<iostream>

int main() {
	StackMax<int> testStack;
	testStack.push(4);
	std::cout << "Max: " << testStack.max() << std::endl;
	testStack.push(10);
	testStack.push(2);
	testStack.push(3);
	std::cout << "Max: " << testStack.max() << std::endl;
	testStack.pop();
	testStack.pop();
	std::cout << "Max: " << testStack.max() << std::endl;
	testStack.pop();
	std::cout << "Max: " << testStack.max() << std::endl;

	return 0;
}
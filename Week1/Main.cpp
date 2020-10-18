#include "Stack.cpp"
#include<iostream>

int main() {
	Stack<int> elements;
	elements.push(4);
	std::cout << elements.max();
	elements.push(5);
	std::cout << elements.peek();
	std::cout << elements.max();
	std::cout << elements.pop();
	std::cout << elements.max();
	return 0;
}
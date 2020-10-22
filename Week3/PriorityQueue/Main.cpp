#include "PriorityQueue.cpp"
#include <iostream>

int main() {
	PriorityQueue<int> test;
	test.enqueue(5, 'h');
	test.enqueue(1);
	test.enqueue(2, 'h');
	test.enqueue(3, 'l');

	while (!test.isEmpty()) {
		std::cout << test.dequeue() << std::endl;
	}

	return 0;
}
#include "SSQueue.cpp"
#include<iostream>

int main() {
	SSQueue<int> test;
	test.enqueue(1);
	test.enqueue(2);
	test.enqueue(3);
	std::cout << test.dequeue() << std::endl;
	test.enqueue(4);
	test.enqueue(5);
	while (!test.isEmpty()) {
		std::cout << test.dequeue() << std::endl;
	}



	return 0;
}
#include "LQueue.cpp"
#include<iostream>

int main() {
	LQueue<int> testQueue;
	std::cout << testQueue.size() << std::endl;
	std::cout << testQueue.isEmpty() << std::endl;
	testQueue.enqueue(4);
	testQueue.enqueue(5);
	testQueue.enqueue(6);
	
	while (!testQueue.isEmpty()) {
		std::cout << testQueue.dequeue() << std::endl;
	}
	
	return 0;
}
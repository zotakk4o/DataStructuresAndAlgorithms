#include "include/LQueue.cpp"
#include<iostream>

template<typename T>
LQueue<T> sortQueues(LQueue<T> first, LQueue<T> second) {
	LQueue<T> res;

	while (!first.isEmpty()) {
		if (!second.isEmpty()) {
			if (first.first() > second.first()) {
				res.enqueue(second.dequeue());
			}
			else if (first.first() < second.first()) {
				res.enqueue(first.dequeue());
			}
			else {
				res.enqueue(first.dequeue());
				res.enqueue(second.dequeue());
			}
			continue;
		}

		res.enqueue(first.dequeue());
	}

	while (!second.isEmpty()) {
		res.enqueue(second.dequeue());
	}

	return res;
}

int main() {
	LQueue<int> first;
	LQueue<int> second;
	LQueue<int> mixed;
	first.enqueue(1);
	first.enqueue(2);
	first.enqueue(3);
	first.enqueue(50);
	second.enqueue(25);
	second.enqueue(50);
	second.enqueue(51);

	mixed = sortQueues(first, second);
	while (!mixed.isEmpty()) {
		std::cout << mixed.dequeue() << std::endl;
	}

	return 0;
}
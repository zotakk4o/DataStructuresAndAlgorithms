#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "include/LQueue.cpp"

template<typename T>
class PriorityQueue
{
	private:
		LQueue<T> high, normal, low;
	public:
		void enqueue(const T&, const char& = 'n');
		T dequeue();
		bool isEmpty() const;
		int size() const;
};

#endif


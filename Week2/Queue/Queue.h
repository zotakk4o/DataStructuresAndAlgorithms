#ifndef QUEUE_H
#define QUEUE_H

#include "include/DataStructure.cpp"

template <typename T>
class Queue : DataStructure<T>
{
	public:
		void enqueue(const T&);
		T dequeue();
		bool isEmpty() const;
		int size() const;
};

#endif
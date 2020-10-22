#ifndef SSQUEUE_H
#define SSQUEUE_H

#include "include/Stack.cpp"

template<typename T>
class SSQueue 
{
	private:
		Stack<T> pushStack;
		Stack<T> popStack;
	public:	
		void enqueue(const T&);
		T dequeue();
		bool isEmpty() const;
		int size() const;
};

#endif

#ifndef STACK_H
#define STACK_H
#include "DataStructure.cpp"

template <typename T>
class Stack : private DataStructure<T>
{
	public:
		void push(const T&);
		T pop();
		T peek() const;
		bool isEmpty() const;
};

#endif
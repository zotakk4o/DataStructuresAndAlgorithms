#ifndef STACK_H
#define STACK_H
#include "DataStructure.cpp"

template <typename T>
class Stack : private DataStructure<T>
{
	public:
		virtual void push(const T&);
		virtual T pop();
		virtual T peek() const;
		virtual bool isEmpty() const;

		unsigned int getSize() const;
};

#endif
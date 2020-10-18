#ifndef STACK_H
#define STACK_H
#include "DataStructure.cpp"

template <typename T>
class Stack : private DataStructure<T>
{
	private:
		T maxElement;
	public:
		void push(const T&);
		T pop();
		T peek() const;
		bool isEmpty() const;
		T max() const;
};

#endif
#ifndef STACKMAX_H
#define STACKMAX_H

#include "include/Stack.cpp"

template<typename T>
class StackMax : public Stack<T>
{
	private:
		Stack<T> track;
	public:
		virtual void push(const T&);
		virtual T pop();
		T max() const;
};

#endif

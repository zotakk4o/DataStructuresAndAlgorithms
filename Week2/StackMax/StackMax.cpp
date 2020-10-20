#ifndef STACKMAX_CPP
#define STACKMAX_CPP

#include "StackMax.h"

template<typename T>
void StackMax<T>::push(const T& element) {
	if (this->isEmpty() || element > this->track.peek()) {
		this->track.push(element);
	}
	else {
		this->track.push(this->track.peek());
	}

	this->Stack<T>::push(element);
}

template<typename T>
T StackMax<T>::pop() {
	this->track.pop();
	return this->Stack<T>::pop();
}

template<typename T>
T StackMax<T>::max() const {
	return this->track.peek();
}

#endif
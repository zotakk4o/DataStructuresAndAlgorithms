#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

template<typename T>
void Stack<T>::push(const T& element) {
	if (this->isFull()) {
		this->reserve();
	}

	if (this->isEmpty()) {
		this->maxElement = element;
	}
	else if (element > this->maxElement) {
		this->data[this->size++] = 2 * element - this->maxElement;
		this->maxElement = element;
		return;
	}

	this->data[this->size++] = element;
}

template<typename T>
T Stack<T>::pop() {
	assert(this->size != 0);

	T topEl = this->data[this->size-- - 1];

	if (topEl > this->maxElement) {
		this->maxElement = 2 * this->maxElement - topEl;
		topEl = this->maxElement;
	}

	return topEl;
}

template<typename T>
T Stack<T>::peek() const {
	assert(this->size != 0);
	T topEl = this->data[this->size - 1];

	return topEl > this->maxElement ? this->maxElement : topEl;
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return this->size == 0;
}

template<typename T>
T Stack<T>::max() const {
	assert(!this->isEmpty());

	return this->maxElement;
}

#endif
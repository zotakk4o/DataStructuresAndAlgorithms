#ifndef SSQUEUE_CPP
#define SSQUEUE_CPP

#include "SSQueue.h"
#include <assert.h>

template<typename T>
void SSQueue<T>::enqueue(const T& element) {
	this->pushStack.push(element);
}

template<typename T>
T SSQueue<T>::dequeue() {
	assert(!this->pushStack.isEmpty() || !this->popStack.isEmpty());

	if (!this->popStack.isEmpty()) {
		return this->popStack.pop();
	}

	while (!this->pushStack.isEmpty()) {
		this->popStack.push(this->pushStack.pop());
	}

	return this->popStack.pop();
}

template<typename T>
bool SSQueue<T>::isEmpty() const {
	return this->pushStack.getSize() == 0 && this->popStack.getSize() == 0;
}

template<typename T>
int SSQueue<T>::size() const {
	return this->pushStack.getSize() + this->popStack.getSize();
}

#endif
#include "Stack.h"

template<typename T>
void Stack<T>::push(const T& element) {
	if (this->isFull()) {
		this->reserve();
	}
	this->data[this->size++] = element;
}

template<typename T>
T Stack<T>::pop() {
	assert(this->size != 0);

	return this->data[this->size-- - 1];
}

template<typename T>
T Stack<T>::peek() {
	assert(this->size != 0);

	return this->data[this->size - 1];
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return this->size == 0;
}
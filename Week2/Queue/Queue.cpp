#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template<typename T>
void Queue<T>::enqueue(const T& element) {

}

template<typename T>
T Queue<T>::dequeue() {

}

template<typename T>
bool Queue<T>::isEmpty() const {
	return this->size == 0;
}

template<typename T>
int Queue<T>::size() const {
	return this->size;
}

#endif

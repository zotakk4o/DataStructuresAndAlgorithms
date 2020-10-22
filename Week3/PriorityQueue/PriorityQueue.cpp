#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP

#include "PriorityQueue.h"
#include<assert.h>

template<typename T>
void PriorityQueue<T>::enqueue(const T& element, const char& priority) {
	assert(priority == 'h' || priority == 'n' || priority == 'l');

	if (priority == 'h') {
		this->high.enqueue(element);
	}
	else if (priority == 'n') {
		this->normal.enqueue(element);
	}
	else {
		this->low.enqueue(element);
	}
}

template<typename T>
T PriorityQueue<T>::dequeue() {
	assert(!this->high.isEmpty() || !this->normal.isEmpty() || !this->low.isEmpty());

	if (!this->high.isEmpty()) {
		return this->high.dequeue();
	}
	else if (!this->normal.isEmpty()) {
		return this->normal.dequeue();
	}

	return this->low.dequeue();
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const {
	return this->high.size() == 0 && this->normal.size() == 0 && this->low.size() == 0;
}

template<typename T>
int PriorityQueue<T>::size() const {
	return this->high.size() + this->normal.size() + this->low.size();
}

#endif
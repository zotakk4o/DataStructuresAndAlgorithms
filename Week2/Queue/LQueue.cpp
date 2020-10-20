#ifndef LQUEUE_CPP
#define LQUEUE_CPP

#include "LQueue.h"
#include<assert.h>

template<typename T>
QueueNode<T>::QueueNode(const T& _data) : data(_data), next(nullptr) {}

template<typename T>
LQueue<T>::LQueue() : front(nullptr), rear(nullptr) {}

template<typename T>
void LQueue<T>::enqueue(const T& element) {
	QueueNode<T>* newEl = new QueueNode<T>(element);

	if (front == nullptr) {
		front = rear = newEl;
		return;
	}

	rear->next = newEl;
	rear = newEl;
}

template<typename T>
T LQueue<T>::dequeue() {
	assert(this->front != nullptr);
	
	QueueNode<T>* temp = front;
	front = front->next;

	if (front == nullptr) {
		rear == nullptr;
	}

	T result = temp->data;
	delete temp;

	return result;
}

template<typename T>
bool LQueue<T>::isEmpty() const {
	return this->front == nullptr;
}

template<typename T>
int LQueue<T>::size() const {
	return this->rear - this->front;
}

#endif
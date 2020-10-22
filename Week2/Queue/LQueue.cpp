#ifndef LQUEUE_CPP
#define LQUEUE_CPP

#include "LQueue.h"
#include<assert.h>

template<typename T>
QueueNode<T>::QueueNode(const T& _data) : data(_data), next(nullptr) {}

template<typename T>
LQueue<T>::LQueue() : front(nullptr), rear(nullptr), queueSize(0) {}

template<typename T>
void LQueue<T>::copy(const LQueue<T>& other) {
	this->queueSize = other.queueSize;
	this->front = new QueueNode<T>(other.front->data);

	QueueNode<T>* currentFront = this->front;
	QueueNode<T>* newNode;
	QueueNode<T>* otherFront = other.front;

	while (otherFront != other.rear) {
		otherFront = otherFront->next;

		newNode = new QueueNode<T>(otherFront->data);

		currentFront->next = newNode;
		currentFront = newNode;
	}

	currentFront->next = nullptr;
	this->rear = currentFront;
}

template<typename T>
LQueue<T>::LQueue(const LQueue<T>& other) {
	this->copy(other);
}

template<typename T>
void LQueue<T>::deleteInternals() {
	if (this->queueSize == 0) {
		return;
	}
	while (this->front != this->rear) {
		QueueNode<T>* curr = this->front;
		this->front = this->front->next;

		delete curr;
	}

	delete this->rear;
}

template<typename T>
LQueue<T>& LQueue<T>::operator=(const LQueue<T>& other) {
	if (this != &other) {
		this->deleteInternals();
		this->copy(other);
	}

	return *this;
}

template<typename T>
LQueue<T>::~LQueue() {
	this->deleteInternals();
}

template<typename T>
void LQueue<T>::enqueue(const T& element) {
	QueueNode<T>* newEl = new QueueNode<T>(element);
	this->queueSize++;

	if (front == nullptr) {
		front = rear = newEl;
		return;
	}

	rear->next = newEl;
	rear = newEl;
}

template<typename T>
T LQueue<T>::dequeue() {
	assert(this->queueSize != 0);
	
	QueueNode<T>* temp = front;
	front = front->next;

	if (front == nullptr) {
		rear == nullptr;
	}

	T result = temp->data;
	delete temp;
	this->queueSize--;
	return result;
}

template<typename T>
T LQueue<T>::first() const {
	assert(this->queueSize != 0);

	return this->front->data;
}

template<typename T>
bool LQueue<T>::isEmpty() const {
	return this->queueSize == 0;
}

template<typename T>
int LQueue<T>::size() const {
	return this->queueSize;
}

#endif
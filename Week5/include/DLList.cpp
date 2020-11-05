#ifndef DLLIST_CPP
#define DLLIST_CPP

#include "DLList.h"
#include <assert.h>

template<typename T>
Node<T>::Node(const T& _data) : data(_data), next(nullptr), prev(nullptr) {}

template<typename T>
Iterator<T>::Iterator(Node<T>* _ptr, Node<T>* _end, bool _canIncrease, bool _canDecrease) : ptr(_ptr), end(_end), canIncrease(_canIncrease), canDecrease(_canDecrease) {}

template<typename T>
Iterator<T> Iterator<T>::next() const {
	if (!this->canIncrease || !this->ptr)
		return *this;

	return this->ptr->next == this->end ? Iterator<T>(this->ptr->next, this->end, false) : Iterator<T>(this->ptr->next, this->end, true);
}

template<typename T>
Iterator<T> Iterator<T>::prev() const {
	if (!this->canDecrease || !this->ptr)
		return *this;

	return this->ptr->prev == this->end ? Iterator<T>(this->ptr->prev, this->end, true, false) : Iterator<T>(this->ptr->prev, this->end, true, true);
}

template<typename T>
T const& Iterator<T>::getConst() const {
	return this->ptr->data;
}

template<typename T>
T& Iterator<T>::get() const {
	return this->ptr->data;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
	return (*this = this->next());
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator<T> curr = *this;
	++(*this);
	return curr;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--() {
	return (*this = this->prev());
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
	Iterator<T> curr = *this;
	--(*this);
	return curr;
}

template<typename T>
T& Iterator<T>::operator*() {
	return this->get();
}

template<typename T>
bool Iterator<T>::operator==(Iterator<T> const& it) const {
	return (this->ptr == nullptr && it.ptr == nullptr) || (this->ptr == it.ptr && it.canIncrease == this->canIncrease && it.canDecrease == this->canDecrease);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& it) const {
	return !(*this == it);
}

template<typename T>
Iterator<T>& Iterator<T>::operator+=(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		++(*this);
	}

	return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator-=(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		--(*this);
	}

	return *this;
}

template<typename T>
void DLList<T>::deleteInternals() {
	if (this->frontPtr == nullptr) {
		return;
	}

	if (this->dllistSize == 1) {
		delete this->frontPtr;
		this->frontPtr = nullptr;
		this->backPtr = nullptr;
		return;
	}

	while (this->frontPtr != this->backPtr) {
		Node<T>* curr = this->frontPtr;
		this->frontPtr = this->frontPtr->next;
		delete curr;
	}

	delete this->backPtr;
	this->dllistSize = 0;
	this->frontPtr = nullptr;
	this->backPtr = nullptr;
}

template<typename T>
void DLList<T>::copy(const DLList& other) {
	if (!other.dllistSize) {
		return;
	}

	this->dllistSize = other.dllistSize;
	this->frontPtr = new Node<T>(other.frontPtr->data);
	this->backPtr = this->frontPtr;
	this->backPtr->prev = this->frontPtr;
	this->frontPtr->next = this->backPtr;

	Node<T>* otherFront = other.frontPtr;
	while (otherFront != other.backPtr) {
		otherFront = otherFront->next;
		Node<T>* newEl = new Node<T>{ otherFront->data };

		this->backPtr->next = newEl;
		newEl->prev = this->backPtr;
		this->backPtr = newEl;
	}
	
	this->frontPtr->prev = this->backPtr;
	this->backPtr->next = this->frontPtr;
}

template<typename T>
DLList<T>::DLList() : dllistSize(0), frontPtr(nullptr), backPtr(nullptr) {}

template<typename T>
DLList<T>::DLList(const DLList& other) {
	this->copy(other);
}

template<typename T>
DLList<T>& DLList<T>::operator=(const DLList& other) {
	if (this != &other) {
		this->deleteInternals();
		this->copy(other);
	}

	return *this;
}

template<typename T>
DLList<T>::~DLList() {
	this->deleteInternals();
}

template<typename T>
bool DLList<T>::isEmpty() const {
	return this->dllistSize == 0;
}

template<typename T>
unsigned int DLList<T>::size() const {
	return this->dllistSize;
}

template<typename T>
T DLList<T>::front() const {
	assert(this->frontPtr);

	return this->frontPtr->data;
}

template<typename T>
T DLList<T>::back() const {
	assert(this->backPtr);
	return this->backPtr->data;
}

template<typename T>
void DLList<T>::assign(size_t n, const T& el) {
	for (size_t i = 0; i < n; i++)
	{
		this->pushBack(el);
	}
}

template<typename T>
void DLList<T>::pushFront(const T& el) {
	Node<T>* newEl = new Node<T>{ el };
	Node<T>* oldFrontPtr = newEl;

	if (this->frontPtr) {
		oldFrontPtr = this->frontPtr;
		this->frontPtr->prev = newEl;
	}
	else {
		this->backPtr = newEl;
		this->backPtr->prev = newEl;
	}
	
	this->frontPtr = newEl;
	this->backPtr->next = newEl;
	this->frontPtr->next = oldFrontPtr;
	this->frontPtr->prev = this->backPtr;
	this->dllistSize++;
}

template<typename T>
void DLList<T>::pushBack(const T& el) {
	Node<T>* newEl = new Node<T>{ el };
	Node<T>* oldBackPtr = newEl;

	if (this->backPtr) {
		oldBackPtr = this->backPtr;
		this->backPtr->next = newEl;
	}
	else {
		this->frontPtr = newEl;
		this->frontPtr->next = newEl;
	}

	this->backPtr = newEl;
	this->frontPtr->prev = newEl;
	this->backPtr->prev = oldBackPtr;
	this->backPtr->next = this->frontPtr;
	this->dllistSize++;
}

template<typename T>
T DLList<T>::popFront() {
	assert(!this->isEmpty());

	T currFrontData = this->frontPtr->data;
	Node<T>* currFront = this->frontPtr;

	if (this->dllistSize == 1) {
		this->frontPtr = nullptr;
		this->backPtr = nullptr;
	}
	else {
		this->frontPtr = this->frontPtr->next;
		this->frontPtr->prev = this->backPtr;
	}

	this->dllistSize--;
	delete currFront;
	return currFrontData;
}

template<typename T>
T DLList<T>::popBack() {
	assert(!this->isEmpty());

	T currBackData = this->backPtr->data;
	Node<T>* currBack = this->backPtr;

	if (this->dllistSize == 1) {
		this->frontPtr = nullptr;
		this->backPtr = nullptr;
	}
	else {
		this->backPtr = this->backPtr->prev;
		this->backPtr->next = this->frontPtr;
	}

	this->dllistSize--;
	delete currBack;
	return currBackData;
}

template<typename T>
void DLList<T>::insert(size_t, const T&);

template<typename T>
void DLList<T>::erase(size_t pos) {
	assert(pos >= 0 && pos < this->dllistSize && !this->isEmpty());

	if (this->dllistSize == 1) {
		delete this->frontPtr;
		this->frontPtr = nullptr;
		this->backPtr = nullptr;
		this->dllistSize--;
		return;
	}

	Iterator<T> element = this->begin();
	element += pos;
	Node<T>* elPtr = element.ptr;
	elPtr->prev->next = elPtr->next;
	elPtr->next->prev = elPtr->prev;

	if (pos == this->dllistSize - 1) {
		this->backPtr = this->backPtr->prev;
	}
	else if (pos == 0) {
		this->frontPtr = this->frontPtr->next;
	}

	this->dllistSize--;
	delete elPtr;

}

template<typename T>
void DLList<T>::clear() {
	this->deleteInternals();
}

template<typename T>
void DLList<T>::unique() {
	assert(!this->isEmpty());
	int currPos = 0;
	for (T x : *this)
	{
		int yPos = currPos + 1;
		Iterator<T> currBeg = this->begin();
		currBeg += yPos;
		for (Iterator<T> it = currBeg; it != this->end(); ++it)
		{
			if ((*it) == x) {
				it--;
				this->erase(yPos);
				yPos--;
			}
			yPos++;
		}
		currPos++;
	}
}

template<typename T>
DLList<T>& DLList<T>::reverse() {
	assert(!this->isEmpty());

	Node<T>* currHead = this->frontPtr;
	for (size_t i = 0; i < this->dllistSize; i++)
	{
		Node<T>* currPrev = currHead->prev;
		currHead->prev = currHead->next;
		currHead->next = currPrev;
		currHead = currHead->next;
	}

	this->frontPtr = this->frontPtr->next;
	this->backPtr = this->backPtr->prev;

	return *this;
}

template<typename T>
void DLList<T>::removelf(bool (*pred)(const T&)) {
	int currPos = 0;
	Node<T>* currHead = this->frontPtr;
	while (currHead != this->backPtr) {
		if (pred(currHead->data)) {
			currHead = currHead->prev;
			this->erase(currPos);
			currPos--;
		}

		currHead = currHead->next;
		currPos++;
	}

	if (pred(this->backPtr->data)) {
		this->erase(this->dllistSize - 1);
	}
}

template<typename T>
void DLList<T>::map(T(*func) (const T&)) {
	for (Iterator<T> it = this->begin(); it != this->end(); it++)
	{
		*it = func(*it);
	}
}

template<typename T>
Iterator<T> DLList<T>::begin() const {
	return Iterator<T>{this->frontPtr, this->frontPtr, true, false};
}

template<typename T>
Iterator<T> DLList<T>::end() const {
	return Iterator<T>{this->frontPtr, this->frontPtr, false, true};
}

#endif
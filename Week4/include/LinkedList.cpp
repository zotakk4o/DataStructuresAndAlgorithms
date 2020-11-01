#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "include/Vector.cpp"
#include "LinkedList.h"
#include <assert.h>

template<typename T>
Node<T>::Node(const T& _data) : data(_data), next(nullptr) {}

template<typename T>
LinkedListIterator<T>::LinkedListIterator(Node<T>* _ptr): ptr(_ptr) {}

template<typename T>
LinkedListIterator<T> LinkedListIterator<T>::next() const {
	if (!this->valid())
		return *this;

	return LinkedListIterator<T>(ptr->next);
}

template<typename T>
bool LinkedListIterator<T>::valid() const {
	return this->ptr != nullptr;
}

template<typename T>
T const& LinkedListIterator<T>::getConst() const {
	return this->ptr->data;
}

template<typename T>
T& LinkedListIterator<T>::get() const {
	return this->ptr->data;
}

template<typename T>
LinkedListIterator<T>::operator bool() const {
	return this->valid();
}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++() {
	return (*this = next());
}

template<typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator++(int) {
	LinkedListIterator<T> curr = *this;
	++(*this);
	return curr;
}

template<typename T>
T& LinkedListIterator<T>::operator*() {
	return this->get();
}

template<typename T>
bool LinkedListIterator<T>::operator==(LinkedListIterator<T> const& it) const {
	return this->ptr == it.ptr;
}

template<typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& it) const {
	return !(*this == it);
}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator+=(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		++(*this);
	}
		
	return *this;
}


template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

template<typename T>
void LinkedList<T>::copy(const LinkedList<T>& other) {
	this->listSize = other.listSize;
	this->head = new Node<T>(other.head->data);

	Node<T>* currenthead = this->head;
	Node<T>* newNode;
	Node<T>* otherhead = other.head;

	while (otherhead != other.tail) {
		otherhead = otherhead->next;

		newNode = new Node<T>(otherhead->data);

		currenthead->next = newNode;
		currenthead = newNode;
	}

	currenthead->next = nullptr;
	this->tail = currenthead;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
	this->copy(other);
}

template<typename T>
void LinkedList<T>::deleteInternals() {
	if (this->head == nullptr) {
		return;
	}
	
	this->listSize = 0;

	while (this->head != nullptr) {
		Node<T>* curr = this->head;
		this->head = this->head->next;

		delete curr;
	}
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
	if (this != &other) {
		this->deleteInternals();
		this->copy(other);
	}

	return *this;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	this->deleteInternals();
}

template<typename T>
bool LinkedList<T>::empty() const {
	return this->listSize == 0;
}

template<typename T>
unsigned int LinkedList<T>::count() const {
	return this->listSize;
}

template<typename T>
LinkedListIterator<T> LinkedList<T>::getNthIterator(const unsigned int& index) const {
	assert(index < this->listSize && index >= 0);

	int curr = 0;
	LinkedListIterator<T> currItem{this->begin()};
	while (curr != index) {
		currItem++;
		curr++;
	}

	return currItem;
}

template<typename T>
T LinkedList<T>::getNth(const unsigned int& index) const {
	return *this->getNthIterator(index);
}


template<typename T>
void LinkedList<T>::deleteList() {
	this->deleteInternals();
}

template<typename T>
T LinkedList<T>::pop() {
	if (this->listSize == 1) {
		T res = this->head->data;
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		this->listSize--;
		return res;
	}

	LinkedListIterator<T> beforeLast = this->getNthIterator(this->listSize - 2);

	T res = this->tail->data;
	delete this->tail;
	beforeLast.ptr->next = nullptr;
	this->tail = beforeLast.ptr;
	this->listSize--;
	return res;
}

template<typename T>
void LinkedList<T>::insertEnd(const T& element) {
	Node<T>* newEl = new Node<T>(element);
	this->listSize++;

	if (head == nullptr) {
		head = tail = newEl;
		return;
	}

	tail->next = newEl;
	tail = newEl;
}

template<typename T>
void LinkedList<T>::insertBeg(const T& element) {
	Node<T>* newEl = new Node<T>(element);
	this->listSize++;
	newEl->next = this->head;
	this->head = newEl;

	if (this->tail == nullptr) {
		this->tail = newEl;
	}
}

template<typename T>
void LinkedList<T>::insertNth(const T& element, const unsigned int& index) {
	Node<T>* newEl = new Node<T>(element);
	this->getNthIterator(index).ptr->data = element;
}

template<typename T>
LinkedList<T>& LinkedList<T>::reverse() {
	LinkedList<T> reversed;
	for (T const& x : *this) {
		reversed.insertBeg(x);
	}

	*this = reversed;

	return *this;
}

template<typename T>
Node<T>* recursiveReverseInternal(Node<T>* head) {
	if (head == nullptr || head->next == nullptr)
		return head;

	Node<T>* rest = recursiveReverseInternal(head->next);
	head->next->next = head;
	head->next = nullptr;

	return rest;
}

template<typename T>
LinkedList<T>& LinkedList<T>::recursiveReverse() {
	Node<T>* newHead = recursiveReverseInternal(this->head);
	this->tail = this->head;
	this->head = newHead;

	return *this;
}

template<typename T>
T LinkedList<T>::getMidNode() const {
	return *this->getNthIterator(this->listSize / 2);
}

template<typename T>
void LinkedList<T>::append(LinkedList<T>& first, LinkedList<T>& second) {
	for (const T& x : second)
	{
		first.insertEnd(x);
	}

	second.head = nullptr;
	second.tail = nullptr;
	second.listSize = 0;
}

template<typename T>
bool LinkedList<T>::detectCycle() const {
	Node<T>* curr = this->head;
	Vector<Node<T>*> alreadySearched;
	while (curr != nullptr) {
		if (alreadySearched.indexOf(curr) != -1) {
			return true;
		}
		alreadySearched.pushBack(curr);
		curr = curr->next;
	}

	return false;
}

template<typename T>
Node<T>* LinkedList<T>::findPrev(const LinkedListIterator<T>& it) {
	Node<T>* target;

	if (!it) {
		target = this->tail;
	}	
	else {
		target = it.ptr;
	}
		
	LinkedListIterator<T> result = begin();
	while (result && result.ptr->next != target) {
		++result;
	}
		
	return result;
}

template<typename T>
void LinkedList<T>::deleteAt(const LinkedListIterator<T>& it) {
	if (!it) {
		return;
	}	

	if (!this->empty() && it == this->begin()) {
		Node<T>* ptr = this->head;
		this->head = this->head->next;
		if (this->tail == ptr)
			this->tail = nullptr;
		delete ptr;
		return;
	}

	Node<T>* prev = this->findPrev(it);

	prev->next = it.ptr->next;

	if (it.ptr == this->tail) {
		this->tail = prev;
	}

	delete it.ptr;
}

template<typename T>
LinkedListIterator<T> LinkedList<T>::begin() const {
	return LinkedListIterator<T>{this->head};
}

template<typename T>
LinkedListIterator<T> LinkedList<T>::end() const {
	return LinkedListIterator<T>{};
}

#endif
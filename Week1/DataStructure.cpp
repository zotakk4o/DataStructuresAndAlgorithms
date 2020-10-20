#ifndef DATASTRUCTURE_CPP
#define DATASTRUCTURE_CPP

#include "DataStructure.h"
#include<assert.h>

template<typename T>
DataStructure<T>::~DataStructure() {
	this->deleteInternals();
};

template<typename T>
void DataStructure<T>::reserve() {
	this->capacity = this->capacity == 0 ? DataStructure<T>::INITIAL_CAPACITY : this->capacity * 2;

	this->copy(*this);
}

template<typename T>
DataStructure<T>::DataStructure(const unsigned int& capacity) : size(0), capacity(0), data(nullptr) {
	assert(capacity > 0);

	this->capacity = capacity;
	this->reserve();
}

template<typename T>
void DataStructure<T>::copy(const DataStructure<T>& other) {
	this->size = other.size;
	this->capacity = other.capacity;

	T* newArr = new T[this->capacity];

	for (unsigned int i = 0; i < this->size; i++)
	{
		newArr[i] = other.data[i];
	}

	this->deleteInternals();
	this->data = newArr;
}



template<typename T>
DataStructure<T>::DataStructure(const DataStructure<T>& other) : size(0), capacity(0), data(nullptr) {
	if (this != &other) {
		this->copy(other);
	}
}

template<typename T>
DataStructure<T>& DataStructure<T>::operator=(const DataStructure<T>& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}


template<typename T>
void DataStructure<T>::deleteInternals() {
	delete[] this->data;
}

template<typename T>
bool DataStructure<T>::isFull() const {
	return this->size == this->capacity;
}

#endif
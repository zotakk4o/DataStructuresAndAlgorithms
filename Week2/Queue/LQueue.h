#ifndef LQUEUE_H
#define LQUEUE_H

template<typename T>
struct QueueNode {
	T data;
	QueueNode* next;
	QueueNode(const T&);
};

template<typename T>
class LQueue
{
	private:
		QueueNode<T>* front;
		QueueNode<T>* rear;
	public:
		LQueue();
		void enqueue(const T&);
		T dequeue();
		bool isEmpty() const;
		int size() const;
};

#endif
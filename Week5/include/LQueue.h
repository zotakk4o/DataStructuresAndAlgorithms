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
		unsigned int queueSize;
		QueueNode<T>* front;
		QueueNode<T>* rear;
		void copy(const LQueue<T>&);
		void deleteInternals();
	public:
		LQueue();
		LQueue(const LQueue<T>&);
		LQueue<T>& operator=(const LQueue<T>&);
		~LQueue();
		void enqueue(const T&);
		T dequeue();
		T first() const;
		bool isEmpty() const;
		unsigned int size() const;
};

#endif
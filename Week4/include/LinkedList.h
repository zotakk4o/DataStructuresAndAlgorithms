#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
struct Node {
	T data;
	Node* next;
	Node(const T&);
};

template<typename T>
class LinkedList;

template <typename T>
class LinkedListIterator {
	private:
		friend class LinkedList<T>;
		Node<T>* ptr;
	public:
		LinkedListIterator(Node<T>* = nullptr);
	
		LinkedListIterator<T> next() const;
	
		bool valid() const;
	
		T const& getConst() const;
		T& get() const;
	
		operator bool() const;
		LinkedListIterator<T>& operator++();
		LinkedListIterator<T> operator++(int);
		T& operator*();
		bool operator==(LinkedListIterator<T> const& it) const;
		bool operator!=(LinkedListIterator<T> const& it) const;
		LinkedListIterator<T>& operator+=(unsigned int n);
};

template<typename T>
class LinkedList
{
	private:
		unsigned int listSize;
		Node<T>* head;
		Node<T>* tail;
		void copy(const LinkedList<T>&);
		void deleteInternals();
		LinkedListIterator<T> getNthIterator(const unsigned int&) const;
		Node<T>* findPrev(const LinkedListIterator<T>&);
	public:
		LinkedList();
		LinkedList(const LinkedList<T>&);
		LinkedList<T>& operator=(const LinkedList<T>&);
		~LinkedList();
		bool empty() const;
		unsigned int count() const;
		T getNth(const unsigned int&) const;
		void deleteList();
		T pop();
		void insertBeg(const T&);
		void insertEnd(const T&);
		void insertNth(const T&, const unsigned int&);
		void deleteAt(const LinkedListIterator<T>&);
		LinkedList<T>& reverse();
		LinkedList<T>& recursiveReverse();
		T getMidNode() const;
		static void append(LinkedList<T>&, LinkedList<T>&);
		bool detectCycle() const;
		LinkedListIterator<T> begin() const;
		LinkedListIterator<T> end() const;
};

#endif


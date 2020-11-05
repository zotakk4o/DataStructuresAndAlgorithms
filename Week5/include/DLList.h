#ifndef DLLIST_H
#define DLLIST_H

template<typename T>
struct Node {
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node(const T&);
};

template <typename T>
class DLList;

template <typename T>
class Iterator {
private:
	friend class DLList<T>;
	bool canIncrease;
	bool canDecrease;
	Node<T>* ptr;
	Node<T>* end;
public:
	Iterator(Node<T>*, Node<T>*, bool = true, bool = true);

	Iterator<T> next() const;
	Iterator<T> prev() const;

	T const& getConst() const;
	T& get() const;

	Iterator<T>& operator++();
	Iterator<T> operator++(int);
	Iterator<T>& operator--();
	Iterator<T> operator--(int);
	T& operator*();
	bool operator==(Iterator<T> const&) const;
	bool operator!=(Iterator<T> const&) const;
	Iterator<T>& operator+=(unsigned int);
	Iterator<T>& operator-=(unsigned int);
};

template<typename T>
class DLList
{
	private:
		friend class Iterator<T>;
		unsigned int dllistSize;
		Node<T>* frontPtr;
		Node<T>* backPtr;

		void deleteInternals();
		void copy(const DLList&);
	public:
		DLList();
		DLList(const DLList&);
		DLList<T>& operator=(const DLList&);
		~DLList();
		bool isEmpty() const;
		unsigned int size() const;
		T front() const;
		T back() const;
		void assign(size_t, const T&);
		void pushFront(const T&);
		void pushBack(const T&);
		T popFront();
		T popBack();
		void insert(size_t, const T&);
		void erase(size_t);
		void clear();
		void unique();
		DLList<T>& reverse();
		void removelf(bool (*)(const T& element));
		void map(T(*) (const T&));

		Iterator<T> begin() const;
		Iterator<T> end() const;
};

#endif
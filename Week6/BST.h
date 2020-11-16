#ifndef BST_H
#define BST_H

#include <utility>
#include "include/Vector.cpp"
#include <ostream>

template<typename K, typename V>
struct Node {
	K key;
	V value;

	Node<K, V>* left;
	Node<K, V>* right;

	Node(const K&, const V&);
};

template<typename K, typename V>
class BST
{
	private:
		Node<K, V>* root;
		void deleteTree(Node<K, V>*);
		Node<K, V>* copyTree(const Node<K, V>*&);
		Node<K, V>* createTree(const Vector<std::pair<K, V>>&);
		void recurrsivePrint(Node<K, V>* const&, int = 0);
		int calculateHeightRecurrsive(Node<K, V>* const&, int = 0);
		Node<K, V>* removeRecurrsive(Node<K, V>*&, const K&);
	public:
		BST(const Vector<std::pair<K, V>>&);
		BST(const BST<K, V>&);
		~BST();
		BST& operator=(const BST<K, V>&);
		
		void prittyPrint();
		bool contains(const K&);
		int calculateHeight();
		int sumLeaves();
		int countLeaves();
		bool remove(const K&);
		void serializeTree(std::ofstream&);
};

#endif


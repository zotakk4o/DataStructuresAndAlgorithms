#ifndef BST_H
#define BST_H

#include <utility>
#include "include/Vector.cpp"

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
		void recurrsivePrint(const Node<K, V>*&, int);
		int calculateHeightRecurrsive(Node<K, V>* const&, int = 0);
	public:
		BST(const Vector<std::pair<K, V>>&);
		BST(const BST<K, V>&);
		~BST();
		BST& operator=(const BST<K, V>&);
		
		void prittyPrint();
		int calculateHeight();
};

#endif


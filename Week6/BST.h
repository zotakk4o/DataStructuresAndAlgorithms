#ifndef BST_H
#define BST_H

#include <utility>
#include "include/Vector.cpp"
#include "include/BinaryTree.h"
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
class BST : public BinaryTree<K, V>
{
	private:
		Node<K, V>* root;
		void deleteTree(Node<K, V>*);
		Node<K, V>* copyTree(const Node<K, V>*&);
		Node<K, V>* createTree(const Vector<std::pair<K, V>>&);
		void recurrsivePrint(Node<K, V>* const&, int = 0);
		Node<K, V>* recurrsiveInsert(Node<K, V>*, const K&, const V&);
		int calculateHeightRecurrsive(Node<K, V>* const&, int = 0);
		Node<K, V>* removeRecurrsive(Node<K, V>*&, const K&);
	public:
		BST();
		BST(const Vector<std::pair<K, V>>&);
		BST(const BST<K, V>&);
		~BST();
		BST& operator=(const BST<K, V>&);
		
		void insert(const K&, const V&);
		void prittyPrint();
		bool contains(const K&);
		int calculateHeight();
		int sumLeaves();
		int countLeaves();
		bool remove(const K&);
		void serializeTree(std::ofstream&);
};

#endif


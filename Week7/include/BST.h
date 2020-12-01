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
	unsigned int height;

	Node<K, V>* left;
	Node<K, V>* right;

	Node(const K&, const V&, const unsigned int& = 0);
};

template<typename K, typename V>
class BST;

template<typename K, typename V>
class BSTPosition {
	private:
		friend class BST<K, V>;
		Node<K, V>* ptr;
	public:
		BSTPosition(Node<K, V>*& = nullptr);
		BSTPosition<K, V> left();
		BSTPosition<K, V> right();
		K getKey();
		V getValue();
		bool setKey(const K&);
		bool setValue(const V&);
		operator bool() const;
};

template<typename K, typename V>
class BST : public BinaryTree<K, V>
{
	private:
		Node<K, V>* root;
		void deleteTree(Node<K, V>*);
		Node<K, V>* copyTree(const Node<K, V>* const&);
		Node<K, V>* createTree(const Vector<std::pair<K, V>>&);
		void recurrsivePrint(Node<K, V>* const&, int = 0);
		Node<K, V>* recurrsiveInsert(Node<K, V>*, const K&, const V&);
		int calculateHeightRecurrsive(Node<K, V>* const&, int = 0);
		Node<K, V>* removeRecurrsive(Node<K, V>*&, const K&);
		Node<K, V>* largestLeftNode(Node<K, V>* const&);
		unsigned int updateHeight(const Node<K, V>* const&);
		bool isBalancedRecurrsive(Node<K, V>* const&);
		void mirrorTreeRecurrsive(Node<K, V>*&);
		void childrenifyRecurrsive(Node<K, V>*&);
	public:
		BST();
		BST(const Vector<std::pair<K, V>>&);
		BST(const BST<K, V>&);
		~BST();
		BST& operator=(const BST<K, V>&);
		
		void insert(const K&, const V&);
		void prittyPrint();
		bool contains(const K&);
		bool isBalanced();
		bool isOrdered();
		int calculateHeight();
		int sumLeaves();
		int countLeaves();
		void mirrorTree();
		void childrenify();
		bool remove(const K&);
		void serializeTree(std::ofstream&);
		static void rightJoinTrees(BSTPosition<K, V>, BST<K, V>&&);
		static void leftJoinTrees(BSTPosition<K, V>, BST<K, V>&&);
		BSTPosition<K, V> rootPosition() const;
};

#endif


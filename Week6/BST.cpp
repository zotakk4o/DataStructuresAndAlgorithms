#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

template<typename K, typename V>
Node<K, V>::Node(const K& _key, const V& _value) : key(_key), value(_value), left(nullptr), right(nullptr) {};

template<typename K, typename V>
void BST<K, V>::deleteTree(Node<K, V>* root) {
	if (!root) {
		return;
	}

	this->deleteTree(root->left);
	this->deleteTree(root->right);

	delete root;
}

template<typename K, typename V>
Node<K,V>* BST<K, V>::copyTree(const Node<K,V>*& root) {
	if (!root) {
		return nullptr;
	}

	Node<K, V>* newNode = new Node<K, V>{ root->key, root->value };

	newNode->left = this->copyTree(root->left);
	newNode->right = this->copyTree(root->right);

	return newNode;
}

template<typename K, typename V>
BST<K, V>::BST(const Vector<std::pair<K, V>>& pairs) {
	this->root = this->createTree(pairs);
}

template<typename K, typename V>
Node<K, V>* BST<K, V>::createTree(const Vector<std::pair<K, V>>& pairs) {
	if (!pairs.getSize()) {
		return nullptr;
	}

	int pairsSize = pairs.getSize();
	int currIndex = pairsSize % 2 == 0 ? pairsSize / 2 - 1 : pairsSize / 2 ;

	std::pair<K, V> current = pairs[currIndex];
	Node<K, V>* newNode = new Node<K, V>{current.first, current.second};

	newNode->left = this->createTree(pairs.slice(0, currIndex - 1));
	newNode->right = this->createTree(pairs.slice(currIndex + 1, pairsSize - 1));

	return newNode;
}

template<typename K, typename V>
BST<K, V>::BST(const BST<K, V>& other) {
	this->root = this->copyTree(other.root);
}

template<typename K, typename V>
BST<K, V>::~BST() {
	this->deleteTree(this->root);
}

template<typename K, typename V>
BST<K, V>& BST<K, V>::operator=(const BST<K, V>& other) {
	if (this != &other) {
		this->deleteTree(this->root);
		this->root = this->copyTree(other.root);
	}

	return *this;
}

template<typename K, typename V>
void BST<K, V>::prittyPrint() {

}

template<typename K, typename V>
void BST<K, V>::recurrsivePrint(const Node<K, V>*& root, int spaces) {

}

template<typename K, typename V>
int BST<K, V>::calculateHeightRecurrsive(Node<K, V>* const& root, int currHeight) {
	if (!root) {
		return -1;
	}

	int currLeftHeight = this->calculateHeightRecurrsive(root->left, currHeight + 1);
	int currRightHeight = this->calculateHeightRecurrsive(root->right, currHeight + 1);

	if (currLeftHeight == currRightHeight && currLeftHeight == -1) {
		return currHeight;
	}

	return currLeftHeight > currRightHeight ? currLeftHeight : currRightHeight;
}

template<typename K, typename V>
int BST<K, V>::calculateHeight() {
	return this->calculateHeightRecurrsive(this->root);
}

#endif
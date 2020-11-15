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
Node<K, V>* createTree(const Vector<V>& values) {
	Node<K, V>* currRoot = new Node<K, V>{};
}

template<typename K, typename V>
BST<K, V>::BST(const Vector<std::pair<K, V>>& pairs) {
	this->root = this->createTree(pairs);
}

template<typename K, typename V>
Node<K, V>* BST<K, V>::createTree(const Vector<std::pair<K, V>>& pairs) {
	//TODO
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
void prittyPrint();

#endif
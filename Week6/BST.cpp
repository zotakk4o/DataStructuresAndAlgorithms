#ifndef BST_CPP
#define BST_CPP

#include "BST.h"
#include <fstream>
#include <iostream>

template<typename K, typename V>
Node<K, V>::Node(const K& _key, const V& _value) : key(_key), value(_value), left(nullptr), right(nullptr) {};

template<typename K, typename V>
BST<K, V>::BST() : root(nullptr) {}

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
	this->recurrsivePrint(this->root);
}

template<typename K, typename V>
Node<K, V>* BST<K, V>::recurrsiveInsert(Node<K, V>* root, const K& key, const V& value) {
	if (!root) {
		return new Node<K, V>{ key, value };
	}

	if (key > root->key) {
		root->right = this->recurrsiveInsert(root->right, key, value);
	}
	else if (key < root->key) {
		root->left = this->recurrsiveInsert(root->left, key, value);
	}

	return root;
}

template<typename K, typename V>
void BST<K, V>::insert(const K& key, const V& value) {
	if (!this->root) {
		this->root = this->recurrsiveInsert(this->root, key, value);
	}
	else {
		this->recurrsiveInsert(this->root, key, value);
	}
	
}

template<typename K, typename V>
void BST<K, V>::recurrsivePrint(Node<K, V>* const& root, int spaces) {
	if (!root) {
		return;
	}
		
	spaces += 5;
	recurrsivePrint(root->right, spaces);

	std::cout << std::endl;
	for (int i = 5; i < spaces; i++) {
		std::cout << " ";
	}	
	std::cout << root->value << "\n";

	recurrsivePrint(root->left, spaces);
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

template<typename K, typename V>
bool BST<K, V>::contains(const K& key) {
	if (!this->root) {
		return false;
	}

	bool res = false;
	Node<K, V>* currRoot = this->root;

	if (key > this->root->key) {
		this->root = this->root->right;
	} else if (key < this->root->key) {
		this->root = this->root->left;
	}
	else {
		res = true;
		this->root = currRoot;
		return res;
	}
	
	res = this->contains(key);
	this->root = currRoot;
	return res;
}

template<typename K, typename V>
int BST<K, V>::sumLeaves() {
	if (!this->root) {
		return 0;
	}
	Node<K, V>* currRoot = this->root;

	if (!this->root->left && !this->root->right) {
		return this->root->key;
	}

	int sumLeaves = 0;
	if (this->root->left) {
		this->root = this->root->left;
		sumLeaves += this->sumLeaves();
		this->root = currRoot;
	}

	if (this->root->right) {
		this->root = this->root->right;
		sumLeaves += this->sumLeaves();
		this->root = currRoot;
	}

	return sumLeaves;
}

template<typename K, typename V>
int BST<K, V>::countLeaves() {
	if (!this->root) {
		return 0;
	}
	Node<K, V>* currRoot = this->root;

	if (!this->root->left && !this->root->right) {
		return 1;
	}

	int countLeaves = 0;
	if (this->root->left) {
		this->root = this->root->left;
		countLeaves += this->countLeaves();
		this->root = currRoot;
	}

	if (this->root->right) {
		this->root = this->root->right;
		countLeaves += this->countLeaves();
		this->root = currRoot;
	}

	return countLeaves;
}

template<typename K, typename V>
bool BST<K, V>::remove(const K& key) {
	if (!this->contains(key)) {
		return false;
	}

	this->root = this->removeRecurrsive(this->root, key);

	return true;
}

template<typename K, typename V>
Node<K, V>* BST<K, V>::removeRecurrsive(Node<K, V>*& root, const K& key) {
	if (!root) {
		return nullptr;
	}

	if (key > root->key) {
		root->right = this->removeRecurrsive(root->right, key);
	}
	else if (key < root->key) {
		root->left = this->removeRecurrsive(root->left, key);
	}
	else {
		if (!root->left) {
			Node<K, V>* temp = root->right;
			delete root;
			return temp;
		}
		else if (!root->right) {
			Node<K, V>* temp = root->left;
			delete root;
			return temp;
		}

		Node<K, V>* temp = root->left;

		root->key = temp->key;
		root->value = temp->value;
		root->left = this->removeRecurrsive(root->left, temp->key);
	}

	return root;
}

template<typename K, typename V>
void BST<K, V>::serializeTree(std::ofstream& out) {
	if (!this->root) {
		out << "()";
		return;
	}

	out << "(" << this->root->key << ":" << this->root->value << " ";
	Node<K, V>* currRoot = this->root;
	this->root = currRoot->left;
	this->serializeTree(out);
	this->root = currRoot->right;
	this->serializeTree(out);
	this->root = currRoot;
	out << ")";
}

#endif
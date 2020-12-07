#ifndef BST_CPP
#define BST_CPP

#include "BST.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

template<typename K, typename V>
Node<K, V>::Node(const K& _key, const V& _value, const unsigned int& _height) : key(_key), value(_value), height(_height), left(nullptr), right(nullptr) {};

template<typename K, typename V>
BSTPosition<K, V>::BSTPosition(Node<K, V>*& _ptr) : ptr(_ptr) {}

template<typename K, typename V>
BSTPosition<K, V> BSTPosition<K, V>::left() const {
	if (this->ptr) {
		return BSTPosition<K, V>{this->ptr->left};
	}

	return *this;
}

template<typename K, typename V>
BSTPosition<K, V> BSTPosition<K, V>::right() const {
	if (this->ptr) {
		return BSTPosition<K, V>{this->ptr->right};
	}

	return *this;
}

template<typename K, typename V>
BSTPosition<K, V>::operator bool() const {
	return this->ptr;
}

template<typename K, typename V>
K BSTPosition<K, V>::getKey() const {
	if (!this->ptr) {
		throw "Cannot get key of nullptr";
	}
	return this->ptr->key;
}

template<typename K, typename V>
V BSTPosition<K, V>::getValue() {
	if (!this->ptr) {
		throw "Cannot get value of nullptr";
	}
	return this->ptr->value;
}

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
Node<K,V>* BST<K, V>::copyTree(const Node<K,V>* const& root) {
	if (!root) {
		return nullptr;
	}

	Node<K, V>* newNode = new Node<K, V>{ root->key, root->value, root->height };

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

	newNode->height = this->updateHeight(newNode);

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
	
	root->height = this->updateHeight(root);

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
	std::cout << root->key << "-" <<  root->value << "\n";

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
	if (!root) {
		return -1;
	}

	return this->root->height;
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

		Node<K, V>* temp = this->largestLeftNode(root);

		root->key = temp->key;
		root->value = temp->value;
		root->left = this->removeRecurrsive(root->left, temp->key);
	}

	root->height = this->updateHeight(root);

	return root;
}

template<typename K, typename V>
Node<K, V>* BST<K, V>::largestLeftNode(Node<K, V>* const& root) {
	if (root->left && !root->left->left) {
		return root->right;
	}

	return this->largestLeftNode(root->left);
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

template<typename K, typename V>
bool BST<K, V>::isOrdered(const K& minValue, const K& maxValue) {
	return this->isOrderedInternals(this->root, minValue, maxValue);
}

template<typename K, typename V>
bool BST<K, V>::isOrderedInternals(Node<K, V>* const& root, const K& minExpected, const K& maxExpected) {
	if (!root || (!root->left && !root->right)) {
		return true;
	}

	if (root->key < minExpected || root->key > maxExpected) {
		return false;
	}
	
return this->isOrderedInternals(root->left, minExpected, root->key) && this->isOrderedInternals(root->right, root->key, maxExpected);
}

template<typename K, typename V>
bool BST<K, V>::isBalanced() {
	return this->isBalancedRecurrsive(this->root);
}

template<typename K, typename V>
bool BST<K, V>::isBalancedRecurrsive(Node<K, V>* const& root) {
	if (!root) {
		return true;
	}

	unsigned int leftHeight = this->root->left ? this->root->left->height + 1 : 0;
	unsigned int rightHeight = this->root->right ? this->root->right->height + 1 : 0;

	if (std::labs(leftHeight - rightHeight) <= 1 && this->isBalancedRecurrsive(root->left) && isBalancedRecurrsive(root->right)) {
		return true;
	}
	
	return false;
}

template<typename K, typename V>
void BST<K, V>::mirrorTree() {
	this->mirrorTreeRecurrsive(this->root);
}

template<typename K, typename V>
void BST<K, V>::childrenify() {
	this->childrenifyRecurrsive(this->root);
}

template<typename K, typename V>
void BST<K, V>::mirrorTreeRecurrsive(Node<K, V>*& root) {
	if (!root) {
		return;
	}

	Node<K, V>* temp = root->right;
	root->right = root->left;
	root->left = temp;

	this->mirrorTreeRecurrsive(root->right);
	this->mirrorTreeRecurrsive(root->left);
}

template<typename K, typename V>
void BST<K, V>::childrenifyRecurrsive(Node<K, V>*& root) {
	if (!root) {
		return;
	}

	if (!root->left && !root->right) {
		root->key = 1;
		return;
	}

	this->childrenifyRecurrsive(root->right);
	this->childrenifyRecurrsive(root->left);

	unsigned int leftKey = root->left ? root->left->key : 0;
	unsigned int rightkey = root->right ? root->right->key : 0;

	root->key = leftKey + rightkey + 1;
}

template<typename K, typename V>
unsigned int BST<K, V>::updateHeight(const Node<K, V>* const &node) {
	unsigned int leftHeight = node->left ? node->left->height : 0;
	unsigned int rightHeight = node->right ? node->right->height : 0;
	return !node->left && !node->right ? 0 : 1 + std::max(leftHeight, rightHeight);
}

template<typename K, typename V>
BSTPosition<K, V> BST<K, V>::rootPosition() const {
	return BSTPosition<K, V>{this->root};
}

template<typename K, typename V>
void BST<K, V>::rightJoinTrees(BSTPosition<K, V> rightPos, BST<K, V>& tree) {
	if (!rightPos.ptr) {
		return;
	}
	rightPos.ptr->right = tree.root;
	tree.root = nullptr;
}

template<typename K, typename V>
void BST<K, V>::leftJoinTrees(BSTPosition<K, V> leftPos, BST<K, V>& tree) {
	if (!leftPos.ptr) {
		return;
	}
	leftPos.ptr->left= tree.root;
	tree.root = nullptr;
}

#endif
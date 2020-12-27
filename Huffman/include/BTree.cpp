#ifndef BTREE_CPP
#define BTREE_CPP

#include "BTree.h"
#include <queue>
template<typename V>
BNode<V>::BNode(const V& _value) : value(_value), left(nullptr), right(nullptr) {};

template<typename V>
BTreePosition<V>::BTreePosition(BNode<V>*& _ptr) : ptr(_ptr) {}

template<typename V>
BTreePosition<V> BTreePosition<V>::left() const {
	if (this->ptr) {
		return BTreePosition<V>{this->ptr->left};
	}

	return *this;
}

template<typename V>
BTreePosition<V> BTreePosition<V>::right() const {
	if (this->ptr) {
		return BTreePosition<V>{this->ptr->right};
	}

	return *this;
}

template<typename V>
BTreePosition<V>::operator bool() const {
	return this->ptr;
}

template<typename V>
V BTreePosition<V>::getValue() const {
	if (!this->ptr) {
		throw "Cannot get value of nullptr";
	}
	return this->ptr->value;
}

template<typename V>
bool BTreePosition<V>::setValue(const V& value) {
	if (!this->ptr) {
		return false;
	}
	this->ptr->value = value;
	return true;
}


template<typename V>
BTree<V>::BTree() : root(nullptr) {}

template<typename V>
void BTree<V>::deleteTree(BNode<V>* root) {
	if (!root) {
		return;
	}

	this->deleteTree(root->left);
	this->deleteTree(root->right);

	delete root;
}

template<typename V>
BNode<V>* BTree<V>::copyTree(const BNode<V>* const& root) {
	if (!root) {
		return nullptr;
	}

	BNode<V>* newNode = new BNode<V>{ root->value };

	newNode->left = this->copyTree(root->left);
	newNode->right = this->copyTree(root->right);

	return newNode;
}

template<typename V>
BTree<V>::BTree(const BTree<V>& other) {
	this->root = this->copyTree(other.root);
}

template<typename V>
BTree<V>::~BTree() {
	this->deleteTree(this->root);
}

template<typename V>
BTree<V>& BTree<V>::operator=(const BTree<V>& other) {
	if (this != &other) {
		this->deleteTree(this->root);
		this->root = this->copyTree(other.root);
	}

	return *this;
}

template<typename V>
BTreePosition<V> BTree<V>::rootPosition() {
	return BTreePosition<V>{this->root};
}

template<typename V>
BNode<V>* BTree<V>::insertRecurrsive(BNode<V>*& root, const V& value){
	if (root == nullptr) {
		return new BNode<V>{ value };
	}

	std::queue<BNode<V>*> q;
	q.push(root);

	while (!q.empty()) {
		BNode<V>* temp = q.front();
		q.pop();

		if (temp->left != nullptr)
			q.push(temp->left);
		else {
			temp->left = new BNode<V>{ value };
			return root;
		}

		if (temp->right != nullptr)
			q.push(temp->right);
		else {
			temp->right = new BNode<V>{ value };
			return root;
		}
	}
}

template<typename V>
void BTree<V>::insert(const V& value) {
	this->root = this->insertRecurrsive(this->root, value);
}

template<typename V>
void BTree<V>::rightJoinTrees(BTreePosition<V> rightPos, BTree<V>& tree) {
	if (!rightPos.ptr) {
		return;
	}
	rightPos.ptr->right = tree.root;
	tree.root = nullptr;
}

template<typename V>
void BTree<V>::leftJoinTrees(BTreePosition<V> leftPos, BTree<V>& tree) {
	if (!leftPos.ptr) {
		return;
	}
	leftPos.ptr->left = tree.root;
	tree.root = nullptr;
}

template<typename V>
void BTree<V>::prittyPrint() {
	this->recurrsivePrint(this->root);
}

template<typename V>
void BTree<V>::recurrsivePrint(BNode<V>* const& root, int spaces) {
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
#endif
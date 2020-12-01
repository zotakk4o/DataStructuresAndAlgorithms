#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename K, typename V>
class BinaryTree {
	protected:
		virtual bool remove(const K&) = 0;
		virtual bool contains(const K&) = 0;
		virtual void insert(const K&, const V&) = 0;
		virtual bool isOrdered() = 0;
		virtual bool isBalanced() = 0;
};


#endif
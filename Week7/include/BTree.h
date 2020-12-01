#ifndef BTREE_H
#define BTREE_H

template<typename V>
struct BNode {
	V value;

	BNode<V>* left;
	BNode<V>* right;

	BNode(const V&);
};

template<typename V>
class BTree;

template<typename V>
class BTreePosition {
private:
	friend class BTree<V>;
	BNode<V>* ptr;
public:
	BTreePosition(BNode<V>*& = nullptr);
	BTreePosition<V> left();
	BTreePosition<V> right();
	V getValue();
	bool setValue(const V&);
	operator bool() const;
};

template<typename V>
class BTree
{
	private:
		friend class BTreePosition<V>;
		BNode<V>* root;
		void deleteTree(BNode<V>*);
		BNode<V>* copyTree(const BNode<V>* const&);
		BNode<V>* insertRecurrsive(BNode<V>*&, const V&);
		void recurrsivePrint(BNode<V>* const&, int = 0);
	public:
		BTree();
		BTree(const BTree<V>&);
		~BTree();
		BTree& operator=(const BTree<V>&);
		BTreePosition<V> rootPosition();
		void insert(const V&);
		void prittyPrint();
		static void rightJoinTrees(BTreePosition<V>, BTree<V>&);
		static void leftJoinTrees(BTreePosition<V>, BTree<V>&);
};

#endif

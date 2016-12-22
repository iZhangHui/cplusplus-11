#pragma once

#include <iomanip>
#include <iostream>
#include <exception>

template <typename T>
class BSTNode {
public:
	BSTNode(T value, BSTNode* p, BSTNode* l, BSTNode* r) :
	key(value), parent(p), left(l), right(r) { }
	T key;
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
};

template <typename T>
class BSTree {
public:
	BSTree();
	~BSTree();

	void preOrder();
	void inOrder();
	void postOrder();

	BSTNode<T>* search(T key);
	BSTNode<T>* iterativeSearch(T key);

	BSTNode<T>* minimum();
	BSTNode<T>* maxmum();

	BSTNode<T>* successor(BSTNode<T>* node);
	BSTNode<T>* preDecessor(BSTNode<T>* node);

	void insert(T key);
	void remove(T key);

	void destroy();

	void print();

private:
	void preOrder(BSTNode<T>* tree) const;
	void inOrder(BSTNode<T>* tree) const;
	void postOrder(BSTNode<T>* tree) const;

	BSTNode<T>* search(BSTNode<T>* x, T key) const;
	BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;

	BSTNode<T>* minimum(BSTNode<T>* tree);
	BSTNode<T>* maxmum(BSTNode<T>* tree);

	void insert(BSTNode<T>* &tree, BSTNode<T>* z);
	void transplant(BSTNode<T>* &tree, BSTNode<T>* u, BSTNode<T>* v);
	void remove(BSTNode<T>* &tree, BSTNode<T>* z);

	void destroy(BSTNode<T>* &tree);

	void print(BSTNode<T>* tree, T key, int direction);
private:
	BSTNode<T>* mRoot;
};

template <typename T>
BSTree<T>::BSTree() : mRoot(nullptr) { }

template <typename T>
BSTree<T>::~BSTree()
{
	destroy();
}

template <typename T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const
{
	if (tree != nullptr) {
		std::cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template <typename T>
void BSTree<T>::preOrder()
{
	preOrder(mRoot);
}

template <typename T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const
{
	if (tree != nullptr) {
		inOrder(tree->left);
		std::cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template <typename T>
void BSTree<T>::inOrder()
{
	inOrder(mRoot);
}

template <typename T>
void BSTree<T>::postOrder(BSTNode<T>* tree) const
{
	if (tree != nullptr) {
		postOrder(tree->right);
		std::cout << tree->key << " ";
		postOrder(tree->left);
	}
}

template <typename T>
void BSTree<T>::postOrder()
{
	postOrder(mRoot);
}

template <typename T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key) const
{
	if (x == nullptr || x->key == key)
		return x;

	if (key < x->key) {
		return search(x->left, key);

	} else {
		return search(x->right, key);
	}
}

template <typename T>
BSTNode<T>* BSTree<T>::search(T key)
{
	return search(mRoot, key);
}

template <typename T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T>* x, T key) const
{
	while ((x != nullptr) && (x->key != key)) {
		if (key < x->key) {
			x = x->left;

		} else {
			x = x->right;
		}
	}

	return x;
}

template <typename T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

template <typename T>
BSTNode<T>* BSTree<T>::maxmum(BSTNode<T>* tree)
{
	while (tree != nullptr && tree->right != nullptr) {
		tree = tree->right;
	}

	return tree;
}

template <typename T>
BSTNode<T>* BSTree<T>::maxmum()
{
	return maxmum(mRoot);
}

template <typename T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree)
{
	while (tree != nullptr && tree->left != nullptr) {
		tree = tree->left;
	}

	return tree;
}

template <typename T>
BSTNode<T>* BSTree<T>::minimum()
{
	return minimum(mRoot);
}

template <typename T>
BSTNode<T>* BSTree<T>::preDecessor(BSTNode<T>* node)
{
	if (node->left != nullptr) {
		return maxmum(node->left);
	}

	BSTNode<T>* target = node->parent;
	while ((target != nullptr) && (node == target->left)) {
		node = target;
		target = target->parent;
	}

	return target;
}

template <typename T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T>* node)
{
	if (node->right != nullptr) {
		return minimum(node->right);
	}

	BSTNode<T>* target = node->parent;
	while ((target != nullptr) && (node == target->right)) {
		node = target;
		target = target->parent;
	}

	return target;
}

// template <typename T>
// void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
// {
// 	BSTNode<T>* iter = tree;
// 	BSTNode<T>* tmp = nullptr;

// 	while (iter != nullptr) {
// 		tmp = iter;
// 		if (z->key < iter->key) {
// 			iter = iter->left;

// 		} else {
// 			iter = iter->right;
// 		}
// 	}

// 	if (tmp == nullptr) {
// 		tree = z;

// 	} else {
// 		if (z->key < tmp->key) {
// 			tmp->left = z;

// 		} else {
// 			tmp->right = z;
// 		}
// 	}
// }

template <typename T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
	if (tree == nullptr) {
		tree = z;

	} else {
		z->parent = tree; // :)
		if (z->key < tree->key) {
			insert(tree->left, z);

		} else {
			insert(tree->right, z);
		}
	}
}

template <typename T>
void BSTree<T>::insert(T key)
{
	BSTNode<T>* z = new BSTNode<T>(key, nullptr, nullptr, nullptr);
	if (z == nullptr)
		return;

	insert(mRoot, z);
}

template <typename T>
void BSTree<T>::transplant(BSTNode<T>* &tree, BSTNode<T>* u, BSTNode<T>* v)
{
	if (u->parent == nullptr) {
		tree = v;

	} else if (u == u->parent->left) {
		// left child tree
		u->parent->left = v;

	} else {
		// right child tree
		u->parent->right = v;
	}

	if (v != nullptr) {
		// update v's parent
		v->parent = u->parent;
	}

}

template <typename T>
void BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T>* z)
{
	BSTNode<T>* x = nullptr;
	BSTNode<T>* y = nullptr;

	if (z->left == nullptr) {
		// z has no left child tree
		// then transplant right child tree
		transplant(tree, z, z->right);

	} else if (z->right == nullptr) {
		// z has no right child tree
		// then transplant left child tree
		transplant(tree, z, z->left);

	} else {
		// z has both left and right child tree
		y = minimum(z->right);
		if (y->parent != z) {
			transplant(tree, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		transplant(tree, z, y);
		y->left = z->left;
		y->left->parent = y;
	}

	delete z;
}

template <typename T>
void BSTree<T>::remove(T key)
{
	BSTNode<T>* target = search(key);
	if (target != nullptr) {
		remove(mRoot, target);
	}

}

template <typename T>
void BSTree<T>::print(BSTNode<T>* tree, T key, int direction)
{
	if (tree != nullptr) {
		if (direction == 0) {
			std::cout << std::setw(2) << tree->key << " is root" << std::endl;

		} else {
			std::cout << std::setw(2) << tree->key << " is " << std::setw(2)
			<< key << "'s " << std::setw(12) << (direction == 1 ? "right child" : "left child") << std::endl;
		}

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template <typename T>
void BSTree<T>::print()
{
	if (mRoot != nullptr)
		print(mRoot, mRoot->key, 0);
}

template <typename T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
	if (tree == nullptr)
		return;

	if (tree->left != nullptr)
		return destroy(tree->left);

	if (tree->right != nullptr)
		return destroy(tree->right);

	delete tree;

	tree = nullptr;
}

template <typename T>
void BSTree<T>::destroy()
{
	destroy(mRoot);
}
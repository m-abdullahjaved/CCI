#pragma once
#include "Headers.h"

template<typename T>
class BST {
	struct Node{
		T Data;
		Node* left;
		Node* right;
		Node* parent;
		Node(T val, Node* p= nullptr, Node* l = nullptr, Node* r = nullptr) {
			Data = val;
			left = l;
			right = r;
			parent = p;
		}
	};
	Node* insert(Node* root, T val) {
		if (root == nullptr)
			root = new Node(val);
		else {
			if (root->Data > val) {
				if (root->left)
					insert(root->left, val);
				else
					root->left = new Node(val, root);
			}
			else {
				if (root->right)
					insert(root->right, val);
				else
					root->right = new Node(val, root);
			}
		}
		return root;

	}
	void print(Node* root, int d) {
		if (root == nullptr)
			return;
		else {
			print(root->right, d + 1);
			for (int i = 1; i <= d; i++) {
				cout << "\t";
			}
			cout << root->Data << endl;
			print(root->left, d + 1);
		}
	}
	bool isSameBST(Node* a, Node* b) {
		if (a == nullptr && b == nullptr)
			return true;
		else if (a == nullptr || b == nullptr)
			return false;
		
		return a->Data == b->Data && isSameBST(a->left, b->left) && isSameBST(a->right, b->right);
	}

	static Node* Min(Node* r) {
		while (r->left)
			r = r->left;

		return r;
	}
	static Node* Max(Node* r) {
		while (r->right)
			r = r->right;

		return r;
	}
	static Node* Successor(Node* r) {
		if (r->right)
			return Min(r->right);
		else {
			while (r->parent && r->parent->left != r)
				r = r->parent;

			return r->parent;
		}
	}
	static Node* Predecessor(Node* r) {
		if (r->left)
			return Max(r->left);
		else {
			while (r->parent && r->parent->right != r)
				r = r->parent;

			return r->parent;
		}
	}
	Node* root;
public:
	
	BST() :root{nullptr} {

	}
	void insert(T val) {
		root = insert(root,val);
	}
	void print() {
		print(root, 0);
	}
	bool isSame(const BST& b) {
		return isSameBST(this->root, b.root);
	}

	class LNRIterator {
		Node* n;
	public:
		LNRIterator(Node* _n) {
			n = _n;
		}

		LNRIterator operator++(int) {
			n = Successor(n);
			return *this;
		}

		LNRIterator operator--(int) {
			n = Predecessor(n);
			return *this;
		}

		bool operator!=(const LNRIterator& i) {
			return n != i.n;
		}
		T operator*() {
			return n->Data;
		}
	};

	class RNLIterator {
		Node* n;
	public:
		RNLIterator(Node* _n) {
			n = _n;
		}
		RNLIterator operator++(int) {
			n = Predecessor(n);
			return *this;
		}
		RNLIterator operator--(int) {
			n = Successor(n);
			return *this;
		}
		bool operator!=(const RNLIterator& i) {
			return n != i.n;
		}
		T operator*() {
			return n->Data;
		}
	};

	LNRIterator begin() {
		return LNRIterator(Min(root));
	}
	LNRIterator end() {
		return LNRIterator(nullptr);
	}
	RNLIterator rbegin() {
		return RNLIterator(Max(root));
	}
	RNLIterator rend() {
		return RNLIterator(nullptr);
	}
	
};
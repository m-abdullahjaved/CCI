#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {
	class Node {
	public:
		int val;
		Node* next;
		Node(int data, Node* nxt = NULL) {
			val = data;
			next = nxt;
		}
	};
	Node* head, * tail;
public:
	MyLinkedList() : head(nullptr), tail(nullptr) {
	}

	MyLinkedList(vector<int> Vs):head(nullptr), tail(nullptr) {
		int size = Vs.size();
		for (int i = 0; i < size; i++) {
			addAtTail(Vs[i]);
		}
	}

	int get(int index) {
		int i = 0;
		Node* prev = head;
		while (i < index) {
			if (prev) {
				prev = prev->next;
			}
			else {
				break;
			}
			i++;
		}
		if (prev && i == index) {
			return prev->val;
		}
		else
			return -1;
	}

	void addAtHead(int val) {
		if (head == nullptr) {
			head = new Node(val);
			tail = head;
		}
		else {
			head = new Node(val, head);
		}
	}

	void addAtTail(int val) {
		if (tail == nullptr) {
			addAtHead(val);
		}
		else {
			tail->next = new Node(val);
			tail = tail->next;
		}
	}

	void addAtIndex(int index, int val) {
		if (index == 0)
			addAtHead(val);
		else if (head) {
			int i = 0;
			Node* prev = head;
			Node* curr = head->next;

			while (i < index - 1) {
				if (curr) {
					prev = curr;
					curr = curr->next;
				}
				else {
					break;
				}
				i++;
			}
			if (prev && (i + 1) == index) {
				prev->next = new Node(val, curr);
				if (prev == tail) {
					tail = tail->next;
				}
			}

		}
	}

	void deleteAtIndex(int index) {
		Node* temp = nullptr;
		if (index == 0) {
			temp = head;
			head = head->next;
			delete temp;
		}
		else {
			int i = 0;
			Node* prev = head;
			Node* curr = head->next;

			while (i < index - 1) {
				if (curr) {
					prev = curr;
					curr = curr->next;
				}
				else {
					break;
				}
				i++;
			}
			if (curr) {
				prev->next = curr->next;
				if (curr == tail)
					tail = prev;
				delete curr;
			}
		}
	}

	class iterator {
		Node* n;
	public:
		iterator(Node* _n) {
			n = _n;
		}
		iterator(const iterator& i) {
			n = i.n;
		}
		bool operator==(const iterator& i) {
			return n == i.n;
		}
		bool operator!=(const iterator& i) {
			return n != i.n;
		}
		void operator++(int) {
			n = n->next;
		}
		int& operator*() {
			return n->val;
		}
	};

	iterator begin() {
		return iterator(head);
	}
	iterator end() {
		return iterator(nullptr);
	}

};
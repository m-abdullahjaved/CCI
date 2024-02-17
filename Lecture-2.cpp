// Algorithm's Efficiency
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

template<typename T>
class GrowableArray {
	T* Vs;
	int Size;
public:
	GrowableArray():Size(0), Vs(nullptr){}

	void push_back(const T& v) {
		T* HA = new T[Size + 1];
		for (int i = 0; i < Size; i++) {
			HA[i] = Vs[i];
		}
		HA[Size] = v;
		Size++;

		delete[] Vs;
		Vs = HA;
	}
	T& operator[](int i) {
		if (i >= 0 && i < Size)
			return Vs[i];
	}
	friend ostream& operator<<(ostream&, GrowableArray<T>& GA) {
		for (int i = 0; i < GA.Size; i++) {
			cout << GA[i] << " ";
		}
		return cout;
	}
};

// Insertion Sort

void insertInSortedVector(vector<int>& nums, int i) {
	int j = i - 1;
	while (j >= 0 && nums[j] > nums[i]) {
		swap(nums[j], nums[i]);
		i--, j--;
	}
}

void insertionSort(vector<int>& nums) {
	int length = nums.size();

	for (int i = 1; i < length; i++)
		insertInSortedVector(nums, i);
}

ostream& operator<<(ostream&, vector<int>& A) {
	int length = A.size();
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";

	return cout;
}

int longestCommonSubsequence(string text1, string text2) {
	int m = text1.length() + 1, n = text2.length() + 1;
	int** c = new int* [m];
	for (int i = 0; i < m; i++) {
		c[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
		c[i][0] = 0;

	for (int j = 0; j < n; j++)
		c[0][j] = 0;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (text1[i - 1] == text2[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else {
				if (c[i - 1][j] >= c[i][j - 1])
					c[i][j] = c[i - 1][j];
				else
					c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[m - 1][n - 1];
}


/*
int main() {
	string text1 = "abc";
	string text2 = "def";
	cout << longestCommonSubsequence(text1, text2) << endl;
	return 0;
}
*/


/*
int main() {
	vector<int> A = { 10,24,5,20,15,0 };
	cout << "Before Sorting: " << A << endl;
	insertionSort(A);
	cout << "After Sorting: " << A << endl;

	return 0;
}
*/


/*
int main() {
	GrowableArray<int> GA;
	ifstream Rdr("input.txt");
	int d = 0;
	while (!Rdr.eof()) {
		Rdr >> d;
		// cout << d << " ";
		GA.push_back(d);
	}
	cout << GA << endl;
	return 0;
}
*/
class MyQueue {
	stack<int> s1, s2;
public:
	MyQueue() {
		
	}

	void push(int x) {
		s1.push(x);
	}

	int pop() {
		int temp = 0;
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		temp = s2.top();
		s2.pop();
		return temp;
	}

	int peek() {
		int temp = 0;
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		if (!s2.empty())
			temp = s2.top();
		return temp;
	}

	bool empty() {
		return s1.empty() && s2.empty();
	}
};
/*
int main() {
	MyQueue* obj = new MyQueue();
	obj->push(10);
	cout << obj->pop();
	cout << obj->peek();

	cout << obj->empty();
	return 0;
}
*/

void printStack(stack<int> S) {
	while (!S.empty()) {
		cout << S.top() << " ", S.pop();
	}
	cout << endl;
}
void sortStack(stack<int>& S) {
	stack<int> T;
	int var = 0;

	if (S.empty())
		return;


	while (true) {
		T.push(S.top());
		S.pop();
		while (!S.empty() && S.top() < T.top()) {
			T.push(S.top());
			S.pop();
		}

		if (S.empty()) {
			S = T;
			break;
		}
		var = S.top();
		S.pop();

		while (!T.empty() && T.top() < var) {
			S.push(T.top());
			T.pop();
		}
		S.push(var);

	}

}
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
};


int getSecretKey(int public_key)
{
	cout << public_key;

		if (public_key < 14)
		{
			getSecretKey(getSecretKey(getSecretKey(++public_key)));
		}
		return public_key;
}
/*
int main() {
	getSecretKey(12);
	int a = 1100111011100011;
	int b = 1100000001110000;

	cout << ~(a & b) << endl;
	return 0;
}
*/
/*
int main() {
	MyLinkedList L1;
	L1.addAtIndex(1, 0);
	cout << L1.get(0) << endl;
	
	return 0;
}
*/

/**
* 
* ["deleteAtIndex","deleteAtIndex","get","deleteAtIndex","get"]
[[3],[0],[0],[0],[0]]
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/*
int main() {
	stack<int> S;
	S.push(10);
	S.push(30);

	printStack(S);
	sortStack(S);
	printStack(S);
	return 0;
}
*/
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
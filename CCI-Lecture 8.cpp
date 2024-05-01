#include "BST.h"
#include <iomanip>



struct Student {
	string name;
	int rollno;
	double cgpa;
};

static bool operator<(const Student& l, const Student& r) {
	return l.cgpa < r.cgpa;
}

static ostream& operator<<(ostream&, const Student& lhs) {
	return cout << left << setw(15) << lhs.name << lhs.rollno << " " << lhs.cgpa;
}

/*
int main() {
	BST<int> B;
	//B.insert(4);
	//B.insert(2);
	//B.insert(6);
	//B.insert(1);
	//B.insert(3);
	//B.insert(5);
	//B.insert(7);
	////B.print();
	B.deleteNode(2);
	B.deleteNode(4);
	B.print();
	
	return 0;
}
*/
/*
int main() {
	Student A[] = {
		{"Abdullah",1, 2.5},
		{"Manahil", 2, 3.5},
		{"Khadija", 3, 3.0},
		{"Sarfraz", 4, 2.5},
		{"Ali", 5, 3.0},
		{"Moiz", 6, 2.7}
	};

	multiset<Student> S;
	for (int i = 0; i < 6; i++)
		S.insert(A[i]);
	
	for (auto i = S.rbegin(); i != S.rend(); i++)
		cout << *i << endl;
	


	return 0;
}
*/
/*
int main() {
	BST<int> B;
	vector<int> Vs = { 6, 4, 2, 1, 3, 5, 8, 9, 10, 7 };
	for (auto x : Vs)
		B.insert(x);

	B.print();
	cout << endl << endl;

	cout << "LNR : ";
	for (auto itr = B.begin(); itr != B.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl << endl;

	cout << "RNL : ";
	for (auto itr = B.rbegin(); itr != B.rend(); itr++) {
		cout << *itr << " ";
	}

	return 0;
}
*/
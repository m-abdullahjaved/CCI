#include "LinkedList.h"
#include <unordered_map>

unordered_map<int, int> removeDuplicates(MyLinkedList& L) {
	unordered_map<int, int> Us;
	for (auto i = L.begin(); i != L.end(); i++) {
		if (Us.find(*i) == Us.end())
			Us[*i] = *i;
	}
	return Us;
}

int main() {

	MyLinkedList L({1,2,3,4,1,1,3});
	
	for (auto itr = L.begin(); itr != L.end(); itr++) {
		cout << (*itr) << " ";
	}
	cout << endl;

	unordered_map<int, int> Us = removeDuplicates(L);

	for (auto itr = Us.begin(); itr != Us.end(); itr++) {
		cout << itr->first << " ";
	}


	return 0;
}
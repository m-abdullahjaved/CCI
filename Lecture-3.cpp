#include "LinkedList.h"
#include "CircularQueue.h"
#include <unordered_map>
#include <string>


/*
int main() {
	MyCircularQueue* obj = new MyCircularQueue(4);

	obj->enQueue(1);
	obj->enQueue(2);
	obj->enQueue(3);
	obj->enQueue(4);

	obj->deQueue();
	obj->enQueue(5);
	obj->deQueue();
	obj->deQueue();
	cout << obj->Front() << " " << obj->Rear() << endl;
	obj->deQueue();
	cout << obj->Front() << " " << obj->Rear() << endl;
	obj->enQueue(6);
	obj->enQueue(7);
	obj->enQueue(8);
	obj->enQueue(9);
	cout << obj->Front() << " " << obj->Rear() << endl;


	cout << "Front: " << obj->Front() << endl;
	cout << "Rear: " << obj->Rear() << endl;
	obj->deQueue();
	cout << "Front: " << obj->Front() << endl;
	cout << "Rear: " << obj->Rear() << endl;
	obj->enQueue(5);
	cout << "Front: " << obj->Front() << endl;
	cout << "Rear: " << obj->Rear() << endl;
	int param_3 = obj->Front();
	int param_4 = obj->Rear();
	bool param_5 = obj->isEmpty();
	bool param_6 = obj->isFull();
	return 0;
}

*/


int strStr(string haystack, string needle) {
	return haystack.find(needle);
}

int searchInsert(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target == nums[mid])
			return mid;
		else if (start == end && target != nums[mid]) {
			if (target > nums[mid])
				return start + 1;
			else
				return start;
		}
		else if (target > nums[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return mid;
}

bool isHappy(int n) {
	int num = n;
	unordered_map<int, int> map;
	while (true) {
		int result = 0;
		while (num >= 10) {
			result += pow(num % 10, 2);
			num /= 10;
		}
		result += pow(num, 2);
		cout << num << ": " << result << endl;
		if (map.find(result) == map.end()) {
			map[result] = result;
		}
		else
			return false;

		num = result;
		if (result == 1)
			return true;
	}
	return false;
}
int reverse(int x) {
	int num = abs(x), output = 0;
	while (num > 0) {
		if (output * 10 < INT_MAX)
			output *= 10;
		else
			return 0;
		output += (num % 10);
		num /= 10;
	}
	if (x < 0) {
		return -1 * output;
	}
	return output;
}

/*
void printDigit(int n) {
	if (n < 10) {
		cout << n << endl;
		return;
	}
	printDigit(n / 10);
	cout << (n % 10) << endl;
}

int main() {
	printDigit(12345);
	return 0;
}
*/

/*
int searchPeak(vector<int>& arr, int low, int high, int size) {
	int mid = (low + high) / 2;
	if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == size - 1 || arr[mid + 1] <= arr[mid]))
		return mid;
	else if (mid > 0 && arr[mid - 1] > arr[mid]) {
		return searchPeak(arr, low, mid - 1, size);
	}
	else
		return searchPeak(arr, mid + 1, high, size);
}

int findPeakElement(vector<int>& nums) {
	return searchPeak(nums, 0, nums.size() - 1, nums.size());
}

int main() {
	vector<int> nums = { 1,2 };
	cout << findPeakElement(nums) << endl;
	return 0;
}
*/

/*

int countTasks(vector<int> a, vector<int> b, int n) {
	int size = a.size();
	unordered_map<int, bool> map;
	int count = 0;
	
	for (int i = 0; i < size; i++) {
		if (map.find(a[i]) == map.end()) {
			map[b[i]] = true;
		}
		else {
			map[b[i]] = false;
		}
	}
	for (auto x : map) {
		if (x.second == 0) {
			count++;
		}
	}
	return (n - count);
}

int main() {

	
	vector<int> a = { 1 };
	vector<int> b = { 2 };
	
	vector<int> a = { 1,2 };
	vector<int> b = { 2,1 };

	vector<int> a = { 1,2,3,4,6,5 };
	vector<int> b = { 7,6,4,1,2,1 };
	
	cout << countTasks(a, b, 2) << endl;
	return 0;
}

*/




unordered_map<int, int> removeDuplicates(MyLinkedList& L) {
	unordered_map<int, int> Us;
	for (auto i = L.begin(); i != L.end(); i++) {
		if (Us.find(*i) == Us.end())
			Us[*i] = *i;
	}
	return Us;
}

/*
int main() {
	vector<int> permute;
	permutations("123", 0, 2, permute);
	for (auto x : permute) {
		cout << x << " ";
		if (x % 8 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

*/

/*
void permutations(string s, int l, int r, vector<int>& permute) {
	if (l == r) {
		//cout << s << endl;
		permute.push_back(stoi(s));
	}
	else {
		for (int i = l; i <= r; i++) {
			swap(s[i], s[l]);
			permutations(s, l + 1, r, permute);
			swap(s[i], s[l]);
		}
	}
	
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
*/
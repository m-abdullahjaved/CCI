// Recursion
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void extend(int count0, int count1, int n, string str, vector<string>& Vs) {
	if (str.length() == 2*n) {
		if (count0 == count1) {
			Vs.push_back(str); 
		}
		return;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 0)
			extend(count0 + 1, count1, n, str + '0', Vs);
		else {
			if (count1 < count0)
				extend(count0, count1 + 1, n, str + '1', Vs);
		}
	}

}

vector<string> generateString(int n) {
	vector<string> Vs;
	extend(0, 0, n, "", Vs);
	return Vs;
}
/*
int main() {
	vector<string> Vs = generateString(2);
	for (auto x : Vs)
		cout << x << " ";
	cout << endl;
	return 0;
}
*/
void floodFill(vector<vector<int>>& image, int oldColor, int sr, int sc, int newColor) {
	if (sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size() || oldColor == newColor)
		return;

	if (image[sr][sc] != oldColor)
		return;
	else {
		image[sr][sc] = newColor;
		floodFill(image, oldColor, sr + 1, sc, newColor);
		floodFill(image, oldColor, sr - 1, sc, newColor);
		floodFill(image, oldColor, sr, sc + 1, newColor);
		floodFill(image, oldColor, sr, sc - 1, newColor);

	}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	floodFill(image, image[sr][sc], sr, sc, color);
	return image;
}

void permuteRec(int si, int ei, vector<int> N, vector<vector<int>>& AllPs) {

	if (si == ei) {
		AllPs.push_back(N);
		return;
	}

	for (int i = si; i <= ei; i++) {
		swap(N[i], N[si]);
		permuteRec(si + 1, ei, N, AllPs);
		swap(N[i], N[si]);
	}
}

vector<vector<int>> permute(vector<int> nums) {
	vector<vector<int>> AllPs;
	permuteRec(0, nums.size() - 1, nums, AllPs);
	return AllPs;
}

int main() {
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> AllPs = permute(nums);
	for (auto x : AllPs) {
		for (auto row : x) {
			cout << row;
		}
		cout << endl;
	}
	return 0;
}

int findMax(int* freq, int size) {
	int max = freq[0];
	for (int i = 1; i < size; i++) {
		if (freq[i] > max)
			max = freq[i];
	}
	return max;
}
int maxFrequencyElements(vector<int>& nums) {
	int freq[100] = { 0 };
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		freq[nums[i] - 1]++;
	}
	int maxFreq = findMax(freq, 100);
	cout << maxFreq << endl;
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (freq[i] == maxFreq)
			count += freq[i];
	}
	return count;

}
/*
int main() {
	vector<int> nums{ 15 };
	cout << maxFrequencyElements(nums) << endl;
	return 0;
}
*/
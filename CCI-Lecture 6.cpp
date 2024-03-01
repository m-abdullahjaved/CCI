// Recursion
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


void createMap(int rows, int cols, string filename) {
	ofstream outFile(filename);
	outFile << rows << " " << cols << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			outFile << 0 << " ";
		outFile << endl;
	}
}

struct Position {
	int row;
	int col;
	
};

void loadMap(ifstream& Rdr, vector<vector<int>>& Map) {
	for (int i = 0; i < Map.size(); i++) {
		for (int j = 0; j < Map[i].size(); j++)
			Rdr >> Map[i][j];
	}
}
void printMap(vector<vector<int>>& Map) {
	for (int i = 0; i < Map.size(); i++) {
		for (int j = 0; j < Map[i].size(); j++)
			cout << Map[i][j] << " ";
		cout << endl;
	}
}

vector<Position> findAllRobots(vector<vector<int>>& Map) {
	vector<Position> Pos;
	for (int i = 0; i < Map.size(); i++) {
		for (int j = 0; j < Map[i].size(); j++) {
			if (Map[i][j] == 2) {
				Pos.push_back({i,j});
			}
		}
	}
	return Pos;
}

bool isEscapable(Position P, vector<vector<int>>& Map) {
	if (P.row < 0 || P.col < 0 || P.row >= Map.size() || P.col >= Map[0].size())
		return false;
	if (Map[P.row][P.col] == 1 || Map[P.row][P.col] == -1)
		return false;
	else if (Map[P.row][P.col] == 3)
		return true;
	else {
		Map[P.row][P.col] = -1;
		return (isEscapable({ P.row, P.col - 1 }, Map) ||
			isEscapable({ P.row, P.col + 1 }, Map) ||
			isEscapable({ P.row - 1, P.col }, Map) ||
			isEscapable({ P.row + 1, P.col }, Map));
	}
}

void statusOfAllRobots(vector<Position> RPositions, vector<vector<int>>& Map) {
	for (int i = 0; i < RPositions.size(); i++) {
		vector<vector<int>> copyMap = Map;
		if (isEscapable(RPositions[i], copyMap)) {
			cout << RPositions[i].row << " " << RPositions[i].col << " is escapable.." << endl;
		}
		else {
			cout << RPositions[i].row << " " << RPositions[i].col << " is not escapable.." << endl;
		}
	}
}

/*

int main() {
	ifstream Rdr("input.txt");
	int rows = 0, cols = 0;
	Rdr >> rows >> cols;
	vector<int> row(cols);
	vector<vector<int>> Map(rows,{row});
	loadMap(Rdr, Map);
	printMap(Map);

	vector<Position> RPositions = findAllRobots(Map);

	statusOfAllRobots(RPositions, Map);


	return 0;
}

*/
int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int fibonacci(int n) {
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
00
01
10
11

000
001
010
011
100
101
110
111

*/

vector<string> print01String(int n) {
	if (n == 0)
		return { "" };
	
	else {
		vector<string> nums = print01String(n - 1);
		vector<string> result;
		for (char sym = '0'; sym <= '1'; sym++) {
			for (int i = 0; i < nums.size(); i++) {
				result.push_back(sym + nums[i]);
			}
		}
		return result;
	}
}

void printDigit(int n) {
	if (n < 10) {
		cout << n << endl;
		return;
	}
	printDigit(n / 10);
	cout << (n % 10) << endl;
}
/*
int main() {
	vector<string> nums = print01String(5);
	for (auto x : nums) {
		cout << x << endl;
	}
	//cout << fibonacci(9) << endl;
	return 0;
}
*/

int slow_multiply(int A, int B) {
	if (B == 0)
		return 0;

	return slow_multiply(A, B - 1) + A;
}

int fast_multiply(int A, int B) {
	if (B == 0)
		return 0;
	int C = 1, R = A;
	do {
		R += R;
		C += C;
	} while (C + C <= B);

	return R + fast_multiply(A, B - C);
}

/*
int main() {
	cout << fast_multiply(10,100000000) << endl;
	//cout << slow_multiply(10,100000000) << endl;
	return 0;
}
*/
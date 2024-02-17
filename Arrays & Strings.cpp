// Lecture => 1 (CCI) [Arrays & Strings]
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// Problem: 1
bool isUniqueES(char A[], int length) {
    int counts[26]{};
    for (int i = 0; i < length; i++) {
        int c = A[i] - 'a';
        counts[c]++;

        if (counts[c] > 1)
            return false;
    }
    return true;
}
bool isUnique(char A[], int length) {
    sort(A, A + length);  // O (N lg N)
    for (int i = 0; i + 1 < length; i++) // O(N)
        if (A[i] == A[i + 1]) 
            return false;

    return true;
}

// Problem: 2
bool isPermutationNlgN(string s1, string s2) { // O (N lg N)
    sort(s1.begin(), s1.end()); // O(N lg N)
    sort(s2.begin(), s2.end()); // O(N lg N)
    return s1 == s2;  // O(N)
}
bool isPermutation(string s1, string s2) { // O(N)
    
    if (s1.length() != s2.length()) // O(1)
        return false;

    int counts[26]{};
    int length = s1.length();

    for (int i = 0; i < length; i++) { // O(N)
        int ci = s1[i] - 'a';
        counts[ci]++;
    }
    
    for (int i = 0; i < length; i++) { // O(N)
        int ci = s2[i] - 'a';
        counts[ci]--;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0)
            return false;
    }

    return true;
}

// Problem: 3
void Modify(char A[], int length) {
    char* M = new char[length * 3 + 1]; // Modified Array
    int mi = 0; // Index of Modified Array
    for (int i = 0; i <= length; i++) {
        if (A[i] != ' ') {
            M[mi] = A[i];
            mi++;
        }
        else {
            M[mi] = '%'; mi++;
            M[mi] = '2'; mi++;
            M[mi] = '0'; mi++;
        }
    }
    for (int i = 0; i < mi; i++) {
        A[i] = M[i];
    }
}

// Problem: 4
bool isSubstring(string s1, string s2) {
    return s1.find(s2) != string::npos;
}
bool rotatedString(string s1, string s2) {
    s2 += s2;
    return isSubstring(s2, s1);
}

// Problem: 5
string Compressed(string s) {
    string cs;
    int length = s.length(), count = 1;
    char prev = s[0];
    char A[10];
    for (int i = 1; i <= length; i++) {
        if (s[i] == prev) 
            count++;
        else {
            cs += prev;
            _itoa_s(count, A, 10);
            cs += A;
            prev = s[i];
            count = 1;
        }
    }
    return (cs.length() < s.length())? cs: s;
}

// Problem: 6
#define ROWS 10
#define COLS 10

// This is not always true that complexity will be O(N^2) if there is a nested loop..
bool isZeroMatrix(int M[ROWS][COLS], int n) { // O(N^2)
    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            if (M[ri][ci] != 0)
                return false;
        }
    }
    return true;
}
void printMatrix(int M[ROWS][COLS], int n) { // O(N^2)
    for (int ri = 0; ri < n; ri++) {
        cout << "[";
        for (int ci = 0; ci < n; ci++) {
            cout << M[ri][ci] << " ";
        }
        cout << "]" << endl;
    }
}

// Problem: 7
void transposeMatrix(int M[ROWS][COLS], int n) {
    int A[ROWS][COLS];
    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            A[ci][ri] = M[ri][ci];
        }
    }

    for (int ri = 0; ri < n; ri++) {
        for (int ci = 0; ci < n; ci++) {
            M[ri][ci] = A[ri][ci];
        }
    }
}
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rl = matrix.size();
    int cl = matrix[0].size();
    vector<vector<int>> A(cl, vector<int>(rl));

    for (int ri = 0; ri < rl; ri++) {
        for (int ci = 0; ci < cl; ci++) {
            A[ci][ri] = matrix[ri][ci];
        }
    }
    return A;
}


int main1() {
    int MATRIX[ROWS][COLS] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << (isZeroMatrix(MATRIX, 3)? "ZERO MATRIX" : "NOT A ZERO MATRIX") << endl;
    printMatrix(MATRIX, 3);
    transposeMatrix(MATRIX, 3);
    cout << "Transpose MATRIX:" << endl;
    printMatrix(MATRIX, 3);
    return 0;
}
int main0()
{
    char A[9] = "abcdeagh";
    cout << (isUnique(A, 8)?"Unique": "Not Unique") << endl;
    cout << (isPermutation("bulc", "club") ? "Permutation" : "Not Permutation") << endl;
    char Name[100] = { "M Abdullah Javed" };
    int length = strlen(Name);
    Modify(Name, length);
    cout << Name << endl;
    string str = "waterbottle", sub = "erbottlewat";
    cout << rotatedString(str,sub) << endl;
    cout << Compressed("abbbbbbb") << endl;
    return 0;
}
// Question
// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
// Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

//-------Code---------
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &v, int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < (n - i) - 1; j++) {
			int temp = v[i][j];
			v[i][j] = v[n - 1 -j][i];
			v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
			v[n - 1 - i][n - 1 - j] = v[j][n - 1 - i];
			v[j][n - 1 - i] = temp;
		}
	}
}

int main() {
	int n = 5;
	vector<vector<int>> v = { {1,2,3,4,5},
							{6,7,8,9,10},
							{11,12,13,14,15},
							{16,17,18,19,20},
							{21,22,23,24,25} };

	solve(v, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

// Question
// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

//---------Code------------
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

int solve(vector<vector<int>> &Mat, int n) {
    for (int i = n - 2; i >= 0; i--) {
        Mat[n - 1][i] = max(Mat[n - 1][i + 1], Mat[n - 1][i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        Mat[i][n - 1] = max(Mat[i + 1][n - 1], Mat[i][n - 1]);
    }

    int maxd = INT_MIN;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            maxd = max(maxd, Mat[i + 1][j + 1] - Mat[i][j]);
            Mat[i][j] = max(Mat[i][j], max(Mat[i + 1][j], Mat[i][j + 1]));
        }
    }

    return maxd;
}

int main() {
    int n = 6;
    vector<vector<int>> Mat = { { 1, 2, -1, -4, -20, 1 },
                                { -8, -3, 4, 2, 1, 34 },
                                { 3, 8, 6, 1, 3, 5 },
                                { -4, -1, 1, 7, -6, -11 },
                                { 0, -4, 10, -5, 1, 67 },
                                {4, 5, 6, 7,-11, 7} };
    int ans = solve(Mat, n);
    cout << ans; 
}

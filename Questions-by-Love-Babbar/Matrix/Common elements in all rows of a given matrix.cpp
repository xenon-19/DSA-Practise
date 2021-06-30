// Question
// https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

//-------Code---------
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n = 4, m = 5;
	vector<vector<int>> mat = { {1, 2, 1, 4, 8},
             {3, 7, 8, 5, 4},
             {8, 4, 7, 3, 1},
             {8, 1, 4, 7, 9},
    };
    vector<int> to_remove;
    unordered_set<int> mp;
    unordered_set<int> temp;

    for (int i = 0; i < m; i++) {
        mp.insert(mat[0][i]);
    }

    for (int i = 1; i < n; i++) {
        temp.clear();
        to_remove.clear();
        for (int j = 0; j < m; j++) {
            temp.insert(mat[i][j]);
        }

        for (auto x : mp) {
            if (temp.find(x) == temp.end())
                to_remove.push_back(x);
        }

        for (auto x : to_remove) {
            mp.erase(x);
        }
    }

    for (auto x : mp) {
        cout << x << ' ';
    }cout << endl;
    
}

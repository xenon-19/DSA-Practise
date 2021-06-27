// Question
// https://www.geeksforgeeks.org/print-elements-sorted-order-row-column-wise-sorted-matrix/
// Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

//------Code--------
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        int arr[N*N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i*N + j] = Mat[i][j];
            }
        }
        sort(arr, arr+N*N);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                Mat[i][j] = arr[i*N + j];
            }
        }
        return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends

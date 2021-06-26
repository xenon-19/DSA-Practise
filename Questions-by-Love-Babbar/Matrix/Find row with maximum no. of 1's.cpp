// Question
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.
  
//--------Code--------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int max_idx = m, ans = 0;
	    for(int i=0; i<n; i++){
	        if(max_idx == 0) break;
	        if(arr[i][max_idx - 1] == 1){
	            for(int j=max_idx-1; j>=0; j--){
	                if(arr[i][j] == 1) max_idx = j;
	                else break;
	            }
	            ans = i;
	        }
	    }
	    if(max_idx == m) return -1;
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends

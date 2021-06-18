// Question
// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m.
// Task is to check whether a2[] is a subset of a1[] or not. 
// Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.

//---------Code-----------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m) ;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];
        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }
        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(a1[i]);
    }
    bool flag = true;
    for(int i=0; i<m; i++){
        if(s.find(a2[i])==s.end()) flag = false;
    }    
    if(flag) return "Yes";
    else return "No";
}

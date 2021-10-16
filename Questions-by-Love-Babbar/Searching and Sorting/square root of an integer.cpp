// Question
// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. 
// You are given a number N, you have to output the number of integers less than N in the sample space S.
// https://practice.geeksforgeeks.org/problems/count-squares3649/1#

//--------------Code--------------
//--------------O(1)--------------

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution {
  public:
    int countSquares(int n) {
        int r = 1;
        // 100 iteratoins of newton-raphson
        for(int i=0; i<100; i++){
            r = (r + n/r)/2;
        }
        if(n - pow(r, 2) > 0) return r;
        else return r-1;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends

// Question
// Given a number N having only one ‘1’ and all other ’0’s in its binary representation, 
// find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. 
// Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.
// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1#

//-------Code-------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        if(n==0 || n&(n-1)) return -1;
        int cnt = 0;
        while(n>0){
            cnt++;
            n = n >> 1;
        }
        return cnt;
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
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends

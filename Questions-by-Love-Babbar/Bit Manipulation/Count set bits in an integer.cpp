// Question
// Given a positive integer N, print count of set bits in it. 
// https://practice.geeksforgeeks.org/problems/set-bits0143/1

//--------Code-O(logN)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int setBits(int l) {
        int count = 0;
        while(l>0){
            if(l%2 == 1)  count++;
            l = l>>1;
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends

//---------Code--------
//number of times loop runs is number of set bits in n
//Brian Kernighan's Algorithm
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        int cnt = 0;
        while(N > 0){
            N = (N-1)&N;
            cnt++;
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
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends

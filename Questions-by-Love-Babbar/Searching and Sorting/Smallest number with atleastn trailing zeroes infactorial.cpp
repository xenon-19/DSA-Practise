// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1

//-----------Code-----------
//----------O(log5)---------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int find_zeroes(int n){
        if(n<5) return 0;
        int x = log(n)/log(5);
        int cnt=0;
        int temp=1;
        for(int i=0; i<x; i++){
            temp *= 5;
            cnt += n/temp;
        }
        return cnt;
    }
    
    int findNum(int n){
        if(n==0) return 0;
        int lo=0, hi=50000, mid=0;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(find_zeroes(mid)>=n) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends

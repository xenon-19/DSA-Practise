// Question
// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k),
// having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.
// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

//------------Code-------------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution{
    public:
    long long countTriplets(long long arr[], int n, long long sum){
        sort(arr, arr+n);
        long long count = 0;
        for(int i=0; i<n; i++){
            int k=n-1;
            if(arr[i] > sum) break;
            for(int j=i+1; j<n; j++){
                while(arr[i]+arr[j]+arr[k]>=sum && k>j){
                    k--;
                }
                if(k<=j) break;
                count += k-j;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
   	int t;
    cin >> t;
    while (t--){
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	    cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends

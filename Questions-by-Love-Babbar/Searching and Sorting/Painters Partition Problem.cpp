// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/#

//-------------Code------------
//----------O(n*log(m))--------
// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool possible(long long x, int arr[], long long n, long long k){
        long long s=0;
        for(int i=0; i<n; i++){
            if(arr[i]>x) return 0;
            s+=arr[i];
            if(s>x){
                k--;
                s = arr[i];
            }
            if(k<=0) return 0;
        }
        return 1;
    }
    
    long long minTime(int arr[], int n, int k){
        long long lo=0, hi=accumulate(arr, arr+n, 0ll), mid=0;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            //cout << lo << " " << mid << " " << hi << endl;
            if(possible(mid, arr, n, k)){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends

// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

//-------------Code-------------
//----------O(n),O(n)-----------
// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    //store all running sum cnt, is sum is repeated that means the subarray in-between has 0 sum
    ll findSubarray(vector<ll> arr, int n ) {
        ll cnt = 0;
        unordered_map<ll, ll> mp;
        ll sum = 0;
        mp[0] = 1;
        for(auto x: arr){
            sum+=x;
            if(mp.find(sum) != mp.end()){
                cnt += mp[sum];
            }
            mp[sum]++;
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends

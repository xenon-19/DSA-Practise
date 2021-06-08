// Question
// Given an array arr of N integers.
// Find the contiguous sub-array with maximum sum.

//---------------Code--------------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int s=0, max_s=0;
        for(int i=0; i<n; i++){
            s+=arr[i];
            if(s<0) s=0;
            if(s>max_s) max_s = s;
        }
        return max_s;
    }
};

// { Driver Code Starts.
int main()
{
    int t,n;
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        cin>>n; //input size of array   
        int a[n];        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends

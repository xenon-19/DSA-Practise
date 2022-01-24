// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].
// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

//--------------Code---------------
//--------------O(n)---------------
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long> ret(n);
       long long temp = 1;
       ret[0] = 1;
       
       //now ret[i] will store product of nums till nums[i-1]
       for(int i=1; i<n; i++){
           ret[i] = ret[i-1]*nums[i-1];
       }
       
	//temp stores product of nums nums[i+1]...nums[n-1]
       for(int i=n-1; i>=0; i--){
           ret[i] *= temp;
           temp *= nums[i];
       }
       
       return ret;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends

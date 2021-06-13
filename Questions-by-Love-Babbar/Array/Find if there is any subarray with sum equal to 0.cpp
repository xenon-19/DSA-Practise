// Question
// Given an array of positive and negative numbers.
// Find if there is a subarray (of size at-least one) with 0 sum.

//--------Code---------
// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        set<int> unique_sum;
        int s=0;
        for(int i=0; i<n; i++){
            s+=arr[i];
            if(s==0) return true;
            unique_sum.insert(s);
        }
        if(n>unique_sum.size()) return true;
        else return false;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends

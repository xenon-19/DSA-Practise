// Question
// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).
// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#

//--------Code--------
//--------O(logN)---------

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int cnt = 0;
        long long grp_size = 1;
        while(grp_size <= n){
            grp_size <<= 1;
            cnt += ((n+1)/grp_size)*(grp_size/2) + ((n+1)%grp_size-grp_size/2 > 0 ? (n+1)%grp_size-grp_size/2: 0);
        }
        return cnt;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends

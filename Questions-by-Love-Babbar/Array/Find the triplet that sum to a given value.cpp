// Question
// Given an array arr of size n and an integer X. 
// Find if there's a triplet in the array which sums up to the given integer X.

//------Code------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A+n);
        int p1,p2;
        bool flag = false;
        for(int i=0; i<n-2 && !flag; i++){
            p1=i+1; p2=n-1;
            while(p1!=p2 && !flag){
                if(A[p1]+A[p2] > X - A[i]) p2--;
                else if(A[p1]+A[p2] < X - A[i]) p1++;
                else flag = true;
            }
        }
        return flag;
    }
};

// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends

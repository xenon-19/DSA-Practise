// Question
// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

//------Code-------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
  public:
    int sb(int arr[], int n, int x){   
        int p1=0, p2=0;
        int s=arr[0], m=n;
        while(p2<n && p1<n){
            if(s>x) m = min(m, p2-p1+1);
            if(s-arr[p1]>x){
                s-=arr[p1];
                p1++;
            }else{
                p2++;
                s+=arr[p2];
            }
        }
        return m;
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends

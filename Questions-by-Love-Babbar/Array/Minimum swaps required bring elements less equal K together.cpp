// Question
// Given an array of n positive integers and a number k. 
// Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

//--------Code--------
// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;
int minSwap(int *arr, int n, int k);
// Driver code
int main() {
	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends

int minSwap(int *arr, int n, int k) {
    int count=0, visited=0, min_gaps=n*n, temp_gaps=0;
    for(int i=0; i<n; i++){
        if(arr[i]<=k) count++;
    }
    if(count==0 || count==1 || count==n) return 0;
    
    for(int i=0; i<count; i++){
        if(arr[i]>k) temp_gaps++;
    }
    
    for(int i=count; i<n; i++){
        min_gaps = min(min_gaps, temp_gaps);
        if(arr[i]>k) temp_gaps++;
        if(arr[i-count]>k) temp_gaps--;
        min_gaps = min(min_gaps, temp_gaps);
    }
    return min_gaps;
}

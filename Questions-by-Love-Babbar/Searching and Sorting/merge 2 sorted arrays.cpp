// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
// Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
// Check Editorial for detailed solution

//-------------Code------------
//---O((n+m)*log(n+m)),O(1)----
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

    int arr(int i, int arr1[], int arr2[], int n){
        if(i<n) return arr1[i];
        else return arr2[i-n];
    }
    
    void swap(int i, int j, int arr1[], int arr2[], int n){
        //cout << "swapping i = " << i << " " << j << endl;
        //cout << "swapping " << arr(i, arr1, arr2) << " " << arr(j, arr1, arr2) << endl;
        if(i>=n){
            int temp = arr2[i-n];
            arr2[i-n] = arr2[j-n];
            arr2[j-n] = temp;
        }else if(j<n){
            int temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
        }else{
            int temp = arr1[i];
            arr1[i] = arr2[j-n];
            arr2[j-n] = temp;
        }
    }
    
	void merge(int arr1[], int arr2[], int n, int m) {
	    int gap = (n+m+1)/2;
	    while(gap){
	        for(int i=0; i<n+m-gap; i++){
	            if(arr(i, arr1, arr2, n)>arr(i+gap, arr1, arr2, n)) swap(i, i+gap, arr1, arr2, n);
	        }
	        if(gap<=1) gap=0;
	        else gap = (gap+1)/2;
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends

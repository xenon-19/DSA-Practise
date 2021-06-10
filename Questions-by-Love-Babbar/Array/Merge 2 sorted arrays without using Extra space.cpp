// Question
// Given two sorted arrays arr1[] of size N and arr2[] of size M. 
// Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
// Expected Time Complexity: O((n+m)*log(n+m))
// Expected Auxiliary Space: O(1)

//-----------Code-----------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i1=n-1,i2=0;
	    while(1){
	        if(arr1[i1]>arr2[i2]) swap(&arr1[i1], &arr2[i2]);
	        else break;
	        if(i1==0) break;
	        if(i2==m-1) break;
	        i1--; i2++;
	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
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


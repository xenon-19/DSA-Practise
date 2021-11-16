// Quesetion
// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

//-----------Code-----------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution{
public:
    int* findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        for(int i=0; i<n; i++){
            if(arr[i]==-1) continue;
            if(arr[arr[i]-1] == -1) continue;
            
            int temp;
            temp = arr[i];
            arr[i] = arr[arr[i]-1];
            arr[temp-1] = -1;
            i--;
        }
        for(int i=0; i<n; i++) if(arr[i] != -1) {ans[0] = arr[i]; ans[1] = i+1;}
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends

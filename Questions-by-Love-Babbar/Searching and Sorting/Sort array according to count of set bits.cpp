//Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 
//Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.
//https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#

//-----------------Code------------------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
int cnt_bits(int n){
    int cnt = 0;
    while(n){
        n &= n-1;
        cnt++;
    }
    return cnt;
}

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n){
        stable_sort(arr, arr+n, [](int a, int b){return cnt_bits(a)>cnt_bits(b);});
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends

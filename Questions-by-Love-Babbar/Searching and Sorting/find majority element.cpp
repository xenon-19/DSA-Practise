// Quesetion
// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

//----------Code------------
//---------O(n),O(1)--------
// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

//User function template for C++

class Solution{
  public:
    int majorityElement(int a[], int size){
        int idx = -1, cnt = 0;
        for(int i=0; i<size; i++){
            if(cnt == 0) idx = i;
            if(a[i] == a[idx]) cnt++;
            else cnt--;
        }
        cnt = 0;
        for(int i=0; i<size; i++) if(a[i] == a[idx]) cnt++;
        
        if(cnt > size/2) return a[idx];
        else return -1;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends

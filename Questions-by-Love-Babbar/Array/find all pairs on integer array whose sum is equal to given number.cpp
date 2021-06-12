// Question
// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

//---------Code-----------
// { Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
//User function template for C++
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int count = 0;
        map<int, int> m;
        map<int, int>::iterator idx;
        for(int i=0; i<n; i++){
            idx = m.find(arr[i]);
            if(idx!=m.end()) idx->second++;
            else m.insert({arr[i],1});
        }
        for(int i=0; i<n; i++){
            idx = m.find(k-arr[i]);
            if(idx!=m.end()){
                if(idx->first==arr[i]) count+=idx->second-1;
                else count+=idx->second;
            } 
        }
        return count/2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    } 
    return 0;
}  // } Driver Code Ends

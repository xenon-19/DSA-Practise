// Question
// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.
// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

//-----------Code------------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &arr, int k){
        sort(arr.begin(), arr.end());
        vector<unordered_set<int>> s(arr.size()+1, unordered_set<int>());
        for(int i=arr.size()-1; i>=0; i--){
            s[i] = s[i+1];
            s[i].insert(arr[i]);
        }
        set<vector<int>> res;
        int temp = 0;
        for(int i=0; i<arr.size(); i++){
            temp = arr[i];
            if(temp > k && arr[i]>=0) break;
            for(int j=i+1; j<arr.size(); j++){
                temp = arr[i] + arr[j];
                if(temp > k && arr[j]>=0) break;
                for(int l=j+1; l<arr.size(); l++){
                    temp = arr[i] + arr[j] + arr[l];
                    if(temp > k && arr[l]>=0) break;
                    if(s[l+1].find(k-temp) != s[l+1].end()){
                        res.insert({arr[i], arr[j], arr[l], k-temp});
                    }
                }
            }
        }
        vector<vector<int>> ret(res.begin(), res.end());
        return ret;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends

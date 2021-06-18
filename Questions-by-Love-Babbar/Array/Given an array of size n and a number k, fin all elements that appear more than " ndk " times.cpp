// Question
// Given an array arr[] of size N and an element k. 
// The task is to find all elements in array that appear more than n/k times.

//-------Code-------
// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator itr;
        unordered_map<int, int>::iterator itr2;
        
        int count=0;
        for(int i=0; i<n; i++){
            itr = mp.find(arr[i]);
            if(itr!=mp.end()){
                itr->second++;
            }else if(mp.size()<k-1){
                mp.insert({arr[i],1});
            }else{
                for(itr=mp.begin(); itr!=mp.end();){
                    itr->second--;
                    if(itr->second==0){
                        mp.erase(itr++);
                    }else itr++;
                }
            }
        }
        
        for(itr=mp.begin(); itr!=mp.end(); itr++){
            itr->second=0;
        }
        
        
        for(int i=0; i<n; i++){
            itr = mp.find(arr[i]);
            if(itr!=mp.end()){
                itr->second++;
                if(itr->second > n/k){
                    count++;
                    mp.erase(itr->first);
                }
            }
        }
    return count;
    }
};
// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends

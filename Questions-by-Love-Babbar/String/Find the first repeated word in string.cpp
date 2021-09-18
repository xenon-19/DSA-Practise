// Question
// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.
// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1

//-------Code-------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent(string arr[], int n){
        unordered_map <string, int> cnt;
        for(int i=0; i<n; i++)  cnt[arr[i]]++;
        
        int mc = -1, tmc = -1;
        string ms = "", tms = "";
        for(auto x: cnt){
            if(x.second > mc){
                tmc = mc;
                tms = ms;
                mc = x.second;
                ms = x.first;
            }else if(x.second > tmc){
                tmc = x.second;
                tms = x.first;
            }
        }
        return tms;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
  // } Driver Code Ends

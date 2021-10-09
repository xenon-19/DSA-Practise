// Question
// Given two strings A and B. Find the minimum number of steps required to transform string A into string B. 
// The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.
// https://practice.geeksforgeeks.org/problems/transform-string5648/1#

//-------------Code-------------
//-------------O(n)-------------
// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
 // } Driver Code Ends

class Solution
{
    public:
    int transform (string a, string b)
    {
       vector<int> freq(256, 0);
       for(auto x: b)   freq[x]++;
       for(auto x: a)   freq[x]--;
       for(auto x: freq) if(x) return -1;
       
       int pb = a.size()-1, pa = a.size()-1;
       int cnt = 0;
       while(pa>=0){
            if(a[pa]==b[pb]){
               pa--;
               pb--;
            }else{
               cnt++;
               pa--;
            }
       }
       return cnt;
       
    }
};


// { Driver Code Starts.
int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends

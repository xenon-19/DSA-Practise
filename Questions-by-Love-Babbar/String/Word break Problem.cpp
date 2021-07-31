// Question
// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
// https://practice.geeksforgeeks.org/problems/word-break1352/1

//--------Code--------
//----O(n^2),O(n)-----
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string a, vector<string> &b) {
        unordered_set<string> s;
        for(auto x: b){
            s.insert(x);
        }
        //dp[i] stores if the string starting from i to end is breakable or not
        vector<int> dp(a.length(), 0);
        for(int i=a.length()-1; i>=0; i--){
            string temp;
            temp = a[i];
            for(int j=i+1; j<a.length(); j++){
                if(s.find(temp)!=s.end() && dp[j]){
                    dp[i] = 1;
                }else{
                    temp += a[j];
                }
            }
            if(s.find(temp)!=s.end()) dp[i] =1;
        }
        if(dp[0]) return 1;
        else return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends

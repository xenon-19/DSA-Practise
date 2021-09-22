// Question
// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#

//--------Code-------
//---O(n^2),O(n^2)---
// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        //dp[i][j] stores max-len-common-substr in s1[:i+1],s2[:j+1]
        //dp[i][j] either dp[i-1][j-1]+1 or max(dp[i-1][j],dp[i][j-1])
        //here initializing first row and column as 0, then will use 1 indexing
        vector<vector<int>> dp(x+1, vector<int>(y+1));
        for(int i=0; i<=x; i++){
            dp[i][0] = 0;
        }
        for(int i=0; i<=y; i++){
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }   
        return dp[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends

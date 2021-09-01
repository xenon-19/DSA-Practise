// Question
// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
// Note: You have to return the answer module 109+7;

// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

//------Code------

//--------------recursive soln---------------
//--------------O(n**2),O(n**2)--------------
// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define mod 1000000007
class Solution{
    public:
        int count(int i, int j, vector<vector<int>> &dp, string &s){

          if(i>j) return 0;
          if(dp[i][j] != -1){
              return dp[i][j];
          }else{
              if(i==j){
                  dp[i][j] = 1;
              }else if(s[i] == s[j]){
                  dp[i][j] = (1 + count(i,j-1,dp,s)%mod + count(i+1,j,dp,s)%mod)%mod;
              }else{
                  dp[i][j] = ((count(i,j-1,dp,s) + count(i+1,j,dp,s))%mod - count(i+1,j-1,dp,s) + mod)%mod;
              }
              return dp[i][j];
          }
      }
    
    int countPS(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //cout << (int)(2*mod) << endl;
        return count(0, n-1, dp, s);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends

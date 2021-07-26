// Question
// https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2.
// The possible operations are:
// Insert
// Remove
// Replace

//--------Code--------
//--------O(n*m),O(n*m)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1));
        for(int i=0; i<t.length()+1; i++) dp[i][0] = i;
        for(int i=0; i<s.length()+1; i++) dp[0][i] = i;
        for(int i=1; i<t.length()+1; i++){
            for(int j=1; j<s.length()+1; j++){
                if(t[i-1]==s[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int temp = dp[i-1][j-1] + 1;
                    temp = min(temp, dp[i][j-1]+1);
                    temp = min(temp, dp[i-1][j]+1);
                    dp[i][j] = temp;
                }
            }
        }
        return dp[t.length()][s.length()];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends

// Question
// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
// Given a string, find the length of the longest repeating subsequence such that,
// the two subsequences don't have same string character at the same position, 
// i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

//-------Code--------
//--------theta(n**2), theta(n**2)---modified LCS
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
 
		int LongestRepeatingSubsequence(string s){
		    int n = s.length();
		    int dp[n+1][n+1] = {};
		    for(int i=1; i<=n; i++){
		        for(int j=1; j<=n; j++){
		            if(s[i-1]==s[j-1] && i!=j){
		                dp[i][j] = dp[i-1][j-1] + 1;
		            }else{
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

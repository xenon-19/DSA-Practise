// Question
// https://practice.geeksforgeeks.org/problems/word-wrap1646/1#
// Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
// Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 
// You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

//-------Code-------
//--O(n**2, n**2)---
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        vector<int> min_cost(nums.size(), INT_MAX);
        int last_line_cost = 0, curr_length = 0; 
        for(int i=0; i<nums.size(); i++){
            curr_length = nums[i];
            dp[i][i] = pow(k - curr_length, 2);
            int j;
            for(j=i+1; j<nums.size(); j++){
                last_line_cost = pow(k - curr_length, 2);
                if(curr_length + nums[j] + 1 <= k){
                    curr_length += nums[j] + 1;
                    dp[i][j] = dp[i][j-1] + pow(k-curr_length, 2) - last_line_cost;
                }else{
                    curr_length = nums[j];
                    dp[i][j] = dp[i][j-1] + pow(k-curr_length, 2);  
                }
            }
            dp[i][j-1] = dp[i][j-1] - pow(k - curr_length, 2);
        }
        
        min_cost[0] = dp[0][0];
        for(int i=1; i<nums.size(); i++){
            min_cost[i] = dp[0][i];
            for(int j=i-1; j>=0; j--){
                min_cost[i] = min(min_cost[j]+dp[j+1][i], min_cost[i]);
            }
        }
        return min_cost[nums.size()-1];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends

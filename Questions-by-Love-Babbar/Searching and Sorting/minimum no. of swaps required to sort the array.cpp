// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1#

//-------Code-------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	int minSwaps(vector<int>&nums){
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        int c = 0;
        sort(nums.begin(), nums.end());
        vector<int> vis(nums.size(), 0);
        
        //counting number of loops
        for(int i=0; i<nums.size(); i++){
            if(vis[i]) continue;
            c++;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                int temp = j;
                j = mp[nums[j]][mp[nums[j]].size()-1];
                mp[nums[temp]].pop_back();
            }
        }
        
        return nums.size()-c;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

// https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/

//--------Code--------
//------O(nlogn)------
class Solution {
public:
    
    int max_profit(vector<vector<int>> &intervals, int i, unordered_map<int, int> &dp){
        
        if(i==intervals.size()) return 0;
        if(dp.find(i) != dp.end()) return dp[i];
        
        int lo=i, hi=intervals.size(), mid=0;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(intervals[mid][0] < intervals[i][1]) lo = mid + 1;
            else hi = mid;
        }
        
        dp[i] = max(intervals[i][2]+max_profit(intervals, lo, dp), max_profit(intervals, i+1, dp));
        return dp[i];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> intervals(startTime.size(), vector<int> (3));
        for(int i=0; i<startTime.size(); i++){
            intervals[i][0] = startTime[i];
            intervals[i][1] = endTime[i];
            intervals[i][2] = profit[i];
        }
        
        sort(intervals.begin(), intervals.end());
        unordered_map<int, int> dp;
        return max_profit(intervals, 0, dp);
    }
};

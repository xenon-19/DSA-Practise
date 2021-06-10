// Question
// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, 
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

//---------------------Code------------------------
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i<intervals.size()){
            if(ans.size()==0){
                ans.push_back(intervals[0]);
                i++;
                continue;
            }
            if((*(ans.end()-1))[1] >= intervals[i][0]){
                if((*(ans.end()-1))[1] < intervals[i][1]){
                    (*(ans.end()-1))[1] = intervals[i][1];
                }
            }else{
                ans.push_back(intervals[i]);
            }
            i++;
        }   
        return ans;
    }
};

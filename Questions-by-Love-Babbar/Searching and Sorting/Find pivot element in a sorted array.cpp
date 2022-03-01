//same concept
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/

//-------code----------
//--------O(logn)------
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0, hi=nums.size()-1, mid=0;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]<nums[hi]) hi = mid;
            else lo = mid+1;
        }
        return nums[lo];
    }
};

// Question
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
// https://leetcode.com/problems/search-in-rotated-sorted-array/

//----------Code-------------
class Solution {
public:
    int pivot = 0;
    int n = 0;
    
    int rot(int i){
        return (i+pivot)%n;
    }
    
    int search(vector<int>& nums, int target) {
        n = nums.size();
        
        //finding pivot
        int lo = 0, hi = n-1, mid = 0;
        while(lo < hi-1){
            mid = lo + (hi-lo)/2;
            if(nums[lo] < nums[mid]) lo = mid;
            else hi = mid;
        }
        if(nums[lo] > nums[hi]) pivot = lo+1;
        
        //finding target
        lo = 0, hi = n-1;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(nums[rot(mid)] < target) lo = mid+1;
            else hi = mid;
        }
        
        lo = rot(lo);
        if(nums[lo]==target) return lo;
        else return -1;
    }
};

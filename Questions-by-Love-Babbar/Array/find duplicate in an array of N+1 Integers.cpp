// Question
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

//------------Code--------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1=0,p2=0;
        while(1){
            p1=nums[p1];
            p2=nums[nums[p2]];
            if(p1==p2) break;
        }
        p1=0;
        while(1){
            p1=nums[p1];
            p2=nums[p2];
            if(p1==p2) break;
        }
        return p2;
    }
};

 

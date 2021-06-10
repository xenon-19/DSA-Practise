// Question
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

//------------Code--------------
class Solution {
public:
    void swap(int *a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i == nums[i]-1) continue;
            if(nums[nums[i]-1] == nums[i]) return nums[i];
            else{
                swap(&nums[i], &nums[nums[i]-1]);
                i--;
            }
        }
        return -1;
    }
};

 

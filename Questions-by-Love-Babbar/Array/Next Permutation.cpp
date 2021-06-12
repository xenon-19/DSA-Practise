// Question
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
// The replacement must be in place and use only constant extra memory.

//------------Code--------------
class Solution {
public:
    //helper functions
    void reverse(vector<int>& nums){
        int temp;
        cout << "reverse function called" <<endl;
        for(int i=0; i<nums.size()/2; i++){
            temp = nums[i];
            nums[i] = nums[nums.size()-1-i];
            nums[nums.size()-1-i] = temp;
        }
    }
    
    int find_to_insert(vector<int>& nums, int val, int start, int end){
        int mid = (start+end)/2;
        if(start == end){
            if(nums[mid] > val) return mid;
            else return -1;
        }
        if(nums[mid] > val){
            if(mid==end) return mid;
            int right = find_to_insert(nums, val, mid+1, end);
            if(right == -1) return mid;
            else return right;
        }else{
            if(mid==start) return -1;
            int left = find_to_insert(nums, val, start, mid-1);
            if(left==-1) return -1;
            else return left;
        }
    }
    
    //main function
    void nextPermutation(vector<int>& nums) {
        int prev = nums[nums.size()-1];
        bool to_reverse = true;
        for(int i=nums.size()-1; i>=0; --i){
            cout << prev << " " << nums[i] << endl;
            if(prev>nums[i]){
                int to_insert = find_to_insert(nums, nums[i], i+1, nums.size()-1);
                int temp = nums[to_insert];
                nums[to_insert] = nums[i];
                nums[i] = temp;
                sort(nums.begin()+i+1, nums.end());
                to_reverse = false;
                //cout << "to_reverse set to false" << endl;
                break;
            }
            prev = nums[i];
        }
        if(to_reverse) reverse(nums);
    }
};

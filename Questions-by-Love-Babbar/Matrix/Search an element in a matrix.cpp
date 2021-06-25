// Question
// https://leetcode.com/problems/search-a-2d-matrix/
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

//-------Code-------
class Solution {
public:
    int find_row(vector<vector<int>>& matrix, int target, int start, int end){
        int idx = (start + end) / 2;
        int temp = 0;
        if(end < start) return -1;
        if(start == end && matrix[idx][0] > target){
            return -1;
        }else if(start == end && matrix[idx][0] <= target){
            return idx;
        }else if(matrix[idx][0] > target){
            temp = find_row(matrix, target, start, idx-1);
            if(temp != -1) return temp;
            else return -1;
        }else if(matrix[idx][0] <= target){
            temp = find_row(matrix, target, idx+1, end);
            if(temp != -1) return temp;
            else return idx;
        }
        return -1;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row_idx = find_row(matrix, target, 0, n-1);
        if(row_idx == -1) return false;
        auto found = find(matrix[row_idx].begin(), matrix[row_idx].end(), target);
        if(found == matrix[row_idx].end()) return false;
        else return true;
    }
};
 

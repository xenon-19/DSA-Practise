// Question
// https://leetcode.com/problems/reverse-string/submissions/
// Write a function that reverses a string. The input string is given as an array of characters s.

//---------Code---------
//--------O(n/2)
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i<s.size()/2; i++){
            char temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
    }
};

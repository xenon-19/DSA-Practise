// Question
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// https://leetcode.com/problems/longest-common-prefix/

//------Code------
class Solution {
public:
    string find_common(string& s1, string& s2){
        string common = "";
        int l = max(s1.size(), s2.size());
        for(int i=0; i<l; i++){
            if(s1[i] == s2[i]){
                common += s1[i];
            }else break;
        }
        return common;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for(int i=1; i<strs.size(); i++){
            common = find_common(common, strs[i]);
            if(common=="") break;
        }
        return common;
    }
};

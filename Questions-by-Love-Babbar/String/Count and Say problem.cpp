// Question
// https://leetcode.com/problems/count-and-say/

//----------Code-------------
class Solution {
public:
    string arr[30] = {"1"};
    
    string countAndSay(int n) {
        if(arr[n-1] != "") return arr[n-1];
        
        string prev_str = countAndSay(n-1);
        int count = 1;
        char temp = prev_str[0];
        
        for(int i=1; i<prev_str.length(); i++){
            if(prev_str[i-1] == prev_str[i]) count++;
            else{
                arr[n-1] += to_string(count) + temp;
                count=1; temp = prev_str[i];
            }
        }
        
        arr[n-1] += to_string(count) + temp;
        return arr[n-1];
    }
};

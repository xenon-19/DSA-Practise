// Question
// Given a string S consisting of only opening and closing curly brackets '{' and '}', 
// find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.
// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#

//-------Code-------
//-------O(n)-------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

int countRev (string s)
{

    if(s.length()%2) return -1;
    
    int curr_sum = 0, cnt = 0;
    unordered_map<char, int> val = {{'{', 2}, {'}', -2}};
    
    for(int i=0; i<s.length(); i++){
        int curr_val = val[s[i]];
        if(curr_sum + curr_val < 0){
            curr_sum -= curr_val;
            cnt++;
        }else{
            curr_sum += curr_val;
        }
    }
    
    curr_sum = 0;
    for(int i=s.length()-1; i>=0; i--){
        int curr_val = val[s[i]];
        if(curr_sum + curr_val > 0){
            curr_sum -= curr_val;
            cnt++;
        }else{
            curr_sum += curr_val;
        }
    }
    
    return cnt;
    
}

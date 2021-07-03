// Question
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
// Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. 
// Incase of conflict, return the substring which occurs first ( with the least starting index).

//-------Code-------
//-------O(n^2)
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int prt = 0, max_len = 1, n = s.length();
        string ans;
        ans+=s[0];
        //partition can be from 0 to n-2
        //for n-1 no element on right
        for(int prt=0; prt<n-1; prt++){
            int l = prt, r = prt+1, cnt = 0;
            bool flag = false;
            //if centre two elements equal
            //count all equal elements at centre
            if(s[l] == s[r]){
                cnt+=2;
                while(l-1 >= 0 && s[l-1]==s[prt]){
                    l--;
                    cnt++;
                }
                while(r+1 < n && s[r+1]==s[prt]){
                    r++;
                    cnt++;
                }
            }
            //if not equal then center must be sandwiched b/w two same chars
            else if(r+1 < n && s[l] == s[r+1]){
                    cnt+=3;
                    r++;
            }
            else continue;
            
            //for remaining elements  left must equal be right
            while(l-1 >= 0 && r+1 < n && s[l-1]==s[r+1]){
                cnt+=2;
                l--; r++;
            }
            
            if(max_len < cnt){
                max_len = cnt;
                ans = s.substr(l, cnt);
            }

        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
  // } Driver Code Ends


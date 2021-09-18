// Quesetion
// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000
  
// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1#

//---------Code----------
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map <char, int> map ={{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D',500},
                                        {'M',1000}};
        int prev_val = 0, val = 0;  
        int ans = 0;
        for(auto x: str){
            val = map[x];
            if(val<=prev_val){
                ans += val;
            }else{
                ans += val - 2*prev_val;
            }
            prev_val = val;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends

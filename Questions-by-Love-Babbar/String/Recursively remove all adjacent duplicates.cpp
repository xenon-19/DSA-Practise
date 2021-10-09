// Question
// Given a string S delete the characters which are appearing more than once consecutively.
// https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1#

//------------Code--------------
//---recursive,O(n),O(n^2)------

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        if(s.size()==1) return s;
        else{
            if(s[0]==s[1]){
                return removeConsecutiveCharacter(s.substr(1, s.size()-1));
            }else{
                return s[0] + removeConsecutiveCharacter(s.substr(1, s.size()-1));
            }
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 
// } Driver Code Ends

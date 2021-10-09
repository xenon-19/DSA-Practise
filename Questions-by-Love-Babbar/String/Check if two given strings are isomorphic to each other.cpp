// Question
// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’
// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#

//---------------Code----------------
// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>
#include <vector>
#include <unordered_map>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map<char, char> mp;
        vector<int> flag(256, 0);
        
        if(str2.size() != str1.size()) return false;
        
        for(int i=0; i<str1.size(); i++){
            if(mp.find(str1[i])==mp.end()){
                if(flag[str2[i]]) return false;
                else{
                    mp.insert({str1[i], str2[i]});
                    flag[str2[i]] = 1;
                }
            }else{
                if(str2[i] != mp[str1[i]]) return false;
            }
        }
        
        return true;
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends

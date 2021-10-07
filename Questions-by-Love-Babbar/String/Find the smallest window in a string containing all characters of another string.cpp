// Question
// Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  
// Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#

//----------------Code----------------
//--------------O(n),O(1)-------------

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        vector<int> freq(256, 0);
        for(int i=0; i<p.size(); i++) freq[p[i]]++;
        
        int lo=0, hi=-1;
        int n = s.size();
        int min_l = n+1, min_lo = 0, req = 0;
        
        for(auto x: freq) if(x>0) req++;
        
        while(true){
            if(freq[s[lo]] < 0){
                freq[s[lo]]++;
                lo++;
            }else{
                if(hi == n-1) break;
                else{
                    hi++;
                    if(freq[s[hi]]==1) req--; 
                    freq[s[hi]]--;
                }
            }
            if(req==0 && min_l > hi-lo+1){
                min_l = hi-lo+1;
                min_lo = lo;
            }
        }
        
        if(min_l == n+1) return "-1";
        return s.substr(min_lo, min_l);
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends

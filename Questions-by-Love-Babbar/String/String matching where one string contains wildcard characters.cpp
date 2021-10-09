// Question
// Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match.
// https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#

//-----------Code------------
//------O(n*m),O(n*m)--------

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    string wild = "";
    string pattern = "";
    int n = 0;
    int m = 0;
    vector<vector<int>> memo;
    
    bool rmatch(int i, int j){
        
        int oi = i, oj = j;
        if(memo[i][j] != -1) return  memo[i][j];
        
        while(i<n && j<m){
            if(wild[i]==pattern[j]){
                i++;
                j++;
            }else if(wild[i]=='?'){
                i++;
                j++;
            }else if(wild[i]=='*'){
                if(i==n-1){
                    memo[oi][oj] = 1;
                    return true;
                }
                for(int k=j; k<m; k++){
                    if(rmatch(i+1, k)){
                        memo[oi][oj] = 1;                      
                        return true;
                    }
                }
                memo[oi][oj] = 0;
                return false;
            }else{
                break;
            }
        }
        
        if(i==n && j==m){
            memo[oi][oj] = 1;
            return true;
        }else if(i==n-1 && wild[i] == '*' && j==m){
            memo[oi][oj] = true;
            return true;
        }
        else{
            memo[oi][oj] = 0;
            return false;
        }
    }
    bool match(string wild, string pattern)
    {
        int n=wild.size(), m=pattern.size();
        int i=0, j=0;
        while(i<n-1){
            if(wild[i]=='*' && wild[i+1]=='*'){
                wild = wild.substr(0, i+1) + wild.substr(i+2, n-i+1);
                n--;
            }else{
                i++;
            }
        }
        
        this->wild = wild;
        this->pattern = pattern;
        this->n = n;
        this->m = m;
        
        memo = vector<vector<int>> (n, vector<int> (m, -1));
        return rmatch(0, 0);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends

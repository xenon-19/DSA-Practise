// Question
// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.
// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        //frequecy cnt
        int cnt[256], max_distinct = 0;
        for(int i=0; i<256; i++) cnt[i] = 0;
        
        for(auto x: str){
            if(cnt[x]==0) max_distinct++;
            cnt[x]++;
        }
        
        for(int i=0; i<256; i++) cnt[i] = 0;
        int i=0,j=0,dis=1;
        cnt[str[i]] = 1;
        
        int minl=str.size(), low=0;
        
        //if starting char can be removed then remove it
        //else add a char to end
        //update minimum
        while(j<str.size() && i<=j){
            if(cnt[str[i]] > 1){
                cnt[str[i]]--;
                i++;
            }else{
                j++;
                if(j<str.size()){
                    cnt[str[j]]++;
                    if(cnt[str[j]]==1) dis++;
                }
            }
            
            if(dis==max_distinct && j-i+1 < minl){
                minl = j-i+1;
                low = i;
            }
        }
        return str.substr(low, minl);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends

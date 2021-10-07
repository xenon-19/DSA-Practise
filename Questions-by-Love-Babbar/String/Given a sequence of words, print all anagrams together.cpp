// Question
// Given an array of strings, return all groups of strings that are anagrams. 
// The groups must be created in order of their appearance in the original array.
// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#

//------------Code------------
//-----O(n*|S|),O(n*|S|)------

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        vector<vector<int>> keys;
        vector<vector<string>> ans;
        
        for(auto str: string_list){
            vector<int> temp(26,0);
            for(auto x: str){
                temp[x-97]++;
            }
            int pos = find(keys.begin(), keys.end(), temp) - keys.begin();
            if(pos == keys.size()){
                keys.push_back(temp);
                ans.push_back({str});
            }else{
                ans[pos].push_back(str);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
  // } Driver Code Ends

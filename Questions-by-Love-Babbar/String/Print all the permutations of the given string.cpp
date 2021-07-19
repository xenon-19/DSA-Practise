// Question
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
// Given a string S. The task is to print all permutations of a given string.

//------Code------
//-----theta(n!),O(n!)
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void get_permutation(set<string> &per, string s, int to_start){
	        string temp = s;
	        if(to_start == s.length()-1){
	            per.insert(s);
	        }else{
	            for(int i=to_start; i<s.length(); i++){
	                temp = s;
	                swap(temp[to_start], temp[i]);
	                get_permutation(per, temp, to_start+1);
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{   
		    set<string> per;
		    get_permutation(per, s, 0);
		    vector<string> ans(per.begin(), per.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends

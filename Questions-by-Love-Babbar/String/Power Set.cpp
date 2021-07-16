// Question
// https://practice.geeksforgeeks.org/problems/power-set4302/1#
// Given a string S find all possible substrings of the string in lexicographically-sorted order.

//-------Code-------
//---O(logN*2**n)---
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = s.length();
		    vector<string> ans;
            string temp;
            for(int i=0; i<(1<<n); i++){
                temp = "";
                for(int j=0; j<n; j++){
                    if((1<<j)&i) temp += s[j];
                }
                if(temp != "")
                    ans.push_back(temp);
            }
            sort(ans.begin(), ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends

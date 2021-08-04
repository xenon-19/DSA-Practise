// Queation
// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.
// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

//-------Code-------
// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    vector<int> lps(s.length(), 0);
	    int p1 = 0, p2 = 1;
	    while(p2 < s.length()){
	        if(s[p1]==s[p2]){
	            lps[p2] = p1+1;
	            p1++; p2++;
	        }else{
	            if(p1==0){
	                lps[p2] = 0;
	                p2++;
	            }else{
	                p1 = lps[p1-1];
	            }
	        }
	    }
	    return lps[s.length()-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends

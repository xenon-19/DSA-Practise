// Question
// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
// Given a string S, check if it is palindrome or not.

//---------Code----------
//------O(n/2)
// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    bool flag = true;
	    int n = s.length();
	    for(int i=0; i<n/2; i++){
	        if(s[i]!=s[n-1-i]){
	            flag = false;
	            break;
	        }
	    }
	    if(flag) return 1;
	    else return 0;
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
  

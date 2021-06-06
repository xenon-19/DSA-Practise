// Question
// You are given a string s. You need to reverse the string.
// You only need to complete the function reverseWord() that takes s as parameter and returns the reversed string.
// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).
// Constraints:
// 1 <= |s| <= 10000
  
//-----------------------------Code------------------------------- 
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main() {	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;	
	cout << reverseWord(s) << endl;
	}
	return 0;	
}

// } Driver Code Ends

//User function Template for C++
string reverseWord(string str){   
  char temp = ' ';
  int n = str.length();
  for(int i=0; i<n/2; i++){
      temp = str[i];
      str[i] = str[n-1-i];
      str[n-1-i] = temp;
  }
  return str;
}

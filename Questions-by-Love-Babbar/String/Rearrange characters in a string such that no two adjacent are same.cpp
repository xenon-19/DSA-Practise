// Question
// Given a string S with repeated characters (only lowercase).
// The task is to rearrange characters in a string such that no two
// adjacent characters are same.
// https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems

//---------Code----------
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    string s;
	    vector<int> cnt(26,0);
	    cin >> s;
	    
	    for(int i=0; i<s.length(); i++){
            cnt[s[i]-97]++;	        
	    }
	    
	    int m=0;
	    for(int i=0; i<26; i++){
	        if(cnt[i]>m) m=cnt[i];
	    }
	    
	    if(m>s.length()-m+1){
	        cout << '0' << endl;
	    }else{
	        cout << '1' << endl;
	    }
	}
	return 0;
}

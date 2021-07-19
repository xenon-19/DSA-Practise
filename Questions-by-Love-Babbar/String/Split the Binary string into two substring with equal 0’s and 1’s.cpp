// Question
// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
// Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. 
// they have equal number of 0s and 1s. 
// If it is not possible to split str satisfying the conditions then print -1.

//------Code-----
//------O(n)----
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "1010101011110000000";
	int temp = 0, cnt = 0;
	for(int i=0; i<s.length(); i++){
	      if(s[i]=='1') temp++;
	      else temp--;
	      if(temp == 0) cnt++;
	}
	if(cnt) cout << cnt;
	else cout << cnt;
	return 0;
}

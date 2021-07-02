//Question
https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
//Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?

//-------Code-------
//-------O(n^2)
#include <iostream>
using namespace std;

bool areRotation(string str1, string str2, int n, int m){
      if(n!=m) return false;
      int start = 0;
      while(start < n){
            if(str2[start] == str1[0]){
                  for(int i=0; i<n; i++){
                        int temp = (start+i < n) ? start+i : start+i-n;
                        if(str1[i]!=str2[temp]) break;
                        if(i==n-1) return true;
                  }
            }
            start++;
      }
      return false;
      
}

int main() {
	string str1 = "abcde", str2 = "deabc";
	int n = str1.length(), m = str2.length();
	cout << areRotation(str1, str2, n, m);
	return 0;
}

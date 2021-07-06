//Question
https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
//Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?

//-------Code-------
//-------O(n^2)-naive approach
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

//-------O(n),O(n)---KMP algo
#include <iostream>
using namespace std;

int* make_lcs(string s) {
	int n = s.length(), i = 0, j = 1;
	int* lcs = new int[n];
	lcs[0] = 0;

	while (j < n) {
		if (s[i] == s[j]) {
			lcs[j] = i + 1;
			i++; j++;
		}
		else {
			if (i == 0) {
				lcs[j] = 0;
				j++;
			}
			else {
				i = lcs[i - 1];
			}
		}
	}
	return lcs;
}

bool checkIfRotation(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();
	if (n != m) return false;
	if (m == 0) return false;

	int* lcs = make_lcs(s2);

	int i = 0, j = 0;
	while (i < 2 * n) {
		if (s1[i % n] == s2[j]) {
			if (j == m - 1) return true;
			i++; j++;
		}
		else {
			if (j == 0) i++;
			else j = lcs[j - 1];
		}
	}

	return false;
}

int main() {
	string s1 = "acfgtr";
	string s2 = "racfgt";

	cout << checkIfRotation(s1, s2);

	return 0;
}

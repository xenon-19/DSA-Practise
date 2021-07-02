// Question
// https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
// Write a Program to check whether a string is a valid shuffle of two strings or not.

//--------------Code----------------
//--------------O(n+m+k), O(n+m+k), n,m,k = length of str1, str2 and res string resp.
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> getCharMap(string s) {
	unordered_map<char, int> mp;
	for (int i = 0; i < s.length(); i++) {
		auto itr = mp.find(s[i]);
		if (itr == mp.end())
			mp.insert({ s[i], 1 });
		else
			itr->second++;
	}
	return mp;
}

bool checkValidShuffle(string str1, string str2, string res) {
	if (str1.length() + str2.length() != res.length()) return false;
	unordered_map<char, int> mp_str1 = getCharMap(str1);
	unordered_map<char, int> mp_str2 = getCharMap(str2);
	unordered_map<char, int> mp_res = getCharMap(res);

	for (auto x : mp_res) {
		auto itr1 = mp_str1.find(x.first);
		auto itr2 = mp_str2.find(x.first);
		int cnt = ((itr1 == mp_str1.end()) ? 0 : itr1->second) + ((itr2 == mp_str2.end()) ? 0 : itr2->second);
		if (x.second != cnt) return false;
	}

	return true;
}

int main() {
	string str1 = "abc", str2 = "123", res = "a12bc3";
	cout << checkValidShuffle(str1, str2, res);
	return 0;
}

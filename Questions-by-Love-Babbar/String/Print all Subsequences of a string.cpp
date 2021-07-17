Question
https://www.geeksforgeeks.org/print-subsequences-string/

//-------Code-------
//------O(2**n), O(2**n)
#include <bits/stdc++.h>
using namespace std;

void find_subsequences(string inp_str, unordered_set <string> &sub_set){
      string temp;
      vector <string> temp_vec;
      for(int i=0; i<inp_str.length(); i++){
            temp_vec.clear();
            for(auto x: sub_set){
                  temp = x + inp_str[i];
                  temp_vec.push_back(temp);
            }
            temp = inp_str[i];
            temp_vec.push_back(temp);
            for(auto x: temp_vec){
                  sub_set.insert(x);
            }
      }
}

int main() {
      string inp_str;
      unordered_set <string> sub_set;
	cin >> inp_str;
	if(inp_str.length() == 0)     cout << "String is empty"; 
      else find_subsequences(inp_str, sub_set);
      
      for(auto x: sub_set) cout << x << endl;
	return 0;
}

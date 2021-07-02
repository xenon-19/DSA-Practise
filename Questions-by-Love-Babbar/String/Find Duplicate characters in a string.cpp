//Questio
//https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

//--------Code--------
#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  unordered_set<char> visited;
  unordered_set<char> duplicates;
  
  for(int i=0; i<s.length(); i++){
    if(visited.find(s[i]) == visited.end()) visited.insert(s[i]);
    else duplicates.insert(s[i]);
  }
  
  for(auto x:duplicates) cout << x << " ";
  cout << endl;
  return 0;
}

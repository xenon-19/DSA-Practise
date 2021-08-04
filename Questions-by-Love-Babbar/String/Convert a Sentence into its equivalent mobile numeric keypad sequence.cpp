// Question
// Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 
// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

//--------Code--------
#include <bits/stdc++.h>
using namespace std;

int main() {
      string hs[] = {"2","22","222",
                        "3","33","333",
                        "4","44","444",
                        "5","55","555",
                        "6","66","666",
                        "7","77","777","7777",
                        "8","88","888",
                        "9","99","999","9999"};
      
      string inp_str = "IUGIOAJAJHFHUAJSHHKIJ";
      
      for(int i=0; i<inp_str.length(); i++){
            cout << hs[inp_str[i]-65];
      }cout << endl;
      
	return 0;
}

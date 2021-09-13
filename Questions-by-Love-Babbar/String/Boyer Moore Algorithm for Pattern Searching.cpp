// Boyer Moore Algorithm for Pattern Searching.

//-----------Code-----------
//---Bad Character Heuristic

#include <bits/stdc++.h>
using namespace std;

//create an array containing last-occurence-index of a char in given pattern
void make_last_pos(vector<int> &last_pos, string &pat){
      for(int i=0; i<pat.size(); i++){
            last_pos[pat[i]] = i;
      }
}

vector<int> find_pat(string &text, string &pat){
      vector<int> last_pos(256, -1);
      vector<int> pos;
	make_last_pos(last_pos, pat);
	
	//s strores the shift of pattern to match with text
	int s=0;
	while(s+pat.size() <= text.size()){
	      int i=pat.size()-1;
	      for(; i>=0; i--){
	            if(pat[i]!=text[s+i]) break;
	      }
	      //if pattern matches then good
	      if(i==-1){
	            pos.push_back(s);
	            s += 1;
	      }
	      //else shift patern to right till the mismatch char starts to match
	      //dont shift back
	      else{
	            s += max(1, (i-last_pos[text[i+s]]));
	      }
	}
	return pos;
}

int main() {
	string pat = "AABA";
	string text = "AABAACAADAABAABAIBIUiup-AABAuhbuhAABAibbiAAAABABA";
	
	vector<int> pos = find_pat(text, pat);
	for(auto x: pos){
	      cout << x << " ";
	}cout << endl;
	
	return 0;
}

  

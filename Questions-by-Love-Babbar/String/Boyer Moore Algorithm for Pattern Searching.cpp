// Boyer Moore Algorithm for Pattern Searching.
//Best expanation I found -> https://www.inf.hs-flensburg.de/lang/algorithmen/pattern/bmen.htm
//.htm not .html

//2 parts, bad-character, good-suffix, both should be combined for faster search
//worst case -> m*n
//best-case -> n/m

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

//----Good Suffix Heuristic
#include <bits/stdc++.h>
using namespace std;

void preprocess(string &pattern, vector<int> &shift){
      //case1
      //let temp be suffix of pattern startig at pos i
      //bpos[i]=starting pos of longest suffix of temp which is also a prefix
      vector<int> bpos(pattern.size()+1);
      bpos[pattern.size()] = pattern.size()+1;
      int i=pattern.size()-1, j=pattern.size();
      while(i>=0){
            while(j<pattern.size() && pattern[i] != pattern[j]){
                  if(!shift[j]){
                        shift[j] = j-i;
                  }
                  j = bpos[j+1] - 1;
            }
            bpos[i]=j;
            i--; j--;
      }
      
      //case2
      //where a suffix of matched suffix is a prefix of pattern
      //refer to above link for more detailed explanation
      j = bpos[0];
      for(int i=0; i<pattern.size(); i++){
            //if i has reached j, then push j forward
            if(i==j) j=bpos[j];
            
            //if shift[i]==0 => case2 situation
            if(shift[i]==0) shift[i] = j;
      }
}

vector<int> find_pat(string &text, string &pattern){
      //stores pos of match
      vector<int> pos;
      
      //shift[i] stores how much to shift if mismatch occurs at i
      vector<int> shift(pattern.size(), 0);
      preprocess(pattern, shift);
      
      //initial shift of pattern, to match with text
      int s=0;
      
      while(s+pattern.size() <= text.size()){
            int i=pattern.size()-1;
            while(i>=0){
                  if(text[s+i] == pattern[i])     i--;
                  else break;
            }
            if(i==-1){
                  pos.push_back(s);
                  s++;
            }else s+=shift[i];
      }
      
      return pos;
}

//driver code
int main() {
	string text = "wagwegiagweagwegguaagweggweggagwegbwiagwegovnwo";
	string pattern = "agweg";
	vector<int> occurences = find_pat(text, pattern);
	for(auto x: occurences){
	      cout << x << " ";
	}cout << endl;
	return 0;
}

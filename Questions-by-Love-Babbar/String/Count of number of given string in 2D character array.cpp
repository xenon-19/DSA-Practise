//Question
// Given a 2-Dimensional character array and a string, 
// we need to find the given string in 2-dimensional character array such that individual characters can be present left to right,
// right to left, top to down or down to top.
// https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/

//----------Code----------
//-------O(|s|*n*m)-------
#include <bits/stdc++.h>
using namespace std;

int get_directional_cnt(string &s, vector<string> &mat, int i, int j){
      int n=mat.size(), m=mat[0].size(), cnt = 0;
      
      //check right
      if(m-j < s.size()) ;
      else{
            int x = 0;
            for(; x<s.size(); x++){
                  if(s[x]!=mat[i][j+x]){
                        break;
                  }
            }
            if(x==s.size()){
                  cnt++;
            }
      }
      
      //check down
      if(n-i < s.size()) ;
      else{
            int x = 0;
            for(; x<s.size(); x++){
                  if(s[x]!=mat[i+x][j]){
                        break;
                  }
            }
            if(x==s.size()){
                  cnt++;
            }
      }
      
      //check left
      if(j+1 < s.size()) ;
      else{
            int x = 0;
            for(; x<s.size(); x++){
                  if(s[x]!=mat[i][j-x]){
                        break;
                  }
            }
            if(x==s.size()){
                  cnt++;
            }
      }
      
      //check up
      if(i+1 < s.size()) ;
      else{
            int x = 0;
            for(; x<s.size(); x++){
                  if(s[x]!=mat[i-x][j]){
                        break;
                  }
            }
            if(x==s.size()){
                  cnt++;
            }
      }
      return cnt;
}

int count_occurence(string &s, vector<string> &mat){
      int n = mat.size(), m = mat[0].size(), cnt=0;
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  if(mat[i][j] == s[0]){
                        cnt += get_directional_cnt(s, mat, i,j);
                  }
            }
      }
      return cnt;
}

int main() {
      string to_find = "MAGIC";
      vector<string> mat =   {"BBABBM",
                              "CBMBBA",
                              "IBABBG",
                              "GOZBBI",
                              "ABBBBC",
                              "MCIGAM" };
      cout << count_occurence(to_find, mat) <<endl;

	return 0;
}


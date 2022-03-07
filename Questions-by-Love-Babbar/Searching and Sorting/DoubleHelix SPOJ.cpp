// https://www.spoj.com/problems/ANARC05B/

//--------Code-------
//-----O(n), O(n)----

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(vector<int> &a1, vector<int> &a2){
      vector<int> inter;
      unordered_set<int> st;
      
      for(int i=0; i<a1.size(); i++){
            st.insert(a1[i]);
      }
      
      for(int i=0; i<a2.size(); i++){
            if(st.find(a2[i]) != st.end()){
                  inter.push_back(a2[i]);
            }
      }
      
      ll s=0, s1=0, s2=0;
      int i=0, j=0, k=0;
      
      while(i<a1.size() || j<a2.size() || k<inter.size()){
            if(i<a1.size() && (k>=inter.size() || a1[i] != inter[k])){
                  s1 += a1[i];
                  i++;
            }
            if(j<a2.size() && (k>=inter.size() || a2[j] != inter[k])){
                  s2 += a2[j];
                  j++;
            }
            if(i<a1.size() && j<a2.size() && k<inter.size() && a1[i] == inter[k] && a2[j] == inter[k]){
                  s+=max(s1, s2);
                  s1 = inter[k];
                  s2 = inter[k];
                  i++; j++; k++;
            }
            
      }
      
      s+=max(s1, s2);
      return s;
}

int main() {
	while(true){
	      int n1, n2;
	      cin >> n1;
	      if(n1==0) break;
	      vector<int> a1(n1);
	      for(int i=0; i<n1; i++) cin >> a1[i];
	      
	      cin >> n2;
	       vector<int> a2(n2);
	      for(int i=0; i<n2; i++) cin >> a2[i];
	      
	      cout << solve(a1, a2) << endl;
	}
	return 0;
}

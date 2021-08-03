// Question
// Implement Rabin-Karp Algorithm for pattern matching

//----O(n)-average-case---
#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool match(string s, string t, ll idx){
      for(int i=0; i<s.length(); i++){
            if(s[i]!=t[idx+i]){
                  return false;
            }
      }
      return true;
}

bool is_prime(int a){
      if(a<=1) return false;
      for(int i=2; i<a; i++){
            if(a%i == 0){
                  return false;
            }
      }
      return true;
}

int nxt_prime(int a){
      for(int i=a;true;i++){
            if(is_prime(i)) return i;
      }
}

int main() {
      
	string s,t;
	s = "utfdg";
	t = "efeutfdgijnjutfdgjnutfdge";
      
      if(s.length() > t.length()) return 0;
      
      ll hs = 0, ht = 0, base = 256; //hash-string, hash-temporary
	ll p = nxt_prime(s.length()); //prime number for taking modulo
	ll h = ((ll)pow(base, s.length()-1))%p; //constant for lshift to remove first character
	
	//the hash is (decimal representation of string as 256 base number) mod p
	//calculating both hashes at the same time
	for(int i=0; i<s.length(); i++){
	      hs = (hs*base + s[i])%p;
	      ht = (ht*base + t[i])%p;
	}
      
	if(match(s,t,0)) cout << 0 << endl;
	
	for(int i=1; i<t.length()-s.length(); i++){
	      ht = ((ht-t[i-1]*h)*base + t[i+s.length()-1])%p;
	      if(ht < 0) ht += p;
	      if(ht == hs){
	            if(match(s,t,i)) cout << i << endl;
	      }
	}
	
	return 0;
}

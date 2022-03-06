// https://www.spoj.com/problems/PRATA/

//---------Code-----------
//------O(log^2(n))-------

#include <bits/stdc++.h>
using namespace std;

bool possible(int p, vector<int> &cooks, int t){
      int pp=0;
      for(auto x: cooks){
            int lo=0, hi=p, mid=0;
            while(lo<hi){
                  mid = hi - (hi-lo)/2;
                  if(((mid*(mid+1)*x)/2) <= t) lo = mid;
                  else hi = mid-1;
            }
            pp += lo;
            if(pp >= p) return 1;
      }
      return 0;
}

int solve(){
      int p, n;
      cin >> p;
      cin >> n;
      
      vector<int> cooks(n);
      for(int i=0; i<n; i++) cin >> cooks[i];
      
      int lo=0, hi=4*100000000, mid=0;
      while(lo<hi){
            mid = lo + (hi-lo)/2;
            //cout << lo << " " << mid << " " << hi << endl;
            if(possible(p, cooks, mid)){
                  hi = mid;
            }
            else lo = mid+1;
      }
      return lo;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	      cout << solve() << endl;
	}
	return 0;
}

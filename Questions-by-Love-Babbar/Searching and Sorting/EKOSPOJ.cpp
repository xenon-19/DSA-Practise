// https://www.spoj.com/problems/EKO/

//---------Code------
//--------O(nlogn)---
#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &trees, int m, int h){
      long long s=0;
      for(int i=0; i<trees.size(); i++){
            //cout << s << " ";
            if(trees[i]>h) s += trees[i]-h;
            if(s >= m) return true;
      }
      //cout << endl;
      return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> trees(n);
	for(int i=0; i<n; i++){
	      cin >>  trees[i];
	}
	
	int lo=0, hi=INT_MAX, mid=0;
	while(lo<hi){
	      //cout << lo << " " << hi << endl;
	      mid = hi - (hi-lo)/2;
	      if(possible(trees, m, mid)) lo = mid;
	      else hi = mid-1;
	}
	cout << lo << endl;
	return 0;
}

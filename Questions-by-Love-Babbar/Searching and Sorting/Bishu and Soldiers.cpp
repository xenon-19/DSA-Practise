// Bishu went to fight for Coding Club. There were N soldiers with various powers. 
// There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). 
// After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, 
// help him to count the number of soldiers that he can kill in each round and the total sum of their powers.
  
// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

//----------Code---------
//------O(n*log(n))------
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
#define show(v) for(auto &x: v) cout << x << ' '; cout << endl;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
	cin >> n;

	vector<int> sol(n);
	for(int i=0; i<n; i++){
		cin >> sol[i];
	}

	int q;
	cin >> q;

	sort(sol.begin(), sol.end());
	
	//to store sum till ith soldier
	vector<int> str(n);
	str[0] = sol[0];
	for(int i=1; i<n; i++){
		str[i] = str[i-1]+sol[i];
	}

	for(int i=0; i<q; i++){
		int cstr;
		cin >> cstr;

		int lo=0, hi=n-1, mid;
		while(lo<hi){
			mid = hi - (hi-lo)/2;
			if(sol[mid]>cstr) hi = mid-1;
			else lo = mid;
		}

		cout << lo+1 << " " << str[lo] << endl;
	}
    return 0;
}

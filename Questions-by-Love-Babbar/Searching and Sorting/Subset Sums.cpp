// https://www.spoj.com/problems/SUBSUMS/

//-------Code-------
//--O(n/2*2^(n/2))--

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void find_possible_sum(vector<int> &arr, vector<ll> &s){
      s.push_back(0);
      for(ll i=0; i<arr.size(); i++){
            ll n = s.size();
            for(ll j=0; j<n; j++){
                  s.push_back(s[j]+arr[i]);
            }
      }
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	vector<int> arr1(arr.begin(), arr.begin()+(n+1)/2), arr2(arr.begin()+(n+1)/2, arr.end());
	
      vector<ll> s1, s2;
      find_possible_sum(arr1, s1);
      find_possible_sum(arr2, s2);
      
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());
      
      //for(auto x: s1) cout << x << " ";
      //cout << endl;
      //for(auto x: s2) cout << x << " ";
      //cout << endl;
      
      ll cnt = 0;
      for(ll i=0; i<s1.size(); i++){
            ll lo=-1, hi=s2.size()-1, mid=0;
            while(lo<hi){
                  mid = hi-(hi-lo)/2;
                  if(s1[i]+s2[mid]<=b) lo=mid;
                  else hi = mid-1;
            }
            
            lo = upper_bound(s2.begin(), s2.end(), a-s1[i]-1) - s2.begin();
            //cout << s1[i] << " " << lo << " " << hi << " " << cnt << endl;
            if(hi>=lo) cnt += (hi-lo) + 1;
      }
	cout << cnt << endl;
}

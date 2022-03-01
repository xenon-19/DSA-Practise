https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/

//---------Code----------
//---------O(nlogn)------
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

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> interval_in(2*n);

    for(ll i=0; i<n; i++){
        ll l,r;
        cin >> l >> r;
        interval_in[i] = {l, -1ll};
        interval_in[i+n] = {r, 1ll};
    }

    sort(interval_in.begin(), interval_in.end());

    vector<pair<ll, ll>> inter;

    ll s=0, l=-1;
    for(auto x: interval_in){
        if(l==-1) l=x.first; 
        s += x.second;
        if(s==0){
            inter.push_back({l, x.first});
            l = -1;
        }
    }

    vector<ll> cnt(inter.size());
    cnt[0] = inter[0].second - inter[0].first + 1;
    for(ll i=1; i<inter.size(); i++){
        cnt[i] = cnt[i-1] + inter[i].second - inter[i].first + 1;
    }

    for(ll i=0; i<q; i++){
        ll k;
        cin >> k;
        // cout << k << endl;
        // show(cnt);
        ll lo=0, hi=cnt.size(), mid=0;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(cnt[mid]<k) lo = mid+1;
            else hi = mid;
        }

        ll idx = lo;
        if(idx==0){
            cout << inter[idx].first +  k - 1 << endl;
            continue;  
        }
        if(idx==cnt.size()){
            cout << -1 << endl;
            continue;
        }
        
        k -= cnt[idx-1];
        cout << inter[idx].first + k - 1 << endl;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

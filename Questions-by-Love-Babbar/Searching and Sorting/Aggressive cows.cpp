// https://www.spoj.com/problems/AGGRCOW/

//-----Code-------
//------32*n------
#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &nums, int x, int c){
      int prev=1;
      c--;
      for(int i=1; i<nums.size(); i++){
            if(nums[i]-prev >= x){
                  prev = nums[i];
                  c--;
            }
            if(c<=0) return true;
      }
      return false;
}

int solve(){
      int n,c;
      cin >> n >> c;
      vector<int> nums(n);
      for(int i=0; i<n; i++){
            cin >> nums[i];
      }
      
      sort(nums.begin(), nums.end());
      
      int lo=0, hi=nums[n-1], mid=0;
      while(lo<hi){
            mid = hi - (hi-lo)/2;
            //cout << mid << endl;
            if(possible(nums, mid, c)) lo = mid;
            else hi = mid-1;
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

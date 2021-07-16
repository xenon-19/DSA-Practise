// Question
// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
// Given an integer n, calculate the square of a number without using *, / and pow(). 

//-------Code-------
//-------O(logN)----
#include <bits/stdc++.h>
using namespace std;

int get_sq(int n){
      int lshift_cnt = 0, size = sizeof(int)*8, ans = 0;
      if(n < 0) n = ~n + 1;
      while(lshift_cnt < 31){
            if((1<<lshift_cnt)&n){
                  if(ans+(n<<lshift_cnt)<ans){
                        return -1;
                  }
                  ans += n << lshift_cnt;
            }
            lshift_cnt++;
      }
      return ans;
}

int main() {
	int n;
	cin >> n;
	cout << get_sq(n);
	return 0;
}

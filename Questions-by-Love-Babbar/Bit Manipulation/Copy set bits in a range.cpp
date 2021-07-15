// Question
// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. 
// The task is consider set bits of y in range [l, r] and set these bits in x also.
// https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

//----------------Code---------------
#include <bits/stdc++.h>
using namespace std;

//l and r are lth and rth bit from left
void copyLtoR(int* x, int* y, int l, int r){
      int mask = 0, size = sizeof(int);
      mask = (1<<r-l+1) - 1;
      mask <<= size - r;
      mask &= *x;
      *y |= mask;
}

int main() {
	int x, y, l, r;
	cin >> x >> y >> l >> r;
	copyLtoR(&x, &y, l, r);
	cout << y;
	return 0;
}

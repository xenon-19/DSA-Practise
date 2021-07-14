// Question
// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. 
// The task is consider set bits of y in range [l, r] and set these bits in x also.
// https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

//----------------Code---------------
//---------------O(l+r)-------------
#include <bits/stdc++.h>
using namespace std;

//l and r are lth and rth bit from left
void copyLtoR(int* x, int* y, int l, int r){
      //storing different bits
      *x = *x ^ *y;
      //clear all bits left of l
      //-2 to not make the number negative
      *x = *x << l - 2;
      *x = *x >> l - 2;
      //clear all bits right of r
      *x = *x >> sizeof(int)*8 - r - 1;
      *x = *x << sizeof(int)*8 - r - 1;
      //inverting different bits of y
      *y = *y ^ *x;
}

int main() {
      //1237 1109 8 5
      //here 1109 will become 1237 
	int x, y, l, r;
	cin >> x >> y >> l >> r;
	copyLtoR(&x, &y, l, r);
	cout << y;
	return 0;
}

// Question
// https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
// Given a two integers say a and b. Find the quotient after dividing a by b without using multiplication, division and mod operator.

//-----------Code---------
//----------O(loga)-------
#include <bits/stdc++.h>
using namespace std;

int divide(int dvdnt, int dvsr){
      int lshift_size = 0, ans = 0, to_sub;
      
      bool neg_flag = false;
      if((dvdnt ^ dvsr) < 0) neg_flag = true;
      
      if(dvdnt < 0) dvdnt = ~dvdnt + 1;
      if(dvsr < 0) dvsr = ~dvsr + 1;
      
      to_sub = dvsr;
      while(to_sub < dvdnt){
            if((to_sub << 1) < 0) break;
            to_sub <<= 1;
            lshift_size++;
      }
      while(lshift_size>=0){
            if(to_sub <= dvdnt){
                  dvdnt -= to_sub;
                  ans |= 1 << lshift_size;
            }
            to_sub >>= 1;
            lshift_size--;
      }
      
      if(neg_flag){
            ans = ~ans + 1;
      }
      return ans;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	cout << divide(n1, n2);
	return 0;
}

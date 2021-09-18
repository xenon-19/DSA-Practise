// Quesetion
// Given a binary string, that is it contains only 0s and 1s. 
// We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.
// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1#

//------Code------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// } Driver Code Ends

int minFlips (string s)
{
    int z_at_odd = 0, z_at_even = 0;
    int total_odd = s.size()/2, total_even = s.size()-total_odd;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            if(i%2) z_at_odd++;
            else z_at_even++;
        }
    }
    return min((total_even - z_at_even + z_at_odd),(total_odd - z_at_odd + z_at_even));
}

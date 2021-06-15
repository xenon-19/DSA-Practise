// Question
// Given an integer N, find its factorial.
// Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.

//---------Code-----------
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        int carry=0;
        int digit;
        int prod;
        ans.push_back(1);
        for(int i=2; i<=N; i++){
            carry=0;
            for(int j=0; j<ans.size(); j++){
                prod = ans[j]*i + carry;
                digit = prod%10;
                ans[j] = digit;
                carry = prod/10;
            }
            while(carry){
                ans.push_back(carry%10);
                carry = carry/10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

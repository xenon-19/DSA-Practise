// Question
// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. 
// Find the other two numbers.
// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#

//---------------Code--------------
//----------O(N)------------
// { Driver Code Starts
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xor_of_2_missing = 0;
        for(auto x: nums){
            xor_of_2_missing ^= x;
        }
        //int k stored the number corresponding to the rightmost bit of xor-of_2_missing
        //for xor = 1001, k will be 1
        // ~(xor -1) is the 2s compliment of xor
        int k = (xor_of_2_missing) & ~(xor_of_2_missing - 1);
        vector<int> ans = {0, 0};
        for(auto x: nums){
            if(x&k){
                ans[0] ^= x;
            }else{
                ans[1] ^= x;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends

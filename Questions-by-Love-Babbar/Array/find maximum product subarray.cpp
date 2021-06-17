// Question
// Given an array Arr that contains N integers (may be positive, negative or zero). 
// Find the product of the maximum product subarray.

//--------Code------------
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
        long long max_prod = arr[0], curr_max = arr[0], curr_min = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]<0){
                long long temp = curr_max;
                curr_max = curr_min;
                curr_min = temp;
            }
            curr_max = max((long long)arr[i], curr_max*arr[i]);
            curr_min = min((long long)arr[i], curr_min*arr[i]);
            
            max_prod = max(max_prod, curr_max);
        }
    return max_prod;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

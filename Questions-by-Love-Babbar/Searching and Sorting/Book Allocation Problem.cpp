// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#


//--------Code--------
//-----o(nlogn)-------
// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool is_possible(int a[], int n, int m, int x){
        long long s=0;
        for(int i=0; i<n; i++){
            if(a[i]>x) return false;
            if(s+a[i]>x){
                s=a[i];
                m--;
            }else{
                s += a[i];
            }
            if(m<=0) return false;
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m){
     long long lo=0, hi=LLONG_MAX, mid=0;
     while(lo<hi){
         mid = lo + (hi-lo)/2;
         if(is_possible(a, n, m, mid)) hi=mid;
         else lo = mid+1;
     }
     return lo;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends

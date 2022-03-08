// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

//----------Code----------
//------O(nlogn),O(n)-----

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define ll long long

class Solution{   
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll cntMerge(ll arr[], ll l, ll  m, ll r){
       ll ta[r-l];
       ll p1=l, p2=m, cnt=0;
       while(p1<m || p2<r){
           if(p1==m){
               ta[p1-l+p2-m] = arr[p2];
               p2++;
           }else if(p2==r){
               ta[p1-l+p2-m] = arr[p1];
               p1++;
           }else if(arr[p1]<=arr[p2]){
               ta[p1-l+p2-m] = arr[p1];
               p1++;
           }else{
               ta[p1-l+p2-m] = arr[p2];
               cnt += m-p1;
               p2++;
           }
       }
       
       for(int i=l; i<r; i++){
           arr[i] = ta[i-l];
       }
       
       return cnt;
       
    }
    
    
    ll cntMergeSort(ll arr[], ll l, ll r){

        if(r-l==0) return 0;
        if(r-l==1) return 0;
        
        ll cnt=0;
        cnt += cntMergeSort(arr, l, l + (r-l)/2);
        cnt += cntMergeSort(arr, l + (r-l)/2, r);
        cnt += cntMerge(arr, l, l + (r-l)/2, r);
        return cnt;
    }
    
    long long inversionCount(long long arr[], long long N){
        return cntMergeSort(arr, 0, N);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends

// Question
// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
// If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

//-------------Code---------------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution{
  public:   
    long long int count_after_merging(long long int* arr, long long int start1, long long int end1, long long int start2, long long int end2){
        long long int i=start1, j=start2;
        vector<long long int> temp;
        long long int count=0;
        while(1){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                if(i<end1) i++;
                else{
                    for(;j<=end2;j++){
                        temp.push_back(arr[j]);
                    }
                    break;
                }
            }else{
                temp.push_back(arr[j]);
                count+=end1-i+1;
                if(j<end2) j++;
                else{
                    for(;i<=end1;i++){
                        temp.push_back(arr[i]);
                    }
                    break;
                }
            }
        }
        for(int i=start1; i<=end2; i++){
            arr[i]=temp[i-start1];
        }
        temp.clear();
        return count;
    }
    
    long long int find_inversionCount_recursive(long long int* arr, long long int start, long long int end){
        long long int mid = (start+end)/2;
        if(start==end) return 0;
        long long int count_left = find_inversionCount_recursive(arr, start, mid);
        long long int count_right = find_inversionCount_recursive(arr, mid+1, end);
        long long int count = count_left + count_right + count_after_merging(arr, start, mid, mid+1, end);
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return find_inversionCount_recursive(arr, 0, N-1);
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

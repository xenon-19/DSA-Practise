// Question
// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


//------------Code-----------------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution
{
    public:
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sort012(int a[], int n){
        int last_0 = -1, first_2 = n;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                while(1){
                    if(a[last_0+1]==0) last_0++;
                    else break;
                }
                if(i<=last_0){
                    i=last_0;
                    continue;
                }
                swap(&a[i], &a[last_0+1]);
                i--;
            }else if(a[i]==2){
                while(1){
                    if(a[first_2-1]==2) first_2--;
                    else break;
                }
                if(i>=first_2){
                    break;
                }
                swap(&a[i], &a[first_2-1]);
                i--;
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        Solution ob;
        ob.sort012(a, n);
        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }
        cout << endl;      
    }
    return 0;
}
  // } Driver Code Ends

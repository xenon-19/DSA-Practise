// Question
// An array contains both positive and negative numbers in random order. 
// Rearrange the array elements so that all negative numbers appear before all positive numbers.


//--------------Code-------------------
#include <bits/stdc++.h>
using namespace std;

void solve(int* arr, int n){
    int l = -1;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            while(1){
                if(l>=n) break;
             if(arr[l+1]<0) l++;
             else break;
            }
            if(l>i){
                i=l;
                continue;
            }
            int temp = arr[i];
            arr[i] = arr[l+1];
            arr[l+1] = temp;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    solve(arr,n);  
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}

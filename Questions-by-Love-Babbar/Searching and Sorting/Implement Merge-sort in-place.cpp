// https://www.geeksforgeeks.org/in-place-merge-sort/

//--------Code-------
//---O(n*lon*logn)---

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends


class Solution
{
    public:
    void merge(int arr[], int l, int m, int r){
        int gap = r-l+1;
        while(gap){
            int i=0;
            while(i+gap<=r){
                if(arr[i]>arr[i+gap]) swap(arr[i], arr[i+gap]);
                i++;
            }
            if(gap==1) break;
            gap = (gap+1)/2;
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r){
        //cout << l << " ->l, r<- " << r << endl;
        if(r-l+1==1) return;
        int m = l+(r-l)/2;
        if(r!=l){
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
        // for(int i=l; i<=r; i++){
        //     cout << arr[i] << " ";
        // }cout << endl;
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends

// Question
// Given an array arr[] of N non-negative integers representing the height of blocks. 
// If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

//--------Code----------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int p1=0, p2=n-1, l=0, r=0;
        int water=0;
        while(p1!=p2){
            if(arr[p1]>l) l=arr[p1];
            if(arr[p2]>r) r=arr[p2];
            if(l<=r){
                water += l-arr[p1];
                p1++;
            }else{
                water += r-arr[p2];
                p2--;
            }
        }
        return water;
    }
};

// { Driver Code Starts.
int main(){    
    int t;
    //testcases
    cin >> t;   
    while(t--){
        int n;       
        //size of array
        cin >> n;       
        int a[n];        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;       
    }   
    return 0;
}  // } Driver Code Ends

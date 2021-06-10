//   Question
//   Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element.
//   Find the minimum number of jumps to reach the end of the array (starting from the first element). 
//   If an element is 0, then you cannot move through that element.

//--------------------Code---------------------------

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int max_reach=arr[0], steps=arr[0], jumps=0;
        if(max_reach>=n-1) return 1;
        for(int i=1; i<n; i++){
            steps--;
            if(i>max_reach) return -1;
            max_reach = max(max_reach, i+arr[i]);
            if(max_reach >= n-1)    return jumps+2;
            if(steps == 0){
                jumps++;
                steps = max_reach - i;
            }
        }
        return jumps;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

// Question
// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#

//-------Code---------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
   vector<int> ret = {-1,-1};
   for(int i=0; i<n; i++){
       if(arr[i]==x){
           if(ret[0]==-1) ret[0]=i;
           ret[1]=i;
       }
   }
   return ret;
}

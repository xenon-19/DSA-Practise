// Question
// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.
// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

//-----------Code-----------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 
bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
// } Driver Code Ends

bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    int p1=0, p2=0;
    while(p2<size){
        if(arr[p2]-arr[p1] > n) p1++;
        else if(arr[p2]-arr[p1] < n) p2++;
        else return true;
    }
    return false;
}

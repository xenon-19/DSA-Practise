// Question
// Given an array of positive integers. 
// Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

//--------Code--------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> s;
        for(int i=0; i<N; i++){
            s.insert(arr[i]);
        }
        int max_count=0;
        int count=0;
        for(int i=0; i<N; i++){
            if(s.find(arr[i]-1)==s.end()){
                int temp = arr[i];
                count=0;
                while(1){
                    if(s.find(temp)!=s.end()){
                        count++;
                        temp++;
                        max_count = max(count, max_count);
                    }else break;
                }
            }
        }
        return max_count;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
 

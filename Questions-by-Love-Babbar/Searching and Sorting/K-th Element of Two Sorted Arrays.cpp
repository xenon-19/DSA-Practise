// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.

//--------code1---------
//-----O(logn+logm)-----
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //lo set to -1 as maybe answer is not present in the particular array, in such
        //case the array will converge to -1
        int lo1=-1, lo2=-1, hi1=n-1, hi2=m-1, mid1=0, mid2=0;
        //find when anyone array converges
        while(lo1<hi1 && lo2<hi2){
            mid1 = hi1 - (hi1-lo1)/2;
            mid2 = hi2 - (hi2-lo2)/2;
            if(mid1+mid2+2 > k){
                if(arr1[mid1] > arr2[mid2]){
                    hi1 = mid1-1;
                }else{
                    hi2 = mid2-1;
                }
            }
            else{
                if(arr1[mid1] > arr2[mid2]){
                    lo2 = mid2;
                }else{
                    lo1 = mid1;
                }
            }
        }
        
        //when converged in one array, the number of elements from 2nd array can be
        //found out by subtracting it form 2nd array
        if(lo1==hi1){
            lo2 = k - lo1 - 2;
        }else{
            lo1 = k - lo2 - 2;
        }
        
        if(lo1<0) return arr2[lo2];
        if(lo2<0) return arr1[lo1];
        return max(arr1[lo1], arr2[lo2]);
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends


//-------code 2----------
//--------O(logk)--------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   
        if(n+m < k) return -1;
        if(k==0) return -1;
        
        int kt = k;
        
        int p1=-1, p2=-1, t1=0, t2=0;
        while(k && p1<n-1 && p2<m-1){
            if(p1+(k+1)/2>n-1){
                t1 = n-1;
                t2 = kt - n - 1;
            }else if(p2+(k+1)/2>m-1){
                t2 = m-1;
                t1 = kt - m - 1;
            }
            else{
                t1 = p1 + (k+1)/2;
                t2 = p2 + (k+1)/2;
            }
            
            if(arr1[t1]<arr2[t2]){
                k = k - (t1 - p1);
                p1 = t1;  
            } 
            else{
                k = k - (t2 - p2);
                p2 = t2;
            }
            
        }
        
      //   cout << p1 << " " << p2 << endl;
        
        if(p1+p2+2 != kt){
            if(p1==n-1) p2 = kt-n-1;
            if(p2==m-1) p1 = kt-m-1;
        }
        
      //   cout << p1 << " " << p2 << endl;
        
        if(p1<0) return arr2[p2];
        if(p2<0) return arr1[p1];
        
        return max(arr1[p1], arr2[p2]);
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends

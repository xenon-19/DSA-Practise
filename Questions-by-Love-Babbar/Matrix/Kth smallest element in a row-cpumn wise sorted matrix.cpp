// Question
// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#
// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

//------Code------ //-------finding-num-with-k-nos-smaller-than-it
// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends


int kthSmallest(int matrix[MAX][MAX], int n, int k){
    int minn = INT_MAX, maxx = INT_MIN;
    for(int i=0; i<n; i++){
        minn = min(minn, matrix[i][0]);
        maxx = max(maxx, matrix[i][n-1]);
    }
    
    int mid = (minn + maxx)/2;
    
    int low_cnt;
    while(minn < maxx){
        low_cnt = 0;
        for(int i=0; i<n; i++){
            low_cnt += upper_bound(matrix[i], matrix[i]+n, mid) - matrix[i];
        }
        if(low_cnt < k) minn = mid + 1;
        else maxx = mid;
        mid = (minn + maxx)/2;
    }

    return mid;
}

//------------Code---------min-heap
// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

struct node{
    int num;
    int row;
    int col;
};

void Heapify(node* arr, int n, int i){
    node temp;
    int left = 2*i+1, right = 2*i+2, return_val = 0, to_swap = i;
    if(left < n && arr[left].num < arr[to_swap].num) to_swap = left;
    if(right < n && arr[right].num < arr[to_swap].num) to_swap = right;
    
    temp = arr[i];
    arr[i] = arr[to_swap];
    arr[to_swap] = temp;
    
    if(to_swap != i) Heapify(arr, n, to_swap);
}

int kthSmallest(int mat[MAX][MAX], int n, int k){
    node hp[n];
    int ans;
    for(int i=0; i<n; i++){
        hp[i].num = mat[0][i];
        hp[i].row = 0;
        hp[i].col = i;
    }
    while(k--){
        n = sizeof(hp)/sizeof(node);
        ans = hp[0].num;
        if(hp[0].row == n-1){
            hp[0].num = INT_MAX;
        }
        else{
            hp[0].num = mat[++hp[0].row][hp[0].col];
        }
        Heapify(hp, n, 0);
    }
    return ans;
}

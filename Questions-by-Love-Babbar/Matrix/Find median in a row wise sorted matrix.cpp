// Question
// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

//-------Code--------
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int minn = INT_MAX, maxx = INT_MIN;
        for(int i=0; i<r; i++){
            minn = min(minn, matrix[i][0]);
            maxx = max(maxx, matrix[i][c-1]);
        }
        
        int mid = (minn + maxx)/2;
        
        int low_cnt;
        while(minn < maxx){
            low_cnt = 0;
            for(int i=0; i<r; i++){
                low_cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(low_cnt < (c*r)/2 + 1) minn = mid + 1;
            else maxx = mid;
            mid = (minn + maxx)/2;
        }

        return mid;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends

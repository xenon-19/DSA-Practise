// Question
// Given a matrix of size r*c. Traverse the matrix in spiral form.
//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

//------Code--------
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int row_upper = 0, row_lower = r-1, col_left = 0, col_right = c-1;
        //dirn: 1=right, 2=down, 3=left, 0=up
        int dirn = 1, i=0, j=0;
        while(i>=row_upper && i<=row_lower && j<=col_right && j>=col_left){
            ans.push_back(matrix[i][j]);
            //cout << matrix[i][j] << " ";
            if(dirn==1){
                if(i==row_upper && j==col_right){
                    dirn = (dirn+1)%4;
                    i++;
                    row_upper++;
                }else j++;
            }else if(dirn==2){
                if(i==row_lower && j==col_right){
                    dirn = (dirn+1)%4;
                    j--;
                    col_right--;
                }else i++;
            }else if(dirn==3){
                if(i==row_lower && j==col_left){
                    dirn = (dirn+1)%4;
                    i--;
                    row_lower--;
                }else j--;
            }else{
                if(i==row_upper && j==col_left){
                    dirn = (dirn+1)%4;
                    col_left++;
                    j++;
                }else i--;
            }
        }
        //cout << endl;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

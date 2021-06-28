// Question
// https://practice.geeksforgeeks.org/problems/max-rectangle/1
// Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.
  
//-------Code----------
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxAreaHistogram(int *arr, int n){
        int max_area = 0;
        stack<int> stk;
        int tp;
        
        int i=0;
        while(i < n){
            if(stk.empty() || arr[i] > arr[stk.top()]){
                stk.push(i++);
            }else if(arr[i] == arr[stk.top()]){
                stk.pop();
            }else{
                tp = stk.top();
                stk.pop();
                max_area = max(max_area, arr[tp]*(stk.empty() ? i : i - stk.top() - 1));
            }
        }
        
        while(!stk.empty()){
            tp = stk.top();
            stk.pop();
            max_area = max(max_area, arr[tp]*(stk.empty() ? i : i - stk.top() - 1));
        }
        return max_area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int max_area = maxAreaHistogram(M[0], m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]){
                    M[i][j] += M[i-1][j];
                }
            }
            max_area = max(max_area, maxAreaHistogram(&M[i][0], m));
        }
        
        return max_area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends

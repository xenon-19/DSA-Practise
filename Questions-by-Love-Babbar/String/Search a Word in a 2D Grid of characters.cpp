// Question
// Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid.
// A word can be matched in all 8 directions at any point. 
// Word is said be found in a direction if all characters match in this direction (not in zig-zag form). 
// The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1#

//-------Code-------
//-----O(n*m*k)-----

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool starts_here(vector<vector<char>> &grid, string &word, int i, int j){
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> to_add = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        for(int dirn=0; dirn<8; dirn++){
           int x=0;
           for(; x<word.size(); x++){
               int tx = i+x*to_add[dirn][0];
               int ty = j+x*to_add[dirn][1];
               if(tx<0||tx>=n||ty<0||ty>=m){
                   break;
               }
               if(word[x] != grid[tx][ty]){
                   break;
               }
           }
           if(x==word.size()){
               return true;
           }
        }
        return false;
        }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        vector<vector<int>> list;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(starts_here(grid, word, i, j)){
                    list.push_back({i,j});
                }
            }
        }
        return list;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends

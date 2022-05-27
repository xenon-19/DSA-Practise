// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#

//---------------Code------------------
//--------------O(n*m),O(n*m)----------

vector<vector<int>> get_neighbors(int x, int y, vector<vector<char>> &grid){
    vector<vector<int>> ret;
    int n=grid.size();
    if(n == 0) return {};
    int m=grid[0].size();
    
    if(x+1<n and x+1>=0 and y<m and y>=0 and grid[x][y]=='1') ret.push_back({x+1, y});
    if(x+1<n and x+1>=0 and y+1<m and y+1>=0 and grid[x][y]=='1') ret.push_back({x+1, y+1});
    if(x+1<n and x+1>=0 and y-1<m and y-1>=0 and grid[x][y]=='1') ret.push_back({x+1, y-1});
    if(x<n and x>=0 and y+1<m and y+1>=0 and grid[x][y]=='1') ret.push_back({x, y+1});
    if(x<n and x>=0 and y-1<m and y-1>=0 and grid[x][y]=='1') ret.push_back({x, y-1});
    if(x-1<n and x-1>=0 and y<m and y>=0 and grid[x][y]=='1') ret.push_back({x-1, y});
    if(x-1<n and x-1>=0 and y-1<m and y-1>=0 and grid[x][y]=='1') ret.push_back({x-1, y-1});
    if(x-1<n and x-1>=0 and y+1<m and y+1>=0 and grid[x][y]=='1') ret.push_back({x-1, y+1});
    
    return ret;
    
}

void visit(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid){
    queue<vector<int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    
    while(!q.empty()){
        vector<int> front = q.front();
        q.pop();
        for(auto neighbor: get_neighbors(front[0], front[1], grid)){
            if(!vis[neighbor[0]][neighbor[1]]){
                q.push(neighbor);
                vis[neighbor[0]][neighbor[1]] = 1;
            }
        }
    }
}

// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    if(n==0) return 0;
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int> (m));
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] and grid[i][j]=='1'){
                visit(i, j, vis, grid);
                cnt++;
            }
        }
    }
    return cnt;
}

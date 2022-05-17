// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

//--------------Code----------------
//-------O((3*n**2),O(3n**2)--------

bool check_valid(int x, int y, int n, vector<vector<int>> &m){
    if(x<0 or x>=n){
        return false;
    }
    if(y<0 or y>=n){
        return false;
    } 
    if(m[x][y] == 0){
        return false;
    }
    return true;
}
    
void dfs(int x, int y, int n, vector<string> &ans, vector<vector<int>> &m, string path){
    if(x==n-1 and y==n-1){
        ans.push_back(path);
    }
    else{
        int to_flip=0;
        if(m[x][y]) to_flip=1;
        m[x][y] = 0;
        if(check_valid(x, y+1, n, m)){
            dfs(x, y+1, n, ans, m, path+'R');
        }
        if(check_valid(x, y-1, n, m)){
            dfs(x, y-1, n, ans, m, path+'L');
        }
        if(check_valid(x+1, y, n, m)){
            dfs(x+1, y, n, ans, m, path+'D');
        }
        if(check_valid(x-1, y, n, m)){
            dfs(x-1, y, n, ans, m, path+'U');
        }
        if(to_flip) m[x][y] = 1;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    if(m[0][0]==0 or m[n-1][n-1]==0){
        return ans;
    }
    dfs(0, 0, n, ans, m, "");
    return ans;
}

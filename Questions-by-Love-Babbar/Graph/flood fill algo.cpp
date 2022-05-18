// https://leetcode.com/problems/flood-fill/

//----------Code--------------
//--------O(n*m),O(n*m)-------

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int origColor = image[sr][sc];
        if(newColor == origColor) return image;
        
        int n = image.size(), m=image[0].size();
        
        vector<vector<int>> steps = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<vector<int>> q;
        q.push({sr, sc});
        vis[sr][sc]=1;
        
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            image[temp[0]][temp[1]] = newColor;
            for(auto step: steps){
                vector<int> ttemp = {temp[0]+step[0], temp[1]+step[1]};
                if(ttemp[0]>=0 and ttemp[0]<n and ttemp[1]>=0 and ttemp[1]<m and !vis[ttemp[0]][ttemp[1]] and image[ttemp[0]][ttemp[1]]==origColor){
                    q.push(ttemp);
                    vis[ttemp[0]][ttemp[1]]=1;
                }
            }
        }
                                                                                                                    
        return image;
    }
};

//https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/

//-------------------Code------------------
//----------------O(v+e),O(v)----------------

class Solution {
public:
    void visit_component(vector<int> &vis, vector<vector<int>> &adjacency_list, int node){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(auto x: adjacency_list[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> vis(n);
        int cnt=0;
        
        vector<vector<int>> adjacency_list(n);
        
        for(auto x: connections){
            adjacency_list[x[0]].push_back(x[1]);            
            adjacency_list[x[1]].push_back(x[0]);
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                visit_component(vis, adjacency_list, i);
                cnt++;
            }
        }
        //cout << "no. of components " << cnt << endl;
        cnt--;
        return cnt;
    }
};

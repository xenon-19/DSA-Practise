// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

//-------------------------Code-----------------------------
//---------------------O(ElogE),O(E)------------------------
int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> to_visit;
        
        int ans=0;
        to_visit.push({0, 0});
        
        int cnt=0;
        while(cnt<V and !to_visit.empty()){
            vector<int> top = to_visit.top();
            to_visit.pop();
            if(!vis[top[1]]){
                vis[top[1]] = 1;
                cnt++;
                ans+=top[0];
                //cout << "visited "  << top[1] << endl;
                for(auto x: adj[top[1]]){
                    to_visit.push({x[1], x[0]});
                }
            }
        }
        
        return ans;
    }

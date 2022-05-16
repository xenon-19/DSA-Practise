// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//-----------------Code-----------------
//-----------------O(n), O(n)-----------
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> vis(V);
        vector<int> ans;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto x: adj[temp]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        return ans;
    }

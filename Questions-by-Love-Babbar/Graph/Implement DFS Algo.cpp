// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#

//-------------------Code----------------------
//-----------------O(v+e),O(v)-----------------
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V);
        stack<int> stk;
        
        stk.push(0);
        
        while(!stk.empty()){
            int temp=stk.top();
            stk.pop();
            if(!vis[temp]) ans.push_back(temp);
            vis[temp]=1;
            for(int i=adj[temp].size()-1; i>=0; i--){
                if(!vis[adj[temp][i]]){
                    stk.push(adj[temp][i]);
                }
            }
        }
        return ans;
    }

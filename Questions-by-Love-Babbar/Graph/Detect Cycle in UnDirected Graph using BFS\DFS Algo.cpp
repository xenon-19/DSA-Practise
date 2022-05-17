// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//--------------Code-----------------
//-------------O(v+e),O(v)-----------

bool check(int node, vector<int> vis, vector<int> adj[], int parent){
    if(vis[node]) return true;
    vis[node]=1;
    for(auto x: adj[node]){
        if(x!=parent and check(x, vis, adj, node)) return true;
    }

    return false;
}
    
bool isCycle(int V, vector<int> adj[]) {
   vector<int> vis(V);
   for(int i=0; i<V; i++){
       if(!vis[i] and check(i, vis, adj, -1)) return true;
   }
   return false;
}

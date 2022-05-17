// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

//-----------------------Code-----------------------
//---------------------O(v+e),O(v)------------------
bool check(int node, vector<int> adj[], vector<int> &vis, vector<int> &checked){
      if(vis[node]==1) return true;

      vis[node] = 1;

      for(auto x: adj[node]){
          if(!checked[x] and check(x, adj, vis, checked)) return true;
      }

      checked[node] = 1;
      vis[node]=0;
      return false;
  }
    
    
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> checked(V);
    vector<int> vis(V);

    for(int i=0; i<V; i++){
        if(!checked[i]){
            if(check(i, adj, vis, checked)){
                return true;
            }
        }
    }

    return false;
}

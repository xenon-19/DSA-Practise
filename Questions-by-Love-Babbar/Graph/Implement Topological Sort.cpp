// https://practice.geeksforgeeks.org/problems/topological-sort/1

//-----------------Code---------------------
//---------------O(V+E),O(V)----------------

void print_topo(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans){
	    vis[node] = 1;
	    for(auto x: adj[node]){
	        if(!vis[x]) print_topo(x, adj, vis, ans);
	    }
	    ans.push_back(node);
	}
	
vector<int> topoSort(int V, vector<int> adj[]) {
      vector<int> vis(V);
      vector<int> ans;
      for(int i=0; i<V; i++){
          if(!vis[i]) print_topo(i, adj, vis, ans);
      }
      reverse(ans.begin(), ans.end());
      return ans;
}

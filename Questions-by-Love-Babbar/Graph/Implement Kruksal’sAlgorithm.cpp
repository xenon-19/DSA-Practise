// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//-------------------Code-----------------
//------------------O(ElogE),O(E)---------
bool is_cycle(int e1, int e2, vector<int> &par, vector<int> &rank){
	        int n1 = e1;
	        while(par[n1] != n1){
	            n1 = par[n1];
	        }
	        par[e1] = n1; //path compression
	        
	        int n2 = e2;
	        while(par[n2]!=n2){
	            n2 = par[n2];
	        }
	        par[e2] = n2;
	        
	        if(rank[n1] <= rank[n2]) par[n1] = n2;
	        else par[n2] = n1;
	        
	        if(n1 == n2) return true;
	        return false;
	}

	
    int spanningTree(int V, vector<vector<int>> adj[]){
        int ans=0;
    
        vector<vector<int>> edges;
        for(int i=0; i<V; i++){
            for(auto x: adj[i]){
                edges.push_back({x[1], i, x[0]});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        vector<int> par(V);
        vector<int> rank(V, 1);
        
        for(int i=0; i<V; i++) par[i] = i;
        
        int cnt=0;
        for(int i=0; i<edges.size(); i++){
            if(cnt>V) break;
            if(!is_cycle(edges[i][1], edges[i][2], par, rank)){
                ans += edges[i][0];
                cnt ++;
            }
        }
        
        return ans;
    }

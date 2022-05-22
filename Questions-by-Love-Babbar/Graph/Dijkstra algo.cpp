// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/#


//----------------Code---------------

//-----------Using heap---------------
//-----------O(ElogV),O(V)------------
  int heapify(int idx, vector<vector<int>> &heap, vector<int> &pos){
        int n = pos.size(), left = 2*idx+1, right = 2*idx+2;
        
        if(left>=n) left = idx;
        if(right>=n) right = idx;
        
        int minn = idx;
        if(heap[left][0] < heap[minn][0]) minn = left;
        if(heap[right][0] < heap[minn][0]) minn = right;
        
        if(minn == idx) return 1;

        pos[heap[idx][1]] =  minn;
        pos[heap[minn][1]] = idx;
        vector<int> temp = heap[idx];
        heap[idx] = heap[minn];
        heap[minn] = temp;
        heapify(minn, heap, pos);
        return 0;
    }
    
    int extract_min(vector<vector<int>> &heap, vector<int> &pos){
        int ret = heap[0][1];
        heap[0][0] = INT_MAX;
        heapify(0, heap, pos);
        return ret;
    }
    
    int update_heap(int idx, vector<vector<int>> &heap, vector<int> &pos){
        int par = (idx-1)/2;
        while(par>=0){
            if(heapify(par, heap, pos) == 1) break;
            par = (par-1)/2;
        }
        return 0;
    }
    
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        vector<int> pos(V);
        for(int i=0; i<V; i++) pos[i] = i;
        
        vector<vector<int>> heap(V, vector<int>(2));
        for(int i=0; i<V; i++){
            heap[i][0] = dist[i];
            heap[i][1] = i;
        }
        
        update_heap(pos[S], heap, pos);
        
        vector<int> incl(V);
        for(int i=0; i<V; i++){
            int mn = extract_min(heap, pos);            
            incl[mn] = 1;
            for(auto x: adj[mn]){

                if(!incl[x[0]] and dist[x[0]] > dist[mn]+x[1]){
                    dist[x[0]] = dist[mn]+x[1];
                    heap[pos[x[0]]][0] = dist[mn]+x[1];
                    update_heap(pos[x[0]], heap, pos);
                }
            }
        }
        return dist;
    }




//---------------naive, linear for finding minimum-------------------
//---------------O(V*V),O(V)-----------------------------------------

  int find_min(vector<int> &dist, vector<int> &incl){
        int md = INT_MAX, mdi = -1;
        for(int i=0; i<dist.size();  i++){
            if(!incl[i] and dist[i]<md){
                md = dist[i];
                mdi = i;
            }
        }
        return mdi;
    }
    
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        vector<int> incl(V);
        for(int i=0; i<V; i++){
            int mn = find_min(dist, incl);
            //cout << "minimum vertex here is " << mn << endl;
            incl[mn] = 1;
            for(auto x: adj[mn]){
                if(!incl[x[0]] and dist[x[0]] > dist[mn]+x[1]){
                    dist[x[0]] = dist[mn]+x[1];
                    //cout << "dist upated to " << dist[x[0]] << endl;
                }
            }
        }
        
        return dist;
        
    }

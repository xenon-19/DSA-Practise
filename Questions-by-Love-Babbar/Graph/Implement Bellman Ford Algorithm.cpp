// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

//-------------------------Code------------------------
//---------------------O(v*loge),O(v)------------------
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<long long> dist(n, INT_MAX);

    //taking 0 as src node
    //will calculate dist of all nodes from 0 (reachable from 0)
    //will detect -ve cycle none the less (even if cycle is unreachable form 0)
    dist[0] = 0;

    for(int i=0; i<n-1; i++){
        for(auto edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            if(dist[v]>dist[u]+w) dist[v]=dist[u]+w;
        }
    }

    for(auto edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            if(dist[v]>dist[u]+w) return 1;
        }

    return 0;
}

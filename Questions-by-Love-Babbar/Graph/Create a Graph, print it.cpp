// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?leftPanelTab=1

//--------------------Code--------------------
vector< vector< int > > printAdjacency(int n, int m, vector< vector< int > > &edges) {
    vector<vector<int>> graph(n, vector< int >());
	for(int i=0; i<n; i++){
		graph[i].push_back(i);
	}
	
	for(int i=0; i<m; i++){
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}
	
	return graph;
}

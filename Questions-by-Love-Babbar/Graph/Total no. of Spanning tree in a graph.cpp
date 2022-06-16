// https://www.geeksforgeeks.org/total-number-spanning-trees-graph/
// https://www.codingninjas.com/codestudio/problems/total-number-of-spanning-trees-in-a-graph_1171196?leftPanelTab=1

//------------------Code-------------------
//--------------O(n*n),O(n*n)--------------

int determinant(int, vector<vector<int>>&);
int cofactor(int, int, int, vector<vector<int>>&);

int cofactor(int x, int y, int n, vector<vector<int>> &matrix){
    vector<vector<int>> comat(n-1, vector<int> (n-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<x and j<y) comat[i][j] = matrix[i][j];
            if(i>x and j<y) comat[i-1][j] = matrix[i][j];
            if(i<x and j>y) comat[i][j-1] = matrix[i][j];
            if(i>x and j>y) comat[i-1][j-1] = matrix[i][j];
        }
    }
    
    if((x+y)%2){
        return -1*determinant(n-1, comat);
    }else{
        return determinant(n-1, comat);
    }
}

int determinant(int n, vector<vector<int>> &matrix){
    if(n==0) return 0;
    if(n==1) return matrix[0][0];
    
    int ret=0;
    for(int i=0; i<n; i++){
        ret += matrix[0][i]*cofactor(0, i, n, matrix);
    }
    return ret;
}

int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m){
	vector<int> degree(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adjMatrix[i][j]==1){
                degree[i]++;
                adjMatrix[i][j]=-1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        adjMatrix[i][i] = degree[i];
    }
    return cofactor(0, 0, n, adjMatrix);
}

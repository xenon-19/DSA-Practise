// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

//------------------------Code-----------------------
//-------------------O(v+e),O(v)---------------------
//-------------------O(n*n),O(n*n)-------------------

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    vector<vector<int>> vis(N+1, vector<int> (N+1));
	    vector<vector<int>> steps = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
	    queue<vector<int>> q;
	    q.push({KnightPos[0], KnightPos[1], 0});
	    vis[KnightPos[0]][KnightPos[1]] = 1;
	    while(!q.empty()){
	        vector<int> t_pos = q.front();
	        q.pop();
	        if(t_pos[0]==TargetPos[0] and t_pos[1]==TargetPos[1]) return t_pos[2];
	        vector<int> n_pos = t_pos;
	        for(auto step: steps){
	            n_pos = {t_pos[0]+step[0], t_pos[1]+step[1], t_pos[2]+1};
	            if((n_pos[0]>0) and (n_pos[0]<=N) and (n_pos[1]>0) and (n_pos[1]<=N) and !vis[n_pos[0]][n_pos[1]]){
                    vis[n_pos[0]][n_pos[1]] = 1;
                    q.push(n_pos);	                
	            }
	        }
	    }
	    return -1;
	}

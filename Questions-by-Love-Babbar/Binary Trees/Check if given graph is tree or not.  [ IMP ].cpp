// https://www.lintcode.com/problem/178/

//----------------Code-----------------
bool validTree(int n, vector<vector<int>> &edges) {
        if(n==0) return 1;
        if(n==1) return 1;
        if(edges.size() != n-1){
            cout << "edges != n-1" << endl;
            return 0;
        }

        unordered_map<int, unordered_set<int>> t;
        for(int i=0; i<n-1; i++){
            t[edges[i][0]].insert(edges[i][1]);
            t[edges[i][1]].insert(edges[i][0]);
        }

        vector<int> vis(n);
        stack<int> stk;

        stk.push(0);
        int cnt=0;

        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();
            if(vis[curr]){
                cout << "Loop" << endl;
                return 0;
            }
            vis[curr] = 1;
            cnt++;

            //if(t.find(curr) == t.end()) continue;
            for(auto x: t[curr]){
                stk.push(x);
                t[x].erase(curr);
            }
        }

        if(cnt != n){
            cout << " cnt != n" << endl;
            cout << cnt << endl;
            // for(int i=0; i<n; i++){
            //     if(vis[i] == 0) cout << i << " ";
            // } cout << endl;
            // cout << "------------------------" << endl;
            for(int i=0; i<n; i++){
                if(vis[i] == 1) cout << i << " ";
            } cout << endl;
            return 0;
        }

        return 1;
    }

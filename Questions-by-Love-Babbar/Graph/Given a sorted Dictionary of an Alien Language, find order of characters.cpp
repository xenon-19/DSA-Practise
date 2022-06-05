// https://practice.geeksforgeeks.org/problems/alien-dictionary/1#

//---------------Code----------------
//-------------O(n*l),O(n)-------------
vector<char> find_order(string w1, string w2){
        int n = min(w1.size(), w2.size());
        for(int i=0; i<n; i++){
            if(w1[i] != w2[i]){
                return {w1[i], w2[i]};
            }
        }
        return {'!', '!'};
    }
    
void visit(map<char, set<char>> &tree, vector<char> &ans, vector<int> &vis, char node){
    vis[node-'a'] = 1;
    for(auto x: tree[node]){
        if(!vis[x-'a']) visit(tree, ans, vis, x);
    }
    //cout << "inserting char " << node << endl;
    ans.push_back(node);
}

string findOrder(string dict[], int N, int K) {
    map<char, set<char>> tree;

    for(int i=0; i<N-1; i++){
        vector<char> x = find_order(dict[i], dict[i+1]);
        if(x[0] != '!') tree[x[0]].insert(x[1]);
    }

    vector<char> ans;
    vector<int> vis(K);

    for(int i=0; i<K; i++){
        if(!vis[i]){
            visit(tree, ans, vis, char(i+'a'));
        }
    }

    //for(int i=0; i<ans.size(); i++) cout << ans[i];
    //cout << endl;

    reverse(ans.begin(), ans.end());

    string ret;
    for(auto x: ans) ret += x;
    //cout << ret << endl;

    return ret;
}

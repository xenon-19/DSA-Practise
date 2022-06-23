// https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
// https://practice.geeksforgeeks.org/problems/travelling-salesman-problem2732/1#

//----------------Code---------------
//---------------O(n*n*2^n)----------
int check_in_map(int i, set<int> &s, map<string, int> &mp){
    string w;
    w = to_string(i);
    for(auto x: s){
        w += to_string(x);
    }
    if(mp.find(w) != mp.end()) return mp[w];
    return -1;
}

bool insert_in_map(int i, set<int> s, map<string, int> &mp, int val){
    string str;
    str = to_string(i);
    for(auto x: s){
        str += to_string(x);
    }
    
    mp.insert({str, val});
}

int solve(int start, set<int> &s, vector<vector<int>> &cost, map<string, int> &mp){
    int ret=INT_MAX;
    if(s.size()==0){
        ret = cost[start][0];
        insert_in_map(start, s, mp, ret);
        return ret;
    }
    
    if(check_in_map(start, s, mp)!=-1){
        return check_in_map(start, s, mp);
    }
    
    set<int> ts = s; 
    for(auto x: ts){
        s.erase(x);
        ret = min(ret, cost[start][x]+solve(x, s, cost, mp));
        s.insert(x);
    }
    
    insert_in_map(start, s, mp, ret);
    return ret;
}

//main function
int total_cost(vector<vector<int>>cost){
    int ans=0;
    map<string, int> mp;
    set<int> s;
    for(int i=1; i<cost.size(); i++) s.insert(i);
    
    ans = solve(0, s, cost, mp);
    
    return ans;
}

// https://leetcode.com/problems/word-ladder/submissions/

//---------------Code------------------
//------------O(m*m*n),O(m*m*n)--------
// m = letters in each word, n = no. of words

class Solution {
public:
    bool is_neighbor(string s1, string s2){
        if(s1.size()!=s2.size()) return false;
        
        int cnt=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) cnt++;
            if(cnt > 1) return false;
        }
        if(cnt==1) return true;
        return false;
    }
    
    int find_shortest_path(string beginWord, string endWord, unordered_map<string, vector<string>> &adjacencyList){
        queue<pair<string, int>> q;
        unordered_set<string> vis;
        
        q.push({beginWord, 0});
        vis.insert(beginWord);
        
        while(!q.empty()){
            pair<string, int> temp = q.front();
            q.pop();
            //cout << temp.first << " " << temp.second << endl;
            if(temp.first == endWord) return temp.second;
            for(auto x: adjacencyList[temp.first]){
                if(vis.find(x)==vis.end()){
                    vis.insert(x);
                    q.push({x, temp.second+1});
                }
            }
        }
        return -1; 
    }
    
    void make_tree(vector<string> &words, unordered_map<string, vector<string>> &adjacencyList){
        unordered_map<string, vector<string>> inter;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[0].size(); j++){
                string temp = "";
                for(int k=0; k<words[0].size(); k++){
                    if(k==j) temp += '*';
                    else temp += words[i][k];
                }
                if(inter.find(temp)!=inter.end()){
                    for(auto x: inter[temp]){
                        adjacencyList[x].push_back(words[i]);
                        adjacencyList[words[i]].push_back(x);
                    }
                }
                inter[temp].push_back(words[i]);
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adjacencyList;
        vector<string> words = wordList;
        words.push_back(beginWord);
        
        make_tree(words, adjacencyList);

        return find_shortest_path(beginWord, endWord, adjacencyList)+1;
    }
};

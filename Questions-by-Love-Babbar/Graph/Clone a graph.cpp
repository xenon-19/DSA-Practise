// https://leetcode.com/problems/clone-graph/

//-------Code---------
//------O(v+e),O(v)---

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL) return node;
        
        unordered_map<Node*, Node*> vis;
        queue<vector<Node*>> to_cpy;
        
        Node* ret = new Node();
        
        to_cpy.push({ret, node});
        vis[node] = ret;
        
        while(!to_cpy.empty()){
            vector<Node*> temp = to_cpy.front();
            to_cpy.pop();
            temp[0]->val = temp[1]->val;
            temp[0]->neighbors = temp[1]->neighbors;
            for(int i=0; i<temp[1]->neighbors.size(); i++){
                if(vis.find(temp[1]->neighbors[i]) == vis.end()){
                    temp[0]->neighbors[i] = new Node();
                    to_cpy.push({temp[0]->neighbors[i], temp[1]->neighbors[i]});
                    vis[temp[1]->neighbors[i]] = temp[0]->neighbors[i];
                }else{
                    temp[0]->neighbors[i] = vis[temp[1]->neighbors[i]];
                }
            }
        }
        
        return ret;
    }
};

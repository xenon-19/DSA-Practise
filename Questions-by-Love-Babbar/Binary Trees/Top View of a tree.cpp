// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#

//--------------O(n)---------------
vector<int> topView(Node *root){
        deque<int> ans;
        
        //* of node and its x value
        pair<Node*, int> cur = {root, 0};
        
        queue<pair<Node*, int>> q;
        q.push(cur);
        
        int minx=1, maxx=0;
        
        //level order traversal
        while(!q.empty()){
            cur = q.front();
            q.pop();
            
            //if x val less than min put in left side
            if(cur.second < minx){
                minx = cur.second;
                ans.push_front(cur.first->data);
            }
            //if x val more than max put on right side
            if(cur.second > maxx){
                maxx = cur.second;
                ans.push_back(cur.first->data);
            }
            if(cur.first->left) q.push({cur.first->left, cur.second-1});
            if(cur.first->right) q.push({cur.first->right, cur.second+1});
        }
        
        vector<int> ret(ans.begin(), ans.end());
        return ret;
    }

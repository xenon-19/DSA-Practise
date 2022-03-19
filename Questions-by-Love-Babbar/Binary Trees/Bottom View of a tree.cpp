// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//-----------------Code----------------

//function to find left most ans right most position
void find_width(Node* node, vector<int> &x, int pos){
        if(pos < x[0]){
            x[0] = pos;
        }
        if(pos > x[1]){
            x[1] = pos;
        }
        if(node->left) find_width(node->left, x, pos-1);
        if(node->right) find_width(node->right, x, pos+1);
    }

//create vector containing max width elements(no of nodes in bottom view), level order traversal to fill the vector
//retrun the vector
vector<int> bottomView(Node *root) {
        if(root==NULL) return {};
        
        vector<int> x = {INT_MAX, INT_MIN};
        find_width(root, x, 0);
        
        vector<int> ans(x[1]-x[0]+1);
        
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        pair<Node*, int> curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            ans[curr.second - x[0]] = curr.first->data;
            if(curr.first->left) q.push({curr.first->left, curr.second-1});
            if(curr.first->right) q.push({curr.first->right, curr.second+1});
        }
        
        return ans;
    }

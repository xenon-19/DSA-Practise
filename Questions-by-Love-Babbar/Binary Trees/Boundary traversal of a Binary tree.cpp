// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

//----------------Code-----------------
vector <int> boundary(Node *root){
        if(root==NULL) return {};
        
        vector<int> ans;
        ans.push_back(root->data);
        
        if(!root->left and !root->right){
            return ans;
        }
        
        //left boundary
        Node* node=root->left;
        while(node){
            ans.push_back(node->data);
            if(node->left) node=node->left;
            else node=node->right;
        }
        if(root->left) ans.pop_back(); //removing leaf node
        
        //leaf nodes, using dfs
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            node = stk.top();
            stk.pop();
            if(!(node->left) and !(node->right)){
                //cout << node->data << endl;
                ans.push_back(node->data);
                continue;
            }
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        
        //right boundary
        node=root->right;
        while(node){
            stk.push(node);
            if(node->right) node=node->right;
            else node=node->left;
        }
        if(root->right) stk.pop(); // remove the leaf node
        
        while(!stk.empty()){
            node=stk.top();
            stk.pop();
            ans.push_back(node->data);
        }
        
        return ans;
    }

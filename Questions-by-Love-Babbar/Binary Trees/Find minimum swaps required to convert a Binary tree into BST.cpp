// https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/#:~:text=Given%20the%20array%20representation%20of,it%20into%20Binary%20Search%20Tree.&text=Swap%201%3A%20Swap%20node%208,node%209%20with%20node%2010.
// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

//---------------Code--------------
void find_inorder(vector<Node*> &v, Node* root){
        if(!root) return;
        if(root->left) find_inorder(v, root->left);
        v.push_back(root);
        if(root->right) find_inorder(v, root->right);
    }
    
Node* binaryTreeToBST (Node *root){
        vector<Node*> inorder_nodes;
        
        find_inorder(inorder_nodes, root);
        
        int n = inorder_nodes.size();
        
        vector<int> values(inorder_nodes.size());
        
        for(int i=0; i<inorder_nodes.size(); i++){
            values[i] = inorder_nodes[i]->data;
        }
        sort(values.begin(), values.end());
        
        unordered_map<int, int> mp;
        for(int i=0; i<inorder_nodes.size(); i++){
            mp.insert({values[i], i});
        }
        
        long long cnt=0;
        for(int i=0; i<inorder_nodes.size(); i++){
            while(mp[inorder_nodes[i]->data]!=i){
                int tmp = inorder_nodes[i]->data;
                inorder_nodes[i]->data = inorder_nodes[mp[tmp]]->data;
                inorder_nodes[mp[tmp]]->data = tmp;
                cnt++;
            }
        }
        
        return root;
        
    }

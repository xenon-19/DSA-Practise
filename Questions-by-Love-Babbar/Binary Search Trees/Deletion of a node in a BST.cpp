// https://leetcode.com/problems/delete-node-in-a-bst/submissions/

//-------------------------Code--------------------------
//this function takes the root of a bst subtree, and deletes ite root, returns the pointer of the new root
TreeNode* del(TreeNode* node){
        if(node->left == NULL and node->right == NULL) return NULL;
        
        if(node->left and node->right == NULL) return node->left;
        if(node->right and node->left==NULL) return node->right;
         
        if(node->left and node->right){
          
          //finding smallest node on right along with its parent
            TreeNode *smallest_node = node->right, *parent = node;
            while(smallest_node->left){
                parent = smallest_node;
                smallest_node = smallest_node->left;
            }
            
          //copy value of smallest in root, and delete the smallest node
            node->val = smallest_node->val;
            if(parent == node){
                parent->right = del(smallest_node);
            }else{
                parent->left = del(smallest_node);
            }
            return node;
    
        }
        return node;
}

//main function
TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        
        if(root->val == key) return del(root);
        
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
}

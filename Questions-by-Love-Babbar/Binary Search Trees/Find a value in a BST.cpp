// https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/

//-----------------------Code------------------------
TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        
        if(val<root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }

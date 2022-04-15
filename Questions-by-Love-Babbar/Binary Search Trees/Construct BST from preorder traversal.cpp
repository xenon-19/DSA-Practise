// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

//--------------------Code--------------------
TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        TreeNode* tp;
        
        for(int i=1; i<preorder.size(); i++){
            if(preorder[i] < stk.top()->val){
                stk.top()->left = new TreeNode(preorder[i]);
                stk.push(stk.top()->left);
            }else{
                while(!stk.empty() and stk.top()->val < preorder[i]){
                    tp = stk.top();
                    stk.pop();
                }
                tp->right = new TreeNode(preorder[i]);
                stk.push(tp->right);
            }
        }
        return root;
    }

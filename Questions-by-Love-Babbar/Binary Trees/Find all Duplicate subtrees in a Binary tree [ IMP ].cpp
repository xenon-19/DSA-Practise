// https://leetcode.com/problems/find-duplicate-subtrees/submissions/

//--------------Code-----------------
string rec(TreeNode* node, unordered_set<string> &st, unordered_set<string> &done, vector<TreeNode*> &ans){
        if(node==NULL) return "`";

        string ret = to_string(node->val) + "_";

        ret += rec(node->left, st, done, ans);
        ret += rec(node->right, st, done, ans);


        if(st.find(ret) != st.end()){
            if(done.find(ret) == done.end()){
                ans.push_back(node);
                done.insert(ret);
            }
        }

        st.insert(ret);

        return ret;
    }
    
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_set<string> st;
        vector<TreeNode*> ans;
        unordered_set<string> done;
        rec(root, st, done, ans);

        return ans;
}

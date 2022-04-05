// https://www.codingninjas.com/codestudio/problems/largest-sub-tree-sum_920400?leftPanelTab=1

//----------------Code----------------
ll rec(TreeNode<int> *node, ll &ans){
    ll l=-1*1000000000, r=-1*1000000000;
    ll s = node->data;
    if(node->left){
        l = rec(node->left, ans);
        s += l;
    }
    if(node->right){
        r = rec(node->right, ans);
        s += r;
    }
    
    ans = max(ans, s);
    return s;
}

int largestSubtreeSum(TreeNode<int> *root) {
    if(root == NULL) return 0;
    ll ans = -1*1000000000;
	rec(root, ans);
    return ans;
}

// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#

//--------------------Code---------------------
int rec(Node* node, int k, int& ans, int cnt_smaller){
        if(node==NULL) return 0;
        
        int l_ele, r_ele;
        l_ele = rec(node->left, k, ans, cnt_smaller);
        cnt_smaller += l_ele;
        
        if(cnt_smaller == k-1) ans = node->data;
        if(cnt_smaller >= k) return k+1;
        
        r_ele = rec(node->right, k, ans, cnt_smaller+1);
        return l_ele + r_ele + 1;
    }

int KthSmallestElement(Node* root, int k) {
    if(root==NULL) return -1;
    int ans=-1;
    rec(root, k, ans, 0);
    return ans;
}

// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#

//-----------------------------Code------------------------------
int rec(Node* node, int k, int &ans, int cnt_greater){
        if(node==NULL) return 0;
        
        int r_ele, l_ele;
        r_ele = rec(node->right, k, ans, cnt_greater);
        
        cnt_greater += r_ele;
        
        if(cnt_greater == k-1) ans = node->data;
        if(cnt_greater >= k) return k;
        
        l_ele = rec(node->left, k, ans, cnt_greater+1);
        
        return r_ele+l_ele+1;
        
        
    }
    
int kthLargest(Node *root, int k){
    int ans = 0;
    rec(root, k, ans, 0);
    return ans;
}

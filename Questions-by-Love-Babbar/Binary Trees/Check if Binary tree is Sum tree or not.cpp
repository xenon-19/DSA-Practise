//https://practice.geeksforgeeks.org/problems/sum-tree/1#

//------------------Code--------------------
vector<ll> rec(Node* node){
    
    vector<ll> l, r, ret;
    ret = {1, 0};
    
    if(node->left==NULL and node->right==NULL){
        return {1, node->data};
    }
    
    if(node->left){
        l = rec(node->left);
        ret[0] = ret[0]&l[0];
        ret[1] += l[1];
    }
    if(node->right){
        r = rec(node->right);
        ret[0] = ret[0]&r[0];
        ret[1] += r[1];
    } 
    
    ret[0] &= (node->data == ret[1]);
    ret[1] += node->data;
    
    return ret;
}

class Solution{
    public:
    bool isSumTree(Node* root){
         if(root == NULL) return true;
         vector<ll> ans = rec(root);
         return ans[0];
    }
};

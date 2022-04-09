// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/#

//-------------------Code------------------
int rec(Node* node, int k, int n, vector<int> &path){
    if(node==NULL) return -1;
    
    path.push_back(node->data);
    
    if(node->data == n){
        if(path.size() > k){
            path.pop_back();
            return path[path.size()-k];
        }else{
            path.pop_back();
            return -1;
        }
    }else{
        int l=rec(node->left, k, n, path), r=rec(node->right, k, n, path);
        path.pop_back();
        return max(l, r);
    }
}

int kthAncestor(Node *root, int k, int node){
    vector<int> path;
    if(root==NULL) return -1;
    return rec(root, k, node, path);
}

// https://www.codingninjas.com/codestudio/problems/k-sum-path-in-a-binary-tree_893543?leftPanelTab=1


//------------------------Code----------------------
void rec(BinaryTreeNode<int>* node, int k, vector<int> &path, vector<vector<int>> &ans){
    path.push_back(node->data); 
    
    if(node->left) rec(node->left, k, path, ans);
    if(node->right) rec(node->right, k, path, ans);
    
    int temp = 0, i;
    for(i=path.size()-1; i>=0; i--){
        temp += path[i];
        if(temp == k){
			vector<int> t_path(path.begin()+i, path.end());
			ans.push_back(t_path); 
        }
    }
// this can be done here as well    
//     if(node->left) rec(node->left, k, path, ans);
//     if(node->right) rec(node->right, k, path, ans);
    
    path.pop_back();
}

vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
	vector<int> path;
    vector<vector<int>> ans;
    if(root == NULL) return {{}};
    rec(root, k, path, ans);
    return ans;
}

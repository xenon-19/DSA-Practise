// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

//--------------Code---------------
void find_inorder(vector<Node*> &v, Node* root){
        if(!root) return;
        if(root->left) find_inorder(v, root->left);
        v.push_back(root);
        if(root->right) find_inorder(v, root->right);
    }
    
Node* binaryTreeToBST (Node *root){
    vector<Node*> inorder_nodes;
    find_inorder(inorder_nodes, root);

    int n = inorder_nodes.size();

    vector<int> values(inorder_nodes.size());
    for(int i=0; i<inorder_nodes.size(); i++) values[i] = inorder_nodes[i]->data;
    sort(values.begin(), values.end());

    for(int i=0; i<n; i++) inorder_nodes[i]->data = values[i];

    return root;

}

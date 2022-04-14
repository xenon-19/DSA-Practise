// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

//-------------Code---------------
Node* LCA(Node *root, int n1, int n2){
    if(root==NULL) return NULL;
    if(root->data>n1 and root->data>n2) return LCA(root->left, n1, n2);
    if(root->data<n1 and root->data<n2) return LCA(root->right, n1, n2);
    return root;
}

// https://practice.geeksforgeeks.org/problems/check-for-bst/1

//---------------------Code------------------------
bool rec(Node* node, int ma, int mi){
        if(node==NULL) return true;
        if(node->data >= ma || node->data <= mi) return false;
        else{
            return rec(node->left, node->data, mi)&rec(node->right, ma, node->data);
        }
    }
    
bool isBST(Node* root) {
    if(root == NULL) return true;
    return rec(root, INT_MAX, INT_MIN);
}

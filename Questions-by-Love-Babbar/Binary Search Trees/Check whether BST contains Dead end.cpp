// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

//--------------O(n)---------------
//----------------Code-------------
bool rec(Node* node, int max, int min){
    bool l, r;
    l = r = 0;
    if(max==min) return 1;
    if(node->left) l=rec(node->left, node->data-1, min);
    if(node->right) r=rec(node->right, max, node->data+1);
    
    return l|r;
}

bool isDeadEnd(Node *root){
    return rec(root, INT_MAX, 1);
}

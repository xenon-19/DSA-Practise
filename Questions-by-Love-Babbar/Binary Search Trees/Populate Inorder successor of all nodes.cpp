// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

//--------------Code--------------
Node* rec(Node* node, Node* greater){
        if(node==NULL) return NULL;
        
        Node* l_io = rec(node->left, node);
        Node* r_io = rec(node->right, greater);
        
        if(r_io) node->next = r_io;
        else{
            node->next = greater;
        }
        
        if(l_io) return l_io;
        return node;
    }
    
void populateNext(Node *root){
    rec(root, NULL);
}

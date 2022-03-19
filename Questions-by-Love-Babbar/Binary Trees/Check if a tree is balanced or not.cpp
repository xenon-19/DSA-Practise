// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

//-------------------Code-------------------
int findh(Node* node){
        if(node==NULL) return 0;
        int lh = findh(node->left);
        int rh = findh(node->right);
        
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return max(lh, rh) + 1;
    }
    
bool isBalanced(Node *root)
    {
        if(root == NULL) return true;
        if(findh(root) == -1) return false;
        return true;
    }

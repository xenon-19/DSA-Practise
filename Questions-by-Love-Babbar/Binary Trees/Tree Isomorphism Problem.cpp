// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#

//-------------------Code---------------------
bool isIsomorphic(Node *root1, Node *root2){
        if(root1==NULL && root2==NULL) return 1;
        if(root1==NULL || root2==NULL) return 0;
        if(root1->data != root2->data) return 0;
        
        if(isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right)){
            return 1;
        }
        if(isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left)){
            return 1;
        }
        return 0;
    
    }

// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

//----------------Code--------------------
class Solution{
  public:
    bool rec(Node* node, int curr_h, int& leaf_h){
        curr_h++;
        if(node->left == NULL and node->right == NULL){
            if(leaf_h == -1){
                leaf_h = curr_h;
            }else if(leaf_h != curr_h){
                return false;
            }else return true;
        }
        
        bool l=1, r=1;
        if(node->left){
            l = rec(node->left, curr_h, leaf_h);
        }
        if(node->right){
            r = rec(node->right, curr_h, leaf_h);
        }
        
        return l&r;
    }
  
    /*You are required to complete this method*/
    bool check(Node *root){
        int curr_h = 0, leaf_h = -1;
        if(root == NULL) return true;
        return rec(root, curr_h, leaf_h);
    }
};

// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

string rec_inorder(Node* node, set<string> &s){
        string inorder;
        
        if(node->left) inorder += rec_inorder(node->left, s);
        inorder += to_string(node->data);
        if(node->right) inorder += rec_inorder(node->right, s);
        
        if((inorder[0] == 'p') or (inorder[inorder.size()-1] == 'p')) return "p";
        
        if(node->left or node->right){
            if(s.find(inorder) == s.end()){
                s.insert(inorder);
            }else{
                return "p";
            }
        }
        
        return inorder;
    }
    
    int dupSub(Node *root){
         set<string> s;
         if(root == NULL) return 0;
         string ret = rec_inorder(root, s);
         if(ret == "p"){
             return 1;
         }
         else return 0;
    }

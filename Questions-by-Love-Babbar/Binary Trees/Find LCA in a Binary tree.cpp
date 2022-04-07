// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#

//-----------------Code------------------
vector<int> rec(Node* node, int n1, int n2, Node* &lca){
        vector<int> ret(2), l(2), r(2);
        
        if(node->left) l = rec(node->left, n1, n2, lca);
        if(node->right) r = rec(node->right, n1, n2, lca);
        
        if(node->data == n1){
            l[0] = 1;
            r[0] = 1;
        }
        
        if(node->data == n2){
            l[1] = 1;
            r[1] = 1;
        }
        
        ret[0] = ret[0] | l[0] | r[0];
        ret[1] = ret[1] | l[1] | r[1];
        
        if((l[0]&r[1]) | (l[1]&r[0])){
            lca = node;
            //cout << node->data << endl;
        }
        
        return ret;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 ){
       Node* lca;
       if(root==NULL) return NULL;
       
       rec(root, n1, n2, lca);
       
       return lca;
    }

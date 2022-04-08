// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

//-------------------Code-------------------------
vector<int> rec(Node* node, int a, int b, int &ans){
        vector<int> l(2, -1), r(2, -1), c(2, -1);
        
        if(node->left) l = rec(node->left, a, b, ans);
        if(node->right) r = rec(node->right, a, b, ans);
        
        if(l[0] == -1 and r[0] == -1) c[0] = -1;
        else c[0] = max(l[0], r[0]) + 1;
        
        if(l[1] == -1 and r[1] == -1) c[1] = -1;
        else c[1] = max(l[1], r[1]) + 1;
        
        if(node->data == a) c[0] = 0;
        if(node->data == b) c[1] = 0;
        
        if((c[0]==0 and c[1]!=-1) || (c[1]==0 and c[0]!=-1) || (l[0]!=-1 and r[1]!=-1) || (l[1]!=-1 and r[0]!=-1)){
            ans = c[0]+c[1];
        }
        
        return c;
    }
    
    int findDist(Node* root, int a, int b) {
        if(root==NULL) return -1;
        int ans = -1;
        rec(root, a, b, ans);
        
        return ans;
    }

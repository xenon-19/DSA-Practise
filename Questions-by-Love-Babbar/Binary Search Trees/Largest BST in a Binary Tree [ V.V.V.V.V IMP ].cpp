// https://practice.geeksforgeeks.org/problems/largest-bst/1#

//--------------O(n)----------------
//----------------Code--------------
 vector<int> rec(Node* node){
      if(node==NULL) return {1, INT_MAX, INT_MIN, 0};
      vector<int> l, r;
        
        l = rec(node->left); r = rec(node->right);
        if((l[0]&r[0])){
            if(l[2]<node->data and r[1]>node->data){
                ans = max(ans, l[3]+r[3]+1);
                return {1, min(node->data, l[1]), max(node->data, r[2]), l[3]+r[3]+1};
            }else{
                return {0, 0, 0, 0};
            }
        }else{
            return {0, 0, 0, 0};
        }
    }
    
int largestBst(Node *root){
    ans=0;
    rec(root);
    return ans;
}

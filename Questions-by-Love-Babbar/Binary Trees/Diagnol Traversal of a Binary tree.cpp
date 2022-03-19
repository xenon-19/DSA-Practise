// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

//------------------------Code-----------------------
vector<int> diagonal(Node *root){
   if(root==NULL) return {};
   
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   
   //q contains generator nodes, which can generate node in a diagonal level
   while(!q.empty()){
       int s=q.size();
       while(s--){
           Node* node = q.front();
           q.pop();
           while(node){
               ans.push_back(node->data);
               if(node->left) q.push(node->left);
               node = node->right;
           }
       }
   }
   
   return ans;
}

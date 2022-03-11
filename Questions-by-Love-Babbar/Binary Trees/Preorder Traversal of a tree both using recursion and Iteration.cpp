// https://practice.geeksforgeeks.org/problems/preorder-traversal/1

//---------------recursive--------------

void rec(Node* node, vector<int> &ans){
    if(node==NULL) return;
    ans.push_back(node->data);
    rec(node->left, ans);
    rec(node->right, ans);
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  vector<int> ans;
  rec(root, ans);
  return ans;
}

//---------------iterative------------------

vector <int> preorder(Node* root)
{
  vector<int> ans;
  stack<Node*> s;
  
  Node* curr = root;
  
  while(!s.empty() || curr){
      if(!curr){
          curr = s.top();
          s.pop();
      }else{
          if(curr->right) s.push(curr->right);
          ans.push_back(curr->data);
          curr = curr->left;
      }
      
  }
  
  return ans;
}

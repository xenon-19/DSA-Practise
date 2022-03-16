// https://practice.geeksforgeeks.org/problems/postorder-traversal/1

//-------------------recursive---------------------

void rec(Node* node, vector<int> &ans){
    if(node==NULL) return;
    rec(node->left, ans);
    rec(node->right, ans);
    ans.push_back(node->data);
}

vector <int> postOrder(Node* root)
{
  vector<int> ans;
  rec(root, ans);
  
  return ans;
}

//--------------------iterative--------------------------
vector <int> postOrder(Node* root)
{
  stack<Node*> temp;
  stack<int> vis;
  vector<int> ans;
  
  Node* curr = root;
  
  temp.push(curr);
  while(!temp.empty()){
      curr = temp.top();
      temp.pop();
      vis.push(curr->data);
      if(curr->left) temp.push(curr->left);
      if(curr->right) temp.push(curr->right);
  }
  
  while(!vis.empty()){
      ans.push_back(vis.top());
          vis.pop();
  }
  return ans;

}

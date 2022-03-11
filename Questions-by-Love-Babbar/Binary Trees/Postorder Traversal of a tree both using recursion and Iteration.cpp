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


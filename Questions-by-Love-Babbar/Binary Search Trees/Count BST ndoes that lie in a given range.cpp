// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

//------------------Code-----------------
void rec(Node* node, int l, int h, int &cnt){
    if(node == NULL) return;
    if(node->data >= l) rec(node->left, l, h, cnt);
    if(node->data>=l and node->data<=h) cnt++;
    if(node->data <= h) rec(node->right, l, h, cnt);
}

int getCount(Node *root, int l, int h){
  int cnt = 0;
  rec(root, l, h, cnt);
  return cnt;
}

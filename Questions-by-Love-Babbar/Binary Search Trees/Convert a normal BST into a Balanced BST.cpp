// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

//-----------------Code---------------
void make_inorder(Node* node, vector<Node*> &inorder){
    if(node==NULL) return;
    make_inorder(node->left, inorder);
    inorder.push_back(node);
    make_inorder(node->right, inorder);
}

Node* rec(vector<Node*> &io, int start, int end){
    int n = end-start;
    if(n==0) return NULL;
    Node* node = new Node(io[start + n/2]->data);
    node->left = rec(io, start, start+n/2);
    node->right = rec(io, start+n/2+1, end);
    
    return node;
}

Node* buildBalancedTree(Node* root){
  if(root==NULL) return NULL;
    
	vector<Node*> inorder;
	make_inorder(root, inorder);
	
	int n = inorder.size();
	
	return rec(inorder, 0, n);
}

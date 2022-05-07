// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=1

//---------------O(n)---------------
//---------------Code---------------
TreeNode<int>* flatten(TreeNode<int>* root){
    if(root==NULL) return root;
	TreeNode<int>* node=root;
	while(root->left) root=root->left;
	while(node->left || node->right){
		if(node->left){
			TreeNode<int> *temp=node->left;
			while(temp->right) temp=temp->right;
			temp->right = node;
			temp = node->left;
			node->left = NULL;
			node = temp;
		}else{
			TreeNode<int> *temp=node->right, *temp2=node->right;
			while(temp->left) temp=temp->left;
			node->right = temp;
			node=temp2;
		}
	}
	return root;
}

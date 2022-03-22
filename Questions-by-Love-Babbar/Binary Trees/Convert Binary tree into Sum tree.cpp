// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1


//-----------------Code-------------------
long long sum(Node* node){
        if(node==NULL) return 0;
        int temp = node->data;
        node->data = sum(node->left) + sum(node->right);
        return temp + node->data;
    }
    
void toSumTree(Node* node){
    sum(node);
}

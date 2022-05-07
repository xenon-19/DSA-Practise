// https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1


//-----------O(n),O(n)-----------
//-------------Code-------------
Node* post_order(int pre[], int size){
    Node* root = newNode(pre[0]);
    stack<Node*> stk;
    stk.push(root);
    for(int i=1; i<size; i++){
        if(stk.top()->data > pre[i]){
            stk.top()->left = newNode(pre[i]);
            stk.push(stk.top()->left);
        }else{
            Node* temp;
            while(!stk.empty() and stk.top()->data < pre[i]){
                temp = stk.top();
                stk.pop();
            }
            temp->right = newNode(pre[i]);
            stk.push(temp->right);
        }
    }
    return root;
}

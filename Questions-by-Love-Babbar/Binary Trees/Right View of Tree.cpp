// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

//------------------Code---------------
//-----------driver -> rightView funtion---------

void rec(Node* node, int &maxh, int currh, vector<int> &ans){
        currh++;
        
        if(node==NULL) return;
        
        if(currh>maxh){
            maxh = currh;
            ans.push_back(node->data);
        }
        if(node->right) rec(node->right, maxh, currh, ans);
        if(node->left) rec(node->left, maxh, currh, ans);
}

vector<int> rightView(Node *root){

       vector<int> ans;
       int maxh=0;
       int currh=0;

       rec(root, maxh, currh, ans);

       return ans;
}

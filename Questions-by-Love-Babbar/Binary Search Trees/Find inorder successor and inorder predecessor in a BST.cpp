// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#

//------------------Code------------------
void find_pre(Node* node, int key, Node *&pre){
    if(node==NULL) return;
    if(node->key < key){
        pre = node;
        //cout << "pre = "<< node->key << endl; 
        find_pre(node->right, key, pre);
    }
    if(node->key >= key){
        find_pre(node->left, key, pre);
    }
}

void find_suc(Node* node, int key, Node *&suc){
    if(node==NULL) return;
    if(node->key > key){
        suc = node;
        //cout << "suc = "<< node->key << endl;
        find_suc(node->left, key, suc);
    }
    if(node->key <= key){
        find_suc(node->right, key, suc);
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    find_pre(root, key, pre);
    find_suc(root, key, suc);
    //cout << pre->key << " " << suc->key << endl;
}

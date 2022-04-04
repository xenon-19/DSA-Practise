// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

//--------------------Code-----------------------
void rec(Node* node, ll& maxl, ll& maxs, ll currl, ll currs){
        currl += 1;
        currs += node->data;
        
        
        if(currl > maxl){
            maxl = currl;
            maxs = currs;
        }else if(currl == maxl and currs > maxs){
            maxs = currs;
        }
        
        //cout << node->data << " " << currl << " " << currs << endl;
        //cout << node->data << " " << maxl << " " << maxs << endl;
        
        if(node->left) rec(node->left, maxl, maxs, currl, currs);
        if(node->right) rec(node->right, maxl, maxs, currl, currs);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        ll maxl=0, maxs=0;
        
        if(root==NULL) return 0;
        
        rec(root, maxl, maxs, 0, 0);
        
        return maxs;
    }

// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

//-----------------------Code--------------------------

//---------------O(n) space-------------------
Node * bToDLL(Node *root){
        vector<Node*> ionodes;
        Node* curr=root;
        stack<Node*> stk;
        
        while(curr or !stk.empty()){
            if(curr){
                stk.push(curr);
                curr = curr->left;
            }else{
                ionodes.push_back(stk.top());
                curr = stk.top()->right;
                stk.pop();
            }
        }
        
        ionodes[0]->left = NULL;
        ionodes[ionodes.size()-1]->right = NULL;
        
        for(int i=1; i<ionodes.size(); i++){
            ionodes[i-1]->right = ionodes[i];
            ionodes[i]->left = ionodes[i-1];
        }
        
        return ionodes[0];
    }


//-------------------------O(1) space-------------------------------
Node * bToDLL(Node *root){
        Node* curr=root;
        Node* dlr=NULL;
        Node* dll=NULL;
        
        stack<Node*> stk;
        while(!stk.empty() or curr){
            if(curr){
                stk.push(curr);
                curr = curr->left;
            }else{
                if(!dlr){
                    dlr=stk.top();
                    dll=stk.top();
                    curr=stk.top()->right;
                    stk.pop();
                }else{
                    dll->right = stk.top();
                    stk.top()->left=dll;
                    dll = stk.top();
                    curr=stk.top()->right;
                    stk.pop();
                }
            }
        }
        
        return dlr;
    }

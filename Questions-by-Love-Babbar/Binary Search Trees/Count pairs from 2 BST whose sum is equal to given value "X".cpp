// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

//----------------------Code----------------------
int countPairs(Node* root1, Node* root2, int x){
        stack<Node*> s1, s2;
        int cnt = 0;
        Node *n1=root1, *n2=root2;
        
        while((!s1.empty() || n1) and (!s2.empty() || n2)){
            if(n1){
                s1.push(n1);
                n1=n1->left;
            }
            if(n2){
                s2.push(n2);
                n2=n2->right;
            }
            if(n1==NULL and n2==NULL){
                if(s1.top()->data + s2.top()->data == x){
                    cnt++;
                    n1 = s1.top()->right;
                    n2 = s2.top()->left;
                    s1.pop(); s2.pop();
                }else if(s1.top()->data + s2.top()->data > x){
                    n2 = s2.top()->left;
                    s2.pop();
                }else{
                    n1 = s1.top()->right;
                    s1.pop();
                }
            }
        }
        
        return cnt;
    }

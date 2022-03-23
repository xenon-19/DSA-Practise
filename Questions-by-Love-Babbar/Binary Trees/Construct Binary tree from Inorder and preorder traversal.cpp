// https://practice.geeksforgeeks.org/problems/construct-tree-1/1#

//-----------------Code------------------
int left_cnt(int in[], int node, int n){
        for(int i=0; i<n; i++){
            if(in[i] == node) return i;
        }
        return -1;
    }
    
    Node* buildTree(int in[],int pre[], int n){
        
        if(n==0) return NULL;
        
        Node* curr = new Node(pre[0]);
        
        int lc = left_cnt(in, curr->data, n);
        int rc = n - (lc+1);
        
        //cout << lc << " " << rc <<endl;
        
        int lin[lc], rin[rc], lpre[lc], rpre[rc];
        
        int i=0;
        for(i=0; i<lc; i++){
            lin[i] = in[i];
        }
        i++;
        for(;i<n; i++){
            rin[i-lc-1] = in[i]; 
        }
        
        for(i=1; i<=lc; i++){
            lpre[i-1] = pre[i];
        }
        for(; i<n; i++){
            rpre[i-lc-1] = pre[i]; 
        }
        
        curr->left = buildTree(lin, lpre, lc);
        curr->right = buildTree(rin, rpre, rc);
        
        return curr;
    }

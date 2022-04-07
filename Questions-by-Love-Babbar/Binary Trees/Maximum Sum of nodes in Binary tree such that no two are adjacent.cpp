// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

int rec(Node* node, bool flag, map<pair<Node*, bool>, int> &mp){
        if(mp.find({node, flag})!=mp.end()) return mp[{node, flag}];
        
        if(flag == 0){
            int m=0, temp=0;
            if(node->left) temp += rec(node->left, 0, mp);
            if(node->right) temp += rec(node->right, 0, mp);
            m=max(m, temp);
            temp = 0;
            
            if(node->left) temp += rec(node->left, 1, mp);
            if(node->right) temp += rec(node->right, 0, mp);
            m=max(m, temp);
            temp = 0;
            
            if(node->left) temp += rec(node->left, 0, mp);
            if(node->right) temp += rec(node->right, 1, mp);
            m=max(m, temp);
            temp = 0;
            
            if(node->left) temp += rec(node->left, 1, mp);
            if(node->right) temp += rec(node->right, 1, mp);
            m=max(m, temp);
            temp = 0;
            
            mp[{node, flag}] = m;
            return m;
        }else{
            int m=0, temp=node->data;
            if(node->left) temp += rec(node->left, 0, mp);
            if(node->right) temp += rec(node->right, 0, mp);
            m=max(m, temp);
            mp[{node, flag}] = m;
            return m;
        }
    }
    
    int getMaxSum(Node *root){
        map<pair<Node*, bool>, int> mp;
        
        if(root==NULL) return 0;
        
        rec(root, 0, mp);
        rec(root, 1, mp);
          
        return max(mp[{root, 0}], mp[{root, 1}]);
    }

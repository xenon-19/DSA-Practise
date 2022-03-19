// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//-----------------Code------------------

//fxn to empty stack into ans array
void empty_stk(stack<int> &stk, vector<int> &ans){
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
    }

//main function
//apply normal bfs but for odd level push nodes in a stack then in the ans array
vector<int> zigZagTraversal(Node* root){
    	if(root==NULL) return {};
    	
    	queue<pair<Node*, int>> q;
    	stack<int> stk;
    	
    	q.push({root, 0});
    	pair<Node*, int> curr;
    	
    	vector<int> ans;
    	
    	while(!q.empty()){
    	    curr = q.front();
    	    q.pop();
    	    
    	    if(curr.second%2){
    	        stk.push(curr.first->data);
    	    }else{
    	        if(!stk.empty()) empty_stk(stk, ans);
    	        ans.push_back(curr.first->data);
    	    }
    	    if(curr.first->left) q.push({curr.first->left, curr.second+1});
    	    if(curr.first->right) q.push({curr.first->right, curr.second+1});
    	}
    	
    	if(!stk.empty()) empty_stk(stk, ans);
    	return ans;
    }

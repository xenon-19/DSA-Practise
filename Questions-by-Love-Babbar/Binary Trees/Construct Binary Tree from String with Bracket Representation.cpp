// https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
// https://www.lintcode.com/problem/880/

//---------------Code-----------------
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param s: a string
     * @return: a root of this tree
     */
    TreeNode* str2tree(string s) {
        //cout << s << endl;
        if(s.size()==0) return NULL;
        TreeNode* root;

        vector<int> p1(2);
        vector<int> p2(2);
        int c=0, k=0;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]=='(') c++;
                if(s[i]=='(' and c==1){
                    p1[k]=i;
                }
                if(s[i]==')') c--;
                if(c==0){
                    p2[k]=i;
                    k++;
                }
            }
        }

        // cout << p1[0] << " " << p2[0] << endl;
        // cout << p1[1] << " " << p2[1] << endl;

        if(k==0){
            stringstream st(s);
            int val;
            st >> val;
            root = new TreeNode(val);
        }if(k>0){
            stringstream st(s.substr(0, p1[0]));
            int val;
            st >> val;
            root = new TreeNode(val);
        }

        if(k>0) root->left = str2tree(s.substr(p1[0]+1, p2[0]-p1[0]-1));
        else root->left=NULL;

        if(k>1) root->right = str2tree(s.substr(p1[1]+1, p2[1]-p1[1]-1));
        else root->right = NULL;

        return root;
    }
};

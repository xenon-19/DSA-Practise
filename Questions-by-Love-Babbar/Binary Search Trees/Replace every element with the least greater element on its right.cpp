// https://www.codingninjas.com/codestudio/problems/least-greater-element_1164266?leftPanelTab=1

//-----------------O(nlogn),O(nlogn)----------------
//-----------------Code-----------------------
#include <unordered_map>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

void insert(struct Node* root, int data, int to_replace, int i, vector<int> &replaced){
	if(root==NULL) return;
	if(root->data > data){
		to_replace = root->data;
		if(root->left){
			insert(root->left, data, to_replace, i, replaced);
		}else{
			replaced[i] = to_replace;
			struct Node* temp = new struct Node();
			temp->data = data;
			temp->left = temp->right = NULL;
			root->left = temp;
		}
	}
	else if(root->data <= data){
		if(root->right){
			insert(root->right, data, to_replace, i, replaced);
		}else{
			replaced[i] = to_replace;
			struct Node* temp = new struct Node();
			temp->data = data;
			temp->left = temp->right = NULL;
			root->right = temp;
		}
	}
}

vector<int> leastGreaterElement(vector<int> &arr){
	struct Node* root = new struct Node();
	root->data = arr[arr.size()-1];
	root->left = root->right = NULL;
	
	vector<int> replaced(arr.size());
	replaced[arr.size()-1] = -1;
	
	for(int i=arr.size()-2; i>=0; i--){
		insert(root, arr[i], -1, i, replaced);
	}
	
	return replaced;
}

int main(){
      int t;
      cin >> t;
      while(t--){
            int n;
            cin >> n;
            vector<int> v(n);
            for(int i=0; i<n; i++) cin >> v[i];
            v = leastGreaterElement(v);
            for(int i=0; i<n; i++) cout << v[i] << " ";
            cout << endl;
      }
}

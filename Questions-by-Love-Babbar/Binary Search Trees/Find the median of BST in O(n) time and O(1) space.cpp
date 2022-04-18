// https://practice.geeksforgeeks.org/problems/median-of-bst/1
// https://www.geeksforgeeks.org/find-median-bst-time-o1-space/

//--------------------Code-------------------
Node* find_pred(Node* node){
    Node* temp = node->left;
    while(temp->right and temp->right != node){
        temp = temp->right;
    }
    return temp;
}

int cnt_elements(Node* node){
    int cnt = 0;
    if(node ==  NULL) return 0;
    while(node){
        if(node->left){
            Node* pred = find_pred(node);
            if(pred->right){
                cnt++;
                pred->right = NULL;
                node = node->right;
            }else{
                pred->right = node;
                node = node->left;
            }
        }else{
            cnt++;
            node = node->right;
        }
    }
    return  cnt;
}

float findMedian(struct Node *root){
      int n;
      n = cnt_elements(root);
      Node *p1=NULL, *p2=NULL;
      
      int f = (n+1)/2, cnt=0;
      
      Node *node = root;
      while(node){
          if(node->left){
              Node* pred = find_pred(node);
              if(pred->right){
                  cnt++;
                  if(cnt == f) p1 = node;
                  if(cnt == f+1) p2 = node;
                  if(cnt > f+1) break;
                  pred->right = NULL;
                  node = node->right;
              }else{
                  pred->right = node;
                  node = node->left;
              }
          }else{
              cnt++;
              if(cnt == f) p1 = node;
              if(cnt == f+1) p2 = node;
              if(cnt > f+1) break;
              node = node->right;
          }
      }
      
      if(n%2) return p1->data;
      else return ((float)p1->data+p2->data)/2;
}

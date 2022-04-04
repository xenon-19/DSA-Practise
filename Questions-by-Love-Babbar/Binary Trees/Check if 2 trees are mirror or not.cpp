// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

//--------------------------Code--------------------------
void lvlorder(int flag, unordered_map<int, vector<int>> &t, int r, vector<int> &l){
        queue<int> q;
        q.push(r);
        
        int temp=0;
        
        while(!q.empty()){
            temp = q.front();
            l.push_back(temp);
            q.pop();
            if(flag==1){
                for(int i=0; i<t[temp].size(); i++){
                    q.push(t[temp][i]);
                }
            }else{
                for(int i=t[temp].size()-1; i>=0; i--){
                    q.push(t[temp][i]);
                }
            }
        }
    }
  
    int checkMirrorTree(int n, int e, int a[], int b[]) {
        unordered_map<int, vector<int>> ta, tb;
        
        if(n==1) return 1;
        
        int ra=a[0], rb=b[0];
        
        for(int i=0; i<2*e; i+=2){
            ta[a[i]].push_back(a[i+1]);
            tb[b[i]].push_back(b[i+1]);
        }
        
        vector<int> la;
        vector<int> lb;
        
        lvlorder(1, ta, ra, la);
        lvlorder(2, tb, rb, lb);
        
        if(la == lb) return 1;
        return 0;
    }

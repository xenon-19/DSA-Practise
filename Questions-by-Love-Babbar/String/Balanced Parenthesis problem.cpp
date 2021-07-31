// Question
// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#
// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

//--------Code--------
//--------O(n)--------
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    bool is_opening(char a){
        if(a=='(' || a=='{' || a=='['){
            return true;
        }else return false;
    }
    
    char opp(char x){
        if(x=='(') return ')';
        else if(x=='{') return '}';
        else if(x=='[') return ']';
        else return -1;
    }
    
    bool ispar(string x)
    {
        vector<char> stk;
        for(int i=0; i<x.length(); i++){
            if(is_opening(x[i])){
                stk.push_back(x[i]);
            }else{
                if((!stk.empty()) && opp(*(stk.end()-1)) == x[i]){
                    stk.pop_back();
                    continue;
                }else{
                    return false;
                }
            }
        }
        if(stk.size()==0) return true;
        else return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends

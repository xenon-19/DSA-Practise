// Question
// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. 
// A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. 
// We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
// Note - Strings S1 and S2 can be empty.
// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#

//---------Code---------
//---------O(n)---------
// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
 // } Driver Code Ends

class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        int p=0, ans=0, temp=0;
        //p keeps track of next '[', if i moves ahead of p, we shift p to i
        //temp < 0, whenever num of '[' are less than ']'
        //so we will grab one from right and bring it here
        for(int i=0; i<s.size(); i++){
            if(s[i]=='[')   temp++;
            else if(s[i]==']')  temp--;
            p=max(p,i);
            if(temp < 0){
                p++;
                for(;p<s.size();p++){
                    if(s[p]=='[') break;
                }
                ans+=p-i;
                //all element between ']' and '[' are ']'
                swap(s[i],s[p]);
                temp+=2; //remove the ']' from count and add '[' to count
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends

// Question
// Implement KMP algo, to find all occurences of a pattern in a string.

//------Code-----
#include <bits/stdc++.h>
using namespace std;

void get_lps(vector<int> &lps, string pat){
    int p1 = 0, p2 = 1;
    lps[0] = 0;
    
    while(p2 < pat.length()){
        if(pat[p1] == pat[p2]){
            lps[p2] = p1+1;
            p1++; p2++;
        }else{
            if(!p1){
                lps[p2] = 0;
                p2++;
            }else{
                p1 = lps[p1-1];
            }
        }
    }
    
}

int main() {
    string txt = "efwjefefqiufgefqiufghiowjsfefqiufghwhjekhlfbweefefqiufgqiufghskhjfeefqiufgkl";
    string pat = "efqiufg";
    
    if(pat.length() == 0){
        cout << "pat string empty";
        return 0;
    }
    
    vector<int> lps(pat.length());
    get_lps(lps, pat);
    
    int p1=0, p2=0;
    while(p2 < txt.length()){
        if(pat[p1] == txt[p2]){
            if(p1 == pat.length()-1){
                p1 = 0;
                p2 = p2 - pat.length() + 2;
                cout << "match at idx : " << p2 - 1 << endl; 
            }else{
                p1++; p2++;
            }
        }else{
            if(p1 == 0){
                p2++;
            }else{
                p1 = lps[p1-1];
            }
        }
    }
    
    return 0;
    
}

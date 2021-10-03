// Question
// Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

//-------Code-------
//----O(n),O(n)-----
//essentially we need to find length of longest palindromic prefix

#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long ll;

//essentially we need to find longest palindromic prefix

void find_lps(string &s, vector<int> &lps);
int longest_palindromic_prefix(string &s, vector<int> &lps);

int main(){
    string s = "AACECAAAA";
    vector<int> lps(s.size(), 0);
    find_lps(s, lps);
    int l = longest_palindromic_prefix(s, lps);
    //cout << l << endl;
    cout << s.size() - l << endl;
    return 0;
}

//will make the lps array, lps[i] = length of str which is both prefix ans suffix of s[:i+1]
void find_lps(string &s, vector<int> &lps){
    int n = s.size();
    int i=0, j=1;
    while(j<n){
        if(s[i]==s[j]){
            lps[j] = i+1;
            i++;
            j++;
        }else if(i==0){
            j++;
        }else{
            i=lps[i-1];
        }
    }
}

//find the length of longest palindromic prefix
//follows logic similar to kmp
int longest_palindromic_prefix(string &s, vector<int> &lps){
    int n = s.size();
    //i starts from 0, j from end
    int i=0, j=n-1;

    //will stop if i crosses j
    while(i<j){
        //if s[i]==s[j], both can be part of palindrome, move ahead
        //if not, then update value of i using lsp
        if(s[i]==s[j]){
            i++;
            j--;
        }else if(i==0){
            j--;
        }else{
            i = lps[i-1];
        }
    }
    
    //return 2*midpoint of palindrome
    if(i==j) return 2*(i+1)-1;
    else return 2*(j+1);
}

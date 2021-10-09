// Question
// Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion? 
// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/

//------------Code-------------
//-----------O(n^2)------------
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long ll;
#define show(v) for(auto &x: v) cout << x << ' '; cout << endl;

void combination(string till_now, vector<vector<string>> &words, int i){
    for(int j=0; j<words[i].size(); j++){
        string temp = till_now + " " + words[i][j];
        if(i==words.size()-1) cout << temp << endl;
        else{
            combination(temp, words, i+1);
        }

    }
}

int main(){
    vector<vector<string>> words = {{"you", "we"},
                                    {"have", "are"},
                                    {"sleep", "eat", "drink"}};;
    combination("", words, 0);
    return 0;
}

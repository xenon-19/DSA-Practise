// Question
// A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.
// https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

//-------------Code---------------
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
#define show(v) for(auto &x: v) cout << x << ' '; cout << endl;

int find_idx(vector<int> arr, int k, int x){
    int i=0;
    while(i<arr.size()){
        if(arr[i]==x) return i;
        int diff = abs(arr[i]-x)/k;
        if(diff) i+=diff;
        else i+=1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr = {20, 40, 50, 70, 70, 60};
    int k = 20;
    int x = 60;

    int idx = find_idx(arr, k, x);
    cout << "First Index of the element is " << idx << endl;
    return 0;
}

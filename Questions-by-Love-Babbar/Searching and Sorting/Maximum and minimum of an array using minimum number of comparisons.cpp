// Question
// Write a function to return minimum and maximum in an array. Your program should make the minimum number of comparisons. 
// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/#

//---------------Code-----------------
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_maxNmin(vector<int> &arr){
    int ma = arr[arr.size()-1], mi = arr[arr.size()-1];
    for(int i=0; i<arr.size()-1; i+=2){
        int tma, tmi;
        if(arr[i] < arr[i+1]){
            tmi = arr[i];
            tma = arr[i+1];
        }else{
            tmi = arr[i+1];
            tma = arr[i];
        }
        ma = max(tma, ma);
        mi = min(tmi, mi);
    }
    cout << "Maximum : " << ma << "; Mininmum : " << mi << endl;
}

int main() {
	vector<int> arr = { 1000, 11, 445, 1, 330, 3000 };
	print_maxNmin(arr);
	return 0;
}

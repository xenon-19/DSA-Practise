// Question
// Given an array of positive and negative numbers, 
// arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
// Number of positive and negative numbers need not be equal. 
// If there are more positive numbers they appear at the end of the array. 
// If there are more negative numbers, they too appear in the end of the array.

//-----------Code------------
#include <bits/stdc++.h>
using namespace std;

void rotate(int* arr, int start, int end);
void find_nxt(int* arr, int opp_to, int* to_insert, int n);
void arrange_alternate(int* arr, int n);

int main(){
      int n;
      cin >> n;
      int arr[n];
      
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      
      arrange_alternate(arr, n);
      
      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }
      cout << endl;
      
      return 0;
}

void arrange_alternate(int* arr, int n){
      int to_insert;
      for(int i=0; i<n; i++){
            if(i%2==0){
                  if(!((arr[i]>=0 && arr[0]>=0) || (arr[i]<0 && arr[0]<0))){
                        find_nxt(arr, i, &to_insert, n);
                        if(to_insert==-1) break;
                        rotate(arr, i, to_insert);
                  }
            }else{
                  if(!((arr[i]<0 && arr[0]>=0) || (arr[i]>=0 && arr[0]<0))){
                        find_nxt(arr, i, &to_insert, n);
                        if(to_insert==-1) break;
                        rotate(arr, i, to_insert);
                  }
            }
            
      }
}

void find_nxt(int* arr, int opp_to, int* to_insert, int n){
      int i=opp_to;
      if(arr[opp_to]>=0){
            for(; i<n; i++){
                  if(arr[i]<0){
                        *to_insert = i;
                        break;
                  }
            }
            if(i==n) *to_insert = -1;
      }else{
            for(; i<n; i++){
                  if(arr[i]>=0){
                        *to_insert = i;
                        break;
                  }
            }
            if(i==n) *to_insert = -1;
      }
}

void rotate(int* arr, int start, int end){
      int temp=arr[end];
      for(int i=end; i>start; i--){
            arr[i] = arr[i-1];
      }
      arr[start] = temp;
}

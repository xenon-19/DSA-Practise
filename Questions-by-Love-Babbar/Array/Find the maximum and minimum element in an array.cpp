// Question
// Write a C++ function to return minimum and maximum in an array. Your program should make the minimum number of comparisons.

//-----------code---------------
//driver code
#include <bits/stdc++.h>
using namespace std;
struct max_min{ //structure to return max and min value
    int max;
    int min;
};
struct max_min find_mm(int, int*); //function prototype declaration
int main() {
  int n_array;    
	cin >> n_array;         
	int arr[n_array];	
	for(int i=0; i<n_array; i++){
	    cin >> arr[i];
	}	
	struct max_min* mm =  find_mm(n_array, arr);	
	cout << "The maximum is " << mm.max << " and the minimum is "<< mm.min << endl;
	return 0;
}
//driver code ends
//function definition
struct max_min find_mm(int n_array, int* arr){
    struct max_min mm;
    mm.max = arr[0];
    mm.min = arr[0];
    for(int i=0; i<n_array; i++){
        if(arr[i]>mm.max)   mm.max=arr[i];
        if(arr[i]<mm.min)   mm.min=arr[i];
    }
    return &mm;
}

// Question
// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array.
// It is given that all array elements are distinct.

//------------------Code----------------------
// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class MinHeap{
    public: 
    int* arr;
    int size;    
    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}   
    void swap(int a, int b){
        int temp;
        temp = arr[b];
        arr[b] = arr[a];
        arr[a] = temp;
    }  
    void MinHeapify(int i){
        int smallest = i;
        if(left(i)<size && arr[left(i)] < arr[smallest]) smallest = left(i);
        if(right(i)<size && arr[right(i)] < arr[smallest]) smallest = right(i);
        if(smallest != i){
            swap(smallest, i);
            MinHeapify(smallest);
        }
    }   
    MinHeap(int* a, int sizeofarr){
        arr = a;
        size = sizeofarr;
        int i = (sizeofarr-1)/2;
        while(i>=0){
            MinHeapify(i);
            i--;
        }
    }   
};

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int rqrd_val;
        MinHeap mh(arr, r+1);        
        while(k--){
            rqrd_val = arr[0];
            arr[0] = arr[mh.size-1];
            mh.size--;
            mh.MinHeapify(0);
        }       
        return rqrd_val;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends

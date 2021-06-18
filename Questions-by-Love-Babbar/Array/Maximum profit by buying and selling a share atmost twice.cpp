// Question
// In daily share trading, a buyer buys shares in the morning and sells them on the same day. 
// If the trader is allowed to make at most 2 transactions in a day, 
// whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). 
// Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

//---------Code----------
#include <bits/stdc++.h>
using namespace std;

int find_max_profit(int*, int);

int main(){
    int n;
    cin >> n;
    int prices[n];
    for(int i=0; i<n; i++) cin >> prices[i];
    int ans = find_max_profit(prices, n);
    cout << ans;
}

int find_max_profit(int* arr, int n){
    int single_trans_profit[n];
    int temp_min=arr[n-1], temp_max=arr[n-1], temp_max_diff=0, max_profit=0;
    for(int i=n-1; i>=0; --i){
        temp_max = max(arr[i], temp_max);
        temp_max_diff = max(temp_max_diff, temp_max-arr[i]);
        single_trans_profit[i] = temp_max_diff;

    }
    
    temp_max_diff = 0; temp_min = arr[0]; max_profit = 0;
    for(int i=0; i<n-1; i++){
        temp_min = min(temp_min, arr[i]);
        temp_max_diff = max(temp_max_diff, arr[i]-temp_min);
        max_profit = max(max_profit, temp_max_diff+single_trans_profit[i]);
    }
    return max_profit;
}

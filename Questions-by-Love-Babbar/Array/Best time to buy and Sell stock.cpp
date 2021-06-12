// Question
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//--------Code---------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_lower=prices[0], max_d=0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]-prev_lower>max_d) max_d = prices[i]-prev_lower;
            if(prices[i]<prev_lower) prev_lower = prices[i];
        }
        return max_d;
    }
};

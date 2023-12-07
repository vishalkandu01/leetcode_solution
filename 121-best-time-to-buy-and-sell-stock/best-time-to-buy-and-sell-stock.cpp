class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // method-1 -> Time Limit Exceeded
        // int maximumProfit = 0;
        // for(int i = 0; i < n-1; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         if(prices[j]-prices[i] > maximumProfit) {
        //             maximumProfit = prices[j]-prices[i];
        //         }
        //     }
        // }
        // return maximumProfit;


        // method-2
        int maximumProfit = 0; 
        int buy = prices[0];
        for(int i = 1; i < n; i++) {
            int sell = prices[i];
            int profit = sell - buy;
            if(profit > maximumProfit) {
                maximumProfit = profit;
            }
            if(buy > sell) {
                buy = sell;
            }
        }
        return maximumProfit;
    }
};
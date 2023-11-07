class Solution {
private:
    int solve(vector<int>& prices, int ind, bool buy, int n, vector<vector<int>>& dp) {
        if(ind == n) {
            return 0;
        }

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = INT_MIN;
        if(buy == true) {
            profit = max((solve(prices, ind+1, false, n, dp) - prices[ind]), (solve(prices, ind+1, buy, n, dp)));
        }
        else {
            profit = max((solve(prices, ind+1, true, n, dp) + prices[ind]), (solve(prices, ind+1, buy, n, dp)));
        }

        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        int ind = 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, ind, buy, n, dp);
    }
};
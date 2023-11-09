class Solution {
private:
    int solve(vector<int>& prices, int fee, bool buy, int ind, int n, vector<vector<int>>& dp) {
        if(ind == n) {
            return 0;
        }

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = INT_MIN;
        if(buy == true) {
            profit = max(solve(prices, fee, false, ind+1, n, dp) - prices[ind], solve(prices, fee, buy, ind+1, n, dp));
        }
        else {
            profit = max(solve(prices, fee, true, ind+1, n, dp) + prices[ind] - fee, solve(prices, fee, buy, ind+1, n, dp));
        }

        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        bool buy = true;
        int ind = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, fee, buy, ind, n, dp);
    }
};
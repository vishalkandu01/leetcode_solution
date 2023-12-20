class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        
        sort(prices.begin(), prices.end());
        int chocolatePrice = prices[0] + prices[1];
        if(chocolatePrice > money) return money;
        int leftMoney = money - chocolatePrice;
        return leftMoney;
    }
};
class Solution {
private:
    // int solve(int prevInd, int curInd, vector<int>& nums) {
    //     if(curInd == nums.size()) {
    //         return 0;
    //     }

    //     int take;
    //     if(prevInd == -1 || nums[prevInd] < nums[curInd]) {
    //         take = solve(curInd, curInd+1, nums) + 1;
    //     }
    //     int notTake = solve(prevInd, curInd+1, nums) + 0;

    //     return max(take, notTake);
    // }


    int f(int ind, int prevInd, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if(ind == n) return 0;

        if(dp[ind][prevInd+1] != -1) {
            return dp[ind][prevInd+1];
        }

        // return karna max between take or notTake --> max(take, notTake);
        int take = 0;
        if(prevInd == -1 || nums[ind] > nums[prevInd]) {
            take = f(ind+1, ind, nums, n, dp) + 1;
        }
        int notTake = f(ind+1, prevInd, nums, n, dp);

        return dp[ind][prevInd+1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // Memoization
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return f(0, -1, nums, n, dp);

        // Tabulation
        // int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // for(int ind = n-1; ind >= 0; ind--) {
        //     for(int prevInd = ind-1; prevInd >= -1; prevInd--) {
        //         int take = 0;
        //         if(prevInd == -1 || nums[ind] > nums[prevInd]) {
        //             take = dp[ind+1][ind+1] + 1;
        //         }
        //         int notTake = dp[ind+1][prevInd+1] + 0;

        //         dp[ind][prevInd+1] = max(take, notTake);
        //     }
        // }
        // return dp[0][0];


        // more optimization
        vector<int> ans;
        ans.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
        }
        return len;
    }
};
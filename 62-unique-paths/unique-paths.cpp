class Solution {
private:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i == m-1 && j == n-1) {
            return 1;
        }

        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(m, n, i+1, j, dp);
        int right = solve(m, n, i, j+1, dp);

        return dp[i][j] = down + right;
    }

public:
    int uniquePaths(int m, int n) {

        // Method 1
        // int i = 0;
        // int j = 0;
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(m, n, i, j, dp);


        // Method 2
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int up = 0;
                int down = 0;
                if(i == 0 || j == 0) dp[i][j] = 1;
                else {
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) down = dp[i][j-1];
                    dp[i][j] = up + down; 
                }
            }
        }
        return dp[n-1][m-1];
    }
};
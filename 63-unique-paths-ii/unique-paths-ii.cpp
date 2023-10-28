class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& dp) {
        if(i == n-1 && j == m-1 && grid[i][j] == 0) return 1;
        if(i >= n || j >= m || grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(grid, i+1, j, n, m, dp);
        int right = solve(grid, i, j+1, n, m, dp);

        return dp[i][j] = down + right; 
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0;
        int j = 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(obstacleGrid, i, j, n, m, dp);
    }
};
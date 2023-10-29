class Solution {
private:
    int solve(vector<vector<int>>& matrix, int row, int col, int n, vector<vector<int>>& dp) {
        if(row >= n || col >= n || col < 0) return 1e8;
        if(row == n-1 && col >= 0 && col < n) return matrix[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int first_way = solve(matrix, row+1, col-1, n, dp) + matrix[row][col];
        int second_way = solve(matrix, row+1, col, n, dp) + matrix[row][col];
        int third_way = solve(matrix, row+1, col+1, n, dp) + matrix[row][col];

        return dp[row][col] = min(first_way, min(second_way, third_way));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // Method 1
        // int n = matrix.size();
        // int ans = 1e8;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int col = 0; col < n; col++) {
        //     ans = min(solve(matrix, 0, col, n, dp), ans);
        // }
        // return ans;


        // Method 2
        int n = matrix.size();
        int ans = INT_MAX;
        if(n == 0) return 0;
        if(n == 1) return matrix[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int prev = matrix[i-1][j];
                if(j-1 >= 0) prev = min(prev, matrix[i-1][j-1]);
                if(j+1 < n) prev = min(prev, matrix[i-1][j+1]);
                matrix[i][j] += prev;
                if(i == n-1) ans = min(ans, matrix[n-1][j]);
            }
        }
        return ans;
    }
};
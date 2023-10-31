class Solution {
private:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i-1, j-1, dp) + 1;
        }
        
        return dp[i][j] = max( solve(s1, s2, i-1, j, dp), solve(s1, s2, i, j-1, dp) );
    }

public:
    int longestPalindromeSubseq(string str) {
        int n = str.size();
        string revStr = str;
        for(int i = 0; i < n/2; i++) {
            swap(revStr[i], revStr[n-1-i]);
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        solve(str, revStr, n-1, n-1, dp);
        return dp[n-1][n-1];
    }
};
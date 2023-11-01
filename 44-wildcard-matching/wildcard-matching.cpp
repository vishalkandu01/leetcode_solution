class Solution {
private:
    bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(i >= 0 && j < 0) {
            for(int ii = 0; ii <= i; ii++) {
                if(pattern[ii] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(pattern[i] == text[j] || pattern[i] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);
        if(pattern[i] == '*') return dp[i][j] = (f(i-1, j, pattern, text, dp) || f(i, j-1, pattern, text, dp));
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, p, s, dp);
    }
};
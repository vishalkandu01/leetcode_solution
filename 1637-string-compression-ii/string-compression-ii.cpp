class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(101, vector<int>(101, 0));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = 999;
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                int count = 0;
                int del = 0;
                for(int t = i; t >= 1; t--) {
                    if(s[t-1] == s[i-1]) count++;
                    else del++;
                    if(j - del >= 0) {
                        int temp = 0;
                        if(count >= 100) temp = 3;
                        else if(count >= 10) temp = 2;
                        else if(count >= 2) temp = 1;
                        dp[i][j] = min(dp[i][j], dp[t-1][j-del] + 1 + temp);
                    }
                }
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        return dp[n][k];
    }
};
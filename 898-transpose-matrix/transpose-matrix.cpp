class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // method-1
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int i, j;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> copyMatrix(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    copyMatrix[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(copyMatrix[i][j] == 0) {
                    for(int k = 0; k < n; k++) {
                        matrix[k][j] = 0;
                    }
                    for(int k = 0; k < m; k++) {
                        matrix[i][k] = 0;
                    }
                }
            }
        }
        return;
    }
};
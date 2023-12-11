class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> ans;
        int count = 0;
        int total = row * col;
        int startRow = 0;
        int startCol = 0;
        int endRow = row - 1;
        int endCol = col - 1;
        while(count < total) {
            for(int ind = startCol; ind <= endCol && count < total; ind++) {
                ans.push_back(matrix[startRow][ind]);
                count += 1;
            } startRow++;
            for(int ind = startRow; ind <= endRow && count < total; ind++) {
                ans.push_back(matrix[ind][endCol]);
                count += 1;
            } endCol--;
            for(int ind = endCol; ind >= startCol && count < total; ind--) {
                ans.push_back(matrix[endRow][ind]);
                count += 1;
            } endRow--;
            for(int ind = endRow; ind >= startRow && count < total; ind--) {
                ans.push_back(matrix[ind][startCol]);
                count += 1;
            } startCol++;
        }
        return ans;
    }
};
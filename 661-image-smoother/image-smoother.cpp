class Solution {
private:
    int smoothen(const vector<vector<int>>& img, int x, int y) {
        int m = img.size();
        int n = img[0].size();
        int sum = 0;
        int count = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; ++j) {
                int newx = x + i;
                int newy = y + j;
                if(newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    sum += img[newx][newy];
                    count++;
                }
            }
        }
        return sum/count;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = smoothen(img, i, j);
            }
        }
        return res;
    }
};
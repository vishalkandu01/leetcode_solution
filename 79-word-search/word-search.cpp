class Solution {
private:
    bool find(vector<vector<char>>& board, string word, int row, int col, int n, int m, int k) {
        if(k == word.size()) return true;
        if((row < 0 || col < 0 || row >= n || col >= m) || board[row][col] != word[k]) return false;
        char ch = board[row][col];
        board[row][col] = '#';
        bool left = find(board, word, row, col-1, n, m, k+1);
        bool right = find(board, word, row, col+1, n, m, k+1);
        bool up = find(board, word, row-1, col, n, m, k+1);
        bool down = find(board, word, row+1, col, n, m, k+1);
        board[row][col] = ch;
        return (left || right || up || down);
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis;
        int n = board.size();
        int m = board[0].size();
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(board[row][col] == word[0]) {
                    if(find(board, word, row, col, n, m, 0)) return true;
                }
            }
        }
        return false;
    }
};